#include <iostream>
using namespace std;

char Board[3][3];
char currentPlayer;

void initializeBoard()
{
    char ch = '1';
    for ( int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Board[i][j] = ch++;
        }
    }
}
void DisplayBoard()
{
    cout << "\n";
    for ( int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << Board[i][j];
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
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool checkwin(){
    
    for(int i = 0; i < 3;i++){
        if((Board[i][0] == currentPlayer &&
           Board[i][1] == currentPlayer &&
           Board[i][2] == currentPlayer) ||
        ( Board[0][i] == currentPlayer &&
          Board[1][i] == currentPlayer &&
          Board[2][i] == currentPlayer)) 
          return true;
    }

 
     if ((Board[0][0] == currentPlayer &&
         Board[1][1] == currentPlayer &&
         Board[2][2] == currentPlayer) ||
        (Board[0][2] == currentPlayer &&
         Board[1][1] == currentPlayer &&
         Board[2][0] == currentPlayer))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (Board[i][j] != 'X' && Board[i][j] != 'O')
                return false;
    return true;
}


void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || Board[row][col] == 'X' || Board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        makeMove();
    } else {
        Board[row][col] = currentPlayer;
    }
}
int main(){
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            DisplayBoard();
            makeMove();

            if (checkwin()) {
                DisplayBoard();
                cout << " Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                DisplayBoard();
                cout << " It's a draw!\n";
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


