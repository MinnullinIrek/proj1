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
//    Texture texture;//���� ��������
//    texture.loadFromFile(filePath);//���������� ���� ����������� � ��������
//    textures.emplace(textureId, texture);
//}
//
//Texture AssetManager::GetTexture(std::string textureId) {
//    //return textures[textureId];
//    Texture texture;//���� ��������
//    texture.loadFromFile(textureId);
//    //textures.emplace(textureId, texture);
//    return texture;
//}
