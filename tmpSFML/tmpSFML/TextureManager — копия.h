#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "./Game.h"

class TextureManager {
public:
    static Texture LoadTexture(const char* fileName);
    //static void Draw(Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip);
};

#endif
