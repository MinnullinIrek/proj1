#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

//#include "./Game.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class TextureManager {
public:
    sf::Texture* LoadTexture(const std::string& fileName);
    //static void Draw(Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip);
    ~TextureManager();
private:

    std::unordered_map<std::string, sf::Texture*> m_textures;

};

#endif
