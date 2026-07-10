#include "core/Renderer.h"
#include "utils/Logger.h"

using namespace std;

Renderer::Renderer() : renderer(nullptr) {}

Renderer::~Renderer() {
    destroy();
}
bool Renderer::create(SDL_Window* window) {
    if (window == nullptr) {
        Logger::error("Khong the tao Renderer vi SDL_Window bi NULL");
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        Logger::error(string("Error SDL_Renderer: ") + SDL_GetError());
        return false;
    }
    return true;
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 20, 20, 30, 255);
    SDL_RenderClear(renderer);
}
void Renderer::present() {
    SDL_RenderPresent(renderer);
}

void Renderer::destroy() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}
SDL_Renderer* Renderer::getRenderer() const {
    return renderer;
}