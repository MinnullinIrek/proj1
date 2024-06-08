#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "Header.h"
#include "EntityManager.h"
#include "Component.h"
//#include "../Game.h"


class TransformComponent : public Component {
public:
    Vector2f position2 = {0,0};

    Vector2f position;
    Vector2f velocity;
    Vector2f size;
    Vector2f scale;

    TransformComponent(int posX, int posY, float velX, float velY, int w, int h, int s) {
        position2 = Vector2f(posX, posY);
        velocity = Vector2f(velX, velY);
        size = Vector2f( w, h );
        scale = Vector2f( s, s );
    }

    void Initialize() override {

    }

    void Update(float deltaTime) override {
        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;
    }
};

#endif
