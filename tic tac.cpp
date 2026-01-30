#include <iostream>
using namespace std;

char Board[3][3];
char Current player;

void initializeBoard()
{
    char ch = '1';
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ch++
        }
    }
}
void DisplayBoard()
{
    cout << "/n";
    for (i = 0; i < 3; i++)
    {
        cout << " ";
        for (j = 0; j < 3; j++)
        {
            cout << Borad[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---|---|---" << endl;
    }
    cout << "\n";
}

void switchPlayer(){
    currentplayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool checkwin(){
    
    for(int i = 0; i < 3;i++){
        if((board[i][0] == currentPlayer &&
        if board[i][1] == currentPlayer &&
        if board[i][2] == currentPlayer) ||
        ( board[0][i] == currentPlayer &&
          board[1][i] == currentPlayer &&
          board[2][i] == currentPlayer)) 
          return true;
    }

 
     if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}


void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        makeMove();
    } else {
        board[row][col] = currentPlayer;
    }
}
int main(){
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            makeMove();

            if (checkWin()) {
                displayBoard();
                cout << "?? Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "?? It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}


