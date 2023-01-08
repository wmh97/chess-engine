#include "Queen.h"

#include <iostream>

Queen::Queen(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{IPieceFactory::PieceType::queen, colour, position},
    _container{pieces_container}
{
    calculateLegalMoves();
}

void Queen::calculateLegalMoves()
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

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left_up]), 
        std::end(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left_up])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left_down]), 
        std::end(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::left_down])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right_up]), 
        std::end(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right_up])
    );
    start = checkForBlockingPieces(start);

    _legal_moves.insert(
        std::end(_legal_moves), 
        std::begin(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right_down]), 
        std::end(_container->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::right_down])
    );
    start = checkForBlockingPieces(start);    
}

void Queen::update()
{
    calculateLegalMoves();
}

std::size_t Queen::checkForBlockingPieces(std::size_t start_index)
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

std::vector<int> Queen::legalMoves() const
{
    // std::vector<int> rook_legal_moves { Rook::legalMoves() };
    // std::vector<int> bishop_legal_moves { Bishop::legalMoves() };
    // rook_legal_moves.insert(
    //     std::end(rook_legal_moves),
    //     std::begin(bishop_legal_moves), std::end(bishop_legal_moves)
    // );
    // return rook_legal_moves;
    return _legal_moves;
}