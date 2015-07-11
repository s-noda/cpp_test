#include <iostream>
#include <math.h>

double calc_diff(double A, double B, double C, double D, double x) {
	double f = A * x + B * sin(C * x) - D;
	return f;
}

bool check_range(double min, double max, double A, double B, double C,
		double D) {
	double d1 = calc_diff(A, B, C, D, min);
	double d2 = calc_diff(A, B, C, D, max);
	//
	int n = (int)(C*max/M_PI - 0.5);
	if ( min*C > (n+0.5)*M_PI && d1*d2>0){
		return false;
	}
	return true;
}

double sep_search(double min, double max, double A, double B, double C,
		double D) {
	double x = (max + min) / 2;
	double dif = calc_diff(A, B, C, D, x);
	if ( dif > -1e-6 && dif < 1e-6 ) return x;
	while (true) {
		double mid = (max + min) / 2;
		double x1 = (min + mid) / 2;
		double x2 = (max + mid) / 2;
		double d1 = calc_diff(A, B, C, D, x1);
		double d2 = calc_diff(A, B, C, D, x2);
		//
		if ( !check_range(min,max,A,B,C,D) ) break;
		//
		if (d1 * d1 < d2 * d2) {
			max = mid;
		} else {
			min = mid;
		}
		x = (max + min) / 2;
		dif = calc_diff(A, B, C, D, x);
		//
		if ( dif > -1e-6 && dif < 1e-6 ){
			//std::cout << "f(" << x << ") = " << dif << std::endl;
			return x;
		}
	}
	return -1;
}

int main(int argc, char** argv) {
	int A_, B_, C_;
	double A, B, C, D;

	std::cin >> A_ >> B_ >> C_;

	A = 1.0 * A_;
	B = 1.0 * B_;
	C = M_PI * C_;
	D = 100.0;

	double min = (100.0 - B) / A;
	double max = (100.0 + B) / A;
	if (max < min) {
		double swap = max;
		max = min;
		min = swap;
	}
	if (min < 0)
		min = 0;
	if (max < 0)
		max = 0;

	double ret;
	int n = (int)(C*min/M_PI - 0.5);
	double min2 = min, max2;
	n++ ;
	while ( min < max ){
		double max2 = (n+0.5)*M_PI/C;
		//std::cout << "search t E (" << min2 << ", " << max2 << ")" << std::endl;
		ret = sep_search(min2, max2,A,B,C,D);
		if ( ret >= 0 ) break;
		min2 = max2;
		n++;
	}

	//double ret1 = sep_search(min,(min+max)/2,A,B,C,D);
	//double ret2 = sep_search((min+max)/2, max,A,B,C,D);
	//double ret = ret1 >= 0 ? ret1 : ret2;

	std::cout.precision(100);
	std::cout << ret << std::endl;
}
