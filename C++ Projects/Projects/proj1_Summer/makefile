CXX = g++
CXXFLAGS = -Wall -g 

proj1: LlamaNode.o Llama.h Llama.cpp driver3.cpp
	$(CXX) $(CXXFLAGS) LlamaNode.o Llama.h Llama.cpp driver3.cpp -o proj1

LlamaNode.o: LlamaNode.cpp LlamaNode.h 
	$(CXX) $(CXXFLAGS) -c LlamaNode.cpp

run: 

	./proj1

