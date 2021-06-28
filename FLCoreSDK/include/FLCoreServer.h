//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreServer.h
//	Module:			FLCoreServer.lib
//	Description:	Interface to Server.dll
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCORESERVER_H_
#define _FLCORESERVER_H_

#include <string>
#include <list>
#include <vector>
#include <map>

#include "ci_string.h"

#include "FLCoreDefs.h"

#pragma comment( lib, "FLCoreServer.lib" )

class EXTERN CAccount
{
public:
	 CAccount(class CAccount const &);
	 CAccount(void);
	 virtual ~CAccount(void);
	 class CAccount & operator=(class CAccount const &);
	 void AppendCharacterNames(std::list<ci_wstring> &);
	 void DeleteCharacterFromID(ci_string &);
	 void ForceLogout(void);
	 void InitFromFolder(char const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CDeadReckonedVector
{
public:
	 CDeadReckonedVector(class CDeadReckonedVector const &);
	 class CDeadReckonedVector & operator=(class CDeadReckonedVector const &);
	 double CalcError(class Vector const &);
	 class Vector const & GetSample(int);
	 void NormalizeProjectedPosition(void);
	 void NormalizeTrackedPosition(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace BaseGroupMessage
{
	enum Type;
};

class EXTERN CPlayerGroup
{
public:
	 CPlayerGroup(class CPlayerGroup const &);
	 CPlayerGroup(void);
	 virtual ~CPlayerGroup(void);
	 class CPlayerGroup & operator=(class CPlayerGroup const &);
	 bool AddInvite(unsigned int);
	 bool AddMember(unsigned int);
	 bool DelInvite(unsigned int);
	 bool DelMember(unsigned int);
	 void DeliverChat(unsigned long,void const *);
	 static class CPlayerGroup * FromGroupID(unsigned int);
	 unsigned int GetID(void);
	 unsigned int GetInviteCount(void);
	 unsigned int GetMember(int)const ;
	 unsigned int GetMemberCount(void);
	 unsigned int GetMissionID(void);
	 unsigned int GetMissionSetBy(void);
	 void HandleClientLogout(unsigned int);
	 bool IsFull(void);
	 bool IsInvited(unsigned int);
	 bool IsMember(unsigned int);
	 void RewardMembers(int);
	 void SendChat(int,unsigned short const *,...);
	 void SendGroup(enum BaseGroupMessage::Type,unsigned int);
	 void SetMissionID(unsigned int,unsigned int);
	 void SetMissionMessage(struct CSetMissionMessage &);
	 void SetMissionObjectives(struct CMissionObjectives &);
	 void StoreMemberList(std::vector<unsigned int> &);

protected:
	 static class std::map<unsigned int const ,CPlayerGroup*>  s_GroupIDToGroupPtrMap;
	 static unsigned int  s_uiGroupID;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CRemotePhysicsSimulation
{
public:
	 CRemotePhysicsSimulation(class CRemotePhysicsSimulation const &);
	 class CRemotePhysicsSimulation & operator=(class CRemotePhysicsSimulation const &);
	 double CalcPositionError(class Vector const &);
	 class Vector  GetLatestUpdate(void);
	 class Vector  GetSample(int);
	 unsigned long GetSampleCount(void);
	 double GetSimulationTime(void);
	 void SetLogging(bool);

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
	 virtual void ReqCollisionGroups(class std::list<struct CollisionGroupDesc,class std::allocator<struct CollisionGroupDesc> > const &,unsigned int);
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

class EXTERN MD5Hash
{
public:
	 MD5Hash(class MD5Hash const &);
	 class MD5Hash & operator=(class MD5Hash const &);
	 unsigned char * GetStatePtr(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};


class EXTERN PlayerDB
{
public:
	 PlayerDB(class PlayerDB const &);
	 PlayerDB(void);
	 ~PlayerDB(void);
	 class PlayerDB & operator=(class PlayerDB const &);
	 struct PlayerData & operator[](unsigned int const &);
	 bool BanAccount(ci_wstring &,bool);
	 void BuildLocalUserDir(void);
	 unsigned int CountPlayersInSystem(int);
	 bool CreateAccount(ci_wstring &);
	 void DeleteAccount(ci_wstring &);
	 void DeleteCharacterFromID(ci_string &);
	 bool DeleteCharacterFromName(ci_wstring &);
	 class CAccount * FindAccountFromCharacterID(ci_string &);
	 class CAccount * FindAccountFromCharacterName(ci_wstring &);
	 class CAccount * FindAccountFromClientID(unsigned int);
	 class CAccount * FindAccountFromName(ci_wstring &);
	 bool GetAccountAdminRights(ci_wstring &);
	 bool GetAccountBanned(ci_wstring &);
	 unsigned short const * GetActiveCharacterName(unsigned int)const ;
	 bool GetCharactersForAccount(ci_wstring &,class std::list<ci_wstring> &);
	 unsigned int GetGroupID(unsigned int);
	 std::wstring & GetMOTD(void);
	 unsigned int GetMaxPlayerCount(void);
	 unsigned int GetServerID(void);
	 char const * GetServerSig(void);
	 void LockAccountAccess(ci_wstring &);
	 bool MakeLocalUserPath(char *,char const *);
	 void ReadCharacterName(char const *,ci_wstring &);
	 void SendGroupID(unsigned int,unsigned int);
	 void SendSystemID(unsigned int,unsigned int);
	 bool SetAccountAdminRights(ci_wstring &,bool);
	 bool SetAccountPassword(ci_wstring &,ci_wstring &);
	 void SetMOTD(std::wstring &);
	 void UnlockAccountAccess(ci_wstring &);
	 void cleanup(unsigned int);
	 bool create_new_character(struct SCreateCharacterInfo const &,unsigned int);
	 bool create_restart_file(char const *);
	 void free(void);
	 void init(unsigned int,bool);
	 bool is_valid(unsigned int const &);
	 bool is_valid_ship_owner(unsigned int const &,unsigned int const &);
	 unsigned char login(struct SLoginInfo const &,unsigned int);
	 void logout(unsigned int);
	 void logout_all(void);
	 struct PlayerData * traverse_active(struct PlayerData *)const ;

private:
	 int create_account(struct SLoginInfo const &);
	 unsigned char load_user_data(struct SLoginInfo const &,unsigned int);
	 unsigned int to_index(unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};


namespace CmnAsteroid  // from FLCoreCommon.h
{
	class CAsteroidSystem;
}; 

namespace SrvAsteroid
{
	class EXTERN SrvAsteroidSystem
	{
	public:
		 SrvAsteroidSystem(SrvAsteroidSystem const &);
		 SrvAsteroidSystem(void);
		 ~SrvAsteroidSystem(void);
		 SrvAsteroidSystem & operator=(SrvAsteroidSystem const &);
		 int AddRef(void);
		 int Release(void);
		 void load(char const *);
		 void map_asteroid_fields(void);
		 void set_cmn_system(class CmnAsteroid::CAsteroidSystem *);
		 void set_sys_id(unsigned int);
		 void update(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

};

struct EXTERN StarSystem
{
	 unsigned int count_players(unsigned int)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace SysDB
{
	EXTERN  std::map<unsigned int,class StarSystem> SysMap;
};

namespace Controller
{
	struct TimerExpired;
}

namespace pub
{
	struct CargoEnumerator;
	
	EXTERN  int BuildBaseReader(class INI_Reader &,unsigned int const &);
	EXTERN  int BuildSystemReader(class INI_Reader &,unsigned int const &);
	EXTERN  struct HINSTANCE__ * DLL_LoadLibrary(char const *);
	EXTERN  void DebugPrint(char const *,int);
	EXTERN  int FindHardpoint(char const *,unsigned int,class Vector &,class Matrix &);
	EXTERN  int GetBaseID(unsigned int &,char const *);
	EXTERN  unsigned int GetBaseNickname(char *,unsigned int,unsigned int const &);
	EXTERN  int GetBaseStridName(unsigned int &,unsigned int const &);
	EXTERN  int GetBases(unsigned int const &,unsigned int * const,unsigned int,unsigned int &);
	EXTERN  int GetCargoHoldSize(unsigned int const &,unsigned int &);
	EXTERN  int GetCostumeID(int &,char const *);
	EXTERN  struct IFileSystem * GetDataPath(void);
	EXTERN  int GetEquipmentID(unsigned int &,char const *);
	EXTERN  int GetFullHealth(unsigned int const &,unsigned int &);
	EXTERN  int GetGoodID(unsigned int &,char const *);
	EXTERN  int GetGoodProperties(unsigned int const &,float &,float &);
	EXTERN  int GetLoadout(struct EquipDescVector &,unsigned int const &);
	EXTERN  int GetLoadoutID(unsigned int &,char const *);
	EXTERN  int GetLoadoutName(unsigned int const &,char *,int);
	EXTERN  unsigned int GetLocationNickname(char *,unsigned int,unsigned int const &);
	EXTERN  int GetLocations(unsigned int const &,unsigned int * const,unsigned int,unsigned int &);
	EXTERN  int GetMaxHitPoints(unsigned int const &,int &);
	EXTERN  int GetNavMapScale(unsigned int,float &);
	EXTERN  unsigned int GetNicknameId(char const *);
	EXTERN  int GetRwTime(double &);
	EXTERN  int GetShipArchSTRID(unsigned int const &,unsigned int &);
	EXTERN  int GetShipID(unsigned int &,char const *);
	EXTERN  int GetSolarType(unsigned int const &,unsigned int &);
	EXTERN  int GetSystem(unsigned int &,unsigned int const &);
	EXTERN  int GetSystemGateConnection(unsigned int const &,unsigned int &);
	EXTERN  int GetSystemID(unsigned int &,char const *);
	EXTERN  unsigned int GetSystemNickname(char *,unsigned int,unsigned int const &);
	EXTERN  int GetTime(double &);
	EXTERN  int GetType(unsigned int const &,unsigned int &);
	EXTERN  int GetVoiceID(unsigned int &,char const *);
	EXTERN  int IsCommodity(unsigned int const &,bool &);
	EXTERN  unsigned short MakeId(char const *);
	EXTERN  bool NextBaseID(unsigned int &);
	EXTERN  bool NextSystemID(unsigned int &);
	EXTERN  int ReportFreeTerminal(unsigned int,int);
	EXTERN  int Save(unsigned int,unsigned int);
	EXTERN  int SetTimer(unsigned int const &,struct Controller::TimerExpired const &,float);
	EXTERN  bool SinglePlayer(void);
	EXTERN  int TranslateArchToGood(unsigned int const &,unsigned int &);
	EXTERN  int TranslateGoodToMsgIdPrefix(unsigned int,struct TString<64> &);
	EXTERN  int TranslateShipToMsgIdPrefix(unsigned int,struct TString<64> &);
	EXTERN  int TranslateSystemToMsgIdPrefix(unsigned int,struct TString<64> &);

	namespace AI
	{
		struct EXTERN ContentCallback
		{
			 virtual void combat_drift_event(void);
			 virtual void combat_state_notification(enum CSNType,unsigned int,unsigned int);
			 virtual void follow_event(unsigned int,unsigned int,enum FollowStatusType,float);
			 virtual enum CreationType  get_creation_type(void);
			 virtual bool information_request(enum InformationType,int,char *);
			 virtual void lead_object_event(unsigned int,unsigned int,enum LeadProgressType,float,class Vector const &);
			 virtual bool request_flee_destination(unsigned int,enum FleeReason,enum FleeDestinationType &,class Vector &,unsigned int &,float &);
			 virtual void scan_state_change(bool);
			 virtual void ship_in_sights_event(unsigned int);
			 virtual void tether_object_event(unsigned int,unsigned int,enum TetherStatusType,class Vector const &);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		EXTERN  enum OP_RTYPE  SubmitDirective(unsigned int,class BaseOp *);
		EXTERN  enum OP_RTYPE  SubmitState(unsigned int,class BaseOp *);
		EXTERN  bool enable_all_maneuvers(unsigned int);
		EXTERN  bool enable_maneuver(unsigned int,int,bool);
		EXTERN  int get_behavior_id(unsigned int);
		EXTERN  bool get_personality(unsigned int,class Personality &);
		EXTERN  enum ScanResponse  get_scan_response(unsigned int,unsigned int,unsigned int);
		EXTERN  int get_state_graph_id(unsigned int);
		EXTERN  bool lock_maneuvers(unsigned int,bool);
		EXTERN  void refresh_state_graph(unsigned int);
		EXTERN  int remove_forced_target(unsigned int,unsigned int);
		EXTERN  enum OP_RTYPE  set_directive_priority(unsigned int,enum DirectivePriority);
		EXTERN  bool set_player_enemy_clamp(unsigned int,int,int);
		EXTERN  int submit_forced_target(unsigned int,unsigned int);
		EXTERN  enum FORMATION_RTYPE  update_formation_state(unsigned int,unsigned int,class Vector const &);
	};

	namespace Audio
	{
		EXTERN  int CancelMusic(unsigned int);
		EXTERN  int PlaySoundEffect(unsigned int,unsigned int);
		EXTERN  int SetMusic(unsigned int,struct Tryptich const &);
	};

	namespace Controller
	{
		EXTERN  unsigned int Create(char const *,char const *,struct CreateParms const *,enum PRIORITY);
		EXTERN  void Destroy(unsigned int);
		EXTERN  int SetHeartbeatInterval(unsigned int const &,float);
		EXTERN  int _SendMessage(unsigned int const &,int,void const *);
	};

	namespace GF
	{
		EXTERN  unsigned long AmbientScriptCreate(struct AmbientScriptDescription const &);
		EXTERN  void AmbientScriptDestroy(unsigned long *);
		EXTERN  unsigned long CharacterBehaviorCreate(struct CharacterBehaviorDescription const &);
		EXTERN  void CharacterBehaviorDestroy(unsigned long *);
		EXTERN  unsigned int CharacterCreate(struct CharacterDescription const &);
		EXTERN  void CharacterDestroy(unsigned int *);
		EXTERN  void CharacterSetBehavior(unsigned int,unsigned long);
		EXTERN  void EnumerateCharacterPlacementIni(unsigned int,void (*)(int,class INI_Reader *,void *),void *);
		EXTERN  unsigned int FindBase(char const *);
		EXTERN  unsigned int FindLocation(unsigned int,char const *);
		EXTERN  char const * FormCharacterPlacementName(struct SetpointProperties const *);
		EXTERN  int GetAccessory(char const *);
		EXTERN  int GetBasePosition(unsigned int const &,unsigned int const &,class Vector &);
		EXTERN  int GetBodyPart(char const *,int);
		EXTERN  unsigned int GetCharacterOnPlacement(unsigned int,unsigned int,int);
		EXTERN  int GetCharacterPlacementByName(unsigned int,char const *,int &);
		EXTERN  char const * GetCharacterPlacementName(unsigned int,int);
		EXTERN  unsigned long GetCharacterPlacementOccupancy(unsigned int,int);
		EXTERN  int GetCharacterPlacementPosture(unsigned int,int,unsigned long &);
		EXTERN  bool GetCharacterPlacementProperties(unsigned int,int,struct SetpointProperties *);
		EXTERN  void GetCostumeByID(int,struct Costume &);
		EXTERN  int GetCostumeSkeletonGender(struct Costume const &,int &);
		EXTERN  int GetMissionVendorOfferCount(unsigned int,unsigned int);
		EXTERN  int GetNumCharacterPlacements(unsigned int);
		EXTERN  float GetRtcPerformanceSlider(void);
		EXTERN  unsigned int GetSpaceflightLocation(void);
		EXTERN  bool IsCharacterPlacementNormal(unsigned int,int);
		EXTERN  bool IsCharacterPlacementSpecial(unsigned int,int);
		EXTERN  void MissionVendorAcceptance(unsigned long,bool,struct FmtStr const &,unsigned int);
		EXTERN  unsigned long MissionVendorOfferCreate(struct MissionVendorOfferDescription const &);
		EXTERN  void MissionVendorOfferDestroy(unsigned long *);
		EXTERN  unsigned long NewsBroadcastCreate(struct NewsBroadcastDescription const &);
		EXTERN  void NewsBroadcastDestroy(unsigned long *);
		EXTERN  int ReportWhyMissionVendorEmpty(unsigned int,enum MVEmptyReason);
	};

	namespace Market
	{
		EXTERN  int GetCommoditiesForSale(unsigned int,unsigned int * const,int *);
		EXTERN  int GetCommoditiesInDemand(unsigned int,unsigned int * const,int *);
		EXTERN  int GetGoodJumpDist(unsigned int,unsigned int &);
		EXTERN  int GetMinInventory(unsigned int,unsigned int,int &);
		EXTERN  int GetNominalPrice(unsigned int,float &);
		EXTERN  int GetNumCommoditiesForSale(unsigned int,int *);
		EXTERN  int GetNumCommoditiesInDemand(unsigned int,int *);
		EXTERN  int GetPrice(unsigned int,unsigned int,float &);
		EXTERN  int IsGoodInDemand(unsigned int,unsigned int,bool &);
	};

	namespace Phantom
	{
		EXTERN  int Attach(unsigned int const &,void *);
		EXTERN  int Create(unsigned int,class Vector const &,class Vector const &,class Matrix const &,unsigned int,void * &);
		EXTERN  int Create(unsigned int,float,class Vector const &,unsigned int,void * &);
		EXTERN  int Destroy(void *);
		EXTERN  int Detach(void *);
		EXTERN  int SetActive(void *,bool);
	};

	namespace Player
	{
		EXTERN  int AddCargo(unsigned int const &,unsigned int const &,unsigned int,float,bool);
		EXTERN  int AdjustCash(unsigned int const &,int);
		EXTERN  int CfgInterfaceNotification(unsigned int,unsigned int,bool,int);
		EXTERN  int DisplayMissionMessage(unsigned int const &,struct FmtStr const &,enum MissionMessageType,bool);
		EXTERN  int EnumerateCargo(unsigned int const &,struct pub::CargoEnumerator &);
		EXTERN  int ForceLand(unsigned int,unsigned int);
		EXTERN  int GetAssetValue(unsigned int const &,float &);
		EXTERN  int GetBase(unsigned int const &,unsigned int &);
		EXTERN  int GetBody(unsigned int const &,unsigned int &);
		EXTERN  int GetCharacter(unsigned int const &,unsigned int &);
		EXTERN  int GetGender(unsigned int const &,int &);
		EXTERN  int GetGroupMembers(unsigned int,std::vector<unsigned int> &);
		EXTERN  int GetGroupSize(unsigned int,unsigned int &);
		EXTERN  int GetLocation(unsigned int const &,unsigned int &);
		EXTERN  int GetMoneyNeededToNextRank(unsigned int const &,int &);
		EXTERN  int GetMsnID(unsigned int,unsigned int &);
		EXTERN  int GetName(unsigned int,std::wstring &);
		EXTERN  int GetNumKills(unsigned int const &,int &);
		EXTERN  int GetNumMissionFailures(unsigned int const &,int &);
		EXTERN  int GetNumMissionSuccesses(unsigned int const &,int &);
		EXTERN  int GetRank(unsigned int const &,int &);
		EXTERN  int GetRelativeHealth(unsigned int const &,float &);
		EXTERN  int GetRemainingHoldSize(unsigned int const &,float &);
		EXTERN  int GetRep(unsigned int const &,int &);
		EXTERN  int GetShip(unsigned int const &,unsigned int &);
		EXTERN  int GetShipID(unsigned int const &,unsigned int &);
		EXTERN  int GetSystem(unsigned int const &,unsigned int &);
		EXTERN  int InspectCash(unsigned int const &,int &);
		EXTERN  int IsGroupMember(unsigned int,unsigned int,bool &);
		EXTERN  int LoadHint(unsigned int,struct BaseHint *);
		EXTERN  int MarkObj(unsigned int,unsigned int,int);
		EXTERN  int PopUpDialog(unsigned int,struct FmtStr const &,struct FmtStr const &,unsigned int);
		EXTERN  int RemoveCargo(unsigned int const &,unsigned short,unsigned int);
		EXTERN  int RemoveFromGroup(unsigned int);
		EXTERN  int ReplaceMissionObjective(unsigned int const &,unsigned int const &,unsigned int,struct MissionObjective const &);
		EXTERN  int ReturnBestPath(unsigned int,unsigned char *,int);
		EXTERN  int ReturnPlayerStats(unsigned int,unsigned char *,int);
		EXTERN  int RevertCamera(unsigned int);
		EXTERN  int RewardGroup(unsigned int,int);
		EXTERN  int SendNNMessage(unsigned int,unsigned int);
		EXTERN  int SetCamera(unsigned int,class Transform const &,float,float);
		EXTERN  int SetCostume(unsigned int const &,int);
		EXTERN  int SetInitialOrnt(unsigned int const &,class Matrix const &);
		EXTERN  int SetInitialPos(unsigned int const &,class Vector const &);
		EXTERN  int SetMissionObjectiveState(unsigned int const &,unsigned int const &,int,unsigned int);
		EXTERN  int SetMissionObjectives(unsigned int const &,unsigned int const &,struct MissionObjective const *,unsigned int,struct FmtStr const &,unsigned char,struct FmtStr const &);
		EXTERN  int SetMoneyNeededToNextRank(unsigned int,int);
		EXTERN  int SetMonkey(unsigned int);
		EXTERN  int SetMsnID(unsigned int,unsigned int,unsigned int,bool,unsigned int);
		EXTERN  int SetNumKills(unsigned int const &,int);
		EXTERN  int SetNumMissionFailures(unsigned int const &,int);
		EXTERN  int SetNumMissionSuccesses(unsigned int const &,int);
		EXTERN  int SetRank(unsigned int,int);
		EXTERN  int SetRobot(unsigned int);
		EXTERN  int SetShipAndLoadout(unsigned int const &,unsigned int,struct EquipDescVector const &);
		EXTERN  int SetStoryCue(unsigned int const &,unsigned int);
		EXTERN  int SetTrent(unsigned int);
	};

	namespace Reputation
	{
		EXTERN  int Alloc(int &,struct FmtStr const &,struct FmtStr const &);
		EXTERN  int EnumerateGroups(struct Enumerator &);
		EXTERN  int Free(int const &);
		EXTERN  int GetAffiliation(int const &,unsigned int &);
		EXTERN  int GetAttitude(int const &,int const &,float &);
		EXTERN  int GetGroupFeelingsTowards(int const &,unsigned int const &,float &);
		EXTERN  int GetGroupName(unsigned int const &,unsigned int &);
		EXTERN  int GetName(int const &,struct FmtStr &,struct FmtStr &);
		EXTERN  int GetRank(int const &,float &);
		EXTERN  int GetReputation(int &,struct ID_String const &);
		EXTERN  int GetReputation(int &,char const *);
		EXTERN  int GetReputation(int const &,unsigned int const &,float &);
		EXTERN  int GetReputation(unsigned int const &,unsigned int const &,float &);
		EXTERN  int GetReputationGroup(unsigned int &,char const *);
		EXTERN  int GetShortGroupName(unsigned int const &,unsigned int &);
		EXTERN  int SetAffiliation(int const &,unsigned int const &);
		EXTERN  int SetAttitude(int const &,int const &,float);
		EXTERN  int SetRank(int const &,float);
		EXTERN  int SetReputation(int const &,unsigned int const &,float);
		EXTERN  int SetReputation(unsigned int const &,unsigned int const &,float);
	};

	namespace SpaceObj
	{
		EXTERN  int Activate(unsigned int const &,bool,int);
		EXTERN  enum EQUIPMENT_RTYPE  ActivateEquipment(unsigned int const &,struct EQInfo *);
		EXTERN  int AddImpulse(unsigned int const &,class Vector const &,class Vector const &);
		EXTERN  int Create(unsigned int &,struct ShipInfo const &);
		EXTERN  int CreateLoot(unsigned int &,struct LootInfo const &);
		EXTERN  int CreateSolar(unsigned int &,struct SolarInfo const &);
		EXTERN  int Destroy(unsigned int,enum DestroyType);
		EXTERN  int Dock(unsigned int const &,unsigned int const &,int,enum DOCK_HOST_RESPONSE);
		EXTERN  int DockRequest(unsigned int const &,unsigned int const &);
		EXTERN  int DrainShields(unsigned int);
		EXTERN  int EnumerateCargo(unsigned int const &,struct pub::CargoEnumerator &);
		EXTERN  int ExistsAndAlive(unsigned int);
		EXTERN  int FormationResponse(unsigned int const &,enum FORMATION_RTYPE);
		EXTERN  int GetArchetypeID(unsigned int const &,unsigned int &);
		EXTERN  int GetAtmosphereRange(unsigned int const &,float &);
		EXTERN  int GetBurnRadius(unsigned int const &,float &,class Vector &);
		EXTERN  int GetCargoSpaceOccupied(unsigned int const &,unsigned int &);
		EXTERN  int GetCenterOfMass(unsigned int const &,class Vector &);
		EXTERN  int GetDockingTarget(unsigned int const &,unsigned int &);
		EXTERN  int GetEmptyPos(unsigned int const &,class Transform const &,float const &,float const &,enum PosSelectionType const &,class Vector &);
		EXTERN  int GetGoodID(unsigned int const &,unsigned int &);
		EXTERN  int GetHardpoint(unsigned int const &,char const *,class Vector *,class Matrix *);
		EXTERN  int GetHealth(unsigned int const &,float &,float &);
		EXTERN  int GetInvincible(unsigned int,bool &,bool &,float &);
		EXTERN  int GetJumpTarget(unsigned int const &,unsigned int &,unsigned int &);
		EXTERN  int GetLocation(unsigned int,class Vector &,class Matrix &);
		EXTERN  int GetMass(unsigned int const &,float &);
		EXTERN  int GetMotion(unsigned int,class Vector &,class Vector &);
		EXTERN  int GetRadius(unsigned int const &,float &,class Vector &);
		EXTERN  int GetRelativeHealth(unsigned int const &,float &);
		EXTERN  int GetRep(unsigned int,int &);
		EXTERN  int GetScannerRange(unsigned int,int &,int &);
		EXTERN  int GetShieldHealth(unsigned int const &,float &,float &,bool &);
		EXTERN  int GetSolarArchetypeID(unsigned int,unsigned int &);
		EXTERN  int GetSolarArchetypeNickname(char *,int,unsigned int);
		EXTERN  int GetSolarParent(unsigned int const &,unsigned int &);
		EXTERN  int GetSolarRep(unsigned int,int &);
		EXTERN  int GetSystem(unsigned int,unsigned int &);
		EXTERN  int GetTarget(unsigned int const &,unsigned int &);
		EXTERN  int GetTerminalInfo(unsigned int const &,int,struct TerminalInfo &);
		EXTERN  int GetTradelaneNextAndPrev(unsigned int const &,unsigned int &,unsigned int &);
		EXTERN  int GetType(unsigned int,unsigned int &);
		EXTERN  int GetVoiceID(unsigned int const &,unsigned int &);
		EXTERN  int InstantDock(unsigned int const &,unsigned int const &,int);
		EXTERN  int IsPosEmpty(unsigned int const &,class Vector const &,float const &,bool &);
		EXTERN  int JettisonEquipment(unsigned int const &,unsigned short const &,int const &);
		EXTERN  int JumpIn(unsigned int const &,unsigned int const &);
		EXTERN  int LaneResponse(unsigned int const &,int);
		EXTERN  int Launch(unsigned int const &,unsigned int const &,int);
		EXTERN  int LightFuse(unsigned int const &,char const *,float);
		EXTERN  int Relocate(unsigned int const &,unsigned int const &,class Vector const &,class Matrix const &);
		EXTERN  int RequestSpaceScript(unsigned int const &,class Vector const &,int const &,unsigned int,char const *);
		EXTERN  int SendComm(unsigned int,unsigned int,unsigned int,struct Costume const *,unsigned int,unsigned int *,int,unsigned int,float,bool);
		EXTERN  int SetInvincible2(unsigned int,bool,bool,float);
		EXTERN  int SetInvincible(unsigned int,bool,bool,float);
		EXTERN  int SetRelativeHealth(unsigned int const &,float);
	};

	namespace System
	{
		EXTERN  int EnumerateConnections(unsigned int const &,struct ConnectionEnumerator &,enum ConnectionType);
		EXTERN  int EnumerateObjects(unsigned int const &,struct SysObjEnumerator &);
		EXTERN  int EnumerateZones(unsigned int const &,struct ZoneEnumerator &);
		EXTERN  int Find(unsigned int const &,char const *,unsigned int &);
		EXTERN  int GetName(unsigned int,unsigned int &);
		EXTERN  int GetNestedProperties(unsigned int const &,class Vector const &,unsigned long &);
		EXTERN  int InZones(unsigned int,class Transform const &,float,float,float,unsigned int * const,unsigned int,unsigned int &);
		EXTERN  int InZones(unsigned int,class Vector const &,float,unsigned int * const,unsigned int,unsigned int &);
		EXTERN  int LoadSystem(unsigned int const &);
		EXTERN  int ScanObjects(unsigned int const &,unsigned int * const,unsigned int,class Vector const &,float,unsigned int,unsigned int &);
	};

	namespace Zone
	{
		EXTERN  float ClassifyPoint(unsigned int,class Vector const &);
		EXTERN  float GetDistance(unsigned int,class Vector const &);
		EXTERN  unsigned int GetId(unsigned int,char const *);
		EXTERN  int GetLootableInfo(unsigned int,struct ID_String &,struct ID_String &,int &,int &,int &);
		EXTERN  int GetName(unsigned int,unsigned int &);
		EXTERN  int GetOrientation(unsigned int const &,class Matrix &);
		//EXTERN  int GetPopulation(unsigned int,class weighted_vector<unsigned int> const * &);
		EXTERN  class Vector  GetPos(unsigned int);
		EXTERN  int GetProperties(unsigned int,unsigned long &);
		EXTERN  float GetRadius(unsigned int);
		EXTERN  int GetShape(unsigned int,enum ZoneShape &);
		EXTERN  int GetSize(unsigned int,class Vector &);
		EXTERN  unsigned int GetSystem(unsigned int);
		EXTERN  bool InZone(unsigned int,class Vector const &,float);
		EXTERN  bool Intersect(unsigned int,class Vector const &,class Vector const &,class Vector &);
		EXTERN  bool VerifyId(unsigned int);
	};

};

EXTERN  void (* g_pPrivateChatHook)(unsigned short *,int);
EXTERN  void (* g_pSystemChatHook)(unsigned short *,int);
EXTERN  void (* g_pUniverseChatHook)(unsigned short *,int);

EXTERN  PlayerDB  Players;
extern "C" struct IChatServer* GetChatServerInterface();
extern "C" struct IServer* GetServerInterface();
extern "C" IServerImpl Server;

#endif // _FLCORESERVER_H_