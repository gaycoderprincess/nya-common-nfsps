class IAttachmentSystem;

class DBCarPart {
	bool isValid;
	uint8_t CarTypeNameHashIndex;
	uint16_t AttributeTableOffset;
	uint32_t partAttributes;
	uint16_t kitNum;
	uint16_t materialFlags;
	uint8_t padding[0x4];
};
static_assert(sizeof(DBCarPart) == 0x10);

class CarPaintPartRecord {
	uint32_t paint_group;
	uint32_t baseHue;
	float saturation;
	float variance;
};
static_assert(sizeof(CarPaintPartRecord) == 0x10);

class CarPaintPart {
	uint32_t resultLightMaterial;
	CarPaintPartRecord paintRecord;
	bool valid;
};
static_assert(sizeof(CarPaintPart) == 0x18);

class VinylColorPartInfo {
public:
	DBCarPart hue;
	uint8_t saturation;
	uint8_t brightness;
};
static_assert(sizeof(VinylColorPartInfo) == 0x14);

class VinylLayerPartInfo {
	DBCarPart vinyl;
	VinylColorPartInfo colors[4];
	VinylSystem::VinylTransformPacked transform;
};
static_assert(sizeof(VinylLayerPartInfo) == 0x68);

class DecalLayerPartInfo {
	DBCarPart decal;
	VinylSystem::VinylTransformPacked transform;
	VinylColorPartInfo color;
};
static_assert(sizeof(DecalLayerPartInfo) == 0x2C);

class AutoSculptRegion {
public:
	float mSculptZoneBlendAmount[11];
	bool mModified;
};
static_assert(sizeof(AutoSculptRegion) == 0x30);

class AutoSculpt {
public:
	bool mIsInitialized; // +0
	AutoSculptRegion mRegionList[41]; // +4
};
static_assert(sizeof(AutoSculpt) == 0x7B4);

class RideInfo {
public:
	uint32_t Type; // +0
	uint8_t InstanceIndex; // +4
	uint8_t Initialized; // +5
	uint8_t ForceLowRez; // +6
	uint8_t loadedFE; // +7
	uint32_t mMinLodLevel; // +8
	uint32_t mMaxLodLevel; // +C
	uint32_t mMinFELodLevel; // +10
	uint32_t mMaxFELodLevel; // +14
	uint32_t mMaxLicenseLodLevel; // +18
	uint32_t mMinTrafficDiffuseLodLevel; // +1C
	uint32_t mMinShadowLodLevel; // +20
	uint32_t mMaxShadowLodLevel; // +24
	uint32_t mMaxExhaustLodLevel; // +28
	uint32_t mMaxTireLodLevel; // +2C
	uint32_t mMaxBrakeLodLevel; // +30
	uint32_t mMaxSpoilerLodLevel; // +34
	uint32_t mMaxRoofScoopLodLevel; // +38
	uint32_t mMaxSeatLodLevel; // +3C
	uint32_t mMinReflectionLodLevel; // +40
	uint32_t mMaxInteriorLodLevel; // +44
	uint32_t mMinInteriorLodLevel; // +48
	uint32_t mCompositeSkinHash; // +4C
	uint32_t mCompositeWheelHash[2]; // +50
	DBCarPart mPartsTable[165]; // +58
	bool mPartsEnabled[165]; // +AA8
	int32_t PreviewPart; // +B50
	bool autosculptLoad; // +B54
	CarPaintPart mCustomPaints[12]; // +B58
	bool mCustomPaintValid[12]; // +C78
	void* partLightMaterials[19]; // +C84
	uint32_t mMyCarLoaderHandle; // +CD0
	uint32_t mMyCarRenderUsage; // +CD4
	uint8_t mSpecialLODBehavior; // +CD8
	float mRideHeight; // +CDC
	VinylLayerPartInfo mVinylLayers[20]; // +CE0
	DecalLayerPartInfo mDecalLayers[20]; // +1500
	uint32_t mVinylMirrorBits; // +1870
	uint64_t mDecalMirrorBits; // +1878
	uint16_t mNumVinylLayers; // +1880
	uint16_t mNumDecalLayers; // +1882
	uint16_t mVinylEditLayer; // +1884
	uint16_t mDecalEditLayer; // +1886
	bool mEditingVinyl; // +1888
	bool mEditingDecal; // +1889
	uint16_t mFastVinyl; // +188A
	AutoSculpt mAutoSculpt; // +188C
	void* mAttachmentSystem; // +2040
	bool mNeedCreateSkins; // +2044
	uint32_t kitTypeInstalled; // +2048
	uint32_t kitNumInstalled; // +204C
	uint32_t bluePrintType; // +2050
	Physics::Upgrades::Tuning PhysicsTuning[32]; // +2054

	RideInfo() {
		((int(__thiscall*)(RideInfo*))(0x78E2B0))(this);
	}
	static inline auto Init = (void(__thiscall*)(RideInfo*, int type, CarRenderUsage usage, int has_dash, int can_be_vertex_damaged, int force_low_rez, IAttachmentSystem *attachmentSystem))0x789E10;
	static inline auto SetStockParts = (void(__thiscall*)(RideInfo*))0x78A2B0;
	static inline auto FillWithPreset = (void(__thiscall*)(RideInfo*, PresetSkin* preset))0x785410;
};
static_assert(sizeof(RideInfo) == 0x21D8);