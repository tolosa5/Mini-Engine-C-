#include "Input.h"

using namespace std;

InputData::InputData()
{
    for (int i = 0; i < static_cast<int>(EInputKeys::COUNT); i++)
    {
        Keys[i] = false;
    }
}

void InputData::UpdateInputs() //el metodo UpdateInputs de la clase .h Input, hace esto
{
    SetIsPressed(EInputKeys::UP, GetAsyncKeyState(VK_UP));
    SetIsPressed(EInputKeys::RIGHT, GetAsyncKeyState(VK_RIGHT));
    SetIsPressed(EInputKeys::DOWN, GetAsyncKeyState(VK_DOWN));
    SetIsPressed(EInputKeys::LEFT, GetAsyncKeyState(VK_LEFT));
    SetIsPressed(EInputKeys::ESC, GetAsyncKeyState(VK_ESCAPE));
}

bool InputData::GetIsPressed(EInputKeys Key)
{
    Keys[static_cast<int>(Key)];
}

void InputData::FPS()
{
    Sleep(fps);
}

void InputData::SetIsPressed(EInputKeys key, bool state)
{
    Keys[static_cast<int>(key)] = state;
}

