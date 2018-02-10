#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

double minDistance(const string& doc, const string& s1, const string& s2) {
  vector<string> tokens;
  boost::split(tokens, doc, boost::is_any_of(" "), boost::token_compress_on);
    
  double p1 = 0, p2 = 0; //positions of s1, s2,
  double curSz = 0, minDiff = doc.size();
  for (auto& str : tokens) {
    if (str == s1)
      p1 = curSz + s1.size() / (double)2;
    else if (str == s2)
      p2 = curSz + s2.size() / (double)2;
        
    if (fabs(p2 - p1) < minDiff && p1 > 0 && p2 > 0)
      minDiff = fabs(p2 - p1);
        
    curSz += str.size();
  };
    
  return minDiff;
};

int main(int argc, const char * argv[]) {
  string doc = "This is a test";
  string s1 = "is", s2 = "a";
  double dis = minDistance(doc, s1, s2);
    
  cout<<dis<<endl;
  return 0;
}
