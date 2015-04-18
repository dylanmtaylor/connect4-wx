/***************************************************************
 * Name:      connect4App.cpp
 * Purpose:   Code for Application Class
 * Author:    Dylan Taylor (aliendude5300@gmail.com)
 * Created:   2011-03-28
 * Copyright: Dylan Taylor (http://dylanmtaylor.com/)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "connect4App.h"
#include "connect4Main.h"

IMPLEMENT_APP(connect4App);

bool connect4App::OnInit()
{
    wxBitmap orange(_T("orange.png"));
    wxBitmap orange_glow(_T("orange-glow.png"));
    wxBitmap brown(_T("brown.png"));
    wxBitmap brown_glow(_T("brown-glow.png"));
    wxImage::AddHandler(new wxPNGHandler());
    connect4Frame* frame = new connect4Frame(0L);
    frame->Show();
    return true;
}

