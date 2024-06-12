#include "./TextureManager.h"

sf::Texture* TextureManager::LoadTexture(const std::string&  fileName) {
    //Image image;
    //image.loadFromFile(String("images/") + fileName);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� image.loadFromFile("images/hero/png");

    //image.createMaskFromColor(Color(41, 33, 59));//������� �������� �����-����� ����, ��� ���� ��� ���������� �� ��������.
    //Texture texture;//���� ��������

    //texture.loadFromImage(image);//���������� ���� ����������� � ��������
    
    
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
