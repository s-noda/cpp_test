#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class vector_comp {
public:
	int index;
	vector_comp(int index) {
		this->index = index;
	}

	bool operator()(const std::vector<int> &a,
			const std::vector<int> &b) const {
		return (a[this->index] > b[this->index]);
	}
};

std::vector<int> calc_score(std::vector<std::vector<char> > &map,
		std::vector<std::vector<int> > &b, std::vector<std::vector<int> > &c) {
	std::vector<int> ret(2, 0);

	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			if (map[i][j] == map[i + 1][j]) {
				ret[0] += b[i][j];
			} else {
				ret[1] += b[i][j];
			}
		}
	}

	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c[0].size(); j++) {
			if (map[i][j] == map[i][j + 1]) {
				ret[0] += c[i][j];
			} else {
				ret[1] += c[i][j];
			}
		}
	}

	return ret;
}

std::vector<int> ox_simulation(char player,
		std::vector<std::vector<char> > &map, std::vector<std::vector<int> > &b,
		std::vector<std::vector<int> > &c) {
	std::vector<std::vector<int> > score;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			if (!(map[i][j] == 'o' || map[i][j] == 'x')) {
				map[i][j] = player;
				score.push_back(
						ox_simulation(player == 'o' ? 'x' : 'o', map, b, c));
				map[i][j] = ' ';
			}
		}
	}
	if (score.size() == 0) {
		return calc_score(map, b, c);
	} else {
		return *std::max_element(score.begin(), score.end(),
				vector_comp(player == 'o' ? 1 : 0));
	}
}

int main(int argc, char** argv) {
	std::vector<std::vector<int> > b(2, std::vector<int>(3));
	std::vector<std::vector<int> > c(3, std::vector<int>(2));

	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			std::cin >> b[i][j];
		}
	}

	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c[0].size(); j++) {
			std::cin >> c[i][j];
		}
	}

	char player = 'o';
	std::vector<std::vector<char> > map(3, std::vector<char>(3));
	std::vector<int> ret = ox_simulation(player, map, b, c);
	std::cout << ret[0] << std::endl;
	std::cout << ret[1] << std::endl;

	return 0;
}
