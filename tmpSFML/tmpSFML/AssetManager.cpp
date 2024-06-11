//#include "./AssetManager.h"
//#include "TransformComponent.h"
//
//AssetManager::AssetManager(EntityManager* manager) : manager(manager) {
//
//}
//
//void AssetManager::ClearData() {
//    textures.clear();
//}
//
//void AssetManager::AddTexture(std::string textureId, const char* filePath) {
//    //textures.emplace(textureId, TextureManager::LoadTexture(filePath));
//    Texture texture;//сфмл текстура
//    texture.loadFromFile(filePath);//закидываем наше изображение в текстуру
//    textures.emplace(textureId, texture);
//}
//
//Texture AssetManager::GetTexture(std::string textureId) {
//    //return textures[textureId];
//    Texture texture;//сфмл текстура
//    texture.loadFromFile(textureId);
//    //textures.emplace(textureId, texture);
//    return texture;
//}
