#ifndef MAP_H
#define MAP_H

#include <vector>

#include "Entity.h"

#include <SFML\Graphics.hpp>
#pragma once

using namespace sf;

const int HEIGHT_MAP = 25;//размер карты высота
const int WIDTH_MAP = 40;//размер карты ширина 
//String TileMap[HEIGHT_MAP] = {
//"0000000000000000000000000000000000000000",
//"0                                      0",
//"0                                     0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0000000000000000000000000000000000000000",
//};

class Map 
{
public:
	Map();
	Map(String map);
	~Map() {};
	void Update(float dt);
	void Render();
	void loadTileWall(const char* id, const Vector2f& cord, const Vector2i& size);
	void loadTileFloor(const char* id, Vector2f cord, Vector2i size);
	void loadMap();
	void loadMapFromStr(String map);
	
	std::vector<Entity> getEntities();
	Vector2i getSize();
	Entity* getTile(Vector2f cord);
private:
	Vector2i m_size;
	int entity_count = 0;
	std::vector<Entity> m_walls;
	
};

#endif