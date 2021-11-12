//
// Created by pbialas on 25.09.2020.
//

#include "app.h"

#include <iostream>
#include <vector>
#include <tuple>

#include "Application/utils.h"
#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glm/gtc/matrix_transform.hpp"

void SimpleShapeApplication::init()
{
    auto program = xe::utils::create_program(
        {{GL_VERTEX_SHADER, std::string(PROJECT_DIR) + "/shaders/base_vs.glsl"},
         {GL_FRAGMENT_SHADER, std::string(PROJECT_DIR) + "/shaders/base_fs.glsl"}});

    if (!program)
    {
        std::cerr << "Invalid program" << std::endl;
        exit(-1);
    }

    std::vector<GLfloat> vertices = {
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//0
        0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,//1
        0.5f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f,//2
        0.5f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f,//3
        0.0f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,//4
        -0.5f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,//5
        -0.5f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,//6
    };

    //  std::vector<GLfloat> vertices = {
    //     0.0f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,//0
    //     0.5f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,//1
    //     0.0f, -0.5f, 0.5f,   1.0f, 0.0f, 0.0f,//2
    //     -0.5f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f,//3
    // };

    // glEnable(GL_DEPTH_TEST);

    GLuint v_buffer_handle;
    glGenBuffers(1, &v_buffer_handle);
    OGL_CALL(glBindBuffer(GL_ARRAY_BUFFER, v_buffer_handle));
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    std::vector<GLushort> indices = {
        0, 1, 6, 1, 3, 6, 5, 2, 4
    };
    // std::vector<GLushort> indices = {
    //     0, 1, 2
    // };
    
    GLuint i_buffer_handle;
    glGenBuffers(1, &i_buffer_handle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buffer_handle);
    OGL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buffer_handle));
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLushort), indices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    GLuint color_trans_buffer_handle;
    glGenBuffers(1, &color_trans_buffer_handle);
    glBindBuffer(GL_UNIFORM_BUFFER, color_trans_buffer_handle);
    glBufferData(GL_UNIFORM_BUFFER, 8 * sizeof(float), nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0); 
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, color_trans_buffer_handle); 
    float strength = 0.9;
    float color[3] = {0.98, 0.003, 1.7};
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(float), &strength);
    glBufferSubData(GL_UNIFORM_BUFFER, 4 * sizeof(float), 3 * sizeof(float), color);
    

    auto [w, h] = frame_buffer_size();
    GLuint pvm_buffer_handle;
    glGenBuffers(1, &pvm_buffer_handle);
    glBindBuffer(GL_UNIFORM_BUFFER, pvm_buffer_handle);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), nullptr, GL_STATIC_DRAW);
    glm::mat4 Projection = glm::perspective(glm::half_pi<float>(), (float)w/h, 0.1f, 100.0f);
    glm::mat4 View = glm::lookAt(glm::vec3{1.0, .5, 2.0}, glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{0.0, 0.0, 1.0});
    glm::mat4 Model = glm::mat4(1.0f);
    glm::mat4 PVM = Projection * View * Model;
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), &PVM[0]);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, pvm_buffer_handle);

    // This setups a Vertex Array Object (VAO) that  encapsulates
    // the state of all vertex buffers needed for rendering
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, v_buffer_handle);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), reinterpret_cast<GLvoid *>(0));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), reinterpret_cast<GLvoid *>(3*sizeof(GLfloat)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buffer_handle);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    //end of vao "recording"

    // Setting the background color of the rendering window,
    // I suggest not to use white or black for better debuging.
    glClearColor(0.81f, 0.81f, 0.8f, 1.0f);

    // This setups an OpenGL vieport of the size of the whole rendering window.
    
    glViewport(0, 0, w, h);

    glUseProgram(program);
}

//This functions is called every frame and does the actual rendering.
void SimpleShapeApplication::frame()
{
    // Binding the VAO will setup all the required vertex buffers.
    glBindVertexArray(vao_);
    // glDrawArrays(GL_TRIANGLES, 0, 9);
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_SHORT, reinterpret_cast<GLvoid*>(0));
    glBindVertexArray(0);
}