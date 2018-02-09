#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SubArray(const vector<double> v, double target) {
  int i = 0, j = 0, sz = INT_MAX;
  double currSum = v[0];
    
  while (i < v.size() && j < v.size()) {
    if (currSum >= target) {
      sz = min(sz, j - i + 1);
      currSum -= v[i++];
    } else
      currSum += v[++j];
        
    if (i == v.size() || j == v.size()) {
      if (currSum >= target)
	sz = min(sz, j - i +1);
      break;
    };
  };
    
  return sz == INT_MAX ? -1 : sz;
};

int main() {
  vector<double> v = {1, 2, 3, 4};
  if (SubArray(v, 1) == 1 && SubArray(v, 2) == 1 && SubArray(v, 3) == 1
      && SubArray(v,10) == 4 && SubArray(v, 5) == 2)
    cout<<"Succeed"<<endl;
  else
    cout<<"Fail"<<endl;
    
  return 0;
}
