/***************************************************************
 * Name:      connect4Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dylan Taylor (aliendude5300@gmail.com)
 * Created:   2011-03-28
 * Copyright: Dylan Taylor (http://dylanmtaylor.com/)
 * License:
 **************************************************************/

#ifndef CONNECT4MAIN_H
#define CONNECT4MAIN_H

#include "connect4App.h"
#include "GUIFrame.h"
#include <vector>

struct Point  {
    Point() {}
    Point(int row, int col): row_(row), col_(col) {}
    int row_, col_;
};


class connect4Frame: public GUIFrame
{
    public:
        connect4Frame(wxFrame *frame);
        ~connect4Frame();
    private:
        bool playing;
        short board[6][7]; //pieces
        bool winningPiece[6][7]; //whether pieces are winning pieces or not
        void dropPiece(int column);
        void checkIfGameWon(int row, int column);
        bool checkForWinGivenBasePointAndDirection(int counter, int piece, Point location, Point &direction);
        void updateBoard();
        void switchPlayers();
        void clearBoard();
        int currentPlayer;
        void displayWinner(int player);
        void displayPostGameDebuggingInformation();
        void resetWinningPieces();
        void checkAllDirectionsFromBasePoint(int row, int column);
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void OnNew(wxCommandEvent& event);
        virtual void OnKeyPress(wxKeyEvent& event);
        virtual void OnDrop1(wxCommandEvent& event);
        virtual void OnDrop2(wxCommandEvent& event);
        virtual void OnDrop3(wxCommandEvent& event);
        virtual void OnDrop4(wxCommandEvent& event);
        virtual void OnDrop5(wxCommandEvent& event);
        virtual void OnDrop6(wxCommandEvent& event);
        virtual void OnDrop7(wxCommandEvent& event);
};
#endif // CONNECT4MAIN_H
