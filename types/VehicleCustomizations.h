enum KIT_TYPE {
	KIT_TYPE_BASE = 0,
	KIT_TYPE_STOCK = 1,
	KIT_TYPE_AUTOSCULPT = 2,
	KIT_TYPE_WIDEBODY = 3,
	NUM_KIT_TYPE = 4,
};

struct PackedVinylColor {
	int16_t huePart;
	uint8_t saturation;
	uint8_t brightness;
};

class PackedVinylLayer {
public:
	int16_t vinylPart;
	VinylSystem::VinylTransformPacked transform;
	PackedVinylColor colors[4];
};

class PackedDecalLayer {
public:
	int16_t decalPart;
	VinylSystem::VinylTransformPacked transform;
	PackedVinylColor color;
};

class RideInfo;
class VehicleCustomizations {
public:
	class InstalledPart {
	public:
		unsigned int part_key;
		int kit_num;
	};

	int16_t GUID[5];
	unsigned int creatorId;
	char creatorName[32];
	unsigned int shareNumber;
	int16_t InstalledParts[165];
	uint8_t customPaintsValid[12];
	CarPaintPartRecordPacked customPaints[12];
	uint8_t partBaseMaterials[12];
	BluePrintType bluePrintType;
	KIT_TYPE kitType;
	unsigned int kitNum;
	float RideHeight;
	PackedVinylLayer VinylLayers[20];
	int VinylMirrorBits;
	int NumVinylLayers;
	PackedDecalLayer DecalLayers[20];
	int DecalMirrorBits;
	int NumDecalLayers;
	int LiveryID;
	uint8_t MorphValues[41][11];
	float PhysicsTuning[32];
	int Type;
};
static_assert(sizeof(VehicleCustomizations) == 0x7B4);