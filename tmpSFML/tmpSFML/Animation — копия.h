#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
using namespace sf;


class Animation {
public:
    Vector2u startFrame = {0, 0};
    unsigned int numFrames = 1;
    float animationSpeed = 1;
    bool isCickled = false;
    bool isReverse = false;
    Animation();
    Animation(Vector2u startFrame, int numFrames, float animationSpeed, bool isCickled = false);
    Animation(Vector2u startFrame, int numFrames, float animationSpeed, bool isClikled, bool isReverse);
};

#endif
