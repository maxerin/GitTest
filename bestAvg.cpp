#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

double bestAvg(const vector<vector<string>> scores) {
  unordered_map<string, pair<double,double>> currAvg;
  for (auto& x : scores) {
    auto name = x[0];
    double score = stod(x[1]);
    if (currAvg.find(name) == currAvg.end())
      currAvg[name]= make_pair(score,1);
    else {
      currAvg[name].first += score;
      currAvg[name].second += 1;
    };
  };
    
  double bestAvg = 0;
  for (auto& x : currAvg) {
    auto currAvg = x.second.first / x.second.second;
    if (currAvg > bestAvg)
      bestAvg = currAvg;
  }
    
  return bestAvg;
};

int main(int argc, const char * argv[]) {
  vector<vector<string>> scores = {
    {"Foo", "15"},
    {"Foo", "20"},
    {"Bar", "20"},
    {"Bar", "17"} };
    
  cout<<"Best Avg = " << bestAvg(scores) << endl;
    
  return 0;
}
