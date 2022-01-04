#include <bits/stdc++.h>
using namespace std;

const int N = 210;
int a[N], b[N], c[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string x, y; cin >> x >> y;
  int n = 0, m = 0, k = 0;
  for (int i = x.size() - 1; i >= 0; --i) {
    if (x[i] == '.') continue;
    a[++n] = x[i] - '0';
  } 
  for (int i = y.size() - 1; i >= 0; --i) {
    if (y[i] == '.') continue;
    b[++m] = y[i] - '0';
  } 
  for (int i = 1, r = 0; i <= n || i <= m || r; ++i) {
    r += a[i] + b[i];
    c[i] = r % 10;
    r /= 10;
    k = i;
  }
  for (int i = k; i; --i) {
    cout << c[i];
    if (i == 3) cout << '.';
  }
  cout << endl;
}