#version 450

in vec2 vertex_texcoords; 

layout(std140, binding = 0) uniform Modifier {
    vec3  color; 
    float strength;
};

layout(std140, binding=0) uniform Color {
    vec4  Kd;
    bool use_map_Kd;
};

layout(location = 0) out vec4 vFragColor;

void main() {
    vFragColor.a = vertexColor.a;
    vFragColor.rgb = color*strength;
}