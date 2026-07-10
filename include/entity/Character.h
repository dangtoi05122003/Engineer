#pragma once

#include "../core/Entity.h"
class Character : public Entity {
public:
    Character();
    virtual ~Character();
    virtual void attack();
    virtual void takeDamage(int damage);

protected:
    int hp;
    int maxHp;
    float speed;
};