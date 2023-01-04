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
    thTagBldr.setTagType("th");
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
    HtmlTagBuilder tdTagBldr1 {};
    tdTagBldr1.setClassTag("td", "light");
    tdTagBldr1.addTagContents("♜");
    HtmlTagBuilder tdTagBldr2 {};
    tdTagBldr2.setClassTag("td", "dark");
    tdTagBldr2.addTagContents("♞");
    HtmlTagBuilder tdTagBldr3 {};
    tdTagBldr3.setClassTag("td", "light");
    tdTagBldr3.addTagContents("♝");
    HtmlTagBuilder tdTagBldr4 {};
    tdTagBldr4.setClassTag("td", "dark");
    tdTagBldr4.addTagContents("♛");
    HtmlTagBuilder tdTagBldr5 {};
    tdTagBldr5.setClassTag("td", "light");
    tdTagBldr5.addTagContents("♚");
    HtmlTagBuilder tdTagBldr6 {};
    tdTagBldr6.setClassTag("td", "dark");
    tdTagBldr6.addTagContents("♝");
    HtmlTagBuilder tdTagBldr7 {};
    tdTagBldr7.setClassTag("td", "light");
    tdTagBldr7.addTagContents("♞");
    HtmlTagBuilder tdTagBldr8 {};
    tdTagBldr8.setClassTag("td", "dark");
    tdTagBldr8.addTagContents("♜");
    trTagBldr2.addEmbeddedTag(&thTagBldr2);
    trTagBldr2.addEmbeddedTag(&tdTagBldr1);
    trTagBldr2.addEmbeddedTag(&tdTagBldr2);
    trTagBldr2.addEmbeddedTag(&tdTagBldr3);
    trTagBldr2.addEmbeddedTag(&tdTagBldr4);
    trTagBldr2.addEmbeddedTag(&tdTagBldr5);
    trTagBldr2.addEmbeddedTag(&tdTagBldr6);
    trTagBldr2.addEmbeddedTag(&tdTagBldr7);
    trTagBldr2.addEmbeddedTag(&tdTagBldr8);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr2);

    // row 7
    HtmlTagBuilder trTagBldr3 {};
    trTagBldr3.setTagType("tr");
    HtmlTagBuilder thTagBldr3 {};
    thTagBldr3.setTagType("th");
    thTagBldr3.addTagContents("7");
    HtmlTagBuilder tdTagBldr9 {};
    tdTagBldr9.setClassTag("td", "dark");
    tdTagBldr9.addTagContents("♟");
    HtmlTagBuilder tdTagBldr10 {};
    tdTagBldr10.setClassTag("td", "light");
    tdTagBldr10.addTagContents("♟");
    HtmlTagBuilder tdTagBldr11 {};
    tdTagBldr11.setClassTag("td", "dark");
    tdTagBldr11.addTagContents("♟");
    HtmlTagBuilder tdTagBldr12 {};
    tdTagBldr12.setClassTag("td", "light");
    tdTagBldr12.addTagContents("♟");
    HtmlTagBuilder tdTagBldr13 {};
    tdTagBldr13.setClassTag("td", "dark");
    tdTagBldr13.addTagContents("♟");
    HtmlTagBuilder tdTagBldr14 {};
    tdTagBldr14.setClassTag("td", "light");
    tdTagBldr14.addTagContents("♟");
    HtmlTagBuilder tdTagBldr15 {};
    tdTagBldr15.setClassTag("td", "dark");
    tdTagBldr15.addTagContents("♟");
    HtmlTagBuilder tdTagBldr16 {};
    tdTagBldr16.setClassTag("td", "light");
    tdTagBldr16.addTagContents("♟");
    trTagBldr3.addEmbeddedTag(&thTagBldr3);
    trTagBldr3.addEmbeddedTag(&tdTagBldr9);
    trTagBldr3.addEmbeddedTag(&tdTagBldr10);
    trTagBldr3.addEmbeddedTag(&tdTagBldr11);
    trTagBldr3.addEmbeddedTag(&tdTagBldr12);
    trTagBldr3.addEmbeddedTag(&tdTagBldr13);
    trTagBldr3.addEmbeddedTag(&tdTagBldr14);
    trTagBldr3.addEmbeddedTag(&tdTagBldr15);
    trTagBldr3.addEmbeddedTag(&tdTagBldr16);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr3);

    // row 6
    HtmlTagBuilder trTagBldr4 {};
    trTagBldr4.setTagType("tr");
    HtmlTagBuilder thTagBldr4 {};
    thTagBldr4.setTagType("th");
    thTagBldr4.addTagContents("6");
    HtmlTagBuilder tdTagBldr17 {};
    tdTagBldr17.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr18 {};
    tdTagBldr18.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr19 {};
    tdTagBldr19.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr20 {};
    tdTagBldr20.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr21 {};
    tdTagBldr21.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr22 {};
    tdTagBldr22.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr23 {};
    tdTagBldr23.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr24 {};
    tdTagBldr24.setClassTag("td", "dark");
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

    // row5
    HtmlTagBuilder trTagBldr5 {};
    trTagBldr5.setTagType("tr");
    HtmlTagBuilder thTagBldr5 {};
    thTagBldr5.setTagType("th");
    thTagBldr5.addTagContents("5");
    HtmlTagBuilder tdTagBldr25 {};
    tdTagBldr25.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr26 {};
    tdTagBldr26.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr27 {};
    tdTagBldr27.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr28 {};
    tdTagBldr28.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr29 {};
    tdTagBldr29.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr30 {};
    tdTagBldr30.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr31 {};
    tdTagBldr31.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr32 {};
    tdTagBldr32.setClassTag("td", "light");
    trTagBldr5.addEmbeddedTag(&thTagBldr5);
    trTagBldr5.addEmbeddedTag(&tdTagBldr25);
    trTagBldr5.addEmbeddedTag(&tdTagBldr26);
    trTagBldr5.addEmbeddedTag(&tdTagBldr27);
    trTagBldr5.addEmbeddedTag(&tdTagBldr28);
    trTagBldr5.addEmbeddedTag(&tdTagBldr29);
    trTagBldr5.addEmbeddedTag(&tdTagBldr30);
    trTagBldr5.addEmbeddedTag(&tdTagBldr31);
    trTagBldr5.addEmbeddedTag(&tdTagBldr32);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr5);

    // row 4
    HtmlTagBuilder trTagBldr6 {};
    trTagBldr6.setTagType("tr");
    HtmlTagBuilder thTagBldr6 {};
    thTagBldr6.setTagType("th");
    thTagBldr6.addTagContents("4");
    HtmlTagBuilder tdTagBldr33 {};
    tdTagBldr33.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr34 {};
    tdTagBldr34.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr35 {};
    tdTagBldr35.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr36 {};
    tdTagBldr36.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr37 {};
    tdTagBldr37.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr38 {};
    tdTagBldr38.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr39 {};
    tdTagBldr39.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr40 {};
    tdTagBldr40.setClassTag("td", "dark");
    trTagBldr6.addEmbeddedTag(&thTagBldr6);
    trTagBldr6.addEmbeddedTag(&tdTagBldr33);
    trTagBldr6.addEmbeddedTag(&tdTagBldr34);
    trTagBldr6.addEmbeddedTag(&tdTagBldr35);
    trTagBldr6.addEmbeddedTag(&tdTagBldr36);
    trTagBldr6.addEmbeddedTag(&tdTagBldr37);
    trTagBldr6.addEmbeddedTag(&tdTagBldr38);
    trTagBldr6.addEmbeddedTag(&tdTagBldr39);
    trTagBldr6.addEmbeddedTag(&tdTagBldr40);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr6);

    // row 3
    HtmlTagBuilder trTagBldr7 {};
    trTagBldr7.setTagType("tr");
    HtmlTagBuilder thTagBldr7 {};
    thTagBldr7.setTagType("th");
    thTagBldr7.addTagContents("3");
    HtmlTagBuilder tdTagBldr41 {};
    tdTagBldr41.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr42 {};
    tdTagBldr42.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr43 {};
    tdTagBldr43.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr44 {};
    tdTagBldr44.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr45 {};
    tdTagBldr45.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr46 {};
    tdTagBldr46.setClassTag("td", "light");
    HtmlTagBuilder tdTagBldr47 {};
    tdTagBldr47.setClassTag("td", "dark");
    HtmlTagBuilder tdTagBldr48 {};
    tdTagBldr48.setClassTag("td", "light");
    trTagBldr7.addEmbeddedTag(&thTagBldr7);
    trTagBldr7.addEmbeddedTag(&tdTagBldr41);
    trTagBldr7.addEmbeddedTag(&tdTagBldr42);
    trTagBldr7.addEmbeddedTag(&tdTagBldr43);
    trTagBldr7.addEmbeddedTag(&tdTagBldr44);
    trTagBldr7.addEmbeddedTag(&tdTagBldr45);
    trTagBldr7.addEmbeddedTag(&tdTagBldr46);
    trTagBldr7.addEmbeddedTag(&tdTagBldr47);
    trTagBldr7.addEmbeddedTag(&tdTagBldr48);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr7);

    // row 2
    HtmlTagBuilder trTagBldr8 {};
    trTagBldr8.setTagType("tr");
    HtmlTagBuilder thTagBldr8 {};
    thTagBldr8.setTagType("th");
    thTagBldr8.addTagContents("2");
    HtmlTagBuilder tdTagBldr49 {};
    tdTagBldr49.setClassTag("td", "light");
    tdTagBldr49.addTagContents("♙");
    HtmlTagBuilder tdTagBldr50 {};
    tdTagBldr50.setClassTag("td", "dark");
    tdTagBldr50.addTagContents("♙");
    HtmlTagBuilder tdTagBldr51 {};
    tdTagBldr51.setClassTag("td", "light");
    tdTagBldr51.addTagContents("♙");
    HtmlTagBuilder tdTagBldr52 {};
    tdTagBldr52.setClassTag("td", "dark");
    tdTagBldr52.addTagContents("♙");
    HtmlTagBuilder tdTagBldr53 {};
    tdTagBldr53.setClassTag("td", "light");
    tdTagBldr53.addTagContents("♙");
    HtmlTagBuilder tdTagBldr54 {};
    tdTagBldr54.setClassTag("td", "dark");
    tdTagBldr54.addTagContents("♙");
    HtmlTagBuilder tdTagBldr55 {};
    tdTagBldr55.setClassTag("td", "light");
    tdTagBldr55.addTagContents("♙");
    HtmlTagBuilder tdTagBldr56 {};
    tdTagBldr56.setClassTag("td", "dark");
    tdTagBldr56.addTagContents("♙");
    trTagBldr8.addEmbeddedTag(&thTagBldr8);
    trTagBldr8.addEmbeddedTag(&tdTagBldr49);
    trTagBldr8.addEmbeddedTag(&tdTagBldr50);
    trTagBldr8.addEmbeddedTag(&tdTagBldr51);
    trTagBldr8.addEmbeddedTag(&tdTagBldr52);
    trTagBldr8.addEmbeddedTag(&tdTagBldr53);
    trTagBldr8.addEmbeddedTag(&tdTagBldr54);
    trTagBldr8.addEmbeddedTag(&tdTagBldr55);
    trTagBldr8.addEmbeddedTag(&tdTagBldr56);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr8);

    // row 1
    HtmlTagBuilder trTagBldr9 {};
    trTagBldr9.setTagType("tr");
    HtmlTagBuilder thTagBldr9 {};
    thTagBldr9.setTagType("th");
    thTagBldr9.addTagContents("1");
    HtmlTagBuilder tdTagBldr57 {};
    tdTagBldr57.setClassTag("td", "dark");
    tdTagBldr57.addTagContents("♖");
    HtmlTagBuilder tdTagBldr58 {};
    tdTagBldr58.setClassTag("td", "light");
    tdTagBldr58.addTagContents("♘");
    HtmlTagBuilder tdTagBldr59 {};
    tdTagBldr59.setClassTag("td", "dark");
    tdTagBldr59.addTagContents("♗");
    HtmlTagBuilder tdTagBldr60 {};
    tdTagBldr60.setClassTag("td", "light");
    tdTagBldr60.addTagContents("♕");
    HtmlTagBuilder tdTagBldr61 {};
    tdTagBldr61.setClassTag("td", "dark");
    tdTagBldr61.addTagContents("♔");
    HtmlTagBuilder tdTagBldr62 {};
    tdTagBldr62.setClassTag("td", "light");
    tdTagBldr62.addTagContents("♗");
    HtmlTagBuilder tdTagBldr63 {};
    tdTagBldr63.setClassTag("td", "dark");
    tdTagBldr63.addTagContents("♘");
    HtmlTagBuilder tdTagBldr64 {};
    tdTagBldr64.setClassTag("td", "light");
    tdTagBldr64.addTagContents("♖");
    trTagBldr9.addEmbeddedTag(&thTagBldr9);
    trTagBldr9.addEmbeddedTag(&tdTagBldr57);
    trTagBldr9.addEmbeddedTag(&tdTagBldr58);
    trTagBldr9.addEmbeddedTag(&tdTagBldr59);
    trTagBldr9.addEmbeddedTag(&tdTagBldr60);
    trTagBldr9.addEmbeddedTag(&tdTagBldr61);
    trTagBldr9.addEmbeddedTag(&tdTagBldr62);
    trTagBldr9.addEmbeddedTag(&tdTagBldr63);
    trTagBldr9.addEmbeddedTag(&tdTagBldr64);
    tbodyTagBldr.addEmbeddedTag(&trTagBldr9);

    tableTagBldr.addEmbeddedTag(&tbodyTagBldr);
    bodyTagBldr.addEmbeddedTag(&tableTagBldr);
    htmlTagBldr.addEmbeddedTag(&bodyTagBldr);

    std::cout << htmlTagBldr.buildTag() << "\n";

    std::cout << "Finished!";
    return 0;
}