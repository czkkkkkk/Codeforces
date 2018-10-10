// Given a tree, compute the distance of each pair of node \
// after adding a new edge between each pair of node that share a common neighbor
//
//
//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define N 200020

long long f[N], ans[N];

int sz[N];
int odd[N];

vector<vector<int>> vec;

int n;

void dfs(int u, int p) {
  sz[u] = 1;
  f[u] = 0;
  odd[u] = 0;
  for(auto v : vec[u]) {
    if(v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
    f[u] += f[v] + sz[v];
    odd[u] += sz[v] - odd[v];
  }
}
void dfs1(int u, int p) {
  if(p == -1) ans[u] = f[u];
  else {
    ans[u] = ans[p] + n - 2 * sz[u];
    odd[u] = n - odd[p];
  }
  for(auto v : vec[u]) {
    if(v == p) continue;
    dfs1(v, u);
  }
}
int main() {

  scanf("%d", &n);
  for(int i = 0; i <= n; ++i) vec.push_back(vector<int>());
  for(int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  dfs(1, -1);
  dfs1(1, -1);
  long long res = 0;
  for(int i = 1; i <= n; ++i) {
    res += odd[i] + ans[i];
  }
  res /= 4;
  printf("%lld\n", res);
  return 0;
}

