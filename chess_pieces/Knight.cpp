#include "Knight.h"

#include <iostream>

Knight::Knight(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{pieces_container, IPieceFactory::PieceType::knight, colour, position}
{
    calculateLegalMoves();
}

std::size_t Knight::checkForBlockingPieces(std::size_t start_index)
{
    for (std::size_t i {start_index}; i<_legal_moves.size(); i++)
    {
        for (const auto& piece : Piece::container()->allPieces())
        {
            if (_legal_moves[i] == piece->position())
            {                
                if (piece->colour() == Piece::colour())
                {
                    _legal_moves.erase(std::begin(_legal_moves)+i);
                }
            }
        }
    }
    return _legal_moves.size();
}

void Knight::calculateLegalMoves()
{
    // need to make legal moves more easily accessible
    _legal_moves.clear();
    std::size_t start {_legal_moves.size()};

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::knight]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::knight])
    );
    start = checkForBlockingPieces(start);
}

void Knight::update()
{
    calculateLegalMoves();
}

std::vector<int> Knight::legalMoves() const
{
    return _legal_moves;
}