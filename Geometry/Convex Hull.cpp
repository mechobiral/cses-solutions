/**
 * Problem name: Convex Hull
 * Link: https://cses.fi/problemset/task/2195
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;
};

long long int cross_prod(Point a, Point b, Point c) {
  return 1ll*(b.x-a.x)*(c.y-a.y)-1ll*(b.y-a.y)*(c.x-a.x);
}

int main() {
  int n;
  cin>>n;

  vector<Point> points(n);
  for(int i=0; i<n; i++) {
    cin>>points[i].x>>points[i].y;
  }

  // Approach: Convex Hull - Monotone chain algorithm

  sort(points.begin(), points.end(), [&](Point a, Point b) {
    if(a.x==b.x)
      return a.y<b.y;

    return a.x<b.x;
  });

  vector<Point> hull(2*n+10); // will work as a stack
  int hull_top = 0;

  // Construct lower hull
  for(int i=0; i<n; i++) {
    while(hull_top>=2 and cross_prod(hull[hull_top-2], hull[hull_top-1], points[i])<0)
      hull_top--;

    hull[hull_top]=points[i];
    hull_top++;
  }

  // Construct upper hull
  int t=hull_top+1;

  for(int i=n-1; i>0; i--) {
    while(hull_top>=t and cross_prod(hull[hull_top-2], hull[hull_top-1], points[i-1])<0)
      hull_top--;

    hull[hull_top]=points[i-1];
    hull_top++;
  }

  hull.resize(hull_top-1);

  cout<<hull.size()<<endl;
  for(int i=0; i<hull.size(); i++)
    cout<<hull[i].x<<" "<<hull[i].y<<endl;

  cout<<endl;

  return 0;
}