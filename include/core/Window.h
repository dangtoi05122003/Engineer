#pragma once
#include <SDL.h>
#include<string>

using namespace std;

class Window {
    public:
        Window();
        ~Window();
        bool create(const string& title, int width, int height);
        void destroy();
        SDL_Window* getWindow() const;
    private:
        SDL_Window* window;
};