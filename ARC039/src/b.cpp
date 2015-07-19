#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int comb(int N, int k){
	if ( k == 1 ) return N;
	else return N * comb(N-1,k-1) / k;
}

int comb2(int d, int k, std::vector<bool> &map){
	if ( k == 1 ){
		int ret = 0;
		for ( int i=d ; i<map.size() ; i++ ){
			if ( map[i] ){

			} else {
				ret = ( ret + 1 ) % 1000000007 ;
			}
		}
		return ret;
	} else {
		int ret = 0;
		for ( int i=d ; i<map.size() ; i++ ){
			if ( map[i] ){
			} else {
				map[i] = true;
				ret = ( ret + comb2(i+1,k-1,map) ) % 1000000007 ;
				map[i] = false;
			}
		}
		return ret;
	}
}

int main(int argc, char** argv){
  int N, K;
  int split;

  std::cin >> N >> K;

  if ( K % N == 0 ){
	  std::cout << 1 << std::endl;
	  return 0;
  }

  split = K % N;

  std::vector<bool> map;
  map.resize(N, false);
  std::cout << (comb2(0, split,map) %  1000000007) << std::endl;
}
