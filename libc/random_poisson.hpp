#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

class RandomPoisson {
  private:
    long long _seed;
    double nextNextGaussian;

  public:
    //RandomPoisson() { _seed = static_cast<long long>(time(nullptr) * 1000);}
    RandomPoisson(int seed) {
        this->_seed = (seed ^ 0x5deece66dl) & ((1LL << 48) - 1);
        nextNextGaussian = -1;
    }

    void setSeed(int seed) {
        this->_seed = seed;
    }

    int getSeed() {
        return _seed;
    }


    int next(int bits) {
        if (bits < 1)
            bits = 1;
        else if (bits > 32)
            bits = 32;
    
        this->_seed = (_seed * 0x5deece66dl + 0xb) & ((1LL << 48) - 1);
        int retval = _seed >> (48 - bits);
    
        if (retval & (1L << 31))
            retval -= (1L << 32);
    
        return retval;
    }

    int* nextBytes(int l[]) {
        int n, b;
        for (int i = 0; i < sizeof(l)/sizeof(l[0]); ++i) {
            if (i % 4 == 0) {
                n = nextInt();
            }
            b = n & 0xff;
            if (b & 0x80)
                b -= 0x100;
            l[i] = b;
            n >>= 8;
        }
        return l;
    }

    int nextInt(int n=-1) {
        if (n <= 0)
            return next(32);
    
        if (!(n & (n - 1)))
            return (n * next(31)) >> 31;
    
        int bits = next(31);
        int val = bits % n;
        while (bits - val + n - 1 < 0) {
            bits = next(31);
            val = bits % n;
        }
        return val;
    }

    long long nextLong() {
        return (static_cast<long long>(RandomPoisson::next(32)) << 32) + next(32);
    }

    bool nextBoolean() {
        return RandomPoisson::next(1);
    }
    
    float nextFloat() {
        return next(24) / static_cast<float>(1 << 24);
    }
    
    double nextDouble() {
        return ((static_cast<long long>(next(26)) << 27) + next(27)) / static_cast<double>(1L << 53);
    }
    
    double nextGaussian() {
        if (nextNextGaussian != -1) {
            double temp = nextNextGaussian;
            nextNextGaussian = -1;
            return temp;
        }
        double v1, v2, s;
        do {
            v1 = 2 * nextDouble() - 1;
            v2 = 2 * nextDouble() - 1;
            s = v1 * v1 + v2 * v2;
        } while (s >= 1 || s == 0);
        double multiplier = sqrt(-2 * log(s) / s);
        nextNextGaussian = v2 * multiplier;
        return v1 * multiplier;
    }
    
    int poisson(double lambda) {
        if (lambda < 100.0) {
          double product = 1.0;
          double sum = 1.0;
          double threshold = nextDouble() * std::exp(lambda);
          int i = 1;
          int max_ = std::max(100, 10 * (int) std::ceil(lambda));
          while ((i < max_) && (sum <= threshold)) {
              product *= (lambda / i);
              sum += product;
              i++;
          }
          return i - 1;
        }
        double x = lambda + std::sqrt(lambda) * nextGaussian();
        if (x < 0.0) {
            return 0;
        }
        return (int) std::floor(x);
    
    }

    std::vector<int> multiplePoisson(double lambda, int n) {
        std::vector<int> retVal(0); 
        for (int i = 0; i < n; i++) {
            retVal.push_back(poisson(lambda));
        }
        return retVal;
    }
};

//class RandomPoisson {
////private:
//
//public: 
//    int _seed;
//    //double nextNextGaussian;
//
//    //RandomPoisson();
//    RandomPoisson(int seed);
//    void setSeed(int seed);
//    int getSeed();
///*
//    int next(int bits);
//    int* nextBytes(int l[]);
//    int nextInt(int n=-1);
//    long long nextLong();
//    bool nextBoolean();
//    float nextFloat();
//    double nextDouble();
//    double nextGaussian();
//    int poisson(double lambda);
//*/
//};
