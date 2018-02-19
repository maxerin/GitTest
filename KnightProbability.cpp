#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <numeric>
#include <unordered_map>

using namespace std;

/* 
 naive solution based on recursive; the counts serves as the analysis to see 
 how poor  the recursive algorithm is
 
unordered_map<string, int> counts;
double probability(int x, int y, int n) {
    string key = to_string(x) + "," + to_string(y) + "," + to_string(n);
    if (counts.find(key) != counts.end())
        counts[key]++;
    else
        counts[key] = 1;
    
    double onBoard = x >= 0 && x <= 7 && y >= 0 && y <= 7;
    if (!onBoard) {
        return 0;
    }
    
    //still on board, but no more move
    if (n == 0)
        return 1;
    
    //still on board with n move
    int move[8][2] = {
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
    };
    
    double tot[8];
    for (int i = 0 ; i < 8; ++i)
        tot[i] = probability(x + move[i][0], y + move[i][1], n - 1);
    
    double sum = 0;
    for (auto i : tot)
        sum += i;
    
    return sum / 8;
};
*/

//this is the solution based on dynamic programming.
const int N = 8;
const int moves[N][2] = {
  {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
  {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
};

double onBoard(int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < N;
};

  double prob(int x, int y, int steps) {
    double pb[N][N][steps];
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) {
	pb[i][j][0] = 1;
      };
    //the key to loop from step 0 until steps
    for (int s = 1; s <= steps; ++s)
      for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j) {
	  double newP = 0;
	  for (auto& move : moves) {
	    auto nx = i + move[0], ny = j + move[1];
	    if (onBoard(nx, ny))
	      newP += pb[nx][ny][s-1] / 8.0;
	  }
                
	  pb[i][j][s] = newP;
	};
    
    return pb[x][y][steps];
  }

  int main(int argc, const char * argv[]) {
    double sum = prob(0, 0, 1);
    /* test cases
     (1,1,3) -> 0.289062
     (1,3,20) -> 0.00332377
     (0, 0, 1 ) -> 0.25
    */
    
    std::cout << sum <<endl;
    
    return 0;
  }
