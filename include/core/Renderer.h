#pragma once

#include <SDL.h>

class Renderer {
    public:
        Renderer();
        ~Renderer();
        bool create(SDL_Window* window);
        void clear();
        void present();
        void destroy();
        SDL_Renderer* getRenderer() const;
    private:
        SDL_Renderer* renderer;
};