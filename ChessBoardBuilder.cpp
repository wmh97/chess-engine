#include "ChessBoardBuilder.h"

#include <numeric>
#include <fstream>

void ChessBoardBuilder::setBlackRook(int position1, int position2)
{
    _board_map[position1] = "♜";
    _board_map[position2] = "♜";
}

void ChessBoardBuilder::setBlackKnight(int position1, int position2)
{
    _board_map[position1] = "♞";
    _board_map[position2] = "♞";   
}

void ChessBoardBuilder::setBlackBishop(int position1, int position2)
{
    _board_map[position1] = "♝";
    _board_map[position2] = "♝";  
}

void ChessBoardBuilder::setBlackKing(int position)
{
    _board_map[position] = "♛";  
}

void ChessBoardBuilder::setBlackQueen(int position)
{
    _board_map[position] = "♚";  
}

void ChessBoardBuilder::setBlackPawn(int position1,
                                                 int position2,
                                                 int position3,
                                                 int position4,
                                                 int position5,
                                                 int position6,
                                                 int position7,
                                                 int position8)
{
    _board_map[position1] = "♟";
    _board_map[position2] = "♟"; 
    _board_map[position3] = "♟";
    _board_map[position4] = "♟"; 
    _board_map[position5] = "♟";
    _board_map[position6] = "♟"; 
    _board_map[position7] = "♟";
    _board_map[position8] = "♟"; 
}

void ChessBoardBuilder::setWhiteRook(int position1, int position2)
{
    _board_map[position1] = "♖";
    _board_map[position2] = "♖";
}

void ChessBoardBuilder::setWhiteKnight(int position1, int position2)
{
    _board_map[position1] = "♘";
    _board_map[position2] = "♘";
}

void ChessBoardBuilder::setWhiteBishop(int position1, int position2)
{
    _board_map[position1] = "♗";
    _board_map[position2] = "♗";
}

void ChessBoardBuilder::setWhiteKing(int position)
{
    _board_map[position] = "♔"; 
}

void ChessBoardBuilder::setWhiteQueen(int position)
{
    _board_map[position] = "♕"; 
}

void ChessBoardBuilder::setWhitePawn(int position1,
                                                 int position2,
                                                 int position3,
                                                 int position4,
                                                 int position5,
                                                 int position6,
                                                 int position7,
                                                 int position8)
{
    _board_map[position1] = "♙";
    _board_map[position2] = "♙"; 
    _board_map[position3] = "♙";
    _board_map[position4] = "♙"; 
    _board_map[position5] = "♙";
    _board_map[position6] = "♙"; 
    _board_map[position7] = "♙";
    _board_map[position8] = "♙"; 
}

