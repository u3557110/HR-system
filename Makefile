census.o:census.cpp BigInteger.h Country.h
  g++ -c census.cpp

BigInteger.o:BigInteger.h BigInteger.cpp
  g++ -c BigInteger.cpp
  
Country.o:BigInteger.h Country.h Country.cpp
  g++ -c Country.cpp

census:census.o BigInteger.o Country.o
  g++ census.o BigInteger.o Country.o -o census

run:
  ./census > output.txt
  echo "The following is the output of census."
  cat output.txt

 #This file must be named Makefile
 #Comments start with #
