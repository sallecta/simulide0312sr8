/***************************************************************************
 *   Copyright (C) 2018 by santiago González                               *
 *   santigoro@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/

#ifndef FUNCTION_H
#define FUNCTION_H

#include "e-function.h"
#include "logiccomponent.h"

class LibraryItem;

class MAINMODULE_EXPORT Function : public LogicComponent, public eFunction
{
    Q_OBJECT
    Q_PROPERTY( double Input_High_V READ inputHighV WRITE setInputHighV DESIGNABLE true USER true )
    Q_PROPERTY( double Input_Low_V  READ inputLowV  WRITE setInputLowV  DESIGNABLE true USER true )
    Q_PROPERTY( double Input_Imped  READ inputImp   WRITE setInputImp   DESIGNABLE true USER true )
    Q_PROPERTY( double Out_High_V   READ outHighV   WRITE setOutHighV   DESIGNABLE true USER true )
    Q_PROPERTY( double Out_Low_V    READ outLowV    WRITE setOutLowV    DESIGNABLE true USER true )
    Q_PROPERTY( double Out_Imped    READ outImp     WRITE setOutImp     DESIGNABLE true USER true )
    Q_PROPERTY( bool   Inverted     READ inverted   WRITE setInverted   DESIGNABLE true USER true )
    Q_PROPERTY( int    Num_Inputs   READ numInps    WRITE setNumInps    DESIGNABLE true USER true )
    Q_PROPERTY( int    Num_Outputs  READ numOuts    WRITE setNumOuts    DESIGNABLE true USER true )
    Q_PROPERTY( QString Functions   READ functions  WRITE setFunctions  DESIGNABLE true USER true )
    

    public:
        
        Function( QObject* parent, QString type, QString id );
        ~Function();
        
 static Component* construct( QObject* parent, QString type, QString id );
 static LibraryItem* libraryItem();
        
        void setNumInps( int inputs );
        void setNumOuts( int outs );
        
    public slots:
        virtual void remove();
        void onbuttonclicked();
        
    private:
        QList<QPushButton*> m_buttons;
        QList<QGraphicsProxyWidget*> m_proxys;
};

#endif
