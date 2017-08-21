#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > sudoku(9, vector<int>(9));
string s;

void printSudoku() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
}

void readSudoku() {
    for (int i = 0; i < 9; ++i) {
        cin >> s;
        for (int j = 0; j < 9; ++j)
            sudoku[i][j] = s[j] - '0';
    }
}

int isValid(int n, int row, int col) {
    int sectorRow = 3*(row/3);
    int sectorCol = 3*(col/3);

    // check for value in given row and column
    for (int i = 0; i < 9; ++i) {
        if (sudoku[row][i] == n) return 0;
        if (sudoku[i][col] == n) return 0;
    }

    // check block
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (sudoku[sectorRow + i][sectorCol + j] == n)
                return 0;

    return 1;
}

int solveSudoku(int row, int col) {
    if (row == 9)
        return 1;

    if (sudoku[row][col] != 0) {
        if (col == 8) {
            if (solveSudoku(row+1, 0)) return 1;
        } else {
            if (solveSudoku(row, col+1)) return 1;
        }
        return 0;
    }

    for (int i = 1; i <= 9; ++i) {
        if (isValid(i, row, col)) {
            sudoku[row][col] = i;
            if (col == 8) {
                if (solveSudoku(row+1, 0)) return 1;
            } else {
                if (solveSudoku(row, col+1)) return 1;
            }
            sudoku[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int res = 0;

    while (cin >> s >> s) {
        readSudoku();
        solveSudoku(0, 0);
        res += sudoku[0][0]*100 + sudoku[0][1]*10 + sudoku[0][2];
    }

    cout << res << endl;

    return 0;
}
