#include <iostream>
using namespace std;

bool isSafe(int** board, int row, int col, int N) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int** board, int col, int N) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1, N))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

void printSolution(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        cout << endl;
    }
}

void solveNQ(int N) {
    int** board = new int*[N];
    for (int i = 0; i < N; i++)
        board[i] = new int[N]{0};

    if (!solveNQUtil(board, 0, N)) {
        cout << "Solution does not exist" << endl;
        for (int i = 0; i < N; i++)
            delete[] board[i];
        delete[] board;
        return;
    }

    printSolution(board, N);

    for (int i = 0; i < N; i++)
        delete[] board[i];
    delete[] board;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    solveNQ(N);
    return 0;
}
