CXX = g++

CPPFLAGS = -Wall \
		   -g \
		   -std=c++2a

SOURCES = main.cpp \
          HtmlTagBuilder.cpp \
		  ChessBoardHtmlBuilder.cpp

OBJECTS := $(patsubst %.cpp, build/%.o, $(SOURCES))

build/%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o $@ 

all: pre_build engine.exe

pre_build:
	if not exist build mkdir build
	if not exist run mkdir run

engine.exe: $(OBJECTS)
	$(CXX) -o run/$@ $^ $(CPPFLAGS)

clean:
	RMDIR "build" /S /Q
	RMDIR "run" /S /Q