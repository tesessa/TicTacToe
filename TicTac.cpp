#include "TicTac.h"

TicTac::TicTac() {
//	string board[ROW_SIZE][COL_SIZE];
	srand(time(0));
	int counter = 1;
	string str;
	for(int i = 0; i<ROW_SIZE; i++) {
		for(int j = 0; j<COL_SIZE; j++) {
			stringstream ss;
			ss << counter;
			ss >> str;
			board[i][j] = str;
			counter++;
		}
	}
}

TicTac::~TicTac() {
	clear();
}

bool TicTac::cellIsFull(int rowIndex, int colIndex) {
	if(board[rowIndex][colIndex] == "X" || board[rowIndex][colIndex] == "O") {
		return true;
	} else {
		return false;
	}
}

void TicTac::clear() {
	for(int i = 0; i<ROW_SIZE; i++) {
	   for(int j=0; j<COL_SIZE; j++) {
	      board[i][j] = "";
	    }
	 }
  position = "";
  turn = 0;
  numberOfPlayers = 0;

}

void TicTac::botsTurn() {
	turn++;
	  int row = 0;
	  int col = 0;
	  do {
	    row = rand()%3;
	    col = rand()%3;
          }while(cellIsFull(row, col));
	  board[row][col] = PLAYER2;
	checkTurn();
	
}

void TicTac::mediumDifficulty() {
    turn++;
    int numberOfX1 = 0;
    int numberOfX2 = 0;
    for(int i = 0; i<ROW_SIZE-1; i++) {
    	for(int j = 0; j<COL_SIZE-1; j++) {
	   if(board[i][j] == PLAYER1) {
	   	numberOfX1++;
	   }
	   if(board[j][i] == PLAYER1) {
	        numberOfX2++;
	   }
	   if(numberOfX1 == 2) {
		if(!cellIsFull(i, j+1)) {
	   	  board[i][j+1] = PLAYER2;
		  checkTurn();
	      }
	    }
	    if(numberOfX2 == 2) {
		if(!cellIsFull(j+1, i)){
	    	  board[j+1][i] = PLAYER2;
		  checkTurn();
		}
	    }
	}
	numberOfX1 = 0;
	numberOfX2 = 0;
    }
    for(int i = ROW_SIZE-1; i>0; i--) {
    	for(int j = COL_SIZE; j>0; j--) {
	   if(board[i][j] == PLAYER1) {
	   	numberOfX1++;
	   }
	   if(board[j][i] == PLAYER1) {
	   	numberOfX2++;
	   }
	   if(numberOfX1 == 2) {
		if(!cellIsFull(i, j-1)) {
	   	   board[i][j-1] = PLAYER2;
		   checkTurn();
		}
	   }
	   if(numberOfX2 == 2) {
	   	if(!cellIsFull(j-1, i)) {
	   	  board[j-1][i] = PLAYER2;
		  checkTurn();
		}
	   }
	 }
	 numberOfX1 = 0;
	 numberOfX2 = 0;
    }
    //check diagonals
    if(board[0][0] == PLAYER1 && board [1][1] == PLAYER1) {
	if(!cellIsFull(2,2)){
	  board[2][2] = PLAYER2;
	  checkTurn();
	}
    }
    if (board[0][0] == PLAYER1 && board[2][2] == PLAYER1) {
	if(!cellIsFull(1,1)) {
	  board[1][1] = PLAYER2;
	  checkTurn();
	}
    }
    if((board[1][1] == PLAYER1 && board[2][2] == PLAYER1) || (board[0][2] == PLAYER1 && board[2][0] == PLAYER1)) {
	if(!cellIsFull(0,0)) {
	  board[0][0] = PLAYER2;
	  checkTurn();
	}
    }
    if(board[0][0] == PLAYER1 && board[0][2] == PLAYER1) {
	if(!cellIsFull(2,0)) {
	  board[2][0] = PLAYER2;
	  checkTurn();
	}
    }
    if(board[2][0] == PLAYER1 && board[0][0] == PLAYER1) {
	if(!cellIsFull(0,2)) {
    	  board[0][2] = PLAYER2;
	  checkTurn();
	}
    }

    
    int row = 0;
    int col = 0;
    do {
      row = rand()%3;
      col = rand()%3;
    }while(cellIsFull(row, col));
    board[row][col] = PLAYER2;
    checkTurn();
}

