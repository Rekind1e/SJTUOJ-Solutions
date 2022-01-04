#include <bits/stdc++.h>
using namespace std;

int a[2][2], b[2][2], mod = 2010;

void prod(int x[2][2], int y[2][2]) {
  int tmp[2][2] {};
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
    for (int k = 0; k < 2; ++k) tmp[i][j] += x[i][k] * y[k][j];
    tmp[i][j] %= mod;
  }
  memcpy(x, tmp, 4 * sizeof(int));
}

int main() {
  a[0][0] = a[1][1] = 1;
  b[0][0] = b[1][0] = b[0][1] = 1;
  int64_t n; scanf("%ld", &n);
  for (; n; n >>= 1) {
    if (n & 1) prod(a, b);
    prod(b, b);
  }
  printf("%d\n", a[1][0]);

}