#include "./TextureManager.h"

Texture TextureManager::LoadTexture(const char* fileName) {
    Image image;
    image.loadFromFile(String("images/") + fileName);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� image.loadFromFile("images/hero/png");

    //image.createMaskFromColor(Color(41, 33, 59));//������� �������� �����-����� ����, ��� ���� ��� ���������� �� ��������.
    Texture texture;//���� ��������
    texture.loadFromImage(image);//���������� ���� ����������� � ��������
    return texture;
}

//void TextureManager::Draw(SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip) {
//    SDL_RenderCopyEx(Game::renderer, texture, &sourceRectangle, &destinationRectangle, 0.0, NULL, flip);
//}
