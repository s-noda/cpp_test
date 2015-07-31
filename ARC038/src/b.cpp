#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool check_map(int i, int j, std::vector<std::string> &map){
	if ( i>=0 && j>=0 ){
		map[i][j] = '#';
	}
	return ( i==0 && j==0 );
}

int main(int argc, char** argv){
  int H, W;
  std::vector<std::string> map;

  std::cin >> H >> W;

  map.resize(H+1, std::string(W+1, '#'));
  std::string buf;
  for ( int i=0; i<H ; i++ ){
	  std::cin >> buf;
	  for ( int j=0 ; j<W ; j++ ){
		  map[i][j] = buf[j];
	  }
	  //std::cout << map[i] << std::endl;
  }

  int cnt=0;
  while ( true ){
	  for ( int i=1 ; i<H+1 ; i++ ){
		  for ( int j=1 ; j<W+1 ; j++ ){
			  if ( map[i][j] == '#' && map[i-1][j] == '#' && map[i][j-1] == '#' && map[i-1][j-1] != '#'){
				  if ( check_map(i-2, j-2, map) ||  check_map(i-2, j-1, map) ||  check_map(i-1, j-2, map) || check_map(i-1, j-1, map) ){
					  goto RET;
				  }
			  }
		  }
	  }
//	  for ( int i=0 ; i<map.size() ; i++ ) std::cout << map[i] << std::endl;
//	  std::cout << std::endl;

	  cnt++;
  }
  RET:
  //if ( cnt % 2 == 1 ){
	  if ( map[1][0] != '#' || map[0][1] != '#'|| map[1][1] != '#'){
		  std::cout << "First" << std::endl;
	  } else {
		  std::cout << "Second" << std::endl;
	  }
//  }  else {
//	  std::cout << "First" << std::endl;
//  }
}
