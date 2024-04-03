#include <iostream>

class TicTacToe
{
public:
enum { PLAYER_X = 'X', PLAYER_O = 'O', AVAILABLE = ' '};

void newGame()
{
for (int r = 0; r < 3; ++r)
{
for (int c = 0; c < 3; ++c)
{
board[r][c] = AVAILABLE;
}
}
}

void play()
{
for (int turns = 0; turns < 9; ++turns)
{
char player = (turns % 2 == 0 ? PLAYER_X : PLAYER_O);
bool legal = false;
do
{
int row = -1;
int col = -1;

std::cout << "\nPlayer " << player << " -- Choose a move..." << std::endl;
std::cout << "Enter row and col (e.g. 1 2): ";
std::cin >> row >> col;

legal = isLegalMove(row-1, col-1);

if (!legal)
{
std::cout << "Illegal move! Try again...\n" << std::endl;
}
else
{
board[row-1][col-1] = player;

displayBoard();

if (checkForWin(player))
{
std::cout << "Player " << player << " has won!" << std::endl;
exit(0);
}
}
} while (!legal);
}
std::cout << "The game ended in a tie!" << std::endl;
}

private:
void displayBoard()
{
std::cout << "+-----+-----+-----+\n";
for (int r = 0; r < 3; ++r)
{
std::cout << "|";
for (int c = 0; c < 3; ++c)
{
std::cout << " " << board[r][c] << " |";
}
std::cout << "\n+-----+-----+-----+\n";
}
std::cout << std::endl;
}

bool isLegalMove(int row, int col)
{
if (row < 0 || row > 2 || col < 0 || col > 2)
return false;

// return true if cell in board is available, false otherwise
return board[row][col] == AVAILABLE;
}

bool checkForWin(char player)
{
for (int r = 0; r < 3; ++r)
{
if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
return true;
}
for (int c = 0; c < 3; ++c)
{
if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
return true;
}
if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
(board[0][2] == player && board[1][1] == player && board[2][0] == player))
{
return true;
}
return false;
}

char board[3][3];
};

int main()
{
TicTacToe ttt;

ttt.newGame();
ttt.play();
}
