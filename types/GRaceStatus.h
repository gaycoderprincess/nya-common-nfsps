class WorldModel;
class GIOpponent;
class GCharacter;
class GElapsedCallback;

class GTimer {
public:
	float mStartTime;
	float mTotalTime;
	bool mRunning;

	float GetTime() {
		if (mRunning) {
			return (Sim::GetTime() - mStartTime) + mTotalTime;
		}
		else {
			return mTotalTime;
		}
	}
};
static_assert(sizeof(GTimer) == 0xC);

class GCallbackTimer {
public:
	float mInterval;
	bool mRunning;
	float mElapsed;
	unsigned int mNameHash;
	char mName[20];
	GElapsedCallback* mCallback;
};
static_assert(sizeof(GCallbackTimer) == 0x28);

class GElapsedCallback {
public:
	virtual void Elapsed(GCallbackTimer* timer);
};
static_assert(sizeof(GElapsedCallback) == 0x4);

class IStateRecordable {
public:
	virtual void Reset();
	virtual void Rewind();
	virtual void Restart();
	virtual void Clean();
	virtual void Record_Frame(float dT);
	virtual void Playback_Frame(float dT);
	virtual void PrepareForRecord();
	virtual void PrepareForPlayback();
	virtual void CreatePlayBackAssets();
};
static_assert(sizeof(IStateRecordable) == 0x4);

class Timeline {
public:
	enum TimelineMode {
		STOPPED = 0,
		PLAYING = 1,
		RECORDING = 2,
	};

	IStateRecordable* mRecordableObject;
	TimelineMode mTimelineMode;
	bool mIsPaused;

	virtual void _vf0();
};
static_assert(sizeof(Timeline) == 0x10);

class GIOpponent : public UCOM::IUnknown {
public:
	enum Flags {
		kFlag_LowResolution = 0x2,
	};

	enum OpponentStatus {
		kStatus_Free = 0,
		kStatus_Joining = 1,
		kStatus_Hub = 2,
		kStatus_Racing = 3,
		kStatus_Disconnected = 4,
		kStatus_Clean = 5,
	};

	enum DamageSeverity {
		kDamageSeverity_None = 0,
		kDamageSeverity_Cosmetic = 1,
		kDamageSeverity_1 = 2,
		kDamageSeverity_2 = 3,
		kDamageSeverity_Totalled = 4,
	};

	enum PerformanceLevel {
		kPerformanceLevel_Min = 0,
		kPerformanceLevel_Current = 1,
		kPerformanceLevel_Max = 2,
	};

	virtual unsigned int Id();
	virtual void Prepare(GIOpponent::Flags);
	virtual void Cleanup();
	virtual void Disconnect();
	virtual void Destroy();
	virtual const char *GetOpponentName();
	virtual GIOpponent::OpponentStatus GetStatus();
	virtual void EnterHub();
	virtual void EnterRace();
	virtual ISimable *GetSimable();
	virtual unsigned int GetVehicleKey();
	virtual float GetPerformanceLevel(GIOpponent::PerformanceLevel);
	virtual void StoreDamageData();
	virtual void RestoreDamage();
	virtual float GetDamageLevel();
	virtual void SetDamageLevel(float);
	virtual float GetInitialDamageLevel();
	virtual void SetInitialDamageLevel(float);
	virtual void RepairDamage();
	virtual void RepairCareerDamage();
	virtual void RepairEngineDamage();
	virtual float GetDynamicTargetTime();
	virtual void SetDynamicTargetTime(float);
	virtual GIOpponent::DamageSeverity GetDamageSeverity();
	virtual int GetGridNumber();
	virtual void SetGridNumber(int);
	virtual bool IsHidden();
	virtual void SetHidden(bool);
	virtual void RequestDamageStoreAndRepair();
	virtual void RequestDamageRepair();
	virtual int GetIndex();
};

class GOpponent : public GIOpponent, UCOM::Object {
public:
	HSIMABLE__* mHSimable;
	GIOpponent::OpponentStatus mStatus;
	char mOpponentName[32];
	unsigned int mId;
	int mIndex;
	float mDamageLevel;
	float mInitialDamageLevel;
	float mDynamicTargetTime;
	int mGridNum;
	bool mHidden;
	void* mDamageRestoreData;
	unsigned int mDamageRestoreBufferSize;
	int mDamageRequestPending;

