#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

char tiles[20][20]; // row column
int W, H;
vector<int> results;

void printTiles()
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cout << tiles[i][j];
        }
        cout << endl;
    } 
}

int dfs(int curY, int curX) {
    tiles[curY][curX] = '@';
    int result = 1;

    if (curX > 0 && tiles[curY][curX-1] == '.') {
        result += dfs(curY, curX-1);
    }
    if (curY > 0 && tiles[curY-1][curX] == '.') {
        result += dfs(curY-1, curX);
    }
    if (curX < W-1 && tiles[curY][curX+1] == '.') {
        result += dfs(curY, curX+1);
    }
    if (curY < H-1 && tiles[curY+1][curX] == '.') {
        result += dfs(curY+1, curX);
    }

    return result;
}

int main(int argc, char **argv) {
    int startRow, startCol;

    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> tiles[i][j];
                if (tiles[i][j] == '@') {
                    startRow = i;
                    startCol = j;
                }
            }
        }
        results.push_back(dfs(startRow, startCol));
        //printTiles();
    }

    for (vector<int>::const_iterator it = results.begin(); it != results.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}