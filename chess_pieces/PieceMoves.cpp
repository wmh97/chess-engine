#include "PieceMoves.h"

using namespace PieceMoves;

int PieceMoves::calculateSquaresAbove(int position) noexcept
{
    int count {};
    while (position > 0)
    {
        position -= 8;
        count++;
    }
    return count;
}

int PieceMoves::calculateSquaresBelow(int position) noexcept
{
    int count {};
    while (position <= 56)
    {
        position += 8;
        count++;
    }
    return count;
}

int PieceMoves::calculateSquaresToLeft(int position) noexcept
{
    return (position % 8) == 0 ? 7 : (position % 8) - 1;
}

int PieceMoves::calculateSquaresToRight(int position) noexcept
{
    return (position % 8) == 0 ? 0 : 8 - (position % 8);
}

std::vector<int> PieceMoves::calculateUpLeftDiagonalLegalMoves(int position) noexcept
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

std::vector<int> PieceMoves::calculateUpRightDiagonalLegalMoves(int position) noexcept
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

std::vector<int> PieceMoves::calculateDownLeftDiagonalLegalMoves(int position) noexcept
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

std::vector<int> PieceMoves::calculateDownRightDiagonalLegalMoves(int position) noexcept
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

std::vector<int> PieceMoves::calculateLegalMovesUp(int position) noexcept
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

std::vector<int> PieceMoves::calculateLegalMovesDown(int position) noexcept
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

std::vector<int> PieceMoves::calculateLegalMovesLeft(int position) noexcept
{
    std::vector<int> legal_moves {};
    int squaresToLeft {calculateSquaresToLeft(position)};
    for (int i = 1; i <= squaresToLeft; i++)
    {
        legal_moves.push_back(position - i);
    }
    return legal_moves;
}

std::vector<int> PieceMoves::calculateLegalMovesRight(int position) noexcept
{
    std::vector<int> legal_moves {};
    int squaresToRight {calculateSquaresToRight(position)};
    for (int i = 1; i <= squaresToRight; i++)
    {
        legal_moves.push_back(position + i);
    }
    return legal_moves;
}


std::vector<int> PieceMoves::calculateKnightLegalMoves(int position) noexcept
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

std::vector<int> PieceMoves::calculateBlackPawnLegalMoves(int position) noexcept
{
    std::vector<int> legal_moves {};
    if (position <= 56) legal_moves.push_back(position+8);
    // diagonals
    if (calculateSquaresToLeft(position) >= 1) legal_moves.push_back(position+7);
    if (calculateSquaresToRight(position) >= 1) legal_moves.push_back(position+9);
    return legal_moves;
}

std::vector<int> PieceMoves::calculateBlackPawnLegalStartMoves(int position) noexcept
{
    std::vector<int> legal_moves {};
    if (position >= 9 && position <= 16) // black pawn start pos.
    {
        auto standard_legal_moves {calculateBlackPawnLegalMoves(position)};
        legal_moves.insert(std::end(legal_moves), std::begin(standard_legal_moves), std::end(standard_legal_moves));
        legal_moves.insert(std::begin(legal_moves)+1, position+16);        
    }
    return legal_moves;
}

std::vector<int> PieceMoves::calculateWhitePawnLegalMoves(int position) noexcept
{
    std::vector<int> legal_moves {};
    if (position >= 9) legal_moves.push_back(position-8);
    // diagonals
    if (calculateSquaresToLeft(position) >= 1) legal_moves.push_back(position-9);
    if (calculateSquaresToRight(position) >= 1) legal_moves.push_back(position-7);
    return legal_moves;   
}

std::vector<int> PieceMoves::calculateWhitePawnLegalStartMoves(int position) noexcept
{
    std::vector<int> legal_moves {};
    if (position >= 9 && position <= 16) // black pawn start pos.
    {
        auto standard_legal_moves {calculateWhitePawnLegalMoves(position)};
        legal_moves.insert(std::end(legal_moves), std::begin(standard_legal_moves), std::end(standard_legal_moves));
        legal_moves.insert(std::begin(legal_moves)+1, position-16);        
    }
    return legal_moves;
}

std::vector<int> PieceMoves::calculateKingLegalMoves(int position) noexcept
{
    std::vector<int> legal_moves {};

    int squares_to_left {calculateSquaresToLeft(position)};
    int squares_to_right {calculateSquaresToRight(position)};
    int squares_above {calculateSquaresAbove(position)};
    int squares_below {calculateSquaresBelow(position)};
    
    // up
    if (squares_above >= 1) legal_moves.push_back(position-8);
    // down
    if (squares_below >= 1) legal_moves.push_back(position+8);
    // left
    if (squares_to_left >= 1) legal_moves.push_back(position-1);
    // right
    if (squares_to_right >= 1) legal_moves.push_back(position+1);

    // left up: -9
    if (squares_to_left >= 1 && squares_above >= 1) legal_moves.push_back(position-9);
    // left down: +7
    if (squares_to_left >= 1 && squares_below >= 1) legal_moves.push_back(position+7);
    // right up: -7
    if (squares_to_right >= 1 && squares_above >= 1) legal_moves.push_back(position-7);
    // right down: +9
    if (squares_to_right >= 1 && squares_below >= 1) legal_moves.push_back(position+9);

    return legal_moves;
}