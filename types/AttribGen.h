class VariableArray {
public:
	float *mArray;
	unsigned int mLength;
};

class Curve {
public:
	float xMin;
	float xMax;
	float yMin;
	float yMax;
	float graphScale;
	VariableArray X;
	VariableArray Y;
	VariableArray Y2;
	bool allocatedMemory;
};

class AxlePair {
public:
	float Front;
	float Rear;

	float At(int index) const {
		return (&Front)[index];
	}
};

class AxlePairCurve {
public:
	Curve Front;
	Curve Rear;

	Curve At(int index) const {
		return (&Front)[index];
	}
};

enum TireCondition {
	kGrip = 0,
	kWet = 1,
	kFlat = 2,
	kDrift = 3,
	kDrag = 4,
};

class TireEffectRecord {
public:
	TireCondition mTireCondition;
	Attrib::RefSpec mEmitter;
	Attrib::RefSpec mEmitterLowLod;
	float mMinSpeed;
	float mMaxSpeed;
};

class RoadNoiseRecord {
public:
	float Frequency;
	float Amplitude;
	float MinSpeed;
	float MaxSpeed;
};

enum eDecalType {
	DECAL_TYPE_NONE = -1,
	DECAL_TYPE_SKID_CONCRETE = 0,
	DECAL_TYPE_SKID_DIRT = 1,
	DECAL_TYPE_SKID_GRASS = 2,
	DECAL_TYPE_SKID_SAND = 3,
	DECAL_TYPE_SCRAPE_METAL = 4,
	DECAL_TYPE_SCRAPE_PLASTIC = 5,
	DECAL_TYPE_SCRAPE_WOOD = 6,
	DECAL_TYPE_SCRAPE_CONCRETE = 7,
};

enum SCRAPE_SURFACES {
	SCRAPE_NONE = 0,
	SCRAPE_CONCRETE = 1,
	SCRAPE_METAL = 2,
	SCRAPE_RUBBER = 3,
	SCRAPE_OFFROAD = 4,
	MAX_SCRAPES = 5,
};

enum SURFACE_SFX {
	SURFACE_SFX_NONE = 0,
	SURFACE_SFX_LIGHT_CRACK = 1,
	SURFACE_SFX_TAR_STRIP = 3,
	SURFACE_SFX_ROADSIDE_PATCH = 5,
	SURFACE_SFX_HEAVY_PATCH = 6,
	SURFACE_SFX_DIRT = 7,
	MAX_SURFACE_SFX = 8,
};

enum EnginePosition {
	ENGINE_REAR = 0,
	ENGINE_MID = 1,
	ENGINE_FRONT = 2,
};

namespace Attrib {
	namespace Gen {
		class pvehicle : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				Attrib::StringKey MODEL;
				Attrib::RefSpec frontend;
				const char *DefaultPresetRide;
				const char *CollectionName;
				bool RandomOpponent;
				GRace::Tier RacingTier;
				bool isRateable;
				EnginePosition ENGINE_POSITION;
			};

			pvehicle(uint32_t collectionKey) {
				((pvehicle*(__thiscall*)(pvehicle*, uint32_t))0x49CC70)(this, collectionKey);
			}
			~pvehicle() {
				((void(__thiscall*)(pvehicle*))0x5301F0)(this);
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class vehicle : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				uint8_t _0[0x108];
				AxlePair TRACK_WIDTH; // +108
				AxlePair Tp;
				AxlePair SWAYBAR_STIFFNESS;
				AxlePair SPRING_STIFFNESS;
				AxlePair SPRING_PROGRESSION;
				AxlePair SHOCK_VALVING;
				AxlePair SHOCK_DIGRESSION;
				AxlePair SECTION_WIDTH; // +140
				AxlePair RIM_SIZE; // +148
				AxlePair RIDE_HEIGHT;
				AxlePair Kmu;
				AxlePair Ka;
				AxlePair K1;
				AxlePair Fzt;
				AxlePair CSvsFZ;
				AxlePair C4;
				AxlePair C3;
				AxlePair C2;
				AxlePair C1;
				AxlePair BRAKES;
				AxlePair ASPECT_RATIO;
				AxlePair A4;
				AxlePair A3;
				AxlePair A2;
				AxlePair A1;
				AxlePair A0;
				float WHEEL_BASE; // +1D8
				float TORQUE_SPLIT;
				float TORQUE_SLIP_SLOPE0;
				float TANK_SLAPPER_TIMER;
				float SteeringPID_P;
				float SteeringPID_I;
				float SteeringPID_HighSpeed_P;
				float SteeringPID_HighSpeed_I;
				float SteeringPID_HighSpeed_D;
				float SteeringPID_D;
				float STEERING_ALIGNING_TORQUE;
				float SPOOL_TIME_UP;
				float SPOOL_TIME_DOWN;
				float SHOCK_BLOWOUT;
				float SHIFT_SPEED;
				float ROLL_CENTER;
				float RENDER_MOTION;
				float RED_LINE;
				float OPTIMAL_SHIFT;
				float MIN_TIRE_TRACTION_TO_SHIFT_UP_FIRST_GEAR;
				float MIN_TIRE_TRACTION_TO_SHIFT_UP;
				float MAX_RPM;
				float MASS;
				float LOW_BOOST;
				float LIFT_HEIGHT_RATIO;
				float IDLE;
				float HIGH_BOOST;
				float GROUNDEFFECT_HEIGHT_RATIO;
				float FRONT_WEIGHT_BIAS;
				float FRONT_AXLE; // +24C
			};
			static_assert(offsetof(_LayoutStruct, WHEEL_BASE) == 0x1D8);
			static_assert(offsetof(_LayoutStruct, TRACK_WIDTH) == 0x108);
			static_assert(offsetof(_LayoutStruct, SECTION_WIDTH) == 0x140);
			static_assert(offsetof(_LayoutStruct, FRONT_AXLE) == 0x24C);
			static_assert(offsetof(_LayoutStruct, RIM_SIZE) == 0x148);

			vehicle(uint32_t collectionKey) {
				((vehicle*(__thiscall*)(vehicle*, uint32_t))0x49CD50)(this, collectionKey);
			}
			~vehicle() {
				((void(__thiscall*)(vehicle*))0x5301F0)(this);
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class simsurface : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				Private _Array_TireSlipEffects;
				TireEffectRecord TireSlipEffects[5];
				const char *CollectionName;
				RoadNoiseRecord RenderNoise;
				float WORLD_FRICTION;
				SURFACE_SFX SurfaceFX_ID;
				float STICK;
				SCRAPE_SURFACES ScrapeFX_ID;
				float ROLLING_RESISTANCE;
				float LATERAL_GRIP;
				float GROUND_FRICTION;
				float DRIVE_GRIP;
				eDecalType Decal;
				unsigned __int16 WheelEffectFrequency;
				unsigned __int8 WheelEffectIntensity;
			};

			simsurface() {
				((simsurface*(__thiscall*)(simsurface*))0x4CD2F0)(this);
			}
			//simsurface(const Attrib::Collection *collection, uint32_t msgPort) {
			//	((simsurface*(__thiscall*)(simsurface*, const Attrib::Collection*, uint32_t))0x)(this, collection, msgPort);
			//}
			~simsurface() {
				((void(__thiscall*)(simsurface*))0x5301F0)(this);
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};
	}
}