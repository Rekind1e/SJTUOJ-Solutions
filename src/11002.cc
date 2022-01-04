#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int sum[N][N];

int main() {
  int m, n; cin >> m >> n;
  for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
    cin >> sum[i][j];
    sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  }
  int a, b; cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= m; ++i) for (int j = b; j <= n; ++j) {
    ans = max(ans, sum[i][j] - sum[i - a][j] - sum[i][j - b] + sum[i - a][j - b]);
  }
  cout << ans << endl;
}