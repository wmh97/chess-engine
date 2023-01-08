#ifndef QUEEN_H
#define QUEEN_H

#include "PiecesContainer.h"
#include "Rook.h"
#include "Bishop.h"

#include <memory>

class Queen : public Piece
{
public:
    Queen(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position);
    void update() override;
    std::vector<int> legalMoves() const override;
private:
    std::shared_ptr<PiecesContainer> _container;
    std::vector<int> _legal_moves {};

    void calculateLegalMoves();
    std::size_t checkForBlockingPieces(std::size_t start_index);
};

#endif