enum eTrackDirection {
	eDIRECTION_FORWARD = 0,
	eDIRECTION_BACKWARD = 1,
	NUM_TRACK_DIRECTIONS = 2,
};

enum eTrafficDensity {
	eTRAFFICDENSITY_OFF = 0,
	eTRAFFICDENSITY_LOW = 1,
	eTRAFFICDENSITY_MEDIUM = 2,
	eTRAFFICDENSITY_HIGH = 3,
	NUM_TRAFFIC_DENSITIES = 4,
};

enum eHandlingMode {
	HANDLING_MODE_CLASSIC = 0,
	HANDLING_MODE_EXTREME = 1,
};

enum eOpponentStrength {
	eOPPONENTSTRENGTH_LOW = 0,
	eOPPONENTSTRENGTH_MEDIUM = 1,
	eOPPONENTSTRENGTH_HIGH = 2,
	NUM_OPPONENT_STRENGTHS = 3,
};

namespace GRace {
	enum Context {
		kRaceContext_QuickRace = 0x0,
		kRaceContext_TimeTrial = 0x1,
		kRaceContext_Online = 0x2,
		kRaceContext_Career = 0x3,
		kRaceContext_Count = 0x4,
	};
}

class Timer {
public:
	int PackedTime;
};

class RaceParameters {
public:
	int TrackNumber;
	eTrackDirection TrackDirection;
	eTrafficDensity TrafficDensity;
	float TrafficOncoming;
	bool AIDemoMode;
	bool ReplayDemoMode;
	GRace::Context RaceType;
	int Point2Point;
	float RollingStartSpeed;
	int NumLapsInRace;
	int NumPlayerCars;
	int NumAICars;
	int NumOnlinePlayerCars;
	int NumOnlineAICars;
	char PlayerStartPosition[2];
	bool DamageEnabled;
	eHandlingMode HandlingMode;
	int FinishLineNumber;
	bool bDragRaceFlag;
	bool bShortRaceFlag;
	bool bOnlineRace;
	bool bCarShowFlag;
	bool bGamebreakerOn;
	bool bIsPracticeMode;
	bool bIsSlotcarRace;
	int nMaxCops;
	eOpponentStrength CopStrength;
	float DriftOpponentScoreMultiplier;
	eOpponentStrength OpponentStrength;
	int Boost;
	float BoostScale[4];
	int PlayerDriverNumber[2];
	int NumDriverInfo;
	Timer TimeTrialTime;
	bool bCareerEventRace;

	static inline auto InitWithDefaults = (void(__thiscall*)(RaceParameters*))0x74EEE0;
};
static_assert(sizeof(RaceParameters) == 0x80);

auto& TheRaceParameters = *(RaceParameters*)0xA835D8;