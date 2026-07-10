#pragma once

#include "Character.h"
#include "graphics/Texture.h"
#include "graphics/Animation.h"
class Player : public Character {
public:
    Player();
    ~Player();
    void loadAssets();
    void update(float dt) override;
    void render() override;
    void jump();
    void attack();
    void moveLeft();
    void moveRight();
    void stop();
private:
    Texture idleTexture;
    Texture runTexture;
    Texture attackTexture;
    Texture jumpTexture;
    Texture* currentTexture;
    Animation animation;
    bool facingRight;
    bool onGround;
    bool isAttacking;
    Uint32 attackTime;
};