#include "map.h"

#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "Game.h"
#include "CollisionComponent.h"

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

void Map::loadTileWall(const char* id, Vector2f cord, Vector2i size) {
	//auto& game = Game::instance();
	
	Game::instance().assetManager->AddTexture("wall", id);
	
	std::map<std::string, Animation> animations;
	m_tiles.push_back(Entity(Game::instance().getManager().AddEntity("wall" + std::to_string(entity_count))));
	animations["left"] = Animation();
	
	m_tiles[entity_count].AddComponent<TransformComponent>(cord.x, cord.y, 0, 0, size.x, size.y, 1);
	m_tiles[entity_count].AddComponent<SpriteComponent>(std::string(id), std::move(animations));
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
