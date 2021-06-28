//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreMovie.h
//	Module:			FLCoreMovie.lib
//	Description:	Interface to movie.dll
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCOREMOVIE_H_
#define _FLCOREMOVIE_H_

#include "FLCoreDefs.h"

#pragma comment( lib, "FLCoreMovie.lib" )

namespace MediaPlayer
{
	EXTERN  void FreeMovie(void);
	EXTERN  long PlayMovie(struct HWND__ *,bool,char const *);
	EXTERN  void SetApproach(enum Approach);
	EXTERN  void Shutdown(void);
	EXTERN  void Startup(void);
	EXTERN  void StopMovie(void);
	EXTERN  bool UpdateMovie(void);
};


#endif // _FLCOREMOVIE_H_