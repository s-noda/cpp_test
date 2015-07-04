#include <iostream>

int main(int argc, char** argv){
	int A, B, C, K, S, T;
	std::cin >> A >> B >> C >> K >> S >> T;

	int ret = A*S + B*T ;
	if ( S + T >= K ){
		ret -= (S + T) * C;
	}
	std::cout << ret << std::endl;
}

