#include <iostream>

using namespace std;

char tiles[20][20];

void printTiles()
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cout << tiles[i][j];
        }
        cout << endl;
    } 
}

int main(int argc, char **argv) {
    int W, H;

    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%c",&tiles[i][j]);
            }
        }
        printTiles();
    }
    return 0;
}