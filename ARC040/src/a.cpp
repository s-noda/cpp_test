#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	int N;
	std::vector<std::string> S;
	int score = 0;

	std::cin >> N;

	S.resize(N);

	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
		for (int j = 0; j < N; j++) {
			switch (S[i][j]) {
			case 'R':
				score++;
				break;
			case 'B':
				score--;
				break;
			}
		}
	}

	if (score > 0) {
		std::cout << "TAKAHASHI" << std::endl;
	} else if (score == 0) {
		std::cout << "DRAW" << std::endl;
	} else {
		std::cout << "AOKI" << std::endl;
	}
}
