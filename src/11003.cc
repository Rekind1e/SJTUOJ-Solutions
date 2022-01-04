#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N][N];

int main() {
  memset(a, -1, sizeof a);
  int n; cin >> n;
  int rem = 0;
  queue<pair<int, int>> q;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
    cin >> a[i][j];
    if (a[i][j] == 1) q.push({i, j}), rem--;
    if (a[i][j] <= 1) rem++;
  }
  for (int t = 1; ; ++t) {
    int sz = q.size();
    while (sz--) {
      auto [i, j] = q.front(); q.pop();
      for (auto [dx, dy]: vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
        int x = i + dx, y = j + dy;
        if (a[x][y] == 0) {
          q.push({x, y});
          a[x][y] = 1;
          if (--rem == 0) {
            cout << t << endl;
            return 0;
          }
        }
      }
    }
  }

}