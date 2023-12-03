#include <vector>
#include <iostream>
#include <algorithm>

void greeting() {
  std::cout << "======================\n";
  std::cout << "Tic-Tac Toe\n";
  std::cout << "======================\n";
  std::cout << "Instructions: Two players will take turns choosing which\nposition on the grid to place their X or O. Positions are chosen\nvia numbers 1-9 representing the sections on the grid left to right\n \n";
}

void drawGame() {
  std::cout << "ITS A TIE!!!!!";
}

std::vector<std::string> placeChoice(char playerToken, int pChoice, std::vector<std::string> gameboard) {
  std::string position = gameboard[pChoice - 1];
  if (pChoice % 3 == 0) {
    position[3] = playerToken;
  } else {
      position[2] = playerToken;
  }
  gameboard[pChoice - 1] = position;
  return gameboard;
}

int squareTaken(int pChoice, std::vector<int> squaresChosen) {
    for (int i = 0; i < squaresChosen.size(); i++) {
      if(pChoice == squaresChosen[i]) {
        std::cout << "That Square is taken! Don't cheat, pick another square: \n";
        std::cin >> pChoice;
        i = 0;
      }
    }
  return pChoice;
}

bool winCheck(std::vector<int> pSquares) {
  if (pSquares.size() < 3) {
    return false;
  }

  std::vector<std::vector<int>> winCombinations {{1,2,3}, {1,4,7}, {1,5,9}, {2,5,8}, {3,5,7}, {3,6,9}, {4,5,6}, {7,8,9}};
  for(int i = 0; i < winCombinations.size(); i++) {
    std::sort(pSquares.begin(), pSquares.end());
    std::sort( winCombinations[i].begin(), winCombinations[i].end());
    if (std::includes(pSquares.begin(), pSquares.end(), winCombinations[i].begin(), winCombinations[i].end())) {
        return true;
    }
  }
  return false;
}

int playerTurn(std::vector<int> squaresChosen, std::vector<int> pSquares, int player, char playerToken) {
  int choice;
  std::cout << "Player " << player << "'s turn! pick a number to place an " << playerToken <<".\n";
  std::cin >> choice;
  choice = squareTaken(choice, squaresChosen);
  squaresChosen.push_back(choice);
  pSquares.push_back(choice);
  return choice;
}

void displayGameboard(std::vector<std::string> gameboard) {
  std::cout << "     |     |     \n";
  for(int i = 0; i < gameboard.size(); i++ ) {
    std::cout << gameboard[i];
    if (i == 2 || i == 5) {
      std::cout << "_____|_____|_____\n";
      std::cout << "     |     |     \n";
    }
  }
  std::cout << "     |     |     \n \n";
}
