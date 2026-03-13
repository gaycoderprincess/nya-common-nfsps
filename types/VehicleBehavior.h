// todo this is horrible and inaccurate
class PhysicsObject {
public:
	uintptr_t vtable;
	uint8_t _4[0x20];
	UCOM::Object Object;
};
static_assert(offsetof(PhysicsObject, Object) == 0x24);

namespace Sim {
	class IServiceable {
	public:
		virtual bool OnService(void* hCon, void* pkt) {
			return false;
		}
	};
}

class Behavior : public Sim::IServiceable {
public:
	uint8_t _4[0x20];
	bool mPaused;
	PhysicsObject *mOwner;
	ISimable *mIOwner;
	UCrc32 mMechanic;
	UCrc32 mSignature;
	int mPriority;
	HSIMPROFILE mProfile;
};
static_assert(offsetof(Behavior, mPriority) == 0x38);

class VehicleBehavior : public Behavior {
public:
	IVehicle* mVehicle;
};
static_assert(offsetof(VehicleBehavior, mVehicle) == 0x40);

class BehaviorParams {
public:
	const Sim::Param *fparams;
	PhysicsObject *fowner;
	const UCrc32 *fSig;
	const UCrc32 *fMechanic;
};