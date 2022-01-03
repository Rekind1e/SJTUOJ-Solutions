#include <bits/stdc++.h>
using namespace std;

int64_t a[100010];
int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  for (int i = 1; i < n; ++i) a[i] += a[i - 1];
  double ans = 0.0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, double(a[i]) / (i + 1));
  }
  cout << ans << endl;
}