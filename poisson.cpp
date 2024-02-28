#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <chrono>
#include "libc/random.hpp"
using namespace std;
using namespace std::chrono;

int poisson(double lambda, Random &r) {
  if (lambda < 100.0) {
    double product = 1.0;
    double sum = 1.0;
    double threshold = r.nextDouble() * exp(lambda);
    //cout << "threshold = " << threshold << endl;
    int i = 1;
    int max_ = max(100, 10 * (int) ceil(lambda));
    while ((i < max_) && (sum <= threshold)) {
        product *= (lambda / i);
        sum += product;
        i++;
    }
    return i - 1;
  }
  double x = lambda + sqrt(lambda) * r.nextGaussian();
  if (x < 0.0) {
      return 0;
  }
  return (int) floor(x);
}

int main(int argc, char **argv){

  int seed = 1;
  Random r(seed);
  int k = 0;
  int sum = 0;
  auto start = high_resolution_clock::now();
  for (int i = 0; i < 100000; i++) {
      k = poisson(1.0, r);
      sum += k;
      //cout << "iter = " <<  i << ", k = " << k << '\n';
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function: "
       << duration.count() << " microseconds" << endl;
  cout << sum << '\n';

  return 1;
}
