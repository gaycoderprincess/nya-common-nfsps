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
};