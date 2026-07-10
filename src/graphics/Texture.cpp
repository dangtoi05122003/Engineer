#include "graphics/Texture.h"
#include <SDL_image.h>
#include "utils/Logger.h"

using namespace std;

Texture::Texture() {
    texture = nullptr;
    width = 0;
    height = 0;
}

Texture::~Texture() {
    destroy();
}

bool Texture::load(SDL_Renderer* renderer, const string& path) {
    destroy();
    SDL_Surface* tempSurface = IMG_Load(path.c_str());
    if (tempSurface == nullptr) {
        Logger::error("Khong the nap anh tu duong dan: " + path + " | Error SDL_image: " + IMG_GetError());
        return false;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    if (texture == nullptr) {
        Logger::error("Khong the tao texture tu surface cho file: " + path + " | Error SDL: " + SDL_GetError());
        SDL_FreeSurface(tempSurface);
        return false;
    }
    width = tempSurface->w;
    height = tempSurface->h;
    SDL_FreeSurface(tempSurface);

    return true;
}

void Texture::render(int x, int y) {
    if (texture == nullptr) return;
}

void Texture::render(SDL_Rect* src, SDL_Rect* dst) {
    if (texture == nullptr) return;
}

void Texture::destroy() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

int Texture::getWidth() const { return width; }
int Texture::getHeight() const { return height; }