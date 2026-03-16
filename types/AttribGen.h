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

enum PartType {
	PartType_CarSpecific = 0,
	PartType_Universal = 1,
	PartType_Vinyl = 2,
	PartType_Paint = 3,
	PartType_Windtunnel = 4,
	PartType_Damage = 5,
	PartType_DamageSD = 6,
};

struct DynamicSizeArray {
	Attrib::RefSpec *mArray;
	unsigned int mLength;
};

struct CCarSlotEntry {
	DynamicSizeArray parts;
	const char *slotName;
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
				dtor();
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class vehicle : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				UMath::Vector4 TENSOR_SCALE; // +0
				uint8_t _10[0xF8];
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
				float FLYWHEEL_MASS;
				float FINAL_GEAR;
				float EBRAKE;
				float DYNAMIC_ROLL_CENTER_MIN_ANGLE;
				float DYNAMIC_ROLL_CENTER_MAX_ANGLE;
				float DYNAMIC_ROLL_CENTER_CORRECTION;
				float DRAG_COEFFICIENT;
				float COUNTER_STEER_MIN_ANGLE;
				float CLUTCH_SLIP;
				float CASTER;
				float AERO_COEFFICIENT_MAX_LIFT;
				float AERO_COEFFICIENT_MAX_GROUND_EFFECT;
				float AERO_COEFFICIENT_90_DEG_LOSS;
				float AERO_COEFFICIENT;
				float AERO_CG;
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
				dtor();
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class car : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				Attrib::RefSpec pvehicle;
				Attrib::RefSpec parts;
				Attrib::RefSpec kits;
				Attrib::RefSpec art;
				const char *offerid;
				const char *name;
				bool isStandardDef;
				bool isOnlineLockable;
				bool isHiDef;
			};

			car(uint32_t collectionKey) {
				ctor(Attrib::FindCollection(Attrib::StringHash32("car"), collectionKey), 0);
			}
			~car() {
				dtor();
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class car_parts : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				CCarSlotEntry window_tint_swatch;
				CCarSlotEntry window_tint_group;
				CCarSlotEntry window_tint;
				CCarSlotEntry window_rear_right;
				CCarSlotEntry window_rear_left;
				CCarSlotEntry window_rear;
				CCarSlotEntry window_front_right;
				CCarSlotEntry window_front_left;
				CCarSlotEntry window_front;
				CCarSlotEntry wheel_spoke_rear_paint_swatch;
				CCarSlotEntry wheel_spoke_rear_paint_group;
				CCarSlotEntry wheel_spoke_rear_paint;
				CCarSlotEntry wheel_spoke_front_paint_swatch;
				CCarSlotEntry wheel_spoke_front_paint_group;
				CCarSlotEntry wheel_spoke_front_paint;
				CCarSlotEntry wheel_rear;
				CCarSlotEntry wheel_paint_swatch;
				CCarSlotEntry wheel_paint_group;
				CCarSlotEntry wheel_paint;
				CCarSlotEntry wheel_front;
				CCarSlotEntry vinyl_vector;
				CCarSlotEntry vinyl_paint;
				CCarSlotEntry universal_spoiler_base;
				CCarSlotEntry trunk;
				CCarSlotEntry tire_rear;
				CCarSlotEntry tire_package;
				CCarSlotEntry tire_front;
				CCarSlotEntry suspension_package;
				CCarSlotEntry steering_wheel;
				CCarSlotEntry spoiler_paint_swatch;
				CCarSlotEntry spoiler_paint_group;
				CCarSlotEntry spoiler_paint;
				CCarSlotEntry spoiler;
				CCarSlotEntry skirt_right;
				CCarSlotEntry skirt_paint_swatch;
				CCarSlotEntry skirt_paint_group;
				CCarSlotEntry skirt_paint;
				CCarSlotEntry skirt_left;
				CCarSlotEntry side_mirror_right;
				CCarSlotEntry side_mirror_paint_swatch;
				CCarSlotEntry side_mirror_paint_group;
				CCarSlotEntry side_mirror_paint;
				CCarSlotEntry side_mirror_left;
				CCarSlotEntry seat_right;
				CCarSlotEntry seat_left;
				CCarSlotEntry roof_scoop;
				CCarSlotEntry roof_inside;
				CCarSlotEntry roof;
				CCarSlotEntry rollcage_paint_swatch;
				CCarSlotEntry rollcage_paint_group;
				CCarSlotEntry rollcage_paint;
				CCarSlotEntry roll_cage;
				CCarSlotEntry nitrous_package;
				CCarSlotEntry livery;
				CCarSlotEntry license_plate;
				CCarSlotEntry interior;
				CCarSlotEntry hood_paint_swatch;
				CCarSlotEntry hood_paint_group;
				CCarSlotEntry hood_paint;
				CCarSlotEntry hood;
				CCarSlotEntry headlight_right;
				CCarSlotEntry headlight_left;
				CCarSlotEntry headlight_glass_right;
				CCarSlotEntry headlight_glass_left;
				CCarSlotEntry forced_induction_package;
				CCarSlotEntry fender_front_right;
				CCarSlotEntry fender_front_left;
				CCarSlotEntry exhaust;
				CCarSlotEntry engine_package;
				CCarSlotEntry engine;
				CCarSlotEntry drivetrain_package;
				CCarSlotEntry driver;
				CCarSlotEntry doorhandle_rear_right;
				CCarSlotEntry doorhandle_rear_left;
				CCarSlotEntry doorhandle_front_right;
				CCarSlotEntry doorhandle_front_left;
				CCarSlotEntry door_right;
				CCarSlotEntry door_rear_right;
				CCarSlotEntry door_rear_left;
				CCarSlotEntry door_left;
				CCarSlotEntry decal_window_rear;
				CCarSlotEntry decal_window_front;
				CCarSlotEntry chassis;
				CCarSlotEntry bumper_rear_paint_swatch;
				CCarSlotEntry bumper_rear_paint_group;
				CCarSlotEntry bumper_rear_paint;
				CCarSlotEntry bumper_rear_extra;
				CCarSlotEntry bumper_rear;
				CCarSlotEntry bumper_front_paint_swatch;
				CCarSlotEntry bumper_front_paint_group;
				CCarSlotEntry bumper_front_paint;
				CCarSlotEntry bumper_front_extra;
				CCarSlotEntry bumper_front;
				CCarSlotEntry brakelight_right;
				CCarSlotEntry brakelight_left;
				CCarSlotEntry brakelight_glass_right;
				CCarSlotEntry brakelight_glass_left;
				CCarSlotEntry brake_rotor_rear;
				CCarSlotEntry brake_rotor_front;
				CCarSlotEntry brake_caliper_rear;
				CCarSlotEntry brake_caliper_front;
				CCarSlotEntry body_paint_swatch;
				CCarSlotEntry body_paint_group;
				CCarSlotEntry body_paint;
				CCarSlotEntry body_doorline;
				CCarSlotEntry body;
				CCarSlotEntry base;
				CCarSlotEntry badging_trunk;
				CCarSlotEntry badging_fender_rear_right;
				CCarSlotEntry badging_fender_rear_left;
				CCarSlotEntry badging_fender_front_right;
				CCarSlotEntry badging_fender_front_left;
				CCarSlotEntry badging_bumper_rear;
				CCarSlotEntry badging_bumper_front;
			};

			car_parts(uint32_t collectionKey) {
				ctor(Attrib::FindCollection(Attrib::StringHash32("car_parts"), collectionKey), 0);
			}
			~car_parts() {
				dtor();
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class car_part : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				Attrib::RefSpec fe_data;
				const char *part_id;
				const char *name;
				PartType part_type;
				int kit_min;
				int kit_max;
			};

			car_part(uint32_t collectionKey) {
				ctor(Attrib::FindCollection(Attrib::StringHash32("car_part"), collectionKey), 0);
			}
			~car_part() {
				dtor();
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
				dtor();
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};
	}
}