#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> findTopAddr(const vector<string>& doc) {
  using Addr = unordered_map<string, double>;
  Addr dir;
  string top;
  for (auto& line : doc) {
    string addr;
    istringstream s(line);
    s >> addr;
    //auto offset = line.find_first_of(' ');
    //addr = line.substr(0, offset);
    if (dir.find(addr) != dir.end())
      dir[addr]++;
    else
      dir[addr] = 1;
  };
    
  double curMax = 0;
  vector<string> curTops;
  for (auto& pair : dir) {
    if (pair.second > curMax) {
      curMax = pair.second;
      curTops.clear();
      curTops.push_back(pair.first);
    } else if (pair.second == curMax)
      curTops.push_back(pair.first);
  };
    
  return curTops;
};

int main(int argc, const char * argv[]) {
  // insert code here...
  vector<string> doc = {
    "10.2.2.3 push request",
    "10.2.2.1 push request",
    "10.2.2.1 push request",
    "10.2.2.3 push request",
    "10.2.2.4 push request",
  };
    
  vector<string> top = findTopAddr(doc);
  for (auto& x : top)
    cout<<x<<endl;
    
  return 0;
}
