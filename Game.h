#pragma once

#include "GameDefinition.h"


void GameInitialization();

bool GameIsRowValid(int row);
bool GameIsColumnValid(int column);
bool GameIsPositionAvailable(int row, int column);

void GameUpdate(int row, int column, int player);

bool GameIsGameDone();