void TicTac::hardDifficulty() {
    turn++;
    int numberOfX1 = 0;
    int numberOfX2 = 0;
    int numberOfO1 = 0;
    int numberOfO2 = 0;
    for(int i = 0; i<ROW_SIZE-1; i++) {
        for(int j = 0; j<COL_SIZE-1; j++) {
           if(board[i][j] == PLAYER1) {
                numberOfX1++;
           }
           if(board[j][i] == PLAYER1) {
                numberOfX2++;
           }
	   if(board[i][j] == PLAYER2) {
	   	numberOfO1++;
	   }
	   if(board[j][i] == PLAYER2) {
	   	numberOfO2++;
	   }
           if(numberOfX1 == 2) {
	   	if(!cellIsFull(i, j+1)) {
                  board[i][j+1] = PLAYER2;
                  checkTurn();
		}
            }
            if(numberOfX2 == 2) {
	       if(!cellIsFull(j+1, i)) {
                  board[j+1][i] = PLAYER2;
                  checkTurn();
		}
            }
	    if(numberOfO1 == 2) {
	       if(!cellIsFull(i,j+1)) {
	    	board[i][j+1] = PLAYER2;
		checkTurn();
	       }
	    }
	    if(numberOfO2 == 2) {
	       if(!cellIsFull(j+1, i)) {
	    	board[j+1][i] = PLAYER2;
	    	checkTurn();
	       }
	    }
        }
        numberOfX1 = 0;
        numberOfX2 = 0;
    }
       for(int i = ROW_SIZE-1; i>0; i--) {
        for(int j = COL_SIZE; j>0; j--) {
           if(board[i][j] == PLAYER1) {
                numberOfX1++;
           }
           if(board[j][i] == PLAYER1) {
                numberOfX2++;
           }
	   if(board[i][j] == PLAYER2) {
	   	numberOfO1++;
	   }
	   if(board[j][i] == PLAYER2) {
	   	numberOfO2++;
	   }
	   if(numberOfO1 == 2) {
	   	if(!cellIsFull(i, j-1)) {
		   board[i][j-1] = PLAYER2;
		   checkTurn();
		}
	   }
	   if(numberOfO2 == 2) {
	   	if(!cellIsFull(j-1, i)) {
		  board[j-1][i] = PLAYER2;
		  checkTurn();
		}
		
	  }
           if(numberOfX1 == 2) {
                if(!cellIsFull(i, j-1)) {
		  board[i][j-1] = PLAYER2;
                  checkTurn();
		}
           }
           if(numberOfX2 == 2) {
                if(!cellIsFull(j-1, i)) {
		  board[j-1][i] = PLAYER2;
                  checkTurn();
		}
           }
         }
         numberOfX1 = 0;
         numberOfX2 = 0;
	 numberOfO1 = 0;
	 numberOfO2= 0;
    }
    for(int i = 0; i<ROW_SIZE; i+=2) {
    	for(int j = 0; j<COL_SIZE; j+=2) {
		if(board[i][j] == PLAYER1) {
		   numberOfX1++;
		}
		if(board[j][i] == PLAYER1) {
		   numberOfX2++;
		}
		if(board[i][j] == PLAYER2) {
		   numberOfO1++;
		}
		if(board[j][i] == PLAYER2) {
		   numberOfO2++;
		}
		if(numberOfO1==2) {
		 if(!cellIsFull(i, j-1)) {
		    board[i][j-1] = PLAYER2;
		    checkTurn();
		  }
		}
		if(numberOfO2 == 2) {
		   if(!cellIsFull(j, i-1)) {
		      board[j][i-1] = PLAYER2;
		      checkTurn();
		    }
		}
		if(numberOfX1 == 2) {
		    if(!cellIsFull(i, j-1)) {
		      board[i][j-1] = PLAYER1;
		      checkTurn();
		    }
		}
		if(numberOfX2 == 2) {
		    if(!cellIsFull(j, i-1)) {
		      board[j][i-1] = PLAYER1;
		      checkTurn();
		    }
		}
	}
	numberOfX1 = 0;
        numberOfX2 = 0;
        numberOfO1 = 0;
        numberOfO2= 0;
   }
    //check diagaonals
      if(board[0][0] == PLAYER1 && board [1][1] == PLAYER1){
        if(!cellIsFull(2,2)) {
	  board[2][2] = PLAYER2;
	  checkTurn();
	}
    }
    if (board[0][0] == PLAYER1 && board[2][2] == PLAYER1) {
        if(!cellIsFull(1,1)) {
	  board[1][1] = PLAYER2;
	  checkTurn();
	}
    }
    if((board[1][1] == PLAYER1 && board[2][2] == PLAYER1) || (board[0][2] == PLAYER1 && board[2][0] == PLAYER1)) {
        if(!cellIsFull(0,0)) {
	  board[0][0] = PLAYER2;
	  checkTurn();
	}
    }
    if(board[0][0] == PLAYER1 && board[0][2] == PLAYER1) {
        if(!cellIsFull(2,0)) {
	  board[2][0] = PLAYER2;
	  checkTurn();
	}
    }
    if(board[2][0] == PLAYER1 && board[0][0] == PLAYER1) {
        if(!cellIsFull(0, 2)) {
	  board[0][2] = PLAYER2;
	  checkTurn();
	}
    }
    
    int row = 0;
    int col = 0;
    do {
      row = rand()%3;
      col = rand()%3;
    }while(cellIsFull(row, col));
    board[row][col] = PLAYER2;
    checkTurn();

}

