//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreFLServerEXE.h
//	Module:			FLCoreFLServerEXE.lib
//	Description:	Interface to FLServer.exe
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCOREFLSERVEREXE_H_
#define _FLCOREFLSERVEREXE_H_

#include "FLCoreDefs.h"
#include <string>

#pragma comment( lib, "FLCoreFLServerEXE.lib" )

EXTERN  int ServerLogf(struct ErrorCode,char const *,...);

#endif // _FLCOREFLSERVEREXE_H_