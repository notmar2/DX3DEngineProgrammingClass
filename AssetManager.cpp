#include "AssetManager.h"

AssetManager::AssetManager() {

}

void AssetManager::SaveMeshToMeshMap(std::string meshName, Mesh mesh) {
	simpleMeshMap[meshName] = mesh;
}

Mesh* AssetManager::LoadMeshFromMeshMap(std::string meshName) {
	return &simpleMeshMap[meshName];
}