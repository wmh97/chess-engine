#include "PiecesContainer.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"

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
            auto piece {std::make_shared<Rook>(container, colour, position)};
            _all_pieces.push_back(piece);
            notifyOfPieceAdded();
            return piece;
            break;
        }
        case(PieceType::knight):
        {
            auto piece {std::make_shared<Knight>(container, colour, position)};
            _all_pieces.push_back(piece);
            notifyOfPieceAdded();
            return piece;
            break;
        }
        case(PieceType::bishop):
        {
            auto piece {std::make_shared<Bishop>(container, colour, position)};
            _all_pieces.push_back(piece);
            notifyOfPieceAdded();
            return piece;
            break;
        }
        case(PieceType::king):
        {
            auto piece {std::make_shared<Rook>(container, colour, position)};
            _all_pieces.push_back(piece);
            notifyOfPieceAdded();
            return piece;
            break;
        }
        case(PieceType::queen):
        {
            auto piece {std::make_shared<Rook>(container, colour, position)};
            _all_pieces.push_back(piece);
            notifyOfPieceAdded();
            return piece;
            break;
        }
        case(PieceType::pawn):
        {
            auto piece {std::make_shared<Rook>(container, colour, position)};
            _all_pieces.push_back(piece);
            notifyOfPieceAdded();
            return piece;
            break;
        }
    }
    return nullptr;
}

void PiecesContainer::notifyOfPieceAdded()
{
    for (const auto& p : _all_pieces)
    {
        p->update();
    }
}