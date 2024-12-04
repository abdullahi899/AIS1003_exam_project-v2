#include "Imgui.hpp"
#include <imgui_impl_opengl3.h>

ImGuiHelper::ImGuiHelper(GLFWwindow* window, const char* glslVersion) {


    ImGui::CreateContext();
    const ImGuiIO& io = ImGui::GetIO(); (void)io;


    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glslVersion);
}

void ImGuiHelper::beginFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiHelper::render() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

