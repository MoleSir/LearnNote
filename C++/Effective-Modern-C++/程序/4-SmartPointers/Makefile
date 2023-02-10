CC := g++

.PHYON: buildItem18, buildItem21, buildItem22

buildItem18: Item18-Use_unique_ptr.cpp
	$(CC) $^ -o ./exe/Item18.exe 

buildItem21: Item21-Use_make_instead_of_new.cpp
	$(CC) $^ -o ./exe/Item21.exe

buildItem22: ./Item22-Impl/Widget.cpp ./Item22-Impl/Application.cpp
	$(CC) $^ -o ./exe/Item22.exe