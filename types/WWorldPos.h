namespace CARP {
	struct CollisionSurface {
		uint8_t fSurface;
		uint8_t fFlags;
	};
}

class WSurface : CARP::CollisionSurface {};

class WCollisionTri {
public:
	UMath::Vector3 fPt0;
	const Attrib::Collection *fSurfaceRef;
	UMath::Vector3 fPt1;
	unsigned int fFlags;
	UMath::Vector3 fPt2;
	WSurface fSurface;
	uint16_t PAD;
};

class WWorldPos {
public:
	WCollisionTri fFace;
	uint32_t fUsageCount : 16;
	uint32_t fMissCount : 15;
	uint32_t fFaceValid : 1;
	float fYOffset;
	const Attrib::Collection *fSurface;

	WWorldPos() {
		memset(this,0,sizeof(*this));
		fYOffset = 0.025;
	}

	void SetTolerance(float liftAmount) {
		fYOffset = liftAmount;
	}

	static inline auto Update = (bool(__thiscall*)(WWorldPos*, UMath::Vector3* pos, UMath::Vector4* dest, bool usecache, const WCollider* collider, bool keep_valid))0x7AC6D0;
};
static_assert(offsetof(WWorldPos, fYOffset) == 0x34);
static_assert(offsetof(WWorldPos, fSurface) == 0x38);