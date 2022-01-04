#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1, ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1;ch = getchar();}
	while (ch >= '0' && ch <= '9'){x=x * 10 + ch - 48;ch = getchar();}
	return x * f;
}

int a[400];

void prod() {
  for (int i = 0, r = 0; i < 400; ++i) {
    r += a[i] * 2;
    a[i] = r % 10;
    r /= 10;
  }
}

void subtract() {
  for (int i = 0, r = 0; i < 400; ++i) {
    if (i == 0) r = (a[i] - 3 < 0), a[i] = (a[i] + 7) % 10;
    else {
      if (!r) break;
      r = (a[i] - 1 < 0), a[i] = (a[i] + 9) % 10;
    }
  }
}

int main() {
  
  int m = read(), n = read();
  int ans;
  if (m == 0) ans = n + 1;
  if (m == 1) ans = n + 2;
  if (m == 2) ans = 2 * n + 3;

  if (m == 3) {
    a[0] = 1;
    for (int i = 0; i < n + 3; ++i) prod();
    subtract();
    int loc = 399;
    while (a[loc] == 0) loc--;
    for (; loc >= 0; --loc) printf("%d", a[loc]);
  } else {
    printf("%d", ans);
  }
}