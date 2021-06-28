//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreRemoteClient.h
//	Module:			FLCoreRemoteClient.lib
//	Description:	Interface to RemoteClient.dll
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCOREREMOTECLIENT_H_
#define _FLCOREREMOTECLIENT_H_

#include "FLCoreDefs.h"
#include <vector>

#pragma comment( lib, "FLCoreRemoteClient.lib" )

class EXTERN IClient
{
public:
	 IClient(class IClient const &);
	 IClient(void);
	 class IClient & operator=(class IClient const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

EXTERN  void  ForceClientLogout(unsigned int);
EXTERN  int  GetClientStats(struct client_stats_t *,int *);
EXTERN  int  GetNumClients(void);
EXTERN  void  GetRemoteClientPort( std::vector<unsigned long> & );
EXTERN  void  SetRemoteClientPassword(unsigned short const *);
EXTERN  void  SetRemoteClientResponseData(bool,bool,int,unsigned short const *,unsigned int,char const *);
EXTERN  void  SetRemoteClientSessionName(unsigned short const *);
EXTERN  void  SetServerLogFunction(int (*)(struct ErrorCode,char const *,...));

extern "C" IClient Client;
extern "C" IClient * GetChatClientInterface();
extern "C" IClient * GetClientInterface();

#endif // _FLCOREREMOTECLIENT_H_
