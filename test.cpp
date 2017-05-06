/**
 * @file test.cpp
 *
 * Provides a function for testing the program and some other functions in order to provide this.
 */

#include "test.h"
#include "config.h"

#include <iostream>

extern void show_field(const int field[SIZE_Y][SIZE_X]);
extern int winner(const int field[SIZE_Y][SIZE_X]);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
		const int pos_x, const int pos_y);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player,
		const int pos_x, const int pos_y);
extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);
/**
 * @brief test the winner function of the game
 * @param field of the game and winner_code
 * @return true if test worked and false if it failed
 *
 * This function test the winner function of the main file
 * Return true if test worked and false if it failed
 *
 */

bool test_winner(const int field[SIZE_Y][SIZE_X], const int winner_code) {
	std::cout << "Running test for 'winner'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	show_field(field);
	std::cout << "Checking who wins" << std::endl;

	int currentWinner = winner(field);

	if (currentWinner == winner_code) {
		std::cout << "Test worked" << std::endl;
		return true;
	} else {
		std::cout << "Test failed" << std::endl;
		return false;
	}

	/* Check if result of winner function is correct and what you expected
	 *
	 * Return true for correct and false for wrong
	 *
	 * also print to the console if test was passed or not
	 */

}

bool test_turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
		const int pos_x, const int pos_y, const bool valid) {

		std::cout << "Running test for 'turn_valid'..." << std::endl;
		std::cout << "----------------------------" << std::endl;
		show_field(field);
		std::cout << "Checking if turn valid" << std::endl;

		bool currentResult = turn_valid(field, player, pos_x, pos_y);
		if(currentResult == valid)
		{
			std::cout << "Test worked" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Test failed" << currentResult << std::endl;
			return false;
		}
	return 0;
}

bool test_execute_turn(int input[SIZE_Y][SIZE_X],
		const int output[SIZE_Y][SIZE_X], const int player, const int pos_x,
		const int pos_y) {

			std::cout << "Running test for 'execute_turn'..." << std::endl;
			std::cout << "----------------------------" << std::endl;

			std::cout << "Checking if execute_turn" << std::endl;

			execute_turn(input,player,pos_x,pos_y);

			for (int i = 0; i < SIZE_Y; ++i) {
				for (int j = 0; j < SIZE_X; ++j) {
					if(input[j][i] == output[j][i]){
						std::cout << "Test worked" << std::endl;
						return true;
					}
					else
					{
						std::cout << "Test failed" << std::endl;
						return false;
					}
				}
			}




	// check for a given field whether the execution of a turn is valid
	return 0;
}

bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
		const int count_possible_turns) {

		std::cout << "Running test for 'possible_turns'..." << std::endl;
		std::cout << "----------------------------" << std::endl;
		std::cout << "Checking if possible_turns" << std::endl;

		if(possible_turns(field,player) == count_possible_turns)
		{
			std::cout << "Test worked" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Test failed" << std::endl;
			return false;
		}


	// very if your function finds all possible turns
	return 0;
}

bool run_full_test(void) {
	bool result = true;

// ---------- CHECK WINNER ---------- //

	int winner_matrix[5][8][8] = { { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0,
					0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
					0, 0, 0, 0 } }, { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 2, 0,
			0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 2, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0,
					0, 0, 0, 0, 0 }, { 0, 2, 0, 0, 0, 2, 0, 0 }, { 0, 0, 0, 0,
					0, 0, 0, 0 } }, { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			1, 0, 0, 1 }, { 0, 2, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 2,
					0, 0, 0, 0, 0 }, { 0, 2, 0, 0, 2, 0, 0, 0 }, { 0, 0, 0, 0,
					0, 0, 0, 0 } }, { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 2, 0, 0,
			2, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 0, 1, 0 }, { 0, 0, 1,
					0, 1, 0, 0, 0 }, { 0, 2, 0, 0, 2, 0, 0, 0 }, { 0, 0, 0, 0,
					0, 0, 0, 0 } }, { { 2, 0, 0, 0, 0, 0, 1, 0 }, { 2, 0, 0, 0,
			2, 0, 0, 0 }, { 0, 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 2, 0, 2, 0, 0 }, { 0, 0, 0, 0, 2, 0, 0, 0 }, { 0, 2, 0,
					0, 0, 2, 0, 0 }, { 0, 0, 0, 1, 0, 0, 1, 0 }, { 0, 0, 0, 0,
					0, 0, 0, 0 } } };

	int winner_code[5] = { 1, 2, 1, 1, 2 };

	for (int i = 0; i < 5; i++) {
		// TODO: Call the check function
		if (test_winner(winner_matrix[i], winner_code[i]) != true) {
			result = false;
		}

	}

