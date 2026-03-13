class WCollider;

namespace Sim {
	namespace Collision {
		enum Shape {
			SHAPE_UNKNOWN = 0,
			SHAPE_BOX = 1,
			SHAPE_SPHERE = 2,
			SHAPE_MAX = 3,
		};
	}
}

class ICollisionBody : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x402250;

	virtual const UMath::Vector3 *GetPosition();
	virtual const UMath::Vector3 *GetLinearVelocity();
	virtual const UMath::Vector3 *GetAngularVelocity();
	virtual UMath::Vector3 *GetDimension(UMath::Vector3 *result);
	virtual void Damp(float);
	virtual void SetAnimating(bool);
	virtual bool IsModeling();
	virtual void DisableModeling();
	virtual void EnableModeling();
	virtual bool IsTriggering();
	virtual void DisableTriggering();
	virtual void EnableTriggering();
	virtual bool IsSleeping();
	virtual void SetCenterOfGravity(const UMath::Vector3 *);
	virtual const UMath::Vector3 *GetCenterOfGravity();
	virtual bool HasHadCollision();
	virtual bool HasHadWorldCollision();
	virtual bool HasHadObjectCollision();
	virtual bool HasHadGroundCollision();
	virtual void EnableCollisionGeometries(UCrc32, bool);
	virtual bool DistributeMass();
	virtual const UMath::Vector3 *GetWorldMomentScale();
	virtual const UMath::Vector3 *GetGroundMomentScale();
	virtual bool IsAttachedToWorld();
	virtual void AttachedToWorld(bool, float);
	virtual bool IsAnchored();
	virtual void SetAnchored(bool);
	virtual void SetInertiaTensor(const UMath::Vector3 *);
	virtual const UMath::Vector3 *GetInertiaTensor();
	virtual float GetOrientToGround();
	virtual bool IsInGroundContact();
	virtual unsigned int GetNumContactPoints();
	virtual const UMath::Vector4 *GetGroundNormal();
	virtual void SetForce(const UMath::Vector3 *);
	virtual void SetTorque(const UMath::Vector3 *);
	virtual const UMath::Vector3 *GetForce();
	virtual const UMath::Vector3 *GetTorque();
	virtual float GetGravity();
	virtual const UMath::Vector3 *GetForwardVector();
	virtual const UMath::Vector3 *GetRightVector();
	virtual const UMath::Vector3 *GetUpVector();
	virtual const UMath::Matrix4 *GetMatrix4();
	virtual unsigned int SetWorldCollisionMask(unsigned int);
	virtual int EnumPrimitiveHandles(bool (*)(HCOLPRIM__ *, void *), void *);
	virtual void GetPrimitive(HCOLPRIM__ *, UMath::Matrix4 *, UCrc32 *, UMath::Vector3 *, Sim::Collision::Shape *);
	virtual void BeginModifyPrimitives();
	virtual void ModifyPrimitive(HCOLPRIM__ *, const UMath::Matrix4 *, const UMath::Vector3 *);
	virtual void EndModifyPrimitives();
};