//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreRPCLocal.h
//	Module:			FLCoreRPCLocal.lib
//	Description:	Interface to rpclocal.dll
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCORERPCLOCAL_H_
#define _FLCORERPCLOCAL_H_

#include "FLCoreDefs.h"
#include <list>

#pragma comment( lib, "FLCoreRPCLocal.lib" )

class EXTERN IClient
{
public:
	 IClient(class IClient const &);
	 IClient(void);
	 class IClient & operator=(class IClient const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN IServerImpl
{
	 IServerImpl(struct IServerImpl const &);
	 IServerImpl(void);
	 struct IServerImpl & operator=(struct IServerImpl const &);
	 virtual void AbortMission(unsigned int,unsigned int);
	 virtual void AcceptTrade(unsigned int,bool);
	 virtual void ActivateCruise(unsigned int,struct XActivateCruise const &);
	 virtual void ActivateEquip(unsigned int,struct XActivateEquip const &);
	 virtual void ActivateThrusters(unsigned int,struct XActivateThrusters const &);
	 virtual void AddTradeEquip(unsigned int,struct EquipDesc const &);
	 virtual void BaseEnter(unsigned int,unsigned int);
	 virtual void BaseExit(unsigned int,unsigned int);
	 virtual void BaseInfoRequest(unsigned int,unsigned int,bool);
	 virtual void CharacterInfoReq(unsigned int,bool);
	 virtual void CharacterSelect(struct CHARACTER_ID const &,unsigned int);
	 virtual void CharacterSkipAutosave(unsigned int);
	 virtual void CommComplete(unsigned int,unsigned int,unsigned int,enum CommResult);
	 virtual void Connect(char const *,unsigned short *);
	 virtual void CreateNewCharacter(struct SCreateCharacterInfo const &,unsigned int);
	 virtual void DelTradeEquip(unsigned int,struct EquipDesc const &);
	 virtual void DestroyCharacter(struct CHARACTER_ID const &,unsigned int);
	 virtual void DisConnect(unsigned int,enum EFLConnection);
	 virtual void Dock(unsigned int const &,unsigned int const &);
	 virtual void DumpPacketStats(char const *);
	 virtual void ElapseTime(float);
	 virtual void FireWeapon(unsigned int,struct XFireWeaponInfo const &);
	 virtual void GFGoodBuy(struct SGFGoodBuyInfo const &,unsigned int);
	 virtual void GFGoodSell(struct SGFGoodSellInfo const &,unsigned int);
	 virtual void GFGoodVaporized(struct SGFGoodVaporizedInfo const &,unsigned int);
	 virtual void GFObjSelect(unsigned int,unsigned int);
	 virtual unsigned int GetServerID(void);
	 virtual char const * GetServerSig(void);
	 void GetServerStats(struct ServerStats &);
	 virtual void GoTradelane(unsigned int,struct XGoTradelane const &);
	 virtual void Hail(unsigned int,unsigned int,unsigned int);
	 bool HandleCharacterInfo(class CDAPCharacterInfo *,class IClient *,unsigned int);
	 bool HandleDamageObject(class CDAPDamageSpaceObj *,class IClient *,unsigned int);
	 void HandlePacket(class CDAPacket *);
	 virtual void InitiateTrade(unsigned int,unsigned int);
	 virtual void InterfaceItemUsed(unsigned int,unsigned int);
	 virtual void JettisonCargo(unsigned int,struct XJettisonCargo const &);
	 virtual void JumpInComplete(unsigned int,unsigned int);
	 virtual void LaunchComplete(unsigned int,unsigned int);
	 virtual void LocationEnter(unsigned int,unsigned int);
	 virtual void LocationExit(unsigned int,unsigned int);
	 virtual void LocationInfoRequest(unsigned int,unsigned int,bool);
	 virtual void Login(struct SLoginInfo const &,unsigned int);
	 virtual void MineAsteroid(unsigned int,class Vector const &,unsigned int,unsigned int,unsigned int,unsigned int);
	 virtual void MissionResponse(unsigned int,unsigned long,bool,unsigned int);
	 virtual void MissionSaveB(unsigned int,unsigned long);
	 virtual void NewCharacterInfoReq(unsigned int);
	 virtual void OnConnect(unsigned int);
	 virtual void PlayerLaunch(unsigned int,unsigned int);
	 virtual void PopUpDialog(unsigned int,unsigned int);
	 virtual void PushToServer(class CDAPacket *);
	 virtual void RTCDone(unsigned int,unsigned int);
	 virtual void ReqAddItem(unsigned int,char const *,int,float,bool,unsigned int);
	 virtual void ReqCargo(class EquipDescList const &,unsigned int);
	 virtual void ReqChangeCash(int,unsigned int);
	 virtual void ReqCollisionGroups(std::list<struct CollisionGroupDesc> const &,unsigned int);
	 virtual void ReqDifficultyScale(float,unsigned int);
	 virtual void ReqEquipment(class EquipDescList const &,unsigned int);
	 virtual void ReqHullStatus(float,unsigned int);
	 virtual void ReqModifyItem(unsigned short,char const *,int,float,bool,unsigned int);
	 virtual void ReqRemoveItem(unsigned short,int,unsigned int);
	 virtual void ReqSetCash(int,unsigned int);
	 virtual void ReqShipArch(unsigned int,unsigned int);
	 virtual void RequestBestPath(unsigned int,unsigned char *,int);
	 virtual void RequestCancel(int,unsigned int,unsigned int,unsigned long,unsigned int);
	 virtual void RequestCreateShip(unsigned int);
	 virtual void RequestEvent(int,unsigned int,unsigned int,unsigned int,unsigned long,unsigned int);
	 virtual void RequestGroupPositions(unsigned int,unsigned char *,int);
	 virtual void RequestPlayerStats(unsigned int,unsigned char *,int);
	 virtual void RequestRankLevel(unsigned int,unsigned char *,int);
	 virtual void RequestTrade(unsigned int,unsigned int);
	 virtual void SPBadLandsObjCollision(struct SSPBadLandsObjCollisionInfo const &,unsigned int);
	 virtual void SPMunitionCollision(struct SSPMunitionCollisionInfo const &,unsigned int);
	 virtual void SPObjCollision(struct SSPObjCollisionInfo const &,unsigned int);
	 virtual void SPObjUpdate(struct SSPObjUpdateInfo const &,unsigned int);
	 virtual void SPRequestInvincibility(unsigned int,bool,enum InvincibilityReason,unsigned int);
	 virtual void SPRequestUseItem(struct SSPUseItem const &,unsigned int);
	 virtual void SPScanCargo(unsigned int const &,unsigned int const &,unsigned int);
	 virtual void SaveGame(struct CHARACTER_ID const &,unsigned short const *,unsigned int);
	 virtual void SetActiveConnection(enum EFLConnection);
	 virtual void SetInterfaceState(unsigned int,unsigned char *,int);
	 virtual void SetManeuver(unsigned int,struct XSetManeuver const &);
	 virtual void SetMissionLog(unsigned int,unsigned char *,int);
	 virtual void SetTarget(unsigned int,struct XSetTarget const &);
	 virtual void SetTradeMoney(unsigned int,unsigned long);
	 virtual void SetVisitedState(unsigned int,unsigned char *,int);
	 virtual void SetWeaponGroup(unsigned int,unsigned char *,int);
	 virtual void Shutdown(void);
	 virtual bool Startup(struct SStartupInfo const &);
	 virtual void StopTradeRequest(unsigned int);
	 virtual void StopTradelane(unsigned int,unsigned int,unsigned int,unsigned int);
	 virtual void SubmitChat(struct CHAT_ID,unsigned long,void const *,struct CHAT_ID,int);
	 virtual bool SwapConnections(enum EFLConnection,enum EFLConnection);
	 virtual void SystemSwitchOutComplete(unsigned int,unsigned int);
	 virtual void TerminateTrade(unsigned int,int);
	 virtual void TractorObjects(unsigned int,struct XTractorObjects const &);
	 virtual void TradeResponse(unsigned char const *,int,unsigned int);
	 virtual int Update(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

extern "C" IClient * GetChatClientInterface();
extern "C" IClient * GetClientInterface();
extern "C" IClient Client;

extern "C" struct IServer * GetServerInterface;
extern "C" struct IChatServer * GetChatServerInterface();
extern "C" IServerImpl Server;

#endif // _FLCORERPCLOCAL_H_