	virtual unsigned int Id();
	virtual void Prepare(GIOpponent::Flags);
	virtual void Cleanup();
	virtual void Disconnect();
	virtual void Destroy();
	virtual const char* GetOpponentName();
	virtual GIOpponent::OpponentStatus GetStatus();
	virtual void EnterHub();
	virtual void EnterRace();
	virtual ISimable* GetSimable();
	virtual unsigned int GetVehicleKey();
	virtual float GetPerformanceLevel(GIOpponent::PerformanceLevel);
	virtual void StoreDamageData();
	virtual void RestoreDamage();
	virtual float GetDamageLevel();
	virtual void SetDamageLevel(float);
	virtual float GetInitialDamageLevel();
	virtual void SetInitialDamageLevel(float);
	virtual void RepairDamage();
	virtual void RepairCareerDamage();
	virtual void RepairEngineDamage();
	virtual float GetDynamicTargetTime();
	virtual void SetDynamicTargetTime(float);
	virtual GIOpponent::DamageSeverity GetDamageSeverity();
	virtual int GetGridNumber();
	virtual void SetGridNumber(int);
	virtual bool IsHidden();
	virtual void SetHidden(bool);
	virtual void RequestDamageStoreAndRepair();
	virtual void RequestDamageRepair();
	virtual int GetIndex();
	virtual void SetSimable(ISimable*);
};

class GRacerInfo : public GElapsedCallback {
public:
	enum State {
		kState_Initial = 1,
		kState_NIS = 2,
		kState_PreStaging = 3,
		kState_Staging = 4,
		kState_PostStaging = 5,
		kState_Handicap = 6,
		kState_Countdown = 7,
		kState_Racing = 8,
		kState_RaceOver = 9,
		kState_Spectate = 10,
		kState_Done = 11,
	};

	enum Type {
		kType_Human = 1,
		kType_Artifical = 2,
	};

	enum RecordingState {
		kRecording_Reset = 0,
		kRecording_Recording = 1,
		kRecording_Done = 2,
	};

	enum FinishReason {
		kReason_Unknown = 0x0,
		kReason_Completed = 0x2,
		kReason_CrossedFinish = 0x6,
		kReason_DidNotFinish = 0xA,
		kReason_KnockedOut = 0x1A,
		kReason_Totalled = 0x2A,
		kReason_EngineBlown = 0x4A,
		kReason_Busted = 0x8A,
		kReason_ChallengeCompleted = 0x102,
		kReason_Disconnected = 0x20A,
		kReason_FalseStart = 0x40A,
	};

	enum RacerStateFlag {
		kFlag_DisableCountdown = 0x2,
		kFlag_Crashing = 0x4,
		kFlag_CameraDetached = 0x100,
		kFlag_ControllingAI = 0x800,
		kFlag_StartedRace = 0x1000,
		kFlag_RaceInit = 0x1000,
		kFlag_ClearAll = 0x0,
	};

	enum {
		kNamesAvail = 0xA2,
		kMaxTimers = 1,
		kFinishFuncCount = 4,
	};

	class GArbitratedRacerStats {
	public:
		unsigned int mFinishReason;
		float mPointTotal;
		float mRaceTime;
		int mLapsCompleted;
		float mTopSpeed;
		float mAvgSpeed;
		float mBestLapTime;
		float mPoundsNOSUsed;
		float mBestSectorPoints;
		float mCheckpointTopSpeeds[16];
		float mRaceResult;
		float mAccumulatedCheckpointSpeeds;
		float mDragWheelieDistance;
	};

	class GLocalRacerStats {
	public:
		float mPctRaceComplete;
		float mPctLapComplete;
		float mPctRaceCompleteHighWaterMark;
		int mCheckpointsHitThisLap;
		float mTimeRemainingToBooth[16];
		float mDistToNextCheckpoint;
		float mDistanceDriven;
		float mDeltaXP;
		float mTimeFacingWrongWay;
		float mPercentTimes[100];
		bool mFinishedBackwards;
		int mSkillLevel;
		float mCurrentAirTime;
		float mLastLapTime;
		float mTimeCrossedLastCheck;
		float mTotalUpdateTime;
		float mHandicap;
		float mDriftFactor;
		bool mDominatedSectorShootout;
		int mSpeedTrapsCrossed;
		float mSpeedTrapSpeed[16];
		int mSpeedTrapPosition[16];
		float mFinishingSpeed;
		int mNumPerfectShifts;
		int mNumTrafficCarsHit;
		float mSpeedBreakerTime;
		float mZeroToSixtyTime;
		float mZeroToHundredTime;
		float mSeventyToHundredFiftyTime;
		float mSixtyFeetTime;
		float mQuarterMileTime;
		float mEighthMileTime;
		float mReactionTime;
		float mSplitTimes[4];
		int mSplitRankings[4];
		float mLongestAirTime;
		int mTollboothsCrossed;
		int mNumRaceBreakersActivated;
		unsigned int mRacerGroup;
		float mLastRollOverTime;
		int mPotentialTargetPoints;
		float mDistanceToStartLine;
		float mSectorDynamicTargetTime[4];
	};

