#include <iostream>
#include <string>

int main(int argc, char** argv){
	int N, R;
	std::string S;
	int ret = 0;
	int pos = 0;
	int last_dot_pos = -1;

	std::cin >> N >> R >> S;

	for ( int i=N-1 ; i>=0 ; i-- ){
		if ( S[i] == '.' ){
			last_dot_pos = i;
			break;
		}
	}

	if ( last_dot_pos < 0 ){
		std::cout << "0" << std::endl;
		return 0;
	}

	while ( pos < N ) {
		// std::cout << S << " at " << pos << std::endl;
		if (last_dot_pos - pos < R ){
			ret++ ;
			break;
		} else if (S[pos] == '.'){
			for ( int j=0 ; j<R ; j++ ){
				S[pos+j] = 'o';
			}
		} else {
			pos++;
		}
		ret++;
	}

	std::cout << ret << std::endl;
	return 0;
}
