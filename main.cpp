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

    auto blackRook1 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::rook, IPieceFactory::PieceColour::black, 1);
    // auto blackRook2 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::rook, IPieceFactory::PieceColour::black, 8);
    auto blackKnight1 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::knight, IPieceFactory::PieceColour::black, 2);
    // auto blackKnight2 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::knight, IPieceFactory::PieceColour::black, 7);
    auto blackBishop1 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::bishop, IPieceFactory::PieceColour::black, 3);
    // auto blackBishop2 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::bishop, IPieceFactory::PieceColour::black, 6);
    // auto blackKing = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::king, IPieceFactory::PieceColour::black, 4);
    auto blackQueen = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::queen, IPieceFactory::PieceColour::black, 5);
    // auto blackPawn1 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::black, 9);
    // auto blackPawn2 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::black, 10);
    // auto blackPawn3 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::black, 11);
    // auto blackPawn4 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::black, 12);
    // auto blackPawn5 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::black, 13);
    // auto blackPawn6 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::black, 14);
    // auto blackPawn7 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::black, 15);
    // auto blackPawn8 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::black, 16);

    auto whiteRook1 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::rook, IPieceFactory::PieceColour::white, 57);
    // auto whiteRook2 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::rook, IPieceFactory::PieceColour::white, 64);
    auto whiteKnight1 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::knight, IPieceFactory::PieceColour::white, 58);
    // auto whiteKnight2 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::knight, IPieceFactory::PieceColour::white, 63);
    auto whiteBishop1 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::bishop, IPieceFactory::PieceColour::white, 59);
    // auto whiteBishop2 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::bishop, IPieceFactory::PieceColour::white, 62);
    // auto whiteKing = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::king, IPieceFactory::PieceColour::white, 61);
    auto whiteQueen = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::queen, IPieceFactory::PieceColour::white, 60);
    // auto whitePawn1 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::white, 49);
    // auto whitePawn2 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::white, 50);
    // auto whitePawn3 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::white, 51);
    // auto whitePawn4 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::white, 52);
    // auto whitePawn5 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::white, 53);
    // auto whitePawn6 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::white, 54);
    // auto whitePawn7 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::white, 55);
    // auto whitePawn8 = piecesContainer->makePiece(piecesContainer, IPieceFactory::PieceType::pawn, IPieceFactory::PieceColour::white, 56);

    whiteQueen->move(61);
    blackRook1->move(57);

    ChessBoardBuilder boardBldr {};

    for (const auto& piece : piecesContainer->allPieces())
    {
        boardBldr.setPiece(piece.get(), true);
    }

    // boardBldr.setPiece(blackRook1.get(), true);
    // boardBldr.setPiece(blackRook2.get(), true);
    // boardBldr.setPiece(blackKnight1.get(), true);
    // boardBldr.setPiece(blackKnight2.get());
    // boardBldr.setPiece(blackBishop1.get(), true);
    // boardBldr.setPiece(blackBishop2.get());
    // boardBldr.setPiece(blackKing.get());
    // boardBldr.setPiece(blackQueen.get(), true);
    // boardBldr.setPiece(blackPawn1.get());
    // boardBldr.setPiece(blackPawn2.get());
    // boardBldr.setPiece(blackPawn3.get());
    // boardBldr.setPiece(blackPawn4.get(), true);
    // boardBldr.setPiece(blackPawn5.get());
    // boardBldr.setPiece(blackPawn6.get());
    // boardBldr.setPiece(blackPawn7.get());
    // boardBldr.setPiece(blackPawn8.get());

    // boardBldr.setPiece(whiteRook1.get(), true);
    // boardBldr.setPiece(whiteRook2.get());
    // boardBldr.setPiece(whiteKnight1.get(), true);
    // boardBldr.setPiece(whiteKnight2.get());
    // boardBldr.setPiece(whiteBishop1.get(), true);
    // boardBldr.setPiece(whiteBishop2.get());
    // boardBldr.setPiece(whiteKing.get());
    // boardBldr.setPiece(whiteQueen.get(), true);
    // boardBldr.setPiece(whitePawn1.get());
    // boardBldr.setPiece(whitePawn2.get());
    // boardBldr.setPiece(whitePawn3.get());
    // boardBldr.setPiece(whitePawn4.get());
    // boardBldr.setPiece(whitePawn5.get());
    // boardBldr.setPiece(whitePawn6.get());
    // boardBldr.setPiece(whitePawn7.get());
    // boardBldr.setPiece(whitePawn8.get());

    boardBldr.createBoard();
    boardBldr.outputBoard();

    std::cout << "Finished!";
    return 0;
}