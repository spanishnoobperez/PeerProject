//
// PageOutput.h
//
// This file is part of PeerProject Torrent Wizard (peerproject.org) � 2008
// Portions Copyright Shareaza Development Team, 2007.
//
// PeerProject Torrent Wizard is free software; you can redistribute it
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or later version (at your option).
//
// Torrent Wizard is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License 3.0
// along with PeerProject; if not, write to Free Software Foundation, Inc.
// 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA  (www.fsf.org)
//

#pragma once

#include "WizardSheet.h"

class COutputPage : public CWizardPage {
    // Construction
public:
    COutputPage();

    DECLARE_DYNCREATE(COutputPage)

    // Dialog Data
public:
    enum { IDD = IDD_OUTPUT_PAGE };
    CEdit		m_wndName;
    CComboBox	m_wndFolders;
    CString 	m_sFolder;
    CString 	m_sName;
    CComboBox	m_wndPieceSize;
    int			m_nPieceIndex;
    BOOL		m_bAutoPieces;
    BOOL		m_bSHA1;
    BOOL		m_bED2K;
    BOOL		m_bMD5;

    // Overrides
protected:
    virtual void OnReset();
    virtual BOOL OnSetActive();
    virtual LRESULT OnWizardBack();
    virtual LRESULT OnWizardNext();
    virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV support

    // Implementation
protected:
    virtual BOOL OnInitDialog();
    afx_msg void OnClearFolders();
    afx_msg void OnBrowseFolder();
    afx_msg void OnClickedAutoPieceSize();
    afx_msg void OnCloseupPieceSize();
    afx_msg void OnXButtonDown(UINT nFlags, UINT nButton, CPoint point);

    DECLARE_MESSAGE_MAP()
};
