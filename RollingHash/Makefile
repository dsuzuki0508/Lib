all: run
.PHONY: run
run: test
	./test
test: test.cpp RollingHash.h
	g++-12 -std=gnu++20 -O2 -Wall -Wextra -mtune=native -march=native -fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 -I/opt/ac-library -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o test test.cpp -I/usr/include/eigen3 -lgtest_main -lgtest -lpthread

.PHONY: clean
clean:
	-rm -r test
