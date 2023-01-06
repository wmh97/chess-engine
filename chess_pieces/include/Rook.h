#ifndef ROOK_H
#define ROOK_H

#include "PieceInterfaces.h"
#include "PiecesContainer.h"

#include <memory>

class Rook : public IPiece
{
public:
    Rook(std::shared_ptr<PiecesContainer> pieces_container, IPieceFactory::PieceColour colour, int position);
    void move(int position) override;
    int position() const override;
    void calculateLegalMoves() override;
    std::vector<int> legalMoves() const;
    IPieceFactory::PieceType type() const override;
    IPieceFactory::PieceColour colour() const override;
private:
    const IPieceFactory::PieceType _type {IPieceFactory::PieceType::rook};
    IPieceFactory::PieceColour _colour;
    
    std::shared_ptr<PiecesContainer> _container;
    int _position;
    std::vector<int> _legal_moves;

    std::size_t checkForBlockingPieces(std::size_t start_index);
};

#endif