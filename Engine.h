#pragma once
#include "DEF.h"

class Object;

class Engine
{
public:
	Engine();
	HINSTANCE							g_hInst;
	HWND								g_hWnd;
	D3D_DRIVER_TYPE						g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL					g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device*						g_pd3dDevice;
	ID3D11DeviceContext*				g_pImmediateContext;
	IDXGISwapChain*						g_pSwapChain;
	ID3D11RenderTargetView*				g_pRenderTargetView;
	ID3D11Texture2D*					g_pDepthStencil;
	ID3D11DepthStencilView*				g_pDepthStencilView;
	ID3D11VertexShader*					g_pVertexShader;
	ID3D11PixelShader*					g_pPixelShader;
	ID3D11InputLayout*					g_pVertexLayout;
	ID3D11Buffer*						g_pVertexBuffer;
	ID3D11Buffer*						g_pIndexBuffer;
	ID3D11Buffer*						g_pCBNeverChanges;
	ID3D11Buffer*						g_pCBChangeOnResize;
	ID3D11Buffer*						g_pCBChangesEveryFrame;
	ID3D11ShaderResourceView*			g_pTextureRV;
	ID3D11SamplerState*					g_pSamplerLinear;
	XMMATRIX							g_World;
	XMMATRIX							g_View;
	XMMATRIX							g_Projection;
	XMFLOAT4							g_vMeshColor;
	AssetManager*						assetManager;

	//DXMETHODS
	HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow);
	HRESULT InitDevice();
	void CleanupDevice();
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	void Render();
	HRESULT CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	
	//CUSTOMETHODS
	void loadBuffers();
};

