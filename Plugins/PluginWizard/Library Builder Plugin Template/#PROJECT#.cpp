//
// #PROJECT#.cpp : Implementation of DLL Exports.
//
// This file is part of PeerProject (peerproject.org) � 2010
// #COPYRIGHT#
//
// PeerProject is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or later version (at your option).
//
// PeerProject is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License 3.0
// along with PeerProject; if not, write to Free Software Foundation, Inc.
// 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA  (www.fsf.org)
//

#include "StdAfx.h"
#include "Resource.h"
#include "#PROJECT#.h"

class CModule : public CAtlDllModuleT< CModule > {
public :
    DECLARE_LIBID( LIBID_#PROJECT#Lib )
    DECLARE_REGISTRY_APPID_RESOURCEID( IDR_APP, "{#GUID#}" )
};

CModule _AtlModule;

extern "C" BOOL WINAPI DllMain(HINSTANCE /*hInstance*/, DWORD dwReason, LPVOID lpReserved) {
    return _AtlModule.DllMain( dwReason, lpReserved );
}

// Determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void) {
    return _AtlModule.DllCanUnloadNow();
}

// Return a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
    return _AtlModule.DllGetClassObject( rclsid, riid, ppv );
}

// Add entries to the system registry
STDAPI DllRegisterServer(void) {
    return _AtlModule.DllRegisterServer();
}

// Remove entries from the system registry
STDAPI DllUnregisterServer(void) {
    return _AtlModule.DllUnregisterServer();
}

// Add/Remove entries to the system registry per user
STDAPI DllInstall(BOOL bInstall, LPCWSTR pszCmdLine) {
    static const wchar_t szUserSwitch[] = L"user";
    if ( pszCmdLine && _wcsnicmp( pszCmdLine, szUserSwitch, _countof(szUserSwitch) ) == 0 )
        AtlSetPerUserRegistration( true );	// VS2008+
    HRESULT hr = bInstall ?
                 DllRegisterServer() :
                 DllUnregisterServer();
    if ( bInstall && FAILED( hr ) )
        DllUnregisterServer();
    return hr;
}
