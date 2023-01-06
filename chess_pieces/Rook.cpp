#include "Rook.h"

#include <iostream>

Rook::Rook(std::shared_ptr<PiecesContainer> pieces_container, int position) :
    _container{pieces_container},
    _position{position}
{
    calculateLegalMoves();
}

void Rook::move(int position)
{
    // checks
    _position = position;
    // ... TODO
}

int Rook::position() const
{
    return _position;
}

std::vector<int> Rook::legalMoves() const
{
    return _legal_moves;
}

std::size_t Rook::checkForBlockingPieces(std::size_t start_index)
{
    for (std::size_t i {start_index}; i<_legal_moves.size(); i++)
    {
        std::cout << "Checking for blocking piece at " << _legal_moves[i] << "\n";
        if (_legal_moves[i] == _position)
        {
            _legal_moves.resize(i);
            std::cout << "Blocking piece at: " << _legal_moves[i] << "\n";
            return i;
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
        std::begin(_container->legalMoves()->legal_moves[_position][PieceMoves::MoveDirections::up]), 
        std::end(_container->legalMoves()->legal_moves[_position][PieceMoves::MoveDirections::up])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[_position][PieceMoves::MoveDirections::down]), 
        std::end(_container->legalMoves()->legal_moves[_position][PieceMoves::MoveDirections::down])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[_position][PieceMoves::MoveDirections::left]), 
        std::end(_container->legalMoves()->legal_moves[_position][PieceMoves::MoveDirections::left])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[_position][PieceMoves::MoveDirections::right]), 
        std::end(_container->legalMoves()->legal_moves[_position][PieceMoves::MoveDirections::right])
    );
    start = checkForBlockingPieces(start);
}