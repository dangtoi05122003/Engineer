#include "core/Game.h"
#include <SDL.h>
#include "utils/Logger.h"

Game::Game() : running(false) {}

Game::~Game() {
    clean();
}

bool Game::init() {
    if (!window.create("Game", 800, 600)) {
        Logger::error("Khong the khoi tao Window");
        return false;
    }
    if (!renderer.create(window.getWindow())) {
        Logger::error("Khong the khoi tao Renderer");
        return false;
    }
    player = new Player();
    player->setRenderer(renderer.getRenderer());
    player->loadAssets();
    running = true;
    return true;
}

void Game::run() {
    Uint32 lastTime = SDL_GetTicks();
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                if (event.key.keysym.sym == SDLK_SPACE) {
                    if (player != nullptr) player->jump();
                }
                if (event.key.keysym.sym == SDLK_RETURN) {
                    if (player != nullptr) player->attack();
                }
            }
        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (player != nullptr) {
            if (currentKeyStates[SDL_SCANCODE_A]) {
                player->moveLeft();
            }
            else if (currentKeyStates[SDL_SCANCODE_D]) {
                player->moveRight();
            }
            else {
                player->stop();
            }
        }
        Uint32 currentTime = SDL_GetTicks();
        float dt = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        if (dt > 0.1f) dt = 0.1f;
        update(dt);
        render();
    }
}
void Game::update(float dt) {
    if (player != nullptr) {
        player->update(dt);
    }
}
void Game::render() {
    renderer.clear();
    if (player != nullptr) {
        player->render();
    }
    renderer.present();
}
void Game::clean() {
    if (running) {
        running = false;
    }
    if (player != nullptr) {
        delete player;
        player = nullptr;
    }
    renderer.destroy();
    window.destroy();
}