#include <bits/stdc++.h>
using namespace std;

const int M = 1e4 + 10;
int dp[M];

int main() {
  int V, n; cin >> V >> n;
  for (int i = 0; i < n; ++i) {
    int v, w; cin >> v >> w;
    for (int j = v; j <= V; ++j) {
      dp[j] = max(dp[j], dp[j - v] + w);
    }
  }
  cout << dp[V] << endl;
}