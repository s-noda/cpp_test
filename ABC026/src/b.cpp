#include <iostream>
#include <vector>
#include <algorithm>

#define PI 3.14159265258979

int main(int argc, char** argv) {
	int N;
	std::vector<int> R;

	std::cin >> N;
	R.resize(N);

	for (int i = 0; i < N; i++) {
		std::cin >> R[i];
	}

	std::sort(R.begin(), R.end(), std::greater<int>());

	double area = 0;

	for (int i = 0; i < N; i++) {
		// std::cout << R[i] << std::endl;
		if (i % 2 == 0) {
			if ( i != N-1 ){
				area -= R[i + 1] * R[i + 1] * PI;
			}
			area += R[i] * R[i] * PI;
		}
	}
	std::cout.precision(100);
	std::cout << area << std::endl;
}
