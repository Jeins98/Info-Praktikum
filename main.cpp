/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
 * @mainpage Reversi
 *
 * Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
 *
 */

/**Defines the type of a player */
#define HUMAN 1
#define COMPUTER 2

#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include <iostream>
#include <stdlib.h>

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X]) {
	for (int j = 0; j < SIZE_Y; j++) {
		for (int i = 0; i < SIZE_X; i++) {
			field[j][i] = 0;
		}
	}
	field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
	field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
	field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
	field[SIZE_Y / 2][SIZE_X / 2] = 1;
}

/**
 * @brief Prints the playing field to the console.
 *
 * This function gets the current playing field as parameter (two dimensional array)
 * with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
 * <br>The function prints the playing field, grid included, to the console.
 * Crosses symbolize player 1 while circles symbolize player 2.
 *
 *  @param field  The field which is going to be printed
 */
void show_field(const int field[SIZE_Y][SIZE_X]) {
	std::cout << "  ";

//Start at ASCII 65 = A
	for (int j = 65; j < 65 + SIZE_Y; j++)
		std::cout << ((char) j) << " ";

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; j++) {
		std::cout << j + 1;
		for (int i = 0; i < SIZE_X; i++) {
			switch (field[j][i]) {
			case 0:
				std::cout << "  ";
				break;
			case 1:
				std::cout << " X";
				break;
			case 2:
				std::cout << " O";
				break;
			default:
				std::cout << "Inconsistent data in field!" << std::endl;
				std::cout << "Aborting .... " << std::endl;
				exit(0);
				break;
			}
		}; //for i
		std::cout << std::endl;
	} //for j
}
/**
 * @brief Checks who is the winner of the game
 * @param field
 * @return the winner; 0: if drawn
 *
 * This function checks the winner of the game
 * Return 1 if player 1 wins 2 if player 2 wins and 0 if drawn
 *
 */

int winner(const int field[SIZE_Y][SIZE_X]) {
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++) {
		for (int i = 0; i < SIZE_X; i++) {
			if (field[j][i] == 1)
				count_p1++;
			else if (field[j][i] == 2)
				count_p2++;

		} //for i
	} // for j

	if (count_p1 == count_p2) {
		return 0;
	}
	if (count_p2 > count_p1) {
		return 2;
	} else {
		return 1;
	}
}

bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
		const int pos_x, const int pos_y) {
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
			{
		return false;
	}

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			//check if you can find an opponents stone in a neighboring field
			if (field[pos_y + i][pos_x + j] == opponent) {
				int directionY = i + i;
				int directionX = j + j;
				int nextField = 0;

				while ((pos_y + directionY) > 0 && (pos_y + directionY) < 7
						&& (pos_x + directionX) > 0 && (pos_x + directionX) < 7) {

					nextField = field[pos_y + directionY][pos_x + directionX];

					if (nextField == player) {
						return true;
					}
					if (nextField == 0) {
						break;
					}
					directionY += i;
					directionX += j;
				}
			}

		}

	}
	return false;
}

