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

    class ColorMaterial : public Material {
    public:
        ColorMaterial(const glm::vec4 color) : color_(color), texture_(0), texture_unit_(0){}

        void bind();

        void unbind();

        static void init();

        static GLuint program() { return shader_; }

        GLuint getTexture();

        void setTexture();
        
        GLuint getTextureUnit();
        
        void setTextureUnit();

    private:
        static GLuint shader_;
        static GLuint color_uniform_buffer_;
        glm::vec4 color_;
        static GLint uniform_map_Kd_location_; //adres zmiennej uniform
        GLuint texture_; //uchwyt do tekstury
        GLuint texture_unit_; //uchwyt do numeru jednostki teksturujacej

    };


}
