main.o:main.cpp file.hpp getAge.hpp manipulateRec.hpp showMenu.hpp sortRec.hpp searchFunction.hpp printRec.hpp structStaffRec.hpp
	g++ -c main.cpp

file.o:file.cpp file.hpp structStaffRec.hpp
	g++ -c file.cpp

getAge.o:getAge.cpp getAge.hpp
	g++ -c getAge.cpp
  
manipulateRec.o:manipulateRec.cpp manipulateRec.hpp structStaffRec.hpp
	g++ -c manipulateRec.cpp
  
printRec.o:printRec.cpp printRec.hpp structStaffRec.hpp getAge.hpp manipulateRec.hpp sortRec.hpp
	g++ -c printRec.cpp
  
searchFunction.o:searchFunction.cpp searchFunction.hpp manipulateRec.hpp getAge.hpp printRec.hpp structStaffRec.hpp
	g++ -c searchFunction.cpp
  
showMenu.o:showMenu.cpp showMenu.hpp 
	g++ -c showMenu.cpp

sortRec.o:sortRec.cpp sortRec.hpp structStaffRec.hpp getAge.hpp
	g++ -c sortRec.cpp
  
structStaffRec.o:structStaffRec.cpp structStaffRec.hpp
	g++ -c structStaffRec.cpp
  
main:main.o getAge.o manipulateRec.o printRec.o searchFunction.o showMenu.o sortRec.o structStaffRec.o file.o
	g++ main.o getAge.o manipulateRec.o printRec.o searchFunction.o showMenu.o sortRec.o structStaffRec.o file.o -o main

run:
	./main

 #This file must be named Makefile
 #Comments start with #
