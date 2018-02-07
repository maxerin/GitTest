#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/* Test cases
 2 2
 3 1 5 4
 5 1 2 8 9 3
 0 1
 1 3
*/

int main() {
  int n, q;
  cin >> n >> q;
    
  int** v = new int*[n];
    
  int sz = 0;
  for (int i = 0; i < n; ++i) {
    cin >> sz;
    v[i] = new int[sz];
    for (int j = 0; j < sz; ++j) {
      cin >> v[i][j];
    };
  };
    
  int* re = new int[q];
  for (int i = 0; i < q; ++i) {
    int first, second;
    cin >> first >> second;
    re[i] = v[first][second];
  };
    
  for (int i = 0; i < q; i++)
    cout<<re[i]<<endl;
    
  return 0;
}
