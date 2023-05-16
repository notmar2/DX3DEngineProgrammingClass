#pragma once

#define IMGUI_IMPL_WIN32_DISABLE_GAMEPAD

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <imgui_internal.h>
#include <Windows.h>

class EngineGUI
{
	bool show_demo_window;
	bool show_another_window;
	ImVec4 clear_color;
 public:
	 EngineGUI() { 
		show_demo_window = true;
		show_another_window = false;
		clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	 }
	~EngineGUI() {}

	void init(HWND* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext);
	void update();
	void render();
	void shutdown();
};

