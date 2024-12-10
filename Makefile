TARGET = SheepFight

CXX = g++

CXXFLAGS = -I/path/to/SFML/include -std=c++20 -Wall -Wextra

LDFLAGS = -L/path/to/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRCS = main.cpp SheepFight.cpp RightPlayer.cpp RightSheeps.cpp

OBJDIR = build
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: build_dir $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build_dir:
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)
