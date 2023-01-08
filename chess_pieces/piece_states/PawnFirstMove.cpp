#include "PawnFirstMove.h"

std::pair<std::vector<int>, std::unique_ptr<IPieceState>> PawnFirstMove::updateState(PiecesContainer* container, IPieceFactory::PieceType type, IPieceFactory::PieceColour colour, int position)
{
    return std::pair<std::vector<int>, std::unique_ptr<IPieceState>> {calculateLegalMoves(container, type, colour, position), nullptr}; // should return next pawn state - TODO
}

std::vector<int> PawnFirstMove::calculateLegalMoves(PiecesContainer* container, IPieceFactory::PieceType type, IPieceFactory::PieceColour colour, int position)
{
    // need to make legal moves more easily accessible
    std::vector<int> legal_moves {};
    std::size_t start {legal_moves.size()};

    if (colour == IPieceFactory::PieceColour::black)
    {
        legal_moves.insert(
            std::end(legal_moves), 
            std::begin(container->legalMoves()->legal_moves[position][PieceMoves::MoveDirections::black_pawn_start]), 
            std::end(container->legalMoves()->legal_moves[position][PieceMoves::MoveDirections::black_pawn_start])
        );
    }
    else if (colour == IPieceFactory::PieceColour::white)
    {
        legal_moves.insert(
            std::end(legal_moves), 
            std::begin(container->legalMoves()->legal_moves[position][PieceMoves::MoveDirections::white_pawn_start]), 
            std::end(container->legalMoves()->legal_moves[position][PieceMoves::MoveDirections::white_pawn_start])
        );
    }

    auto adjusted_legal_moves {checkForBlockingPieces(container, colour, position, legal_moves, start)};
    legal_moves = adjusted_legal_moves.first;
    start = adjusted_legal_moves.second; // not used... but will be for other impls.

    return legal_moves;
}

std::pair<std::vector<int>, std::size_t> PawnFirstMove::checkForBlockingPieces(PiecesContainer* container, IPieceFactory::PieceColour colour, int position, std::vector<int> legal_moves, std::size_t start_index)
{
    for (std::size_t i {start_index}; i<legal_moves.size(); i++)
    {   
        for (const auto& piece : container->allPieces())
        {
            if (legal_moves[i] == piece->position())
            {
                if (piece->colour() != colour)
                {
                    legal_moves.resize(i+1);
                    return std::pair<std::vector<int>, std::size_t> {legal_moves, i+1};
                }
                legal_moves.resize(i);
                return std::pair<std::vector<int>, std::size_t> {legal_moves, i};
            }
            else if (legal_moves[i] == position+9 || legal_moves[i] == position-9 || legal_moves[i] == position+7 || legal_moves[i] == position-7)
            {
                // if there is no piece on the legal move and the legal move is a diagonal,
                legal_moves.resize(i+1);
                return std::pair<std::vector<int>, std::size_t> {legal_moves, i+1};
            }
        }
    }
    return std::pair<std::vector<int>, std::size_t> {legal_moves, legal_moves.size()};
}