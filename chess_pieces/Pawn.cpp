#include "Pawn.h"

#include <iostream>
#include <algorithm>

Pawn::Pawn(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position) :
    Piece{pieces_container, IPieceFactory::PieceType::pawn, colour, position}
{
    calculateLegalMoves();
}

void Pawn::move(int position)
{
    Piece::move(position);
    if (_first_move)
    {
        _first_move = false;
        calculateLegalMoves();
    }
}

std::size_t Pawn::checkForBlockingPieces(std::size_t start_index)
{
    auto all_pieces {Piece::container()->allPieces()};
    for (std::size_t i {start_index}; i<_legal_moves.size(); i++)
    {
        for (std::size_t piece {0}; piece<all_pieces.size(); piece++)
        {
            if (_legal_moves[i] == all_pieces[piece]->position()) // if there is a piece on the legal move square
            {                
                std::cout << "another piece on " << _legal_moves[i] << "\n";
                if (all_pieces[piece]->colour() == Piece::colour())
                {
                    _legal_moves.erase(std::begin(_legal_moves)+i);
                }
                return start_index;
            }
            else if (piece == all_pieces.size()-1)
            {                
                if (_legal_moves[i] == Piece::position()+7 ||
                    _legal_moves[i] == Piece::position()-7 ||
                    _legal_moves[i] == Piece::position()+9 ||
                    _legal_moves[i] == Piece::position()-9)
                {
                    // finds diagonals successfully just need to work out how to delete them???
                    std::cout << "Diagonal: " << _legal_moves[i] << "\n";
                }
            }
        }
    }
    // std::remove_if(std::begin(_legal_moves), std::end(_legal_moves), [](int i){ return i == 0; });
    return _legal_moves.size();
}

void Pawn::calculateLegalMoves()
{
    // need to make legal moves more easily accessible
    _legal_moves.clear();
    std::size_t start {_legal_moves.size()};

    if (Piece::colour() == IPieceFactory::PieceColour::black)
    {
        if (_first_move)
        {
            _legal_moves.insert(
                std::end(_legal_moves), 
                std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::black_pawn_start]), 
                std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::black_pawn_start])
            );
            checkForBlockingPieces(start);
        }
        else
        {
            _legal_moves.insert(
                std::end(_legal_moves), 
                std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::black_pawn]), 
                std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::black_pawn])
            );
            checkForBlockingPieces(start);
        }
    } 
    else if (Piece::colour() == IPieceFactory::PieceColour::white)
    {
        if (_first_move)
        {
            _legal_moves.insert(
                std::end(_legal_moves), 
                std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::white_pawn_start]), 
                std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::white_pawn_start])
            );
            checkForBlockingPieces(start);
        }
        else
        {
            _legal_moves.insert(
                std::end(_legal_moves), 
                std::begin(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::white_pawn]), 
                std::end(Piece::container()->legalMoves()->legal_moves[Piece::position()][PieceMoves::MoveDirections::white_pawn])
            );
            checkForBlockingPieces(start);
        }
    }
    std::cout << "legal moves: ";
    for (int i : _legal_moves) std::cout << i << " ";
    std::cout << "\n";
}

void Pawn::update()
{
    calculateLegalMoves();
}

std::vector<int> Pawn::legalMoves() const
{
    return _legal_moves;
}