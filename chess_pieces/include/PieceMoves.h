#ifndef PIECE_MOVES_H
#define PIECE_MOVES_H

#include <vector>
#include <map>

namespace PieceMoves
{
    enum class MoveDirections
    {
        up,
        down,
        left,
        right,
        left_up,
        left_down,
        right_up,
        right_down,
        knight,
        black_pawn,
        white_pawn,
        black_pawn_start,
        white_pawn_start,
        black_pawn_enpassant,
        white_pawn_enapssant
    };
    
    extern int calculateSquaresAbove(int position) noexcept;
    extern int calculateSquaresBelow(int position) noexcept;
    extern int calculateSquaresToLeft(int position) noexcept;
    extern int calculateSquaresToRight(int position) noexcept;

    extern std::vector<int> calculateUpLeftDiagonalLegalMoves(int position) noexcept;
    extern std::vector<int> calculateUpRightDiagonalLegalMoves(int position) noexcept;
    extern std::vector<int> calculateDownLeftDiagonalLegalMoves(int position) noexcept;
    extern std::vector<int> calculateDownRightDiagonalLegalMoves(int position) noexcept;

    extern std::vector<int> calculateLegalMovesUp(int position) noexcept;
    extern std::vector<int> calculateLegalMovesDown(int position) noexcept;
    extern std::vector<int> calculateLegalMovesLeft(int position) noexcept;
    extern std::vector<int> calculateLegalMovesRight(int position) noexcept;

    extern std::vector<int> calculateKnightLegalMoves(int position) noexcept;
    extern std::vector<int> calculateBlackPawnLegalMoves(int position) noexcept;

    extern std::vector<int> calculateWhitePawnLegalMoves(int position) noexcept;

    // refactor into class
    struct LegalMovesMap
    {
        LegalMovesMap(std::map<int, std::map<PieceMoves::MoveDirections, std::vector<int>>> legal_moves) : legal_moves{legal_moves} {}
        std::map<int, std::map<PieceMoves::MoveDirections, std::vector<int>>> legal_moves {};
    };
}

#endif