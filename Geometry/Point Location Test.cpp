/**
 * Problem Name: Point Location Test
 * Link: https://cses.fi/problemset/task/2189/
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin>>t;

  while(t--) {
    int ax, ay;
    cin>>ax>>ay;

    int bx, by;
    cin>>bx>>by;

    int cx, cy;
    cin>>cx>>cy;

    // Equation of SL connecting p1 and p2: (x-x1)/(y-y1) = (x1-x2)/(y1-y2)
    // The value of the SL when x=cx, y=cy will speak for itself

    long long int val=1ll*(cx-ax)*(ay-by) - 1ll*(ax-bx)*(cy-ay);

    string pos;

    if(val>0) {
      pos = "LEFT";
    } else if(val<0) {
      pos = "RIGHT";
    } else {
      pos = "TOUCH";
    }

    cout<<pos<<endl;
  }

  return 0;
}
