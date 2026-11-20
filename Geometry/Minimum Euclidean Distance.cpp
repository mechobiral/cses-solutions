/**
 * Problem name: Minimum Euclidean Distance
 * Link: https://cses.fi/problemset/task/2194
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

struct Point {
  long long int x;
  long long int y;

  bool operator<(const Point& p) const {
    if(x==p.x)
      return y<p.y;

    return x<p.x;
  }
};

long long int dist(Point a, Point b) {
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main() {
  int n;
  cin>>n;

  vector<Point> points(n);
  for(int i=0; i<n; i++) {
    cin>>points[i].x>>points[i].y;
  }

  // Approach: Line Sweep algorithm

  sort(points.begin(), points.end());

  // Any point `a` with distance >= dist with the current point can be discarded
  long long int mn_dist = 8e18;
  long long int left=0;

  set<Point> active;
  active.insert({points[0].y, points[0].x});

  // {y, x} is inserted first because we need to binsearch on y

  for(int i=1; i<n; i++) {
    long long int sqrt_d = ceil(sqrt(mn_dist));

    while(left<i and points[left].x<points[i].x-sqrt_d) {
      active.erase({points[left].y, points[left].x});
      left++;
    }

    auto lb=active.lower_bound({points[i].y-sqrt_d, 0});
    auto ub=active.upper_bound({points[i].y+sqrt_d, 0});

    for(auto it=lb; it!=ub; it++)
      mn_dist=min(mn_dist, dist({it->y, it->x}, points[i]));

    active.insert({points[i].y, points[i].x});
  }

  cout<<mn_dist<<endl;

  return 0;
}