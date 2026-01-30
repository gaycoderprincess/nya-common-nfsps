enum eLocationName {
	UPPER_CLASS = 0,
	CITY_CORE = 1,
	SUBURBAN_HILLS = 2,
	INDUSTRIAL_PARK = 3,
	AIRPORT = 4,
	MODE_SPECIFIC = 5,
};

enum eDriftType  {
	VS_AI = 0,
	DOWNHILL = 1,
	TEAM = 2,
};

enum eTrackDifficulty {
	TRACK_DIFFICULTY_EASY = 0,
	TRACK_DIFFICULTY_MEDIUM = 1,
	TRACK_DIFFICULTY_HARD = 2,
};

class TrackInfo {
public:
	char Name[64];
	char TrackDirectory[64];
	char RegionName[32];
	char RegionDirectory[64];
	int LocationNumber;
	char LocationDirectory[32];
	eLocationName LocationName;
	eDriftType DriftType;
	char IsValid;
	char Point2Point;
	char ReverseVersionExists;
	char Unused;
	char IsPerformanceTuning;
	int16_t TrackNumber;
	int16_t SameAsTrackNumber;
	unsigned int SunInfoNameHash;
	unsigned int UsageFlags;
	unsigned int TrackLength;
	float TimeToBeatForwards_ms;
	float TimeToBeatReverse_ms;
	int ScoreToBeatForwards_DriftOnly;
	int ScoreToBeatReverse_DriftOnly;
	bVector2 TrackMapCalibrationUpperLeft;
	float TrackMapCalibrationMapWidthMetres;
	uint16_t TrackMapCalibrationRotation;
	uint16_t TrackMapStartLineAngle;
	uint16_t TrackMapFinishLineAngle;
	float TrackMapZoomFactor;
	eTrackDifficulty ForwardDifficulty;
	eTrackDifficulty ReverseDifficulty;
	int16_t NumSecondsBeforeShortcutsAllowed;
	int16_t nDriftSecondsMin;
	int16_t nDriftSecondsMax;
	int16_t pad2[1];
	char MaxTrafficCars[4][2];
	char TrafficAllowedNearStartLine[2];
	char CarRaceStartConfig;
	char padbyte;
	float TrafficMinInitialDistanceFromStartLine[2];
	float TrafficMinInitialDistanceBetweenCars[2];
	float TrafficOncomingFraction[4];
	bVector2 TrackMapZoomTopLeft;
	float TrackMapZoomWidth;
	char TrackMapStartZoomed;

	static inline auto& TrackInfoTable = *(TrackInfo**)0xAE3340;
	static inline auto& NumTrackInfo = *(int*)0xAE3344;
	static inline auto& LoadedTrackInfo = *(TrackInfo**)0xAE334C;

	static inline auto GetTrackInfo = (TrackInfo*(*)(int track_number))0x7434F0;
};
static_assert(sizeof(TrackInfo) == 0x198);