CXX = g++
CXXFLAGS = -Wall -g

driver.out: Word.o Indexer.o  Driver.cpp
	$(CXX) $(CXXFLAGS) Word.o Indexer.o Driver.cpp -o driver.out


Indexer.o: Indexer.cpp Indexer.h 
	$(CXX) $(CXXFLAGS) -c Indexer.cpp

Word.o: Word.cpp Word.h 	
	$(CXX) $(CXXFLAGS) -c Word.cpp

run: 

	./driver.out gsl.txt input1.txt

val: 

	valgrind ./driver.out gsl.txt input1.txt 