std::unique_ptr<HtmlTagBuilder> ChessBoardBuilder::buildRow(int row_number)
{
    std::string square_colour1 {};
    std::string square_colour2 {};
    if (row_number % 2 == 0) // even rows
    {
        square_colour1 = "light";
        square_colour2 = "dark";
    }
    else
    {
        square_colour1 = "dark";
        square_colour2 = "light";
    }

    std::vector<int> square_numbers(8);
    switch (row_number)
    {
        case(8):
            std::iota(std::begin(square_numbers), std::end(square_numbers), 1); 
            break;
        case(7):
            std::iota(std::begin(square_numbers), std::end(square_numbers), 9); 
            break;
        case(6):
            std::iota(std::begin(square_numbers), std::end(square_numbers), 17); 
            break;
        case(5):
            std::iota(std::begin(square_numbers), std::end(square_numbers), 25); 
            break;
        case(4):
            std::iota(std::begin(square_numbers), std::end(square_numbers), 33); 
            break;  
        case(3):
            std::iota(std::begin(square_numbers), std::end(square_numbers), 41); 
            break;
        case(2):
            std::iota(std::begin(square_numbers), std::end(square_numbers), 49); 
            break;
        case(1):
            std::iota(std::begin(square_numbers), std::end(square_numbers), 57); 
            break;
        default:
            break;
    }

    auto trTagBldr {std::make_unique<HtmlTagBuilder>()};
    trTagBldr->setTagType("tr");
    
    auto thTagBldr {std::make_unique<HtmlTagBuilder>()};
    thTagBldr->setTagType("th");
    thTagBldr->addTagContents(std::to_string(row_number));
    
    auto tdTagBldr1 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr1->setClassTag("td", square_colour1);
    tdTagBldr1->addTagContents(_board_map[square_numbers[0]]);
    
    auto tdTagBldr2 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr2->setClassTag("td", square_colour2);
    tdTagBldr2->addTagContents(_board_map[square_numbers[1]]);
    
    auto tdTagBldr3 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr3->setClassTag("td", square_colour1);
    tdTagBldr3->addTagContents(_board_map[square_numbers[2]]);
    
    auto tdTagBldr4 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr4->setClassTag("td", square_colour2);
    tdTagBldr4->addTagContents(_board_map[square_numbers[3]]);
    
    auto tdTagBldr5 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr5->setClassTag("td", square_colour1);
    tdTagBldr5->addTagContents(_board_map[square_numbers[4]]);
    
    auto tdTagBldr6 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr6->setClassTag("td", square_colour2);
    tdTagBldr6->addTagContents(_board_map[square_numbers[5]]);
    
    auto tdTagBldr7 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr7->setClassTag("td", square_colour1);
    tdTagBldr7->addTagContents(_board_map[square_numbers[6]]);
    
    auto tdTagBldr8 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr8->setClassTag("td", square_colour2);
    tdTagBldr8->addTagContents(_board_map[square_numbers[7]]);
    
    trTagBldr->addEmbeddedTag(std::move(thTagBldr));
    trTagBldr->addEmbeddedTag(std::move(tdTagBldr1));
    trTagBldr->addEmbeddedTag(std::move(tdTagBldr2));
    trTagBldr->addEmbeddedTag(std::move(tdTagBldr3));
    trTagBldr->addEmbeddedTag(std::move(tdTagBldr4));
    trTagBldr->addEmbeddedTag(std::move(tdTagBldr5));
    trTagBldr->addEmbeddedTag(std::move(tdTagBldr6));
    trTagBldr->addEmbeddedTag(std::move(tdTagBldr7));
    trTagBldr->addEmbeddedTag(std::move(tdTagBldr8));
    
    return std::move(trTagBldr);
}

