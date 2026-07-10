#include "entity/Player.h"
#include "utils/Logger.h"

Player::Player() {
    posX = 100.0f;
    posY = 400.0f;
    velocityX = 0.0f;
    velocityY = 0.0f;
    speed = 250.0f;
    facingRight = true;
    onGround = true;
    isAttacking = false;
    srcRect = { 0, 0, 96, 96 };
    animation.setFrameSize(96, 96);
    animation.setFrameCount(10);
    animation.setFPS(10);
    attackTime = 0;
}
void Player::loadAssets() {
    if (renderer == nullptr) {
        Logger::error("Error: Renderer bang NULL, khong the nap anh");
        return;
    }
    idleTexture.load(renderer, "../assets/characters/Samurai/IDLE.png");
    runTexture.load(renderer, "../assets/characters/Samurai/RUN.png");
    attackTexture.load(renderer, "../assets/characters/Samurai/ATTACK.png");
    jumpTexture.load(renderer, "../assets/characters/Samurai/RUN.png");
    currentTexture = &idleTexture;
}
Player::~Player() {
    idleTexture.destroy();
    runTexture.destroy();
    attackTexture.destroy();
    jumpTexture.destroy();
    currentTexture = nullptr;
}

void Player::update(float dt) {
    posX += velocityX * dt;
    posY += velocityY * dt;
    if (isAttacking){
        if (SDL_GetTicks() - attackTime > 700){
            isAttacking = false;
        }
    }
    if (!onGround) {
        velocityY += 980.0f * dt;
    }

    if (posY >= 400.0f) {
        posY = 400.0f;
        velocityY = 0.0f;
        onGround = true;
    }
    if (isAttacking) {
        currentTexture = &attackTexture;
        animation.setFrameCount(7);
    }
    else if (!onGround) {
        currentTexture = &jumpTexture;
        animation.setFrameCount(9);
    }
    else if (velocityX != 0.0f) {
        currentTexture = &runTexture;
        animation.setFrameCount(16);
    }
    else {
        currentTexture = &idleTexture;
        animation.setFrameCount(10);
    }
    animation.update(dt);
    srcRect = animation.getFrame();
    if (velocityX > 0.0f) facingRight = true;
    else if (velocityX < 0.0f) facingRight = false;
    dstRect.x = static_cast<int>(posX);
    dstRect.y = static_cast<int>(posY);
    dstRect.w = 128;
    dstRect.h = 128;
}

void Player::render() {
    if (currentTexture == nullptr || renderer == nullptr) return;
    SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(renderer, currentTexture->getSDLTexture(), &srcRect, &dstRect, 0.0, nullptr, flip);
}

void Player::jump() {
    if (onGround) {
        velocityY = -450.0f;
        onGround = false;
    }
}

void Player::attack() {
    if (!isAttacking) {
        isAttacking = true;
        attackTime = SDL_GetTicks();
        Logger::info("Samurai vung kiem");
    }
}
void Player::moveLeft()
{
    velocityX = -speed;
}
void Player::moveRight()
{
    velocityX = speed;
}
void Player::stop()
{
    velocityX = 0.0f;
}