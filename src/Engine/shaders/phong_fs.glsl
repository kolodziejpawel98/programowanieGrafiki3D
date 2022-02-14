#version 450

layout(location=0) out vec4 vFragColor;

#if __VERSION__ > 410
layout(std140, binding=0) uniform Modifiers {
#else
    layout(std140) uniform Material {
    #endif
    vec4  Kd;
    vec4 Ka;
    vec4 Ks;
    float Ns;
    bool use_map_Kd;
};

in vec2 vertex_texcoords;
in vec3 vertex_normals_in_vs;
in vec3 vertex_coords_in_vs;

uniform sampler2D map_Kd;

const int MAX_POINT_LIGHTS=24;

struct PointLight {
    vec3 position_in_w_space;
    vec3 position_in_view_space;
    vec3 color;
    float intensity;
    float radius;
};  

layout(std140, binding=2) uniform Lights {
    vec3 ambient;
    uint n_p_lights;
    PointLight p_light[MAX_POINT_LIGHTS];
};

void main() {
    float spec = 0.0f, diff = 0.0f;
    vec3 normal = vec3(0.0f), light_dir = vec3(0.0f), ambient = vec3(0.0f), view_dir = vec3(0.0f), half_vector = vec3(0.0f);

    if(use_map_Kd){
        vFragColor = Kd * texture(map_Kd, vertex_texcoords);
    }else{
        vFragColor = Kd;
    }
    
    ambient = Ka.xyz;
    normal = normalize(vertex_normals_in_vs);
    
    view_dir = normalize(vec3(0.0, 0.0, 0.0) - vertex_coords_in_vs);
    vec3 diffuse = vec3(0.0f);
    vec3 specular = vec3(0.0f);

    for(int i = 0; i < n_p_lights; i++){
        light_dir = normalize(p_light[i].position_in_view_space - vertex_coords_in_vs);
        diff = max(dot(normal, light_dir), 0.0);
        diffuse += diff * p_light[i].color * p_light[i].intensity * vFragColor.rgb;

        half_vector = normalize(light_dir + view_dir);
        spec = pow(max(dot(normal, half_vector), 0.0), Ns);
        specular += spec * p_light[i].intensity * Ks.rgb;
    }
    
    vFragColor.a = Kd.a;
    vFragColor.rgb = diffuse * Kd.rgb + ambient + specular;
}
