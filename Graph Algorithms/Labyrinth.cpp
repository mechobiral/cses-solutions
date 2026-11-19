/**
 * Problem Name: Labyrinth
 * Link: https://cses.fi/problemset/task/1193
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin>>n>>m;

  int start_i, start_j;
  int end_i, end_j;
  vector<vector<char>> v(n, vector<char>(m));

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>v[i][j];

      if(v[i][j]=='A') {
        start_i=i;
        start_j=j;
      }

      if(v[i][j]=='B') {
        end_i=i;
        end_j=j;
      }
    }
  }

  vector<vector<char>> prev(n, vector<char>(m, '?'));

  // Approach: BFS with prev track
  queue<pair<int, int>> q;
  vector<vector<bool>> vis(n, vector<bool>(m));
  bool possible=0;

  q.push({start_i, start_j});
  vis[start_i][start_j]=1;

  while(!q.empty()) {
    auto [i, j]=q.front();
    q.pop();

    if(v[i][j]=='B') {
      possible=1;
      break;
    }

    if(i-1>=0 and v[i-1][j]!='#' and !vis[i-1][j]) {
      vis[i-1][j]=1;
      q.push({i-1, j});
      prev[i-1][j]='U';
    }

    if(i+1<n and v[i+1][j]!='#' and !vis[i+1][j]) {
      vis[i+1][j]=1;
      q.push({i+1, j});
      prev[i+1][j]='D';
    }

    if(j-1>=0 and v[i][j-1]!='#' and !vis[i][j-1]) {
      vis[i][j-1]=1;
      q.push({i, j-1});
      prev[i][j-1]='L';
    }

    if(j+1<m and v[i][j+1]!='#' and !vis[i][j+1]) {
      vis[i][j+1]=1;
      q.push({i, j+1});
      prev[i][j+1]='R';
    }
  }

  if(!possible)
    cout<<"NO"<<endl;

  else {
    cout<<"YES"<<endl;

    string path="";
    int i=end_i, j=end_j;

    while(v[i][j]!='A') {
      path+=prev[i][j];

      if(prev[i][j]=='U')
        i++;

      else if(prev[i][j]=='D')
        i--;

      else if(prev[i][j]=='L')
        j++;

      else
        j--;
    }

    reverse(path.begin(), path.end());

    cout<<path.size()<<endl;
    cout<<path<<endl;
  }

  return 0;
}
