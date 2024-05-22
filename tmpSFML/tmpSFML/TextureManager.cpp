#include "./TextureManager.h"

Texture TextureManager::LoadTexture(const char* fileName) {
    Image image;
    image.loadFromFile(String("images/") + fileName);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная image.loadFromFile("images/hero/png");

    //image.createMaskFromColor(Color(41, 33, 59));//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
    Texture texture;//сфмл текстура
    texture.loadFromImage(image);//закидываем наше изображение в текстуру
    return texture;
}

//void TextureManager::Draw(SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip) {
//    SDL_RenderCopyEx(Game::renderer, texture, &sourceRectangle, &destinationRectangle, 0.0, NULL, flip);
//}