// ---------- CHECK TURN VALID ---------- //

	int turnvalid_matrix[6][8][8] = { { { 1, 0, 2, 0, 0, 1, 1, 1 }, { 0, 0, 2,
			0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 1, 2, 2 }, { 2, 2, 0, 2, 0, 0, 0,
			0 }, { 0, 0, 0, 0, 0, 2, 2, 0 }, { 0, 0, 0, 2, 1, 1, 0, 2 }, { 1, 0,
			0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 1, 0, 1 } },

	{ { 1, 0, 2, 0, 0, 1, 1, 1 }, { 0, 0, 2, 0, 0, 1, 0, 0 }, { 0, 0, 2, 0, 0,
			2, 1, 1 }, { 0, 0, 0, 2, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 2, 2, 0 }, {
			0, 0, 0, 2, 1, 1, 0, 2 }, { 1, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 1, 0, 1 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0,
			0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 2, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 1, 0, 0, 2, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 1, 0 }, { 2, 0, 1, 2, 0,
			2, 0, 0 }, { 0, 2, 0, 2, 2, 2, 2, 2 }, { 0, 0, 0, 0, 0, 0, 0, 1 }, {
			1, 0, 0, 0, 0, 2, 2, 2 }, { 0, 2, 0, 0, 0, 0, 0, 0 }, { 0, 1, 0, 1,
			1, 1, 0, 0 } },

	{ { 2, 1, 0, 0, 2, 1, 1, 1 }, { 0, 2, 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 2, 0,
			0, 0, 1 }, { 0, 1, 1, 1, 0, 1, 0, 0 }, { 1, 0, 0, 1, 1, 0, 0, 2 }, {
			0, 0, 0, 0, 0, 0, 0, 1 }, { 1, 1, 0, 0, 0, 0, 2, 0 }, { 1, 1, 2, 0,
			0, 2, 2, 1 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0,
			0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } } };

	int turnvalid_player[6] = { 1, 2, 2, 1, 2, 1 };
	int turnvalid_pos[6][2] = { { 2, 3 }, { 0, 3 }, { 4, 3 }, { 3, 4 },
			{ 3, 5 }, { 3, 4 } };
	bool turnvalid_valid[6] = { 0, 0, 0, 1, 1, 0 };

	for (int i = 0; i < 6; i++) {
		// TODO: Call the check function
		if(test_turn_valid(turnvalid_matrix[i],turnvalid_player[i], turnvalid_pos[i][0],turnvalid_pos[i][1],turnvalid_valid[i]) != true)
		{
			result = false;
		}
	}

// ---------- CHECK EXECUTE TURN ---------- //

	int executeturn_matrix_in[9][8][8] = { { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0,
			0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 1, 2, 2 }, { 2, 2, 0, 0, 0, 0,
			0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0,
			0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0,
			2, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0,
			0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 2, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 1, 0 }, { 0, 0, 0, 2, 0,
			2, 0, 0 }, { 0, 0, 0, 2, 2, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 2, 0,
			0, 0, 0 }, { 0, 0, 0, 1, 0, 1, 0, 0 }, { 0, 0, 0, 1, 1, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0,
			0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 1, 0 }, { 0, 0, 0, 2, 0,
			2, 0, 0 }, { 0, 0, 0, 2, 2, 0, 0, 0 }, { 0, 1, 2, 0, 2, 2, 1, 0 }, {
			0, 0, 0, 2, 2, 0, 0, 0 }, { 0, 0, 0, 1, 0, 1, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 2, 0, 0 }, { 0, 0, 0, 0, 1,
			0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 1, 1, 1, 1, 0 }, {
			0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 0, 2, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0,
			0, 0, 0 }, { 0, 1, 0, 0, 0, 0, 2, 1 }, { 1, 0, 1, 1, 2, 0, 0, 0 }, {
			0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } } };

	int executeturn_matrix_out[9][8][8] { { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0,
			0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 1, 2, 2 }, { 2, 2, 0, 0, 0, 0,
			0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0,
			0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0,
			2, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0,
			0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 2, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 1, 0 }, { 0, 0, 0, 2, 0,
			1, 0, 0 }, { 0, 0, 0, 2, 1, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 2, 0,
			0, 0, 0 }, { 0, 0, 0, 2, 0, 1, 0, 0 }, { 0, 0, 0, 2, 1, 0, 0, 0 }, {
			0, 0, 0, 2, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0,
			0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 1, 0 }, { 0, 0, 0, 1, 0,
			1, 0, 0 }, { 0, 0, 0, 1, 1, 0, 0, 0 }, { 0, 1, 1, 1, 1, 1, 1, 0 }, {
			0, 0, 0, 1, 1, 0, 0, 0 }, { 0, 0, 0, 1, 0, 1, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 2, 0, 0 }, { 0, 0, 0, 0, 2,
			0, 0, 0 }, { 0, 0, 0, 2, 0, 0, 0, 0 }, { 0, 0, 2, 1, 1, 1, 1, 0 }, {
			0, 0, 2, 0, 0, 0, 0, 0 }, { 0, 0, 2, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0,
			0, 0, 0 }, { 0, 1, 0, 0, 0, 0, 2, 1 }, { 1, 2, 2, 2, 2, 0, 0, 0 }, {
			0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } } };

	int executeturn_player[9] = { 0, 0, 0, 1, 2, 0, 1, 2, 2 };
	int executeturn_pos[9][2] = { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 3, 4 },
			{ 3, 5 }, { 0, 0 }, { 3, 4 }, { 2, 4 }, { 1, 4 } };

	for (int i = 0; i < 9; i++) {
		// TODO: Call the check function
		if(test_execute_turn(executeturn_matrix_in[i],executeturn_matrix_out[i],executeturn_player[1], executeturn_pos[i][0], executeturn_pos[i][1]) != true){
			return false;
		}
	}

// ---------- CHECK POSSIBLE TURNS ---------- //

	int possibleturns_matrix[2][8][8] { { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0,
			0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 2, 0, 0,
			0 }, { 0, 0, 0, 2, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0,
			0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 } },

	{ { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 2, 1,
			0, 0, 0 }, { 0, 0, 0, 2, 1, 1, 0, 0 }, { 0, 0, 0, 2, 1, 0, 0, 0 }, {
			0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
			0, 0, 0, 0 } } };

	int possibleturns_player[2] = { 1, 1 };
	int possibleturns_count[2] = { 4, 5 };

	for (int i = 0; i < 2; i++) {
		// TODO: Call the check function
		if(test_possible_turns(possibleturns_matrix[i],possibleturns_player[i],possibleturns_count[i]) != true)
		{
			return false;
		}
	}

	return result;
}
