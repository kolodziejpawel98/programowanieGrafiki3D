//
// Created by Piotr Białas on 02/11/2021.
//

#include "glm/gtx/string_cast.hpp"

#include "PhongMaterial.h"
#include "3rdParty/stb/stb_image.h"

namespace xe {

    GLuint PhongMaterial::color_uniform_buffer_ = 0u;
    GLuint PhongMaterial::shader_ = 0u;
    GLint PhongMaterial::uniform_map_Kd_location_ = 0;

    void PhongMaterial::bind() {
        bool use_map_Kd = 0;
        if(map_Kd > 0){
            if(uniform_map_Kd_location_ != -1){
                glUniform1i(uniform_map_Kd_location_, texture_unit_);
            }
            use_map_Kd = 1;
            glUniform1i(uniform_map_Kd_location_, texture_unit_);
            glActiveTexture(GL_TEXTURE0 + texture_unit_);
            glBindTexture(GL_TEXTURE_2D, map_Kd);
        }
            glBindBufferBase(GL_UNIFORM_BUFFER, 0, color_uniform_buffer_);
            glUseProgram(program());
            glBindBuffer(GL_UNIFORM_BUFFER, color_uniform_buffer_);
            glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::vec4), &Kd[0]);
            glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::vec4), sizeof(glm::vec4), &Ka[0]);
            glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::vec4), sizeof(glm::vec4), &Ks[0]);
            glBufferSubData(GL_UNIFORM_BUFFER, 3 * sizeof(glm::vec4), sizeof(float), &Ns);
            glBufferSubData(GL_UNIFORM_BUFFER, 3 * sizeof(glm::vec4) + sizeof(float), sizeof(bool), &use_map_Kd);
    }

    void PhongMaterial::unbind(){
      glBindBufferBase(GL_UNIFORM_BUFFER, 0, color_uniform_buffer_);
    }

    GLuint PhongMaterial::get_texture(){
        return map_Kd;
    }

    void PhongMaterial::set_texture(GLuint map_Kd){
        this->map_Kd = map_Kd;
    }

    void PhongMaterial::init() {

        auto program = xe::utils::create_program(
                {{GL_VERTEX_SHADER,   std::string(PROJECT_DIR) + "/shaders/phong_vs.glsl"},
                 {GL_FRAGMENT_SHADER, std::string(PROJECT_DIR) + "/shaders/phong_fs.glsl"}});
        if (!program) {
            std::cerr << "Invalid program" << std::endl;
            exit(-1);
        }
        
        shader_ = program;
        
        uniform_map_Kd_location_ = glGetUniformLocation(shader_, "map_Kd");
        if (uniform_map_Kd_location_ == -1) {
            // spdlog::warn("Cannot get uniform {} location", "map_Kd");
            std::cerr << "(PhongMaterial.cpp) cannot get uniform "<< std::endl;
            // exit(-1);
        }

        glGenBuffers(1, &color_uniform_buffer_);

        glBindBuffer(GL_UNIFORM_BUFFER, color_uniform_buffer_);
        glBufferData(GL_UNIFORM_BUFFER, 3 * sizeof(glm::vec4) + sizeof(bool) + sizeof(float), nullptr, GL_STATIC_DRAW);
        glBindBuffer(GL_UNIFORM_BUFFER, 0u);

#if __APPLE__
        auto u_modifiers_index = glGetUniformBlockIndex(program, "Color");
        if (u_modifiers_index == -1) {
            std::cerr << "Cannot find Color uniform block in program" << std::endl;
        } else {
            glUniformBlockBinding(program, u_modifiers_index, 0);
        }
#endif

#if __APPLE__
        auto u_transformations_index = glGetUniformBlockIndex(program, "Transformations");
        if (u_transformations_index == -1) {
            std::cerr << "Cannot find Transformations uniform block in program" << std::endl;
        } else {
            glUniformBlockBinding(program, u_transformations_index, 1);
        }
#endif


    }
}
