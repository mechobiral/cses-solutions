/**
 * Problem name: Grid Coloring I
 * Link: https://cses.fi/problemset/task/3311
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin>>n>>m;

  vector<vector<char>> grid(n, vector<char>(m));

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++)
      cin>>grid[i][j];
  }

  // Logic: Use 'A'/'C' for odd (i+j), 'B'/'D' for even (i+j)

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if((i+j)%2) {
        if(grid[i][j]=='A')
          grid[i][j]='C';
        else
          grid[i][j]='A';
      }

      else {
        if(grid[i][j]=='B')
          grid[i][j]='D';

        else
          grid[i][j]='B';
      }
    }
  }

  // Validate answer
  bool possible=1;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(i and grid[i][j]==grid[i-1][j])
        possible=0;

      if(i<n-1 and grid[i][j]==grid[i+1][j])
        possible=0;

      if(j and grid[i][j]==grid[i][j-1])
        possible=0;

      if(j<m-1 and grid[i][j]==grid[i][j+1])
        possible=0;

      if(!possible)
        break;
    }

  if(!possible)
    break;
  }

  if(possible) {
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++)
        cout<<grid[i][j];

      cout<<endl;
    }
  }

  else {
    cout<<"IMPOSSIBLE"<<endl;
  }

  return 0;
}