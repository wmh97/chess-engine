#include <iostream>
#include <vector>
#include <map>
#include <array>

namespace PieceMoves
{
    static int calculateSquaresAbove(int position) noexcept
    {
        int count {};
        while (position > 0)
        {
            position -= 8;
            count++;
        }
        return count;
    }

    static int calculateSquaresBelow(int position) noexcept
    {
        int count {};
        while (position <= 56)
        {
            position += 8;
            count++;
        }
        return count;
    }
 
    static int calculateSquaresToLeft(int position) noexcept
    {
        return (position % 8) == 0 ? 7 : (position % 8) - 1;
    }

    static int calculateSquaresToRight(int position) noexcept
    {
        return (position % 8) == 0 ? 0 : 8 - (position % 8);
    }

    // constexpr std::array<std::array<int,max_legal_moves>,num_board_squares> test_legal_moves {};

    // // static constexpr int num_board_squares {64};
    // // static constexpr int max_legal_moves {32}; // TODO: calc this.
    // // static constexpr std::array<std::array<int,max_legal_moves>,num_board_squares> generateLegalMoveArrays(bool vertical, bool horizontal, bool diagonal)
    // // {
    // //     constexpr std::array<std::array<int,max_legal_moves>,num_board_squares> legal_moves {};
    // //     for (int square=1; square<=num_board_squares; square++)
    // //     {
    // //         int legal_move {square};
    // //         int legal_move_count {0};

    // //         // calc all legal moves for that sq.
    // //         if (vertical)
    // //         {
    // //             int squares_above {calculateSquaresAbove(square)};
    // //             int squares_below {calculateSquaresBelow(square)};
    // //             for (int above=0; above<squares_above; above++)
    // //             {
    // //                 legal_moves[square][legal_move_count] = square - (above*8);
    // //                 legal_move_count++;
    // //             }
    // //             for (int below=0; below<squares_below; below++)
    // //             {
    // //                 legal_moves[square][legal_move_count] = square + (below*8);
    // //                 legal_move_count++;
    // //             }
    // //         }
    // //         if (horizontal)
    // //         {
    // //             int squares_left {calculateSquaresToLeft(square)};
    // //             int squares_right {calculateSquaresToRight(square)};
    // //             for (int left=0; left<squares_left; left++)
    // //             {
    // //                 legal_moves[square][legal_move_count] = legal_move-left;
    // //                 legal_move_count++;
    // //             }
    // //             for (int right=0; right<squares_right; right++)
    // //             {
    // //                 legal_moves[square][legal_move_count] = legal_move+right;
    // //                 legal_move_count++;
    // //             }
    // //         }
    // //         if (diagonal)
    // //         {

    // //         }
    // //     }
    // //     return legal_moves;
    // // }

    // static std::vector<int> calculateDiagonalLegalMoves(int position)
    // {
    //     std::vector<int> legal_moves {};
    //     int legalMove {position};
    //     int squaresToLeft {calculateSquaresToLeft(position)};
    //     int squaresToRight {calculateSquaresToRight(position)};
    //     // left diagonals: -9, +7
    //     for (int i = 1; i <= squaresToLeft; i++)
    //     {
    //         int leftUp = legalMove - 9*i;
    //         if (leftUp > 0) legal_moves.push_back(leftUp);
    //     }
    //     for (int i = 1; i <= squaresToLeft; i++)
    //     {
    //         int leftDown = legalMove + 7*i;
    //         if (leftDown < 64) legal_moves.push_back(leftDown);
    //     }
    //     // right diagonals: +9, -7
    //     for (int i = 1; i <= squaresToRight; i++)
    //     {
    //         int rightUp = legalMove - 7*i;
    //         if (rightUp > 0) legal_moves.push_back(rightUp);
    //     }
    //     for (int i = 1; i <= squaresToRight; i++)
    //     {
    //         int rightDown = legalMove + 9*i;
    //         if (rightDown <= 64) legal_moves.push_back(rightDown);
            
    //     }
    //     return legal_moves;
    // }

    static std::vector<int> calculateUpLeftDiagonalLegalMoves(int position)
    {
        std::vector<int> legal_moves {};
        int legalMove {position};
        int squaresToLeft {calculateSquaresToLeft(position)};
        for (int i = 1; i <= squaresToLeft; i++)
        {
            int leftUp = legalMove - 9*i;
            if (leftUp > 0) legal_moves.push_back(leftUp);
        }
        return legal_moves;
    }

    static std::vector<int> calculateUpRightDiagonalLegalMoves(int position)
    {
        std::vector<int> legal_moves {};
        int legalMove {position};
        int squaresToRight {calculateSquaresToRight(position)};
        for (int i = 1; i <= squaresToRight; i++)
        {
            int rightUp = legalMove - 7*i;
            if (rightUp > 0) legal_moves.push_back(rightUp);
        }
        return legal_moves;
    }

    static std::vector<int> calculateDownLeftDiagonalLegalMoves(int position)
    {
        std::vector<int> legal_moves {};
        int legalMove {position};
        int squaresToLeft {calculateSquaresToLeft(position)};
        for (int i = 1; i <= squaresToLeft; i++)
        {
            int leftDown = legalMove + 7*i;
            if (leftDown < 64) legal_moves.push_back(leftDown);
        }
        return legal_moves;
    }

    static std::vector<int> calculateDownRightDiagonalLegalMoves(int position)
    {
        std::vector<int> legal_moves {};
        int legalMove {position};
        int squaresToRight {calculateSquaresToRight(position)};
        for (int i = 1; i <= squaresToRight; i++)
        {
            int rightDown = legalMove + 9*i;
            if (rightDown <= 64) legal_moves.push_back(rightDown);
        }
        return legal_moves;
    }

