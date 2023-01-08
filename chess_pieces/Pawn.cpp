#include "Pawn.h"

#include <iostream>

Pawn::Pawn(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{pieces_container, IPieceFactory::PieceType::pawn, colour, position}
{
    calculateLegalMoves();
}

void Pawn::calculateLegalMoves()
{
    auto update = _state->updateState(Piece::container(), Piece::type(), Piece::colour(), Piece::position());
    _legal_moves = update.first;
    if (update.second != nullptr)
    {
        _state = std::move(update.second);
    }
}

void Pawn::update()
{
    calculateLegalMoves();
}

std::vector<int> Pawn::legalMoves() const
{
    return _legal_moves;
}