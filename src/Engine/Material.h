//
// Created by Piotr Białas on 02/11/2021.
//

#pragma once

#include <glad/gl.h>
#include <glm/glm.hpp>

#include "Application/utils.h"

namespace xe {

    class Material {
    public:
        virtual void bind() = 0;

        virtual void unbind() {};
    };

    GLuint create_texture(const std::string &name);

    class ColorMaterial : public Material {
    public:
        ColorMaterial(const glm::vec4 color) : color_(color), texture_(0), texture_unit_(0){}

        void bind();

        void unbind();

        static void init();

        static GLuint program() { return shader_; }

        GLuint get_texture();

        void set_texture(GLuint texture_);
        
        GLuint get_texture_unit();
        
        void set_texture_unit(GLuint texture_unit_);

    private:
        static GLuint shader_;
        static GLuint color_uniform_buffer_;
        glm::vec4 color_;
        static GLint uniform_map_Kd_location_;
        GLuint texture_;
        GLuint texture_unit_; 
    };
}

