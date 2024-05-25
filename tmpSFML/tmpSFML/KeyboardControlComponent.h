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

    KeyboardControlComponent() {

    }


    void Initialize() override {
        transform = owner->GetComponent<TransformComponent>();
        sprite = owner->GetComponent<SpriteComponent>();
    }

    void Update(float deltaTime) override {
        bool changed = false;
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            transform->position2.x += transform->velocity.x * deltaTime;
            changed = true;
        }
        else
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            changed = true;

            transform->position2.x -= transform->velocity.x * deltaTime;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            changed = true;

            transform->position2.y += transform->velocity.y * deltaTime;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            changed = true;

            transform->position2.y -= transform->velocity.y * deltaTime;
        }
        if (changed) {
            Game::instance().view.setCenter(transform->position2);
        }
    }
};

#endif
