#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(int argc, char** argv){
  int N, P;
  std::vector<int> cost;
  std::vector<int> pay;
  std::vector<std::vector<int> > hist;
  std::vector<std::vector<bool> > ok;

  std::cin >> N >> P;

  cost.resize(N);
  pay.resize(N);
  hist.resize(N, std::vector<int>(P > 100 ? P+1 : 101, -1));
  ok.resize(N, std::vector<bool>(P > 100 ? P+1 : 101, true));

  for ( int i=0 ; i<N ; i++ ) std::cin >> cost[i] >> pay[i];

  hist[0][0] = 0;
  hist[0][cost[0]] = pay[0];

  for ( int i=1; i<N ; i++ ){
	  for ( int j=0 ; j<hist[i].size(); j++ ){
		  if ( hist[i-1][j] > 0 ){
			  hist[i][j] = hist[i][j] > hist[i-1][j] ? hist[i][j] : hist[i-1][j];
			  if ( ok[i-1][j] ){
				  hist[i][j+cost[i]] = hist[i][j+cost[i]] > hist[i-1][j] + pay[i] ? hist[i][j] : hist[i-1][j] + pay[i];
				  if ( j + cost[i] > P ){
					  ok[i][j+cost[i]] = false;
				  }
			  }
		  }
	  }
  }

  std::cout << *std::max_element(hist[N-1].begin(), hist[N-1].end()) << std::endl;
}
