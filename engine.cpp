#include <iostream>
#include "Input.h"
#include "Player.h"
#include "utils.h"

using namespace std;

void main()
{
    bool bExit = false;

    InputData Inputs = InputData();
    Player player = Player();

    while(!bExit)
    {
        //Read input
        Inputs.UpdateInputs();

        //Update
        bExit = Inputs.GetIsPressed(EInputKeys::ESC);
        player.Update(Inputs);

        //Draw
        system("cls"); //limpiar la consola antes de pintar
        PRINT("Player pos x");
        PRINT(player.PosX);
        PRINT("Player pos y");
        PRINT(player.PosY);

        //FPS fake control
        Inputs.FPS();
    }

    return;
}
    /*
    int* arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = new int(i);
    }
    for (int i = 0; i < 10; i++)
    {
        PRINT(*arr[i]);
    }

    int* f = nullptr; //puntero nulo, no es invalido y no da error
    PRINT(*f);
    */

    /*
    bool bContinue;
    int it = 0;

    while (bContinue)
    {
        if (it > 6 && it < 10)
        {
            it++;
            continue;
        }

        PRINT(it);
        it++;

        bContinue = it < 13;
    }
    */