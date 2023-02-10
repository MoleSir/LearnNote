main.exe: main.o AdapterPattern.o
	@g++ main.o AdapterPattern.o -o main.exe

main.o: main.cpp
	@g++ -c main.cpp -o main.o

AdapterPattern.o: AdapterPattern.cpp
	@g++ -c AdapterPattern.cpp -o AdapterPattern.o


.PHYON: run

run:
	@./main.exe