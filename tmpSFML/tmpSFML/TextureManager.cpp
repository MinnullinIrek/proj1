#include "./TextureManager.h"

sf::Texture* TextureManager::LoadTexture(const std::string&  fileName) {
    //Image image;
    //image.loadFromFile(String("images/") + fileName);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная image.loadFromFile("images/hero/png");

    //image.createMaskFromColor(Color(41, 33, 59));//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
    //Texture texture;//сфмл текстура

    //texture.loadFromImage(image);//закидываем наше изображение в текстуру
    
    
    if (m_textures.contains(fileName)) {
        return m_textures.at(fileName);
    }
    
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(fileName);
    m_textures[fileName] = texture;
    return texture;
}

TextureManager::~TextureManager() {
    for (auto& pair : m_textures) {
        delete pair.second;
    }
}

//void TextureManager::Draw(SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip) {
//    SDL_RenderCopyEx(Game::renderer, texture, &sourceRectangle, &destinationRectangle, 0.0, NULL, flip);
//}
