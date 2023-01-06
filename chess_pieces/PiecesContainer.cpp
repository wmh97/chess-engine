#include "PiecesContainer.h"
#include "Rook.h"

PiecesContainer::PiecesContainer(std::unique_ptr<PieceMoves::LegalMovesMap> legal_moves):
    _legal_moves{std::move(legal_moves)}
{}

std::vector<std::shared_ptr<IPiece>> PiecesContainer::allPieces() const
{
    return _all_pieces;
}

PieceMoves::LegalMovesMap* PiecesContainer::legalMoves() const
{
    return _legal_moves.get();
}

std::shared_ptr<IPiece> PiecesContainer::makePiece(std::shared_ptr<PiecesContainer> container, PieceType piece_type, PieceColour colour, int position)
{
    switch(piece_type)
    {
        case(PieceType::rook):
        {
            auto blackRook {std::make_shared<Rook>(container, colour, position)};
            _all_pieces.push_back(blackRook);
            notifyOfPieceAdded();
            return blackRook;
            break;
        }
    }
    return nullptr;
}

void PiecesContainer::notifyOfPieceAdded()
{
    for (const auto& p : _all_pieces)
    {
        p->calculateLegalMoves();
    }
}