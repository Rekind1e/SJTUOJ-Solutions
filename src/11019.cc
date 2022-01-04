#include <bits/stdc++.h>
using namespace std;

char s[110];

int main() {
  int t; cin >> t;
  while (t--) {
    scanf("%s", s);
    int c = 0;
    bool ok = true;
    for (int i = 0; s[i]; ++i) {
      if (s[i] == '(') c++;
      else {
        if (--c < 0) {
          ok = false;
          break;
        }
      } 
    }
    printf("%s\n", (ok && c == 0)? "YES" : "NO");
  }
}