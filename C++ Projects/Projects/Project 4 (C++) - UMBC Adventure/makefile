CXX = g++
CXXXFLAGS = -Wall -g

proj4: Entity.o Character.o Monster.o Game.o Room.o BabyDragon.o Goblin.o Skeleton.o Paladin.o Rogue.o Wizard.o proj4.cpp
	$(CXX) $(CXXFLAGS) Entity.o Character.o Monster.o Game.o Room.o BabyDragon.o Goblin.o Skeleton.o Paladin.o Rogue.o Wizard.o proj4.cpp -o proj4

Entity.o: Entity.h Entity.cpp
	$(CXX) $(CXXFLAGS) -c Entity.cpp

Character.o: Entity.o Character.h Character.cpp
	$(CXX) $(CXXFLAGS) -c Character.cpp

Monster.o: Entity.o Monster.h Monster.cpp
	$(CXX) $(CXXFLAGS) -c Monster.cpp

BabyDragon.o: Entity.o BabyDragon.h BabyDragon.cpp
	$(CXX) $(CXXFLAGS) -c BabyDragon.cpp

Goblin.o: Entity.o Goblin.h Goblin.cpp
	$(CXX) $(CXXFLAGS) -c Goblin.cpp

Skeleton.o: Entity.o Skeleton.h Skeleton.cpp
	$(CXX) $(CXXFLAGS) -c Skeleton.cpp

Paladin.o: Entity.o Paladin.h Paladin.cpp
	$(CXX) $(CXXFLAGS) -c Paladin.cpp

Rogue.o: Entity.o Rogue.h Rogue.cpp
	$(CXX) $(CXXFLAGS) -c Rogue.cpp

Wizard.o: Entity.o Wizard.h Wizard.cpp
	$(CXX) $(CXXFLAGS) -c Wizard.cpp

Game.o: Room.o Entity.o Monster.o Character.o Goblin.o Skeleton.o BabyDragon.o Rogue.o Wizard.o Paladin.o Game.h Game.cpp 
	$(CXX) $(CXXFLAGS) -c Game.cpp

Room.o: Room.h Room.cpp
	$(CXX) $(CXXFLAGS) -c Room.cpp

clean:
	rm *.o
	rm *~

run1:
	./proj4 map1_data.txt

run2:
	./proj4 map2_data.txt

val1:
	valgrind ./proj4 map1_data.txt

val2:
	valgrind ./proj4 map2_data.txt 

