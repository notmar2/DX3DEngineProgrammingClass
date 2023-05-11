#include "AssetManager.h"

AssetManager::AssetManager() {

}

void AssetManager::SaveSimpleMesh(std::string meshName, SimpleVertex* mesh) {
	simpleMeshMap[meshName] = mesh;
}

SimpleVertex* AssetManager::LoadSimpleMesh(std::string meshName) {
	return simpleMeshMap[meshName];
}