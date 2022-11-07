//Manage the progression of the game


#include "GameManager.h"

bool end_game = false;
bool winner = false;
int turn = 0;

int row = -2;
int column = -2;


bool row_valid = false;
bool column_valid = false;
bool position_available = false;

bool game_finished = false;

//check for invalide move
static void IsPositionAvailable() {

    row = ConsoleGetRow();
    row_valid = GameIsRowValid(row);
    if (row_valid == true) {
        column = ConsoleGetColumn();
        column_valid = GameIsColumnValid(column);
        if (column_valid == true) {
            position_available = GameIsPositionAvailable(row, column);

        }
    }
}

// update the game with the new move and check if this move result into a win
//player X is assigned the value +1 and player O the value -1
//player X/O win when the sum of a row, column or diagonal is equal to SCALE/-SCALE respectively. 
static void UpdateGame(int turn) {
    int player;
    char console_player;
    if (turn % 2 == 0) {
        player = 1;
        console_player = 'X';
    }
    else {
        player = -1;
        console_player = 'O';
    }
    //change code
    GameUpdate(row, column, player);
    ConsoleUpdate(row, column, console_player);
    game_finished = GameIsGameDone();
    if (game_finished == true) {
        ConsolePrintWinner(player);
        end_game = true;
        winner = true;
    }
}

//check if there is any position left
static void IsDraw(int turn) {
    if (turn == SCALE * SCALE && winner == false) {
        ConsolePrintNoWinner();
        end_game = true;
    }
}

//get the input, validate the input, update the game and check if it is the end
bool Play() {
    
    ConsolePlayerTurn(turn);
    IsPositionAvailable();
    if (position_available == true) {
        UpdateGame(turn);
        turn += 1;
    }
    else {
        ConsoleWrongInput();
    }


    IsDraw(turn);

    return end_game;
}

