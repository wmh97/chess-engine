#include "Pawn.h"

#include <iostream>

Pawn::Pawn(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{pieces_container, IPieceFactory::PieceType::pawn, colour, position}
{
    calculateLegalMoves();
}

std::size_t Pawn::checkForBlockingPieces(std::size_t start_index)
{
    for (std::size_t i {start_index}; i<_legal_moves.size(); i++)
    {
        for (const auto& piece : Piece::container()->allPieces())
        {
            if (_legal_moves[i] == piece->position())
            {
                if (piece->colour() != Piece::colour())
                {
                    _legal_moves.resize(i+1);
                    return i+1;
                }
                _legal_moves.resize(i);
                return i;
            }
        }
    }
    return _legal_moves.size();
}

void Pawn::calculateLegalMoves()
{
    // need to make legal moves more easily accessible
    _legal_moves.clear();
    std::size_t start {_legal_moves.size()};

    if (Piece::colour() == IPieceFactory::PieceColour::black)
    {
        _legal_moves.insert(
            std::end(_legal_moves), 
            std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::black_pawn]), 
            std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::black_pawn])
        );
    }
    else if (Piece::colour() == IPieceFactory::PieceColour::white)
    {
        _legal_moves.insert(
            std::end(_legal_moves), 
            std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::white_pawn]), 
            std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::white_pawn])
        );
    }

    start = checkForBlockingPieces(start);
}

void Pawn::update()
{
    calculateLegalMoves();
}

std::vector<int> Pawn::legalMoves() const
{
    return _legal_moves;
}