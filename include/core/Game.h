#pragma once
#include "core/Window.h"
#include "core/Renderer.h"
#include "entity/Player.h"

class Game {
    public:
        Game();
        ~Game();
        bool init();
        void run();
        void update(float dt);
        void render();
        void clean();
    private:
        bool running;
        Window window;
        Player* player;
        Renderer renderer;
};