﻿//
// Schema.h
//
// This file is part of PeerProject (peerproject.org) � 2008-2015
// Portions copyright Shareaza Development Team, 2002-2008.
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

class CSchema;
class CSchemaMember;
class CSchemaChild;
class CSchemaBitprints;
class CXMLElement;

typedef const CSchema *CSchemaPtr;

#ifdef WIN64

template<>
AFX_INLINE UINT AFXAPI HashKey(CSchemaPtr key) {
    return HashKey< __int64 >( (__int64)key );
}

#endif // _WIN64

#include "SchemaMember.h"


class CSchema {
public:
    CSchema();
    virtual ~CSchema();

public:
    int				m_nType;
    CString			m_sTitle;
    CString			m_sPlural;
    CString			m_sSingular;
    CString			m_sDonkeyType;
    int				m_nAvailability;
    BOOL			m_bPrivate;

    CList< CString >		m_pExtends;
    CList< CSchemaMember * >	m_pMembers;
    CList< CSchemaChild * >	m_pContains;
    CList< CSchemaBitprints * >	m_pBitprintsMap;
    CString			m_sDefaultColumns;
    CString			m_sBitprintsTest;
    CString			m_sLibraryView;
    CString			m_sHeaderTitle;
    CString			m_sHeaderSubtitle;
    CString			m_sTileLine1;
    CString			m_sTileLine2;

    CString			m_sIcon;
    int				m_nIcon16;
    int				m_nIcon32;
    int				m_nIcon48;

    enum { stFile, stFolder };
    enum { saDefault, saAdvanced, saSystem, saMax };

public:
    void			Clear();
    BOOL			Load(LPCTSTR pszName);
    CXMLElement	*Instantiate(BOOL bNamespace = FALSE) const;
    BOOL			Validate(CXMLElement *pXML, BOOL bFix) const;

    BOOL			FilterType(LPCTSTR pszFile) const;
    CString			GetFilterSet() const;
    POSITION		GetFilterIterator() const;
    void			GetNextFilter(POSITION &pos, CString &sType, BOOL &bResult) const;
    POSITION		GetMemberIterator() const;
    CSchemaMember	*GetNextMember(POSITION &pos) const;
    CSchemaMember	*GetMember(LPCTSTR pszName) const;
    INT_PTR			GetMemberCount() const;
    CString			GetFirstMemberName() const;
    CSchemaChild	*GetContained(LPCTSTR pszURI) const;
    CString			GetContainedURI(int nType) const;
    CString			GetIndexedWords(CXMLElement *pXML) const;
    CString			GetVisibleWords(CXMLElement *pXML) const;
    void			ResolveTokens(CString &str, CXMLElement *pXML) const;

protected:
    typedef CMap < CString, const CString &, BOOL, BOOL & > CStringBoolMap;
    CStringBoolMap	m_pTypeFilters;
    CString			m_sURI;

    CXMLElement	*GetType(const CXMLElement *pRoot, LPCTSTR pszName) const;
    BOOL			LoadSchema(LPCTSTR pszFile);
    BOOL			LoadPrimary(const CXMLElement *pRoot, const CXMLElement *pType);
    BOOL			LoadDescriptor(LPCTSTR pszFile);
    void			LoadDescriptorTitles(const CXMLElement *pElement);
    void			LoadDescriptorIcons(const CXMLElement *pElement);
    void			LoadDescriptorMembers(const CXMLElement *pElement);
    void			LoadDescriptorTypeFilter(const CXMLElement *pElement);
    void			LoadDescriptorExtends(const CXMLElement *pElement);
    void			LoadDescriptorContains(const CXMLElement *pElement);
    void			LoadDescriptorBitprintsImport(const CXMLElement *pElement);
    void			LoadDescriptorHeaderContent(const CXMLElement *pElement);
    void			LoadDescriptorViewContent(const CXMLElement *pElement);
    BOOL			LoadIcon();

    // Inlines
public:
    inline CString GetURI() const {
        return m_sURI;
    }

    inline bool Equals(CSchemaPtr pSchema) const {
        return ( pSchema && ( ( this == pSchema ) || CheckURI( pSchema->m_sURI ) ) );
    }

    inline bool CheckURI(LPCTSTR pszURI) const {
        if ( ! pszURI ) return false;
        if ( m_sURI.CompareNoCase( pszURI ) == 0 ) return true;
        for ( POSITION pos = m_pExtends.GetHeadPosition() ; pos ; ) {
            CString strURI = m_pExtends.GetNext( pos );
            if ( strURI.CompareNoCase( pszURI ) == 0 ) return true;
        }
        return false;
    }

    // Common Schemas
public:
    static LPCTSTR	uriApplication;
    static LPCTSTR	uriArchive;
    static LPCTSTR	uriAudio;
    static LPCTSTR	uriBook;
    static LPCTSTR	uriImage;
    static LPCTSTR	uriVideo;
    static LPCTSTR	uriROM;
    static LPCTSTR	uriDocument;
    static LPCTSTR	uriSpreadsheet;
    static LPCTSTR	uriPresentation;
    static LPCTSTR	uriCollection;
    static LPCTSTR	uriLibrary;
    static LPCTSTR	uriFolder;
    static LPCTSTR	uriAllFiles;
    static LPCTSTR	uriCollectionsFolder;
    static LPCTSTR	uriFavoritesFolder;
    static LPCTSTR	uriSearchFolder;
    static LPCTSTR	uriApplicationRoot;
    static LPCTSTR	uriApplicationAll;
    static LPCTSTR	uriArchiveRoot;
    static LPCTSTR	uriArchiveAll;
    static LPCTSTR	uriBookRoot;
    static LPCTSTR	uriBookAll;
    static LPCTSTR	uriImageRoot;
    static LPCTSTR	uriImageAll;
    static LPCTSTR	uriImageAlbum;
    static LPCTSTR	uriMusicRoot;
    static LPCTSTR	uriMusicAll;
    static LPCTSTR	uriMusicAlbum;
    static LPCTSTR	uriMusicArtist;
    static LPCTSTR	uriMusicGenre;
    static LPCTSTR	uriMusicAlbumCollection;
    static LPCTSTR	uriMusicArtistCollection;
    static LPCTSTR	uriMusicGenreCollection;
    static LPCTSTR	uriVideoRoot;
    static LPCTSTR	uriVideoAll;
    static LPCTSTR	uriVideoFilm;
    static LPCTSTR	uriVideoSeries;
    static LPCTSTR	uriVideoFilmCollection;
    static LPCTSTR	uriVideoSeriesCollection;
    static LPCTSTR	uriVideoMusicCollection;
    static LPCTSTR	uriDocumentRoot;
    static LPCTSTR	uriDocumentAll;
    static LPCTSTR	uriUnknown;
    static LPCTSTR	uriUnknownFolder;
    static LPCTSTR	uriBitTorrent;
    static LPCTSTR	uriBitTorrentFolder;
    static LPCTSTR	uriGhostFolder;
    //	static LPCTSTR	uriComments;
    //	static LPCTSTR	uriSkin;

    friend class CSchemaMember;

private:
    CSchema(const CSchema &);
    CSchema &operator=(const CSchema &);
};


class CSchemaBitprints {
public:
    CString		m_sFrom;
    CString		m_sTo;
    double		m_nFactor;

    BOOL		Load(const CXMLElement *pXML);
};
