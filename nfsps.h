#include <d3d9.h>

enum CarRenderUsage : uint32_t {
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

enum BLUEPRINT_NUMBER : uint32_t {
	BLUEPRINT1,
	BLUEPRINT2,
	BLUEPRINT3,
	BLUEPRINT_MAX,
};

#include "types/bNode.h"
#include "types/UMath.h"
#include "types/Attrib.h"
#include "types/Physics.h"
#include "types/VinylSystem.h"
#include "types/PresetSkin.h"
#include "types/RideInfo.h"
#include "types/FEPlayerCarDB.h"
#include "types/FeGarageMain.h"
#include "types/UserProfile.h"
#include "types/GameFlowManager.h"
#include "types/RaceParameters.h"
#include "types/TrackInfo.h"

class RaceStarter {
public:
	static inline auto StartSkipFERace = (void(*)())0x74EFA0;
};

auto& SkipFE = *(bool*)0xBFBC08;
auto& SkipFEForever = *(bool*)0xBFBC0C;
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

auto& SkipNISs = *(bool*)0xBFBC28;

#include "nfspshooks.h"