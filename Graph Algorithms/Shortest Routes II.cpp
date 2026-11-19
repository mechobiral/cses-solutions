/**
 * Problem Name: Shortest Routes II
 * Link: https://cses.fi/problemset/task/1672
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;
using LLI = long long int;

int main() {
  int n, m, q;
  cin>>n>>m>>q;

  // Approach: Floyd-Warshall Algorithm

  vector<vector<LLI>> dist(n+1, vector<LLI>(n+1, 1e18));
  for(int i=1; i<=n; i++)
    dist[i][i] = 0;

  for(int i=0; i<m; i++) {
    int a, b, c;
    cin>>a>>b>>c;

    dist[a][b] = min(dist[a][b], 1ll*c);
    dist[b][a] = min(dist[a][b], 1ll*c);
  }

  for(int k=1; k<=n; k++) {
    for(int j=1; j<=n; j++) {
      for(int i=1; i<=n; i++) {
        if(dist[i][k]!=1e18 and dist[k][j]!=1e18)
          dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }

  while(q--) {
    int x, y;
    cin>>x>>y;

    cout<<(dist[x][y]==1e18? -1 : dist[x][y])<<endl;
  }

  return 0;
}
