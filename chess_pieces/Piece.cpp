#include "Piece.h"

#include <iostream>
#include <algorithm>

Piece::Piece(std::shared_ptr<PiecesContainer> container, IPieceFactory::PieceType type, IPieceFactory::PieceColour colour, int position) :
    _container{container},
    _type{type},
    _colour{colour},
    _position{position}
{
}

void Piece::move(int position)
{
    // checks
    auto legal_moves {legalMoves()};
    if (std::find(std::begin(legal_moves), std::end(legal_moves), position) != std::end(legal_moves))
    {
        _position = position;
        _container->notifyPiecesOfUpdate(this);
        // ... TODO
    }
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

PiecesContainer* Piece::container() const
{
    return _container.get();
}