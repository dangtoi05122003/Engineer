#include "core/Window.h"
#include "utils/Logger.h"

Window::Window() : window(nullptr) {}
Window::~Window() {
    destroy();
}

bool Window::create(const string& title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        Logger::error(string("Error SDL: ") + SDL_GetError());
        return false;
    }
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        Logger::error(string("Error Window: ") + SDL_GetError());
        return false;
    }
    return true;
}

void Window::destroy() {
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

SDL_Window* Window::getWindow() const {
    return window;
}