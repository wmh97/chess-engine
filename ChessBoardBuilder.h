#ifndef CHESS_BOARD_BUILDER_H
#define CHESS_BOARD_BUILDER_H

#include "HtmlTagBuilder.h"

#include <map>
#include <string>

class ChessBoardBuilder
{
public:
    ChessBoardBuilder() = default;

    void setBlackRook(int position1, int position2);
    void setBlackKnight(int position1, int position2);
    void setBlackBishop(int position1, int position2);
    void setBlackKing(int position);
    void setBlackQueen(int position);
    void setBlackPawn(int position1, int position2, int position3, int position4, int position5, int position6, int position7, int position8);

    void setWhiteRook(int position1, int position2);
    void setWhiteKnight(int position1, int position2);
    void setWhiteBishop(int position1, int position2);
    void setWhiteKing(int position);
    void setWhiteQueen(int position);
    void setWhitePawn(int position1, int position2, int position3, int position4, int position5, int position6, int position7, int position8);

    void createBoard();
    void outputBoard();

private:
    std::map<int, std::string> _board_map {};
    std::string _board_html {};

    std::unique_ptr<HtmlTagBuilder> buildRow(int row_number);
};

#endif