CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17
TARGET = HuffmanCompressorApp
SRCS = main.cpp HuffmanTree.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
