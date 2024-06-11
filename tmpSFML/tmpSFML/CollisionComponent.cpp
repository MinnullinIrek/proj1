#include "CollisionComponent.h"
#include "Entity.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "Game.h"
#include "EntityManager.h"
#include "map.h"

void CollisionComponent::Initialize() {
	transform = owner->GetComponent<TransformComponent>();
	sprite = owner->GetComponent<SpriteComponent>();
	this->updateCoord();
}

bool CollisionComponent::checkCollision(float changePos) {
	if (!isMoving)
		return false;

	this->updateCoord();
	std::string direction = sprite->getDirection();
	std::vector<Entity> enties = Game::instance().getMap().getEntities();
	for (auto& entity : enties) {
		
		CollisionComponent* collision_comp = entity.GetComponent<CollisionComponent>();
		if (collision_comp != nullptr) {
			Vector2f cd_width = collision_comp->getWidth();
			Vector2f cd_heigth = collision_comp->getHeigth();
			if (direction == "up") {
				if (heigth.x - changePos <= cd_heigth.y && heigth.x - changePos >= cd_heigth.x) { //check future up y position
					if (width.x >= cd_width.x && width.x <= cd_width.y
					|| width.y >= cd_width.x && width.y <= cd_width.y)
					{
						return false;
					}
				}
			}
			else if (direction == "down") {
				if (heigth.y + changePos >= cd_heigth.x && heigth.y + changePos <= cd_heigth.y) {
					if (width.x >= cd_width.x && width.x <= cd_width.y
					|| width.y >= cd_width.x && width.y <= cd_width.y)
					{
						return false;
					}
				}
			}
			else if (direction == "right") {
				if (width.y + changePos >= cd_width.x && width.y + changePos <= cd_width.y) { //check future right x position
					if (heigth.x >= cd_heigth.x && heigth.x <= cd_heigth.y
					|| heigth.y >= cd_heigth.x && heigth.y <= cd_heigth.y)
					{
						return false;
					}
				}
			}
			else if (direction == "left") {
				if (width.x - changePos <= cd_width.y && width.x - changePos >= cd_width.x) { //check future left x position
					if (heigth.x >= cd_heigth.x && heigth.x <= cd_heigth.y 
					|| heigth.y >= cd_heigth.x && heigth.y <= cd_heigth.y)
					{
						return false;
					}
				}
			}
		}
	
	}
	
	return true;
}


void CollisionComponent::updateCoord() {
	if (transform == nullptr) 
		return;
	//m_rect = sf::FloatRect(left, top, width, height);
	width = Vector2f(transform->position.x, transform->position.x + transform->size.x);
	heigth = Vector2f(transform->position.y, transform->position.y + transform->size.y);
}

Vector2f CollisionComponent::getWidth() {
	return width;
}

Vector2f CollisionComponent::getHeigth() {
	return heigth;
}

sf::FloatRect CollisionComponent::getRect()
{
	return m_rect;
}


void CollisionComponent::checkCollisions() {
	checkWallCollision();
	checkUnitCollision();
}

void CollisionComponent::checkWallCollision() {
	//std::vector<Entity*> collidedWalls;

	//auto& walls = Game::instance().getMap().getWalls();
	//for (const auto& wall : walls) {
	//	auto wallRect = wall->getComponent<CollisionComponent>()->getRect();

	//	if (m_rect.intersects(wallRect)) {
	//		collidedWalls.push_back(wall);
	//	}
	//}
	//wallsCollision(collidedWalls);

}

void CollisionComponent::checkUnitCollision() {
	//можно пока оставить
}

void CollisionComponent::wallsCollision(const std::vector<Entity*>& walls) {



}

void CollisionComponent::unitsCollision(const std::vector<Entity*>& units) {

}
