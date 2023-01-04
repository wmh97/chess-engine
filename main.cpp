#include <iostream>
#include <vector>
#include <map>

#include "HtmlTagBuilder.h"

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

    HtmlTagBuilder htmlTagBldr {};
    htmlTagBldr.setTagType("html");

    HtmlTagBuilder headTagBldr {};
    headTagBldr.setTagType("head");
    headTagBldr.addMetaData("charset", "UTF-8");
    HtmlTagBuilder titleTagBldr {};
    titleTagBldr.setTagType("title");
    HtmlTagBuilder styleTagBldr {};
    styleTagBldr.setTagType("style");
    styleTagBldr.addTagContents(".chess-board { border-spacing: 0; border-collapse: collapse; }");
    styleTagBldr.addTagContents(".chess-board th { padding: .5em; }");
    styleTagBldr.addTagContents(".chess-board th + th { border-bottom: 1px solid #000; }");
    styleTagBldr.addTagContents(".chess-board th:first-child,");
    styleTagBldr.addTagContents(".chess-board td:last-child { border-right: 1px solid #000; }");
    styleTagBldr.addTagContents(".chess-board tr:last-child td { border-bottom: 1px solid; }");
    styleTagBldr.addTagContents(".chess-board th:empty { border: none; }");
    styleTagBldr.addTagContents(".chess-board td { width: 1.5em; height: 1.5em; text-align: center; font-size: 32px; line-height: 0;}");
    styleTagBldr.addTagContents(".chess-board .light { background: #eee; }");
    styleTagBldr.addTagContents(".chess-board .dark { background: #aaa; }");
    headTagBldr.addEmbeddedTag(&titleTagBldr);
    headTagBldr.addEmbeddedTag(&styleTagBldr);

    htmlTagBldr.addEmbeddedTag(&headTagBldr);

    HtmlTagBuilder bodyTagBldr {};
    bodyTagBldr.setTagType("body");

    HtmlTagBuilder tableTagBldr {};
    tableTagBldr.setClassTag("table", "chess-board");

    HtmlTagBuilder tbodyTagBldr {};
    
    HtmlTagBuilder trTagBldr {};
    trTagBldr.setTagType("tr");
    HtmlTagBuilder thTagBldr {};
    HtmlTagBuilder thTagBldrA {};
    thTagBldrA.setTagType("th");
    thTagBldrA.addTagContents("a");
    HtmlTagBuilder thTagBldrB {};
    thTagBldrB.setTagType("th");
    thTagBldrB.addTagContents("b");
    HtmlTagBuilder thTagBldrC {};
    thTagBldrC.setTagType("th");
    thTagBldrC.addTagContents("c");
    HtmlTagBuilder thTagBldrD {};
    thTagBldrD.setTagType("th");
    thTagBldrD.addTagContents("d");
    HtmlTagBuilder thTagBldrE {};
    thTagBldrE.setTagType("th");
    thTagBldrE.addTagContents("e");
    HtmlTagBuilder thTagBldrF {};
    thTagBldrF.setTagType("th");
    thTagBldrF.addTagContents("f");
    HtmlTagBuilder thTagBldrG {};
    thTagBldrG.setTagType("th");
    thTagBldrG.addTagContents("g");
    HtmlTagBuilder thTagBldrH {};
    thTagBldrH.setTagType("th");
    thTagBldrH.addTagContents("h");
    trTagBldr.addEmbeddedTag(&thTagBldr);
    trTagBldr.addEmbeddedTag(&thTagBldrA);
    trTagBldr.addEmbeddedTag(&thTagBldrB);
    trTagBldr.addEmbeddedTag(&thTagBldrC);
    trTagBldr.addEmbeddedTag(&thTagBldrD);
    trTagBldr.addEmbeddedTag(&thTagBldrE);
    trTagBldr.addEmbeddedTag(&thTagBldrF);
    trTagBldr.addEmbeddedTag(&thTagBldrG);
    trTagBldr.addEmbeddedTag(&thTagBldrH);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr);

    // row 8
    HtmlTagBuilder trTagBldr2 {};
    trTagBldr2.setTagType("tr");
    HtmlTagBuilder thTagBldr2 {};
    thTagBldr2.setTagType("th");
    thTagBldr2.addTagContents("8");
    HtmlTagBuilder tdTagBldrW1 {};
    tdTagBldrW1.setClassTag("td", "dark");
    tdTagBldrW1.addTagContents("♜");
    HtmlTagBuilder tdTagBldrW2 {};
    tdTagBldrW2.setClassTag("td", "light");
    tdTagBldrW2.addTagContents("♞");
    HtmlTagBuilder tdTagBldrW3 {};
    tdTagBldrW3.setClassTag("td", "dark");
    tdTagBldrW3.addTagContents("♝");
    HtmlTagBuilder tdTagBldrW4 {};
    tdTagBldrW4.setClassTag("td", "light");
    tdTagBldrW4.addTagContents("♛");
    HtmlTagBuilder tdTagBldrW5 {};
    tdTagBldrW5.setClassTag("td", "dark");
    tdTagBldrW5.addTagContents("♚");
    HtmlTagBuilder tdTagBldrW6 {};
    tdTagBldrW6.setClassTag("td", "light");
    tdTagBldrW6.addTagContents("♝");
    HtmlTagBuilder tdTagBldrW7 {};
    tdTagBldrW7.setClassTag("td", "dark");
    tdTagBldrW7.addTagContents("♞");
    HtmlTagBuilder tdTagBldrW8 {};
    tdTagBldrW8.setClassTag("td", "light");
    tdTagBldrW8.addTagContents("♜");
    trTagBldr2.addEmbeddedTag(&thTagBldr2);
    trTagBldr2.addEmbeddedTag(&tdTagBldrW1);
    trTagBldr2.addEmbeddedTag(&tdTagBldrW2);
    trTagBldr2.addEmbeddedTag(&tdTagBldrW3);
    trTagBldr2.addEmbeddedTag(&tdTagBldrW4);
    trTagBldr2.addEmbeddedTag(&tdTagBldrW5);
    trTagBldr2.addEmbeddedTag(&tdTagBldrW6);
    trTagBldr2.addEmbeddedTag(&tdTagBldrW7);
    trTagBldr2.addEmbeddedTag(&tdTagBldrW8);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr2);

    // row 7
    HtmlTagBuilder trTagBldr3 {};
    trTagBldr3.setTagType("tr");
    HtmlTagBuilder thTagBldr3 {};
    thTagBldr3.setTagType("th");
    thTagBldr3.addTagContents("7");
    HtmlTagBuilder tdTagBldrW9 {};
    tdTagBldrW9.setClassTag("td", "light");
    tdTagBldrW9.addTagContents("♜");
    HtmlTagBuilder tdTagBldrW10 {};
    tdTagBldrW10.setClassTag("td", "dark");
    tdTagBldrW10.addTagContents("♞");
    HtmlTagBuilder tdTagBldrW11 {};
    tdTagBldrW11.setClassTag("td", "light");
    tdTagBldrW11.addTagContents("♝");
    HtmlTagBuilder tdTagBldrW12 {};
    tdTagBldrW12.setClassTag("td", "dark");
    tdTagBldrW12.addTagContents("♛");
    HtmlTagBuilder tdTagBldrW13 {};
    tdTagBldrW13.setClassTag("td", "light");
    tdTagBldrW13.addTagContents("♚");
    HtmlTagBuilder tdTagBldrW14 {};
    tdTagBldrW14.setClassTag("td", "dark");
    tdTagBldrW14.addTagContents("♝");
    HtmlTagBuilder tdTagBldrW15 {};
    tdTagBldrW15.setClassTag("td", "light");
    tdTagBldrW15.addTagContents("♞");
    HtmlTagBuilder tdTagBldrW16 {};
    tdTagBldrW16.setClassTag("td", "dark");
    tdTagBldrW16.addTagContents("♜");
    trTagBldr3.addEmbeddedTag(&thTagBldr3);
    trTagBldr3.addEmbeddedTag(&tdTagBldrW9);
    trTagBldr3.addEmbeddedTag(&tdTagBldrW10);
    trTagBldr3.addEmbeddedTag(&tdTagBldrW11);
    trTagBldr3.addEmbeddedTag(&tdTagBldrW12);
    trTagBldr3.addEmbeddedTag(&tdTagBldrW13);
    trTagBldr3.addEmbeddedTag(&tdTagBldrW14);
    trTagBldr3.addEmbeddedTag(&tdTagBldrW15);
    trTagBldr3.addEmbeddedTag(&tdTagBldrW16);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr3);

    // row 6
    HtmlTagBuilder trTagBldr4 {};
    trTagBldr4.setTagType("tr");
    HtmlTagBuilder thTagBldr4 {};
    thTagBldr4.setTagType("th");
    thTagBldr4.addTagContents("7");
    HtmlTagBuilder tdTagBldr17 {};
    tdTagBldr17.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr18 {};
    tdTagBldr18.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr19 {};
    tdTagBldr19.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr20 {};
    tdTagBldr20.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr21 {};
    tdTagBldr21.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr22 {};
    tdTagBldr22.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr23 {};
    tdTagBldr23.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr24 {};
    tdTagBldr24.setClassTag("td", "light");
    trTagBldr4.addEmbeddedTag(&thTagBldr4);
    trTagBldr4.addEmbeddedTag(&tdTagBldr17);
    trTagBldr4.addEmbeddedTag(&tdTagBldr18);
    trTagBldr4.addEmbeddedTag(&tdTagBldr19);
    trTagBldr4.addEmbeddedTag(&tdTagBldr20);
    trTagBldr4.addEmbeddedTag(&tdTagBldr21);
    trTagBldr4.addEmbeddedTag(&tdTagBldr22);
    trTagBldr4.addEmbeddedTag(&tdTagBldr23);
    trTagBldr4.addEmbeddedTag(&tdTagBldr24);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr4);

    tableTagBldr.addEmbeddedTag(&tbodyTagBldr);
    bodyTagBldr.addEmbeddedTag(&tableTagBldr);
    htmlTagBldr.addEmbeddedTag(&bodyTagBldr);

    std::cout << htmlTagBldr.buildTag() << "\n";

    std::cout << "Finished!";
    return 0;
}