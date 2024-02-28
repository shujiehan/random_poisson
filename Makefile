LIBC = $(wildcard libc/*.cpp)
CC = g++
CFLAGS = -std=c++11

poisson: poisson.cpp $(LIBC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm poisson libc/*.o
