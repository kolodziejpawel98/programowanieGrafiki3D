#pragma once

#include <glad/gl.h>
#include <glm/glm.hpp>

#include "Application/utils.h"
#include "Material.h"

namespace xe {

class PhongMaterial : public Material {
    public:
        PhongMaterial(const glm::vec4 color) : Kd(color), map_Kd_unit(0),  map_Kd(0), texture_unit_(0){}

        void bind();

        void unbind();

        static void init();

        static GLuint program() { return shader_; }

        GLuint get_texture();

        void set_texture(GLuint texture_);
        
        glm::vec4 Kd;
        GLuint map_Kd;
        const GLuint map_Kd_unit;
        glm::vec4 Ka, Ks;
        float Ns;
    private:
        static GLuint shader_;
        static GLuint color_uniform_buffer_;
        static GLint uniform_map_Kd_location_;
        GLuint texture_unit_;
    };
}

