//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreFreelancerEXE.h
//	Module:			FLCoreFreelancerEXE.lib
//	Description:	Interface to Freelancer.exe
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCOREFREELANCEREXE_H_
#define _FLCOREFREELANCEREXE_H_

#include "FLCoreDefs.h"
#include "FLRemoteServer.h"

#pragma comment( lib, "FLCoreFreelancerEXE.lib" )

extern "C" IClient Client;
extern "C" IClient * GetChatClientInterface();
extern "C" IClient * GetClientInterface();

//EXTERN HandleConnectError();

#endif // _FLCOREFREELANCEREXE_H_