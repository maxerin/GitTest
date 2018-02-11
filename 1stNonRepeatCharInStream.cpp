#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

char find1st(const string& s) {
  unordered_map<char, int> fstOffset;
  //use INT_MAX as flag to indicate it is repeated already.
  for (auto i = 0; i < s.size(); ++i) {
    if (fstOffset.find(s[i]) != fstOffset.end())
      fstOffset[s[i]] = INT_MAX;
    else
      fstOffset[s[i]] = i;
  }
    
  int minOffset = INT_MAX;
  char currMinChar = s[0];
  for (auto& x : fstOffset)
    if (minOffset < x.second) {
      minOffset = x.second;
      currMinChar = x.first;
    }
    
  return currMinChar;
};

int main(int argc, const char * argv[]) {
  vector<string> tests = {
    "iostream",
    "egg",
    "a",
    "aa",
    "aabbc" };

  bool ret = true;
  for (auto& x  : tests)
    ret &= find1st(x);
    
  if (ret)
    cout<<"SUCC";
  else
    cout<<"Fail"<<endl;
    
  return 0;
}
