#ifndef PIECE_FACTORY_H
#define PIECE_FACTORY_H

#include "PieceInterfaces.h"

#include <vector>
#include <memory>

class PieceFactory
{
public:
    PieceFactory() = default;

    std::unique_ptr<IPiece> makeBlackRook(int position);
    std::unique_ptr<IPiece> makeBlackKnight(int position);
    std::unique_ptr<IPiece> makeBlackBishop(int position);
    std::unique_ptr<IPiece> makeBlackKing(int position);
    std::unique_ptr<IPiece> makeBlackQueen(int position);
    std::unique_ptr<IPiece> makeBlackPawn(int position);

    std::unique_ptr<IPiece> makeWhiteRook(int position);
    std::unique_ptr<IPiece> makeWhiteKnight(int position);
    std::unique_ptr<IPiece> makeWhiteBishop(int position);
    std::unique_ptr<IPiece> makeWhiteKing(int position);
    std::unique_ptr<IPiece> makeWhiteQueen(int position);
    std::unique_ptr<IPiece> makeWhitePawn(int position);

    std::vector<std::unique_ptr<IPiece>> allPieces() const;

private:
    std::vector<std::unique_ptr<IPiece>> _all_pieces {};

    void notifyOfPieceAdded(std::unique_ptr<IPiece> piece_added);
};

#endif