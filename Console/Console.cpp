//Create the methods that interact with the console 

#include "Console.h"

char PossiblePosition[SCALE][SCALE];

void ConsoleGameInitialization() {
    
    std::cout << "Welcome to Tic Tac Toe" << "\n";
    std::cout << "The game will have " << SCALE * SCALE << " possible positions" << "\n";
    std::cout << "The first player to have " << SCALE << " aligned mark win the game" << "\n";
    std::cout << "The first player will play X and the second O" << "\n";
    std::cout << "Each turn a player will be asked a row and column value from 1 to " << SCALE << "\n";
    std::cout << "An update version of the following table will appear" << "\n";
    

    
    for (int i = 0; i < SCALE; i++) {
        for (int j = 0; j < SCALE; j++) {
            PossiblePosition[i][j] = '_';
            std::cout << PossiblePosition[i][j];
        }
        std::cout << "\n";
    }
}


void ConsoleUpdate(int row, int column, char player) {

    PossiblePosition[row][column] = player;

    for (int i = 0; i < SCALE; i++) {
        for (int j = 0; j < SCALE; j++) {
            std::cout << PossiblePosition[i][j];
        }
        std::cout << "\n";
    }



}

void ConsolePlayerTurn(int turn) {
    if (turn % 2 == 0) 
        std::cout << "Player X turn" << "\n";
    else 
        std::cout << "Player O turn" << "\n";

}

int ConsoleGetRow() {
    int row = -2;
    std::cout << "Enter a Row (integer value) between 0 and "<< SCALE-1<<" :" <<"\n";
    std::cin >> row;
    std::cout << "\n";
    while (std::cin.fail()) {
        std::cout << "Error" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter a Row (integer value) between 0 and " << SCALE - 1 << " :" << "\n";
        std::cin >> row;
        std::cout << "\n";
    }
    return row;
}

int ConsoleGetColumn() {
    int column = -2;
    std::cout << "Enter a Column (integer value) between 0 and " << SCALE-1 << " :" << "\n";
    std::cin >> column;
    std::cout << "\n";
    while (std::cin.fail()) {
        std::cout << "Error" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter a Column (integer value) between 0 and " << SCALE - 1 << " :" << "\n";
        std::cin >> column;
        std::cout << "\n";
    }
    return column;
}

void ConsoleWrongInput() {
    std::cout << "please enter a valid input" << "\n";

}

void ConsolePrintWinner(int player) {
    if (player == 1) {
        std::cout << "Congratulation to player X for winning" << '\n';
    }
    else if (player == -1) {
        std::cout << "Congratulation to player O for winning" << '\n';
    }
}

void ConsolePrintNoWinner() {
    std::cout << "You reached a draw" << '\n';
}