#include "ChessBoardHtmlBuilder.h"
#include "HtmlTagBuilder.h"

#include <iostream>

void ChessBoardHtmlBuilder::setBlackRook(int position1, int position2)
{
    _board_map[position1] = "♜";
    _board_map[position2] = "♜";
}

void ChessBoardHtmlBuilder::setBlackKnight(int position1, int position2)
{
    _board_map[position1] = "♞";
    _board_map[position2] = "♞";   
}

void ChessBoardHtmlBuilder::setBlackBishop(int position1, int position2)
{
    _board_map[position1] = "♝";
    _board_map[position2] = "♝";  
}

void ChessBoardHtmlBuilder::setBlackKing(int position)
{
    _board_map[position] = "♛";  
}

void ChessBoardHtmlBuilder::setBlackQueen(int position)
{
    _board_map[position] = "♚";  
}

void ChessBoardHtmlBuilder::setBlackPawn(int position1,
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

void ChessBoardHtmlBuilder::setWhiteRook(int position1, int position2)
{
    _board_map[position1] = "♖";
    _board_map[position2] = "♖";
}

void ChessBoardHtmlBuilder::setWhiteKnight(int position1, int position2)
{
    _board_map[position1] = "♘";
    _board_map[position2] = "♘";
}

void ChessBoardHtmlBuilder::setWhiteBishop(int position1, int position2)
{
    _board_map[position1] = "♗";
    _board_map[position2] = "♗";
}

void ChessBoardHtmlBuilder::setWhiteKing(int position)
{
    _board_map[position] = "♔"; 
}

void ChessBoardHtmlBuilder::setWhiteQueen(int position)
{
    _board_map[position] = "♕"; 
}

void ChessBoardHtmlBuilder::setWhitePawn(int position1,
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

void ChessBoardHtmlBuilder::createBoard()
{
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
    tdTagBldr1.addTagContents(_board_map[1]);
    HtmlTagBuilder tdTagBldr2 {};
    tdTagBldr2.setClassTag("td", "dark");
    tdTagBldr2.addTagContents(_board_map[2]);
    HtmlTagBuilder tdTagBldr3 {};
    tdTagBldr3.setClassTag("td", "light");
    tdTagBldr3.addTagContents(_board_map[3]);
    HtmlTagBuilder tdTagBldr4 {};
    tdTagBldr4.setClassTag("td", "dark");
    tdTagBldr4.addTagContents(_board_map[4]);
    HtmlTagBuilder tdTagBldr5 {};
    tdTagBldr5.setClassTag("td", "light");
    tdTagBldr5.addTagContents(_board_map[5]);
    HtmlTagBuilder tdTagBldr6 {};
    tdTagBldr6.setClassTag("td", "dark");
    tdTagBldr6.addTagContents(_board_map[6]);
    HtmlTagBuilder tdTagBldr7 {};
    tdTagBldr7.setClassTag("td", "light");
    tdTagBldr7.addTagContents(_board_map[7]);
    HtmlTagBuilder tdTagBldr8 {};
    tdTagBldr8.setClassTag("td", "dark");
    tdTagBldr8.addTagContents(_board_map[8]);
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
    tdTagBldr9.addTagContents(_board_map[9]);
    HtmlTagBuilder tdTagBldr10 {};
    tdTagBldr10.setClassTag("td", "light");
    tdTagBldr10.addTagContents(_board_map[10]);
    HtmlTagBuilder tdTagBldr11 {};
    tdTagBldr11.setClassTag("td", "dark");
    tdTagBldr11.addTagContents(_board_map[11]);
    HtmlTagBuilder tdTagBldr12 {};
    tdTagBldr12.setClassTag("td", "light");
    tdTagBldr12.addTagContents(_board_map[12]);
    HtmlTagBuilder tdTagBldr13 {};
    tdTagBldr13.setClassTag("td", "dark");
    tdTagBldr13.addTagContents(_board_map[13]);
    HtmlTagBuilder tdTagBldr14 {};
    tdTagBldr14.setClassTag("td", "light");
    tdTagBldr14.addTagContents(_board_map[14]);
    HtmlTagBuilder tdTagBldr15 {};
    tdTagBldr15.setClassTag("td", "dark");
    tdTagBldr15.addTagContents(_board_map[15]);
    HtmlTagBuilder tdTagBldr16 {};
    tdTagBldr16.setClassTag("td", "light");
    tdTagBldr16.addTagContents(_board_map[16]);
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
    tdTagBldr17.addTagContents(_board_map[17]);
    HtmlTagBuilder tdTagBldr18 {};
    tdTagBldr18.setClassTag("td", "dark");
    tdTagBldr18.addTagContents(_board_map[18]);
    HtmlTagBuilder tdTagBldr19 {};
    tdTagBldr19.setClassTag("td", "light");
    tdTagBldr19.addTagContents(_board_map[19]);
    HtmlTagBuilder tdTagBldr20 {};
    tdTagBldr20.setClassTag("td", "dark");
    tdTagBldr20.addTagContents(_board_map[20]);
    HtmlTagBuilder tdTagBldr21 {};
    tdTagBldr21.setClassTag("td", "light");
    tdTagBldr21.addTagContents(_board_map[21]);
    HtmlTagBuilder tdTagBldr22 {};
    tdTagBldr22.setClassTag("td", "dark");
    tdTagBldr22.addTagContents(_board_map[22]);
    HtmlTagBuilder tdTagBldr23 {};
    tdTagBldr23.setClassTag("td", "light");
    tdTagBldr23.addTagContents(_board_map[23]);
    HtmlTagBuilder tdTagBldr24 {};
    tdTagBldr24.setClassTag("td", "dark");
    tdTagBldr24.addTagContents(_board_map[24]);
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
    tdTagBldr25.addTagContents(_board_map[25]);
    HtmlTagBuilder tdTagBldr26 {};
    tdTagBldr26.setClassTag("td", "light");
    tdTagBldr26.addTagContents(_board_map[26]);
    HtmlTagBuilder tdTagBldr27 {};
    tdTagBldr27.setClassTag("td", "dark");
    tdTagBldr27.addTagContents(_board_map[27]);
    HtmlTagBuilder tdTagBldr28 {};
    tdTagBldr28.setClassTag("td", "light");
    tdTagBldr28.addTagContents(_board_map[28]);
    HtmlTagBuilder tdTagBldr29 {};
    tdTagBldr29.setClassTag("td", "dark");
    tdTagBldr29.addTagContents(_board_map[29]);
    HtmlTagBuilder tdTagBldr30 {};
    tdTagBldr30.setClassTag("td", "light");
    tdTagBldr30.addTagContents(_board_map[30]);
    HtmlTagBuilder tdTagBldr31 {};
    tdTagBldr31.setClassTag("td", "dark");
    tdTagBldr31.addTagContents(_board_map[31]);
    HtmlTagBuilder tdTagBldr32 {};
    tdTagBldr32.setClassTag("td", "light");
    tdTagBldr32.addTagContents(_board_map[32]);
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
    tdTagBldr33.addTagContents(_board_map[33]);
    HtmlTagBuilder tdTagBldr34 {};
    tdTagBldr34.setClassTag("td", "dark");
    tdTagBldr34.addTagContents(_board_map[34]);
    HtmlTagBuilder tdTagBldr35 {};
    tdTagBldr35.setClassTag("td", "light");
    tdTagBldr35.addTagContents(_board_map[35]);
    HtmlTagBuilder tdTagBldr36 {};
    tdTagBldr36.setClassTag("td", "dark");
    tdTagBldr36.addTagContents(_board_map[36]);
    HtmlTagBuilder tdTagBldr37 {};
    tdTagBldr37.setClassTag("td", "light");
    tdTagBldr37.addTagContents(_board_map[37]);
    HtmlTagBuilder tdTagBldr38 {};
    tdTagBldr38.setClassTag("td", "dark");
    tdTagBldr38.addTagContents(_board_map[38]);
    HtmlTagBuilder tdTagBldr39 {};
    tdTagBldr39.setClassTag("td", "light");
    tdTagBldr39.addTagContents(_board_map[39]);
    HtmlTagBuilder tdTagBldr40 {};
    tdTagBldr40.setClassTag("td", "dark");
    tdTagBldr40.addTagContents(_board_map[40]);
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
    tdTagBldr41.addTagContents(_board_map[41]);
    HtmlTagBuilder tdTagBldr42 {};
    tdTagBldr42.setClassTag("td", "light");
    tdTagBldr42.addTagContents(_board_map[42]);
    HtmlTagBuilder tdTagBldr43 {};
    tdTagBldr43.setClassTag("td", "dark");
    tdTagBldr43.addTagContents(_board_map[43]);
    HtmlTagBuilder tdTagBldr44 {};
    tdTagBldr44.setClassTag("td", "light");
    tdTagBldr44.addTagContents(_board_map[44]);
    HtmlTagBuilder tdTagBldr45 {};
    tdTagBldr45.setClassTag("td", "dark");
    tdTagBldr45.addTagContents(_board_map[45]);
    HtmlTagBuilder tdTagBldr46 {};
    tdTagBldr46.setClassTag("td", "light");
    tdTagBldr46.addTagContents(_board_map[46]);
    HtmlTagBuilder tdTagBldr47 {};
    tdTagBldr47.setClassTag("td", "dark");
    tdTagBldr47.addTagContents(_board_map[47]);
    HtmlTagBuilder tdTagBldr48 {};
    tdTagBldr48.setClassTag("td", "light");
    tdTagBldr48.addTagContents(_board_map[48]);
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
    tdTagBldr49.addTagContents(_board_map[49]);
    HtmlTagBuilder tdTagBldr50 {};
    tdTagBldr50.setClassTag("td", "dark");
    tdTagBldr50.addTagContents(_board_map[50]);
    HtmlTagBuilder tdTagBldr51 {};
    tdTagBldr51.setClassTag("td", "light");
    tdTagBldr51.addTagContents(_board_map[51]);
    HtmlTagBuilder tdTagBldr52 {};
    tdTagBldr52.setClassTag("td", "dark");
    tdTagBldr52.addTagContents(_board_map[52]);
    HtmlTagBuilder tdTagBldr53 {};
    tdTagBldr53.setClassTag("td", "light");
    tdTagBldr53.addTagContents(_board_map[53]);
    HtmlTagBuilder tdTagBldr54 {};
    tdTagBldr54.setClassTag("td", "dark");
    tdTagBldr54.addTagContents(_board_map[54]);
    HtmlTagBuilder tdTagBldr55 {};
    tdTagBldr55.setClassTag("td", "light");
    tdTagBldr55.addTagContents(_board_map[55]);
    HtmlTagBuilder tdTagBldr56 {};
    tdTagBldr56.setClassTag("td", "dark");
    tdTagBldr56.addTagContents(_board_map[56]);
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
    tdTagBldr57.addTagContents(_board_map[57]);
    HtmlTagBuilder tdTagBldr58 {};
    tdTagBldr58.setClassTag("td", "light");
    tdTagBldr58.addTagContents(_board_map[58]);
    HtmlTagBuilder tdTagBldr59 {};
    tdTagBldr59.setClassTag("td", "dark");
    tdTagBldr59.addTagContents(_board_map[59]);
    HtmlTagBuilder tdTagBldr60 {};
    tdTagBldr60.setClassTag("td", "light");
    tdTagBldr60.addTagContents(_board_map[60]);
    HtmlTagBuilder tdTagBldr61 {};
    tdTagBldr61.setClassTag("td", "dark");
    tdTagBldr61.addTagContents(_board_map[61]);
    HtmlTagBuilder tdTagBldr62 {};
    tdTagBldr62.setClassTag("td", "light");
    tdTagBldr62.addTagContents(_board_map[62]);
    HtmlTagBuilder tdTagBldr63 {};
    tdTagBldr63.setClassTag("td", "dark");
    tdTagBldr63.addTagContents(_board_map[63]);
    HtmlTagBuilder tdTagBldr64 {};
    tdTagBldr64.setClassTag("td", "light");
    tdTagBldr64.addTagContents(_board_map[64]);
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

    _board_html = htmlTagBldr.buildTag();
}

void ChessBoardHtmlBuilder::printBoard()
{
    std::cout << "\n" << _board_html << "\n";
}