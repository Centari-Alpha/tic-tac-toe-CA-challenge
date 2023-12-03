#include <vector>
#include <iostream>

void greeting();
void drawGame();
void displayGameboard(std::vector<std::string> gameboard);

int playerTurn(std::vector<int> squaresChosen, std::vector<int> pSquares, int player, char playerToken);

bool winCheck(std::vector<int> pSquares);

std::vector<std::string> placeChoice(char playerToken, int pChoice, std::vector<std::string> gameboard);