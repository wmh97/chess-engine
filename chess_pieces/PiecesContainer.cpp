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

std::shared_ptr<IPiece> PiecesContainer::makePiece(PieceType piece_type, std::shared_ptr<PiecesContainer> container, int position)
{
    switch(piece_type)
    {
        case(PieceType::black_rook):
        {
            auto blackRook {std::make_shared<Rook>(container, position)};
            _all_pieces.push_back(blackRook);
            notifyOfPieceAdded();
            return blackRook;
            break;
        }
        case(PieceType::black_knight):
            break;
        case(PieceType::black_bishop):
            break;
        case(PieceType::black_king):
            break;
        case(PieceType::black_queen):
            break;
        case(PieceType::black_pawn):
            break;
        case(PieceType::white_rook):
        {
            auto whiteRook {std::make_shared<Rook>(container, position)};
            _all_pieces.push_back(whiteRook);
            notifyOfPieceAdded();
            return whiteRook;
            break;
        }
        case(PieceType::white_knight):
            break;
        case(PieceType::white_bishop):
            break;
        case(PieceType::white_king):
            break;
        case(PieceType::white_queen):
            break;
        case(PieceType::white_pawn):
            break;
        default:
            break;
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