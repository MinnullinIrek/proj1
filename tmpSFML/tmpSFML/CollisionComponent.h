#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include <SFML/Graphics.hpp>

#include "Component.h"

using namespace sf;

class TransformComponent;
class SpriteComponent;


#pragma once
class CollisionComponent : public Component
{
public:
	bool isMoving = false;
	
	CollisionComponent();
	CollisionComponent(bool isMoving): isMoving(isMoving) {};
	~CollisionComponent() {};

	bool checkCollision(float changePos) ;
	void Update(float deltaTime)  override {};
	void Initialize() override;
	Vector2f getWidth();
	Vector2f getHeigth();

private:
	void updateCoord();

	Vector2f heigth; //высота
	Vector2f width; //ширина
	TransformComponent* transform;
	SpriteComponent* sprite;
};

#endif