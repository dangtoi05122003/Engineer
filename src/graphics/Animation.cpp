#include "graphics/Animation.h"

Animation::Animation(){
    currentFrame = 0;
    frameCount = 1;
    frameWidth = 0;
    frameHeight = 0;
    timer = 0.0f;
    frameTime = 0.1f;
}

void Animation::update(float dt){
    timer += dt;
    while (timer >= frameTime)
    {
        timer -= frameTime;
        currentFrame = (currentFrame + 1) % frameCount;
    }
}

SDL_Rect Animation::getFrame() const {
    SDL_Rect rect;
    rect.x = currentFrame * frameWidth;
    rect.y = 0;
    rect.w = frameWidth;
    rect.h = frameHeight;
    return rect;
}
void Animation::setFrameSize(int w, int h) {
    frameWidth = w;
    frameHeight = h;
}
void Animation::setFrameCount(int count) {
    if (frameCount != count){
        frameCount = count;
        currentFrame = 0;
        timer = 0.0f;
    }
}
void Animation::setFPS(int fps)
{
    if (fps > 0)
        frameTime = 1.0f / fps;
}