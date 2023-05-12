#pragma once
#include"Mesh.h"
#include <map>
#include <string>
class AssetManager
{
	std::map<std::string, Mesh> simpleMeshMap;
public:
	AssetManager();
	void SaveMeshToMeshMap(std::string meshName, Mesh mesh);
	Mesh* LoadMeshFromMeshMap(std::string meshName);
};

