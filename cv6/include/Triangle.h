#pragma once
#include <opencv2\opencv.hpp>
#include "assets.h"

#include <GLFW/glfw3.h>

class Triangle {
public:
    Triangle();
    bool init(void);
    bool init_assets(void);
    int run(void);
    ~Triangle();

private:
    //new GL stuff
    GLFWwindow* window = nullptr;

    GLuint shader_prog_ID{ 0 };
    GLuint VBO_ID{ 0 };
    GLuint VAO_ID{ 0 };

    std::vector<vertex> triangle_vertices =
    {
        {{0.0f,  0.5f,  0.0f}},
        {{0.5f, -0.5f,  0.0f}},
        {{-0.5f, -0.5f,  0.0f}}
    };

};