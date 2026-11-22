/**
 * Problem name: Knight Moves Grid
 * Link: https://cses.fi/problemset/task/3217/
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int dx[]={2, 2, -2, -2, 1, -1, 1, -1};
int dy[]={1, -1, 1, -1, 2, 2, -2, -2};

int main() {
  int n;
  cin>>n;

  vector<vector<int>> grid(n, vector<int>(n, 1e9));

  // Approach: BFS
  // Complexity: O(8*n^2), will pass under 1s

  queue<pair<int, int>> q;

  grid[0][0]=0;
  q.push({0, 0});

  while(!q.empty()) {
    auto [i, j]=q.front();
    q.pop();

    for(int d=0; d<8; d++) {
      int ni=i+dx[d];
      int nj=j+dy[d];

      if(ni<0 or nj<0 or ni>=n or nj>=n)
        continue;

      if(grid[i][j]+1>=grid[ni][nj])
        continue;

      grid[ni][nj]=grid[i][j]+1;

      q.push({ni, nj});
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++)
      cout<<grid[i][j]<<' ';

    cout<<endl;
  }

  return 0;
}