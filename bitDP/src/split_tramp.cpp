#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

template<typename T> void dump_vector(std::vector<T> &in) {
	for (int i = 0; i < in.size(); i++) {
		std::cout << in[i] << ",";
	}
}

// check all states
int check_dp_tramp_devisions(std::vector<int> &tramp){

	int sum = 0;
	for ( int i=0 ; i<tramp.size() ; i++ ) sum += tramp[i];

	if ( sum % 2 == 1 ) return 0;

	std::vector<std::vector<int> > memo(tramp.size(), std::vector<int>(sum+1, 0));

	memo[0][0] += 1;
	memo[0][tramp[0]] += 1;
	// std::cout << "  >> " ; dump_vector(memo[0]); std::cout << ")" << std::endl;

	for ( int i=1; i<tramp.size(); i++ ){ // O(N*N*N)
		for ( int j=0 ; j<memo[0].size() ; j++ ){
			if ( j+tramp[i] < memo[0].size() ){
				memo[i][j + tramp[i]] += memo[i-1][j];
			}
			memo[i][j] += memo[i-1][j];
		}
		// std::cout << "  >> " ; dump_vector(memo[i]); std::cout << ")" << std::endl;
	}

	return memo[tramp.size()-1][sum/2];
}

// check all states
int check_all_tramp_devisions(std::vector<int> &tramp, std::vector<bool> &split,
		int depth) {
	if (depth >= tramp.size()) { // O(N * 2^N)
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < tramp.size(); i++) {
			if (split[i]) {
				sum1 += tramp[i];
			} else {
				sum2 += tramp[i];
			}
		}
//		if (sum1 == sum2) {
//			std::cout << "  (";
//			dump_vector<bool>(split);
//			std::cout << ")" << std::endl;
//		}
		return (sum1 == sum2) ? 1 : 0;
	} else {
		int ret = 0;
		for (int i = 0; i < 2; i++) { // true or false
			split[depth] = (i == 0) ? true : false;
			ret += check_all_tramp_devisions(tramp, split, depth + 1);
		}
		return ret;
	}
}

int main(int argc, char** argv) {
	std::vector<int> tramp(21);
	std::vector<bool> split(tramp.size());

	int sum=0;
	std::srand(time(0));
	for (int i = 0; i < tramp.size(); i++) {
		tramp[i] = std::rand() % tramp.size();
		sum += tramp[i];
	}
	if ( sum % 2 == 1 ) tramp[0]++;
	std::cout << "$ input (";
	dump_vector<int>(tramp);
	std::cout << ")" << std::endl;

	// search all devisions which separate tramps into 2 groups and in which the both groups have the same summations.
	int start = time(0);
	std::cout << " -- check_all_tramp: " << std::endl ;
	std::cout << "   ans: " << check_all_tramp_devisions(tramp, split, 0) ;
	std::cout << " (time: " << (time(0) - start) << ")" << std::endl;

	start = time(0);
	std::cout << " -- check_dp_tramp: " << std::endl ;
	std::cout << "   ans: " << check_dp_tramp_devisions(tramp) ;
	std::cout << " (time: " << (time(0) - start) << ")" << std::endl;
}
