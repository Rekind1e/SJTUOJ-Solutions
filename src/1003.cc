#include <iostream>
using namespace std;

const int N = 1e6 + 10, M = 1e7 + 10;
int a[N], c[M];

void rsort(int lo, int hi) {
  for (int i = lo; i <= hi; ++i) c[a[i]]++;
  for (int i = 0, j = 0; j < M; ++j) {
    for (; c[j]; c[j]--) a[i++] = j;
  }
}

int main() {
  int n, t, k; cin >> n >> t >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  rsort(0, n - 1);
  double ans = 0.0;
  for (int i = 0; i < n; ++i) {
    if ((t += a[i]) >= k) {
      ans += double(n - i) / n * 10.0; 
      break;
    }
    ans += 100.0 / n;
  }
  cout << int(ans + 1e-7) << endl;
}