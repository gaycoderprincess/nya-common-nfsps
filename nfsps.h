#include <d3d9.h>

struct UCrc32 {
	uint32_t mCRC;
};

enum CarRenderUsage {
	CarRenderUsage_Player,
	CarRenderUsage_RemotePlayer,
	CarRenderUsage_AIRacer,
	CarRenderUsage_AICop,
	CarRenderUsage_AITraffic,
	CarRenderUsage_AIHeli,
	carRenderUsage_NISCar,
	CarRenderUsage_Ghost,
	CarRenderUsage_Invalid,
};

enum BLUEPRINT_NUMBER {
	BLUEPRINT1,
	BLUEPRINT2,
	BLUEPRINT3,
	BLUEPRINT_MAX,
};

enum BluePrintType {
	BLUEPRINT_GRIP = 0,
	BLUEPRINT_DRIFT = 1,
	BLUEPRINT_DRAG = 2,
	BLUEPRINT_SPEED_CHALLENGE = 3,
	BLUEPRINT_FIRST = 0,
	BLUEPRINT_LAST = 3,
	BLUEPRINT_NUM = 4,
};

typedef uint32_t HSIMABLE__;
typedef uint32_t HCAUSE__;
typedef uint32_t HSIMPROFILE__;
typedef uint32_t HCOLPRIM__;
typedef HSIMABLE__* HSIMABLE;
typedef HCAUSE__* HCAUSE;
typedef HSIMPROFILE__* HSIMPROFILE;
typedef HCOLPRIM__* HCOLPRIM;

namespace Hermes {
	typedef uint32_t _h_HHANDLER__;
}

#include "types/eastl.h"
#include "types/bNode.h"
#include "types/UCOM.h"
#include "types/ListableSet.h"
#include "types/UMath.h"
#include "types/SimSystem.h"
#include "types/cFEng.h"
#include "types/Attrib.h"
#include "types/GRace.h"
#include "types/AttribGen.h"
#include "types/Physics.h"
#include "types/VinylSystem.h"
#include "types/PresetSkin.h"
#include "types/RideInfo.h"
#include "types/VehicleCustomizations.h"
#include "types/FEPlayerCarDB.h"
#include "types/FeGarageMain.h"
#include "types/PlayerSettings.h"
#include "types/UserProfile.h"
#include "types/GameFlowManager.h"
#include "types/TrackInfo.h"
#include "types/IAttachable.h"
#include "types/ISimable.h"
#include "types/IVehicle.h"
#include "types/IPlayer.h"
#include "types/ITransmission.h"
#include "types/ITiptronic.h"
#include "types/IInductable.h"
#include "types/IEngine.h"
#include "types/IRaceEngine.h"
#include "types/IEngineDamage.h"
#include "types/ISteeringWheel.h"
#include "types/IChassis.h"
#include "types/IInput.h"
#include "types/IRigidBody.h"
#include "types/ICollisionBody.h"
#include "types/IRBVehicle.h"
#include "types/ISpikeable.h"
#include "types/IVehicleCache.h"
#include "types/IHumanAI.h"
#include "types/ISelectionSet.h"
#include "types/INIS.h"
#include "types/IDamageable.h"
#include "types/IDamageableVehicle.h"
#include "types/DriftScoring.h"
#include "types/GTrigger.h"
#include "types/GRaceParameters.h"
#include "types/GRaceDatabase.h"
#include "types/GRaceStatus.h"
#include "types/RaceParameters.h"
#include "types/GProStreetGame.h"
#include "types/PVehicle.h"
#include "types/Camera.h"
#include "types/eView.h"
#include "types/Event.h"
#include "types/VehicleBehavior.h"
#include "types/FastMem.h"
#include "types/WWorldPos.h"

class SimSurface : public Attrib::Gen::simsurface {
public:
	SimSurface() {}
};

