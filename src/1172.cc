#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<int> p(n + 1);
  iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&] (int u) {
    return u == p[u]? u : p[u] = find(p[u]);
  }; 
  
  while (m--) {
    int z, x, y; cin >> z >> x >> y;
    if (z == 1) {
      p[find(x)] = find(y);
    } else {
      cout << (find(x) == find(y)? "Y" : "N") << endl;
    }
  }
}