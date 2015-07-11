#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class tree {
public:
	int id;
	int parent;
	int pay;
	std::vector<tree*> buka;

	int calc_pay(){
		if ( this->buka.size() == 0 ){
			this->pay = 1;
		} else {
			int max = std::numeric_limits<int>::min();
			int min = std::numeric_limits<int>::max();
			for ( int i=0 ; i<this->buka.size() ; i++ ){
				int ret = this->buka[i]->calc_pay();
				if ( ret > max ) max = ret ;
				if ( ret < min ) min = ret;
			}
			this->pay = max + min +1;
		}
		return this->pay;
	}

};

int main(int argc, char** argv){
	int N;
	std::vector<tree> member;

	std::cin >> N;

	member.resize(N+2);
	member[1].id = 1;
	member[1].parent = 0;

	for ( int i=2 ; i<=N ; i++ ){
		int oya ;
		std::cin >> oya;
		// std::cout << i << "->" << oya << std::endl;
		member[i].id = i;
		member[i].parent = oya;
		member[member[i].parent].buka.push_back(&member[i]);
	}

	std::cout << member[1].calc_pay() << std::endl;
}
