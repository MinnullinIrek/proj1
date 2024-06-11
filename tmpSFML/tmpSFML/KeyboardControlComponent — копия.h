#ifndef KEYBOARDCONTROLCOMPONENT_H
#define KEYBOARDCONTROLCOMPONENT_H

//#include "../Game.h"
#include "EntityManager.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"

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
            changed = true;
            owner->GetComponent<SpriteComponent>()->Play("right");
            float changePos = transform->velocity.x * deltaTime;
            if(owner->GetComponent<CollisionComponent>()->checkCollision(changePos))
                transform->position2.x += changePos;
        }
        else
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            changed = true;
            owner->GetComponent<SpriteComponent>()->Play("left");
            float changePos = transform->velocity.x * deltaTime;
            if (owner->GetComponent<CollisionComponent>()->checkCollision(changePos))
                transform->position2.x -= changePos;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            changed = true;
            owner->GetComponent<SpriteComponent>()->Play("down");
            float changePos = transform->velocity.y * deltaTime;
            if (owner->GetComponent<CollisionComponent>()->checkCollision(changePos))
                transform->position2.y += changePos;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            changed = true;
            owner->GetComponent<SpriteComponent>()->Play("up");
            float changePos = transform->velocity.y * deltaTime;
            if (owner->GetComponent<CollisionComponent>()->checkCollision(changePos))
                transform->position2.y -= changePos;
        }
        if (changed) {
            Game::instance().view.setCenter(transform->position2);
        }
    }
};

#endif
