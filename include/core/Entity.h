#pragma once
#include <SDL.h>

class Entity {
public:
    Entity() {
        renderer = nullptr;
        posX = 0.0f;
        posY = 0.0f;
        velocityX = 0.0f;
        velocityY = 0.0f;
        srcRect = {0, 0, 0, 0};
        dstRect = {0, 0, 0, 0};
    }
    virtual ~Entity() {}
    virtual void update(float dt) = 0;
    virtual void render() = 0;
    void setRenderer(SDL_Renderer* ren) { renderer = ren; }
protected:
    SDL_Renderer* renderer; 
    float posX, posY;
    float velocityX, velocityY;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
};