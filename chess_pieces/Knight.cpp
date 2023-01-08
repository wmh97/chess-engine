#include "Knight.h"

#include <iostream>

Knight::Knight(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{IPieceFactory::PieceType::knight, colour, position},
    _container{pieces_container}
{
    calculateLegalMoves();
}

std::size_t Knight::checkForBlockingPieces(std::size_t start_index)
{
    for (std::size_t i {start_index}; i<_legal_moves.size(); i++)
    {
        for (const auto& piece : _container->allPieces())
        {
            if (_legal_moves[i] == piece->position())
            {
                _legal_moves.resize(i);
                return i;
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
        std::begin(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::knight]), 
        std::end(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::knight])
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