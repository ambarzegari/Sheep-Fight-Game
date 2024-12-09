TARGET = sheep_fight

CXX = g++

CXXFLAGS = -I/path/to/SFML/include -std=c++17 -Wall -Wextra

LDFLAGS = -L/path/to/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRCS = main.cpp SheepFight.cpp RightPlayer.cpp RightSheeps.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
