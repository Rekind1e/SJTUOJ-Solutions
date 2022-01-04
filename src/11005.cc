#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int row[9] {}, col[9] {}, cell[9] {};
  bool ok = true;
  for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
    int x; cin >> x;
    if (row[i] >> x & 1 || col[j] >> x & 1 || cell[i / 3 * 3 + j / 3] >> x & 1) 
      ok = false;
    row[i] |= 1 << x;
    col[j] |= 1 << x;
    cell[i / 3 * 3 + j / 3] |= 1 << x;
  }
  return ok;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) cout << (solve()? "Right" : "Wrong") << endl;
}