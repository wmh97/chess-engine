#include "Queen.h"

#include <iostream>

Queen::Queen(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{pieces_container, IPieceFactory::PieceType::queen, colour, position},
    Rook{pieces_container, colour, position},
    Bishop{pieces_container, colour, position}
{
    calculateLegalMoves();
}

void Queen::calculateLegalMoves()
{
    Rook::update();
    Bishop::update();
}

void Queen::update()
{
    calculateLegalMoves();
}

std::vector<int> Queen::legalMoves() const
{
    std::vector<int> rook_legal_moves { Rook::legalMoves() };
    std::vector<int> bishop_legal_moves { Bishop::legalMoves() };
    rook_legal_moves.insert(
        std::end(rook_legal_moves),
        std::begin(bishop_legal_moves), std::end(bishop_legal_moves)
    );
    return rook_legal_moves;
}