    // static std::vector<int> calculateVerticalLegalMoves(int position)
    // {
    //     std::vector<int> legal_moves {};
    //     int legalMove {position};
    //     while (legalMove <= 56)
    //     {
    //         legalMove += 8;
    //         legal_moves.push_back(legalMove);
    //     }
    //     legalMove = position;
    //     while (legalMove > 8)
    //     {
    //         legalMove -= 8;
    //         legal_moves.push_back(legalMove);
    //     }
    //     return legal_moves;
    // }

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

    static std::vector<int> calculateLegalMovesUp(int position)
    {
        std::vector<int> legal_moves {};
        int legalMove {position};
        while (legalMove > 8)
        {
            legalMove -= 8;
            legal_moves.push_back(legalMove);
        }
        return legal_moves;
    }

    static std::vector<int> calculateLegalMovesDown(int position)
    {
        std::vector<int> legal_moves {};
        int legalMove {position};
        while (legalMove <= 56)
        {
            legalMove += 8;
            legal_moves.push_back(legalMove);
        }
        return legal_moves;
    }

    static std::vector<int> calculateLegalMovesLeft(int position)
    {
        std::vector<int> legal_moves {};
        int squaresToLeft {calculateSquaresToLeft(position)};
        for (int i = 1; i <= squaresToLeft; i++)
        {
            legal_moves.push_back(position - i);
        }
        return legal_moves;
    }

    static std::vector<int> calculateLegalMovesRight(int position)
    {
        std::vector<int> legal_moves {};
        int squaresToRight {calculateSquaresToRight(position)};
        for (int i = 1; i <= squaresToRight; i++)
        {
            legal_moves.push_back(position + i);
        }
        return legal_moves;
    }


    static std::vector<int> calculateKnightLegalMoves(int position)
    {
        std::vector<int> legal_moves {};
        
        int squaresToLeft = calculateSquaresToLeft(position);
        int squaresToRight = calculateSquaresToRight(position);
        int squaresAbove = calculateSquaresAbove(position);
        int squaresBelow = calculateSquaresBelow(position);
        
        // right up 1
        int legalMove {position - 15};
        if (legalMove > 0 && legalMove <= 64 && squaresAbove >= 2 && squaresToRight >= 1)
        {
            legal_moves.push_back(legalMove);
        }

        // right up 2
        legalMove = position - 6;
        if (legalMove > 0 && legalMove <= 64 && squaresAbove >= 1 && squaresToRight >= 2)
        {
            legal_moves.push_back(legalMove);
        }

        // right down 1
        legalMove = position + 10;
        if (legalMove > 0 && legalMove <= 64 && squaresBelow >= 1 && squaresToRight >= 2)
        {
            legal_moves.push_back(legalMove);
        }

        // right down 2
        legalMove = position + 17;
        if (legalMove > 0 && legalMove <= 64 && squaresBelow >= 2 && squaresToRight >= 1)
        {
            legal_moves.push_back(legalMove);
        }

        // left up 1
        legalMove = position - 17;
        if (legalMove > 0 && legalMove <= 64 && squaresAbove >= 2 && squaresToLeft >= 1)
        {
            legal_moves.push_back(legalMove); 
        }

        // left up 2
        legalMove = position - 10;
        if (legalMove > 0 && legalMove <= 64 && squaresAbove >= 1 && squaresToLeft >= 2)
        {
            legal_moves.push_back(legalMove);
        }

        // left down 1
        legalMove = position + 6;
        if (legalMove > 0 && legalMove <= 64 && squaresBelow >= 1 && squaresToLeft >= 2)
        {
            legal_moves.push_back(legalMove);
        }

        // left down 2
        legalMove = position + 15;
        if (legalMove > 0 && legalMove <= 64 && squaresBelow >= 2 && squaresToLeft >= 1)
        {
            legal_moves.push_back(legalMove); 
        }
        return legal_moves;
    }

    static std::vector<int> calculateBlackPawnLegalMoves(int position)
    {
        std::vector<int> legal_moves {};
        if (position <= 56) legal_moves.push_back(position+8);
        // diagonals
        if (calculateSquaresToLeft(position) >= 1) legal_moves.push_back(position+7);
        if (calculateSquaresToRight(position) >= 1) legal_moves.push_back(position+9);
        return legal_moves;
    }

    static std::vector<int> calculateWhitePawnLegalMoves(int position)
    {
        std::vector<int> legal_moves {};
        if (position >= 9) legal_moves.push_back(position-8);
        // diagonals
        if (calculateSquaresToLeft(position) >= 1) legal_moves.push_back(position-9);
        if (calculateSquaresToRight(position) >= 1) legal_moves.push_back(position-7);
        return legal_moves;   
    }
    // static std::vector<int> calculateHorizontalLegalMoves(int position)
    // {
    //     std::vector<int> legal_moves {};
    //     int squaresToLeft {calculateSquaresToLeft(position)};
    //     int squaresToRight {calculateSquaresToRight(position)};
    //     for (int i = 1; i <= squaresToLeft; i++)
    //     {
    //         legal_moves.push_back(position - i);
    //     }
    //     for (int i = 1; i <= squaresToRight; i++)
    //     {
    //         legal_moves.push_back(position + i);
    //     }
    //     return legal_moves;
    // }
}

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

    std::cout << "Finished!";
    return 0;
}