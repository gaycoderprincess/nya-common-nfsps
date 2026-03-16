enum CarUsageType {
	CAR_USAGE_TYPE_RACING = 0,
	CAR_USAGE_TYPE_COP = 1,
	CAR_USAGE_TYPE_TRAFFIC = 2,
	CAR_USAGE_TYPE_WHEELS = 3,
	CAR_USAGE_TYPE_UNIVERSAL = 4,
};

class CarTypeInfo {
public:
	char CarTypeName[16];
	char BaseModelName[16];
	char GeometryFilename[32];
	char ManufacturerName[16];
	unsigned int CarTypeNameHash;
	float HeadlightFOV;
	char padHighPerformance;
	char NumAvailableSkinNumbers;
	char WhatGame;
	char ConvertableFlag;
	char WheelOuterRadius;
	char WheelInnerRadiusMin;
	char WheelInnerRadiusMax;
	char pad0;
	bVector3 HeadlightPosition;
	bVector3 DriverRenderingOffset;
	bVector3 InCarSteeringWheelRenderingOffset;
	int Type;
	CarUsageType UsageType;
	unsigned int CarMemTypeHash;
	char MaxInstances[5];
	char WantToKeepLoaded[5];
	char pad4[2];
	float MinTimeBetweenUses[5];
	char AvailableSkinNumbers[10];
	char DefaultSkinNumber;
	char Skinnable;
	int Padding;
	int DefaultBasePaint;
};
static inline auto GetCarTypeInfoFromHash = (CarTypeInfo*(*)(uint32_t))0x754E00;