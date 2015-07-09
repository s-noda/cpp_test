#include <iostream>

int main(int argc, char** argv){
	int X;
	int ret;
	std::cin >> X;

	ret = (X / 10) + (X % 10);

	std::cout << ret << std::endl;
}
