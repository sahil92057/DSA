#include <iostream>
using namespace std;

vector<bool> upperDiagonal;
vector<bool> lowerDiagonal;
vector<bool> row;

void saveAns(vector<vector<string>> &output, vector<vector<char>> &board) { 
    vector<string> tempans;
    for (auto it : board) {
        string str;
        for (auto ch : it) {
            str += ch;
        }
        tempans.push_back(str);
    }
    output.push_back(tempans);
}

bool isSafe(int i, int j, int n) {
    if (row[i] || lowerDiagonal[i + j] || upperDiagonal[n - 1 + i - j]) {
        return false;
    }
    return true;
}

void solveQueen(int col, vector<vector<string>> &output, int n, vector<vector<char>> &board) {
    if (col >= n) {
        saveAns(output, board);
        return;
    }
    for (int rowIdx = 0; rowIdx < n; rowIdx++) {
        if (isSafe(rowIdx, col, n)) {
            board[rowIdx][col] = 'Q';
            row[rowIdx] = true;
            lowerDiagonal[rowIdx + col] = true;
            upperDiagonal[n - 1 + rowIdx - col] = true;

            solveQueen(col + 1, output, n, board);

            board[rowIdx][col] = '.';
            row[rowIdx] = false;
            lowerDiagonal[rowIdx + col] = false;
            upperDiagonal[n - 1 + rowIdx - col] = false;
        }
    }
}

int main() {
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> output;

    row.resize(n, false);
    lowerDiagonal.resize(2 * n - 1, false);
    upperDiagonal.resize(2 * n - 1, false);

    solveQueen(0, output, n, board);

    // Print solutions
    for (auto &solution : output) {
        for (auto &rowStr : solution) {
            cout << rowStr << endl;
        }
        cout << endl;
    }

    return 0;
}
