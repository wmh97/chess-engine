#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "PiecesContainer.h"

#include <memory>

class Knight : public Piece
{
public:
    Knight(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position);
    void update() override;
    std::vector<int> legalMoves() const override;
private:
    std::vector<int> _legal_moves {};

    void calculateLegalMoves();
    std::size_t checkForBlockingPieces(std::size_t start_index);
};

#endif