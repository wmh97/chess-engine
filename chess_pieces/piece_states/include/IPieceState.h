#ifndef IPIECE_STATE_H
#define IPIECE_STATE_H

#include "PiecesContainer.h"

#include <utility>
#include <vector>
#include <memory>

class IPieceState
{
public:
    virtual std::pair<std::vector<int>, std::unique_ptr<IPieceState>> updateState(PiecesContainer* container, IPieceFactory::PieceType type, IPieceFactory::PieceColour colour, int position) = 0;
};

#endif