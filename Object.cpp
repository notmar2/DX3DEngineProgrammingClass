#include "Object.h"

Object::Object() {
	worldPosition = XMFLOAT3(1.0f, 1.0f, 1.0f);
	scale = XMFLOAT3(1.0f, 1.0f, 1.0f);
	rotation = XMFLOAT3(1.0f, 1.0f, 1.0f);
	worldMatrix = XMMatrixIdentity();
}

Object::Object(Mesh& _meshRef) : objectMesh(_meshRef) {
	worldPosition = XMFLOAT3(1.0f, 1.0f, 1.0f);
	scale = XMFLOAT3(1.0f, 1.0f, 1.0f);
	rotation = XMFLOAT3(1.0f, 1.0f, 1.0f);
	worldMatrix = XMMatrixIdentity();
}

Object::Object(Mesh& _meshRef, XMFLOAT3 _worldPosition, XMFLOAT3 _scale, XMFLOAT3 _rotation) :
	objectMesh(_meshRef),
	worldPosition(_worldPosition),
	scale(_scale),
	rotation(_rotation)
{
	worldMatrix = XMMatrixIdentity();
}

void Object::Move(XMFLOAT3 movementVect) {
	worldMatrix = worldMatrix * XMMatrixTranslationFromVector(XMLoadFloat3(&movementVect));
}

void Object::Render(ID3D11Device* &_g_pd3dDevice, ID3D11DeviceContext* &_g_pImmediateContext,ID3D11Buffer* &_g_pVertexBuffer, ID3D11Buffer* &_g_pIndexBuffer) {
	HRESULT hr;
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * 24;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = objectMesh.getVertexBuffer();
	hr = _g_pd3dDevice->CreateBuffer(&bd, &InitData, &_g_pVertexBuffer);
	UINT stride = sizeof(SimpleVertex);
	UINT offset = 0;
	_g_pImmediateContext->IASetVertexBuffers(0, 1, &_g_pVertexBuffer, &stride, &offset);

	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(WORD) * 36;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	InitData.pSysMem = objectMesh.getIndexBuffer();
	hr = _g_pd3dDevice->CreateBuffer(&bd, &InitData, &_g_pIndexBuffer);
	_g_pImmediateContext->IASetIndexBuffer(_g_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);
	hr = _g_pd3dDevice->CreateBuffer(&bd, &InitData, &_g_pVertexBuffer);

	_g_pImmediateContext->DrawIndexed(36, 0, 0);
}