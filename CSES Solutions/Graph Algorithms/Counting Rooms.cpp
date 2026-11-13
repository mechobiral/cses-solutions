/**
 * Problem Name: Counting Rooms
 * Link: https://cses.fi/problemset/task/1192
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

vector<string> v;
vector<vector<bool>> visited;

void visit(int i, int j) {
  int n = v.size();
  int m = v[0].size();

  if(i<0 or i>=n or j<0 or j>=m)
    return;

  if(v[i][j]=='#' or visited[i][j])
    return;

  visited[i][j]=1;

  visit(i-1, j);
  visit(i+1, j);
  visit(i, j-1);
  visit(i, j+1);
}

int main() {
  int n, m;
  cin>>n>>m;

  v = vector<string>(n);
  visited = vector<vector<bool>>(n, vector<bool>(m, 0));

  for(int i=0; i<n; i++)
    cin>>v[i];

  int rooms = 0;
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(visited[i][j] or v[i][j]=='#')
        continue;

      rooms++;

      visit(i, j);
    }
  }

  cout<<rooms<<endl;

  return 0;
}