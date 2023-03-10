#include "ChessBoardBuilder.h"

#include <iostream>
#include <algorithm>
#include <numeric>
#include <fstream>

void ChessBoardBuilder::setPiece(IPiece* piece, bool show_legal_moves)
{
    switch(piece->type())
    {
        case(IPieceFactory::PieceType::rook):
        {
            if (piece->colour() == IPieceFactory::PieceColour::black)
            {
                _board_map[piece->position()] = "♜";
            }
            else if (piece->colour() == IPieceFactory::PieceColour::white)
            {
                _board_map[piece->position()] = "♖";
            }
            break;
        }
        case(IPieceFactory::PieceType::knight):
        {
            if (piece->colour() == IPieceFactory::PieceColour::black)
            {
                _board_map[piece->position()] = "♞";
            }
            else if (piece->colour() == IPieceFactory::PieceColour::white)
            {
                _board_map[piece->position()] = "♘";
            }
            break;
        }
        case(IPieceFactory::PieceType::bishop):
        {
            if (piece->colour() == IPieceFactory::PieceColour::black)
            {
                _board_map[piece->position()] = "♝";
            }
            else if (piece->colour() == IPieceFactory::PieceColour::white)
            {
                _board_map[piece->position()] = "♗";
            }
            break;
        }
        case(IPieceFactory::PieceType::king):
        {
            if (piece->colour() == IPieceFactory::PieceColour::black)
            {
                _board_map[piece->position()] = "♚";
            }
            else if (piece->colour() == IPieceFactory::PieceColour::white)
            {
                _board_map[piece->position()] = "♔";
            }
            break;
        }
        case(IPieceFactory::PieceType::queen):
        {
            if (piece->colour() == IPieceFactory::PieceColour::black)
            {
                _board_map[piece->position()] = "♛";
            }
            else if (piece->colour() == IPieceFactory::PieceColour::white)
            {
                _board_map[piece->position()] = "♕";
            }
            break;
        }
        case(IPieceFactory::PieceType::pawn):
        {
            if (piece->colour() == IPieceFactory::PieceColour::black)
            {
                _board_map[piece->position()] = "♟";
            }
            else if (piece->colour() == IPieceFactory::PieceColour::white)
            {
                _board_map[piece->position()] = "♙";
            }
            break;
        }
        default:
            break;
    }

    if (show_legal_moves)
    {
        auto legal_moves {piece->legalMoves()};
        _legal_moves.insert(std::end(_legal_moves), std::begin(legal_moves), std::end(legal_moves));
    }
}

std::string ChessBoardBuilder::getSquareColour(int row_number, int position) const
{
    // could be made more concise so that we dont need to pass row number and pos.
    
    std::string colour {};
    bool pos_is_legal_move {false};

    if (std::find(_legal_moves.begin(), _legal_moves.end(), position) != _legal_moves.end())
    {
        pos_is_legal_move = true;
    }

    if (row_number % 2 == 0) // even rows
    {
        if (position % 2 == 0)
        {
            if (pos_is_legal_move) return "legal_moves_dark";
            return "dark";
        }
        else
        {
            if (pos_is_legal_move) return "legal_moves_light";
            return "light";
        }
    }
    else
    {
        if (position % 2 == 0)
        {
            if (pos_is_legal_move) return "legal_moves_light";
            return "light";
        }
        else
        {
            if (pos_is_legal_move) return "legal_moves_dark";
            return "dark";
        }
    }
    return "";
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
    tdTagBldr1->setClassTag("td", getSquareColour(row_number, square_numbers[0]));
    tdTagBldr1->addTagContents(_board_map[square_numbers[0]]);
    
    auto tdTagBldr2 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr2->setClassTag("td", getSquareColour(row_number, square_numbers[1]));
    tdTagBldr2->addTagContents(_board_map[square_numbers[1]]);
    
    auto tdTagBldr3 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr3->setClassTag("td", getSquareColour(row_number, square_numbers[2]));
    tdTagBldr3->addTagContents(_board_map[square_numbers[2]]);
    
    auto tdTagBldr4 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr4->setClassTag("td", getSquareColour(row_number, square_numbers[3]));
    tdTagBldr4->addTagContents(_board_map[square_numbers[3]]);
    
    auto tdTagBldr5 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr5->setClassTag("td", getSquareColour(row_number, square_numbers[4]));
    tdTagBldr5->addTagContents(_board_map[square_numbers[4]]);
    
    auto tdTagBldr6 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr6->setClassTag("td", getSquareColour(row_number, square_numbers[5]));
    tdTagBldr6->addTagContents(_board_map[square_numbers[5]]);
    
    auto tdTagBldr7 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr7->setClassTag("td", getSquareColour(row_number, square_numbers[6]));
    tdTagBldr7->addTagContents(_board_map[square_numbers[6]]);
    
    auto tdTagBldr8 {std::make_unique<HtmlTagBuilder>()};
    tdTagBldr8->setClassTag("td", getSquareColour(row_number, square_numbers[7]));
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
    styleTagBldr->addTagContents(".chess-board .legal_moves_light { background: #FFFDD0; }");
    styleTagBldr->addTagContents(".chess-board .legal_moves_dark { background: #F0E68C; }");
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