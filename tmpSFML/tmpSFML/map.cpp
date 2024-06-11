#include "map.h"

#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "Game.h"
#include "CollisionComponent.h"
#include "TileComponent.h"
#include <string>
Map::Map() {

}

//Map::Map(String map) {
//	loadMapFromStr(map);
//}
/**/

std::vector<Entity> Map::getEntities() {
	return m_tiles;
}

void Map::loadTileWall(const char* id, const Vector2f& cord, const Vector2i& size) {
	m_tiles.push_back(Entity(Game::instance().getManager().AddEntity("wall" + std::to_string(entity_count))));
	
	m_tiles[entity_count].AddComponent<TransformComponent>(cord.x, cord.y, 0, 0, size.x, size.y, 1);
	m_tiles[entity_count].AddComponent<TileComponent>(std::string(id), cord, size);
	m_tiles[entity_count].AddComponent<CollisionComponent>(false);
	/*Game::instance().getManager().getEntity("wall" + std::to_string(entity_count)).AddComponent<TransformComponent>(cord.x, cord.y, 0, 0, size.x, size.y, 1);
	Game::instance().getManager().getEntity("wall" + std::to_string(entity_count)).AddComponent<SpriteComponent>(std::string(id), std::move(animations));
	Game::instance().getManager().getEntity("wall" + std::to_string(entity_count)).AddComponent<CollisionComponent>(false);
	*///m_tiles[entity_count].GetComponent<SpriteComponent>()->Play("wall");
	
	entity_count++;

}


void Map::Render() {
	for (auto& tile : m_tiles) {
		tile.Render();
	}
}
