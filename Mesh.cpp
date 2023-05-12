#include "Mesh.h"

/*
Mesh::Mesh(SimpleVertex* _vertexBuffer, int _vertexArraySize, WORD* _indexBuffer, int _indexArraySize)
{
    vertexBuffer = new SimpleVertex[_vertexArraySize];
    indexBuffer = new WORD[_indexArraySize];

    vertexArraySize = _vertexArraySize;
    indexArraySize = _indexArraySize;
  
    memcpy(vertexBuffer, _vertexBuffer, _vertexArraySize * sizeof(SimpleVertex));
    memcpy(indexBuffer, _indexBuffer, _indexArraySize * sizeof(WORD));
}

Mesh::Mesh(Mesh* originalMesh)
{
    int vertexCount = originalMesh->getVertexCount();
    vertexBuffer = new SimpleVertex[vertexCount];
    memcpy(vertexBuffer, originalMesh->getVertexBuffer(), vertexCount * sizeof(SimpleVertex));

    int indexCount = originalMesh->getIndexCount();
    indexBuffer = new WORD[indexCount];
    memcpy(indexBuffer, originalMesh->getIndexBuffer(), indexCount * sizeof(WORD));
}

Mesh::~Mesh() {
    delete[] vertexBuffer;
    delete[] indexBuffer;
}
*/

Mesh::Mesh(std::vector<SimpleVertex> _vertexBuffer, std::vector<WORD> _indexBuffer) :
    vertexBuffer(_vertexBuffer),
    indexBuffer(_indexBuffer)
{}

Mesh::Mesh(Mesh* meshPtr): vertexBuffer(meshPtr->getVertexVector()), indexBuffer(meshPtr->getIndexVector()){

}