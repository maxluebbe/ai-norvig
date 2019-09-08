binaries = p25
OBJECTS = ch2.o environment.o position.o room.o scorer.o
tests = ch2_test position_test room_test scorer_test
GTEST_FLAGS= -std=c++0x -lgtest -lgtest_main -pthread


.PHONY: all
all: $(OBJECTS) $(tests) $(binaries)

ch2.o: ch2.h ch2.cc common.h position.h room.h scorer.h
	g++ -c ch2.cc

p25: p25.cc $(OBJECTS)
	g++ $(OBJECTS) p25.cc -o p25

ch2_test: ch2_test.cc $(OBJECTS)
	g++ ch2_test.cc $(OBJECTS) $(GTEST_FLAGS) -o ch2_test

environment.o: environment.cc environment.h
	g++ -c environment.cc

environment_test: environment_test.cc $(OBJECTS)
	g++ environment_test.cc $(OBJECTS) $(GTEST_FLAGS) -o environment_test

position.o: position.h position.cc common.h
	g++ -c position.cc

position_test: position_test.cc position.o
	g++ -std=c++0x position_test.cc position.o -lgtest -lgtest_main -pthread -o position_test

room.o: common.h position.h room.h room.cc
	g++ -c room.cc

room_test: room.o room_test.cc
	g++ -std=c++0x room_test.cc position.o room.o -lgtest -lgtest_main -pthread -o room_test

scorer.o: scorer.h scorer.cc
	g++ -c scorer.cc

scorer_test: scorer.h scorer.cc scorer_test.cc
	g++ -std=c++0x scorer_test.cc scorer.o -lgtest -lgtest_main -pthread -o scorer_test

.PHONY: run_tests
run_tests: $(tests)
	./ch2_test
	./environment_test
	./position_test
	./room_test
	./scorer_test

.PHONY: clean
clean:
	rm $(OBJECTS) $(tests) $(binaries)