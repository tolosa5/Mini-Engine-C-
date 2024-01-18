#include "Player.h"

void Player::Update(InputData Input)
{
    if (Input.GetIsPressed(EInputKeys::UP))
        PosY++;

    if (Input.GetIsPressed(EInputKeys::DOWN))
        PosY--;
    
    if (Input.GetIsPressed(EInputKeys::RIGHT))
        PosX++;

    if (Input.GetIsPressed(EInputKeys::LEFT))
        PosX--;
    
}