	class GRacerStats {
	public:
		GArbitratedRacerStats arbitrated;
		GLocalRacerStats local;
	};

	State mState;
	unsigned int mFlags;
	GIOpponent* mOpponent;
	HSIMABLE__* mhSimable;
	GCharacter* mGameCharacter;
	char mName[32];
	char mGroupName[32];
	int mIndex;
	int mRanking;
	int mRankChange;
	int mAiRanking;
	GRacerStats mStats;
	GTimer mRaceTimer;
	GTimer mLapTimer;
	GTimer mCheckTimer;
	GTimer mCrashTimer;
	GTimer mPostCrashTimer;
	GTimer mSectorTimer;
	GCallbackTimer mTimers[1];
	float mSectorTargetTime;
	RecordingState mRecording70To150;
	float mCurrent70To150;
	UMath::Vector3 mSavedPosition;
	float mSavedHeatLevel;
	UMath::Vector3 mSavedDirection;
	float mSavedSpeed;
	UMath::Vector3 mCrashPosition;
	UMath::Vector3 mCrashDirection;
	bool mPlayerLapGhostCars;
	bool mCarIsInWheelie;
	bool mCarHasWheelied;
	UMath::Vector3 mDragWheelieLastPosition;
	float mDragDistanceWheelied;
	DriftScoring mDriftScoring;
	Timeline* mRecordTimeline;
	Timeline* mPlaybackTimelines[1];
	bool mOffRoad;
	UMath::Vector3 mLastOnRoadPosition;
	UMath::Vector3 mLastOnRoadDirection;
	float mFirstLapTimeEstimate;
	float mSubsequentLapTimesEstimate;
	unsigned int mCurrentGoal;
	FinishReason (*mExtrapolateFinishFuncs[4])(GRacerInfo*, FinishReason);
	FinishReason (*mNoFinishFuncs[4])(GRacerInfo*, FinishReason);
};
static_assert(sizeof(GRacerInfo) == 0x594);
static_assert(offsetof(GRacerInfo, mOpponent) == 0xC);
static_assert(offsetof(GRacerInfo, mSectorTimer) == 0x424);
static_assert(offsetof(GRacerInfo, mTimers) == 0x430);
static_assert(offsetof(GRacerInfo, mSavedPosition) == 0x464);
static_assert(offsetof(GRacerInfo, mCarIsInWheelie) == 0x49D);
static_assert(offsetof(GRacerInfo, mCarHasWheelied) == 0x49E);
static_assert(offsetof(GRacerInfo, mExtrapolateFinishFuncs) == 0x574);
static_assert(offsetof(GRacerInfo, mNoFinishFuncs) == 0x584);

class GHurryUpTimer {
public:
	Hermes::_h_HHANDLER__* mStartHurryUpTimer;
	Hermes::_h_HHANDLER__* mStopHurryUpTimer;
	bool mIsRunning;
	float mTimeRemaining;
};
static_assert(sizeof(GHurryUpTimer) == 0x10);

class GRaceStatus : public IVehicleCache, ISelectionSet, UCOM::Object {
public:
	enum PlayMode {
		kPlayMode_Roaming = 0,
		kPlayMode_Racing = 1,
	};

	enum RaceStartFormat {
		STANDING_START = 0,
		ROLLING_START_LEADER = 1,
		ROLLING_START_MYCAR = 2,
		DRAG_START_HEADSUP = 3,
		DRAG_START_BRACKET = 4,
	};

	enum eAdaptiveGainReason {
		kAdaptiveGain_FromEngineBlown = 0,
		kAdaptiveGain_FromVehicleDestroyed = 1,
		kAdaptiveGain_FromFinalizeRace = 2,
		kAdaptiveGain_FromRacerKOed = 3,
		kAdaptiveGain_FromRacerFinished = 4,
		kAdaptiveGain_FromRestart = 5,
	};

	enum FinishType {
		kFinish_Extrapolate = 0,
		kFinish_Disqualify = 1,
		kFinish_HurryUp = 2,
	};

