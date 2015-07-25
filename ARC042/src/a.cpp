#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(int argc, char** argv) {
	int N, M;
	std::vector<int> a, b;

	std::cin >> N >> M;

	a.resize(N + 1);
	b.resize(M);
	for (int i = 0; i < a.size(); i++) {
		a[i] = i;
	}

	for (int i = 0; i < M; i++) {
		std::cin >> b[i];
	}

	for (int i = b.size() - 1; i >= 0; i--) {
		if (a[b[i]] > 0) {
			std::cout << b[i] << std::endl;
			a[b[i]] = -1;
		}
	}
	for (int i = 1; i < a.size(); i++) {
		if (a[i] > 0) {
			std::cout << a[i] << std::endl;
		}
	}
}
