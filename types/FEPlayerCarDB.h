class VehicleCustomizations {
public:
	uint8_t _0[0x7B4];
};

class FECarRecord {
public:
	uint32_t Handle; // +0
	uint32_t FEKey; // +4
	uint32_t VehicleKey; // +8
	uint32_t PresetKey; // +C
	uint32_t FilterBits; // +10
	int8_t Customization; // +14
	int8_t CareerHandle; // +15
	bool IsPresetSkin; // +16
	uint8_t Padd; // +17

	static inline auto GetDebugName = (const char*(__thiscall*)(FECarRecord*))0x548D60;
	static inline auto GetVCRecord = (bool(__thiscall*)(FECarRecord*, VehicleCustomizations* rec, BLUEPRINT_NUMBER bpNum))0x5581E0;
};
static_assert(sizeof(FECarRecord) == 0x18);

struct FEKitInfo {
	uint32_t installedType[3];
	uint32_t installedKitNum[3];
	uint32_t inventory[4];
};
static_assert(sizeof(FEKitInfo) == 0x28);

struct FEBlueprintStats {
	uint32_t NumRaces;
	uint32_t NumWins;
	uint32_t NumTotaled;
	float Content[4];
};
static_assert(sizeof(FEBlueprintStats) == 0x1C);

struct FEPaintSV {
	uint8_t s;
	uint8_t v;
};
static_assert(sizeof(FEPaintSV) == 0x2);

class FECustomizationRecord {
public:
	int16_t FirstCarPartRecordIndex; // +0
	int16_t FirstVinylRecordIndex; // +2
	VehicleCustomizations mBluePrint[3]; // +4
	FEKitInfo mBodykitInfo; // +1720
	FEBlueprintStats mBlueprintStats[3]; // +1748
	Physics::Tunings Tunings[3]; // +179C
	uint32_t ActiveTuning; // +17F0
	uint32_t Preset; // +17F4
	uint8_t Handle; // +17F8
	uint32_t Type; // +17FC
	FEPaintSV mPaint[36]; // +1800
	float mPerformanceDetuning[3]; // +1848
	bool mFastVinyl; // +1854
	bool mBlueprintIsLocked[3]; // +1855
	uint32_t mActiveBlueprint; // +1858
	bool mBlueprintUsed[3]; // +185C
	uint32_t mOnlineType[3]; // +186C
	uint8_t mBlueprintTier[3]; // +186F

	static inline auto WriteRecordIntoRide = (FECarRecord*(__thiscall*)(FECustomizationRecord*, BLUEPRINT_NUMBER num, RideInfo* ride))0x533D50;
};
static_assert(sizeof(FECustomizationRecord) == 0x1870);

struct FEImpoundData {
	uint8_t mMaxBusted;
	uint8_t mTimesBusted;
	uint16_t Pad1;
};
static_assert(sizeof(FEImpoundData) == 0x4);

struct FEInfractionsData {
	uint16_t Speeding;
	uint16_t Racing;
	uint16_t Reckless;
	uint16_t Assault;
	uint16_t HitAndRun;
	uint16_t Damage;
	uint16_t Resist;
	uint16_t OffRoad;
};
static_assert(sizeof(FEInfractionsData) == 0x10);

class FECareerRecord {
public:
	uint16_t Handle; // +0
	FEImpoundData TheImpoundData; // +2
	float VehicleHeat; // +8
	bool HasNeverBeenInHub; // +C
	uint32_t Bounty; // +10
	uint16_t NumEvadedPursuits; // +14
	uint16_t NumBustedPursuits; // +16
	float DamageLevel; // +18
	float DamageCost; // +1C
	FEInfractionsData UnservedInfractions; // +20
	FEInfractionsData ServedInfractions; // +30
};
static_assert(sizeof(FECareerRecord) == 0x40);

class FEPlayerCarDB {
public:
	FECarRecord CarTable[410]; // +0
	FECustomizationRecord Customizations[80]; // +2670
	FECareerRecord CareerRecords[80]; // +7C970
	uint8_t _CarParts[0x128E0]; // +7DD70 placeholder
	uint32_t SoldHistoryBounty; // +90650
	uint16_t SoldHistoryNumEvadedPursuits; // +90654
	uint16_t SoldHistoryNumBustedPursuits; // +90656
	FEInfractionsData SoldHistoryUnservedInfractions; // +90658
	FEInfractionsData SoldHistoryServedInfractions; // +90668
	uint32_t LastAwardedKingCarHistoryCarHandle; // +90678
	uint32_t LastAwardedKingCarHistoryCarMode; // +9067C
	bool mInitializingCarStable; // +90680

	static inline auto GetCarRecordByHandle = (FECarRecord*(__thiscall*)(FEPlayerCarDB*, uint32_t handle))0x5332F0;
	static inline auto GetCustomizationRecordByHandle = (FECustomizationRecord*(__thiscall*)(FEPlayerCarDB*, int8_t handle))0x533410;
	static inline auto GetCareerRecordByHandle = (FECareerRecord*(__thiscall*)(FEPlayerCarDB*, int8_t handle))0x533430;

	static inline auto CreateNewCustomCar = (FECarRecord*(__thiscall*)(FEPlayerCarDB*, uint32_t fromCar))0x5604D0;
	static inline auto CreateNewPresetCar = (FECarRecord*(__thiscall*)(FEPlayerCarDB*, uint32_t nameHash))0x557AF0;
	static inline auto BuildRideForPlayer = (void(__thiscall*)(FEPlayerCarDB*, uint32_t car, int player, RideInfo* ride, BLUEPRINT_NUMBER num))0x558090;
};
static_assert(sizeof(FEPlayerCarDB) == 0x90684);