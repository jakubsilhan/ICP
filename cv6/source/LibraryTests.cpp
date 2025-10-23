#include <iostream>
#include <fstream>
#include <filesystem>

#include <opencv2/opencv.hpp>

//#ifdef _WIN32
//#else
#include <GL/glew.h>
//#endif
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include <nlohmann/json.hpp>

#include "LibraryTests.h"

LibraryTests::LibraryTests()
{
    // default constructor
    std::cout << "Constructed...\n";
}

bool LibraryTests::init()
{
    return 0;
}

int LibraryTests::run(void)
{
    // GL Math
    {
        glm::vec3 test{ 0.0 };
        std::cout << "Hello World! " << glm::to_string(test) << "\n";
    }

    // std::filesystem
    {
        std::cout << "Current working directory: " << std::filesystem::current_path().generic_string() << '\n';
        if (!std::filesystem::exists("resources"))
            throw std::runtime_error("Directory 'resources' not found. Various media files are expected to be there.");
    }

    // JSON
    {
        std::ifstream sett_file("resources/app_settings.json");
        nlohmann::json settings = nlohmann::json::parse(sett_file);

        std::cout << settings["appname"] << '\n';

        // getting value - safely
        int x = 0;
        if (settings["default_resolution"]["x"].is_number_integer()) {
            // key found and value is proper type, use safe conversion            
            x = settings["default_resolution"]["x"].template get<int>();
        }
        else {
            // key not found or wrong data type, use default
            x = 800;
        }

        // getting value - throws exception in problems...
        int y = settings["default_resolution"]["y"];

        std::cout << "[x,y] = [" << x << ',' << y << "]\n";
    }

    // OpenCV
    {
        cv::Mat image = cv::imread("resources/lightbulb.jpg");
        std::cout << "Image size: " << image.cols << ',' << image.rows << '\n';
    }

    // GLEW
    {
        std::cout << glewGetString(GLEW_VERSION) << '\n';
        glewInit();
    }

    // GLFW
    {
        glfwInit();
        auto window = glfwCreateWindow(800, 600, "test", NULL, NULL);

        glfwDestroyWindow(window);
        glfwTerminate();
    }
}

LibraryTests::~LibraryTests()
{
    // clean-up
    std::cout << "Bye...\n";
}

