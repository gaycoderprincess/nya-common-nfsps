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
#include "types/Attrib.h"
#include "types/Physics.h"
#include "types/VinylSystem.h"
#include "types/PresetSkin.h"
#include "types/RideInfo.h"
#include "types/FEPlayerCarDB.h"
#include "types/FeGarageMain.h"
#include "types/UserProfile.h"
#include "types/GameFlowManager.h"

#include "nfspshooks.h"