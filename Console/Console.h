#pragma once
#include <iostream>
#include "../GameDefinition.h"


void ConsoleGameInitialization();

void ConsoleUpdate(int row, int column, char player);

void ConsolePlayerTurn(int turn);
int ConsoleGetRow();
int ConsoleGetColumn();

void ConsoleWrongInput();

void ConsolePrintWinner(int player);

void ConsolePrintNoWinner();
