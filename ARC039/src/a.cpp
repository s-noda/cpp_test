#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(int argc, char** argv) {
	int A, B;
	std::vector<int> A_, B_;
	std::vector<int> ret;

	std::cin >> A >> B;

	ret.resize(6);
	A_.resize(3);
	B_.resize(3);

	A_[2] = A % 10;
	A_[1] = A % 100 - A_[2];
	A_[0] = A % 1000 - A_[1] - A_[2];

	B_[2] = B % 10;
	B_[1] = B % 100 - B_[2];
	B_[0] = B % 1000 - B_[1] - B_[2];

//	std::cout << "A = ";
//	for (int i = 0; i < A_.size(); i++)
//		std::cout << A_[i] << ". ";
//	std::cout << std::endl;
//
//	std::cout << "B = ";
//	for (int i = 0; i < A_.size(); i++)
//		std::cout << B_[i] << ". ";
//	std::cout << std::endl;

	ret[0] = (900 + A_[1] + A_[2]) - B;
	ret[1] = (A_[0] + 90 + A_[2]) - B;
	ret[2] = (A_[0] + A_[1] + 9) - B;
	ret[3] = A - (100 + B_[1] + B_[2]);
	ret[4] = A - (B_[0] + 0 + B_[2]);
	ret[5] = A - (B_[0] + B_[1] + 0);

	std::cout << (*std::max_element(ret.begin(), ret.end())) << std::endl;
}
