/***************************************************************
 * Name:      connect4Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dylan Taylor (aliendude5300@gmail.com)
 * Created:   2011-03-28
 * Copyright: Dylan Taylor (http://dylanmtaylor.com/)
 * License: Public Domain (attribution appreciated)
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "connect4Main.h"

Point directions[] = {
    Point(-1, 0),
    Point(-1, -1),
    Point(0, -1),
    Point(1, -1),
    Point(1, 0),
    Point(1, 1),
    Point(0, 1),
    Point(-1, 1)
};

connect4Frame::connect4Frame(wxFrame *frame) : GUIFrame(frame)
{
    playing = true;
    currentPlayer = 1;
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Welcome to Connect Four!"), 0);
    statusBar->SetStatusText(((currentPlayer == 1) ? _("Current Player: Player One") : _("Current Player: Player Two")), 1);
#endif
    clearBoard(); //clear the board when starting a new game
}

void connect4Frame::updateBoard() {
    wxBitmap grey(_T("grey.png"));
    wxBitmap orange(_T("orange.png"));
    wxBitmap brown(_T("brown.png"));
    for (int r = 0; r < 6; r++) {
        printf("Row %d: ", (r+1));
    	for (int c = 0; c < 7; c++) {
    	    printf("%d; ",board[r][c]);
            UpdatePiece(r,c,(board[r][c] == 0) ? grey : ((board[r][c] == 1) ? orange : brown));
    	}
    	printf("\n");
    }
    printf("\n");
}

void connect4Frame::displayWinner(int player) {
    switch (player) {
        case 1:
            statusBar->SetStatusText(_("Player One Won The Game!"), 1);
            printf("Winner: Player One\n");
            return;
        case 2:
            statusBar->SetStatusText(_("Player Two Won The Game!"), 1);
            printf("Winner: Player Two\n");
            return;
        default:
            statusBar->SetStatusText(_("Something went horribly wrong!"), 1);
            printf("Something went wrong...\n");
            return;
    }
    displayPostGameDebuggingInformation();
}

void connect4Frame::displayPostGameDebuggingInformation() {
    printf("\nX = winning piece; 0 = placeholder\n");
    for (int r = 0; r < 6; r++) {
        printf("Row %d: ", (r+1));
        for (int c = 0; c < 7; c++) {
            printf("%s; ",winningPiece[r][c] ? "X" : "0");
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void connect4Frame::resetWinningPieces() {
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 7; c++) {
            winningPiece[r][c] = false;
        }
    }
}

void connect4Frame::checkIfGameWon(int row, int col) {
    for (int r = 0; r < 6; r++) {
    	for (int c = 0; c < 7; c++) {
    	    if (board[row][col] == board[r][c]) {
                checkAllDirectionsFromBasePoint(r,c);
    	    }
    	}
    }
}

void connect4Frame::checkAllDirectionsFromBasePoint(int r, int c) {
    for (int d = 0; d < 8; d++) {
        if (checkForWinGivenBasePointAndDirection(0, board[r][c],Point(r,c),directions[d])) {
            playing = false;
            displayWinner(board[r][c]);
            return;
        } else resetWinningPieces();
    }
}

/**
Returns true if there are at least four consecutive pieces owned by the same player in any given direction
**/
bool connect4Frame::checkForWinGivenBasePointAndDirection(int counter, int piece, Point location, Point &direction) {
    try {
        if ((board[location.col_][location.row_] == piece) && (piece > 0)) {
            printf("ly: %d lx: %d value: %d piece: %d dy: %d dx: %d counter: %d\n",location.col_,location.row_,
                   board[location.col_][location.row_],piece,direction.col_,direction.row_,counter);
            //std::cout<<"Loc-Y: "<<location.col_<<" Loc-X: "<<location.row_<<" Value: "<<board[location.col_][location.row_]<<" Piece: "<<piece<<" Dir-Y: "<<direction.col_<<" Dir-X: "<<direction.row_<<std::endl;
            if (counter >= 3) { //Winning total is 0 based.
                checkForWinGivenBasePointAndDirection((counter+1),piece,
                        Point((location.row_ + direction.row_),(location.col_ + direction.col_)), direction);
                winningPiece[location.col_][location.row_] = true;
                return true;
            } else {
                if (checkForWinGivenBasePointAndDirection((counter+1),piece, Point((location.col_ + direction.col_),location.row_ + direction.row_), direction)) {
                    winningPiece[location.col_][location.row_] = true;
                    return true;
                } else return false;
            }
        } else return false;
    } catch(...) {
        return false;
    }
}

