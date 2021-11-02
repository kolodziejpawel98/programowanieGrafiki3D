#version 410

in vec4 vertexColor;

layout(std140, binding = 0) uniform Modifier {
    float strength;
    vec3  color; 
};

out vec4 vFragColor;
layout(location=0) out vec4 vFragColor;

void main() {
    vFragColor = vertexColor;
}