void TicTac::personTurn1() {
	int counter = 0;
	cin >> position;
	for(int i = 0; i<ROW_SIZE; i++) {
	   for(int j = 0; j<COL_SIZE; j++) {
	   	if(board[i][j] == position) {
			if(!cellIsFull(i, j)) {
			   board[i][j] = PLAYER1;
			}
		} else {
		    counter++;
	        }
	    }
	}
	if(counter == 9) {
          cout << "Error, wrong position, try again" << endl;
	  personTurn1();
	}
	turn++;
    checkTurn();

}

void TicTac::personTurn2() {
     int counter = 0;
     cin >> position;
     for(int i = 0; i<ROW_SIZE; i++) {
        for(int j = 0; j<COL_SIZE; j++) {
	   if(board[i][j] == position) {
	      if(!cellIsFull(i, j)) {
	         board[i][j] = PLAYER2;
	      }
	   } else {
	      counter++;
	   }
	}
     }
     if(counter == 9) {
        cout << "Error, wrong position, try again" << endl;
	personTurn2();
     }
     turn++;
    checkTurn();
  }

void TicTac::checkTurn() {
//	cout << "Turn: " << turn << endl;
	if(turn >= 5) {
	   if(hasWon()) {
	   	to_string();
	   	exit(0);
	   }
	}
	if(turn == 9 && (!hasWon())) {
		to_string();
		cout << "Tie game!" << endl;
		exit(0);
	}
	if(turn%2==0) {
	   to_string();
	   cout << "Player 1 input an X!" << endl;
	   personTurn1();
	}
	if(numberOfPlayers == 1) {
	  if(turn%2 == 1) {
	   if(difficulty == 1) {
	     botsTurn();
	   }
	   if(difficulty == 2) {
	     mediumDifficulty();
	   }
	   if(difficulty == 3) {
	      hardDifficulty();
	   }
	}
      }
      if(numberOfPlayers == 2) {
         if(turn%2==1) {
	   to_string();
	   cout << "Player 2 input the number where you want to put your O" << endl;
	   personTurn2();
	 }
      }
}

bool TicTac::hasWon() {
	int numberOfX1 = 0;
	int numberOfX2 = 0;
	int numberOfO1 = 0;
	int numberOfO2 = 0;
	int player1 = 0;
	int player2 = 0;
	for(int i = 0; i<ROW_SIZE; i++) {
	   for(int j = 0; j<COL_SIZE; j++) {
	   	if(board[i][j] == PLAYER1) {
			numberOfX1++;
		}
		if(board[j][i] == PLAYER1) {
			numberOfX2++;
		}
		if(board[i][j] == PLAYER2) {
			numberOfO1++;
		}
		if(board[j][i] == PLAYER2) {
			numberOfO2++;
		}
		if(numberOfX1 == 3 || numberOfX2 == 3) {
	          	player1 = 1;
			//return true;
		}
		if(numberOfO1 == 3 || numberOfO2 == 3) {
			//cout << "Player 2 has Won!" << endl;
			//return true;
			player2 = 1;
		}
	}
	numberOfX1 = 0;
	numberOfX2 = 0;
	numberOfO1 = 0;
	numberOfO2 = 0;
  }
  if(player1 == 1) {
  	cout << "Player 1 has Won!" << endl;
	return true;
	exit(0);
  }
  if(player2 == 1) {
  	cout << "Player 2 has Won!" << endl;
	return true;
	exit(0);
  }
  if((board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X") || (board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X")) {
  	cout << "Player 1 has Won!" << endl;
	return true;
	exit(0);
  }
  if((board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O") || (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O")){
  	cout << "Player 2 has Won!" << endl;
	return true;
	exit(0);
  }
  return false;
}

void TicTac::changeArray() {

}

void TicTac::setCell(string value, int rowIndex, int colIndex) {
	board[rowIndex][colIndex] = value;
}

string TicTac::to_string() const {
cout << endl;
for(int i = 0; i<ROW_SIZE; i++) {
	 for(int j = 0; j<COL_SIZE; j++) {
	 	if(j==COL_SIZE-1) {
			cout << board[i][j];
		} else {
			cout << board[i][j] << " | ";
		}
	  }
	  	if(i==ROW_SIZE-1) {
			cout << endl;
		} else {
	  		cout << endl << "----------" << endl;
		}
}	
	string test = "";
	return test;
}

void TicTac::start() {
	cout << "Welcome! This is TicTacToe!" << endl;
	cout << "How many players?" << endl;
	cin >> numberOfPlayers;
	while(numberOfPlayers != 1 && numberOfPlayers != 2) {
		cout << "Error, enter 1 or 2 players" << endl;
		cin >> numberOfPlayers;
	}
	if(numberOfPlayers == 1) {
		cout << "What difficulty would you like?" << endl;
		cout << "Enter a number that corresponds to the difficulty" << endl;
		cout << "1:Easy, 2:Medium, 3:Hard" << endl;
		cin >> difficulty;
		while(difficulty != 1 && difficulty !=2 && difficulty != 3) {
		  cout << "Error, enter 1, 2, or 3" << endl;
		  cin >> difficulty;
		}
	}
	cout << "It's Player 1's turn! Input a number for where you want the X to go!" << endl;
		personTurn1();
}
