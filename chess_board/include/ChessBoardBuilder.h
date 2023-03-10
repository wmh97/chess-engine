#ifndef CHESS_BOARD_BUILDER_H
#define CHESS_BOARD_BUILDER_H

#include "HtmlTagBuilder.h"
#include "PieceInterfaces.h"

#include <map>
#include <string>
#include <memory>

class ChessBoardBuilder
{
public:
    ChessBoardBuilder() = default;

    void setPiece(IPiece* piece, bool show_legal_moves=false);

    // void setBlackRook(IPiece* rook);
    // void setBlackKnight(int position);
    // void setBlackBishop(int position);
    // void setBlackKing(int position);
    // void setBlackQueen(int position);
    // void setBlackPawn(int position);

    // void setWhiteRook(int position);
    // void setWhiteKnight(int position);
    // void setWhiteBishop(int position);
    // void setWhiteKing(int position);
    // void setWhiteQueen(int position);
    // void setWhitePawn(int position);

    void createBoard();
    void outputBoard();

private:
    std::map<int, std::string> _board_map {};
    std::string _board_html {};

    std::vector<int> _legal_moves {};

    std::string getSquareColour(int row_number, int position) const;
    std::unique_ptr<HtmlTagBuilder> buildRow(int row_number);
};

#endif