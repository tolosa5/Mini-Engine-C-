#pragma once
#include "Input.h"
#include "Types.h"

class Player
{
public:
    void Update(InputData Input);
    int PosX, PosY;

private:
    Vec2 pos;
};