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

#include "Engine/Mesh.cpp"
#include "Engine/Material.cpp"
#define STB_IMAGE_IMPLEMENTATION  1
#include "3rdParty/stb/stb_image.h"

void SimpleShapeApplication::init()
{
    xe::ColorMaterial::init();

    auto program = xe::utils::create_program(
        {{GL_VERTEX_SHADER, std::string(PROJECT_DIR) + "/shaders/base_vs.glsl"},
         {GL_FRAGMENT_SHADER, std::string(PROJECT_DIR) + "/shaders/base_fs.glsl"}});

    if (!program)
    {
        std::cerr << "Invalid program" << std::endl;
        exit(-1);
    }
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    set_camera(new Camera);
    set_controler(new CameraControler(camera()));
    
    stbi_set_flip_vertically_on_load(true);
    GLint width, height, channels;
    // std::cout<<"width = "<<width<<std::endl;
    auto texture_file = std::string(ROOT_DIR) + "/Models/multicolor.png";
    const char * texture_file_to_char = texture_file.c_str();
    auto img = stbi_load(texture_file_to_char, &width, &height, &channels, 0);
    // if (!img) {
    //     spdlog::warn("Could not read image from file `{}'", texture_file);
    // }
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
    // xe::ColorMaterial::setTexture(tex);////???<-----

//    std::vector<GLfloat> vertices = {
//         //tylna sciana
//         0.0f, 1.0f, 0.0f,   //0
//         0.5f, -0.5f, -0.5f, //1
//         -0.5f, -0.5f, -0.5f,//2
//         //prawa sciana
//         0.0f, 1.0f, 0.0f,   //3
//         0.5f, -0.5f, 0.5f,  //4
//         0.5f, -0.5f, -0.5f, //5
//         //lewa sciana
//         0.0f, 1.0f, 0.0f,   //6
//         -0.5f, -0.5f, -0.5f,//7
//         -0.5f, -0.5f, 0.5f, //8
//         //przednia sciana
//         0.0f, 1.0f, 0.0f,   //9
//         -0.5f, -0.5f, 0.5f, //11
//         0.5f, -0.5f, 0.5f,  //10
//         //podstawa 
//         0.5f, -0.5f, -0.5f, //12
//         0.5f, -0.5f, 0.5f,  //13
//         -0.5f, -0.5f, 0.5f, //14
//         //podstawa
//         0.5f, -0.5f, -0.5f, //15
//         -0.5f, -0.5f, 0.5f, //16
//         -0.5f, -0.5f, -0.5f,//17
//     };
    std::vector<GLfloat> vertices = {
        0.0f, 0.0f, 0.0f, 0.1910f, 0.5000f, //podstawa 21:00    (0)
        0.0f, 0.0f, 1.0f, 0.5000f, 0.8090f, //podstawa 12:00    (1)
        1.0f, 0.0f, 0.0f, 0.5000f, 0.1910f, //podstawa 18:00    (2)
        1.0f, 0.0f, 1.0f, 0.8090f, 0.5000f, //podstawa 15:00    (3)
        0.5f, 1.0f, 0.5f, 0.0f, 1.0f,       //czubek 11:00      (4)
        0.5f, 1.0f, 0.5f, 1.0f, 1.0f,       //czubek 13:00      (5)
        0.5f, 1.0f, 0.5f, 1.0f, 0.0f,       //czubek 17:00      (6)
        0.5f, 1.0f, 0.5f, 0.0f, 0.0f        //czubek 19:00      (7)

    };

    // std::vector<GLushort> indices = {
    //     0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17
    // };

    std::vector<GLushort> indices = {
            0,2,1,  //podstawa
            1,2,3,  //podstawa
            4,0,1,  //11:00
            5,1,3,  //13:00
            6,3,2,  //17:00
            7,2,0   //19:00
    };

    mesh.add_submesh(0, 3, new xe::ColorMaterial(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)));
    mesh.add_submesh(3, 6, new xe::ColorMaterial(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    mesh.add_submesh(6, 9, new xe::ColorMaterial(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)));
    mesh.add_submesh(9, 12, new xe::ColorMaterial(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)));
    mesh.add_submesh(12, 18, new xe::ColorMaterial(glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)));
    
    mesh.allocate_vertex_buffer(vertices.size() * sizeof(GLfloat), GL_STATIC_DRAW);
    mesh.load_vertices(0, vertices.size() * sizeof(GLfloat), vertices.data());
    mesh.allocate_index_buffer(indices.size()*sizeof(GLushort), GL_STATIC_DRAW);
    mesh.load_indices(0, indices.size()*sizeof(GLushort), indices.data());

    glGenBuffers(1, &pvm_buffer_handle);
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, pvm_buffer_handle);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), nullptr, GL_STATIC_DRAW);

    int w, h;
    std::tie(w, h) = frame_buffer_size();
    float aspect = (float)w/h;
    float fov = glm::pi<float>()/4.0;
    float near = 0.1f;
    float far = 100.0f;
    camera()->set_aspect(aspect); 
    camera()->perspective(fov, aspect, near, far);
    camera()->look_at(glm::vec3{1.8f, -1.4f, 1.8f}, glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{0.0, 1.0, 0.0});

    mesh.vertex_attrib_pointer(0, 3, GL_FLOAT, 5 * sizeof(GLfloat), 0);
    mesh.vertex_attrib_pointer(1, 2, GL_FLOAT, 5 * sizeof(GLfloat), 3*sizeof(GLfloat));

    glClearColor(0.81f, 0.81f, 0.8f, 1.0f);
    glViewport(0, 0, w, h);
}

void SimpleShapeApplication::frame(){
    auto PVM = camera()->projection() * camera()->view();
    glBindBuffer(GL_UNIFORM_BUFFER, pvm_buffer_handle);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), &PVM[0]);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    mesh.draw();
}

void SimpleShapeApplication::framebuffer_resize_callback(int w, int h) {
    Application::framebuffer_resize_callback(w, h);
    glViewport(0,0,w,h); 
    camera()->set_aspect((float) w / h);
}
