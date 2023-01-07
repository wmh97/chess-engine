#include "Piece.h"

#include <iostream>

Piece::Piece(IPieceFactory::PieceType type, IPieceFactory::PieceColour colour, int position) :
    _type{type},
    _colour{colour},
    _position{position}
{
}

void Piece::move(int position)
{
    // checks
    _position = position;
    // ... TODO
}

int Piece::position() const
{
    return _position;
}

IPieceFactory::PieceType Piece::type() const
{
    return _type;
}

IPieceFactory::PieceColour Piece::colour() const
{
    return _colour;
}

// void Piece::update()
// {

// }

// std::vector<int> Piece::legalMoves() const
// {
//     return std::vector<int>{};
// }