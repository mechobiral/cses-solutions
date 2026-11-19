/**
 * Problem name: Chessboard and Queens
 * Link: https://cses.fi/problemset/task/1624
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> grid(8, vector<char>(8));
vector<bool> occupied_col(8);
vector<bool> occupied_diag1(16); // (0, 0)->(8, 8)
vector<bool> occupied_diag2(16); // (0, 8)->(8, 0)

void put_queen(int row, int& ans) {
  if(row==8) {
    ans++;
    return;
  }

  for(int col=0; col<8; col++) {
    if(grid[row][col]=='*')
      continue;

    if(occupied_col[col]==1)
      continue;

    // 1 2 3 ...
    // 2 3 4 ...
    // 3 4 5 ...
    // . . . ...
    // Diagonals can be identified as (row+col) and (row+(8-col))

    if(occupied_diag1[row+col] or occupied_diag2[row+(8-col)])
      continue;

    occupied_col[col]=1;
    occupied_diag1[row+col]=1;
    occupied_diag2[row+(8-col)]=1;

    put_queen(row+1, ans);

    occupied_col[col]=0;
    occupied_diag1[row+col]=0;
    occupied_diag2[row+(8-col)]=0;
  }
}

int main() {
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++)
      cin>>grid[i][j];
  }

  // Approach: Recursion (Backtrack)
  // Complexity: O(n!), n<=8, should pass constraints

  int ans=0;
  put_queen(0, ans);

  cout<<ans<<endl;

  return 0;
}