#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int M, T, U, F, D; cin >> M >> T >> U >> F >> D;
  for (int i = 1; i <= T; ++i) {
    char c; cin >> c;
    if (c == 'u' || c == 'd') a[i] = a[i - 1] + U + D;
    else a[i] = a[i - 1] + F + F;
  }
  int lo = 0, hi = T;
  while (lo < hi) {
    int mid = lo + hi + 1 >> 1;
    if (a[mid] <= M) lo = mid;
    else hi = mid - 1;
  }
  cout << lo << endl;
}