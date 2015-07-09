#include <iostream>
#include <vector>
#include <algorithm>

class vector_comp {
public:
	bool operator()(std::vector<int> a, std::vector<int> b){
		return a[0] > b[0];
	}
};

int main(int argc, char** argv){
	int N;
	std::vector<std::vector<int> > HS;
	vector_comp vc;

	int ret = 0;

	std::cin >> N;
	HS.resize(N, std::vector<int>(2));

	for ( int i=0 ; i<N ; i++ ){
		std::cin >> HS[i][0] >> HS[i][1];
	}

	// greedy search
	for ( int i=0 ; i<N ; i++ ){
		std::vector<std::vector<int> >::iterator it = std::min_element(HS.begin(), HS.end(), vc);

		if ( ret < (*it)[0] ){
			ret = (*it)[0];
		}

		HS.erase(it);

		for ( int j=0 ; j<HS.size() ; j++ ){
			HS[j][0] += HS[j][1];
		}
	}

	std::cout << ret << std::endl;
}
