#include <iostream>

using namespace std;

bool checkWin(int player, int board[3][3]);
bool checkTie(int board[3][3]);

void printBoard(int board[3][3]);

int main() {
  int board[3][3];

  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;

  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;

  int xwin = 0;
  int owin = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = BLANK;
    }
  }

  bool stillPlaying = true;

  while (stillPlaying == true) {
    while (checkWin(X_MOVE, board) == false && checkWin(O_MOVE, board) == false && checkTie(board) == false) {
      printBoard(board);

      char input[2];
      cin.getline(input, 256);

      if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
        cout << "Row must be one of a, b, or c." << endl;
      }

      if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
        cout << "Column must be one of 1, 2, or 3." << endl;
      }

      else {
        int row = input[0] - 'a';
        int column = (int)input[1] - 49;
        if (board[row][column] == BLANK) {
          if (turn == X_TURN) {
            board[row][column] = X_MOVE;
            turn = O_TURN;
          }
          else {
            board[row][column] = O_MOVE;
            turn = X_TURN;
          }
        }
        else {
          cout << "There is a piece there already!";
        }
      }
    }

    if (checkWin(X_MOVE, board) == true) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          board[i][j] = 0;
        }
      }
      turn = X_TURN;
      xwin = xwin + 1;
      cout << "X wins!" << endl;
      cout << "X has won " << xwin << " time(s) and O has won " << owin << " time(s)." << endl;
      cout << "Do you want to play again?" << endl;
      char yesno[1];
      cin.getline(yesno, 256);
      if (yesno[0] == 'y') {
        stillPlaying = true;
      }
      else {
        stillPlaying = false;
      }
    }

    if (checkWin(O_MOVE, board) == true) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          board[i][j] = 0;
        }
      }
      turn = X_TURN;
      owin = owin + 1;
      cout << "O wins!" << endl;
      cout << "O has won " << owin << " time(s) and X has won " << xwin << " time(s)." << endl;
      cout << "Do you want to play again?" << endl;
      char yesno[1];
      cin.getline(yesno, 2);
      if (yesno[0] == 'y') {
        stillPlaying = true;
      }
      else {
        stillPlaying = false;
      }
    }

    if (checkTie(board) == true) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          board[i][j] = 0;
        }
      }
      turn = X_TURN;
      cout << "You guys tied!" << endl;
      cout << "X has won " << xwin << " time(s) and O has won " << owin << " time(s)." << endl;
      cout << "Do you want to play again?" << endl;
      char yesno[1];
      cin.getline(yesno, 2);
      if (yesno[0] == 'y') {
        stillPlaying = true;
      }
      else {
        stillPlaying = false;
      }
    }
  }
  return 0;
}

void printBoard(int board[3][3]) {
  cout << " \t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    cout << (char)('a' + row) << "\t";
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == 0) {
        cout << " \t";
      }
      if (board[row][column] == 1) {
        cout << "X\t";
      }
      if (board[row][column] == 2) {
        cout << "O\t";
      }
    }
    cout << endl;
  }
}

bool checkWin(int player, int board[3][3]) {
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

bool checkTie(int board[3][3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == 0) {
        return false;
      }
    }
  }
  return true;
}
