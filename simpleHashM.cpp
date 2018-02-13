/*
this map needs to expand automtically
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <list>

using namespace std;

template<typename K, typename V>
class SimpleHashMap {
public:
  SimpleHashMap(unsigned bucketSize) : dict_(bucketSize) {
    cout<<"Capacity = "<<dict_.capacity()<<endl;
  };
    
  ~SimpleHashMap() {
  };
    
  V& operator[](const K& key) {
        
    if (dict_.size() * bucketRatio  > dict_.currSize_) {
      resize();
    }
        
    auto hashFunc = hash<K>{};
    auto offset = hashFunc(key) % dict_.size();
    auto& data = dict_[offset];
    for (auto& ele : data) {
      if (ele.first == key)
	return ele.second;
    }
        
    data.push_back(make_pair(key, V{}));
    return data.back().second;
  };

private:
  void resize() {
    auto tmp = dict_;
    dict_.clear();
    dict_.reserve(tmp.size() * 2);
        
  }
  const static int bucketRatio = 2;
  vector<list<pair<K,V>>> dict_;
  int currSize_;
};

int main(int argc, const char * argv[]) {
  SimpleHashMap<string, int> test(100);
     
  test["abc"] = 1;
     
  cout<<test["abc"]<<endl;
     
  if (test["abc"] == 1)
    cout << "Succ"<<endl;

  return 0;
}
