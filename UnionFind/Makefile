all: run
.PHONY: run
run: test
	./test
test: test.cpp UnionFind.h
	g++ test.cpp -lgtest_main -lgtest -lpthread -o test
.PHONY: clean
clean:
	-rm -r test
