#pragma once
#include "Engine.h"
class Object : public Engine
{
	Mesh objectMesh;
	XMFLOAT3 worldPosition;
	XMFLOAT3 scale;
	XMFLOAT3 rotation;

	XMMATRIX worldMatrix;

public:
	Object();
	Object(Mesh& _meshRef);
	Object(Mesh& _meshRef, XMFLOAT3 _worldPosition, XMFLOAT3 _scale, XMFLOAT3 _rotation);

	void setMesh(Mesh& _meshRef) { objectMesh = _meshRef; }
	void setWorldPosition(XMFLOAT3 _worldPosition) { worldPosition = _worldPosition; }
	void setScale(XMFLOAT3 _scale) { scale = _scale; }
	void setRotation(XMFLOAT3 _rotation) { rotation = _rotation; }

	Mesh getMesh() { return &objectMesh; }
	XMFLOAT3 getWorldPosition() { return worldPosition; }
	XMFLOAT3 getScale() { return scale; }
	XMFLOAT3 getRotation() { return rotation; }
	int getVertexCount() { return objectMesh.getVertexCount(); }
	XMMATRIX getWorldMatrix() { return worldMatrix; }

	void Move(XMFLOAT3 movementVect);
	void Render(ID3D11Device* &_g_pd3dDevice, ID3D11DeviceContext* &_g_pImmediateContext, ID3D11Buffer* &_g_pVertexBuffer, ID3D11Buffer* &_g_pIndexBuffer);
};

