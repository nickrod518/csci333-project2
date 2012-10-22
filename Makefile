BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
AA = $(SRC)/AArray
VA = $(SRC)/VArray
SA = $(SRC)/SArray
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
OBJECTS = $(AA)/AArray.o $(VA)/VArray.o $(SA)/SArray.o $(SA)/Node.o
IMPLEMENTATIONS = $(AA)/AArray.cpp $(VA)/VArray.cpp $(SA)/SArray.cpp $(SA)/Node.cpp
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CPPFLAGS = -Wall -Wextra -Werror


all: $(BUILD)/main $(TEST)/array_test

$(BUILD)/main: $(OBJECTS) $(IMPLEMENTATIONS)
	$(CPP) $(CPPFLAGS) -o $(BUILD)/main $(SRC)/array_tester.cpp $(OBJECTS)

$(TEST)/array_test: $(TEST)/Array.cpp $(OBJECTS) $(GTEST_MAINA)
	$(CPP) $(CPPFLAGS) $(GTEST_INCLUDES) -pthread -o $(TEST)/array_test $(TEST)/Array.cpp $(OBJECTS) $(GTEST_MAINA)

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make; make

# array array
aarray_test: $(TEST)/Array.cpp $(AA)/AArray.o $(GTEST_MAINA)
	$(CPP) $(CPPFLAGS) $(GTEST_INCLUDES) -pthread -o $(TEST)/array_test $^

aarray: $(SRC)/array_tester.cpp $(AA)/AArray.o
	$(CPP) $(CPPFLAGS) -o $(BUILD)/aarray $^

AArray.o: $(AA)/AArray.h $(AA)/AArray.cpp
	$(CPP) $(CPPFLAGS) -c $(AA)/AArray.cpp

# vector array
varray: $(SRC)/array_tester.cpp $(VA)/VArray.o
	$(CPP) $(CPPFLAGS) -o $(BUILD)/varray $^

VArray.o: $(VA)/VArray.h $(VA)/VArray.cpp
	$(CPP) $(CPPFLAGS) -c $(VA)/VArray.cpp

# sparse array
sarray: $(SRC)/array_tester.cpp $(SA)/SArray.o $(SA)/Node.o
	$(CPP) $(CPPFLAGS) -o $(BUILD)/sarray $^

SArray.o: $(SA)/SArray.h $(SA)/SArray.cpp
	$(CPP) $(CPPFLAGS) -c $(SA)/SArray.cpp

Node.o: $(SA)/Node.h $(SA)/Node.cpp
	$(CPP) $(CPPFLAGS) -c $(SA)/Node.cpp


clean:
	rm -f $(AA)/*.o
	rm -rf $(AA)/*~
	rm -f $(VA)/*.o
	rm -rf $(VA)/*~
	rm -rf $(SA)/*.o
	rm -rf $(SA)/*~
	rm -rf $(SRC)/*.o
	rm -rf $(SRC)/*~
	rm -rf *~
	rm -f $(BUILD)/main
	rm -f $(BUILD)/aarray
	rm -f $(BUILD)/varray
	rm -f $(BUILD)/sarray
	rm -f $(TEST)/array_test
	rm -f $(GTEST_MAINA)
	cd $(GTEST)/make; make clean
