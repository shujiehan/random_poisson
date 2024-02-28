#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <chrono>
#include "libc/random.hpp"
using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){

  int seed = 1;
  Random r(seed);
  int k = 0;
  int sum = 0;
  auto start = high_resolution_clock::now();
  for (int i = 0; i < 100000; i++) {
      k = r.poisson(1.0);
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
