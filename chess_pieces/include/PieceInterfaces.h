#ifndef PIECE_INTERFACES_H
#define PIECE_INTERFACES_H

class IPiece
{
public:
    virtual ~IPiece() = default;
    virtual void calculateLegalMoves() = 0;
    virtual void move(int position) = 0;
};

#endif