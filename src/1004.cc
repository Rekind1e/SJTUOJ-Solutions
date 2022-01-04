#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  set<int> s;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (i == 0) ans += x;
    else {
      int d = INT_MAX;
      auto it = s.lower_bound(x);
      if (it != s.end()) d = min(d, *it - x);
      if (it != s.begin()) {
        it--;
        d = min(d, x - *it);
      }
      ans += d;
    }
    s.insert(x);
  }
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
}