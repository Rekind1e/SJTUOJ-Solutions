#include <iostream>
#include <algorithm>
using namespace std;

inline int read() {
	int x = 0, f = 1, ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1;ch = getchar();}
	while (ch >= '0' && ch <= '9'){x=x * 10 + ch - 48;ch = getchar();}
	return x * f;
}

const int N = 1e5 + 10;
int a[2][N];

int main() {
  int n = read();
  for (int i : {0, 1}) {
    for (int j = 0; j < n; ++j) a[i][j] = read();
    sort(a[i], a[i] + n);
  }
  int64_t mx = 0, mi = 0;
  for (int i = 0; i < n; ++i) {
    mi += int64_t(a[0][i]) * a[1][n - i - 1];
    mx += int64_t(a[0][i]) * a[1][i];
  }

  printf("%ld %ld\n", mx, mi);
  
}