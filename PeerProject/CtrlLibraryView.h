﻿//
// CtrlLibraryView.h
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

#include "PeerProjectDataSource.h"
#include "LibraryList.h"

class CAlbumFolder;
class CLibraryFrame;
class CLibraryTreeItem;
class CLibraryTipCtrl;

// Abstract base class for CLibraryTileView and CLibraryFileView

class CLibraryView : public CWnd {
    DECLARE_DYNAMIC(CLibraryView)

public:
    CLibraryView();
    virtual ~CLibraryView();

public:
    UINT				m_nCommandID;
    LPCTSTR				m_pszToolBar;
    BOOL				m_bAvailable;
    BOOL				m_bGhostFolder;
    CLibraryListItem	m_oDropItem;

private:
    CLibraryListPtr		m_pSelection;

public:
    inline CLibraryList *GetSelection() const {
        return m_pSelection;
    }

    virtual BOOL				Create(CWnd *pParentWnd);
    virtual BOOL				CheckAvailable(CLibraryTreeItem *pSel);
    virtual void				GetHeaderContent(int &nImage, CString &strTitle);
    virtual void				Update();
    virtual BOOL				Select(DWORD nObject);
    virtual void				SelectAll() = 0;
    virtual void				CacheSelection();
    virtual CLibraryListItem	GetFolder() const;
    virtual CLibraryListItem	DropHitTest(const CPoint &point) const;
    virtual void				StartDragging(const CPoint &ptMouse);
    virtual HBITMAP				CreateDragImage(const CPoint &ptMouse, CPoint &ptMiddle);
    virtual DWORD_PTR			HitTestIndex(const CPoint &point) const = 0;
    virtual void				OnSkinChange() {}

    CLibraryFrame		*GetFrame() const;
    CLibraryTipCtrl	*GetToolTip() const;

protected:
    void				PostUpdate();
    DWORD				GetFolderCookie() const;
    CLibraryTreeItem	*GetFolderSelection() const;
    CAlbumFolder		*GetSelectedAlbum(CLibraryTreeItem *pSel = NULL) const;

    BOOL				SelAdd(CLibraryListItem oObject, BOOL bNotify = TRUE);
    BOOL				SelRemove(CLibraryListItem oObject, BOOL bNotify = TRUE);
    BOOL				SelClear(BOOL bNotify = TRUE);
    POSITION			StartSelectedFileLoop() const;
    INT_PTR 			GetSelectedCount() const;
    CLibraryFile		*GetNextSelectedFile(POSITION &posSel, BOOL bSharedOnly = FALSE, BOOL bAvailableOnly = TRUE) const;
    CLibraryFile		*GetSelectedFile();

protected:
    afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnXButtonDown(UINT nFlags, UINT nButton, CPoint point);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);

    DECLARE_MESSAGE_MAP()
    DECLARE_DROP()
};

#define IDC_LIBRARY_VIEW	132
