#include "Piece.h"

#include <iostream>

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
    _position = position;
    _container->notifyPiecesOfUpdate();
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

PiecesContainer* Piece::container() const
{
    return _container.get();
}