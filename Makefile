CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++11
SRC = srcs/main.cc srcs/map/*.cpp srcs/objects/*.cpp srcs/functions/*.cpp
OBJ = $(SRC:.cc=.o)
TARGET = neopop

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean