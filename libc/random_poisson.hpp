#include <iostream>
#include <cmath>
#include <ctime>

class RandomPoisson {
private:
    long long _seed;
    double nextNextGaussian;

public: 
    RandomPoisson();
    RandomPoisson(long long seed);
    void setSeed(long long seed);
    long long getSeed();
    int next(int bits);
    int* nextBytes(int l[]);
    int nextInt(int n=-1);
    long long nextLong();
    bool nextBoolean();
    float nextFloat();
    double nextDouble();
    double nextGaussian();
    int poisson(double lambda);
};
