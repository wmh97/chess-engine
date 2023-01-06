#ifndef PIECE_INTERFACES_H
#define PIECE_INTERFACES_H

#include <vector>
#include <memory>

class IPiece
{
public:
    virtual ~IPiece() = default;
    virtual void move(int position) = 0;
    virtual int position() const = 0;
    virtual void calculateLegalMoves() = 0;
    virtual std::vector<int> legalMoves() const = 0;
};

class IPieceFactory
{
public:
    enum class PieceType
    {
        black_rook,
        black_knight,
        black_bishop,
        black_king,
        black_queen,
        black_pawn,

        white_rook,
        white_knight,
        white_bishop,
        white_king,
        white_queen,
        white_pawn
    };
    virtual ~IPieceFactory() = default;
    std::unique_ptr<IPiece> makePiece(PieceType piece_type, int position);
};

#endif