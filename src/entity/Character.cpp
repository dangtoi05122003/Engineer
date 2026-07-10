#include "entity/Character.h"
#include "utils/Logger.h"

using namespace std;

Character::Character() {
    maxHp = 100;
    hp = maxHp;
    speed = 200.0f;
}
Character::~Character() {
}
void Character::attack() {
    Logger::info("Mot sinh vat dang tan cong");
}
void Character::takeDamage(int damage) {
    hp -= damage;
    Logger::info("Sinh vat bi tru " + to_string(damage) + " HP con lai: " + to_string(hp) + "/" + to_string(maxHp));
    if (hp <= 0) {
        hp = 0;
         Logger::warning("Sinh vat da tu vong");
    }
}