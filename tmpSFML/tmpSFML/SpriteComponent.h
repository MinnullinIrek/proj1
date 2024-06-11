#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "TextureManager.h"
#include "AssetManager.h"
#include "Animation.h"
#include "Header.h"
#include "TransformComponent.h"

#include <SFML/Graphics.hpp>
using namespace sf;



class SpriteComponent : public Component {
private:
    TransformComponent* transform;
    Texture* texture;
    Sprite sprite;
    bool isAnimated;
    Vector2i numFrames;
    float currentFrame;
    int animationSpeed;
    bool isFixed;
    Vector2u animationIndex;
    std::string currentAnimation = "left";
    std::map<std::string, Animation> animations;
   
    
    Image image;//сфмл изображение
    Texture texture1;//сфмл текстура
    //Sprite sprite;//сфмл спрайт


public:
    SpriteComponent(std::string assetTextureId) {
        this->isAnimated = true;
        this->isFixed = false;
        SetTexture(assetTextureId);
    }

    SpriteComponent(std::string assetTextureId, std::map<std::string, Animation>&& animation)
        : animations(animation)
    {
        this->isAnimated = true;
        this->isFixed = false;
        SetTexture(assetTextureId);
    }

    SpriteComponent(std::string assetTextureId, bool isFixed) {
        this->isAnimated = false;
        this->isFixed = isFixed;
        SetTexture(assetTextureId);
    }

    SpriteComponent(std::string assetTextureId, Vector2f pos, Vector2i size, std::map<std::string, Animation>&& animation):
        animations(animation) //for floor
    { 
        this->isAnimated = true;
        this->isFixed = false;
        SetTexture(assetTextureId);
        
        sprite.setTextureRect(IntRect(Vector2i(pos), size));
        sprite.setPosition(pos);
    }

    SpriteComponent(std::string id, Vector2i numFrames, std::map<std::string, Animation>&& animations, bool isAnimated) :
    animations(animations)
    {
        this->isAnimated = isAnimated;
        this->numFrames = numFrames;
        this->animationSpeed = animationSpeed;
        this->isFixed = isFixed;
        Play(animations.cbegin()->first);
        SetTexture(id);
    }

    void Play(const std::string& currentAnimation) {
        if (this->isAnimated == false)
            return;
        currentFrame = animations[currentAnimation].numFrames;
        animationIndex = animations[currentAnimation].startFrame;
        animationSpeed = animations[currentAnimation].animationSpeed;
        this->currentAnimation = currentAnimation;
        currentFrame = 0;
    }

    std::string getDirection() { 
    //for Collision to define direction, that will be used to check future position
        return currentAnimation;
    }

    void SetTexture(std::string assetTextureId) {
        texture1.loadFromFile(assetTextureId);
    }

    void Initialize() override {
        transform = owner->GetComponent<TransformComponent>();
        if (transform == nullptr) {
            return;
        }
        auto w = transform->size.x;
        auto h = transform->size.y;
        sprite.setTexture(texture1);
        //sprite.setTextureRect(IntRect(0, 0, w, h));
        //if (transform->scale.x != 1 && transform->velocity.y != 1) {
            sprite.scale(w / sprite.getLocalBounds().width, h / sprite.getLocalBounds().height);
        //}
        //else {
          //  sprite.scale(transform->scale);
        //}
    }

    void Update(float deltaTime) override {
        if (isAnimated) {
            const Animation& animation = animations.at(currentAnimation);
            currentFrame += animation.animationSpeed * deltaTime;
            if (currentFrame > animation.numFrames) {
                currentFrame = animation.isCickled ? 0 : animation.numFrames;
            }
        }
    }

    void Render() override {
        if (this->isAnimated == true) {
            const Animation& animation = animations.at(currentAnimation);
            auto startFrame = animation.startFrame;
            auto w = transform->size.x * transform->scale.x;
            auto h = transform->size.y * transform->scale.y;
            sprite.setPosition(transform->position2);
            if (!animation.isReverse) {
                sprite.setTextureRect(IntRect(w * (int(currentFrame) + startFrame.x), h * startFrame.y, w, h));
            }
            else {
                sprite.setTextureRect(IntRect((w * (int(currentFrame) + startFrame.x)) + w, h * startFrame.y, -w, h));
            }
        }
        Game::instance().window->draw(sprite);
    }
};

#endif
