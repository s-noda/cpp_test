#include <iostream>
#include <vector>

int main(int argc, char** argv){
	int R, C, K, N;
	std::vector<std::vector<int> > cr;
	std::vector<int> row_sum, col_sum;
	std::vector<bool> cr_bool;

	std::cin >> R >> C >> K >> N;

	row_sum.resize(R);
	col_sum.resize(C);
	cr.resize(R, std::vector<int>(0));
	cr_bool.resize(C);

	std::fill(row_sum.begin(), row_sum.end(), 0);
	std::fill(col_sum.begin(), col_sum.end(), 0);

	for ( int i=0 ; i<N ; i++ ){
		std::vector<int> c(2);
		std::cin >> c[0] >> c[1];
		c[0]--;
		c[1]--;

		cr[c[0]].push_back(c[1]);

		row_sum[c[0]]++;
		col_sum[c[1]]++;
	}


	int ret = 0;
	for ( int r=0 ; r<R ; r++ ){
		std::fill(cr_bool.begin(), cr_bool.end(), false);
		for ( int i=0; i<cr[r].size() ; i++ ){
			cr_bool[cr[r][i]] = true;
		}
		for ( int c=0; c<C ; c++ ){
			int map = row_sum[r] + col_sum[c];
			if ( cr_bool[c] ) map--;
			if ( map == K ) ret++;
		}
	}

	std::cout << ret << std::endl;
}


//int main(int argc, char** argv){
//	int R, C, K, N;
//	std::vector<std::vector<bool> >sum_map;
//	std::vector<int> row_sum, col_sum;
//
//	std::cin >> R >> C >> K >> N;
//
//	row_sum.resize(R);
//	col_sum.resize(C);
//	sum_map.resize(R, std::vector<bool>(C,false));
//
//	std::fill(row_sum.begin(), row_sum.end(), 0);
//	std::fill(col_sum.begin(), col_sum.end(), 0);
//
//	for ( int i=0 ; i<N ; i++ ){
//		int c1, c2;
//		std::cin >> c1 >> c2;
//		c1--;
//		c2--;
//
//		sum_map[c1][c2] = 1;
//
//		row_sum[c1]++;
//		col_sum[c2]++;
//	}
//
//
//	int ret = 0;
//	for ( int r=0 ; r<R ; r++ ){
//		for ( int c=0; c<C ; c++ ){
//			int map = row_sum[r] + col_sum[c];
//			if ( sum_map[r][c] ) map--;
//			if ( map == K ) ret++;
//		}
//	}
//
//	std::cout << ret << std::endl;
//}
