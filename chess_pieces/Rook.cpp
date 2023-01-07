#include "Rook.h"

#include <iostream>

Rook::Rook(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{IPieceFactory::PieceType::rook, colour, position},
    _container{pieces_container}
{
    calculateLegalMoves();
}

std::size_t Rook::checkForBlockingPieces(std::size_t start_index)
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

void Rook::calculateLegalMoves()
{
    // need to make legal moves more easily accessible
    _legal_moves.clear();
    std::size_t start {_legal_moves.size()};

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::up]), 
        std::end(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::up])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::down]), 
        std::end(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::down])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left]), 
        std::end(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right]), 
        std::end(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right])
    );
    start = checkForBlockingPieces(start);
}

void Rook::update()
{
    calculateLegalMoves();
}

std::vector<int> Rook::legalMoves() const
{
    return _legal_moves;
}