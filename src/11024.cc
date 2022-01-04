#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1, ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1;ch = getchar();}
	while (ch >= '0'&&ch <= '9'){x=x * 10 + ch - 48;ch = getchar();}
	return x * f;
}

const int N = 10010;
int a[N];

void qsort(int lo, int hi) {
  if (lo >= hi) return ;
  int idx = rand() % (hi - lo + 1) + lo;
  swap(a[idx], a[hi]);
  int i = lo;
  for (int j = lo; j < hi; ++j) {
    if (a[j] < a[hi]) swap(a[i++], a[j]);
  }
  swap(a[i], a[hi]);
  qsort(lo, i - 1); 
  qsort(i + 1, hi);
}

int main() {
  int n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  qsort(1, n);
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
}