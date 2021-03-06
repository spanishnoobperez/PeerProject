#ifndef _RAR_EXTINFO_
#define _RAR_EXTINFO_

bool IsRelativeSymlinkSafe(const wchar *SrcName, const wchar *TargetName);
bool ExtractSymlink(CommandData *Cmd, ComprDataIO &DataIO, Archive &Arc, const wchar *LinkName);
//#ifdef _UNIX
//void SetUnixOwner(Archive &Arc,const wchar *FileName);
//#endif

bool ExtractHardlink(wchar *NameNew, wchar *NameExisting, size_t NameExistingSize);

void GetStreamNameNTFS(Archive &Arc, wchar *StreamName, size_t MaxSize);

#ifdef _WIN_ALL
bool SetPrivilege(LPCTSTR PrivName);
#endif

void SetExtraInfo20(CommandData *Cmd, Archive &Arc, wchar *Name);
void SetExtraInfo(CommandData *Cmd, Archive &Arc, wchar *Name);

#endif
