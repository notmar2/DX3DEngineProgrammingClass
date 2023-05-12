#include "Object.h"

Object::Object() {
	worldPosition = XMFLOAT3(1.0f, 1.0f, 1.0f);
	scale = XMFLOAT3(1.0f, 1.0f, 1.0f);
	rotation = XMFLOAT3(1.0f, 1.0f, 1.0f);
}

Object::Object(Mesh& _meshRef) : objectMesh(_meshRef) {
	worldPosition = XMFLOAT3(1.0f, 1.0f, 1.0f);
	scale = XMFLOAT3(1.0f, 1.0f, 1.0f);
	rotation = XMFLOAT3(1.0f, 1.0f, 1.0f);
}

Object::Object(Mesh& _meshRef, XMFLOAT3 _worldPosition, XMFLOAT3 _scale, XMFLOAT3 _rotation) :
	objectMesh(_meshRef),
	worldPosition(_worldPosition),
	scale(_scale),
	rotation(_rotation)
{

}

void Object::Move(XMFLOAT3 movementVect) {

}

void Object::UpdateSubresources(D3D11_BUFFER_DESC& bd) {
	// Logica en caso de ser necesario actualizar la informacion de los buffers o crear mas
}

void Object::Render() {
	// En un futuro contendra la logica de cargar los assets y mandarselos al renderizador principal que estara en
	// El metodo render del engine
}