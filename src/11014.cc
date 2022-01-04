#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
char a[N], b[N], c[N];

int main() {

  scanf("%s", a);
  scanf("%s", b);
  int n = strlen(a), m = strlen(b), k = 0;
  reverse(a, a + n);
  reverse(b, b + m);
  for (int i = 0, r = 0; i < n || i < m || r; i++, k++) {
    if (i < n) r += a[i] - '0';
    if (i < m) r += b[i] - '0';
    c[i] = r % 10 + '0';
    r /= 10;
  }
  reverse(c, c + k);
  printf("%s\n", c);
  

}