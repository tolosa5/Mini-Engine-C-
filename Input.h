#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

enum class EInputKeys
{
    UP, RIGHT, DOWN, LEFT,
    ESC, COUNT
};

class InputData
{

public:
    void UpdateInputs();
    bool GetIsPressed(EInputKeys Key);

    void FPS();

private:
    bool Keys[static_cast<int>(EInputKeys::COUNT)] = {}; //inicializa los valores
    int fps = 5/1000;

    void SetIsPressed(EInputKeys Key, bool state);
};