#ifndef PIECE_FACTORY_H
#define PIECE_FACTORY_H

#include "PieceMoves.h"
#include "PieceInterfaces.h"

#include <vector>
#include <map>

class PiecesContainer : public IPieceFactory
{
public:
    PiecesContainer(std::unique_ptr<PieceMoves::LegalMovesMap> legal_moves);

    std::shared_ptr<IPiece> makePiece(std::shared_ptr<PiecesContainer> container, IPieceFactory::PieceType piece_type, IPieceFactory::PieceColour colour, int position) override;

    std::vector<std::shared_ptr<IPiece>> allPieces() const;
    PieceMoves::LegalMovesMap* legalMoves() const;

private:
    std::vector<std::shared_ptr<IPiece>> _all_pieces {};
    std::unique_ptr<PieceMoves::LegalMovesMap> _legal_moves {};

    void notifyOfPieceAdded();
};

#endif