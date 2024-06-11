#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Entity;

class Component {
public:
    Entity* owner;
    virtual ~Component() {}
    virtual void Initialize() {}
    virtual void Update(float deltaTime) {}
    virtual void Render() {}
};

#endif
