#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int ans = a[1] + a[2];
  for (int i = 3, cur = a[1] + a[2]; i <= n; ++i) {
    cur = max(cur + a[i], a[i - 1] + a[i]);
    ans = max(ans, cur);
  }
  cout << (ans > 0? to_string(ans) : "Game Over") << endl;
}