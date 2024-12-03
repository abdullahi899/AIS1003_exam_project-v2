#ifndef IMGUI_HELPER_HPP
#define IMGUI_HELPER_HPP

#include "imgui_impl_glfw.h"

class ImGuiHelper {
public:
    explicit ImGuiHelper(GLFWwindow *window, const char *glslVersion = "#version 130");

    ~ImGuiHelper();

    // Begin a new ImGui frame
    void beginFrame();

    // Render ImGui components
    void render();

    // Add ImGui components (User-defined UI logic goes here)
    void drawUI();

private:
    // No copying or moving
    ImGuiHelper(const ImGuiHelper &) = delete;

    ImGuiHelper &operator=(const ImGuiHelper &) = delete;
};

#endif // IMGUI_HELPER_HPP
