#pragma once

#include <SDL.h>

class Animation {
public:
    Animation();
    void update(float dt);
    SDL_Rect getFrame() const;
    void setFrameSize(int w, int h);
    void setFrameCount(int count);
    void setFPS(int fps);
private:
    int currentFrame;
    int frameCount;
    int frameWidth;
    int frameHeight;
    float timer;
    float frameTime;
};