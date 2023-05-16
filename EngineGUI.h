#pragma once

#define IMGUI_IMPL_WIN32_DISABLE_GAMEPAD

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <imgui_internal.h>

class EngineGUI
{
public:
	EngineGUI() {}
	~EngineGUI() {}

	void init(void* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext);
	void update();
	void render();
	void shutdown();
};

