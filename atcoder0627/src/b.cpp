#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//template<typename T>
//class _log{
//public:
//	int output(std::vector<std::string> tag, std::vector<T> val){
//		return 0;
//	}
//};

int main(int argc, char** argv){
	int N, A, B;
	int east = 0;
	std::string dir;
	int dist=0;

	std::cin >> N >> A >> B;

	//std::cout << "N=" << N << ", A=" << A << ", B=" << B << std::endl;

	for ( int i=0 ; i<N ; i++ ){
		std::cin >> dir >> dist;
		//std::cout << "dir=" << dir << ", dist=" << dist << std::endl;
		if ( dist < A ) dist = A;
		else if ( dist > B ) dist = B;
		if ( dir == "East" ) east += dist;
		else east -= dist;
	}

	if ( east > 0 ) std::cout << "East " << east << std::endl;
	else if ( east < 0 ) std::cout << "West " << (-1 * east) << std::endl;
	else std::cout << "0" << std::endl;
}
