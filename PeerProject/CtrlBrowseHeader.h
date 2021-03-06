﻿//
// CtrlBrowseHeader.h
//
// This file is part of PeerProject (peerproject.org) � 2008-2014
// Portions copyright Shareaza Development Team, 2002-2007.
//
// PeerProject is free software. You may redistribute and/or modify it
// under the terms of the GNU Affero General Public License
// as published by the Free Software Foundation (fsf.org);
// version 3 or later at your option. (AGPLv3)
//
// PeerProject is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Affero General Public License 3.0 for details:
// (http://www.gnu.org/licenses/agpl.html)
//

#pragma once

#include "CtrlCoolBar.h"

class CHostBrowser;


class CBrowseHeaderCtrl : public CCoolBarCtrl {
public:
    CBrowseHeaderCtrl();
    virtual ~CBrowseHeaderCtrl();

protected:
    CString	m_sTitle;
    CString	m_sIntro;
    int		m_nIcon32;
    int		m_nIcon48;

public:
    void	Update(CHostBrowser *pBrowser);
    void	OnSkinChange();

protected:
    virtual void PrepareRect(CRect *pRect) const;
    virtual void DoPaint(CDC *pDC, CRect &rcBar, BOOL bTransparent);

public:
    virtual BOOL Create(CWnd *pParentWnd);

protected:
    afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);

    DECLARE_MESSAGE_MAP()
};

#define IDC_BROWSE_HEADER	123
