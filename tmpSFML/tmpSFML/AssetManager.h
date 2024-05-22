#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>
#include "./TextureManager.h"
#include "./EntityManager.h"

#include <SFML/Graphics.hpp>
using namespace sf;


class AssetManager {
private:
    EntityManager* manager;
    std::map<std::string, Texture> textures;
public:
    AssetManager(EntityManager* manager);
    ~AssetManager(){};
    void ClearData();
    void AddTexture(std::string textureId, const char* filePath);
    Texture GetTexture(std::string textureId);
};

#endif
