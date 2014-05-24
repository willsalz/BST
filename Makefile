src=BST
build=build

.PHONY : all
all: bst

run: all
	./a.out

bst: bst.o main.o
	clang $(build)/bst.o $(build)/main.o -o a.out

bst.o:
	clang -c $(src)/bst.c -o $(build)/bst.o

main.o:
	clang -c $(src)/main.c -o $(build)/main.o

.PHONY : clean
clean:
	rm $(build)/*
	rm a.out
