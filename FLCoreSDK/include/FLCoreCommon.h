//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreCommon.h
//	Module:			FLCoreCommon.lib
//	Description:	Interface to Common.dll
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCORECOMMON_H_
#define _FLCORECOMMON_H_

#include "FLCoreDefs.h"
#include <string>
#include <list>
#include <vector>
#include <map>

#pragma comment( lib, "FLCoreCommon.lib" )


struct EXTERN ActionDB
{
	ActionDB(void);
	~ActionDB(void);
	struct ActionDB & operator=(struct ActionDB const &);
	void add(struct IAction *);
	struct IAction * find(char const *)const ;
	void free(void);
	int get_action_count(void)const ;
	bool remove(struct IAction *);
	void update(float);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN AmbientScriptInfo
{
	AmbientScriptInfo(void);
	~AmbientScriptInfo(void);
	void clear(void);
	void destroy(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN AmbientScriptProperties
{
public:
	AmbientScriptProperties(void);
	~AmbientScriptProperties(void);
	class AmbientScriptProperties & operator=(class AmbientScriptProperties const &);
	void clear(void);
	void destroy(void);
	unsigned long get_key(void)const ;
	void init(struct AmbientScriptDescription const &);
	void marshal(class MarshalBuffer *)const ;
	void unmarshal(class MarshalBuffer *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace AnimDB
{
	EXTERN  void  Add(int);
	EXTERN  void  Add(struct VChannel *);
	EXTERN  unsigned int  Count(void);
	EXTERN  void  Rem(int);
	EXTERN  void  Rem(struct VChannel const *);
	EXTERN  void  Shutdown(void);
	EXTERN  void  Update(float);
};

namespace PhyArch
{
	struct EXTERN Part
	{
		Part(struct Part const &);
		Part(void);
		~Part(void);
		struct Part & operator=(struct Part const &);
		void clear(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	EXTERN  struct Part const *  GetDefaultPart(void);
	EXTERN  bool  LoadSurfaces(char const *,class std::map<unsigned int,struct Part> &);
};

namespace Archetype
{
	class FuseIgnitionList;

	struct EXTERN Armor
	{
		Armor(struct Armor const &);
		Armor(struct ICliObj *);
		virtual ~Armor(void);
		struct Armor & operator=(struct Armor const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Asteroid
	{
		Asteroid(struct Asteroid const &);
		Asteroid(struct ICliObj *);
		virtual ~Asteroid(void);
		struct Asteroid & operator=(struct Asteroid const &);
		virtual enum AClassType  get_class_type(void)const ;
		float get_detect_radius(void)const ;
		float get_offset_dist(void)const ;
		float get_recharge_time(void)const ;
		virtual bool read(class INI_Reader &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN AttachedEquipment
	{
		AttachedEquipment(struct AttachedEquipment const &);
		AttachedEquipment(struct ICliObj *);
		virtual ~AttachedEquipment(void);
		struct AttachedEquipment & operator=(struct AttachedEquipment const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual bool is_attached(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN AttachedFXEquip
	{
		AttachedFXEquip(struct AttachedFXEquip const &);
		AttachedFXEquip(struct ICliObj *);
		virtual ~AttachedFXEquip(void);
		struct AttachedFXEquip & operator=(struct AttachedFXEquip const &);
		virtual enum AClassType  get_class_type(void)const ;

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN CargoPod
	{
		CargoPod(struct CargoPod const &);
		CargoPod(struct ICliObj *);
		virtual ~CargoPod(void);
		struct CargoPod & operator=(struct CargoPod const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN CloakingDevice
	{
		CloakingDevice(struct CloakingDevice const &);
		CloakingDevice(struct ICliObj *);
		virtual ~CloakingDevice(void);
		struct CloakingDevice & operator=(struct CloakingDevice const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN CollisionGroup
	{
		CollisionGroup(struct CollisionGroup const &);
		CollisionGroup(void);
		~CollisionGroup(void);
		struct CollisionGroup & operator=(struct CollisionGroup const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Commodity
	{
		Commodity(struct Commodity const &);
		Commodity(struct ICliObj *);
		virtual ~Commodity(void);
		struct Commodity & operator=(struct Commodity const &);
		virtual enum AClassType  get_class_type(void)const ;
		float get_decay_per_second(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual struct Equipment * get_loot_appearance(void);
		virtual struct CargoPod * get_pod_appearance(void);
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN CounterMeasure
	{
		CounterMeasure(struct CounterMeasure const &);
		CounterMeasure(struct ICliObj *);
		virtual ~CounterMeasure(void);
		struct CounterMeasure & operator=(struct CounterMeasure const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN CounterMeasureDropper
	{
		CounterMeasureDropper(struct CounterMeasureDropper const &);
		CounterMeasureDropper(struct ICliObj *);
		virtual ~CounterMeasureDropper(void);
		struct CounterMeasureDropper & operator=(struct CounterMeasureDropper const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN DamageObjInfo
	{
		DamageObjInfo(struct DamageObjInfo const &);
		DamageObjInfo(void);
		struct DamageObjInfo & operator=(struct DamageObjInfo const &);
		bool operator==(struct DamageObjInfo const &)const;
		bool operator!=(struct DamageObjInfo const &)const ;
		bool operator<(struct DamageObjInfo const &)const ;
		bool operator>(struct DamageObjInfo const &)const ;

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	class EXTERN DamageObjInfoList
	{
	public:
		DamageObjInfoList(class DamageObjInfoList const &);
		DamageObjInfoList(void);
		~DamageObjInfoList(void);
		class DamageObjInfoList & operator=(class DamageObjInfoList const &);
		bool IsValid(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN DynamicAsteroid
	{
		DynamicAsteroid(struct DynamicAsteroid const &);
		DynamicAsteroid(struct ICliObj *);
		virtual ~DynamicAsteroid(void);
		struct DynamicAsteroid & operator=(struct DynamicAsteroid const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual bool read(class INI_Reader &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Engine
	{
		Engine(struct Engine const &);
		Engine(struct ICliObj *);
		virtual ~Engine(void);
		struct Engine & operator=(struct Engine const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN EqObj
	{
		EqObj(struct EqObj const &);
		EqObj(struct ICliObj *);
		virtual ~EqObj(void);
		struct EqObj const & operator=(struct EqObj const &);
		bool dock_terminal_valid(int)const ;
		virtual enum AClassType  get_class_type(void)const ;
		struct CollisionGroup const * get_group_by_id(unsigned short)const ;
		struct CollisionGroup const * get_group_by_name(struct CacheString const &)const ;
		bool get_undamaged_collision_group_list(class std::list<struct CollisionGroupDesc> &)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);
		bool traverse_groups(struct CollisionGroup const * &)const ;

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Equipment
	{
		Equipment(struct Equipment const &);
		Equipment(struct ICliObj *);
		virtual ~Equipment(void);
		struct Equipment & operator=(struct Equipment const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual struct Equipment * get_loot_appearance(void);
		virtual struct CargoPod * get_pod_appearance(void);
		virtual bool is_attached(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Explosion
	{
		Explosion(struct Explosion const &);
		Explosion(struct ID_String const &);
		~Explosion(void);
		struct Explosion & operator=(struct Explosion const &);
		bool read(class INI_Reader &);
		void reset(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Gun
	{
		Gun(struct Gun const &);
		Gun(struct ICliObj *);
		virtual ~Gun(void);
		struct Gun & operator=(struct Gun const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		enum HpAttachmentType  get_hp_type_by_index(int)const ;
		float get_munition_range(void)const ;
		int get_number_of_hp_types(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN InternalFXEquip
	{
		InternalFXEquip(struct InternalFXEquip const &);
		InternalFXEquip(struct ICliObj *);
		virtual ~InternalFXEquip(void);
		struct InternalFXEquip & operator=(struct InternalFXEquip const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Launcher
	{
		Launcher(struct Launcher const &);
		Launcher(struct ICliObj *);
		virtual ~Launcher(void);
		struct Launcher & operator=(struct Launcher const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Light
	{
		Light(struct Light const &);
		Light(struct ICliObj *);
		virtual ~Light(void);
		struct Light & operator=(struct Light const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual bool read(class INI_Reader &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN LootCrate
	{
		LootCrate(struct LootCrate const &);
		LootCrate(struct ICliObj *);
		virtual ~LootCrate(void);
		struct LootCrate & operator=(struct LootCrate const &);
		virtual enum AClassType  get_class_type(void)const ;

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Mine
	{
		Mine(struct Mine const &);
		Mine(struct ICliObj *);
		virtual ~Mine(void);
		struct Mine & operator=(struct Mine const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN MineDropper
	{
		MineDropper(struct MineDropper const &);
		MineDropper(struct ICliObj *);
		virtual ~MineDropper(void);
		struct MineDropper & operator=(struct MineDropper const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Munition
	{
		Munition(struct Munition const &);
		Munition(struct ICliObj *);
		virtual ~Munition(void);
		struct Munition & operator=(struct Munition const &);
		static void  FreeBeamArchIdx(void);
		static void  LoadBeamArchIdx(void);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		bool is_guided(void)const ;
		virtual bool load(void);
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	protected:
		static long  BEAM_ARCH_INDEX;
		virtual void free_resources(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Power
	{
		Power(struct Power const &);
		Power(struct ICliObj *);
		virtual ~Power(void);
		struct Power & operator=(struct Power const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Projectile
	{
		Projectile(struct Projectile const &);
		Projectile(struct ICliObj *);
		virtual ~Projectile(void);
		struct Projectile & operator=(struct Projectile const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual struct Equipment * get_loot_appearance(void);
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN RepairDroid
	{
		RepairDroid(struct RepairDroid const &);
		RepairDroid(struct ICliObj *);
		virtual ~RepairDroid(void);
		struct RepairDroid & operator=(struct RepairDroid const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN RepairKit
	{
		RepairKit(struct RepairKit const &);
		RepairKit(struct ICliObj *);
		virtual ~RepairKit(void);
		struct RepairKit & operator=(struct RepairKit const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual struct Equipment * get_loot_appearance(void);
		virtual bool read(class INI_Reader &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Root
	{
		Root(struct Root const &);
		Root(struct ICliObj *);
		virtual ~Root(void);
		struct Root const & operator=(struct Root const &);
		void AddRef(void);
		int GetRef(void)const ;
		int Release(void);
		long create_instance(struct IEngineInstance *)const ;
		virtual enum AClassType  get_class_type(void)const ;
		long get_engine_index(void)const ;
		unsigned int get_id(void)const ;
		struct PhyArch::Part const * get_phy_part(unsigned int)const ;
		int get_script_index(void)const ;
		bool is_loaded(void)const ;
		virtual bool load(void);
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	protected:
		void free_physical_representation(void);
		virtual void free_resources(void);
		bool init_physical_representation(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Scanner
	{
		Scanner(struct Scanner const &);
		Scanner(struct ICliObj *);
		virtual ~Scanner(void);
		struct Scanner & operator=(struct Scanner const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Shield
	{
		Shield(struct Shield const &);
		Shield(struct ICliObj *);
		virtual ~Shield(void);
		struct Shield & operator=(struct Shield const &);
		virtual enum AClassType  get_class_type(void)const ;

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN ShieldBattery
	{
		ShieldBattery(struct ShieldBattery const &);
		ShieldBattery(struct ICliObj *);
		virtual ~ShieldBattery(void);
		struct ShieldBattery & operator=(struct ShieldBattery const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual struct Equipment * get_loot_appearance(void);
		virtual bool read(class INI_Reader &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN ShieldGenerator
	{
		ShieldGenerator(struct ShieldGenerator const &);
		ShieldGenerator(struct ICliObj *);
		virtual ~ShieldGenerator(void);
		struct ShieldGenerator & operator=(struct ShieldGenerator const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		enum HpAttachmentType  get_hp_type_by_index(int)const ;
		int get_number_of_hp_types(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN ShieldLink
	{
		ShieldLink(struct ShieldLink const &);
		ShieldLink(void);
		~ShieldLink(void);
		struct ShieldLink & operator=(struct ShieldLink const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Ship
	{
		Ship(struct Ship const &);
		Ship(struct ICliObj *);
		virtual ~Ship(void);
		struct Ship & operator=(struct Ship const &);
		static int const  MAX_EXHAUST_NOZZLES;
		virtual enum AClassType  get_class_type(void)const ;
		std::vector<struct CacheString> const * get_legal_hps(enum HpAttachmentType)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Solar
	{
		Solar(struct Solar const &);
		Solar(struct ICliObj *);
		virtual ~Solar(void);
		struct Solar & operator=(struct Solar const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Thruster
	{
		Thruster(struct Thruster const &);
		Thruster(struct ICliObj *);
		virtual ~Thruster(void);
		struct Thruster & operator=(struct Thruster const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN Tractor
	{
		Tractor(struct Tractor const &);
		Tractor(struct ICliObj *);
		virtual ~Tractor(void);
		struct Tractor & operator=(struct Tractor const &);
		virtual enum AClassType  get_class_type(void)const ;
		virtual enum HpAttachmentType  get_hp_type(void)const ;
		virtual bool read(class INI_Reader &);
		virtual void redefine(struct Root const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN TradeLaneEquip
	{
		TradeLaneEquip(struct TradeLaneEquip const &);
		TradeLaneEquip(struct ICliObj *);
		virtual ~TradeLaneEquip(void);
		struct TradeLaneEquip & operator=(struct TradeLaneEquip const &);
		virtual enum AClassType  get_class_type(void)const ;

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};
	
	EXTERN  void  EnumAsteroids(struct ArchEnumerator *);
	EXTERN  void  EnumDynamicAsteroids(struct ArchEnumerator *);
	EXTERN  void  EnumEquipment(struct ArchEnumerator *);
	EXTERN  void  EnumShips(struct ArchEnumerator *);
	EXTERN  void  EnumSimples(struct ArchEnumerator *);
	EXTERN  void  EnumSolars(struct ArchEnumerator *);
	EXTERN  void  Free(void);
	EXTERN  void  FreeExplosions(void);
	EXTERN  int  GetArchMaxHitPts(unsigned int);
	EXTERN  struct Asteroid *  GetAsteroid(unsigned int);
	EXTERN  struct Asteroid *  GetAsteroidByName(struct ID_String const &);
	EXTERN  unsigned int  GetAsteroidID(struct ID_String const &);
	EXTERN  struct DynamicAsteroid *  GetDynamicAsteroid(unsigned int);
	EXTERN  struct DynamicAsteroid *  GetDynamicAsteroidByName(struct ID_String const &);
	EXTERN  unsigned int  GetDynamicAsteroidID(struct ID_String const &);
	EXTERN  struct Equipment *  GetEquipment(unsigned int);
	EXTERN  struct Equipment *  GetEquipmentByName(struct ID_String const &);
	EXTERN  unsigned int  GetEquipmentID(struct ID_String const &);
	EXTERN  struct Explosion *  GetExplosion(struct ID_String const &);
	EXTERN  unsigned int  GetId(enum AClassType,unsigned int);
	EXTERN  unsigned int  GetIdCount(enum AClassType);
	EXTERN  struct MotorData const *  GetMotor(unsigned int);
	EXTERN  struct Ship *  GetShip(unsigned int);
	EXTERN  struct Ship *  GetShipByName(struct ID_String const &);
	EXTERN  unsigned int  GetShipID(struct ID_String const &);
	EXTERN  struct Root *  GetSimple(unsigned int);
	EXTERN  struct Root *  GetSimpleByName(struct ID_String const &);
	EXTERN  unsigned int  GetSimpleID(struct ID_String const &);
	EXTERN  struct Solar *  GetSolar(unsigned int);
	EXTERN  struct Solar *  GetSolarByName(struct ID_String const &);
	EXTERN  unsigned int  GetSolarID(struct ID_String const &);
	EXTERN  unsigned short  LargeIDToSmallID(unsigned int);
	EXTERN  bool  Load(struct IFileSystem *,long *,int *);
	EXTERN  bool  Load(char const *,long *,int *);
	EXTERN  int  LoadAsteroids(char const *,struct ICliObjFactory *);
	EXTERN  int  LoadEquipment(char const *,bool,struct ICliObjFactory *);
	EXTERN  bool  LoadExplosion(class INI_Reader &,bool);
	EXTERN  int  LoadShips(char const *,bool,struct ICliObjFactory *);
	EXTERN  int  LoadSimples(char const *,bool,struct ICliObjFactory *);
	EXTERN  int  LoadSolar(char const *,bool,struct ICliObjFactory *);
	EXTERN  unsigned int  SmallIDToLargeID(unsigned short);

};

namespace Async
{
	struct EXTERN Action
	{
		Action(struct Action const &);
		Action(bool);
		virtual ~Action(void);

		static void * operator new(unsigned int);
		static void operator delete(void *);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	EXTERN  bool  AddWork(struct Action *);
	EXTERN  void  DumpWorkQueue(void);
	EXTERN  void  Shutdown(void);
	EXTERN  void  Startup(void);
	EXTERN  int  WorkQueueSize(void);
};

class EXTERN AttribStackNode
{
public:
	AttribStackNode(class AttribStackNode const &);
	AttribStackNode(enum Op);
	AttribStackNode(void);
	virtual ~AttribStackNode(void);
	class AttribStackNode & operator=(class AttribStackNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	enum Op  get_operation(void);
	void set_operation(enum Op);

	virtual operator class AttribStackNode *(void);
	virtual operator class AttribStackNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN BaseData
{
public:
	BaseData(class BaseData const &);
	BaseData(void);
	~BaseData(void);
	class BaseData & operator=(class BaseData const &);
	unsigned int get_base_id(void)const ;
	std::list<class RoomData *> const * get_const_room_data_list(void)const ;
	std::map<unsigned int,struct MarketGoodInfo> const * get_market(void)const ;
	float get_price_variance(void)const ;
	std::list<class RoomData *> * get_room_data_list(void);
	float get_ship_repair_cost(void)const ;
	unsigned int get_start_location(void)const ;
	void read_from_ini(char const *,unsigned int);
	void set_market_good(unsigned int,int,int,enum TransactionType,float,float,float);

private:
	void read_Base_block(class INI_Reader *);
	void read_Room_block(class INI_Reader *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN BaseDataList
{
public:
	BaseDataList(class BaseDataList const &);
	BaseDataList(void);
	~BaseDataList(void);
	class BaseDataList & operator=(class BaseDataList const &);
	class BaseData * get_base_data(unsigned int)const ;
	std::list<class BaseData *> * get_base_data_list(void);
	std::list<class BaseData *> const * get_const_base_data_list(void)const ;
	class RoomData * get_room_data(unsigned int)const ;
	class RoomData * get_unloaded_room_data(unsigned int)const ;
	void load(void);
	void load_market_data(char const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN BaseHint
{
	BaseHint(struct BaseHint const &);
	BaseHint(void);
	virtual ~BaseHint(void);
	struct BaseHint & operator=(struct BaseHint const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN BaseWatcher
{
	BaseWatcher(void);
	~BaseWatcher(void);
	struct BaseWatcher & operator=(struct BaseWatcher const &);
	void set(struct Watchable const *);

protected:
	void set_pointer(struct Watchable const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace BehaviorTypes
{
	EXTERN  int  get_behavior_id(char const *);
	EXTERN  char const *  get_behavior_name(int);
};

class EXTERN BinaryRDLReader
{
public:
	BinaryRDLReader(class BinaryRDLReader const &);
	BinaryRDLReader(void);
	class BinaryRDLReader & operator=(class BinaryRDLReader const &);
	virtual bool extract_text_from_buffer(unsigned short *,unsigned int,unsigned int &,char const *,unsigned int);
	virtual bool read_buffer(class RenderDisplayList &,char const *,unsigned int);
	virtual bool read_file(class RenderDisplayList &,char const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN BinaryRDLWriter
{
public:
	BinaryRDLWriter(class BinaryRDLWriter const &);
	BinaryRDLWriter(void);
	class BinaryRDLWriter & operator=(class BinaryRDLWriter const &);
	virtual bool write_buffer(class RenderDisplayList const &,char *,unsigned int,unsigned int &);
	virtual bool write_file(class RenderDisplayList const &,char const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN DamageEntry
{
	enum SubObjFate;

	DamageEntry(void);
	struct DamageEntry & operator=(struct DamageEntry const &);
	bool operator==(struct DamageEntry const &)const ;
	bool operator!=(struct DamageEntry const &)const ;
	bool operator<(struct DamageEntry const &)const ;
	bool operator>(struct DamageEntry const &)const ;
	static char const *  FateToString(enum SubObjFate);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN DamageList
{
	DamageList(struct DamageList const &);
	DamageList(void);
	~DamageList(void);
	struct DamageList & operator=(struct DamageList const &);
	static char const *  DmgCauseToString(enum DamageCause);
	void add_damage_entry(unsigned short,float,enum DamageEntry::SubObjFate);
	enum DamageCause  get_cause(void)const ;
	float get_hit_pts_left(unsigned short)const ;
	unsigned int get_inflictor_id(void)const ;
	unsigned int get_inflictor_owner_player(void)const ;
	bool is_destroyed(void)const ;
	bool is_inflictor_a_player(void)const ;
	void set_cause(enum DamageCause);
	void set_destroyed(bool);
	void set_inflictor_id(unsigned int);
	void set_inflictor_owner_player(unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CArchGroup
{
public:
	CArchGroup(struct Archetype::CollisionGroup const &,struct CEqObj * const);
	~CArchGroup(void);
	struct ID_String const & DebrisTypeName(void)const ;
	bool DestroysParent(void)const ;
	float ExplosionGroupImpulse(void)const ;
	float ExplosionParentImpulse(void)const ;
	float ExplosionResistance(void)const ;
	struct ID_String const & ExplosionTypeName(void)const ;
	class Archetype::FuseIgnitionList const & FuseIgnitions(void)const ;
	bool GetCenterOfMass(class Vector &)const ;
	void GetCollisionGroupDesc(struct CollisionGroupDesc &)const ;
	unsigned int GetCollisionGroupType(void)const ;
	enum DamageEntry::SubObjFate  GetFate(void)const ;
	float GetHitPoints(void)const ;
	unsigned short GetID(void)const ;
	float GetMaxHitPoints(void)const ;
	bool GetRadius(float &)const ;
	float GetRelativeHealth(void)const ;
	long GetRootIndex(void)const ;
	bool GetVelocity(class Vector &)const ;
	class Archetype::DamageObjInfoList const & GroupDamageObjs(void)const ;
	int InstDepthInGroup(long)const ;
	bool IsDead(void)const ;
	bool IsDestroyed(void)const ;
	bool IsInstInGroup(long)const ;
	bool IsRootHealthProxy(void)const ;
	void Kill(enum DamageEntry::SubObjFate);
	float LinkedEquipmentDamage(void)const ;
	unsigned int LinkedEquipmentType(void)const ;
	struct CacheString const & Name(void)const ;
	class Archetype::DamageObjInfoList const & ParentDamageObjs(void)const ;
	struct CObject * RetreiveDestroyedObj(void);
	bool Separable(void)const ;
	void SetHitPoints(float);
	void SetRelativeHealth(float);

protected:
	void AttachDamageObjs(struct CObject *,class Archetype::DamageObjInfoList const &)const ;
	void Destroy(void);
	void FreeDamageObjs(void);
	void GetBoundingSphere(float &,class Vector &)const ;
	void LoadDamageObjs(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CArchGroupManager
{
public:
	CArchGroupManager(class CArchGroupManager const &);
	CArchGroupManager(void);
	~CArchGroupManager(void);
	class CArchGroupManager & operator=(class CArchGroupManager const &);
	bool AddNewArchGroup(class CArchGroup *);
	int Clear(void);
	bool DeleteArchGroup(unsigned short);
	bool DestroyDeadGroups(void);
	bool DestroyGroups(struct DamageList const &,bool);
	class CArchGroup * FindByID(unsigned short);
	class CArchGroup const * FindByID(unsigned short)const ;
	class CArchGroup * FindByName(struct CacheString const &);
	class CArchGroup const * FindByName(struct CacheString const &)const ;
	bool Init(struct CEqObj *);
	unsigned short InstToSubObjID(long)const ;
	bool IsOnMap(unsigned short,bool)const ;
	int NumLiving(void)const ;
	int Size(void)const ;
	class CArchGroup * Traverse(class CArchGrpTraverser &);
	class CArchGroup const * Traverse(class CArchGrpTraverser &)const ;

protected:
	void DestroyDeadGroup(class CArchGroup &);
	void DestroyLowerGroups(class CArchGroup const &);
	static int const  MAX_GROUP_DEPTH;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CArchGrpTraverser
{
public:
	CArchGrpTraverser(void);
	class CArchGrpTraverser & operator=(class CArchGrpTraverser const &);
	void Restart(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace Universe
{
	EXTERN  struct IBase *  GetFirstBase(void);
	EXTERN  struct ISystem *  GetFirstSystem(void);
	EXTERN  struct IBase *  GetNextBase(void);
	EXTERN  struct ISystem *  GetNextSystem(void);
	EXTERN  void  Shutdown(void);
	EXTERN  bool  Startup(char const *);
	EXTERN  struct IZone const *  first_zone(unsigned int);
	EXTERN  struct IBase *  get_base(unsigned int);
	EXTERN  unsigned int  get_base_id(char const *);
	EXTERN  void  get_filename(char *,char const *);
	EXTERN  unsigned int  get_gate_system(unsigned int);
	EXTERN  struct IZone *  get_non_const_zone(unsigned int,unsigned int);
	EXTERN  struct IZone *  get_non_const_zone(unsigned int,char const *);
	EXTERN  struct ISystem const *  get_system(unsigned int);  //universe::getsystem
	EXTERN  unsigned int  get_system_id(char const *);
	EXTERN  struct IZone const *  get_zone(unsigned int);
	EXTERN  struct IZone const *  get_zone(unsigned int,char const *);
	EXTERN  struct IZone const *  next_zone(struct IZone const *);
	EXTERN  unsigned int  num_bases(void);
	EXTERN  unsigned int  num_systems(void);
};


namespace Exclusion
{
	struct EXTERN AsteroidExclusionZone
	{
		AsteroidExclusionZone(void);
		~AsteroidExclusionZone(void);
		struct AsteroidExclusionZone & operator=(struct AsteroidExclusionZone const &);
		struct Universe::IZone const * get_zone(void);
		bool set_zone(struct Universe::IZone const *,struct Universe::IZone const *);
		void update_dist(class Vector const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	class EXTERN AsteroidExclusionZoneMgr
	{
	public:
		AsteroidExclusionZoneMgr(class AsteroidExclusionZoneMgr const &);
		AsteroidExclusionZoneMgr(void);
		~AsteroidExclusionZoneMgr(void);
		class AsteroidExclusionZoneMgr & operator=(class AsteroidExclusionZoneMgr const &);
		struct AsteroidExclusionZone * back(void);
		int get_max_billboard_count(void);
		virtual bool is_excluded(class Vector const &,enum ExcludeObjectType,void *);
		void normalize_billboard_density(int);
		virtual void push_back(struct Universe::IZone const *,struct Universe::IZone const *);
		void set_max_cliasteroid_exclusion_distance(float);
		void set_max_dynamicasteroid_exclusion_distance(float);
		virtual void sort(void *);

	private:
		bool is_billboard_excluded(class Vector const &,float *);
		bool is_cliasteroid_excluded(class Vector const &,float *);
		bool is_cmnasteroid_excluded(class Vector const &,float *);
		bool is_dynamic_asteroid_excluded(class Vector const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	struct EXTERN NebulaExclusionZone
	{
		NebulaExclusionZone(void);
		~NebulaExclusionZone(void);
		struct NebulaExclusionZone & operator=(struct NebulaExclusionZone const &);
		float get_fog_far(void);
		struct Universe::IZone const * get_zone(void);
		struct ID_String  get_zone_shell_name(void);
		void set_fog_far(float);
		bool set_zone(struct Universe::IZone const *,struct Universe::IZone const *);
		void set_zone_shell_name(char const *);
		void update_dist(class Vector const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	class EXTERN NebulaExclusionZoneMgr
	{
	public:
		NebulaExclusionZoneMgr(class NebulaExclusionZoneMgr const &);
		NebulaExclusionZoneMgr(void);
		~NebulaExclusionZoneMgr(void);
		class NebulaExclusionZoneMgr & operator=(class NebulaExclusionZoneMgr const &);
		struct NebulaExclusionZone * back(void);
		virtual bool is_excluded(class Vector const &,enum ExcludeObjectType,void *);
		bool is_in_exclusion_zone(class Vector const &,struct NebulaExclusionZone * *,float *,bool);
		virtual void push_back(struct Universe::IZone const *,struct Universe::IZone const *);
		void set_max_distance(float);
		virtual void sort(void *);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

};

namespace CmnAsteroid
{
	class EXTERN CAsteroidCube
	{
	public:
		CAsteroidCube(class CAsteroidCube const &);
		CAsteroidCube(class CAsteroidField *);
		~CAsteroidCube(void);
		CAsteroidCube & operator=(class CAsteroidCube const &);
		struct asteroid_marker * get_changes(void);
		unsigned long get_id(void);
		class Matrix get_orient(void);
		class Vector get_pos(void);
		enum CubeState  get_state(void);
		void init(class Vector const &,unsigned long,struct AsteroidCubeArch *,struct AxisRotations const &,float);
		void set_size(int);
		void set_state(enum CubeState);
		void set_system(unsigned int);

	private:
		bool compute_asteroid_id(class Vector const &,unsigned long &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	class EXTERN CAsteroidField
	{
	public:
		CAsteroidField(class CAsteroidField const &);
		CAsteroidField(void);
		~CAsteroidField(void);
		class CAsteroidField & operator=(class CAsteroidField const &);
		int AddRef(void);
		int Release(void);
		class Vector  closest_cube_pos(class Vector const &);
		unsigned long create_cube_id(class Vector const &);
		class CAsteroidCube * find_cube(unsigned long);
		void flush_changes(void);
		struct AxisRotations & get_axis_rotations(void);
		struct asteroid_marker * get_changes(void);
		int get_cube_size(void);
		class Exclusion::AsteroidExclusionZoneMgr * get_exclusion_mgr(void);
		float get_immersion(class Vector const &);
		struct Universe::IZone const * get_lootable_zone(class Vector const &)const ;
		void load(class INI_Reader &,int);
		bool near_field(class Vector const &);
		float near_field_fraction(class Vector const &,float);
		void populate_asteroids(class Vector const &,class Vector const &);
		void set_cube_size(int);
		void set_empty_freq(float);
		void set_fill_dist(int);
		void set_system(unsigned int);
		void set_zone(struct Universe::IZone const *);

	private:
		void populate_asteroids_internal(class Vector const &,class Vector const &,float);
		void update(float);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	class EXTERN CAsteroidSystem
	{
	public:
		CAsteroidSystem(class CAsteroidSystem const &);
		CAsteroidSystem(void);
		~CAsteroidSystem(void);
		class CAsteroidSystem & operator=(class CAsteroidSystem const &);
		int AddRef(void);
		class CAsteroidField * FindFirst(void);
		class CAsteroidField * FindNext(void);
		int Release(void);
		class CAsteroidField * create_field(void);
		unsigned int get_sys_id(void);
		void set_sys_id(unsigned int);
		void update(struct IObjDB *,float);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	EXTERN  class CAsteroidField *  CreateAsteroidField(unsigned int);
	EXTERN  class CAsteroidSystem *  Find(unsigned int);
	EXTERN  int  Load(unsigned int);
	EXTERN  int  Unload(unsigned int);
	EXTERN  void  Update(struct IObjDB *,float);
	EXTERN  int  closest_cube_coord(int,int,int);
	EXTERN  unsigned long  compute_cube_id(class Vector const &);
	EXTERN  bool  compute_cube_orientation(unsigned long,class Matrix *,struct AxisRotations const &,float);
};

struct EXTERN CAsteroid
{
	CAsteroid(struct CAsteroid const &);
	CAsteroid(void);
	virtual ~CAsteroid(void);
	struct Archetype::Asteroid const * asteroidarch(void)const ;
	unsigned long get_asteroid_id(void);
	class CmnAsteroid::CAsteroidField const * get_owner_field(void);
	virtual class Vector  get_velocity(void)const ;
	void init(struct CreateParms const &);
	bool is_instant_kill(void);
	bool is_mine(void);
	void set_system(unsigned int);
	virtual int update(float,unsigned int);

protected:
	virtual void init_physics(class Vector const &,class Vector const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CAttachedEquip
{
public:
	CAttachedEquip(class CAttachedEquip const &);
	CAttachedEquip(unsigned int,struct CEqObj *,unsigned short,struct Archetype::Equipment const *,bool);
	virtual ~CAttachedEquip(void);
	struct Archetype::AttachedEquipment const * AttachedEquipArch(void)const ;
	virtual bool Connect(char const *);
	virtual bool GetCenterOfMass(class Vector &)const ;
	virtual float GetHitPoints(void)const ;
	struct CObject * GetPhysicsOwner(void)const ;
	virtual bool GetRadius(float &)const ;
	virtual long GetRootIndex(void)const ;
	virtual int GetToughness(void)const ;
	virtual bool GetVelocity(class Vector &)const ;
	virtual bool IsConnected(void)const ;
	virtual bool IsInstOnEquip(long)const ;
	struct CObject * RetrieveDebrisObject(void);
	virtual void SetFate(enum DamageEntry::SubObjFate);
	virtual void SetHitPoints(float);
	virtual bool Update(float,unsigned int);
	static class CAttachedEquip *  cast(class CEquip *);
	static class CAttachedEquip const *  cast(class CEquip const *);

protected:
	virtual void ComputeBoundingSphere(float &,class Vector &)const ;
	virtual void Disconnect(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CAttachmentObj
{
public:
	CAttachmentObj(class CAttachmentObj const &);
	CAttachmentObj(void);
	virtual ~CAttachmentObj(void);
	class CAttachmentObj & operator=(class CAttachmentObj const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CBase
{
	CBase(struct CBase const &);
	CBase(void);
	virtual ~CBase(void);
	struct CBase & operator=(struct CBase const &);
	void advise(bool);
	void cobject(struct CObject *);
	struct CObject * cobject(void)const ;
	long get_index(void)const ;
	void notify_of_destruction(void *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace PhySys
{
	struct CreateParms;

	struct EXTERN Controller
	{
		Controller(struct Controller const &);
		Controller(void);
		virtual ~Controller(void);
		struct Controller & operator=(struct Controller const &);
		static void  Register(struct Controller *,struct CObject *);
		static void  UnRegister(struct Controller *);
		void push(class Vector const &,float);
		void rotate(class Vector const &,float);

	protected:
		virtual void core_is_going_to_be_deleted_event(class IVP_Core *);
		//@@@ virtual class IVP_U_Vector<class IVP_Core> * get_associated_controlled_cores(void);
		virtual enum IVP_CONTROLLER_PRIORITY  get_controller_priority(void);
		void wakeup(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	class EXTERN PhyCollisionStateManager
	{
	public:
		PhyCollisionStateManager(class PhyCollisionStateManager const &);
		PhyCollisionStateManager(struct CObject *);
		~PhyCollisionStateManager(void);
		class PhyCollisionStateManager & operator=(class PhyCollisionStateManager const &);
		void enable_collisions(bool,bool);
		bool get_actual_collision_state(void)const ;
		bool get_desired_collision_state(void)const ;
		//@@@ int get_intruding_cobjs(bool,struct CheapSet<struct CObject *,struct std::less<struct CObject *> > &);
		virtual void mindist_entered_volume(class IVP_Controller_Phantom *,class IVP_Mindist_Base *);
		virtual void mindist_left_volume(class IVP_Controller_Phantom *,class IVP_Mindist_Base *);
		virtual void phantom_is_going_to_be_deleted_event(class IVP_Controller_Phantom *);
		void update(float);

	protected:
		class IVP_Real_Object * get_other_object(class IVP_Mindist_Base *);
		struct CObject * mindist_to_cobject(class IVP_Mindist_Base *);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	EXTERN  float  ANOM_LIMITS_MAX_ANGULAR_VELOCITY_PER_PSI;
	EXTERN  float  ANOM_LIMITS_MAX_VELOCITY;
	EXTERN  void  AddImpulseAtPoint(struct CObject *,class Vector const &,class Vector const &);
	EXTERN  void  AddToAngularVelocityOS(struct CObject *,class Vector const &);
	EXTERN  void  AddToVelocity(struct CObject *,class Vector const &);
	EXTERN  void  AngularImpulse(struct CObject *,class Vector const &,float);
	EXTERN  void  AngularImpulseOS(struct CObject *,class Vector const &,float);
	EXTERN  bool  AnyActive(void);
	EXTERN  void  Attach(struct CObject *,struct CObject *);
	EXTERN  int  AttachPhantom(struct CObject *,void *);
	EXTERN  float  BULLET_LENGTH_FUDGE;
	EXTERN  void  BeamR(struct CObject *,class Vector const &,class Matrix const &,bool);
	EXTERN  void  BuildIVP_Real(struct CObject *,struct CreateParms const &);
	EXTERN  void  BuildIVP_Sphere(struct CObject *,float,struct CreateParms const &);
	EXTERN  int  CreatePhantom(struct PhantomParms const &,struct PhyArch::Part const &,void * &);
	EXTERN  int  CreatePhantom(struct PhantomParms const &,class Vector const &,void * &);
	EXTERN  int  CreatePhantom(struct PhantomParms const &,float,void * &);
	EXTERN  class Vector  DEFAULT_ANGULAR_DAMPING;
	EXTERN  float  DEFAULT_LINEAR_DAMPING;
	EXTERN  void  DeactivatePhysics(struct CObject *);
	EXTERN  void  DeactivatePhysicsR(struct CObject *);
	EXTERN  void  DestroyPhantom(void *);
	EXTERN  void  Detach(struct CObject *,struct DetachParms const &);
	EXTERN  int  DetachPhantom(void *);
	EXTERN  int  FindRayCollisions(unsigned int,class Vector const &,class Vector const &,struct RayHit *,int);
	EXTERN  int  FindRayIntersect(struct CObject *,class Vector const &,class Vector const &,struct RayHit *,int);
	EXTERN  int  FindSphereCollisions(unsigned int,class Vector const &,float,struct CObject * *,int);
	EXTERN  float  GOLEM_ANGULAR_DAMP_FACTOR;
	EXTERN  class Vector  GOLEM_CHILD_ANGULAR_DAMP;
	EXTERN  float  GOLEM_CHILD_LINEAR_DAMP;
	EXTERN  float  GOLEM_CHILD_MASS;
	EXTERN  float  GOLEM_DAMP_FACTOR;
	EXTERN  float  GOLEM_DELTA_ORIENTATION;
	EXTERN  float  GOLEM_FORCE_FACTOR;
	EXTERN  float  GOLEM_MAX_DELTA_POSITION;
	EXTERN  float  GOLEM_MAX_TORQUE;
	EXTERN  class Vector  GOLEM_MAX_TRANSLATION_FORCE;
	EXTERN  float  GOLEM_TORQUE_FACTOR;
	EXTERN  void  GenerateCollisions(struct CBeam *);
	EXTERN  class Vector   GetAngularVelocityOS(struct CObject const *);
	EXTERN  class Vector   GetCenterOfMass(struct CObject const *);
	EXTERN  bool  GetClosestPhantomIntruderPos(void *,unsigned int,unsigned int,struct CSimple * &,class Vector &);
	EXTERN  char const *  GetCollisionGroup(struct CObject const *);
	EXTERN  bool  GetCollisionState(struct CObject const *);
	EXTERN  bool  GetCollisionStatePhantom(void * const);
	EXTERN  void  GetCollisions(unsigned int,struct CollisionEvent const * &,struct CollisionEvent const * &);
	EXTERN  class IVP_Time   GetCurrentTime(unsigned int);
	EXTERN  void  GetDamping(struct CObject const *,float &,class Vector &);
	EXTERN  float  GetMass(struct CObject const *);
	EXTERN  class Vector   GetMomentOfInertia(struct CObject const *);
	EXTERN  float  GetRadiusR(struct CObject const *,bool,class Vector &);
	EXTERN  class Vector   GetVelocity(struct CObject const *);
	EXTERN  void  LinearImpulse(struct CObject *,class Vector const &,float);
	EXTERN  double  MATERIAL_ELASTICITY;
	EXTERN  double  MATERIAL_FRICTION;
	EXTERN  int  MAX_SPAWNED_MINDIST_COUNT;
	EXTERN  double  MIN_TIME_BETWEEN_COLLISIONS;
	EXTERN  unsigned int  MovingObjectCount(unsigned int);
	EXTERN  float  PHYSICAL_SIM_RATE;
	EXTERN  void  RCBegin(struct CSimple *,class Vector const &,class Vector const &,class Quaternion const &,class Vector const &);
	EXTERN  void  RCEnd(struct CSimple *);
	EXTERN  void  RCSet(struct CSimple *,class Vector const &,class Quaternion const &,double);
	EXTERN  float  RC_MAX_DELTA_ORIENTATION;
	EXTERN  float  RC_MAX_DELTA_POSITION;
	EXTERN  float  RMGR_LOOK_AHEAD_MAX_DISTANCE_INTRA;
	EXTERN  float  RMGR_LOOK_AHEAD_MAX_DISTANCE_WORLD;
	EXTERN  float  RMGR_LOOK_AHEAD_MAX_RADIUS_INTRA;
	EXTERN  float  RMGR_LOOK_AHEAD_MAX_RADIUS_WORLD;
	EXTERN  float  RMGR_LOOK_AHEAD_MIN_DISTANCE_INTRA;
	EXTERN  float  RMGR_LOOK_AHEAD_MIN_DISTANCE_WORLD;
	EXTERN  float  RMGR_LOOK_AHEAD_MIN_SECONDS_INTRA;
	EXTERN  float  RMGR_LOOK_AHEAD_MIN_SECONDS_WORLD;
	EXTERN  float  RMGR_LOOK_AHEAD_TIME_INTRA;
	EXTERN  float  RMGR_LOOK_AHEAD_TIME_WORLD;
	EXTERN  void  ReMakePhysicalR(struct CObject *,struct CreateParms const &,float);
	EXTERN  void  SetCollisionGroup(struct CObject *,char const * const);
	EXTERN  void  SetCollisionState(struct CObject *,bool);
	EXTERN  void  SetCollisionStatePhantom(void *,bool);
	EXTERN  void  SetDamping(struct CObject *,float,class Vector const &);
	EXTERN  void  SetMass(struct CObject *,float);
	EXTERN  void  SetMomentOfInertia(struct CObject *,class Vector const &);
	EXTERN  void  Shutdown(unsigned int);
	EXTERN  void  Startup(unsigned int);
	EXTERN  void  UnMakePhysicalR(struct CObject *);
	EXTERN  void  Update(unsigned int,float);
	EXTERN  void  Wakeup(struct CObject *);
	EXTERN  enum IVP_BOOL  (* m_pCollisionFilter)(class IVP_Real_Object *,class IVP_Real_Object *);
};

struct EXTERN CObject
{
	enum Class;

	CObject(struct CObject const &);
	unsigned int AddRef(void);
	static struct CObject *  Alloc(enum Class);
	static int  Count(enum Class);
	static struct CObject *  Find(unsigned int const &,enum Class);
	static struct CObject *  Find(long,enum Class);
	static struct CObject *  FindFirst(enum Class);
	static struct CObject *  FindNext(void);
	static unsigned int const  NO_ACTIONS;
	static unsigned int const  NO_BEHAVIOR;
	static unsigned int const  NO_COUNTERMEASURE_AI;
	static unsigned int const  NO_DYNAMICS;
	static unsigned int const  NO_SCANNER;
	unsigned int Release(void);
	static void  ReleaseAll(void);
	static unsigned int const  UPDATE_DEFAULT;
	static unsigned int const  UPDATE_DUMB;
	void add_impulse(class Vector const &,class Vector const &);
	void add_impulse(class Vector const &);
	void advise(struct CBase *,bool);
	virtual void beam_object(class Vector const &,class Matrix const &,bool);
	virtual void __stdcall destroy_instance(long);
	virtual void disable_controllers(void);
	void enable_collisions_r(bool);
	virtual void enable_controllers(void);
	bool flag_part_as_shield(unsigned int);
	virtual class Vector  get_angular_velocity(void)const ;
	struct Archetype::Root * get_archetype(void)const ;
	virtual class Vector  get_center_of_mass(void)const ;
	//void get_intruder_set_r(struct CheapSet<struct CObject *,struct std::less<struct CObject *> > &);
	virtual float get_mass(void)const ;
	class Vector  get_moment_of_inertia(void)const ;
	virtual float get_physical_radius_r(class Vector &)const ;
	virtual bool get_surface_extents(class Vector &,class Vector &)const ;
	virtual class Vector  get_velocity(void)const ;
	float hierarchy_radius(class Vector &)const ;
	float hierarchy_radius(void)const ;
	unsigned int inst_to_part(long)const ;
	bool is_shield_part(unsigned int)const ;
	virtual void open(struct Archetype::Root *);
	long part_to_inst(unsigned int)const ;
	virtual void remake_physical(struct PhySys::CreateParms const &,float);
	virtual void unmake_physical(void);
	virtual int update(float,unsigned int);

	static void * operator new(unsigned int);
	static void operator delete(void *);


protected:
	CObject(enum Class);
	virtual ~CObject(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CBeam
{
	CBeam(struct CBeam const &);
	CBeam(enum CObject::Class);
	virtual ~CBeam(void);
	char const * get_collision_group(void)const ;
	class Vector const & get_last_pos(void)const ;
	virtual float get_mass(void)const ;
	virtual class Vector  get_velocity(void)const ;
	void move(float);
	struct Archetype::Munition const * munitionarch(void)const ;
	void set_velocity(class Vector const &);

protected:
	virtual void expire_safe_time(void);
	virtual void init_physics(class Vector const &,class Vector const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CCounterMeasure
{
	CCounterMeasure(struct CCounterMeasure const &);
	CCounterMeasure(enum CObject::Class);
	virtual ~CCounterMeasure(void);
	struct Archetype::CounterMeasure const * countermeasure_arch(void);
	virtual int update(float,unsigned int);

protected:
	virtual void expire_safe_time(void);
	virtual void init_physics(class Vector const &,class Vector const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CDeadReckonedVector
{
public:
	CDeadReckonedVector(class CDeadReckonedVector const &);
	CDeadReckonedVector(void);
	virtual ~CDeadReckonedVector(void);
	class CDeadReckonedVector & operator=(class CDeadReckonedVector const &);
	void AddSample(class Vector const &,double);
	double CalcError(class Vector const &);
	double ConvergeTime(void);
	void Doit(double);
	class Vector const & GetProjectedPosition(void);
	class Vector const & GetSample(int);
	void NormalizeProjectedPosition(void);
	void NormalizeTrackedPosition(void);
	class Vector  ProjectVelocity(double);
	void Reset(void);
	void SetMaxCorrectiveConvergeTime(double);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CDynamicAsteroid
{
	CDynamicAsteroid(struct CDynamicAsteroid const &);
	CDynamicAsteroid(void);
	virtual ~CDynamicAsteroid(void);
	struct Archetype::DynamicAsteroid const * dynamicAsteroidArch(void)const ;
	void init(struct CreateParms const &);
	virtual int update(float,unsigned int);

protected:
	virtual void init_physics(class Vector const &,class Vector const &,unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEArmor
{
public:
	CEArmor(class CEArmor const &);
	CEArmor(struct CEqObj *,unsigned short,struct Archetype::Armor const *,bool);
	virtual ~CEArmor(void);
	struct Archetype::Armor const * ArmorArch(void)const ;
	static class CEArmor *  cast(class CEquip *);
	static class CEArmor const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEAttachedFX
{
public:
	CEAttachedFX(class CEAttachedFX const &);
	CEAttachedFX(struct CEqObj *,unsigned short,struct Archetype::AttachedFXEquip const *,bool);
	virtual ~CEAttachedFX(void);
	struct Archetype::AttachedFXEquip const * FXArch(void)const ;
	virtual void NotifyArchGroupDestroyed(unsigned short);
	static class CEAttachedFX *  cast(class CEquip *);
	static class CEAttachedFX const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CECargo
{
public:
	CECargo(class CECargo const &);
	CECargo(struct CEqObj *,unsigned short,struct Archetype::Equipment const *,bool);
	virtual ~CECargo(void);
	void AddToStack(unsigned int,float);
	virtual void Destroy(void);
	class CECargoPod const * GetContainer(void)const ;
	unsigned int GetCount(void)const ;
	float GetDecayDamagePerSecond(void)const ;
	virtual bool GetEquipDesc(struct EquipDesc &)const ;
	virtual float GetHitPoints(void)const ;
	virtual unsigned int GetType(void)const ;
	virtual void Init(float,unsigned int,struct CacheString const &);
	virtual bool IsDestroyed(void)const ;
	void RemoveFromStack(unsigned int);
	void SetCount(unsigned int);
	virtual void SetHitPoints(float);
	static class CECargo *  cast(class CEquip *);
	static class CECargo const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CECargoPod
{
public:
	CECargoPod(class CECargoPod const &);
	CECargoPod(struct CEqObj *,unsigned short,struct Archetype::CargoPod const *,bool);
	virtual ~CECargoPod(void);
	virtual void Destroy(void);
	void EmptyPod(void);
	void FillPod(class CECargo *);
	class CECargo const * GetContents(void)const ;
	virtual bool IsLootable(void)const ;
	static class CECargoPod *  cast(class CEquip *);
	static class CECargoPod const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CECloakingDevice
{
public:
	CECloakingDevice(class CECloakingDevice const &);
	CECloakingDevice(struct CEqObj *,unsigned short,struct Archetype::CloakingDevice const *,bool);
	virtual ~CECloakingDevice(void);
	virtual bool Activate(bool);
	struct Archetype::CloakingDevice const * CloakArch(void)const ;
	virtual bool Update(float,unsigned int);
	static class CECloakingDevice *  cast(class CEquip *);
	static class CECloakingDevice const *  cast(class CEquip const *);
	float cloak_percent(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CECounterMeasureDropper
{
public:
	CECounterMeasureDropper(class CECounterMeasureDropper const &);
	CECounterMeasureDropper(struct CEqObj *,unsigned short,struct Archetype::CounterMeasureDropper const *,bool);
	virtual ~CECounterMeasureDropper(void);
	struct Archetype::CounterMeasure const * CounterMeasureArch(void);
	struct Archetype::CounterMeasureDropper const * CounterMeasureDropperArch(void);
	virtual bool Update(float,unsigned int);
	static class CECounterMeasureDropper *  cast(class CEquip *);
	static class CECounterMeasureDropper const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEEngine
{
public:
	CEEngine(class CEEngine const &);
	CEEngine(struct CShip *,unsigned short,struct Archetype::Engine const *,bool);
	virtual ~CEEngine(void);
	virtual bool Activate(bool);
	static void  BuildNozzleHPName(int,struct CacheString &);
	virtual bool DisableController(void);
	virtual bool EnableController(void);
	bool EngageCruise(bool,bool);
	struct Archetype::Engine const * EngineArch(void)const ;
	float GetCruiseChargeTime(void)const ;
	float GetCruiseChargeTimeElapsed(void)const ;
	float GetCruiseDrag(void)const ;
	float GetCruisePowerDraw(void)const ;
	float GetCruiseThrust(float)const ;
	float GetLinearDrag(void)const ;
	float GetPowerDraw(float)const ;
	float GetThrust(float)const ;
	virtual bool IsControllerEnabled(void)const ;
	bool IsCruiseEngaged(void)const ;
	virtual bool IsFunctioning(void)const ;
	virtual void NotifyArchGroupDestroyed(unsigned short);
	std::vector<struct ExhaustNozzleInfo> const & NozzleInfos(void)const ;
	virtual bool Update(float,unsigned int);
	static class CEEngine *  cast(class CEquip *);
	static class CEEngine const *  cast(class CEquip const *);

protected:
	//@@@ virtual void do_simulation_controller(class IVP_Event_Sim *,class IVP_U_Vector<class IVP_Core> *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEGun
{
public:
	CEGun(class CEGun const &);
	CEGun(struct CEqObj *,unsigned short,struct Archetype::Gun const *,bool);
	virtual ~CEGun(void);
	virtual bool Activate(bool);
	bool CanPointAt(class Vector const &,float)const ;
	bool CanSeeTargetObject(float)const ;
	bool CanSeeTargetPoint(class Vector const &,float)const ;
	bool ComputeTgtLeadPosition(class Vector &)const ;
	static bool  ComputeTimeToTgt(class Vector const &,class Vector const &,float,float &);
	virtual bool Connect(char const *);
	virtual void ConsumeFireResources(void);
	virtual enum FireResult  Fire(class Vector const &);
	float GetMunitionRange(void)const ;
	float GetSecondsTillLock(void)const ;
	void GetTarget(struct CSimple * &,unsigned short &)const ;
	class Vector  GetTurretOrigin(void)const ;
	struct Archetype::Gun const * GunArch(void)const ;
	bool IsJointInMotion(void)const ;
	struct Archetype::Munition const * MunitionArch(void)const ;
	bool SetTarget(struct CSimple *,unsigned short);
	void SetTargetPoint(class Vector const &);
	virtual bool Update(float,unsigned int);
	static class CEGun *  cast(class CEquip *);
	static class CEGun const *  cast(class CEquip const *);
	bool is_guided(void)const ;

protected:
	virtual enum FireResult  CanFire(class Vector const &)const ;
	virtual void ComputeLaunchInfo_OneBarrel(struct ProjLaunchInfo &,int,class Vector const &)const ;
	void ComputeTurretFrame(void);
	void DecomposeJointMotion(class Vector const &,float &,float &)const ;
	virtual void Disconnect(void);
	bool GetTargetObjectPos(class Vector &)const ;
	bool IsMovable(void)const ;
	void LocateJoints(void);
	void LoseJoints(void);
	static float const  TARGET_POINT_VALID_TIME;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEInternalFX
{
public:
	CEInternalFX(class CEInternalFX const &);
	CEInternalFX(struct CEqObj *,unsigned short,struct Archetype::InternalFXEquip const *,bool);
	virtual ~CEInternalFX(void);
	virtual void Destroy(void);
	struct Archetype::InternalFXEquip const * InternalFXArch(void)const ;
	static class CEInternalFX *  cast(class CEquip *);
	static class CEInternalFX const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CELauncher
{
public:
	CELauncher(class CELauncher const &);
	virtual ~CELauncher(void);
	virtual bool AmmoNeedsMet(void)const ;
	virtual void ComputeLaunchInfo(class std::vector<struct ProjLaunchInfo> &,class Vector const &)const ;
	void ComputeProjectilePosAndVelocity_OneBarrel(class Vector &,class Vector &,int,class Vector const &)const ;
	virtual bool Connect(char const *);
	virtual void ConsumeFireResources(void);
	virtual enum FireResult  Fire(class Vector const &);
	virtual int GetAmmoCount(void)const ;
	class Vector  GetAvgBarrelDirWS(void)const ;
	class Vector  GetAvgBarrelPosWS(void)const ;
	class Vector  GetBarrelDirWS(unsigned int)const ;
	struct Barrel const * GetBarrelInfo(unsigned int)const ;
	class Vector  GetBarrelPosWS(unsigned int)const ;
	virtual float GetPowerDrawPerFire(void)const ;
	unsigned int GetProjectilesPerFire(void)const ;
	virtual void GetStatus(struct EquipStatus &)const ;
	virtual bool IsDisabled(void)const ;
	struct Archetype::Launcher const * LauncherArch(void)const ;
	struct Archetype::Projectile const * ProjectileArch(void)const ;
	virtual bool Update(float,unsigned int);
	static class CELauncher *  cast(class CEquip *);
	static class CELauncher const *  cast(class CEquip const *);

protected:
	CELauncher(unsigned int,struct CEqObj *,unsigned short,struct Archetype::Launcher const *,bool);
	virtual enum FireResult  CanFire(class Vector const &)const ;
	virtual void ComputeLaunchInfo_OneBarrel(struct ProjLaunchInfo &,int,class Vector const &)const ;
	virtual void Disconnect(void);
	virtual void DrawAmmoFromCargo(int);
	virtual void DrawPower(int);
	virtual bool PowerNeedsMet(void)const ;
	virtual bool RefireDelayElapsed(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CELightEquip
{
public:
	CELightEquip(class CELightEquip const &);
	CELightEquip(struct CEqObj *,unsigned short,struct Archetype::Light const *,bool);
	virtual ~CELightEquip(void);
	struct Archetype::Light const * LightArch(void)const ;
	virtual void NotifyArchGroupDestroyed(unsigned short);
	static class CELightEquip *  cast(class CEquip *);
	static class CELightEquip const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEMineDropper
{
public:
	CEMineDropper(class CEMineDropper const &);
	CEMineDropper(struct CEqObj *,unsigned short,struct Archetype::MineDropper const *,bool);
	virtual ~CEMineDropper(void);
	struct Archetype::Mine const * MineArch(void);
	struct Archetype::MineDropper const * MineDropperArch(void);
	static class CEMineDropper *  cast(class CEquip *);
	static class CEMineDropper const *  cast(class CEquip const *);

protected:
	virtual enum FireResult  CanFire(class Vector const &)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEPower
{
public:
	CEPower(class CEPower const &);
	CEPower(struct CEqObj *,unsigned short,struct Archetype::Power const *,bool);
	virtual ~CEPower(void);
	float GetCapacity(void)const ;
	float GetChargeRate(void)const ;
	float GetThrustCapacity(void)const ;
	float GetThrustChargeRate(void)const ;
	virtual bool Update(float,unsigned int);
	static class CEPower *  cast(class CEquip *);
	static class CEPower const *  cast(class CEquip const *);

protected:
	struct Archetype::Power const * PowerArch(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CERepairDroid
{
public:
	CERepairDroid(class CERepairDroid const &);
	CERepairDroid(struct CEqObj *,unsigned short,struct Archetype::RepairDroid const *,bool);
	virtual ~CERepairDroid(void);
	virtual float GetHitPoints(void)const ;
	struct Archetype::RepairDroid const * RepairDroidArch(void)const ;
	virtual void SetHitPoints(float);
	static class CERepairDroid *  cast(class CEquip *);
	static class CERepairDroid const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEScanner
{
public:
	CEScanner(class CEScanner const &);
	CEScanner(struct CEqObj *,unsigned short,struct Archetype::Scanner const *,bool);
	virtual ~CEScanner(void);
	float GetCargoScanRange(void)const ;
	float GetRadarRange(void)const ;
	enum ScanResult  ScanCargo(struct CEqObj *);
	struct Archetype::Scanner const * ScannerArch(void)const ;
	virtual bool Update(float,unsigned int);
	static class CEScanner *  cast(class CEquip *);
	static class CEScanner const *  cast(class CEquip const *);
	void clear_cache(void);
	void scan_for_types(unsigned int);

protected:
	virtual bool add_obj(struct IObjRW *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEShield
{
public:
	CEShield(class CEShield const &);
	CEShield(struct CEqObj *,unsigned short,struct Archetype::Shield const *,bool);
	virtual ~CEShield(void);
	virtual bool Activate(bool);
	void AttachIntruderChecker(void);
	virtual bool Connect(char const *);
	virtual void Destroy(void);
	void DestroyIntruderChecker(void);
	virtual bool GetEquipDesc(struct EquipDesc &)const ;
	virtual float GetHitPoints(void)const ;
	virtual float GetMaxHitPoints(void)const ;
	float GetOfflineRebuildTime(void)const ;
	float GetOfflineThreshold(void)const ;
	float GetWeaponModifier(struct ID_String const &)const ;
	virtual bool IsFunctioning(void)const ;
	virtual bool IsLootable(void)const ;
	virtual void SetFate(enum DamageEntry::SubObjFate);
	virtual void SetHitPoints(float);
	struct Archetype::Shield const * ShieldArch(void)const ;
	void ShieldBatteryBoost(float);
	struct Archetype::ShieldGenerator const * ShieldGenArch(void)const ;
	virtual bool Update(float,unsigned int);
	static class CEShield *  cast(class CEquip *);
	static class CEShield const *  cast(class CEquip const *);

protected:
	bool Activate_Internal(bool);
	void AddGen(class CEShieldGenerator *);
	bool CanActivate(void)const ;
	virtual void Disconnect(void);
	void RemGen(class CEShieldGenerator *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEShieldGenerator
{
public:
	CEShieldGenerator(class CEShieldGenerator const &);
	CEShieldGenerator(struct CEqObj *,unsigned short,struct Archetype::ShieldGenerator const *,bool);
	virtual ~CEShieldGenerator(void);
	virtual void Destroy(void);
	virtual bool IsFunctioning(void)const ;
	bool IsLinked(void)const ;
	void LinkShield(class CEShield *);
	struct Archetype::ShieldGenerator const * ShieldGenArch(void)const ;
	void UnLinkShield(void);
	virtual bool Update(float,unsigned int);
	static class CEShieldGenerator *  cast(class CEquip *);
	static class CEShieldGenerator const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEThruster
{
public:
	CEThruster(class CEThruster const &);
	CEThruster(struct CEqObj *,unsigned short,struct Archetype::Thruster const *,bool);
	virtual ~CEThruster(void);
	virtual bool Activate(bool);
	bool CouldThrust(void)const ;
	virtual bool DisableController(void);
	virtual bool EnableController(void);
	float GetPowerDraw(void)const ;
	float GetThrust(void)const ;
	virtual bool IsControllerEnabled(void)const ;
	struct Archetype::Thruster const * ThrusterArch(void)const ;
	static class CEThruster *  cast(class CEquip *);
	static class CEThruster const *  cast(class CEquip const *);

protected:
	//@@@ virtual void do_simulation_controller(class IVP_Event_Sim *,class IVP_U_Vector<class IVP_Core> *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CETractor
{
public:
	CETractor(class CETractor const &);
	CETractor(struct CShip *,unsigned short,struct Archetype::Tractor const *,bool);
	virtual ~CETractor(void);
	enum TractorFailureCode  AddTarget(struct CLoot *);
	int CountActiveArms(void)const ;
	float GetRange(void)const ;
	class Vector  GetSourcePos(void)const ;
	class TractorArm const * GetTractorArm(unsigned int)const ;
	class std::vector<class TractorArm> const & GetTractorArms(void)const ;
	void RemoveTarget(unsigned int);
	struct Archetype::Tractor const * TractorArch(void)const ;
	virtual bool Update(float,unsigned int);
	enum TractorFailureCode  VerifyTarget(struct CLoot const *)const ;
	static class CETractor *  cast(class CEquip *);
	static class CETractor const *  cast(class CEquip const *);

protected:
	bool CanSeeTarget(struct CLoot const *)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CETradeLaneEquip
{
public:
	CETradeLaneEquip(class CETradeLaneEquip const &);
	CETradeLaneEquip(struct CEqObj *,unsigned short,struct Archetype::TradeLaneEquip const *,bool);
	virtual ~CETradeLaneEquip(void);
	struct Archetype::TradeLaneEquip const * TradeLaneArch(void)const ;
	static class CETradeLaneEquip *  cast(class CEquip *);
	static class CETradeLaneEquip const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct INotify
{
	enum Event;
};

struct EXTERN CEqObj
{
	struct EXTERN DockAnimInfo
	{
		DockAnimInfo(void);
		struct DockAnimInfo & operator=(struct DockAnimInfo const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	CEqObj(struct CEqObj const &);
	virtual enum ObjActivateResult  activate(bool,unsigned int);
	virtual bool add_item(struct EquipDesc const &);
	void attaching_damaged_obj(struct CacheString const &);
	float attitude_towards(struct CEqObj const *)const ;
	void attitude_towards_symmetrical(float &,struct CEqObj const *,float &)const ;
	void clear_arch_groups(void);
	virtual void clear_equip_and_cargo(void);
	virtual void connect(struct INotify *);
	virtual void connect(struct IObjDB *);
	class IBehaviorManager * create_behavior_interface(struct IObjRW *,int);
	virtual void destroy_sub_objs(struct DamageList const &,bool);
	virtual void disable_controllers(void);
	virtual void disconnect(struct INotify *);
	virtual void disconnect(struct IObjDB *);
	virtual void disconnect(struct IObjRW *);
	virtual void enable_controllers(void);
	virtual int enumerate_sub_objs(void)const ;
	struct Archetype::EqObj * eqobjarch(void)const ;
	virtual void flush_animations(void);
	virtual bool get_activate_state(class std::vector<bool,class std::allocator<bool> > &);
	unsigned int get_base(void)const ;
	unsigned int get_base_name(void)const ;
	class IBehaviorManager * get_behavior_interface(void);
	float get_cloak_percentage(void)const ;
	void get_collision_group_description(class std::list<struct CollisionGroupDesc> &)const ;
	unsigned int const & get_dock_target(void)const ;
	virtual void get_equip_desc_list(struct EquipDescVector &)const ;
	bool get_explosion_dmg_bounding_sphere(float &,class Vector &)const ;
	float get_max_power(void)const ;
	virtual unsigned int get_name(void)const ;
	float get_power(void)const ;
	float get_power_ratio(void)const ;
	virtual bool get_sub_obj_center_of_mass(unsigned short,class Vector &)const ;
	virtual bool get_sub_obj_hit_pts(unsigned short,float &)const ;
	virtual bool get_sub_obj_max_hit_pts(unsigned short,float &)const ;
	virtual bool get_sub_obj_relative_health(unsigned short,float &)const ;
	virtual bool get_sub_obj_velocity(unsigned short,class Vector &)const ;
	virtual float get_total_hit_pts(void)const ;
	virtual float get_total_max_hit_pts(void)const ;
	virtual float get_total_relative_health(void)const ;
	int get_vibe(void)const ;
	virtual unsigned short inst_to_subobj_id(long)const ;
	bool is_base(void)const ;
	int is_cloaked(void)const ;
	bool is_control_excluded(unsigned int)const ;
	bool is_damaged_obj_attached(struct CacheString const &)const ;
	bool is_dock(void)const ;
	virtual bool is_targetable(void)const ;
	bool launch_pos(class Vector &,class Matrix &,int)const ;
	void load_arch_groups(class std::list<struct CollisionGroupDesc> const &);
	virtual void load_equip_and_cargo(struct EquipDescVector const &,bool);
	virtual void notify(enum INotify::Event,void *);
	virtual void remake_physical(struct PhySys::CreateParms const &,float);
	void set_control_exclusion(unsigned int);
	void set_power(float);
	virtual bool set_sub_obj_hit_pts(unsigned short,float);
	virtual long sub_obj_id_to_inst(unsigned short)const ;
	bool sync_cargo(class EquipDescList const &);
	virtual void unmake_physical(void);
	virtual int update(float,unsigned int);

protected:
	CEqObj(enum CObject::Class);
	virtual ~CEqObj(void);
	bool add_cargo_item(struct EquipDesc const &);
	bool add_equipped_item(struct EquipDesc const &);
	virtual class CEquip * alloc_equip(unsigned short,struct Archetype::Equipment *,bool);
	void compute_explosion_dmg_bounding_sphere(float &,class Vector &)const ;
	virtual void init(struct CreateParms const &);
	void init_docking_points(unsigned int);
	virtual void link_shields(void);

private:
	void destroy_equipment(struct DamageList const &,bool);
	void update_docking_animations(float);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEquip
{
public:
	CEquip(class CEquip const &);
	CEquip(unsigned int,struct CEqObj *,unsigned short,struct Archetype::Equipment const *,bool);
	virtual ~CEquip(void);
	virtual bool Activate(bool);
	virtual bool CanDelete(void)const ;
	void ConnectClientEquip(struct INotify *);
	void ConnectServerEquip(struct INotify *);
	virtual void Destroy(void);
	virtual bool DisableController(void);
	virtual bool EnableController(void);
	struct Archetype::Equipment const * EquipArch(void)const ;
	virtual bool GetConnectionPosition(class Vector *,class Matrix *)const ;
	virtual bool GetEquipDesc(struct EquipDesc &)const ;
	virtual float GetHitPoints(void)const ;
	unsigned short GetID(void)const ;
	virtual float GetMaxHitPoints(void)const ;
	struct CEqObj * GetOwner(void)const ;
	virtual float GetRelativeHealth(void)const ;
	virtual void GetStatus(struct EquipStatus &)const ;
	unsigned int GetType(void)const ;
	char const * IdentifyEquipment(void)const ;
	virtual bool IsActive(void)const ;
	virtual bool IsControllerEnabled(void)const ;
	virtual bool IsDestroyed(void)const ;
	virtual bool IsDisabled(void)const ;
	virtual bool IsFunctioning(void)const ;
	virtual bool IsLootable(void)const ;
	virtual bool IsTemporary(void)const ;
	void Notify(enum INotify::Event,void *);
	virtual void NotifyArchGroupDestroyed(unsigned short);
	void NotifyDisconnecting(struct INotify *);
	virtual void SetHitPoints(float);
	virtual bool Update(float,unsigned int);

	static void * operator new(unsigned int);
	static void operator delete(void *);


private:
	CEquip(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEquipManager
{
public:
	CEquipManager(class CEquipManager const &);
	CEquipManager(void);
	~CEquipManager(void);
	class CEquipManager & operator=(class CEquipManager const &);
	bool AddNewEquipment(class CEquip *);
	int CleanUp(void);
	void Clear(void);
	class CExternalEquip * FindByHardpoint(struct CacheString const &);
	class CExternalEquip const * FindByHardpoint(struct CacheString const &)const ;
	class CEquip * FindByID(unsigned short);
	class CEquip const * FindByID(unsigned short)const ;
	class CEquip * FindFirst(unsigned int);
	class CEquip const * FindFirst(unsigned int)const ;
	bool HasDecayingCargo(void)const ;
	bool Init(struct CEqObj *);
	unsigned short InstToSubObjID(long)const ;
	class CEquip * ReverseTraverse(class CEquipTraverser &);
	class CEquip const * ReverseTraverse(class CEquipTraverser &)const ;
	int Size(void)const ;
	class CEquip * Traverse(class CEquipTraverser &);
	class CEquip const * Traverse(class CEquipTraverser &)const ;
	bool VerifyListSync(class EquipDescList const &)const ;

private:
	int CleanUp(class std::list<class CEquip *,class std::allocator<class CEquip *> > &);
	static void  Clear(class std::list<class CEquip *,class std::allocator<class CEquip *> > &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEquipTraverser
{
public:
	CEquipTraverser(int);
	CEquipTraverser(int,bool);
	CEquipTraverser(void);
	class CEquipTraverser & operator=(class CEquipTraverser const &);
	void Restart(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CEquipmentObj
{
public:
	CEquipmentObj(class CEquipmentObj const &);
	CEquipmentObj(enum CObject::Class);
	virtual ~CEquipmentObj(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CExternalEquip
{
public:
	CExternalEquip(class CExternalEquip const &);
	CExternalEquip(unsigned int,struct CEqObj *,unsigned short,struct Archetype::Equipment const *,bool);
	virtual ~CExternalEquip(void);
	virtual bool Connect(char const *);
	virtual void Destroy(void);
	virtual bool GetCenterOfMass(class Vector &)const ;
	virtual bool GetConnectionPosition(class Vector *,class Matrix *)const ;
	virtual bool GetEquipDesc(struct EquipDesc &)const ;
	virtual bool GetHardPointInfo(struct HardpointInfo &)const ;
	virtual long GetParentConnector(bool)const ;
	virtual struct CacheString  GetParentHPName(void)const ;
	virtual bool GetVelocity(class Vector &)const ;
	virtual bool IsConnected(void)const ;
	virtual bool IsDestroyed(void)const ;
	virtual bool Update(float,unsigned int);
	static class CExternalEquip *  cast(class CEquip *);
	static class CExternalEquip const *  cast(class CEquip const *);

protected:
	virtual void Disconnect(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CFLIDMaker
{
public:
	class CFLIDMaker & operator=(class CFLIDMaker const &);
	unsigned int AllocateObjectID(void);
	unsigned int CreateStaticID(char const *);
	static class CFLIDMaker *  GetInstance(void);
	int Initialize(void);
	static void  Shutdown(void);
	static class CFLIDMaker *  m_pTheMaker;

protected:
	CFLIDMaker(void);
	~CFLIDMaker(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CGuided
{
	struct EXTERN CreateParms
	{
		CreateParms(void);
		struct CreateParms & operator=(struct CreateParms const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	CGuided(struct CGuided const &);
	CGuided(enum CObject::Class);
	virtual ~CGuided(void);
	struct Archetype::MotorData const * get_motor_arch(void)const ;
	unsigned short get_sub_target(void)const ;
	struct IObjRW * get_target(void)const ;
	void init(struct CreateParms const &);
	bool motor_on(void)const ;
	bool seeker_can_see(class Vector const &)const ;
	static bool  seeker_can_see(class Vector const &,class Vector const &,class Vector const &,struct Archetype::Munition const *);
	void set_sub_target(unsigned short);
	void set_target(struct IObjRW *);
	virtual int update(float,unsigned int);

protected:
	virtual void expire_safe_time(void);
	virtual void init_physics(class Vector const &,class Vector const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CHARACTER_ID
{
	CHARACTER_ID(void);
	struct CHARACTER_ID const & operator=(struct CHARACTER_ID const &);
	void invalidate(void);
	bool is_valid(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CInternalEquip
{
public:
	CInternalEquip(class CInternalEquip const &);
	CInternalEquip(unsigned int,struct CEqObj *,unsigned short,struct Archetype::Equipment const *,bool);
	virtual ~CInternalEquip(void);
	virtual bool GetEquipDesc(struct EquipDesc &)const ;
	static class CInternalEquip *  cast(class CEquip *);
	static class CInternalEquip const *  cast(class CEquip const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CLoot
{
	CLoot(struct CLoot const &);
	CLoot(enum CObject::Class);
	virtual ~CLoot(void);
	bool can_ai_tractor(void)const ;
	struct Archetype::Equipment * container_arch(void)const ;
	struct Archetype::Equipment * contents_arch(void)const ;
	float get_contents_hit_pts(void)const ;
	virtual unsigned int get_name(void)const ;
	unsigned int get_owner(void)const ;
	unsigned int get_units(void)const ;
	float get_volume(void)const ;
	virtual void init(struct CreateParms const &);
	bool is_loot_temporary(void)const ;
	void set_contents_hit_pts(float);
	virtual void set_hit_pts(float);
	void set_units(unsigned int);
	virtual int update(float,unsigned int);

protected:
	virtual void init_physics(class Vector const &,class Vector const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CMine
{
	CMine(struct CMine const &);
	CMine(enum CObject::Class);
	virtual ~CMine(void);
	struct Archetype::Mine const * minearch(void);
	virtual int update(float,unsigned int);

protected:
	virtual void expire_safe_time(void);
	virtual void init_physics(class Vector const &,class Vector const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CMunition
{
	CMunition(struct CMunition const &);
	CMunition(enum CObject::Class);
	virtual ~CMunition(void);
	struct Archetype::Munition const * munitionarch(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CNonPhysAttachment
{
public:
	CNonPhysAttachment(class CNonPhysAttachment const &);
	CNonPhysAttachment(void);
	virtual ~CNonPhysAttachment(void);
	class CNonPhysAttachment & operator=(class CNonPhysAttachment const &);
	virtual bool Connect(class CAttachedEquip *);
	virtual struct CObject * Disconnect(class CAttachedEquip *,bool);
	virtual void EnableCollisions(bool);
	virtual struct CObject * GetPhysicsOwner(void)const ;
	virtual long GetRootIndex(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CNudgeEngine
{
public:
	CNudgeEngine(class CNudgeEngine const &);
	CNudgeEngine(void);
	virtual ~CNudgeEngine(void);
	class CNudgeEngine & operator=(class CNudgeEngine const &);
	bool Activate(bool);
	virtual bool EnableController(void);
	class Vector  GetNudgeVec(void)const ;
	bool IsActive(void)const ;
	void SetNudgeVec(class Vector const &);
	void SetOwner(struct CShip *);

protected:
	static float const  NUDGE_CHANGE_THRESHOLD;
	//@@@ virtual void do_simulation_controller(class IVP_Event_Sim *,class IVP_U_Vector<class IVP_Core> *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CPhysAttachment
{
public:
	CPhysAttachment(class CPhysAttachment const &);
	CPhysAttachment(void);
	virtual ~CPhysAttachment(void);
	class CPhysAttachment & operator=(class CPhysAttachment const &);
	virtual bool Connect(class CAttachedEquip *);
	virtual struct CObject * Disconnect(class CAttachedEquip *,bool);
	virtual void EnableCollisions(bool);
	virtual struct CObject * GetPhysicsOwner(void)const ;
	virtual long GetRootIndex(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CPhysControllerEquip
{
public:
	CPhysControllerEquip(class CPhysControllerEquip const &);
	CPhysControllerEquip(void);
	virtual ~CPhysControllerEquip(void);
	class CPhysControllerEquip & operator=(class CPhysControllerEquip const &);
	virtual bool DisableController(void);
	virtual bool IsControllerEnabled(void)const ;

protected:
	virtual bool ControlObject(struct CObject *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CPlayerAccount
{
public:
	CPlayerAccount(class CPlayerAccount const &);
	CPlayerAccount(void);
	virtual ~CPlayerAccount(void);
	class CPlayerAccount & operator=(class CPlayerAccount const &);
	void GenerateAccount(char const *);
	static bool  GenerateTextKey(char *);
	std::wstring GetAccountName(void);
	char const * GetAccountNameChar(void);
	std::wstring GetAccountNameSig(void);
	char const * GetAccountNameSigChar(void);
	std::wstring GetServerSignature(char const *);
	static bool  GetTextKey(char *);
	bool LoadAccount(void);
	bool LoadAccountFromStrings(char const *,char const *);
	static void  SetAcctIndex(unsigned long);
	static bool  SetTextKey(char *);
	bool VerifyAccount(void);

protected:
	void TossHashes(void);
	static unsigned long  g_dwAccountIndex;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CPlayerTradeOffer
{
public:
	CPlayerTradeOffer(class CPlayerTradeOffer const &);
	CPlayerTradeOffer(void);
	virtual ~CPlayerTradeOffer(void);
	class CPlayerTradeOffer & operator=(class CPlayerTradeOffer const &);
	bool GetAccepted(void);
	class EquipDescList & GetList(void);
	unsigned long GetMoneyOffered(void);
	unsigned int GetSourcePlayerID(void);
	class CPlayerTradeOffer * GetTargetOffer(void);
	unsigned int GetTargetPlayerID(void);
	void SetAccepted(bool);
	void SetMoneyOffered(unsigned long);
	void SetSourcePlayerID(unsigned int);
	void SetTargetOffer(class CPlayerTradeOffer *);
	void SetTargetPlayerID(unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CProjectile
{
	CProjectile(struct CProjectile const &);
	CProjectile(enum CObject::Class);
	virtual ~CProjectile(void);
	unsigned int const & get_owner(void)const ;
	virtual void init(struct CreateParms const &);
	bool is_alive(void)const ;
	bool is_owner_safe(void)const ;
	struct Archetype::Projectile const * projarch(void)const ;
	virtual void set_dead(void);
	virtual int update(float,unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CRemotePhysicsSimulation
{
public:
	CRemotePhysicsSimulation(class CRemotePhysicsSimulation const &);
	CRemotePhysicsSimulation(void);
	virtual ~CRemotePhysicsSimulation(void);
	class CRemotePhysicsSimulation & operator=(class CRemotePhysicsSimulation const &);
	double CalcPositionError(class Vector const &);
	bool CheckForSync(class Vector const &,class Vector const &,class Quaternion const &);
	void Doit(double);
	class Vector  GetLatestUpdate(void);
	class Vector  GetSample(int);
	unsigned long GetSampleCount(void);
	double GetSimulationTime(void);
	virtual void RemoteUpdate(class Vector const &,class Quaternion const &,double);
	void Reset(void);
	void SetLogging(bool);
	void  tracef(char const *,...);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};


struct IObject
{
	enum ThrustEquipType;
};

struct IObjInspect
{
	struct CargoEnumerator;
	struct SubtargetEnumerator;
};


struct EXTERN CShip
{
	CShip(struct CShip const &);
	CShip(void);
	virtual ~CShip(void);
	static float const  JETTISON_CLEARANCE_TIME;
	void VerifyTarget(void);
	enum FORMATION_RTYPE  add_follow_follower(struct IObjRW *);
	enum FORMATION_RTYPE  add_formation_follower(struct IObjRW *);
	void airlock_in(class Vector const &,class Matrix const &);
	bool any_thrusters_on(void)const ;
	bool check_formation_follower_status(float);
	float close_bay(void);
	virtual void disable_controllers(void);
	virtual void enable_controllers(void);
	virtual void flush_animations(void);
	bool generate_follow_offset(struct IObjInspect const *,class Transform &)const ;
	int get_ammo_capacity_remaining(unsigned int)const ;
	int get_ammo_capacity_remaining(struct Archetype::Equipment const *)const ;
	float get_angular_distance_travelled(float,float,float)const ;
	float get_angular_distance_travelled(float,float,float,float)const ;
	class Vector  get_angular_drag(void)const ;
	float get_angular_speed_XY(float,float)const ;
	float get_angular_speed_Z(float)const ;
	class Vector const & get_axis_throttle(void)const ;
	enum BayState  get_bay_state(void)const ;
	float get_cargo_hold_remaining(void)const ;
	float get_distance_travelled(float,float,float,enum IObject::ThrustEquipType)const ;
	bool get_farthest_active_gun_range(float &)const ;
	struct IObjRW * get_follow_leader(void);
	class Vector const & get_follow_offset(void);
	int get_formation_follower_count(void);
	int get_formation_followers(struct IObjRW * * const,unsigned int);
	unsigned int get_group_name(void)const ;
	struct ShipGunStats const & get_gun_stats(void)const ;
	float get_initial_speed_to_coast_distance(float,bool)const ;
	float get_linear_drag(void)const ;
	float get_max_bank_angle(void)const ;
	float get_max_thrust_power(void)const ;
	virtual unsigned int get_name(void)const ;
	class Vector  get_nudge_vec(void)const ;
	unsigned short const * get_pilot_name(void)const ;
	float get_projected_axis_throttle_XY(float)const ;
	float get_projected_axis_throttle_Z(float)const ;
	float get_projected_throttle(float,enum IObject::ThrustEquipType)const ;
	long get_renderable_subtarget(void)const ;
	int get_repair_kit_capacity_remaining(void)const ;
	int get_shield_battery_capacity_remaining(void)const ;
	int get_space_for_cargo_type(struct Archetype::Equipment const *)const ;
	float get_speed(float,enum IObject::ThrustEquipType)const ;
	int get_status(char *,int)const ;
	enum StrafeDir  get_strafe_dir(void)const ;
	unsigned short get_sub_target(void)const ;
	struct IObjRW * get_target(void)const ;
	int get_targeted_enemy_count(void);
	bool get_tgt_lead_fire_pos(class Vector &)const ;
	bool get_tgt_lead_fire_pos(struct IObjInspect const *,class Vector &)const ;
	float get_throttle(void)const ;
	float get_thrust_power(void)const ;
	float get_thrust_power_ratio(void)const ;
	float get_time_to_accelerate(float,float,float,enum IObject::ThrustEquipType)const ;
	float get_time_to_accelerate_angularly(float,float,float)const ;
	float get_time_to_accelerate_angularly(float,float,float,float)const ;
	unsigned int get_tradelane_entrance_ring(void);
	unsigned int get_tradelane_exit_ring(void);
	float get_tradelane_speed(void);
	int go_tradelane(struct IObjInspect const *,struct IObjInspect const *,struct IObjRW *,bool,float);
	virtual void init(struct CreateParms const &);
	bool is_cruise_active(void)const ;
	bool is_enemy(struct IObjInspect *);
	bool is_jumping(void)const ;
	bool is_launching(void)const ;
	bool is_player(void)const ;
	bool is_using_tradelane(void)const ;
	void jump_in(struct IObjRW *,class Vector const &,class Matrix const &,float);
	void launch(struct IObjRW *,struct CEqObj *,int);
	bool leaving_system_update(unsigned int &);
	struct IObjRW * next_enemy(void);
	struct IObjRW * next_target(bool);
	void notify_set_target(struct CShip *,bool);
	float open_bay(void);
	struct IObjRW * previous_enemy(void);
	enum FORMATION_RTYPE  remove_follow_follower(struct IObjRW *);
	enum FORMATION_RTYPE  remove_formation_follower(struct IObjRW *);
	void request_exit_tradelane(void);
	void set_angular_drag_factor(float);
	void set_axis_throttle(class Vector const &);
	void set_follow_leader(struct IObjRW *);
	void set_follow_offset(class Vector const &);
	void set_gun_stats_dirty(void);
	void set_nudge_vec(class Vector const &);
	void set_strafe_dir(enum StrafeDir);
	void set_sub_target(unsigned short);
	void set_target(struct IObjRW *);
	void set_throttle(float);
	void set_thrust_power(float);
	void set_tradelane_speed(float);
	struct Archetype::Ship const * shiparch(void)const ;
	void stop_tradelane(void);
	virtual int update(float,unsigned int);
	void use_tradelane(bool);

protected:
	virtual class CEquip * alloc_equip(unsigned short,struct Archetype::Equipment *,bool);
	virtual void init_physics(class Vector const &,class Vector const &);

private:
	void collect_angular_force_components(unsigned int,float,float &,float &)const ;
	void collect_force_components(float,enum IObject::ThrustEquipType,float &,float &)const ;
	//@@@ virtual void do_simulation_controller(class IVP_Event_Sim *,class IVP_U_Vector<class IVP_Core> *);
	float get_distance_travelled(float,float,float,float,float)const ;
	float get_initial_speed_to_coast_distance(float,float,float)const ;
	float get_time_to_accelerate(float,float,float,float,float)const ;
	void recalculate_formation_speed(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CSimple
{
	CSimple(struct CSimple const &);
	CSimple(enum CObject::Class);
	virtual ~CSimple(void);
	unsigned int GetOwnerPlayer(void)const ;
	void SetOwnerPlayer(unsigned int);
	virtual void beam_object(class Vector const &,class Matrix const &,bool);
	virtual void cache_physical_props(void);
	virtual void connect(struct IObjDB *);
	virtual void disconnect(struct IObjDB *);
	float get_hit_pts(void)const ;
	unsigned int const & get_id(void)const ;
	float get_max_hit_pts(void)const ;
	virtual unsigned int get_name(void)const ;
	struct IObjDB * get_object_database(void)const ;
	virtual float get_physical_radius_r(class Vector &)const ;
	float get_relative_health(void)const ;
	float get_scanner_interference(void)const ;
	unsigned int get_type(void)const ;
	virtual void init(struct CreateParms const &);
	virtual bool is_targetable(void)const ;
	virtual void open(struct Archetype::Root *);
	virtual void set_hit_pts(float);
	virtual void unmake_physical(void);

protected:
	void update_zones(float,unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CSolar
{
	CSolar(struct CSolar const &);
	CSolar(enum CObject::Class);
	virtual ~CSolar(void);
	struct ID_String const & GetParentNickname(void)const ;
	unsigned char GetVisitValue(void)const ;
	static bool  ReadObj(class INI_Reader &,struct Archetype::Solar * &,struct CreateParms &);
	void SetVisitValue(unsigned char);
	virtual enum ObjActivateResult  activate(bool,unsigned int);
	virtual void cache_physical_props(void);
	virtual void flush_animations(void);
	virtual bool get_activate_state(class std::vector<bool,class std::allocator<bool> > &);
	virtual class Vector  get_angular_velocity(void)const ;
	float get_atmosphere_immersion(class Vector const &)const ;
	float get_atmosphere_range(void)const ;
	struct ID_String const & get_dest_gate(void)const ;
	unsigned int get_dest_system(void)const ;
	struct ID_String const & get_loadout(void)const ;
	virtual float get_mass(void)const ;
	unsigned int get_next_trade_ring(void)const ;
	unsigned int get_prev_trade_ring(void)const ;
	unsigned int get_tradelane_space_name(void)const ;
	virtual class Vector  get_velocity(void)const ;
	void init(struct CreateParms const &);
	bool is_destructible(void)const ;
	bool is_dynamic(void)const ;
	bool is_lane_ring(void)const ;
	bool is_planetary(void)const ;
	bool is_system_gate(void)const ;
	bool is_waypoint(void)const ;
	struct Archetype::Solar const * solararch(void)const ;
	virtual int update(float,unsigned int);

protected:
	virtual class CEquip * alloc_equip(unsigned short,struct Archetype::Equipment *,bool);
	void configure_system_gate(char const *);
	void init_continual_anim(char const *);
	virtual void init_physics(class Vector const &,class Vector const &);
	void update_system_gate(float);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CSteering
{
public:
	CSteering(class CSteering const &);
	CSteering(void);
	virtual ~CSteering(void);
	class CSteering & operator=(class CSteering const &);
	bool Activate(bool);
	virtual bool EnableController(void);
	float GetAxisSteeringTorque(unsigned int,float)const ;
	class Vector const & GetAxisThrottle(void)const ;
	bool IsActive(void)const ;
	void SetAxisThrottle(class Vector const &);
	void SetOwner(struct CShip *);

protected:
	static float const  AXIS_CHANGE_THRESHOLD;
	//@@@ virtual void do_simulation_controller(class IVP_Event_Sim *,class IVP_U_Vector<class IVP_Core> *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CStrafeEngine
{
public:
	CStrafeEngine(class CStrafeEngine const &);
	CStrafeEngine(void);
	virtual ~CStrafeEngine(void);
	class CStrafeEngine & operator=(class CStrafeEngine const &);
	virtual bool EnableController(void);
	enum StrafeDir  GetStrafe(void)const ;
	void SetOwner(struct CShip *);
	void SetStrafe(enum StrafeDir);

protected:
	//@@@ virtual void do_simulation_controller(class IVP_Event_Sim *,class IVP_U_Vector<class IVP_Core> *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CacheString
{
	void clear(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CharPlaceInfo
{
	CharPlaceInfo(void);
	~CharPlaceInfo(void);
	void clear(void);
	void destroy(void);
	bool is_named(char const *)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CharacterProperties
{
public:
	CharacterProperties(void);
	~CharacterProperties(void);
	class CharacterProperties & operator=(class CharacterProperties const &);
	void destroy(void);
	unsigned long get_key(void)const ;
	void init(struct CharacterDescription const &);
	void marshal(class MarshalBuffer *)const ;
	void unmarshal(class MarshalBuffer *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN ClipNode
{
public:
	ClipNode(struct tagRECT const &);
	ClipNode(class ClipNode const &);
	ClipNode(void);
	virtual ~ClipNode(void);
	class ClipNode & operator=(class ClipNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	struct tagRECT const & get_rect(void);
	void set_rect(struct tagRECT const &);

	virtual operator class ClipNode *(void);
	virtual operator class ClipNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace Collision
{
	EXTERN  float  CalcCollisionDamage(unsigned int,class Vector const &,class Vector const &);
	EXTERN  float  CalcCollisionDamage(float,float,float);
	EXTERN  void  Free(void);
	EXTERN  float  GetImpactDamageFromType(unsigned int);
	EXTERN  bool  Load(class INI_Reader &);
};

struct EXTERN CollisionGroupDesc
{
	struct CollisionGroupDesc & operator=(struct CollisionGroupDesc const &);
	bool operator==(struct CollisionGroupDesc const &)const ;
	bool operator!=(struct CollisionGroupDesc const &)const ;
	bool operator<(struct CollisionGroupDesc const &)const ;
	bool operator>(struct CollisionGroupDesc const &)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CommReferrable
{
	CommReferrable(struct CommReferrable const &);
	CommReferrable(void);
	struct CommReferrable & operator=(struct CommReferrable const &);
	virtual struct TString<64> const & GetMsgIdPrefix(void)const ;
	virtual bool HasVoiceInfo(void)const ;
	virtual bool read_comm_ini_data(class INI_Reader &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CostumeDescriptions
{
public:
	CostumeDescriptions(class CostumeDescriptions const &);
	CostumeDescriptions(void);
	~CostumeDescriptions(void);
	class CostumeDescriptions & operator=(class CostumeDescriptions const &);
	struct accessory const * find_accessory(unsigned long)const ;
	struct accessory const * find_accessory(char const *)const ;
	unsigned long find_accessory_id(char const *)const ;
	struct bodypart const * find_bodypart(int,unsigned long)const ;
	struct bodypart const * find_bodypart(int,char const *)const ;
	struct costume const * find_costume(unsigned long)const ;
	struct costume const * find_costume(char const *)const ;
	unsigned long find_costume_id(char const *)const ;
	unsigned long find_part_id(int,char const *)const ;
	void get_costume(int,struct Costume &)const ;
	void get_costume(char const *,struct Costume &)const ;
	int get_costume_gender(struct Costume const &)const ;
	int get_costume_gender(unsigned long)const ;
	char const * get_part_mesh(int,unsigned long)const ;
	char const * get_part_name(int,unsigned long)const ;
	void load_bodyparts(char const *);
	void load_costumes(char const *);

private:
	void load_accessory(class INI_Reader *);
	void load_bodypart(int,int,class DetailSwitchTable *,class INI_Reader *);
	void warn(class INI_Reader *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN CostumeHint
{
	CostumeHint(struct CostumeHint const &);
	CostumeHint(void);
	virtual ~CostumeHint(void);
	struct CostumeHint & operator=(struct CostumeHint const &);
	virtual void CleanUp(unsigned char *);
	virtual unsigned int Serialize(unsigned char * *);
	virtual void UnSerialize(unsigned char *,unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN Csys
{
public:
	Csys(void);
	class Csys & operator=(class Csys const &);
	class Csys  get_inverse(void)const ;
	class Transform  get_transform(void)const ;
	void init(class Vector const &,class Matrix const &);
	void set_identity(void);
	void set_transform(class Transform const &);
	class Csys  trans_from_frame(class Csys const &)const ;
	class Matrix  trans_from_frame(class Matrix const &)const ;
	class Vector  trans_from_frame(class Vector const &)const ;
	class Csys  trans_to_frame(class Csys const &)const ;
	class Matrix  trans_to_frame(class Matrix const &)const ;
	class Vector  trans_to_frame(class Vector const &)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

Csys   operator*(Csys const &,Csys const &);


namespace DataConfig
{
	EXTERN  void  shutdown(void);
	EXTERN  int  startup(char const *,struct Archetype::ICliObjFactory *,struct ProgressCB *);
};

class EXTERN DetailSwitchTable
{
public:
	DetailSwitchTable(class DetailSwitchTable const &);
	DetailSwitchTable(void);
	~DetailSwitchTable(void);
	class DetailSwitchTable & operator=(class DetailSwitchTable const &);
	float adjust_distance(float,float,float)const ;
	float get_switch_distance(float)const ;
	void read_from_ini(class INI_Reader *);

private:
	void add_table_entry(float,float);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN TextRenderContext
{
public:
	class Image;
	struct FontDesc;

	TextRenderContext(class TextRenderContext const &);
	TextRenderContext(void);
	virtual ~TextRenderContext(void);
	class TextRenderContext & operator=(class TextRenderContext const &);
	void clear_default_attributes(void);
	struct TextRenderAttributes const & get_current_attributes(void);
	struct TextRenderAttributes const & get_default_attributes(void);
	int get_origin_h(void);
	int get_origin_v(void);
	int get_pos_h(void);
	int get_pos_v(void);
	void pop_default_attributes(void);
	void pop_state(void);
	void push_default_attributes(void);
	void push_state(void);
	void reset_to_default(void);
	void set_current_attributes(struct TextRenderAttributes const &);
	void set_default_attributes(struct TextRenderAttributes const &);
	void set_origin(int,int);
	void set_origin_h(int);
	void set_origin_v(int);
	void set_pos(int,int);
	void set_pos_h(int);
	void set_pos_v(int);

private:
	void get_state(struct State &);
	void set_state(struct State const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN DeviceTRC
{
public:
	DeviceTRC(class DeviceTRC const &);
	DeviceTRC(struct HDC__ *);
	DeviceTRC(void);
	virtual ~DeviceTRC(void);
	class DeviceTRC & operator=(class DeviceTRC const &);
	void bind_to_dc(struct HDC__ *);
	virtual class TextRenderContext::Image * create_image(char const * const);
	virtual void destroy_image(class TextRenderContext::Image *);
	virtual void execute_image(class TextRenderContext::Image const *,bool);
	virtual void execute_text(unsigned short const *,bool,int);
	virtual int get_cell_height(void)const ;
	virtual int get_cell_width(void)const ;
	virtual void get_clip_rect(struct tagRECT &);
	virtual void get_font_metrics(int &,int &)const ;
	virtual void get_text_fit(unsigned short const *,int,int &,int *,struct VisualSize &,int)const ;
	virtual void get_text_visual_size(unsigned short const *,struct VisualSize &,int)const ;
	static void  release_font(int);
	virtual void set_clip_rect(struct tagRECT const &);
	static void  set_drop_shadow_offset(int,int);
	static void  set_image_root(char const *);
	static void  static_set_font(int,struct TextRenderContext::FontDesc const &,float);

private:
	static int  mDropShadowX;
	static int  mDropShadowY;
	static class WinFont *  mFont;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace EngineEquipConsts
{
	EXTERN  float  CRUISE_ACCEL_TIME;
	EXTERN  float  CRUISE_ATTEN_MOD_RANGE;
	EXTERN  float  CRUISE_DISRUPT_TIME;
	EXTERN  float  CRUISE_DRAG;
	EXTERN  float  CRUISE_STEADY_TIME;
	EXTERN  float  CRUISING_SPEED;
	EXTERN  float  DELTA_CRUISE_ATTEN_MOD_STEADY;
	EXTERN  float  DELTA_THROTTLE_ATTEN_MOD_CHANGING;
	EXTERN  float  DELTA_THROTTLE_ATTEN_MOD_STEADY;
	EXTERN  float  MAX_DELTA_FX_THROTTLE;
	EXTERN  float  MAX_ENGINE_FX_THROTTLE;
	EXTERN  float  THROTTLE_ATTEN_MOD_RANGE;
	EXTERN  float  THROTTLE_STEADY_TIME;
};

struct EXTERN EngineObject
{
	EngineObject(struct EngineObject const &);
	EngineObject(void);
	virtual ~EngineObject(void);
	struct EngineObject & operator=(struct EngineObject const &);
	long get_index(void)const ;
	class Matrix const & get_orientation(void)const ;
	class Vector const & get_position(void)const ;
	float const  get_radius(void)const ;
	class Transform const & get_transform(void)const ;
	void set_orientation(class Matrix const &);
	void set_position(class Vector const &);
	void set_transform(class Transform const &);
	void update_tree(void)const ;

private:
	virtual void __stdcall create_instance(long);
	virtual void __stdcall destroy_instance(long);
	virtual class Vector const & __stdcall get_angular_velocity(long)const ;
	virtual void __stdcall get_centered_radius(long,float *,class Vector *)const ;
	virtual unsigned long __stdcall get_instance_flags(long)const ;
	virtual class Matrix const & __stdcall get_orientation(long)const ;
	virtual class Vector const & __stdcall get_position(long)const ;
	virtual class Transform const & __stdcall get_transform(long)const ;
	virtual class Vector const & __stdcall get_velocity(long)const ;
	virtual void __stdcall initialize_instance(long);
	virtual bool __stdcall joint_changed(long);
	virtual void __stdcall set_angular_velocity(long,class Vector const &);
	void set_centered_radius(float,class Vector const &);
	virtual void __stdcall set_centered_radius(long,float,class Vector const &);
	virtual void __stdcall set_instance_flags(long,unsigned long);
	virtual void __stdcall set_orientation(long,class Matrix const &);
	virtual void __stdcall set_position(long,class Vector const &);
	virtual void __stdcall set_transform(long,class Transform const &);
	virtual void __stdcall set_velocity(long,class Vector const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN EquipDesc
{
	EquipDesc(struct EquipDesc const &);
	EquipDesc(void);
	struct EquipDesc & operator=(struct EquipDesc const &);
	bool operator==(struct EquipDesc const &)const ;
	bool operator!=(struct EquipDesc const &)const ;
	bool operator<(struct EquipDesc const &)const ;
	bool operator>(struct EquipDesc const &)const ;

	static struct CacheString const  CARGO_BAY_HP_NAME;
	unsigned int get_arch_id(void)const ;
	float get_cargo_space_occupied(void)const ;
	int get_count(void)const ;
	struct CacheString const & get_hardpoint(void)const ;
	unsigned short get_id(void)const ;
	int get_owner(void)const ;
	float get_status(void)const ;
	bool get_temporary(void)const ;
	bool is_equipped(void)const ;
	bool is_internal(void)const ;
	void make_internal(void);
	void set_arch_id(unsigned int);
	void set_count(int);
	void set_equipped(bool);
	void set_hardpoint(struct CacheString const &);
	void set_id(unsigned short);
	void set_owner(int);
	void set_status(float);
	void set_temporary(bool);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN EquipDescList
{
public:
	EquipDescList(struct EquipDescVector const &);
	EquipDescList(class EquipDescList const &);
	EquipDescList(void);
	~EquipDescList(void);
	class EquipDescList & operator=(class EquipDescList const &);
	int add_equipment_item(struct EquipDesc const &,bool);
	void append(class EquipDescList const &);
	struct EquipDesc * find_equipment_item(struct CacheString const &);
	struct EquipDesc * find_equipment_item(unsigned short);
	struct EquipDesc const * find_equipment_item(struct CacheString const &)const ;
	struct EquipDesc const * find_equipment_item(unsigned short)const ;
	struct EquipDesc const * find_matching_cargo(unsigned int,int,float)const ;
	float get_cargo_space_occupied(void)const ;
	int remove_equipment_item(unsigned short,int);
	struct EquipDesc * traverse_equipment_type(unsigned int,struct EquipDesc const *);
	struct EquipDesc const * traverse_equipment_type(unsigned int,struct EquipDesc const *)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN EquipDescVector
{
	EquipDescVector(struct EquipDescVector const &);
	EquipDescVector(class EquipDescList const &);
	EquipDescVector(void);
	~EquipDescVector(void);
	struct EquipDescVector & operator=(struct EquipDescVector const &);
	int add_equipment_item(struct EquipDesc const &,bool);
	void append(struct EquipDescVector const &);
	struct EquipDesc * traverse_equipment_type(unsigned int,struct EquipDesc const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace ErrorHandler
{
	EXTERN  void  activate(char const *,int (*)(char const *,char const *,bool));
	EXTERN  void  deactivate(void);
	EXTERN  bool  is_log_enabled(int);
	EXTERN  void  log_comment(int,char const *,...);
	EXTERN  void  log_disable(int);
	EXTERN  void  log_enable(int);
	EXTERN  void  log_last_error(char const *,int,enum SeverityLevel,char *,unsigned long);
	EXTERN  void *  new_log(char const *,int,int,bool,bool);
};

struct EXTERN ExhaustNozzleInfo
{
	ExhaustNozzleInfo(void);
	struct ExhaustNozzleInfo & operator=(struct ExhaustNozzleInfo const &);
	bool GetHardpointOffset_NS(class Transform &)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN File
{
public:
	File(void);
	~File(void);
	class File & operator=(class File const &);
	void close(void);
	int eof(void);
	void get_info(void);
	int get_length(void);
	char const * get_name(void)const ;
	bool is_open(void);
	bool open(char const *);
	int read(void *,int);
	int read(void *,int,int);
	int read_line(char *,int);
	int seek(int);
	void set_name(char const *);
	int set_offset(int);
	int tell(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN FileMap
{
	FileMap(struct FileMap const &);
	FileMap(void);
	~FileMap(void);
	struct FileMap & operator=(struct FileMap const &);
	void close(void);
	bool eof(void)const ;
	unsigned int get_file_length(void)const ;
	char const * get_file_name(void)const ;
	void handoff_to(struct FileMap &);
	bool open(char const *);
	bool open_memory(void const *,unsigned int);
	unsigned int read(void *,unsigned int);
	bool read_ptr(struct BINI_Block * &);
	bool read_ptr(struct BINI_Header * &);
	bool read_ptr(struct BINI_Value * &);
	void * request_pointer(unsigned int &);
	void seek(unsigned int);
	unsigned int tell(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN FlashLightSetInfo
{
	FlashLightSetInfo(void);
	~FlashLightSetInfo(void);
	struct FlashLightSetInfo & operator=(struct FlashLightSetInfo const &);
	void clear(void);
	void destroy(void);
	void fixup(long,class HardpointSummary const *,class RoomData const *);
	void unfixup(void);

private:
	void add_light_csys(class Csys const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN FmtStr
{
	struct EXTERN Val
	{
		Val(struct Val const &);
		Val(unsigned short,void *,unsigned char);
		Val(void const *);
		Val(void const *,int &);
		~Val(void);
		struct Val const & operator=(struct Val const &);
		bool operator==(struct Val const &)const ;
		unsigned int flatten(void *,unsigned int)const ;
		unsigned int get_flattened_size(void)const ;

		static void * operator new(unsigned int);
		static void operator delete(void *);

	private:
		int InitFromVoid(void const *);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	FmtStr(struct FmtStr const &);
	FmtStr(unsigned int,struct Val const *);
	~FmtStr(void);
	struct FmtStr const & operator=(struct FmtStr const &);
	bool operator==(struct FmtStr const &)const ;
	void append(struct Val *);
	void append_base(unsigned int const &);
	void append_fmt_str(struct FmtStr const &);
	void append_good(unsigned int const &);
	void append_installation(int);
	void append_int(unsigned int);
	void append_loot(int);
	void append_nav_marker(struct NavMarker const &);
	void append_rep_group(unsigned int const &);
	void append_rep_instance(int const &);
	void append_spaceobj_id(unsigned int const &);
	void append_string(unsigned int);
	void append_system(unsigned int const &);
	int append_void(void *);
	void append_zone_id(unsigned int const &);
	void begin_mad_lib(unsigned int);
	void destroy(void);
	void end_mad_lib(void);
	int flatten(void *,unsigned int)const ;
	int unflatten(void *,unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN Fuse
{
public:
	Fuse(struct ID_String const &,float);
	Fuse(class Fuse const &);
	virtual ~Fuse(void);
	class Fuse & operator=(class Fuse const &);
	int ActionCount(void)const ;
	void Burn(float);
	virtual void FreeActions(void);
	bool IgniteAt(unsigned int,unsigned short,float);
	bool IsBurning(void)const ;
	bool IsDeathFuse(void)const ;
	bool IsSpent(void)const ;
	bool IsSpentAt(float)const ;
	float Lifetime(void)const ;
	void Load(void)const ;
	struct ID_String const & Name(void)const ;
	bool OverrideLifetime(float);
	void RandomizeActions(void);
	bool UnBurn(unsigned short,float);
	void UnLoad(void)const ;

protected:
	bool ReadFuseValues(class INI_Reader &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN FuseAction
{
public:
	FuseAction(class FuseAction const &);
	FuseAction(void);
	virtual ~FuseAction(void);
	class FuseAction & operator=(class FuseAction const &);
	float GetTriggerTime(void)const ;
	virtual bool IsTriggered(unsigned short)const ;
	virtual bool IsTriggered(void)const ;
	virtual int Load(void);
	virtual float Randomize(void);
	virtual bool ShouldRandomize(void)const ;
	virtual void Trigger(unsigned int,unsigned short);
	virtual int UnLoad(void);
	virtual void UnTrigger(unsigned short);

protected:
	virtual void CopyArchProperties(class FuseAction const &);
	bool ReadFuseActionValue(class INI_Reader &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN FuseDB
{
public:
	class FuseDB & operator=(class FuseDB const &);
	static void  AddFuseINIFile(char const *);
	static void  Shutdown(void);

protected:
	typedef TString<260> TString260;
	static std::list<TString260>  m_FuseINIFiles;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN GoodDesc
{
	GoodDesc(void);
	struct GoodDesc & operator=(struct GoodDesc const &);

	static void * operator new(unsigned int);
	static void operator delete(void *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN GoodDescList
{
	GoodDescList(struct GoodDescList const &);
	GoodDescList(void);
	virtual ~GoodDescList(void);
	struct GoodDescList const & operator=(struct GoodDescList const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN GoodInfo
{
	GoodInfo(struct GoodInfo const &);
	GoodInfo(void);
	~GoodInfo(void);
	struct GoodInfo & operator=(struct GoodInfo const &);
	bool has_visual_attachment(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN GoodInfoList
{
public:
	GoodInfoList(class GoodInfoList const &);
	GoodInfoList(void);
	~GoodInfoList(void);
	class GoodInfoList & operator=(class GoodInfoList const &);
	void destroy(void);
	struct GoodInfo const * find_by_archetype(unsigned int)const ;
	struct GoodInfo const * find_by_id(unsigned int)const ;
	struct GoodInfo const * find_by_name(char const *)const ;
	struct GoodInfo const * find_by_ship_arch(unsigned int)const ;
	class std::list<struct GoodInfo *,class std::allocator<struct GoodInfo *> > const * get_list(void)const ;
	void load(char const *);

private:
	void read_Good_block(class INI_Reader *,struct GoodInfo *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace GoodList
{
	EXTERN  struct GoodInfo const *  find_by_archetype(unsigned int);
	EXTERN  struct GoodInfo const *  find_by_id(unsigned int);
	EXTERN  struct GoodInfo const *  find_by_nickname(char const *);
};

class EXTERN HardpointSummary
{
public:
	HardpointSummary(class HardpointSummary const &);
	HardpointSummary(void);
	virtual ~HardpointSummary(void);
	class HardpointSummary & operator=(class HardpointSummary const &);
	int analyze_instance(long);
	void clear(void);
	void destroy(void);
	void expire_instance(void);
	int find_name(char const *)const ;
	long find_name_instance(char const *)const ;
	int get_count(void)const ;
	struct HardpointInfo const & get_info(int)const ;
	struct HardpointInfo const * get_info_by_name(char const *)const ;
	long get_instance(int)const ;
	char const * get_name(int)const ;

private:
	void count_hardpoints(long);
	static void  count_hardpoints_callback(long,void *);
	void fill_hardpoints(long);
	static void  fill_hardpoints_callback(long,void *);
	static void  hardpoint_callback1(char const *,void *);
	static void  hardpoint_callback2(char const *,void *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN Heap
{
	Heap(unsigned int,int);
	void Free(void *);
	void * Malloc(void);
	void Shrink(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace Hierarchy
{
	EXTERN  int  GetDepth(long,long);
};

struct EXTERN IAction
{
	IAction(struct IAction const &);
	IAction(void);
	virtual ~IAction(void);
	struct IAction & operator=(struct IAction const &);
	virtual char const * get_id(void)const ;

	static void * operator new(unsigned int);
	static void operator delete(void *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};


namespace pub
{
	namespace AI
	{
		enum ScanResponse;
		enum OP_RTYPE;
		enum DirectivePriority;
		struct DirectiveCallback;

		class EXTERN BaseOp
		{
		public:
			BaseOp(class BaseOp const &);
			BaseOp(enum OP_TYPE);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

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

		class EXTERN DirectiveCancelOp
		{
		public:
			DirectiveCancelOp(class DirectiveCancelOp const &);
			DirectiveCancelOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveDelayOp
		{
		public:
			DirectiveDelayOp(class DirectiveDelayOp const &);
			DirectiveDelayOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveDockOp
		{
		public:
			DirectiveDockOp(class DirectiveDockOp const &);
			DirectiveDockOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveDrasticEvadeOp
		{
		public:
			DirectiveDrasticEvadeOp(class DirectiveDrasticEvadeOp const &);
			DirectiveDrasticEvadeOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveEvadeOp
		{
		public:
			DirectiveEvadeOp(class DirectiveEvadeOp const &);
			DirectiveEvadeOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveFaceOp
		{
		public:
			DirectiveFaceOp(class DirectiveFaceOp const &);
			DirectiveFaceOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveFollowOp
		{
		public:
			DirectiveFollowOp(class DirectiveFollowOp const &);
			DirectiveFollowOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveFormationOp
		{
		public:
			DirectiveFormationOp(class DirectiveFormationOp const &);
			DirectiveFormationOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveGotoOp
		{
		public:
			DirectiveGotoOp(class DirectiveGotoOp const &);
			DirectiveGotoOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveGuideOp
		{
		public:
			DirectiveGuideOp(class DirectiveGuideOp const &);
			DirectiveGuideOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveIdleOp
		{
		public:
			DirectiveIdleOp(class DirectiveIdleOp const &);
			DirectiveIdleOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveInstantTradelaneOp
		{
		public:
			DirectiveInstantTradelaneOp(class DirectiveInstantTradelaneOp const &);
			DirectiveInstantTradelaneOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveLaunchOp
		{
		public:
			DirectiveLaunchOp(class DirectiveLaunchOp const &);
			DirectiveLaunchOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveRamOp
		{
		public:
			DirectiveRamOp(class DirectiveRamOp const &);
			DirectiveRamOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveStrafeOp
		{
		public:
			DirectiveStrafeOp(class DirectiveStrafeOp const &);
			DirectiveStrafeOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveTractorBeamOp
		{
		public:
			DirectiveTractorBeamOp(class DirectiveTractorBeamOp const &);
			DirectiveTractorBeamOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveTrailOp
		{
		public:
			DirectiveTrailOp(class DirectiveTrailOp const &);
			DirectiveTrailOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveWaitForPlayerManeuverOp
		{
		public:
			DirectiveWaitForPlayerManeuverOp(class DirectiveWaitForPlayerManeuverOp const &);
			DirectiveWaitForPlayerManeuverOp(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN DirectiveWaitForShip
		{
		public:
			DirectiveWaitForShip(class DirectiveWaitForShip const &);
			DirectiveWaitForShip(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		struct EXTERN GSplinePath
		{
			GSplinePath(void);
			struct GSplinePath & operator=(struct GSplinePath const &);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		class EXTERN Personality
		{
		public:
			struct EXTERN BuzzHeadTowardUseStruct
			{
				BuzzHeadTowardUseStruct(void);
				struct BuzzHeadTowardUseStruct & operator=(struct BuzzHeadTowardUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN BuzzPassByUseStruct
			{
				BuzzPassByUseStruct(void);
				struct BuzzPassByUseStruct & operator=(struct BuzzPassByUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN CountermeasureUseStruct
			{
				CountermeasureUseStruct(void);
				struct CountermeasureUseStruct & operator=(struct CountermeasureUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN DamageReactionStruct
			{
				DamageReactionStruct(void);
				struct DamageReactionStruct & operator=(struct DamageReactionStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN EngineKillUseStruct
			{
				EngineKillUseStruct(void);
				struct EngineKillUseStruct & operator=(struct EngineKillUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN EvadeBreakUseStruct
			{
				EvadeBreakUseStruct(void);
				struct EvadeBreakUseStruct & operator=(struct EvadeBreakUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN EvadeDodgeUseStruct
			{
				EvadeDodgeUseStruct(void);
				struct EvadeDodgeUseStruct & operator=(struct EvadeDodgeUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN FormationUseStruct
			{
				FormationUseStruct(void);
				struct FormationUseStruct & operator=(struct FormationUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN GunUseStruct
			{
				GunUseStruct(void);
				struct GunUseStruct & operator=(struct GunUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN JobStruct
			{
				JobStruct(void);
				struct JobStruct & operator=(struct JobStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN MineUseStruct
			{
				MineUseStruct(void);
				struct MineUseStruct & operator=(struct MineUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN MissileReactionStruct
			{
				MissileReactionStruct(void);
				struct MissileReactionStruct & operator=(struct MissileReactionStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN MissileUseStruct
			{
				MissileUseStruct(void);
				struct MissileUseStruct & operator=(struct MissileUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN RepairUseStruct
			{
				RepairUseStruct(void);
				struct RepairUseStruct & operator=(struct RepairUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN StrafeUseStruct
			{
				StrafeUseStruct(void);
				struct StrafeUseStruct & operator=(struct StrafeUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			struct EXTERN TrailUseStruct
			{
				TrailUseStruct(void);
				struct TrailUseStruct & operator=(struct TrailUseStruct const &);

			public:
				unsigned char data[OBJECT_DATA_SIZE];
			};

			Personality(void);
			class Personality & operator=(class Personality const &);
			static float const  SCAN_CHANCE_DEFAULT;
			float get_range_threshold_value(void);
			float get_toughness_ratio(enum TOUGHNESS_TYPE);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		struct EXTERN SetFlagParams
		{
			SetFlagParams(struct SetFlagParams const &);
			SetFlagParams(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		struct EXTERN SetPersonalityParams
		{
			SetPersonalityParams(struct SetPersonalityParams const &);
			SetPersonalityParams(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

		struct EXTERN SetZoneBehaviorParams
		{
			SetZoneBehaviorParams(struct SetZoneBehaviorParams const &);
			SetZoneBehaviorParams(void);
			virtual bool validate(void);

		public:
			unsigned char data[OBJECT_DATA_SIZE];
		};

	};

	namespace StateGraph
	{
		EXTERN  int  get_state_graph(int,enum Type);
		EXTERN  int  get_state_graph(char const *,enum Type);
		EXTERN  struct IStateGraph const *  get_state_graph_internal(int);
		EXTERN  void  refresh_state_graph(void);
	};

};

class EXTERN IBehaviorManager
{
public:
	bool allow_head_tracking(void);
	bool cancel_behavior(enum CancelRequestType);
	bool enable_all_maneuvers(void);
	bool enable_maneuver(int,bool);
	enum EvaluateResult  external_player_evaluate(int);
	bool get_camera_level_status(void);
	float get_closest_trailing_ship(void)const ;
	struct IDirectiveInfo const * get_current_directive(void);
	struct IObjRW const * get_debugger_target(void)const ;
	bool get_docking_port(struct IObjRW const * &,int &);
	unsigned int get_parent_id(void);
	void get_personality(class pub::AI::Personality &);
	enum pub::AI::ScanResponse  get_scan_response(unsigned int);
	class Vector const  get_ship_up_direction(void);
	struct IStateGraph const * get_state_graph(void);
	class SystemManager * get_sys(void);
	bool get_user_turning_input_state(void);
	bool lock_maneuvers(bool);
	void refresh_state_graph(void);
	void reset_current_behavior_direction(void);
	void set_camera_mode(enum IBehaviorCameraMode);
	void set_content_callback(struct pub::AI::ContentCallback *);
	bool set_current_directive(struct IDirectiveInfo const &,class pub::AI::BaseOp const *);
	void set_directive_callback(struct pub::AI::DirectiveCallback *);
	enum pub::AI::OP_RTYPE  set_directive_priority(enum pub::AI::DirectivePriority);
	void set_personality(class pub::AI::Personality const &);
	void set_ship_up_direction(class Vector const &);
	void set_state_graph(int,bool);
	void set_turn_sensitivity(float);
	void set_user_turning_input_state(bool);
	void submit_camera_up(class Vector const &);
	void update_current_behavior_afterburner(bool);
	void update_current_behavior_auto_avoidance(bool);
	void update_current_behavior_auto_level(bool);
	void update_current_behavior_brake_reverse(bool);
	void update_current_behavior_cruise(bool);
	void update_current_behavior_direction(class Vector const &);
	void update_current_behavior_engage_engine(bool);
	void update_current_behavior_slide_strafe_burst(enum StrafeDir);
	void update_current_behavior_throttle(float);
	void update_level_camera(bool);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN ICRSplineSegment
{
	ICRSplineSegment(void);
	struct ICRSplineSegment & operator=(struct ICRSplineSegment const &);
	void calculate_arclength(void);
	class Vector  calculate_spline_tangent(float);
	class Vector  calculate_spline_vector(float);
	float get_spline_length(void);
	float get_t_from_point(class Vector const &,float,float);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN ID_String
{
	bool IsEmpty(void)const ;
	void clear(void);
	char const * get_string(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN INI_Reader
{
public:
	INI_Reader(class INI_Reader const &);
	INI_Reader(void);
	~INI_Reader(void);
	class INI_Reader & operator=(class INI_Reader const &);
	void close(void);
	bool find_header(char const *);
	bool get_bool(unsigned int);
	char const * get_file_name(void)const ;
	char const * get_header_ptr(void);
	char const * get_indexed_value(unsigned int);
	int get_line_num(void)const ;
	char const * get_line_ptr(void);
	char const * get_name(void)const ;
	char const * get_name_ptr(void);
	unsigned int get_num_parameters(void)const ;
	void get_state(struct State &)const ;
	bool get_value_bool(unsigned int);
	float get_value_float(unsigned int);
	int get_value_int(unsigned int);
	char const * get_value_ptr(void);
	char const * get_value_string(unsigned int);
	char const * get_value_string(void);
	unsigned short const * get_value_wstring(void);
	class Vector  get_vector(void);
	bool is_end(void)const ;
	bool is_header(char const *);
	bool is_number(char const *)const ;
	bool is_value(char const *);
	bool is_value_empty(unsigned int);
	void log_link(char const *)const ;
	bool open(char const *,bool);
	bool open_memory(char const *,unsigned int);
	bool read_header(void);
	bool read_value(void);
	void reset(void);
	void seek(unsigned int);
	void set_state(struct State const &);
	unsigned int tell(void)const ;
	double value_num(unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN IObjInspectImpl
{
	IObjInspectImpl(struct IObjInspectImpl const &);
	IObjInspectImpl(void);
	virtual ~IObjInspectImpl(void);
	struct IObjInspectImpl & operator=(struct IObjInspectImpl const &);
	virtual int are_thrusters_active(bool &)const ;
	virtual int can_point_at(bool &,unsigned short const &,class Vector const &,float)const ;
	virtual struct CObject const * cobject(void)const ;
	virtual int enumerate_cargo(struct IObjInspect::CargoEnumerator *)const ;
	virtual int enumerate_subtargets(struct IObjInspect::SubtargetEnumerator *)const ;
	virtual int find_equipment(unsigned short * const,unsigned int,unsigned int)const ;
	virtual bool generate_follow_offset(struct IObjInspect const *,class Transform &)const ;
	virtual int get_affiliation(unsigned int &)const ;
	virtual float get_angular_distance_travelled(float,float,float)const ;
	virtual float get_angular_distance_travelled(float,float,float,float)const ;
	virtual float get_angular_speed_XY(float,float)const ;
	virtual float get_angular_speed_Z(float)const ;
	virtual class Vector  get_angular_velocity(void)const ;
	virtual int get_archetype_extents(class Vector &,class Vector &)const ;
	virtual int get_atmosphere_range(float &)const ;
	virtual int get_attitude_towards(float &,struct IObjInspect const *)const ;
	virtual int get_attitude_towards_symmetrical(float &,struct IObjInspect const *,float &)const ;
	virtual int get_axis_throttle(class Vector &)const ;
	virtual int get_base(unsigned int &)const ;
	virtual int get_behavior_id(void)const ;
	virtual class Vector  get_center_of_mass(void)const ;
	virtual int get_data(void const * &)const ;
	virtual float get_distance_travelled(float,float,float,enum IObject::ThrustEquipType)const ;
	virtual int get_dock_hardpoints(int,enum TERMINAL_TYPE *,class Transform *,class Transform *,class Transform *,float *)const ;
	virtual int get_dock_target(unsigned int &)const ;
	virtual int get_equipment_status(struct EquipStatus &,unsigned short const &)const ;
	virtual int get_equipment_val(struct EquipmentVal &,unsigned short const &,enum EquipmentValType,float)const ;
	virtual int get_follow_leader(struct IObjRW * &)const ;
	virtual int get_follow_offset(class Vector &)const ;
	virtual int get_formation_followers(struct IObjRW * * const,unsigned int)const ;
	virtual int get_formation_leader(struct IObjRW * &)const ;
	virtual int get_formation_offset(class Vector &)const ;
	virtual int get_good_id(unsigned int &)const ;
	virtual int get_hardpoint(char const *,class Vector *,class Matrix *)const ;
	virtual int get_hold_left(float &)const ;
	virtual unsigned int const  get_id(void)const ;
	virtual long get_index(void)const ;
	virtual float get_initial_speed_to_coast_distance(float,bool)const ;
	virtual int get_lane_direction(class Transform const &,bool *)const ;
	virtual int get_lane_start(struct IObjInspect const *,struct IObjInspect const * &,class Vector &,class Vector &)const ;
	virtual float get_mass(void)const ;
	virtual float get_max_bank_angle(void)const ;
	virtual int get_nudge_vec(class Vector &)const ;
	virtual class Matrix const & get_orientation(void)const ;
	virtual int get_physical_radius(float &,class Vector &)const ;
	virtual class Vector const & get_position(void)const ;
	virtual int get_power(float &)const ;
	virtual float get_projected_axis_throttle_XY(float)const ;
	virtual float get_projected_axis_throttle_Z(float)const ;
	virtual float get_projected_throttle(float,enum IObject::ThrustEquipType)const ;
	virtual int get_rank(unsigned int &)const ;
	virtual int get_reputation(float &,unsigned int const &)const ;
	virtual int get_ring_side(class Transform const &,bool *)const ;
	virtual int get_scanlist(struct ScanList const * &,unsigned int,bool)const ;
	virtual float get_scanner_interference(void)const ;
	virtual int get_shield_status(float &,float &,bool &)const ;
	virtual int get_shield_status(float &,bool &)const ;
	virtual float get_speed(float,enum IObject::ThrustEquipType)const ;
	virtual int get_status(float &,float &)const ;
	virtual int get_status(float &)const ;
	virtual int get_strafe_dir(enum StrafeDir &)const ;
	virtual int get_sub_obj_center_of_mass(unsigned short,class Vector &)const ;
	virtual int get_subtarget(unsigned short &)const ;
	virtual int get_subtarget_center_of_mass(class Vector &)const ;
	virtual int get_target(struct IObjRW * &)const ;
	virtual int get_tgt_lead_fire_pos(unsigned short const &,class Vector &)const ;
	virtual int get_throttle(float &)const ;
	virtual float get_time_to_accelerate(float,float,float,enum IObject::ThrustEquipType)const ;
	virtual float get_time_to_accelerate_angularly(float,float,float)const ;
	virtual float get_time_to_accelerate_angularly(float,float,float,float)const ;
	virtual int get_toughness(void)const ;
	virtual class Transform const & get_transform(void)const ;
	virtual int get_type(unsigned int &)const ;
	virtual class Vector  get_velocity(void)const ;
	virtual int get_zone_props(unsigned long &)const ;
	virtual bool has_dock_hardpoints(void)const ;
	virtual int is_cruise_active(bool &,bool &)const ;
	virtual int is_cruise_active(bool &)const ;
	virtual bool is_dying(void)const ;
	virtual bool is_player(void)const ;
	virtual int is_pointing_at(bool &,unsigned short const &,float)const ;
	virtual bool is_targetable(void)const ;
	virtual int is_using_tradelane(bool *)const ;
	virtual int scan_cargo(struct IObjRW *,struct EquipDescVector &)const ;
	virtual int traverse_rings(unsigned int &,bool)const ;

private:
	int find_equipment(class CEquip const * &,unsigned short const &)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN ImageNode
{
public:
	ImageNode(class ImageNode const &);
	ImageNode(class TextRenderContext::Image const *);
	ImageNode(void);
	virtual ~ImageNode(void);
	class ImageNode & operator=(class ImageNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	class TextRenderContext::Image const * get_image(void);
	void set_image(class TextRenderContext::Image const *);

	virtual operator class ImageNode *(void);
	virtual operator class ImageNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN JustifyNode
{
public:
	JustifyNode(class JustifyNode const &);
	JustifyNode(enum TextJustify);
	virtual ~JustifyNode(void);
	class JustifyNode & operator=(class JustifyNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	enum TextJustify  get_justify(void);
	void set_justify(enum TextJustify);

	virtual operator class JustifyNode *(void);
	virtual operator class JustifyNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace LaunchActionVars
{
//@@@TODO	EXTERN  float const  launch_coast_time;
//@@@TODO	EXTERN  float const  launch_decel_time;
};

struct EXTERN LineParser32
{
	LineParser32(void);
	struct LineParser32 & operator=(struct LineParser32 const &);
	void clear(void);
	unsigned int fetch_string(char *,unsigned int);
	int find_char(char)const ;
	char get_char(void)const ;
	unsigned int read_string(char *,char const *);
	unsigned int read_terminator2(char *,char,char);
	unsigned int read_terminator(char *,char);
	void set(char const *,unsigned int);
	bool skip_char(char);
	void skip_white(void);
	bool terminate_line(char);
	bool whitespace(char)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace Loadout
{
	struct EXTERN Map
	{
		Map(struct Map const &);
		Map(void);
		~Map(void);
		struct Map & operator=(struct Map const &);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	EXTERN  void  Free(void);
	EXTERN  struct Map const *  Get(unsigned int);
	EXTERN  unsigned int  GetID(char const *);
	EXTERN  int  Load(char const *,bool);
	EXTERN  bool  ReadCargoLine(class INI_Reader &,struct EquipDesc &);
	EXTERN  bool  ReadEquipLine(class INI_Reader &,struct EquipDesc &);
};

//
// Defined in FLCoreDALib.h
//-------------------------
//class EXTERN MD5Hash
//{
//public:
//	MD5Hash(class MD5Hash const &);
//	class MD5Hash & operator=(class MD5Hash const &);
//	unsigned char * GetStatePtr(void);

//public:
//	unsigned char data[OBJECT_DATA_SIZE];
//};

struct EXTERN MPCritSec
{
	MPCritSec(void);
	~MPCritSec(void);
	struct MPCritSec & operator=(struct MPCritSec const &);
	void lock(void);
	void unlock(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN MarketGoodInfo
{
	MarketGoodInfo(void);
	struct MarketGoodInfo & operator=(struct MarketGoodInfo const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN MarshalBuffer
{
public:
	MarshalBuffer(void);
	class MarshalBuffer & operator=(class MarshalBuffer const &);
	void clear(void);
	struct Costume  get_Costume(void);
	class EquipDescList  get_EquipDescList(void);
	unsigned int get_FL_ID(void);
	struct FmtStr  get_FmtStr(void);
	struct GoodDescList  get_GoodDescList(void);
	unsigned short get_U16(void);
	unsigned long get_U32(void);
	unsigned char get_U8(void);
	bool get_bool(void);
	unsigned char const * get_buffer(void)const ;
	int get_buffer_size(void)const ;
	float get_float(void);
	void get_image(unsigned char *);
	void get_image(unsigned short *);
	void get_image(int *);
	void get_image(unsigned long *);
	void get_image(float *);
	int get_int(void);
	int get_num_written(void)const ;
	char * get_string(void);
	void get_string_to_buffer(char *,int);
	void get_void(void *,int);
	unsigned short * get_wstring(void);
	bool is_empty(void)const ;
	void put_Costume(struct Costume const &);
	void put_EquipDescList(class EquipDescList const &);
	void put_FL_ID(unsigned int);
	void put_FmtStr(struct FmtStr const &);
	void put_GoodDescList(struct GoodDescList const &);
	void put_U16(unsigned short);
	void put_U32(unsigned long);
	void put_U8(unsigned char);
	void put_bool(bool);
	void put_float(float);
	void put_image(unsigned char const &);
	void put_image(unsigned short const &);
	void put_image(int const &);
	void put_image(unsigned long const &);
	void put_image(float const &);
	void put_int(int);
	void put_string(char const *);
	void put_void(void const *,int);
	void put_wstring(unsigned short const *);
	void skip_over(int);
	void use_default(void);
	void use_read_buffer(unsigned char const *,int);
	void use_write_buffer(unsigned char *,int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN MessageHandler
{
	MessageHandler(class IMessageRouter *);
	virtual ~MessageHandler(void);
	unsigned int get_id(void)const ;

protected:
	virtual void send_delayed_message(class StateMachineMessage *,float,unsigned int);
	virtual void send_delayed_message_to_me(class StateMachineMessage *,float,int);
	virtual void send_immediate_message(class StateMachineMessage *,unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN MissionVendorAcceptance
{
public:
	MissionVendorAcceptance(class MissionVendorAcceptance const &);
	MissionVendorAcceptance(void);
	~MissionVendorAcceptance(void);
	class MissionVendorAcceptance & operator=(class MissionVendorAcceptance const &);
	void clear(void);
	void destroy(void);
	unsigned long get_key(void)const ;
	void marshal(class MarshalBuffer *)const ;
	void unmarshal(class MarshalBuffer *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN MissionVendorProperties
{
public:
	MissionVendorProperties(class MissionVendorProperties const &);
	MissionVendorProperties(void);
	~MissionVendorProperties(void);
	class MissionVendorProperties & operator=(class MissionVendorProperties const &);
	void clear(void);
	void destroy(void);
	char const * get_icon_texture(void)const ;
	unsigned long get_key(void)const ;
	void init(struct MissionVendorOfferDescription const &);
	void marshal(class MarshalBuffer *)const ;
	void unmarshal(class MarshalBuffer *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace NewChar
{
	EXTERN  class IDatabase *  TheDB;
};

class EXTERN NewsBroadcastProperties
{
public:
	NewsBroadcastProperties(class NewsBroadcastProperties const &);
	NewsBroadcastProperties(void);
	~NewsBroadcastProperties(void);
	class NewsBroadcastProperties & operator=(class NewsBroadcastProperties const &);
	void clear(void);
	void destroy(void);
	unsigned long get_key(void)const ;
	char const * get_logo_texture(void)const ;
	void init(struct NewsBroadcastDescription const &);
	void marshal(class MarshalBuffer *)const ;
	void unmarshal(class MarshalBuffer *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN NullNode
{
public:
	NullNode(class NullNode const &);
	NullNode(void);
	virtual ~NullNode(void);
	class NullNode & operator=(class NullNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);

	virtual operator class NullNode *(void);
	virtual operator class NullNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN ParagraphNode
{
public:
	ParagraphNode(class ParagraphNode const &);
	ParagraphNode(void);
	virtual ~ParagraphNode(void);
	class ParagraphNode & operator=(class ParagraphNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);

	virtual operator class ParagraphNode *(void);
	virtual operator class ParagraphNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN PathfindManager
{
	void clear_user_zone(void);
	bool get_user_zone(struct UserZone &);
	void submit_user_zone(struct UserZone const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN PetalInterfaceDatabase
{
public:
	PetalInterfaceDatabase(class PetalInterfaceDatabase const &);
	PetalInterfaceDatabase(void);
	~PetalInterfaceDatabase(void);
	class PetalInterfaceDatabase & operator=(class PetalInterfaceDatabase const &);
	void destroy(void);
	struct petal_record const * find_record(int,unsigned long)const ;
	static int  get_category(char const *);
	void load_from_ini(char const *);

private:
	void add_record(int,char const *,char const *,char * *,int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN PositionNode
{
public:
	PositionNode(class PositionNode const &);
	PositionNode(void);
	virtual ~PositionNode(void);
	class PositionNode & operator=(class PositionNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	float get_pos_h(void);
	float get_pos_v(void);
	bool is_rel_h(void);
	bool is_rel_v(void);
	void set_pos(float,float);
	void set_pos_h(float);
	void set_pos_v(float);
	void set_rel_h(bool);
	void set_rel_v(bool);

	virtual operator class PositionNode *(void);
	virtual operator class PositionNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN RDLNode
{
public:
	RDLNode(class RDLNode const &);
	RDLNode(void);
	virtual ~RDLNode(void);
	class RDLNode & operator=(class RDLNode const &);

	virtual operator class AttribStackNode *(void);
	virtual operator class ClipNode *(void);
	virtual operator class ImageNode *(void);
	virtual operator class JustifyNode *(void);
	virtual operator class NullNode *(void);
	virtual operator class ParagraphNode *(void);
	virtual operator class PositionNode *(void);
	virtual operator class RDLRefNode *(void);
	virtual operator class StyleNode *(void);
	virtual operator class TRANode *(void);
	virtual operator class TextNode *(void);
	virtual operator class TextPtrNode *(void);
	virtual operator class AttribStackNode const *(void)const ;
	virtual operator class ClipNode const *(void)const ;
	virtual operator class ImageNode const *(void)const ;
	virtual operator class JustifyNode const *(void)const ;
	virtual operator class NullNode const *(void)const ;
	virtual operator class ParagraphNode const *(void)const ;
	virtual operator class PositionNode const *(void)const ;
	virtual operator class RDLRefNode const *(void)const ;
	virtual operator class StyleNode const *(void)const ;
	virtual operator class TRANode const *(void)const ;
	virtual operator class TextNode const *(void)const ;
	virtual operator class TextPtrNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN RDLRefNode
{
public:
	RDLRefNode(class RenderDisplayList &);
	RDLRefNode(class RDLRefNode const &);
	virtual ~RDLRefNode(void);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	class RenderDisplayList const & get_list(void);

	virtual operator class RDLRefNode *(void);
	virtual operator class RDLRefNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN Rect
{
	Rect(int,int,int,int);
	Rect(void);
	struct Rect & operator=(struct Rect const &);
	int area(void)const ;
	int bottommost(void)const ;
	void clear(void);
	void get_center(int *,int *)const ;
	int height(void)const ;
	void init(int,int,int,int);
	void init_from_ltrb(int,int,int,int);
	int leftmost(void)const ;
	bool nonnull(void)const ;
	bool null(void)const ;
	bool point_is_inside(int,int)const ;
	int rightmost(void)const ;
	int topmost(void)const ;
	int width(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN RenderDisplayList
{
public:
	RenderDisplayList(class RenderDisplayList const &);
	RenderDisplayList(void);
	~RenderDisplayList(void);
	class RenderDisplayList & operator=(class RenderDisplayList const &);
	void execute(class TextRenderContext &,bool);
	void get_dimensions(class TextRenderContext &,float &,float &,float &);
	int get_element_count(void)const ;
	bool get_element_pos(class TextRenderContext &,int,float &,float &,float &);
	void optimize(void);
	void update(float);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace Reputation
{
	struct Relation;

	namespace Vibe
	{
		EXTERN  int  AdjustAttitude(int const &,int const &,float);
		EXTERN  int  Alloc(int const &);
		EXTERN  int  AttitudeTowards(int const &,int const &,float &);
		EXTERN  int  AttitudeTowardsSymmetrical(int const &,int const &,float &,float &);
		EXTERN  unsigned int  Count(void);
		EXTERN  int  EnsureExists(int const &);
		EXTERN  int  Free(int const &);
		EXTERN  void  FreeDynamic(void);
		EXTERN  int  Get(int const &,unsigned int &,unsigned int &,unsigned char &,struct Relation * const,struct FmtStr &,struct FmtStr &,unsigned short const * &);
		EXTERN  int  GetAffiliation(int const &,unsigned int &,bool);
		EXTERN  unsigned int  GetClientID(int);
		EXTERN  int  GetGroupFeelingsTowards(int const &,unsigned int const &,float &);
		EXTERN  int  GetInfocard(int const &,unsigned int &);
		EXTERN  int  GetName(int const &,struct FmtStr &,struct FmtStr &,unsigned short const * &);
		EXTERN  int  GetRank(int const &,unsigned int &);
		EXTERN  int  Set(int const &,unsigned int,unsigned int,unsigned char,struct Reputation::Relation const * const,struct FmtStr const &,struct FmtStr const &,unsigned short const *);
		EXTERN  int  SetAffiliation(int const &,unsigned int,bool);
		EXTERN  int  SetAttitudeTowardsPlayer(int,float);
		EXTERN  int  SetClientID(int,unsigned int);
		EXTERN  int  SetGroupFeelingsTowards(int const &,unsigned int const &,float);
		EXTERN  int  SetInfocard(int const &,unsigned int);
		EXTERN  int  SetName(int const &,struct FmtStr const &,struct FmtStr const &,unsigned short const *);
		EXTERN  int  SetRank(int const &,unsigned int);
		EXTERN  bool  Verify(int);
	};

	EXTERN  void  FreeFeelings(void);
	EXTERN  std::map<unsigned int,unsigned int> *  GetChangedAffiliationClientMap(void);
	EXTERN  bool  IsStoryFaction(unsigned int);
	EXTERN  void  LoadFeelings(class INI_Reader &);
	EXTERN  void  Save(struct ISave *);
	EXTERN  void  Shutdown(void);
	EXTERN  bool  Startup(char const *);
	EXTERN  int  affect_relation(unsigned int const &,unsigned int const &,float);
	EXTERN  void  enumerate(struct RepGroupCB *);
	EXTERN  int  get_feelings_towards(unsigned int,unsigned int,float &);
	EXTERN  unsigned int  get_id(struct TString<16> const &);
	EXTERN  unsigned int  get_info_card(unsigned int);
	EXTERN  unsigned int  get_name(unsigned int);
	EXTERN  int  get_nickname(struct TString<16> &,unsigned int const &);
	EXTERN  unsigned int  get_short_name(unsigned int);
	EXTERN  unsigned int  group_count(void);
	EXTERN  void  set(struct TString<16> const &,struct Relation * const,unsigned int);
};

struct EXTERN RoomButtonInfo
{
	RoomButtonInfo(void);
	~RoomButtonInfo(void);
	void clear(void);
	void destroy(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN RoomCameraInfo
{
	RoomCameraInfo(void);
	~RoomCameraInfo(void);
	struct RoomCameraInfo & operator=(struct RoomCameraInfo const &);
	void clear(void);
	void destroy(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN RoomData
{
public:
	RoomData(class RoomData const &);
	RoomData(void);
	~RoomData(void);
	class RoomData & operator=(class RoomData const &);
	void clear(void);
	void destroy(void);
	void enumerate_CharacterPlacement_ini(void (*)(int,class INI_Reader *,void *),void *)const ;
	struct RoomCameraInfo const * find_camera(char const *,char const *)const ;
	struct RoomCameraInfo const * find_camera_generic(char const *,char const *)const ;
	struct SetpointInfo const * find_setpoint(char const *,char const *)const ;
	struct SetpointInfo const * find_setpoint_generic(char const *,char const *)const ;
	void fixup(long);
	struct RoomCameraInfo const * get_camera_info(void)const ;
	void init(unsigned int,unsigned int,char const *,char const *);
	void load(void);
	void unfixup(void);
	void unload(void);

private:
	void add_set_script_Camera(unsigned long,class Csys const &,char const *,struct ThornCameraProperties const *);
	void add_set_script_Prop(char const *,char const *,int,class Csys const &,bool,bool,bool,bool,unsigned char,signed char,unsigned long,char const *,unsigned long,bool);
	void add_set_script_Setpoint(unsigned long,class Csys const &,char const *,struct ThornEntity const *);
	void add_set_script_light(unsigned long,class Csys const &,struct ThornLightProperties const *,unsigned char);
	struct SetpointInfo const * apply_setpoint(char const *,char * *,class Csys *,char const *);
	struct CharPlaceInfo * find_CharacterPlacement(char const *);
	void fixup_FlashLight_list(long,class HardpointSummary const *);
	static void  make_setpoint_name_generic(char const *,char *);
	void read_Camera_block(class INI_Reader *);
	void read_CharacterPlacement_block(class INI_Reader *);
	void read_FlashLightLine_block(class INI_Reader *);
	void read_FlashLightSet_block(class INI_Reader *);
	void read_ForSaleShipPlacement_block(class INI_Reader *);
	void read_Hotspot_block(class INI_Reader *);
	void read_PlayerShipPlacement_block(class INI_Reader *);
	void read_RoomInfo_block(class INI_Reader *);
	void read_Sound_block(class INI_Reader *);
	void read_ambient_script(class INI_Reader *);
	void read_from_ini(char const *);
	void read_set_script(char const *);
	void setup_Camera(void);
	void unfixup_FlashLight_list(void);
	void unsetup_Camera(void);
	void warn(class INI_Reader *,bool);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN RoomLightInfo
{
	RoomLightInfo(void);
	~RoomLightInfo(void);
	struct RoomLightInfo & operator=(struct RoomLightInfo const &);
	void clear(void);
	void destroy(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN RoomPropInfo
{
	RoomPropInfo(void);
	~RoomPropInfo(void);
	struct RoomPropInfo & operator=(struct RoomPropInfo const &);
	void clear(void);
	void destroy(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace RtcSlider
{
	EXTERN  float  get_default_fps_cap(void);
	EXTERN  float  get_fps_cap(void);
	EXTERN  float  get_slider(void);
	EXTERN  bool  is_enabled(unsigned long);
	EXTERN  bool  is_enabled(char const *);
	EXTERN  void  load(char const *);
	EXTERN  void  set_slider(float);
	EXTERN  bool  validate_setting(char const *,char const *);
};

struct EXTERN SMControllerEvent
{
	SMControllerEvent(int,void const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN SMEventData
{
	SMEventData(enum STATE_MACHINE_EVENT_TYPE);
	virtual enum STATE_MACHINE_EVENT_TYPE  get_event_type(void)const ;
	bool is_sm_event(void)const ;
	bool is_user_event(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN SMMChangeState
{
	SMMChangeState(int);
	virtual class StateMachineMessage * clone(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN SMMessage
{
	SMMessage(class StateMachineMessage *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN ScanList
{
	ScanList(struct ScanList const &);
	ScanList(void);
	~ScanList(void);
	struct ScanList & operator=(struct ScanList const &);
	bool add(struct IObjRW *);
	int add_in_range(class Vector const &,float,struct IObjDB *,unsigned int,struct Filter *);
	void remove(struct IObjRW *);
	void reset(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN ScriptBehavior
{
public:
	ScriptBehavior(class ScriptBehavior const &);
	ScriptBehavior(void);
	~ScriptBehavior(void);
	class ScriptBehavior & operator=(class ScriptBehavior const &);
	void clear(void);
	void destroy(void);
	unsigned long get_key(void)const ;
	void init(struct CharacterBehaviorDescription const &);
	void marshal(class MarshalBuffer *)const ;
	void unmarshal(class MarshalBuffer *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN SetpointInfo
{
	SetpointInfo(struct SetpointInfo const &);
	SetpointInfo(void);
	~SetpointInfo(void);
	void clear(void);
	void destroy(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN SetpointProperties
{
	SetpointProperties(struct SetpointProperties const &);
	SetpointProperties(void);
	~SetpointProperties(void);
	struct SetpointProperties & operator=(struct SetpointProperties const &);
	void clear(void);
	char const * combine_to_name(void)const ;
	void destroy(void);
	void extract_from_name(char const *);
	void set_segment(char const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace ShieldEquipConsts
{
	EXTERN  float  HULL_DAMAGE_FACTOR;
};

struct EXTERN ShipGunStats
{
	ShipGunStats(void);
	struct ShipGunStats & operator=(struct ShipGunStats const &);
	void clear(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN ShipPlaceInfo
{
	ShipPlaceInfo(void);
	~ShipPlaceInfo(void);
	void clear(void);
	void destroy(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace SolarReps
{
	EXTERN  int  FindSolarRep(struct ID_String const &);
};

class EXTERN SphereIntruderChecker
{
public:
	SphereIntruderChecker(class SphereIntruderChecker const &);
	SphereIntruderChecker(void);
	~SphereIntruderChecker(void);
	class SphereIntruderChecker & operator=(class SphereIntruderChecker const &);
	void check_sphere(unsigned int,class Vector const &,float,class std::list<struct CObject *,class std::allocator<struct CObject *> > &);

protected:
	virtual void added(struct CObject *);
	virtual void deleted(struct CObject *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN StateMachine
{
	StateMachine(void);
	virtual ~StateMachine(void);
	int get_state(void)const ;
	virtual void process(struct SMEventData const *);
	void reset(void);
	void start(void);

protected:
	virtual void handle_state_change(void);
	void set_state(int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN StateMachineGroup
{
public:
	StateMachineGroup(class IMessageRouter *);
	virtual ~StateMachineGroup(void);
	virtual void add_state_machine(class StateMachineMessageHandler *);
	virtual void remove_state_machine(unsigned int);
	virtual void remove_state_machine(class StateMachineMessageHandler const *);

protected:
	virtual void process(struct SMEventData const *);
	void remove_dying_machines(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN StateMachineMessage
{
public:
	StateMachineMessage(class StateMachineMessage const &);
	StateMachineMessage(unsigned int);
	StateMachineMessage(float,unsigned int,unsigned int,unsigned int,int);
	StateMachineMessage(void);
	virtual ~StateMachineMessage(void);
	static unsigned int  GenerateUniqueMessageType(void);
	virtual class StateMachineMessage * clone(void)const ;
	int get_delivery_state(void)const ;
	float get_delivery_time(void)const ;
	unsigned int get_message_type(void)const ;
	unsigned int get_receiver(void)const ;
	unsigned int get_sender(void)const ;
	bool is_delivered(void)const ;
	void set_delivered(bool);
	void set_delivery_options(float,unsigned int,unsigned int,int);
	void set_delivery_state(int);
	void set_delivery_time(float);
	void set_message_type(unsigned int);
	void set_receiver(unsigned int);
	void set_sender(unsigned int);

	static void * operator new(unsigned int);
	static void operator delete(void *);

private:
	static unsigned int  s_unique_message_type_generator;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN StateMachineMessageHandler
{
public:
	StateMachineMessageHandler(class IMessageRouter *);
	virtual void receive_message(class StateMachineMessage *);

protected:
	void send_delayed_message_to_me(class StateMachineMessage *,float,enum SM_MESSAGE_SCOPE,int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class Style
{
public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN StyleCollection
{
public:
	class StyleCollection & operator=(class StyleCollection const &);
	static class RenderDisplayList &  get_style(unsigned short);
	static void  remove_style(unsigned short);
	static void  set_style(unsigned short,struct TextRenderAttributes const &);
	static void  set_style(unsigned short,class RenderDisplayList const &);

protected:
	static std::map<unsigned short,class Style>  mStyles;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN StyleNode
{
public:
	StyleNode(class StyleNode const &);
	StyleNode(unsigned short);
	StyleNode(void);
	virtual ~StyleNode(void);
	class StyleNode & operator=(class StyleNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	unsigned short get_style_id(void);
	void set_style_id(unsigned short);

	virtual operator class StyleNode *(void);
	virtual operator class StyleNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace SubObjectID
{
	class EXTERN CollGroupIdMaker
	{
	public:
		CollGroupIdMaker(void);
		class SubObjectID::CollGroupIdMaker & operator=(class SubObjectID::CollGroupIdMaker const &);
		unsigned short CreateGroupID(void);
		void Reset(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	class EXTERN EquipIdMaker
	{
	public:
		EquipIdMaker(void);
		class SubObjectID::EquipIdMaker & operator=(class SubObjectID::EquipIdMaker const &);
		unsigned short CreateEquipID(void);
		void Reset(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	class EXTERN ShieldIdMaker
	{
	public:
		ShieldIdMaker(void);
		class SubObjectID::ShieldIdMaker & operator=(class SubObjectID::ShieldIdMaker const &);
		unsigned short CreateShieldID(void);
		void Reset(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	EXTERN  bool  IsArchGroupID(unsigned short);
	EXTERN  bool  IsEquipID(unsigned short);
	EXTERN  bool  IsShieldEquipID(unsigned short);
};

class EXTERN TRANode
{
public:
	TRANode(struct TextRenderAttributes const &,unsigned int,unsigned int);
	TRANode(class TRANode const &);
	TRANode(void);
	virtual ~TRANode(void);
	class TRANode & operator=(class TRANode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	struct TextRenderAttributes const & get_attributes(void);
	unsigned int get_default_mask(void);
	unsigned int get_mask(void);
	void set_attributes(struct TextRenderAttributes const &,unsigned int);
	void set_default_mask(unsigned int);
	void set_mask(unsigned int);

	virtual operator class TRANode *(void);
	virtual operator class TRANode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN TargetManager
{
	int remove_forced_target(unsigned int);
	void set_player_enemy_clamp(int,int);
	int submit_forced_target(unsigned int);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN TextFile32
{
	TextFile32(struct TextFile32 const &);
	TextFile32(void);
	~TextFile32(void);
	struct TextFile32 & operator=(struct TextFile32 const &);
	unsigned int get_line_num(void)const ;
	bool read_line(struct LineParser32 &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN TextNode
{
public:
	TextNode(class TextNode const &);
	TextNode(std::wstring const &,int);
	TextNode(unsigned short const *,int);
	TextNode(void);
	virtual ~TextNode(void);
	class TextNode & operator=(class TextNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	void append_text(std::wstring const &,int);
	void append_text(unsigned short const *,int);
	std::wstring const & get_text(void)const ;
	void set_text(std::wstring const &,int);
	void set_text(unsigned short const *,int);

	virtual operator class TextNode *(void);
	virtual operator class TextNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN TextPtrNode
{
public:
	TextPtrNode(class TextPtrNode const &);
	TextPtrNode(unsigned short const *,int);
	TextPtrNode(void);
	virtual ~TextPtrNode(void);
	class TextPtrNode & operator=(class TextPtrNode const &);
	virtual class RDLNode * Clone(void)const ;
	virtual void Execute(class TextRenderContext &,bool);
	virtual void GetElementPos(int,class TextRenderContext &,int &)const ;
	virtual void GetElementSize(int &)const ;
	virtual void GetVisualSize(class TextRenderContext const &,struct VisualSize &)const ;
	virtual bool SplitAtSize(class TextRenderContext const &,int,unsigned int,class RDLNode * &,class RDLNode * &)const ;
	virtual void Update(float);
	unsigned short const * get_text(void)const ;
	int get_text_length(void)const ;
	void set_text(unsigned short const *,int);

	virtual operator class TextPtrNode *(void);
	virtual operator class TextPtrNode const *(void)const ;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN ThrustManager
{
	void engage_cruise(bool);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace ThrusterEquipConsts
{
	EXTERN  struct ID_String  EXTERIOR_SOUND_NAME;
	EXTERN  float  INSIDE_CONE_ANGLE;
	EXTERN  struct ID_String  INTERIOR_SOUND_NAME;
	EXTERN  float  MAX_VOLUME_FORCE;
	EXTERN  float  MIN_VOLUME_FORCE;
	EXTERN  float  OUTSIDE_CONE_ANGLE;
	EXTERN  float  OUTSIDE_CONE_ATTENUATION;
};

namespace Timing
{
	struct EXTERN Delta
	{
		Delta(void);
		struct Timing::Delta & operator=(struct Timing::Delta const &);
		double calc_dt(void);
		void init(void);
		double read_dt(void);
		void start(void);
		void stop(void);
		void swap(void);

	public:
		unsigned char data[OBJECT_DATA_SIZE];
	};

	EXTERN  double  GetGlobalTime(void);
	EXTERN  int  GetMachineSpeed(void);
	EXTERN  void  UpdateGlobalTime(double);
	EXTERN  void  init(void);
	EXTERN  double  read(void);
	EXTERN  __int64  read_ticks(void);
	EXTERN  double  seconds(__int64 const &);
};

class EXTERN TractorArm
{
public:
	TractorArm(class TractorArm const &);
	TractorArm(class CETractor *);
	~TractorArm(void);
	class TractorArm & operator=(class TractorArm const &);
	enum TractorFailureCode  GetErrorCode(void)const ;
	enum Mode  GetMode(void)const ;
	struct CLoot * GetTarget(void)const ;
	class Vector  GetTipPos(void)const ;
	bool IsOn(void)const ;
	void SetTarget(struct CLoot *);
	void TurnOff(void);
	void Update(float);

protected:
	static float const  ACQUIRE_DELAY;
	static float const  GRAB_TOLERANCE_SQUARED;

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN TradeResponseInfo
{
public:
	TradeResponseInfo(class TradeResponseInfo const &);
	TradeResponseInfo(void);
	~TradeResponseInfo(void);
	class TradeResponseInfo & operator=(class TradeResponseInfo const &);
	void clear(void);
	void destroy(void);
	void marshal(class MarshalBuffer *)const ;
	void unmarshal(class MarshalBuffer *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace TurnHelper
{
	EXTERN  class Vector   get_angular_throttle(class Matrix const &,class Matrix const &,float *);
};

struct EXTERN Watchable
{
	Watchable(void);
	~Watchable(void);
	struct Watchable & operator=(struct Watchable const &);
	unsigned int unwatch(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN XMLReader
{
public:
	XMLReader(class XMLReader const &);
	XMLReader(void);
	class XMLReader & operator=(class XMLReader const &);
	virtual bool extract_text_from_buffer(unsigned short *,unsigned int,unsigned int &,char const *,unsigned int);
	virtual bool read_buffer(class RenderDisplayList &,char const *,unsigned int);
	virtual bool read_file(class RenderDisplayList &,char const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN XMLWriter
{
public:
	XMLWriter(class XMLWriter const &);
	XMLWriter(void);
	class XMLWriter & operator=(class XMLWriter const &);
	virtual bool write_buffer(class RenderDisplayList const &,char *,unsigned int,unsigned int &);
	virtual bool write_file(class RenderDisplayList const &,char const *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN accessory
{
	accessory(struct accessory const &);
	accessory(void);
	~accessory(void);
	struct accessory & operator=(struct accessory const &);
	char const * get_accessory_hardpoint(void)const ;
	char const * get_character_hardpoint(void)const ;
	std::list<std::string> const & get_materials(void)const ;
	char const * get_mesh(void)const ;
	char const * get_name(void)const ;
	unsigned long get_name_crc(void)const ;
	void init(char const *,char const *,char const *,char const *,std::list<std::string> const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN bodypart
{
	bodypart(struct bodypart const &);
	bodypart(void);
	~bodypart(void);
	struct bodypart & operator=(struct bodypart const &);
	int get_gender(void)const ;
	char const * get_mesh(void)const ;
	char const * get_name(void)const ;
	unsigned long get_name_crc(void)const ;
	std::list<std::string> * get_petal_anims(void)const ;
	class DetailSwitchTable * get_switch_table(void)const ;
	void init(char const *,char const *,int,std::list<std::string> *,class DetailSwitchTable *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN option_spec
{
	struct option_spec & operator=(struct option_spec const &);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

namespace Geometry
{
	struct Frustum;
	struct Sphere;
};

EXTERN bool  operator!=(struct CHARACTER_ID const &,struct CHARACTER_ID const &);
EXTERN bool  operator!=(struct Rect const &,struct Rect const &);
EXTERN bool  operator<(struct CHARACTER_ID const &,struct CHARACTER_ID const &);

EXTERN void  AppendMissionLogData(struct FmtStr const *,unsigned char * &,int &,int);
EXTERN unsigned int  Arch2Good(unsigned int);
EXTERN void  BaseDataList_destroy(void);
EXTERN class BaseDataList *  BaseDataList_get(void);
EXTERN void  BaseDataList_load(void);
EXTERN void  BaseDataList_load_market_data(char const *);
EXTERN void  BuildDirectory(char const *);
EXTERN float  CHATTER_MAX_DIST;
EXTERN float  CHATTER_MAX_DIST_ATTEN;
EXTERN float  CHATTER_START_ATTEN;
EXTERN float  COLLISION_DAMAGE_FACTOR;
EXTERN int  COMM_CONFLICT_PRIORITY_CUTOFF;
EXTERN float  COMM_PLAYER_FAR_DIST;
EXTERN float  COMM_PLAYER_FAR_DIST_ATTEN;
EXTERN class Behavior *  CREATE_BEHAVIOR(int);
EXTERN void  CleanUpDatabases(void);
EXTERN void  CompoundInstanceAnalyze(long,void (*)(long,void *),void *);
EXTERN int  CompoundInstanceCount(long);
EXTERN long  CompoundInstanceFindFirstName(long,char const *);
EXTERN void  CompoundInstanceList(long,int *,long * *);
EXTERN void  ComputeExplosiveImpulses(long,class Vector &,class Vector &,class Vector &);
EXTERN bool  CostumeGenderAdjust(int *,int);
EXTERN bool  Costume_is_equal(struct Costume const &,struct Costume const &);
EXTERN unsigned int  CreateID(char const *);

EXTERN float  Csys_error(class Csys const &,class Csys const &);
EXTERN class Csys   Csys_identity(void);
EXTERN class Csys   Csys_init(class Vector const &,class Matrix const &);
EXTERN class Csys   Csys_interpolate(class Csys,class Csys,float);

EXTERN void  DAEngine_create_filesystem(char const *,struct IFileSystem * *,char const *);
EXTERN void  DAEngine_release_filesystem(struct IFileSystem * *);
EXTERN class Csys   DALib_Engine_get_csys(long);
EXTERN void  DALib_Engine_set_csys(long,class Csys const &);

EXTERN struct ID_String  DEATH_COMM_FUSE;
EXTERN double  DaysPerSecond;
EXTERN void  DebugPrint(char const *,...);
EXTERN unsigned int  DecodeType(char const *);
EXTERN class Matrix   EulerMatrix(class Vector const &);
EXTERN void  ExtractMissionLogData(struct FmtStr *,unsigned char * &,int &);
EXTERN float  FIRE_FAILED_DELAY;
EXTERN struct ID_String  FIRE_FAILED_SOUND;

EXTERN long  FindChild(long,char const *);
EXTERN bool  FindHardpoint(long,char const *,long &);
EXTERN bool  FindHardpoint_OS(long,char const *,long &,struct HardpointInfo &);
EXTERN bool  FindHardpoint_PS(long,char const *,long &,struct HardpointInfo &);
EXTERN void  FreeCostumeDescriptions(void);
EXTERN void  FreeSpatial(struct ISpatialPartition *);
EXTERN bool  FrustumCull(struct Geometry::Frustum const &,struct Universe::IZone const *);
EXTERN class IBehaviorManager *  GetBehaviorManager(struct IObjRW *);
EXTERN class CostumeDescriptions const *  GetCostumeDescriptions(void);
EXTERN class Matrix   GetDirectionMatrix(class Transform const &,class Vector const &);
EXTERN void  GetFileSysPath(char *,char const *,struct IFileSystem *);
EXTERN char const *  GetFullFilename(char const *);
EXTERN long  GetRoot(long);
EXTERN struct CObject *  GetRoot(struct CObject const *);
EXTERN bool  GetScreenShotPath(char * const);
EXTERN float  GetSphereIntersectVol(float,float,float);
EXTERN bool  GetUserDataPath(char * const);
EXTERN bool  GetUserLocalDataPath(char * const);
EXTERN void  GiveClientRunPermission(void);
EXTERN void  GiveServerRunPermission(void);
EXTERN unsigned int  Good2Arch(unsigned int);
EXTERN void  GoodList_destroy(void);
EXTERN class GoodInfoList *  GoodList_get(void);
EXTERN void  GoodList_load(char const *);
EXTERN bool  HardpointPosition(long,char const *,class Vector *,class Matrix *);
EXTERN bool  HardpointPositionA(long,char const *,class Vector *,class Matrix *);
EXTERN void  HardpointToObject(long,struct HardpointInfo &);
EXTERN void  HardpointToWorld(long,struct HardpointInfo &);
EXTERN void  HexToWide(char const *,unsigned short *);
EXTERN bool  InitializeRichText(int);
EXTERN bool  IsDescendant(long,long);
EXTERN bool  IsMPServer(void);
EXTERN float  JETTISONED_CARGO_VELOCITY;
EXTERN bool  JointEnumCallback(long,long,struct JointInfo const *,void *);
EXTERN float  LOOT_OWNER_SAFE_TIME;
EXTERN float  LOOT_UNSEEN_LIFE_TIME;
EXTERN float  LOOT_UNSEEN_RADIUS;
EXTERN bool  LayoutRichText(class TextRenderContext &,class RenderDisplayList const &,int,class RenderDisplayList &,int,int,bool,int *,bool);
EXTERN void  LoadBodypartDescriptions(char const *);
EXTERN void  LoadCostumeDescriptions(char const *);
EXTERN class Matrix   LookMatrix(class Vector const &);
EXTERN class Matrix   LookMatrixYup(class Vector const &);
EXTERN int  MAX_PLAYER_AMMO;
EXTERN float  MUSIC_CROSS_FADE_DELAY;
EXTERN float  MUZZLE_CONE_ANGLE;
EXTERN unsigned short  MakeId(char const *);
EXTERN unsigned int  MakeLocationID(unsigned int,char const *);
EXTERN struct ISpatialPartition *  NewSpatial(char const *);
EXTERN int  NumHardpoints(long,bool);
EXTERN float  PLAYER_ATTACHED_EQUIP_HIT_PTS_SCALE;
EXTERN float  PLAYER_COLLISION_GROUP_HIT_PTS_SCALE;
EXTERN int  PackMissionLogData(int,struct FmtStr const *,unsigned char *,int);
EXTERN struct _GUID *  ParseGUID(char const *,struct _GUID *);
EXTERN double  ParseNumber(char const *);
EXTERN void  PetalDB_destroy(void);
EXTERN class PetalInterfaceDatabase const *  PetalDB_get(void);
EXTERN void  PetalDB_load(char const *);
EXTERN bool  PlayerTrailAvailable;
EXTERN struct Rect   RECT_to_Rect(struct tagRECT const &);
EXTERN class Vector   RandomVector(float);
EXTERN class Vector   random_inside_box(float,float,float);
EXTERN class Vector   random_inside_cylinder(float,float);
EXTERN class Vector   random_inside_ellipsoid(float,float,float);
EXTERN class Vector   random_inside_ring(float,float,float);
EXTERN class Vector   random_inside_sphere(float);
EXTERN class Vector   random_on_unit_sphere(void);
EXTERN class Vector   random_sphere_constrained(class Vector const &,float);
EXTERN class Vector   random_sphere_constrained_2(class Vector const &,float,float);
EXTERN bool  ReadConstants(char const *);
EXTERN struct tagRECT   Rect_to_RECT(struct Rect const &);
EXTERN struct ViewRect   Rect_to_ViewRect(struct Rect const &);
EXTERN void  RefreshLoadingProgress(void);
EXTERN void  RegisterLoadingScreen(class ILoadingScreen *);
EXTERN void  ReinitializeRichTextFonts(void);
EXTERN class Matrix   RotateMatrix(class Vector const &);
//@@@TODO EXTERN unsigned int const  SMM_CHANGE_STATE;
//@@@TODO EXTERN unsigned int const  SMM_TIMEOUT;
EXTERN struct ID_String  SND_CARGO_JETTISONED;
//@@@TODO EXTERN unsigned short const  SUBOBJ_ID_NONE;
//@@@TODO EXTERN unsigned short const  SUBOBJ_ID_POWER;
//@@@TODO EXTERN unsigned short const  SUBOBJ_ID_ROOT;
EXTERN unsigned long  SafeWaitForSingleObject(void *,unsigned long);
EXTERN void  SetIsMPServer(bool);
EXTERN void  SetMultiPlayer(bool);
EXTERN void  SetStandardFont(int,struct TextRenderContext::FontDesc const &);
EXTERN void  ShutdownRichText(void);
EXTERN bool  SinglePlayer(void);
EXTERN struct ID_String  SpaceflightLocationID;
EXTERN bool  SphereCull(struct Geometry::Sphere const &,struct Universe::IZone const *);
EXTERN char *  StringAlloc(char const *,bool);
EXTERN char const *  StringIndex(char const *,unsigned int);
EXTERN void  StringShutdown(void);
EXTERN unsigned long  ThornGetRenderType(struct ThornEntity const *,char const *);
EXTERN bool  ThornGetUserFloat(struct IScriptEngine *,int,char const *,float *);
EXTERN bool  ThornGetUserInt(struct IScriptEngine *,int,char const *,int *);
EXTERN char const *  ThornGetUserString(struct IScriptEngine *,int,char const *);
EXTERN void  ThornScriptDestroy(struct IScriptEngine * *);
EXTERN class Csys   ThornScriptGetCsys(struct IScriptEngine *,char const *);
EXTERN struct IScriptEngine *  ThornScriptLoad(char const *);
EXTERN void  ToggleIceCap(bool);
EXTERN double  ValueNum(char const *,unsigned int);
EXTERN struct Rect   ViewRect_to_Rect(struct ViewRect const &);
EXTERN float  WALLA_MAX_DIST;
EXTERN float  WALLA_MAX_DIST_ATTEN;
EXTERN int  WALLA_PRIORITY_CUTOFF;
EXTERN float  WALLA_START_ATTEN;
EXTERN void  WaitForClientRunPermission(void);
EXTERN void  WaitForServerRunPermission(void);
EXTERN void  WideToHex(unsigned short const *,char *);


EXTERN int  add_good_item(unsigned int,int,float,float,bool,struct GoodDescList *);
EXTERN bool  arch_is_combinable(unsigned int);
EXTERN unsigned short const *  filetime_to_wstring(struct _FILETIME const &);
//@@@ EXTERN struct GoodDesc *  find_good_item(struct GoodDescList *,unsigned int,class MetaNode<struct GoodDesc> * *);
EXTERN long  get_projected_bounding_box(struct ICamera *,class Vector const &,float,struct ViewRect *,float &);
EXTERN long  get_projected_bounding_sphere(struct ICamera *,class Vector const &,float,float &,float &,float &,float &);
EXTERN int  lex_compare(class RenderDisplayList const &,class RenderDisplayList const &,bool);
EXTERN char const *  malloc_strcpy(char * *,char const *);
EXTERN void  malloc_strfree(char * *);
EXTERN unsigned short const *  malloc_wstrcpy(unsigned short * *,unsigned short const *);
EXTERN void  malloc_wstrfree(unsigned short * *);
EXTERN struct Rect   rect_intersect(struct Rect const &,struct Rect const &);
EXTERN struct Rect   rect_union(struct Rect const &,struct Rect const &);
EXTERN int  remove_good_item(unsigned int,int,struct GoodDescList *);
EXTERN char *  safe_strcat(char *,int,char const *);
EXTERN char *  safe_strcpy(char *,int,char const *);
EXTERN unsigned short *  safe_wcscpy(unsigned short *,int,unsigned short const *);
EXTERN unsigned long  select_option_from_string(char *,struct option_spec const * const,int,char const *);
EXTERN bool  strequal(char const *,char const *);

#endif //_FLCORECOMMON_H_
