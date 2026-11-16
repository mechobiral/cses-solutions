/**
 * Problem Name: Monsters
 * Link: https://cses.fi/problemset/task/1194
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

// R, D, L, U
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char dc[] = {'R', 'D', 'L', 'U'};

int main() {
  int n, m;
  cin>>n>>m;

  vector<vector<char>> v(n, vector<char>(m));
  vector<pair<int, int>> exit;
  vector<pair<int, int>> monsters;

  int src_i, src_j;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>v[i][j];

      if(v[i][j]!='#') {
        if(i==0 or j==0 or i==n-1 or j==m-1)
          exit.push_back({i, j});
      }

      if(v[i][j]=='M') {
        monsters.push_back({i, j});
      }

      if(v[i][j]=='A') {
        src_i=i;
        src_j=j;
      }
    }
  }

  // Idea: every monster goes to their closest exit
  // Find if the player goes to any of the exit before the monster

  // Determine closest monsters to exits

  vector<vector<int>> dist_monster(n, vector<int>(m, 1e9));
  queue<pair<int, int>> q;

  for(int i=0; i<monsters.size(); i++) {
    auto [cur_i, cur_j]=monsters[i];

    q.push({cur_i, cur_j});
    dist_monster[cur_i][cur_j]=0;
  }

  while(!q.empty()) {
    auto [i, j]=q.front();
    q.pop();

    for(int k=0; k<4; k++) {
      int ni=i+dx[k];
      int nj=j+dy[k];

      if(ni<0 or ni>=n or nj<0 or nj>=m)
        continue;

      if(v[ni][nj]=='#')
        continue;

      if(dist_monster[i][j]+1>=dist_monster[ni][nj])
        continue;

      dist_monster[ni][nj]=dist_monster[i][j]+1;
      q.push({ni, nj});
    }
  }

  // Calculate minimum distance to exits for player
  vector<vector<int>> dist_player(n, vector<int>(m, 1e9));

  q.push({src_i, src_j});
  dist_player[src_i][src_j]=0;

  while(!q.empty()) {
    auto [i, j]=q.front();
    q.pop();

    for(int k=0; k<4; k++) {
      int ni=i+dx[k];
      int nj=j+dy[k];

      if(ni<0 or ni>=n or nj<0 or nj>=m)
        continue;

      if(v[ni][nj]=='#')
        continue;

      if(dist_player[i][j]+1>=dist_player[ni][nj])
        continue;

      dist_player[ni][nj]=dist_player[i][j]+1;
      q.push({ni, nj});
    }
  }

  // Find nearest exit for player without meeting monster
  int goal_i=-1;
  int goal_j=-1;

  for(int i=0; i<exit.size(); i++) {
    auto [cur_i, cur_j]=exit[i];

    if(monsters.empty()) {
      if(dist_player[cur_i][cur_j]==1e9)
        continue; // unreachable exit

      if(goal_i==-1 and goal_j==-1) {
        goal_i=cur_i;
        goal_j=cur_j;
      }

      else if(dist_player[goal_i][goal_j]>dist_player[cur_i][cur_j]) {
        goal_i=cur_i;
        goal_j=cur_j;
      }
    }

    if(dist_player[cur_i][cur_j]<dist_monster[cur_i][cur_j]) {
      goal_i=cur_i;
      goal_j=cur_j;

      break;
    }
  }

  if(goal_i==-1 and goal_j==-1) {
    cout<<"NO"<<endl;
  }

  else {
    cout<<"YES"<<endl;

    string path="";

    int cur_i=goal_i;
    int cur_j=goal_j;

    while(cur_i!=src_i or cur_j!=src_j) {
      for(int k=0; k<4; k++) {
        int ni=cur_i+dx[k];
        int nj=cur_j+dy[k];

        if(ni<0 or ni>=n or nj<0 or nj>=m)
          continue;

        if(v[ni][nj]=='#')
          continue;

        if(dist_player[ni][nj]>=dist_player[cur_i][cur_j])
          continue;

        char prev;
        if(dc[k]=='U') prev='D';
        else if(dc[k]=='D') prev='U';
        else if(dc[k]=='L') prev='R';
        else prev='L';

        path+=prev;
        cur_i=ni;
        cur_j=nj;
      }
    }

    reverse(path.begin(), path.end());

    cout<<path.size()<<endl;
    cout<<path<<endl;
  }

  return 0;
}
