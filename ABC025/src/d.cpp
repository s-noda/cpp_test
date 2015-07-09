#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//#include <time.h>

bool check_pos_org(std::vector<std::vector<int> > &x, int i, int j) {

	if (!(i >= 0 && i < x.size() && j >= 0 && j < x[0].size())) {
		return true;
	}

	if ((i - 1 >= 0) && (i + 1 < x.size())) {
		if (x[i - 1][j] != 0 && x[i][j] != 0 && x[i + 1][j] != 0) {
			if (((x[i - 1][j] < x[i][j]) && (x[i][j] < x[i + 1][j]))
					|| ((x[i - 1][j] > x[i][j]) && (x[i][j] > x[i + 1][j]))) {
				return false;
			}
		}
	}

	if ((j - 1 >= 0) && (j + 1 < x[0].size())) {
		if (x[i][j - 1] != 0 && x[i][j] != 0 && x[i][j + 1] != 0) {
			if (((x[i][j - 1] < x[i][j]) && (x[i][j] < x[i][j + 1]))
					|| ((x[i][j - 1] > x[i][j]) && (x[i][j] > x[i][j + 1]))) {
				return false;
			}
		}
	}

	return true;
}

bool check_pos(std::vector<std::vector<int> > &x, int i, int j) {
	for (int di = -1; di <= 1; di++) {
		if (!check_pos_org(x, i + di, j))
			return false;
	}

	for (int dj = -1; dj <= 1; dj++) {
		if (!check_pos_org(x, i, j + dj))
			return false;
	}

	return true;
}

std::vector<int> gather_ok_val(std::vector<int> &cand,
		std::vector<std::vector<int> > &x, int i, int j) {
	std::vector<int> ret;

	for (int p = 0; p < cand.size(); p++) {
		x[i][j] = cand[p];
		if (check_pos(x, i, j)) {
			ret.push_back(cand[p]);
		}
		x[i][j] = 0;
	}

	return ret;
}

int check_all_cands(std::vector<std::vector<int> > &zero,
		std::vector<std::vector<int> > &cands,
		std::vector<std::vector<int> > &x, std::vector<int> &blacklist, int z
		) {
	int ret = 0;

	if (z >= zero.size()) {
		return 1;
	}
	int i = zero[z][0];
	int j = zero[z][1];

//	std::cout << ":dump blacklist ";
//	for ( int i=0 ; i<blacklist.size(); i++ ){
//		std::cout << blacklist[i] << " ";
//	}
//	std::cout << std::endl;

	std::vector<int> cand;
	for (int c = 0; c < cands[z].size(); c++) {
		std::vector<int>::iterator it = std::find(blacklist.begin(),
				blacklist.end(), cands[z][c]);
		if (it == blacklist.end()) {
			cand.push_back(cands[z][c]);
		}
	}
	cand = gather_ok_val(cand, x, i, j);

//	std::cout << ":dump candidates ";
//		for ( int i=0 ; i<cand.size(); i++ ){
//			std::cout << cand[i] << " ";
//		}
//		std::cout << std::endl;

	if (cand.size() == 0) {
		return 0;
	} else {
		for (int c = 0; c < cand.size(); c++) {
			x[i][j] = cand[c];
			blacklist.push_back(x[i][j]);
			ret += check_all_cands(zero, cands, x, blacklist, z + 1);
			blacklist.pop_back();
			x[i][j] = 0;
		}
		//std::cout << ret << std::endl;
		return ret;
	}
}

int main(int argc, char** argv) {

//	time_t start_time, end_time;
//	double sec_time;
//	time( &start_time );

	int ret = 0;
	std::vector<std::vector<int> > x(5, std::vector<int>(5));
	std::vector<std::vector<int> > zero;
	std::vector<std::vector<int> > cands;
	std::vector<int> cand(25);
	for (int i = 0; i < cand.size(); i++)
		cand[i] = i + 1;

	//std::cout << "initialize..." << std::endl;

	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x[0].size(); j++) {
			std::cin >> x[i][j];

			if (x[i][j] == 0) {
				std::vector<int> zpos(2);
				zpos[0] = i;
				zpos[1] = j;
				zero.push_back(zpos);
			} else {
				std::vector<int>::iterator pos = std::find(cand.begin(),
						cand.end(), x[i][j]);
				if (pos != cand.end())
					cand.erase(pos);
			}
		}
	}

	//std::cout << "done" << std::endl;

	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x[0].size(); j++) {
			if (!check_pos_org(x, i, j)) {
				std::cout << "0" << std::endl;
				return 0;
			}
		}
	}

	if (zero.size() == 0) {
		std::cout << "1" << std::endl;
		return 0;
	}

	for (int i = 0; i < zero.size(); i++) {
		// std::cout << zero[i][0] << "," << zero[i][1] << std::endl;
		cands.push_back(gather_ok_val(cand, x, zero[i][0], zero[i][1]));
	}

	std::vector<int> bl;
	ret = check_all_cands(zero, cands, x, bl, 0) % 1000000007;

	std::cout << ret << std::endl;

//	time( &end_time );
//	sec_time = difftime( end_time, start_time );
//	std::cout << "time:" << sec_time << std::endl;

	return 0;
}
