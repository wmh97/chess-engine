#include "PieceMoves.h"
#include "PiecesContainer.h"
#include "ChessBoardBuilder.h"

#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::cout << "Hello world!\n";

    static std::map<int, std::map<PieceMoves::MoveDirections, std::vector<int>>> legal_moves {};

    for (int i=1; i<=64; i++)
    {
        legal_moves[i][PieceMoves::MoveDirections::up] = PieceMoves::calculateLegalMovesUp(i);
        legal_moves[i][PieceMoves::MoveDirections::down] = PieceMoves::calculateLegalMovesDown(i);
        legal_moves[i][PieceMoves::MoveDirections::left] = PieceMoves::calculateLegalMovesLeft(i);
        legal_moves[i][PieceMoves::MoveDirections::right] = PieceMoves::calculateLegalMovesRight(i);
        legal_moves[i][PieceMoves::MoveDirections::left_up] = PieceMoves::calculateUpLeftDiagonalLegalMoves(i);
        legal_moves[i][PieceMoves::MoveDirections::left_down] = PieceMoves::calculateDownLeftDiagonalLegalMoves(i);
        legal_moves[i][PieceMoves::MoveDirections::right_up] = PieceMoves::calculateUpRightDiagonalLegalMoves(i);
        legal_moves[i][PieceMoves::MoveDirections::right_down] = PieceMoves::calculateDownRightDiagonalLegalMoves(i);
        legal_moves[i][PieceMoves::MoveDirections::knight] = PieceMoves::calculateKnightLegalMoves(i);
        legal_moves[i][PieceMoves::MoveDirections::black_pawn] = PieceMoves::calculateBlackPawnLegalMoves(i);
        legal_moves[i][PieceMoves::MoveDirections::white_pawn] = PieceMoves::calculateWhitePawnLegalMoves(i);
    }

    auto legalMoves {std::make_unique<PieceMoves::LegalMovesMap>(legal_moves)};
    auto piecesContainer = std::make_shared<PiecesContainer>(std::move(legalMoves));

    auto blackRook = piecesContainer->makePiece(PiecesContainer::PieceType::black_rook, piecesContainer, 30);
    auto otherPiece = piecesContainer->makePiece(PiecesContainer::PieceType::black_rook, piecesContainer, 54);

    ChessBoardBuilder boardBldr {};

    boardBldr.setBlackRook(blackRook.get());
    boardBldr.setBlackPawn(54);

    // boardBldr.setBlackRook(8);

    // boardBldr.setBlackKnight(2);
    // boardBldr.setBlackKnight(7);

    // boardBldr.setBlackBishop(3);
    // boardBldr.setBlackBishop(6);

    // boardBldr.setBlackKing(4);
    // boardBldr.setBlackQueen(5);

    // boardBldr.setBlackPawn(9);
    // boardBldr.setBlackPawn(10);
    // boardBldr.setBlackPawn(11);
    // boardBldr.setBlackPawn(12);
    // boardBldr.setBlackPawn(13);
    // boardBldr.setBlackPawn(14);
    // boardBldr.setBlackPawn(15);
    // boardBldr.setBlackPawn(16);

    // boardBldr.setWhiteRook(57);
    // boardBldr.setWhiteRook(64);

    // boardBldr.setWhiteKnight(58);
    // boardBldr.setWhiteKnight(63);

    // boardBldr.setWhiteBishop(59);
    // boardBldr.setWhiteBishop(62);

    // boardBldr.setWhiteQueen(60);

    // boardBldr.setWhiteKing(61);

    // boardBldr.setWhitePawn(49);
    // boardBldr.setWhitePawn(50);
    // boardBldr.setWhitePawn(51);
    // boardBldr.setWhitePawn(52);
    // boardBldr.setWhitePawn(53);
    // boardBldr.setWhitePawn(54);
    // boardBldr.setWhitePawn(55);
    // boardBldr.setWhitePawn(56);

    boardBldr.createBoard();
    
    boardBldr.outputBoard();

    std::cout << "Finished!";
    return 0;
}