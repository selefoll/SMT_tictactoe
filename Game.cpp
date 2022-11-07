//methods to make the game work.


#include "Game.h"

int table[SCALE][SCALE];

//the table is initialize to a value that the sum of a column or a row can never reach.
void GameInitialization() {

	for (int i = 0; i < SCALE; i++) {
		for (int j = 0; j < SCALE; j++) {
			table[i][j] = SCALE+1;
		}
	}
}

//check if the row input is acceptable
bool GameIsRowValid(int row) {
	if ((row < SCALE) && (row>=0)){
		return true;
	}
	else
		return false;
}

//check if the column input is acceptable
bool GameIsColumnValid(int Column) {
	if ((Column < SCALE) && (Column >= 0)) {
		return true;
	}
	else
		return false;
}

//check if someone already play at this position
bool GameIsPositionAvailable(int row, int column) {
	if (table[row][column] < SCALE) {
		return false;
	}
	else {
		return true;
	}
}

//update the game based on the turn, thus the player
void GameUpdate(int row, int column, int player) {
	table[row][column] = player;
}

//check if the conditions are met for the game to have a winner
//go through the table to check the sum of rows, columns and diagonals.
bool GameIsGameDone() {
	int sum_column, sum_row, diagonal_sum, anti_diagonal_sum;


	sum_column = 0, sum_row = 0, diagonal_sum = 0, anti_diagonal_sum = 0;
	for (int i = 0; i < SCALE; i++) {
		diagonal_sum += table[i][i];
		anti_diagonal_sum += table[i][SCALE - i - 1];
		for (int j = 0; j < SCALE; j++) {
			sum_column += table[i][j];	
			sum_row += table[j][i];
		}
		if (sum_row == SCALE || sum_column == SCALE || sum_row == -SCALE || sum_column == -SCALE) {
			return true;
		}
		sum_column = 0, sum_row = 0;
	}
	if (diagonal_sum == SCALE || anti_diagonal_sum == SCALE || diagonal_sum == -SCALE || anti_diagonal_sum == -SCALE) {
		return true;
	}	

	return false;
}

