#include <iostream>

int main(int argc, char** argv){
	int N, T, Ti_1=-1;
	int ret = 0;
	std::cin >> N >> T;

	for ( int i=0; i<N ; i++ ){
		int Ti;
		std::cin >> Ti;
		if ( Ti_1 < 0 ){
			Ti_1 = Ti;
		} else {
			if ( Ti - Ti_1 > T ){
				ret += T;
			} else {
				ret += Ti - Ti_1;
			}
			Ti_1 = Ti;
		}
	}
	ret += T;

	std::cout << ret << std::endl;
}

