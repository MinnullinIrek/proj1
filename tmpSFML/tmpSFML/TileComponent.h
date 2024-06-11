#pragma once

#include "TextureManager.h"
#include "AssetManager.h"
#include "Animation.h"
#include "Header.h"
#include "TransformComponent.h"
#include "Game.h"

#include <SFML/Graphics.hpp>
using namespace sf;

class TileComponent : public Component {
private:
    Sprite sprite;
public:

    TileComponent(std::string assetTextureId, const Vector2f& pos, const Vector2i& size ) 
    {
        sf::Texture* texture = Game::instance().textureManager.LoadTexture(assetTextureId);
        sprite.setTexture(*texture);

        sprite.scale(size.x / sprite.getLocalBounds().width, size.y / sprite.getLocalBounds().height);
        sprite.setPosition(pos);
    }

    void Render() override {
        Game::instance().window->draw(sprite);
    }
};