void ChessBoardBuilder::createBoard()
{
    auto htmlTagBldr {std::make_unique<HtmlTagBuilder>()};
    htmlTagBldr->setTagType("html");

    auto headTagBldr {std::make_unique<HtmlTagBuilder>()};
    headTagBldr->setTagType("head");
    headTagBldr->addMetaData("charset", "UTF-8");
    auto titleTagBldr {std::make_unique<HtmlTagBuilder>()};
    titleTagBldr->setTagType("title");
    auto styleTagBldr {std::make_unique<HtmlTagBuilder>()};
    styleTagBldr->setTagType("style");
    styleTagBldr->addTagContents(".chess-board { border-spacing: 0; border-collapse: collapse; }");
    styleTagBldr->addTagContents(".chess-board th { padding: .5em; }");
    styleTagBldr->addTagContents(".chess-board th + th { border-bottom: 1px solid #000; }");
    styleTagBldr->addTagContents(".chess-board th:first-child,");
    styleTagBldr->addTagContents(".chess-board td:last-child { border-right: 1px solid #000; }");
    styleTagBldr->addTagContents(".chess-board tr:last-child td { border-bottom: 1px solid; }");
    styleTagBldr->addTagContents(".chess-board th:empty { border: none; }");
    styleTagBldr->addTagContents(".chess-board td { width: 1.5em; height: 1.5em; text-align: center; font-size: 32px; line-height: 0;}");
    styleTagBldr->addTagContents(".chess-board .light { background: #eee; }");
    styleTagBldr->addTagContents(".chess-board .dark { background: #aaa; }");
    styleTagBldr->addTagContents(".chess-board .legal_moves { background: #fffdd0; }");
    headTagBldr->addEmbeddedTag(std::move(titleTagBldr));
    headTagBldr->addEmbeddedTag(std::move(styleTagBldr));

    htmlTagBldr->addEmbeddedTag(std::move(headTagBldr));

    auto bodyTagBldr {std::make_unique<HtmlTagBuilder>()};
    bodyTagBldr->setTagType("body");

    auto tableTagBldr {std::make_unique<HtmlTagBuilder>()};
    tableTagBldr->setClassTag("table", "chess-board");

    auto tbodyTagBldr {std::make_unique<HtmlTagBuilder>()};
    
    auto trTagBldr {std::make_unique<HtmlTagBuilder>()};
    trTagBldr->setTagType("tr");

    auto thTagBldr {std::make_unique<HtmlTagBuilder>()};
    thTagBldr->setTagType("th");
    
    auto thTagBldrA {std::make_unique<HtmlTagBuilder>()};
    thTagBldrA->setTagType("th");
    thTagBldrA->addTagContents("a");
    
    auto thTagBldrB {std::make_unique<HtmlTagBuilder>()};
    thTagBldrB->setTagType("th");
    thTagBldrB->addTagContents("b");
    
    auto thTagBldrC {std::make_unique<HtmlTagBuilder>()};
    thTagBldrC->setTagType("th");
    thTagBldrC->addTagContents("c");
    
    auto thTagBldrD {std::make_unique<HtmlTagBuilder>()};
    thTagBldrD->setTagType("th");
    thTagBldrD->addTagContents("d");
    
    auto thTagBldrE {std::make_unique<HtmlTagBuilder>()};
    thTagBldrE->setTagType("th");
    thTagBldrE->addTagContents("e");
    
    auto thTagBldrF {std::make_unique<HtmlTagBuilder>()};
    thTagBldrF->setTagType("th");
    thTagBldrF->addTagContents("f");
    
    auto thTagBldrG {std::make_unique<HtmlTagBuilder>()};
    thTagBldrG->setTagType("th");
    thTagBldrG->addTagContents("g");
    
    auto thTagBldrH {std::make_unique<HtmlTagBuilder>()};
    thTagBldrH->setTagType("th");
    thTagBldrH->addTagContents("h");
    trTagBldr->addEmbeddedTag(std::move(thTagBldr));
    trTagBldr->addEmbeddedTag(std::move(thTagBldrA));
    trTagBldr->addEmbeddedTag(std::move(thTagBldrB));
    trTagBldr->addEmbeddedTag(std::move(thTagBldrC));
    trTagBldr->addEmbeddedTag(std::move(thTagBldrD));
    trTagBldr->addEmbeddedTag(std::move(thTagBldrE));
    trTagBldr->addEmbeddedTag(std::move(thTagBldrF));
    trTagBldr->addEmbeddedTag(std::move(thTagBldrG));
    trTagBldr->addEmbeddedTag(std::move(thTagBldrH));
    tbodyTagBldr->addEmbeddedTag(std::move(trTagBldr));

    auto trTagBldr2 {buildRow(8)};
    tbodyTagBldr->addEmbeddedTag(std::move(trTagBldr2));

    auto trTagBldr3 {buildRow(7)};
    tbodyTagBldr->addEmbeddedTag(std::move(trTagBldr3));
    
    auto trTagBldr4 {buildRow(6)};
    tbodyTagBldr->addEmbeddedTag(std::move(trTagBldr4));

    auto trTagBldr5 {buildRow(5)};
    tbodyTagBldr->addEmbeddedTag(std::move(trTagBldr5));

    auto trTagBldr6 {buildRow(4)};
    tbodyTagBldr->addEmbeddedTag(std::move(trTagBldr6));

    auto trTagBldr7 {buildRow(3)};
    tbodyTagBldr->addEmbeddedTag(std::move(trTagBldr7));

    auto trTagBldr8 {buildRow(2)};
    tbodyTagBldr->addEmbeddedTag(std::move(trTagBldr8));

    auto trTagBldr9 {buildRow(1)};
    tbodyTagBldr->addEmbeddedTag(std::move(trTagBldr9));

    tableTagBldr->addEmbeddedTag(std::move(tbodyTagBldr));
    bodyTagBldr->addEmbeddedTag(std::move(tableTagBldr));
    htmlTagBldr->addEmbeddedTag(std::move(bodyTagBldr));

    _board_html += htmlTagBldr->buildTag();
}

void ChessBoardBuilder::outputBoard()
{
    std::ofstream outfile {"chess_board.html", std::ios::app};
    if (outfile.is_open())
    {
        outfile << _board_html;
        outfile.close();
    }
}