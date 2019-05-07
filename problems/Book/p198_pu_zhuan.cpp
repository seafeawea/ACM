#include <iostream>

using namespace std;

#define MAX_M 10

const int n = 3;
const int m = 3;
int color[n][m] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
const int M = 100;

int dp[2][1 << MAX_M];

void printDp(int* ptr) {
  for (int i = 0; i < 1 << m; i++) {
    cout << ptr[i] << " ";
  }
  cout << endl;
}

void solve() {
  int *crt = dp[0], *next = dp[1];
  crt[0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      for (int used = 0; used < 1 << m; used++) {
        if ((used >> j & 1) || color[i][j]) {
          next[used] = crt[used & ~(1 << j)];
        } else {
          int res = 0;
          if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1]) {
            res += crt[used | 1 << (j + 1)];
          }
          if (i + 1 < n && !color[i + 1][j]) {
            res += crt[used | 1 << j];
          }
          next[used] = res % M;
        }
      }

      for (int k = 0; k < 1 << m; k++) {
        cout << crt[k] << " ";
      }
      cout << "    i=" << i << ", j=" << j << endl;

      swap(crt, next);
    }
  }
  printDp(crt);
  cout << crt[0] << endl;
}

int main() {
  solve();
  return 0;
}
