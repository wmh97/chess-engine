#ifndef PIECE_H
#define PIECE_H

#include "PieceInterfaces.h"
#include "PiecesContainer.h"

#include <memory>

class Piece : public IPiece
{
public:
    Piece(std::shared_ptr<PiecesContainer> container, IPieceFactory::PieceType type, IPieceFactory::PieceColour colour, int position);
    virtual void move(int position) override;
    int position() const override;
    virtual IPieceFactory::PieceType type() const override;
    IPieceFactory::PieceColour colour() const override;
    
    PiecesContainer* container() const;

    virtual void update() override = 0;
    virtual std::vector<int> legalMoves() const override = 0;
private:  
    std::shared_ptr<PiecesContainer> _container;
    const IPieceFactory::PieceType _type;
    IPieceFactory::PieceColour _colour;
    int _position;
};

#endif