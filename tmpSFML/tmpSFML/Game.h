#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
using namespace sf;


#include "./Entity.h"
#include "./Component.h"
#include "./EntityManager.h"

class AssetManager;

class Game {
private:
    Clock clock;
    float time = 0;
    bool isRunning;
    Game();
public:
    RenderWindow* window;
public:
    static Game& instance() {
        static Game game;
        return game;
    }

    ~Game();
    int ticksLastFrame = 0;
    bool IsRunning() const;
    //static SDL_Renderer* renderer;
    static AssetManager* assetManager;
    static Event event;
    void LoadLevel(int levelNumber);
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};

#endif
