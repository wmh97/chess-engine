#ifndef PIECE_H
#define PIECE_H

#include "PieceInterfaces.h"
#include "PiecesContainer.h"

#include <memory>

class Piece : public IPiece
{
public:
    Piece(IPieceFactory::PieceType type, IPieceFactory::PieceColour colour, int position);
    void move(int position) override;
    int position() const override;
    IPieceFactory::PieceType type() const override;
    IPieceFactory::PieceColour colour() const override;
    
    virtual void update() override = 0;
    virtual std::vector<int> legalMoves() const override = 0;
private:  
    const IPieceFactory::PieceType _type;
    IPieceFactory::PieceColour _colour;
    int _position;
};

#endif