#include "Animation.h"

Animation::Animation() {

}

Animation::Animation(Vector2u startFrame, int numFrames, float animationSpeed, bool isCickled) {
    this->startFrame = startFrame;
    this->numFrames = numFrames;
    this->animationSpeed = animationSpeed;
    this->isCickled = isCickled;
    
}

Animation::Animation(Vector2u startFrame, int numFrames, float animationSpeed, bool isClikled, bool isReverse) {
    this->startFrame = startFrame;
    this->numFrames = numFrames;
    this->animationSpeed = animationSpeed;
    this->isCickled = isCickled;
    this->isReverse = isReverse;
}
