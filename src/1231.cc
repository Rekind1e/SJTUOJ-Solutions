#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  
  vector<int> p(n + 1);
  iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&] (int u) {
    return u == p[u]? u : p[u] = find(p[u]);
  };

  vector<array<int, 3>> edges(m);
  for (auto &[w, u, v] : edges) cin >> u >> v >> w;
  sort(edges.begin(), edges.end());

  int ans = 0;
  for (auto [w, u, v] : edges) {
    if (find(u) == find(v)) continue;
    ans += w;
    p[find(u)] = find(v);
  }
  cout << ans << endl;
}