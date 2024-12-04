#ifndef IMGUI_HELPER_HPP
#define IMGUI_HELPER_HPP

#include "imgui_impl_glfw.h"

class ImGuiHelper {
public:
    explicit ImGuiHelper(GLFWwindow *window, const char *glslVersion = "#version 130");

    void beginFrame();

    void render();


};

#endif // IMGUI_HELPER_HPP
