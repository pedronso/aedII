aedII

Compile:

gcc index.c -o index.o -c
gcc main.c -o main.o -c
gcc ../bst/bst.c -o bst.o -c
gcc ../avl/avl.c -o avl.o -c
gcc ../avp/avp.c -o avp.o -c
gcc -o result index.o main.o bst.o avl.o avp.o
./result

