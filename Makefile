CXX = g++

CPPFLAGS = -Wall \
           -Ichess_board/include \
		   -Ichess_pieces/include \
		   -g \
		   -std=c++2a

SOURCES = main.cpp \
          chess_pieces/PieceMoves.cpp \
		  chess_pieces/PiecesContainer.cpp \
		  chess_pieces/Piece.cpp \
		  chess_pieces/Rook.cpp \
		  chess_pieces/Knight.cpp \
		  chess_pieces/Bishop.cpp \
		  chess_pieces/Queen.cpp \
		  chess_pieces/King.cpp \
          chess_board/HtmlTagBuilder.cpp \
		  chess_board/ChessBoardBuilder.cpp

OBJECTS := $(patsubst %.cpp, build/%.o, $(SOURCES))

build/%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o $@ 

all: pre_build engine.exe

pre_build:
	if not exist build\chess_board mkdir build\chess_board
	if not exist build\chess_pieces mkdir build\chess_pieces
	if not exist run mkdir run

engine.exe: $(OBJECTS)
	$(CXX) -o run/$@ $^ $(CPPFLAGS)

clean:
	RMDIR "build" /S /Q
	RMDIR "run" /S /Q