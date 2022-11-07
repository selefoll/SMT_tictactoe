// tic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameManager.h"

bool end = false;

void main(void)
{
    ConsoleGameInitialization();
    GameInitialization();
    
    while(end == false){
        
        end = Play();
    }
}
