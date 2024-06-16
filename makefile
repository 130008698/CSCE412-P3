CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS =

INCLUDES = -Iinclude
SOURCES = src/Request.cpp src/Webserver.cpp src/Requestqueue.cpp src/Loadbalancer.cpp src/Helpers.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = loadbalancer

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
