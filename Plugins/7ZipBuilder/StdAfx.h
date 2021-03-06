//
// StdAfx.h
//
// Source file for standard system include files,
// or project files that are used frequently but changed infrequently
//

#pragma once

#if !defined(_UNICODE) || !defined(UNICODE)
#error Unicode Required
#endif

// TargetVer.h: (WINVER)
#define NTDDI_VERSION	0x05010200	// NTDDI_WINXPSP2
#define _WIN32_WINNT	0x0501		// XP
#include <sdkddkver.h>

#define VC_EXTRALEAN
#define STRICT

#define _WIN32_DCOM
#define _CRT_SECURE_NO_DEPRECATE
//#define _ATL_NO_AUTOMATIC_NAMESPACE
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#define _ATL_CSTRING_NO_CRT
#define _ATL_FREE_THREADED
#define _ATL_ALL_WARNINGS

#pragma warning( push, 0 )

#include <atlbase.h>
#include <atlcom.h>
#include <atlstr.h>

//using namespace ATL;

#pragma warning( pop )

typedef HRESULT (STDAPICALLTYPE *tCreateObject)(const GUID *clsid, const GUID *iid, void **outObject);

extern tCreateObject fnCreateObject;
