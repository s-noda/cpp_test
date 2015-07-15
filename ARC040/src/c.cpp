#include <iostream>
#include <string>
#include <vector>

void copy_string_vector(std::vector<std::string> &from,
		std::vector<std::string> &to) {
	to.resize(from.size());
	for (int i = 0; i < from.size(); i++) {
		to[i].assign(from[i]);
	}
}

int main(int argc, char** argv) {
	int N;
	std::vector<std::string> S;

	std::cin >> N;

	S.resize(N);

	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}

	std::vector<std::string> Stop;
	int ret1 = 0;
	copy_string_vector(S, Stop);
	for (int i = 0; i < N; i++) {
		int pos = Stop[i].rfind('.');
		if (pos >= 0) {
			ret1++;
			if (i + 1 < N) {
				for (int j = pos; j < N; j++) {
					Stop[i + 1][j] = 'o';
				}
			}
		} else {
			// nop
		}
	}

	std::vector<std::string> Sbtm;
	int ret2 = 0;
	copy_string_vector(S, Sbtm);
	for (int i = N - 1; i >= 0; i--) {
		int pos = Sbtm[i].find('.');
		// std::cout << Sbtm[i] << std::endl;
		if (pos >= 0) {
			ret2++;
			if (i - 1 >= 0) {
				for (int j = 0; j <= pos; j++) {
					Sbtm[i - 1][j] = 'o';
				}
			}
		} else {
			// nop
		}
	}

	std::cout << (ret1 > ret2 ? ret2 : ret1) << std::endl;
}
