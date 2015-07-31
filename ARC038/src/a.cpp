#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(int argc, char** argv){
  int N;
  std::vector<int> score;
  int ret = 0;

  std::cin >> N;

  score.resize(N);

  for ( int i=0 ; i<N ; i++ ) std::cin >> score[i];

  std::sort(score.begin(), score.end(), std::greater<int>());

  for ( int i=0 ; i<N ; i++ ){
	  if ( i % 2 == 0 ){
		  ret += score[i];
	  }
  }

  std::cout << ret << std::endl;
}
