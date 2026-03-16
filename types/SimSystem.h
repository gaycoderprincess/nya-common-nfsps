namespace Sim {
	enum State {
		STATE_NONE = 0,
		STATE_INITIALIZING = 1,
		STATE_ACTIVE = 3,
		STATE_IDLE = 4,
	};

	auto Exists = (bool(*)())0x4CEBC0;
	auto GetTime = (float(*)())0x4CEFB0;
	auto GetState = (State(*)())0x4CEBD0;
}

class SimSystem;

namespace Sim {
	namespace Internal {
		auto& mSystem = *(SimSystem**)0xBFB400;
	}

	namespace Collision {
		class IListener;

		class Info {
		public:
			enum CollisionType {
				NONE = 0,
				OBJECT = 1,
				WORLD = 2,
				GROUND = 3,
			};

			class Primitive {
			public:
				UMath::Vector3 pos;
				UMath::Vector4 orient;
				UMath::Vector3 dim;
				int shape;
			};

			UMath::Vector3 position;
			const Attrib::Collection *objAsurface;
			UMath::Vector3 normal;
			uint32_t unused : 24;
			uint32_t sliding : 1;
			uint32_t objBDetached : 1;
			uint32_t objBImmobile : 1;
			uint32_t objADetached : 1;
			uint32_t objAImmobile : 1;
			uint32_t type : 3;
			UMath::Vector3 closingVel;
			float force;
			UMath::Vector3 armA;
			HSIMABLE__ *objA;
			UMath::Vector3 armB;
			HSIMABLE__ *objB;
			UMath::Vector3 objAVel;
			float impulseA;
			UMath::Vector3 objBVel;
			float impulseB;
			UMath::Vector3 slidingVel;
			const Attrib::Collection *objBsurface;
			Sim::Collision::Info::Primitive primA;
			Sim::Collision::Info::Primitive primB;
		};

		//inline auto AddListener = (void(*)(Sim::Collision::IListener *listener, const UCOM::IUnknown *participant, const char *who))0x7C28A0;
		//inline auto RemoveListener = (void(*)(Sim::Collision::IListener *listener))0x7C0AC0;
	}
}