	enum {
		kMaxLaps = 10,
		kMaxRacers = 8,
		kMaxShortcuts = 32,
		kMaxSpeedTraps = 16,
		kMaxCheckpoints = 16,
		kMaxSectors = 4,
		kMaxCatchUpEntries = 11,
		kMaxBarrierExemptions = 4,
		kFinishNotDisabled = 0,
		kFinishDisabled = 1,
		kFinishEnabled = 2,
		kMaxGroups = 2,
		kMaxGroupSize = 4,
	};

	GRacerInfo mRacerInfo[8];
	GRacerInfo* mLazyRankingInfo[8];
	int mRacerCount;
	eastl::vector<unsigned int,bstl::allocator> mOpponents;
	float mRaceHandicap;
	bool mIsLoading;
	GRaceStatus::PlayMode mPlayMode;
	GRace::Context mRaceContext;
	GRaceParameters* mRaceParms;
	GRaceBin* mRaceBin;
	GTimer mRaceMasterTimer;
	bool mPlayerPursuitInCooldown;
	float mBonusTime;
	float mTaskTime;
	bool mSuddenDeathMode;
	bool mTimeExpiredMsgSent;
	bool mActivelyRacing;
	int mLastSecondTickSent;
	WorldModel* mCheckpointModel;
	AcidEffect* mCheckpointEmitter;
	bool mQueueBinChange;
	unsigned int mWarpWhenInFreeRoam;
	int mNumTimeBonusCheckpoints;
	bool mScriptWaitingForLoad;
	bool mRefreshBinAfterRace;
	bool mWaitForMusicTransition;
	bstl::derived_with_name<eastl::vector<GTrigger*,bstl::allocator>> mCheckpoints;
	GTrigger* mNextCheckpoint;
	GTrigger* mEncounterFinish;
	int mNumRaceSegments;
	float mLapTimes[10][8];
	float mCheckTimes[10][16][8];
	float mSegmentLengths[18];
	float fRaceLength;
	float fFirstLapLength;
	float fSubsequentLapLength;
	bstl::derived_with_name<eastl::map<unsigned short,float,eastl::less<unsigned short>,bstl::allocator>> mRaceDistanceMap;
	uint8_t mRevealedShortcuts[32];
	int16_t mSideRoutes[32];
	uint8_t mSlowcuts[32];
	int mShortcutPairs[32];
	uint8_t mShortcutsExitSegmentReachedByActivatedPathy[32];
	uint8_t mShortcutsExittedByActivatedPathy[32];
	int mIndexOfLastShortcutInRace;
	bool mCaluclatedAdaptiveGain;
	float fCatchUpIntegral;
	float fCatchUpDerivative;
	float fCatchUpAdaptiveBonus;
	float fAveragePercentComplete;
	int nCatchUpSkillEntries;
	float aCatchUpSkillData[11];
	int nCatchUpSpreadEntries;
	float aCatchUpSpreadData[11];
	int nSpeedTraps;
	GTrigger* aSpeedTraps[16];
	float mStartTimeOfBestLap;
	bool mVehicleCacheLocked;
	unsigned int mRaceRouteFlags;
	int mTrafficDensity;
	unsigned int mTrafficPattern;
	bool mHasBeenWon;
	UMath::Vector3 mSavedEngagePos;
	unsigned int mFinishFlareState;
	bool mRestartAllowed;
	bool mStatsArbitrating;
	GTimer mFreeRoamTimer;
	GHurryUpTimer mHurryUpTimer;
	unsigned int mSectorOwner[4];
	float mSectorTime[4];
	float mSectorBestPoints[4];
	float mSectorDistance[4];
	unsigned int mNumSectors;
	bool mSkippedPartOfRace;
	bool mMultiClassDidSetup;
	float mMultiClassSecondGroupDelay;
	bool(*mRankingFuncs[11])(const GRacerInfo*, const GRacerInfo*);
	GRace::Type mRecentRaceType;

	static inline auto& fObj = *(GRaceStatus**)0xAB9D7C;

	static inline auto GetRacerInfo = (GRacerInfo*(__thiscall*)(GRaceStatus*, ISimable*))0x671EC0;
};
static_assert(sizeof(GRaceStatus) == 0x45D0);
static_assert(offsetof(GRaceStatus, mRacerInfo) == 0x20);
static_assert(offsetof(GRaceStatus, mRacerCount) == 0x2CE0);

auto GetOpponentDamage = (float(*)(ISimable*))0x674F30;