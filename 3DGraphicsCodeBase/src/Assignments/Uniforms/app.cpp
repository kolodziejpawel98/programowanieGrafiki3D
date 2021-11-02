//
// Created by pbialas on 25.09.2020.
//

#include "app.h"

#include <iostream>
#include <vector>
#include <tuple>

#include "Application/utils.h"

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

    GLuint v_buffer_handle;
    glGenBuffers(1, &v_buffer_handle);
    OGL_CALL(glBindBuffer(GL_ARRAY_BUFFER, v_buffer_handle));
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    std::vector<GLushort> indices = {
        0, 1, 6, 1, 3, 6, 5, 2, 4
    };

    std::cout<<"\n\nsizeof glushport = "<<sizeof(GLushort)<<std::endl;
    
    GLuint i_buffer_handle;
    glGenBuffers(1, &i_buffer_handle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buffer_handle);
    OGL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buffer_handle));
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLushort), indices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


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
    auto [w, h] = frame_buffer_size();
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
