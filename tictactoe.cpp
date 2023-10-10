#include <iostream>
#include <vector>
// TIC TAC TOE: Tic tac toe game that allows players to play moves by entering
// column number and row letter. Whomever gets 3 consectutive X's or O's in a
// row first wins. Arjun Pai Period 6
//  10/08/23
using namespace std;

// Function 
        if (board[i * 3] == currentPlayer && board[i * 3 + 1] == currentPlayer && bto print the Tic-Tac-Toe board
void printBoard(const char board[]) {
   cout << "   1   2   3" << endl;
    cout << "A  " << board[0] << " | " << board[1] << " | " << board[2] << endl;
 cout << "  ---|---|---" << endl;
 cout << "B  " << board[3] << " | " << board[4] << " | " << board[5] << endl;
              cout << "  ---|---|---" << endl;
    cout << "C  " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to check if the game is over
bool isGameOver(const char board[], char currentPlayer) {
    // Check for a win
    for (int i = 0; i < 3; i++) {
        if (board[i] == currentPlayer && board[i + 3] == currentPlayer && board[i + 6] == currentPlayer)
            return true; // Vertical win
        if (board[i * 3] == currentPlayer && board[i * 3 + 1] == currentPlayer && board[i * 3 + 2] == currentPlayer)
            return true; // Horizontal win
    }
    if (board[0] == currentPlayer && board[4] == currentPlayer && board[8] == currentPlayer)
        return true; // Diagonal win
    if (board[2] == currentPlayer && board[4] == currentPlayer && board[6] == currentPlayer)
        return true; // Diagonal win

    // Check for a tie
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ')
            return false; // Game is not over
    }

    return true; // It's a tie
}

// Function to convert user input (e.g., "A1") to board index
        if (board[i * 3] == currentPlayer && board[i * 3 + 1] == currentPlayer && b
bool parseMove(const string& move, int& index) {
    if (move.length() != 2)
        return false;

    char rowChar = move[0];
    char colChar = move[1];

    if (rowChar >= 'A' && rowChar <= 'C' && colChar >= '1' && colChar <= '3') {
        int row = rowChar - 'A';
        int col = colChar - '1';
        index = row * 3 + col;
        return true;
    } else {
        return false;
    }
}

int main() {
    char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1 (X) vs Player 2 (O)" << endl;

    while (true) {
        printBoard(board);

        // Get user input
        string move;
        int index;
        cout << "Player " << currentPlayer << ", enter your move (e.g., A1): ";
        cin >> move;

        // Parse user input
        if (!parseMove(move, index) || board[index] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Make the move
        board[index] = currentPlayer;

        // Check if the game is over
        if (isGameOver(board, currentPlayer)) {
            printBoard(board);
            if (currentPlayer == 'X')
	      cout << "Player X wins! Congratulations!" << endl;
            else
                cout << "Player O wins! Congratulations!" << endl;            break;
        }
      // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}

OBOBOB        if (board[i * 3] == currentPlayer && board[i * 3 + 1] == currentPlayer && b
