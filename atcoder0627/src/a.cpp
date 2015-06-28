#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char** argv){
	std::string dict;
	int N;
	std::cin >> dict;
	std::cin >> N;

	// std::cout << "dict=" << dict << ", N=" << N << std::endl;

	// sort dict
	std::sort(dict.begin(), dict.end(), std::less<char>());

	int k=N;
	std::string buf = "ab";
	for ( int i=0 ; i<dict.length() ; i++ ){
		buf.at(0) = dict.at(i);
		for ( int j=0; j<dict.length(); j++ ){
			buf.at(1) = dict.at(j);
			// std::cout << buf << "(" << k << ")" << std::endl;
			if ( --k <= 0 ) goto OUT;
		}
	}
	OUT:
	std::cout << buf << std::endl;
}
