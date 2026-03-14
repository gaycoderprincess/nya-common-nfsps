class eView;
class WCollider;

class WaveData3 {
public:
	bVector3 frequency;
	bVector3 amplitude;
};

class CameraParams {
public:
	bMatrix4 Matrix;
	bVector3 Position;
	bVector3 Direction;
	bVector3 Target;
	WaveData3 PosNoise[3];
	WaveData3 RotNoise[3];
	bVector3 PosNoise2Value;
	bVector3 RotNoise2Value;
	float FocalDistance;
	float DepthOfField;
	float DOFFalloff;
	float DOFMaxIntensity;
	float NearZ;
	float FarZ;
	float LB_height;
	float SimTimeMultiplier;
	bVector4 FadeColor;
	float TargetDistance;
	uint16_t FieldOfView;
	uint16_t PaddingAngle;
	bVector2 PaddingVector2;
};

class Camera {
public:
	CameraParams CurrentKey;
	CameraParams PreviousKey;
	CameraParams VelocityKey;
	bool bClearVelocity;
	float ElapsedTime;
	int LastUpdateTime;
	int LastDisparateTime;
	int RenderDash;
	float NoiseIntensity;

	static inline auto SetCameraMatrix = (void(__thiscall*)(Camera*, const bMatrix4* m, float fTime))0x640FC0;
};