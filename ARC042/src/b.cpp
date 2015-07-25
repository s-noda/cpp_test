#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <float.h>
#include <math.h>

int main(int argc, char** argv){
  std::vector<int> x(2);
  int N;
  std::vector<std::vector<int> > y;
  double min_dist = DBL_MAX;

  std::cin >> x[0] >> x[1];
  std::cin >> N;

  y.resize(N, std::vector<int>(2) );

  for ( int i=0 ; i<N ; i++ ){
	  std::cin >> y[i][0] >> y[i][1];
  }

  std::vector<int> x_yi(2);
  std::vector<int> yi1_yi(2);
  std::vector<double> dist(3);
  for ( int i=0 ; i<N ; i++ ){
	  x_yi[0] = x[0] - y[i][0];
	  x_yi[1] = x[1] - y[i][1];

	  yi1_yi[0] = y[((i+1)%(N))][0] - y[i][0];
	  yi1_yi[1] = y[((i+1)%(N))][1] - y[i][1];

	  double alf = (x_yi[0]*yi1_yi[0]+x_yi[1]*yi1_yi[1])/(1.0*yi1_yi[0]*yi1_yi[0]+yi1_yi[1]*yi1_yi[1]);
	  dist[0] = -x_yi[0] + alf * yi1_yi[0];
	  dist[1] = -x_yi[1] + alf * yi1_yi[1];
	  dist[2] = sqrt(dist[0]*dist[0]+dist[1]*dist[1]);
	  // std::cout << alf << ", " << dist[0] << ", " << dist[1] << ", " << dist[2] << std::endl;
	  if ( dist[2] < min_dist ) min_dist = dist[2];
  }

  std::cout.precision(100);
  std::cout << min_dist << std::endl;
}
