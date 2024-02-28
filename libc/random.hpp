#include <iostream>
#include <cmath>
#include <ctime>

class Random {
private:
    long long _seed;
    double nextNextGaussian;

public: 
    Random();
    Random(long long seed);
    void setSeed(long long seed);
    long long getSeed();
    int next(int bits);
    int* nextBytes(int l[]);
    int nextInt();
    int nextInt(int n);
    long long nextLong();
    bool nextBoolean();
    float nextFloat();
    double nextDouble();
    double nextGaussian();
    int poisson(double lambda);
};
