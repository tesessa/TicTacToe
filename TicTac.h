#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class TicTac {
public:
	TicTac();
	~TicTac();
	bool cellIsFull(int rowIndex, int colIndex);
	void clear();
	void botsTurn();
	bool hasWon();
	void personTurn1();
	void changeArray();
	string to_string() const;
	void setCell(string value, int rowIndex, int colIndex);
	void start();
	void checkTurn();
	void mediumDifficulty();
	void hardDifficulty();
	void personTurn2();
/*protected:
	static const int ROW_SIZE = 3;
	static const int COL_SIZE = 3;
	const string PLAYER1 = "X";
	const string PLAYER2 = "O";
	string board[ROW_SIZE][COL_SIZE];
	int turn = 0;
	int numberOfPlayers = 0;
	string position = 0;
*/
private:
	static const int ROW_SIZE = 3;
        static const int COL_SIZE = 3;
        const string PLAYER1 = "X";
        const string PLAYER2 = "O";
        string board[ROW_SIZE][COL_SIZE];
        int turn = 0;
        int numberOfPlayers = 0;
        string position = "0";
	int difficulty = 0;
};
