#pragma once

#include <SDL.h>
#include <string>

class Texture {
public:
    Texture();
    ~Texture();
    bool load(SDL_Renderer* renderer, const std::string& path);
    void render(int x, int y);
    void render(SDL_Rect* src,SDL_Rect* dst);
    void destroy();
    int getWidth() const;
    int getHeight() const;
    SDL_Texture* getSDLTexture() const { return texture; }

private:
    SDL_Texture* texture;
    int width;
    int height;
};