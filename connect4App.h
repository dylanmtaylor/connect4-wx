/***************************************************************
 * Name:      connect4App.h
 * Purpose:   Defines Application Class
 * Author:    Dylan Taylor (aliendude5300@gmail.com)
 * Created:   2011-03-28
 * Copyright: Dylan Taylor (http://dylanmtaylor.com/)
 * License:
 **************************************************************/

#ifndef CONNECT4APP_H
#define CONNECT4APP_H

#include <wx/app.h>

class connect4App : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // CONNECT4APP_H
