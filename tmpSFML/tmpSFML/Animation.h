#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
using namespace sf;


class Animation {
public:
    Vector2u startFrame;
    unsigned int numFrames;
    float animationSpeed;
    bool isCickled;
    Animation();
    Animation(Vector2u startFrame, int numFrames, float animationSpeed, bool isCickled = false);
};

#endif
