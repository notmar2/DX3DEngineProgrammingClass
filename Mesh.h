#pragma once
#include "Structs.h"
#include <cstdio>
#include <vector>
class Mesh
{
	/*
	SimpleVertex* vertexBuffer;
	WORD* indexBuffer;
	int vertexArraySize, indexArraySize;
public:
	Mesh(SimpleVertex* _vertexBuffer, int _vertexArraySize, WORD* _indexBuffer, int _indexArraySize);
	Mesh::Mesh(Mesh* originalMesh);
	~Mesh();
	SimpleVertex* getVertexBuffer() const { return vertexBuffer; }
	WORD* getIndexBuffer() const { return indexBuffer;  }
	int getVertexCount() {
		return vertexArraySize / sizeof(SimpleVertex);
	}
	int getIndexCount() {
		return indexArraySize / sizeof(WORD);
	}
	*/

	std::vector<SimpleVertex> vertexBuffer;
	std::vector<WORD> indexBuffer;
public:
	Mesh() {}
	Mesh(std::vector<SimpleVertex> _vertexBuffer, std::vector<WORD> _indexBuffer);
	Mesh(Mesh* meshPtr);

	std::vector<SimpleVertex>& getVertexVector() { return vertexBuffer; }
	std::vector<WORD>& getIndexVector() { return indexBuffer; }

	SimpleVertex* getVertexBuffer() {
		SimpleVertex* vertexArray = new SimpleVertex[vertexBuffer.size()];
		for (int i = 0; i < vertexBuffer.size(); i++) {
			vertexArray[i] = vertexBuffer[i];
		}
		return vertexArray;
	}

	WORD* getIndexBuffer() {
		WORD* indexArray = new WORD[indexBuffer.size()];
		for (int i = 0; i < indexBuffer.size(); i++) {
			indexArray[i] = indexBuffer[i];
		}
		return indexArray;
	}
	int getVertexCount() {
		return vertexBuffer.size();
	}
};