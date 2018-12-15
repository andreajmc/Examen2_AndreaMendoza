main.out: main.o Node.o User.o LinkedList.o
    g++ main.o Node.o User.o LinkedList.o -o main.out

Node.o: Node.cpp Node.h
    g++ -c Node.cpp

User.o: User.cpp User.h
    g++ -c User.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
    g++ -c LinkedList.cpp

main.o: main.cpp Node.h User.h LinkedList.h
    g++ -c main.cpp