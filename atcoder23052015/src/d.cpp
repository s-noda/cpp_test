#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char** argv) {
	int A, B, C;
	int size = std::ldexp(10,8);
	std::vector<std::vector<int> > map(size, std::vector<int>(size));

	std::cin >> A >> B >> C;

	for ( int i=0; i<map.size() ; i++ ){
		map[i][0] = 1;
	}

	for ( int j=0; j<map[0].size(); j++ ){
		map[0][j] = 1;
	}

//	std::cout << size;
//	std::cout << "map = " << map.size() << "x" << map[0].size() << std::endl;


	for ( int i=1; i<map.size() ; i++ ){
		for ( int j=1; j<map[i].size(); j++ ){
			map[i][j] = ((map[i-1][j] + map[i][j-1]) % 1000000007);
			//std::cout << map[i][j] << " ";
			if ( map[i][j-1] == B && map[i-1][j-1] == A && map[i-1][j] == C ){
				std::cout << (j-1) << " " << (i-1) << std::endl;
				return 0;
			}
		}
		//std::cout << std::endl;
	}

	return -1;
}
