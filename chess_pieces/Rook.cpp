#include "Rook.h"

#include <iostream>

Rook::Rook(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{pieces_container, IPieceFactory::PieceType::rook, colour, position}
{
    calculateLegalMoves();
}

std::size_t Rook::checkForBlockingPieces(std::size_t start_index)
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

void Rook::calculateLegalMoves()
{
    // need to make legal moves more easily accessible
    _legal_moves.clear();
    std::size_t start {_legal_moves.size()};

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::up]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::up])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::down]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::down])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right])
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