#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "PiecesContainer.h"

#include <memory>

class Pawn : public Piece
{
public:
    Pawn(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position);
    void move(int position) override;
    void update() override;
    std::vector<int> legalMoves() const override;
private:
    bool _first_move {true};

    std::vector<int> _legal_moves {};

    void calculateLegalMoves();
    std::size_t checkForBlockingPieces(std::size_t start_index);
};

#endif