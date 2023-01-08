#include "Bishop.h"

#include <iostream>

Bishop::Bishop(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{pieces_container, IPieceFactory::PieceType::bishop, colour, position}
{
    calculateLegalMoves();
}

std::size_t Bishop::checkForBlockingPieces(std::size_t start_index)
{
    for (std::size_t i {start_index}; i<_legal_moves.size(); i++)
    {
        for (const auto& piece : Piece::container()->allPieces())
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

void Bishop::calculateLegalMoves()
{
    // need to make legal moves more easily accessible
    _legal_moves.clear();
    std::size_t start {_legal_moves.size()};

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left_up]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left_up])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left_down]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left_down])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right_up]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right_up])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right_down]), 
        std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right_down])
    );
    start = checkForBlockingPieces(start);
}

void Bishop::update()
{
    calculateLegalMoves();
}

std::vector<int> Bishop::legalMoves() const
{
    return _legal_moves;
}