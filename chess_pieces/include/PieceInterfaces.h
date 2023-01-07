#ifndef PIECE_INTERFACES_H
#define PIECE_INTERFACES_H

#include <vector>
#include <memory>

class IPiece;
class PiecesContainer;

class IPieceFactory
{
public:
    enum class PieceType
    {
        rook,
        knight,
        bishop,
        king,
        queen,
        pawn
    };
    enum class PieceColour
    {
        black,
        white
    };
    virtual ~IPieceFactory() = default;
    virtual std::shared_ptr<IPiece> makePiece(std::shared_ptr<PiecesContainer> container, IPieceFactory::PieceType piece_type, IPieceFactory::PieceColour colour, int position) = 0;
};

class IPiece
{
public:
    virtual ~IPiece() = default;
    virtual void move(int position) = 0;
    virtual int position() const = 0;
    virtual void calculateLegalMoves() = 0;
    virtual std::vector<int> legalMoves() const = 0;
    virtual IPieceFactory::PieceType type() const = 0;
    virtual IPieceFactory::PieceColour colour() const = 0;
};

#endif