class TableBase {
public:
	int NumEntries;
	float MinArg;
	float MaxArg;
	float IndexMultiplier;

	TableBase() {}

	TableBase(int num, float min, float max) {
		NumEntries = num;
		MinArg = min;
		MaxArg = max;
		IndexMultiplier = (NumEntries - 1) / (MaxArg - MinArg);
	}
};

class Table : public TableBase {
public:
	const float* pTable;

	Table(const float *table, int num, float min, float max) : TableBase(num, min, max), pTable(table) {}

	Table(const float* table, int numEntries, float minArg, float maxArg, float indexMultiplier) {
		pTable = table;
		NumEntries = numEntries;
		MinArg = minArg;
		MaxArg = maxArg;
		IndexMultiplier = indexMultiplier;
	}

	float GetValue(float input); // todo does this exist in ps?
};

class DALPauseStates {
public:
	static inline auto& mPauseRequest = *(uint32_t*)0xAB0EDC;
};

class RaceStarter {
public:
	static inline auto StartSkipFERace = (void(*)())0x74EFA0;
};

auto& SkipFE = *(bool*)0xBFBC08;
auto& SkipFEForever = *(bool*)0xBFBC0C;
auto& SkipFEPlayerBluePrintType = *(int*)0xBFBC10;
auto& SkipFENumAICars = *(int*)0xBFBC18;
auto& SkipFEBootFlow = *(bool*)0xBFBC41;
auto& SkipFETrackNumber = *(int*)0xA9D974;
auto& SkipFERaceID = *(const char**)0xA9D978;
auto& SkipFEPlayerCar = *(const char**)0xA9D97C;
auto& SkipFEAICars = *(const char**)0xA9D990;
auto& SkipFEPlayerPerformance = *(float*)0xA9D994;
auto& SkipFEForceHubSelectionSet = *(const char**)0xA9D998;
auto& SkipFEForceRaceSelectionSet = *(const char**)0xA9D99C;
auto& SkipFEForceNIS = *(const char**)0xA9D9A0;
auto& SkipFENumLaps = *(int*)0xA9D9B0;
auto& SkipFEDifficulty = *(int*)0xA9D9B8;
auto& SkipFETractionControlLevel = *(int*)0xA9D9CC;
auto& SkipFEStabilityControlLevel = *(int*)0xA9D9D0;
auto& SkipFEAntiLockBrakesLevel = *(int*)0xA9D9D4;
auto& SkipFEDriftAssistLevel = *(int*)0xA9D9D8;
auto& SkipFERacelineAssistLevel = *(int*)0xA9D9DC;
auto& SkipFEBrakingAssistLevel = *(int*)0xA9D9E0;

auto& Tweak_TotalledDamage = *(float*)0xA5C5B4;

auto bInitTicker = (void(*)(float))0x430F30;

auto LZDecompress = (uint32_t(*)(uint8_t* pSrc, uint8_t* pDst))0x6CFDF0;
auto HUFF_encode = (uint32_t(*)(void *compresseddata, const void *source, uint32_t sourcesize))0x6CFBB0;
uint32_t HUFFCompress(uint8_t *pSrc, uint32_t Size, uint8_t *pDest) {
	auto dest = (uintptr_t)pDest;
	*(uint32_t*)(dest) = 0x46465548;
	*(uint8_t*)(dest + 4) = 1;
	*(uint8_t*)(dest + 5) = 16;
	*(uint16_t*)(dest + 6) = 0;
	*(uint32_t*)(dest + 8) = Size;
	auto size = HUFF_encode((void*)(dest + 0x10), pSrc, Size);
	*(uint32_t*)(dest + 0xC) = size;
	return size + 16;
}

auto& SkipNISs = *(bool*)0xBFBC28;

auto& GameWindow = *(HWND*)0xAC6ED8;
auto& GameD3DDevice = *(IDirect3DDevice9***)0xAC6ED4;

class CameraMover;

#include "nfspshooks.h"