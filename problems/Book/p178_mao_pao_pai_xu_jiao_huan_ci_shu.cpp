#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

int bit[MAX_N + 1] = {0}, n;

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

typedef long long ll;
int a[MAX_N];

void solve() {
  ll ans = 0;
  for (int j = 0; j < n; j++) {
    ans += j - sum(a[j]);
    add(a[j], 1);
  }
  cout << ans << endl;
}

int main(int argc, char** argv) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  solve();
  return 0;
}