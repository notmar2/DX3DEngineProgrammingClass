#pragma once
#include "DEF.h"
class Object
{
	Mesh objectMesh;
	XMFLOAT3 worldPosition;
	XMFLOAT3 scale;
	XMFLOAT3 rotation;

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

	void Move(XMFLOAT3 movementVect);
	void UpdateSubresources(D3D11_BUFFER_DESC& bd);
	void Render();
};

