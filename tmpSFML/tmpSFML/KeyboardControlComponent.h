#ifndef KEYBOARDCONTROLCOMPONENT_H
#define KEYBOARDCONTROLCOMPONENT_H

//#include "../Game.h"
#include "EntityManager.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class KeyboardControlComponent : public Component {
public:
    std::string upKey;
    std::string downKey;
    std::string rightKey;
    std::string leftKey;
    std::string shootKey;
    TransformComponent* transform;
    SpriteComponent* sprite;

    KeyboardControlComponent(){

    }


    void Initialize() override {
        transform = owner->GetComponent<TransformComponent>();
        sprite = owner->GetComponent<SpriteComponent>();
    }

    void Update(float deltaTime) override {
        bool changed = false;
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            //transform->position2.x += transform->velocity.x /** deltaTime*/;
            sprite->SetPosition(Vector2f(sprite->GetPosition().x + transform->velocity.x, sprite->GetPosition().y));
            owner->GetComponent<SpriteComponent>()->Play("right");
            changed = true;
        }
        else
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            changed = true;
            owner->GetComponent<SpriteComponent>()->Play("left");
            //transform->position2.x -= transform->velocity.x * deltaTime;
            sprite->SetPosition(Vector2f(sprite->GetPosition().x - transform->velocity.x, sprite->GetPosition().y));

        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            changed = true;
            owner->GetComponent<SpriteComponent>()->Play("down");
            //transform->position2.y += transform->velocity.y * deltaTime;
            sprite->SetPosition(Vector2f(sprite->GetPosition().x, sprite->GetPosition().y + transform->velocity.y));
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            changed = true;
            owner->GetComponent<SpriteComponent>()->Play("up");
            //transform->position2.y -= transform->velocity.y * deltaTime;
            sprite->SetPosition(Vector2f(sprite->GetPosition().x, sprite->GetPosition().y - transform->velocity.y));
        }
        if (changed) {
            //Game::instance().view.setCenter(sprite->GetPosition()/*transform->position2*/);
        }
    }
};

#endif
