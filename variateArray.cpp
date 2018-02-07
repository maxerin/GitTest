include <cmath>
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
    
  vector<vector<int>> v(n);
  for (auto i = v.begin(); i != v.end(); ++i) {
    int m;
    cin >> m;
    i->reserve(m);
    for (int j = 0; j < m; ++j) {
      int temp;
      cin >> temp;
      i->push_back(temp);
    };
  };
    
  vector<pair<int, int>> queries(q);
  for (auto& i : queries)
    cin >> i.first >> i.second;
    
  for (auto& i : queries) {
    cout<<v[i.first][i.second]<<endl;
  }

  return 0;
}