void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
		const int pos_y) {

	int opponent = 3 - player;
	field[pos_y][pos_x] = player;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++) {
			//check if you can find an opponents stone in a neighboring field
			if (field[pos_y + i][pos_x + j] == opponent) {
				int directionY = i + i;
				int directionX = j + j;
				int nextField = 0;
				bool changeStone = false;

				while ((pos_y + directionY) > 0 && (pos_y + directionY) < 7 && (pos_x + directionX) > 0 && (pos_x + directionX) < 7) {

					nextField = field[pos_y + directionY][pos_x + directionX];

					if (nextField == player) {
						changeStone = true;
					}
					if (nextField == 0) {
						break;
					}
					directionY += i;
					directionX += j;
					}
					if (changeStone == true) {


					while ((pos_y + directionY) > 0 && (pos_y + directionY) < 7 && (pos_x + directionX) > 0 && (pos_x + directionX) < 7)
					{
						directionY = i;
						directionX = j;


						nextField = field[pos_y + directionY][pos_x + directionX];

						if (nextField == player)
						{
							break;
						}

						field[pos_y + directionY][pos_x + directionX] = player;

						directionY += i;
						directionX += j;
					}

				}

			}
		}
	}
}

	int possible_turns(const int field[SIZE_Y][SIZE_X], const int player) {

		int turn = 0;

		for (int j = 0; j < SIZE_Y; ++j)
		{
			for (int i = 0; i < SIZE_X; ++i)
			{
				if(turn_valid(field,player,i,j) == true)
				{
					turn++;
				}
			}

		}
		return turn;
	}

	bool human_turn(int field[SIZE_Y][SIZE_X], const int player) {
		if (possible_turns(field, player) == 0) {
			return false;
		}

		int px;
		int py;

		while (true) {
			std::string input;
			input.reserve(50);
			std::cout << std::endl << "Your move (e.g. A1): ";
			input.erase(input.begin(), input.end());
			std::cin >> input;
			px = ((int) input.at(0)) - 65;
			py = ((int) input.at(1)) - 49;

			if (turn_valid(field, player, px, py)) {
				//accept turn;
				break;
			} else {
				std::cout << std::endl << "Invalid input !" << std::endl;
			}
		}

		execute_turn(field, player, px, py);

		return true;
	}


	int turn(int field[SIZE_Y][SIZE_X], int player_typ, int player)
	{

		if(player_typ == HUMAN)
		{
			int turnvalid = possible_turns(field,player);
			if(turnvalid > 0)
			{
				human_turn(field,player);
				show_field(field);
			}
			return turnvalid;
		}
		if(player_typ == COMPUTER)
		{
			int turnvalid = possible_turns(field,player);
						if(turnvalid > 0)
						{
							computer_turn(field,player);
							show_field(field);
						}
						return turnvalid;
		}
		return 0;

	}

	void game(const int player_typ[2]) {

		int field[SIZE_Y][SIZE_X];

		//Create starting pattern
		initialize_field(field);

		int current_player = 1;
		show_field(field);
		//let each player make its moves until no further moves are possible

		while (true)
		{
			std::cout << "Player 1(X): ";
			int turnvalid1 = turn(field, player_typ[0],current_player);
			current_player = 2;
			std::cout << "Player 2(O): ";
			int turnvalid2 = turn(field, player_typ[1],current_player);
			current_player = 1;

			if(turnvalid1 == 0 && turnvalid2 == 0)
			{
				break;
			}

		}

		switch (winner(field))
		{
		case 0:

			std::cout << "Drawn" << std::endl;
			break;

		case 1:

			std::cout << "Player 1 wins" << std::endl;
			break;

		case 2:

			std::cout << "Player 2 wins" << std::endl;
			break;
		}
	}

	int main(void) {
		if (TEST == 1) {
			bool result = run_full_test();
			if (result == true) {
				std::cout << "ALL TESTS PASSED!" << std::endl;
			} else {
				std::cout << "TEST FAILED!" << std::endl;
			}
		}

		int field[SIZE_Y][SIZE_X];
		int player_typ1 = 0, player_typ2 = 0;
		bool playAgain = false;
		int iplayAgain = 0;

		do{

		std::cout << "Player 1: HUMAN(1),COMPUTER(2)" << std::endl;
		std::cin >> player_typ1;
		std::cout << "Player 2: HUMAN(1),COMPUTER(2)" << std::endl;
		std::cin >> player_typ2;

		initialize_field(field);

		//show_field(field);


		int player_type[2] = { player_typ1, player_typ2 };  //Contains information wether players are HUMAN(=1) or COPMUTER(=2)
		game(player_type);

		std::cout << "Play again? (0)=No; (1)=Yes" << std::endl;
		std::cin >> iplayAgain;

		switch(iplayAgain)
		{
		case 0:
			playAgain = false;
			break;
		case 1:
			playAgain = true;
			break;
		}

		}
		while(playAgain == true);
		std::cout << "Game ended" << std::endl;

		return 0;
	}
