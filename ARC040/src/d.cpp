#include <iostream>
#include <string>
#include <vector>
#include <set>

class stick_graph {
public:
	int x, y;
	std::vector<stick_graph*> neighbor;
};

bool update_stick_graph(std::vector<std::vector<stick_graph> > &map,
		std::vector<std::string> &S) {

	std::set<stick_graph*> net;

	for (int i = 0; i < S.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < S[i].size(); j++) {
			map[i][j].neighbor.clear();
			if (S[i][j] == '.') {
				if (cnt % 2 == 0) {
					if (j + 1 >= S[i].size() || S[i][j + 1] != '.') {
						return false;
					}
					map[i][j].neighbor.push_back(&map[i][j + 1]);
					map[i][j + 1].neighbor.push_back(&map[i][j]);
					net.insert(&map[i][j]);
					net.insert(&map[i][j + 1]);
				}
				cnt++;
			}
		}
	}

	for (int j = 0; j < S[0].size(); j++) {
		int cnt = 0;
		for (int i = 0; i < S.size(); i++) {
			if (S[i][j] == '.') {
				if (cnt % 2 == 0) {
					if (i + 1 >= S.size() || S[i + 1][j] != '.') {
						return false;
					}
					map[i][j].neighbor.push_back(&map[i + 1][j]);
					map[i + 1][j].neighbor.push_back(&map[i][j]);
					net.insert(&map[i][j]);
					net.insert(&map[i + 1][j]);
				}
				cnt++;
			}
		}
	}

	int end_c = 0;
	for (std::set<stick_graph*>::iterator it = net.begin(); it != net.end();
			it++) {
		if ((*it)->neighbor.size() == 2) {
			end_c++;
		}
	}

	if (end_c == 2) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char** argv) {
	int N;
	std::vector<std::string> S;
	std::vector<std::vector<stick_graph> > map;
	std::vector<int> row_dot_c, col_dot_c;

	std::cin >> N;
	S.resize(N);
	map.resize(N, std::vector<stick_graph>(N));
	row_dot_c.resize(N,0);
	col_dot_c.resize(N,0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ( S[i][j] == '.' ){
				row_dot_c[i]++;
				col_dot_c[j]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].neighbor.clear();
		}
	}

	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ( S[i][j] == '.' && row_dot_c[i] % 2 == 1 && col_dot_c[j] % 2 == 1){
				S[i][j] = '#';
				if ( update_stick_graph(map, S) ){
					std::cout << "POSSIBLE" << std::endl;
					return 0;
				}
				S[i][j] = '.';
			}
		}
	}

	std::cout << "IMPOSSIBLE" << std::endl;
	return 0;
}
