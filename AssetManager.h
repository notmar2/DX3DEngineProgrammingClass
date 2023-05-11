#pragma once
#include"Structs.h"
#include <map>
#include <string>
class AssetManager
{
	std::map<std::string, SimpleVertex*> simpleMeshMap;
public:
	AssetManager();
	void SaveSimpleMesh(std::string meshName, SimpleVertex* mesh);
	SimpleVertex* LoadSimpleMesh(std::string meshName);
};

