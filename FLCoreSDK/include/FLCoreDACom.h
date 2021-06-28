//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreDACom.h
//	Module:			FLCoreDACom.lib
//	Description:	Interface to dacom.dll
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCOREDACOM_H_
#define _FLCOREDACOM_H_

#include "FLCoreDefs.h"

#pragma comment( lib, "FLCoreDACom.lib" )

namespace DACOM_CRC
{
	EXTERN  int  CompareStringsI(char const *,char const *);
	EXTERN  unsigned long  GetCRC32(char const *,char const *);
	EXTERN  unsigned long  GetCRC32(char const *);
	EXTERN  unsigned long  GetContinuedCRC32(unsigned long,char);
	EXTERN  unsigned long  GetContinuedCRC32(unsigned long,char const *);
};

namespace LogStream
{
	EXTERN  void  FlushToDisk(void);
	EXTERN  void  LogEvent(char const *,float,unsigned long);
	EXTERN  void  LogNamedEvent(char const *,char const *,unsigned long);
	EXTERN  bool  Startup(char const *);
	EXTERN  void  Update(float);
};

EXTERN  void DACOM_Acquire();
EXTERN  void DACOM_GetDllVersion();
EXTERN  void DACOM_GetVersion();
EXTERN  void FDUMP();

#endif // _FLCOREDACOM_H_