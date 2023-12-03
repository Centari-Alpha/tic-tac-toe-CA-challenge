#include <iostream>
#include <vector>
#include <stdlib.h>
#include "ttt_functions.hpp"

int main() {
  std::string topLeft = "     |";
  std::string topMid = "     ";
  std::string topRight = "|    \n";
  std::string left = "     |";
  std::string mid = "     ";
  std::string right = "|    \n";
  std::string botLeft = "     |";
  std::string botMid = "     ";
  std::string botRight = "|    \n";
  std::vector<std::string> gameboard {topLeft, topMid, topRight, left, mid, right, botLeft, botMid, botRight};
  std::vector<int> squaresChosen;
  std::vector<int> p1Squares;
  std::vector<int> p2Squares;

  greeting();

  for(int i = 0; i < 9; i++) {
    displayGameboard(gameboard);
    if(winCheck(p1Squares) == true) {
      std::cout << "PLAYER 1 IS HAS TAKEN THE VICTORY!!!! \n";
      return 0;
    }
    if(winCheck(p2Squares) == true) {
      std::cout << "PLAYER 2 IS VICTORIOUS!!!! \n";
      return 0;
    }
    if(i % 2 == 0) {
      int p1Choice = playerTurn(squaresChosen, p1Squares, 1, 'X');
      gameboard = placeChoice('X', p1Choice, gameboard);
      p1Squares.push_back(p1Choice);

    } else {
        int p2Choice = playerTurn(squaresChosen, p2Squares, 2, 'O');
        gameboard = placeChoice('O', p2Choice, gameboard);
        squaresChosen.push_back(p2Choice);
    }
  }
  displayGameboard(gameboard);
  drawGame();
}