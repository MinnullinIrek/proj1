#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "TextureManager.h"
#include "AssetManager.h"
#include "Animation.h"
#include "Header.h"


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
    std::string currentAnimationName;

    Image image;//сфмл изображение
    Texture texture1;//сфмл текстура
    //Sprite sprite;//сфмл спрайт


public:
    SpriteComponent(std::string assetTextureId) {
        this->isAnimated = true;
        this->isFixed = false;
        SetTexture(assetTextureId);
    }

    SpriteComponent(std::string assetTextureId, bool isFixed) {
        this->isAnimated = false;
        this->isFixed = isFixed;
        SetTexture(assetTextureId);
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
        currentFrame = animations[currentAnimation].numFrames;
        animationIndex = animations[currentAnimation].startFrame;
        animationSpeed = animations[currentAnimation].animationSpeed;
        currentAnimationName = currentAnimation;
        currentFrame = 0;
    }

    void SetTexture(std::string assetTextureId) {
        //texture = Game::assetManager->GetTexture(assetTextureId);
        texture1.loadFromFile(assetTextureId);//закидываем наше изображение в текстуру

    }

    void Initialize() override {
        transform = owner->GetComponent<TransformComponent>();
        //sprite.setTexture(*texture);
        auto w = transform->size.x * transform->scale.x;
        auto h = transform->size.y * transform->scale.y;
        sprite.setTexture(texture1);//заливаем спрайт текстурой
        sprite.setTextureRect(IntRect(0, 0, w, h)); //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
        sprite.scale(0.5, 0.5);
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
        const Animation& animation = animations.at(currentAnimation);
        auto startFrame = animation.startFrame;
        auto w = transform->size.x * transform->scale.x;
        auto h = transform->size.y * transform->scale.y;
        sprite.setPosition(transform->position2);
        sprite.setTextureRect(IntRect(w * (int(currentFrame) + startFrame.x), h*startFrame.y, w, h));
        Game::instance().window->draw(sprite);
    }
};

#endif
