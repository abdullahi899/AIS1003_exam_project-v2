#include "Imugi.hpp"
#include <imgui_impl_opengl3.h>

ImGuiHelper::ImGuiHelper(GLFWwindow* window, const char* glslVersion) {
    // Setup Dear ImGui context

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;



    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glslVersion);
}

ImGuiHelper::~ImGuiHelper() {
    // Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
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

