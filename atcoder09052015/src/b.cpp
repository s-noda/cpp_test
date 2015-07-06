#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	int N;
	std::string S;
	int ret = -1;

	std::cin >> N >> S;

	if (N % 2 != 1) {
	} else {
		if (S[N / 2] == 'b') {
			ret = N/2;
			for (int i = 1; i <= N / 2; i++) {
				if (i % 3 == 0) {
					if (!(S[N / 2 - i] == 'b' && S[N / 2 + i] == 'b')) {
						ret = -1;
						break;
					}
				} else if (i % 3 == 1) {
					if (!(S[N / 2 - i] == 'a' && S[N / 2 + i] == 'c')) {
						ret = -1;
						break;
					}
				} else if (i % 3 == 2) {
					if (!(S[N / 2 - i] == 'c' && S[N / 2 + i] == 'a')) {
						ret = -1;
						break;
					}
				}
			}
		}

	}

	std::cout << ret << std::endl;
}
