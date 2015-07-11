#include <iostream>

int main(int argc, char** argv){
	int A;
	std::cin >> A;

	int max = -1;
	for ( int i=1; i<=A-1 ; i++ ){
		if ( max < i*(A-i) ){
			max = i*(A-i);
		}
	}
	std::cout << max << std::endl;
}
