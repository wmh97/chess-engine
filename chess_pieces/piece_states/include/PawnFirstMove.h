#ifndef PAWN_FIRST_MOVE_H
#define PAWN_FIRST_MOVE_H

#include "IPieceState.h"
#include "PiecesContainer.h"

class PawnFirstMove : public IPieceState
{
public:
    PawnFirstMove() = default;
    std::pair<std::vector<int>, std::unique_ptr<IPieceState>> updateState(PiecesContainer* container, IPieceFactory::PieceType type, IPieceFactory::PieceColour colour, int position) override;
private:
    std::vector<int> calculateLegalMoves(PiecesContainer* container, IPieceFactory::PieceType type, IPieceFactory::PieceColour colour, int position);
    std::pair<std::vector<int>, std::size_t> checkForBlockingPieces(PiecesContainer* container, IPieceFactory::PieceColour colour, int position, std::vector<int> legal_moves, std::size_t start_index);
};

#endif