/***** Original Visual Basic code -- for coding reference only
//    Private Sub CheckAllForWin(ByVal Drop As Point)
//        For Row As Integer = 0 To 5
//            For Column As Integer = 0 To 6
//                If Board(Column, Row).PlayerNo <> Board(Drop.X, Drop.Y).PlayerNo Then Continue For
//                For Each D As Point In Directions
//                    Dim xL As New List(Of Point)
//                    If CheckForWin(0, Board(Column, Row), New Point(Column, Row), D, xL) Then
//                        Flasher = New System.Threading.Thread(AddressOf FlashWinners)
//                        Flasher.Start(xL)
//                        IsPlaying = False
//                        StatusLabel.Content = "Player " & Board(Drop.X, Drop.Y).PlayerNo & " wins! To rematch, start a new game."
//                        MsgBox("Player " & Board(Column, Row).PlayerNo & " wins!")
//                        Me.Focus() 'Otherwise shortcuts won't work
//                        Exit Sub
//                    End If
//                Next
//            Next
//        Next
//    End Sub
//    Private Function CheckForWin(ByVal ctr As Integer, ByRef P As Piece, ByVal Location As Point, ByRef Direction As Point, ByRef Winners As List(Of Point)) As Boolean
//        Try
//            If Board(Location.X, Location.Y).PlayerNo = P.PlayerNo Then
//                If ctr >= 3 Then 'Winning total is 0 based.
//                    CheckForWin(ctr + 1, P, New Point(Location.X + Direction.X, Location.Y + Direction.Y), Direction, Winners)
//                    Winners.Add(Location)
//                    Return True
//                Else
//                    If CheckForWin(ctr + 1, P, New Point(Location.X + Direction.X, Location.Y + Direction.Y), Direction, Winners) Then
//                        Winners.Add(Location)
//                        Return True
//                    Else
//                    End If
//                End If
//            Else
//                Return False
//            End If
//        Catch
//            Return False
//        End Try
//
//    End Function
******/

void connect4Frame::switchPlayers() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    statusBar->SetStatusText(((currentPlayer == 1) ? _("Current Player: Player One") : _("Current Player: Player Two")), 1);
    updateBoard(); //after switching players, let's update the board to reflect the changes
}

void connect4Frame::dropPiece(int col) {
    if (!playing) return;
    col--; //because the first index is zero, not one.
    for (int row = 5; row >= 0; row--) {
        if (board[row][col] == 0) {
            board[row][col] = currentPlayer;
            switchPlayers();  //switch players after the turn, if we successfully dropped the piece
            checkIfGameWon(row,col);
            return;
        }
    }
//    wxString msg = _("That column is full, moron! You can't put any more pieces in it.");
//    wxMessageBox(msg, _("Connect Four"));
    return;
}

connect4Frame::~connect4Frame()
{
    //destructor
}

void connect4Frame::clearBoard() {
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 7; c++) {
            board[r][c] = 0; //clear every cell
            winningPiece[r][c] = false;
        }
    }
    updateBoard();
    return;
}

void connect4Frame::OnNew(wxCommandEvent &event)
{
    printf("Starting new game...\n");
    playing = true;
    currentPlayer = 1;
    statusBar->SetStatusText(((currentPlayer == 1) ? _("Current Player: Player One") : _("Current Player: Player Two")), 1);
    clearBoard();
}

void connect4Frame::OnKeyPress(wxKeyEvent &event)
{
    wxString msg = _("Key event detected");
    wxMessageBox(msg, _("Connect Four"));
}

void connect4Frame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void connect4Frame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void connect4Frame::OnAbout(wxCommandEvent &event)
{
    wxString msg = _("Written by Dylan Taylor and Scott Ketelaar");
    wxMessageBox(msg, _("Connect Four"));
}

void connect4Frame::OnDrop1(wxCommandEvent &event) { dropPiece(1); }
void connect4Frame::OnDrop2(wxCommandEvent &event) { dropPiece(2); }
void connect4Frame::OnDrop3(wxCommandEvent &event) { dropPiece(3); }
void connect4Frame::OnDrop4(wxCommandEvent &event) { dropPiece(4); }
void connect4Frame::OnDrop5(wxCommandEvent &event) { dropPiece(5); }
void connect4Frame::OnDrop6(wxCommandEvent &event) { dropPiece(6); }
void connect4Frame::OnDrop7(wxCommandEvent &event) { dropPiece(7); }

