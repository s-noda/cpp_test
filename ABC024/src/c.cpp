#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	int N, D, K;
	std::vector<int> L, R, S, T, ret;
	std::vector<std::vector<int> > map;

	std::cin >> N >> D >> K;

	L.resize(D);
	R.resize(D);
	S.resize(K);
	T.resize(K);
	ret.resize(K);
	std::fill(ret.begin(), ret.end(), -1);

	for (int i = 0; i < D; i++) {
		std::cin >> L[i] >> R[i];
	}

	for (int i = 0; i < K; i++) {
		std::cin >> S[i] >> T[i];
	}

	for (int i = 0; i < K; i++) {
		std::vector<int> buf(2);
		buf[0] = S[i];
		buf[1] = S[i];
		map.push_back(buf);
	}

//	std::cout << ":date" << 0 << std::endl;
//	for (int k = 0; k < K; k++) {
//		std::cout << "  -- group " << k << " E (" << map[k][0] << "," << map[k][1] << ")" << std::endl;
//	}

	for (int i = 0; i < D; i++) {

		for (int k = 0; k < K; k++) {

			if (ret[k] >= 0)
				continue;

			if (map[k][0] >= L[i] && map[k][0] <= R[i]) {
				map[k][0] = L[i];
			}
			if (map[k][1] >= L[i] && map[k][1] <= R[i]) {
				map[k][1] = R[i];
			}

			if (map[k][0] <= T[k] && map[k][1] >= T[k]) {
				ret[k] = i;
			}

		}

//		std::cout << ":date" << i << " = (" << L[i] << "," << R[i] << ")" << std::endl;
//		for (int k = 0; k < K; k++) {
//			std::cout << "  -- group" << k << " : " << T[k] << " E (" << map[k][0] << "," << map[k][1] << ")" << std::endl;
//		}
	}

	for (int i = 0; i < ret.size(); i++) {
		std::cout << (1 + ret[i]) << std::endl;
	}
}
