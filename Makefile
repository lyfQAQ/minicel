# compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall

# object file and source file
TARGET = minicel
SOURCES = main.cpp

# default object
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
