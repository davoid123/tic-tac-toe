#ifndef TICTACTOE
#define TICTACTOE

int printWelcome(void);
int goFirst(void);
void printBoard(std::array<char, 9> board);
std::array<char, 9> playerMove(std::array<char, 9> board);
std::array<char, 9> compMove(std::array<char, 9> board);
int won(std::array<char, 9> board);
int loss(std::array<char, 9> board);
int tie(std::array<char, 9> board);
int ending(int i);

#endif