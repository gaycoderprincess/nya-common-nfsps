namespace Sim {
	class Param {
	public:
		UCrc32 mType;
		const Sim::Param* mSource;
		unsigned int pad;
		unsigned int pad1;
	};
}

class IVehicleCache;

class VehicleParams : public Sim::Param {
public:
	DriverClass carClass;
	Attrib::Instance pvehicle;
	const UMath::Vector3* initialVec;
	const UMath::Vector3* initialPos;
	RideInfo* rideInfo;
	IVehicleCache* VehicleCache;
	const Physics::Info::PerformanceMatching* matched;
	unsigned int Flags;

	VehicleParams() {
		mType.mCRC = Attrib::StringHash32("VehicleParams");
		mSource = this;
	}
};
static_assert(sizeof(VehicleParams) == 0x3C);

class PVehicle {
public:
	uint8_t _0[0x14C];
	DriverClass mDriverClass;

	static inline auto Construct = (ISimable*(__cdecl*)(Sim::Param params))0x72FBC0;

	auto LookupBehaviorSignature(UCrc32 *result, const Attrib::StringKey *mechanic) {
		auto f = (UCrc32*(__thiscall*)(PVehicle*, UCrc32 *result, const Attrib::StringKey *mechanic))0x71FD60;
		return f(this, result, mechanic);
	}
};
static_assert(offsetof(PVehicle, mDriverClass) == 0x14C);

auto& BEHAVIOR_MECHANIC_AI = *(Attrib::StringKey*)0xACDE4C;
auto& BEHAVIOR_MECHANIC_AUDIO = *(Attrib::StringKey*)0xACDDF8;
auto& BEHAVIOR_MECHANIC_DAMAGE = *(Attrib::StringKey*)0xACDE58;
auto& BEHAVIOR_MECHANIC_DAMAGEPHYSICS = *(Attrib::StringKey*)0xACDD94;
auto& BEHAVIOR_MECHANIC_DRAW = *(Attrib::StringKey*)0xACDE00;
auto& BEHAVIOR_MECHANIC_EFFECTS = *(Attrib::StringKey*)0xACDE24;
auto& BEHAVIOR_MECHANIC_ENGINE = *(Attrib::StringKey*)0xACDDE0;
auto& BEHAVIOR_MECHANIC_INPUT = *(Attrib::StringKey*)0xACDD9C;
auto& BEHAVIOR_MECHANIC_RESET = *(Attrib::StringKey*)0xACDE40;
auto& BEHAVIOR_MECHANIC_RIGIDBODY = *(Attrib::StringKey*)0xACDE38;
auto& BEHAVIOR_MECHANIC_SUSPENSION = *(Attrib::StringKey*)0xACDE70;