#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n; cin >> h >> w >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x <= h + w) ans++;
  }
  cout << ans << endl;

}