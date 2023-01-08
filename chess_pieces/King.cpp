#include "King.h"

#include <iostream>

King::King(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{pieces_container, IPieceFactory::PieceType::king, colour, position}
{
    calculateLegalMoves();
}

std::size_t King::checkForBlockingPieces(std::size_t start_index)
{
    for (std::size_t i {start_index}; i<_legal_moves.size(); i++)
    {
        for (const auto& piece : Piece::container()->allPieces())
        {
            if (_legal_moves[i] == piece->position())
            {
                if (piece->type() == Piece::type()) // block squares adjacent to king.
                {
                    _legal_moves.resize(i-1);
                    return i-1;
                }
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

void King::calculateLegalMoves()
{
    // need to make legal moves more easily accessible
    _legal_moves.clear();
    std::size_t start {_legal_moves.size()};

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::king]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::king])
    );
    start = checkForBlockingPieces(start);
}

void King::update()
{
    calculateLegalMoves();
}

std::vector<int> King::legalMoves() const
{
    return _legal_moves;
}