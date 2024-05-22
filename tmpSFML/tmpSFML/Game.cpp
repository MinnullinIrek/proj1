#include <iostream>
#include "Header.h"
#include "Game.h"
#include "AssetManager.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "KeyboardControlComponent.h"

EntityManager manager;
AssetManager* Game::assetManager = new AssetManager(&manager);
//SDL_Renderer* Game::renderer;
Event Game::event;

Game::Game() {
    this->isRunning = false;
}

Game::~Game() {
}

bool Game::IsRunning() const {
    return this->isRunning;
}

void Game::Initialize(int width, int height) {
    window = new RenderWindow(VideoMode(width, height), L"Новый проект", Style::Default);

    window->setVerticalSyncEnabled(true);
    LoadLevel(0);

    isRunning = true;
    return;
}

void Game::LoadLevel(int levelNumber) {
    /* Start including new assets to the assetmanager list */
    assetManager->AddTexture("hero", "images/Warrior_Blue.png");
    assetManager->AddTexture("goblin", "images/Torch_Red.png");

    /* Start including entities and also components to them */
    Entity& chopperEntity(manager.AddEntity("hero"));
    //chopperEntity.AddComponent<TransformComponent>(0, 0, 0, 0, 32, 32, 1);
    
    std::map<std::string, Animation> animations;
    animations[std::string("left")] = Animation(Vector2u{ 0, 2 }, 3, 0.005, true);
    animations[std::string("right")] = Animation(Vector2u{ 0, 2 }, 3, 0.005, true);
    animations[std::string("up")] = Animation(Vector2u{ 0, 6 }, 3, 0.005, true);
    animations[std::string("down")] = Animation(Vector2u{ 0, 4 }, 3, 0.005, true);
    
    animations[std::string("left_attack")] = Animation(Vector2u{ 3, 2 }, 3, 0.005, true);
    animations[std::string("right_attack")] = Animation(Vector2u{ 3, 2 }, 3, 0.005, true);
    animations[std::string("up_attack")] = Animation(Vector2u{ 3, 6 }, 3, 0.005, true);
    animations[std::string("down_attack")] = Animation(Vector2u{ 3, 4 }, 3, 0.005, true);

    //std::string id, Vector2i numFrames, const std::map<std::string, Animation>& animations
    chopperEntity.AddComponent<TransformComponent>(0, 0, 0.1, 0.1, 1152 / 6, 1536 / 8, 1);
    chopperEntity.AddComponent<SpriteComponent>("images/Warrior_Blue.png", Vector2i{6, 8}, std::move(animations), true);
    chopperEntity.AddComponent<KeyboardControlComponent>("up", "right", "down", "left", "space");

    //Entity& tankEntity(manager.AddEntity("goblin"));
    //tankEntity.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
    //tankEntity.AddComponent<SpriteComponent>("tank-image");

    //Entity& radarEntity(manager.AddEntity("Radar"));
    //radarEntity.AddComponent<TransformComponent>(720, 15, 0, 0, 64, 64, 1);
    //radarEntity.AddComponent<SpriteComponent>("radar-image", 8, 150, false, true);
}

void Game::ProcessInput() {
    //SDL_PollEvent(&event);
    //switch (event.type) {
    //case SDL_QUIT: {
    //    isRunning = false;
    //    break;
    //}
    //case SDL_KEYDOWN: {
    //    if (event.key.keysym.sym == SDLK_ESCAPE) {
    //        isRunning = false;
    //    }
    //}
    //default: {
    //    break;
    //}
    //}
}

void Game::Update() {
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
        }
        float deltaTime = clock.getElapsedTime().asMilliseconds();//asMicroseconds();
        clock.restart();
        manager.Update(deltaTime);
        Render();
    }
}

void Game::Render() {
    if (manager.HasNoEntities()) {
        return;
    }
    window->clear(Color::Cyan);
    manager.Render();
    window->display();
}

void Game::Destroy() {
    //SDL_DestroyRenderer(renderer);
    //SDL_DestroyWindow(window);
    //SDL_Quit();
}
