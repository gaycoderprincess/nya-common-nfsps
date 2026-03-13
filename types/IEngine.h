class IEngine : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x405D50;

	virtual float GetRPM();
	virtual float GetEngineBogRPM();
	virtual float GetRedline();
	virtual float GetMaxRPM();
	virtual float GetMinRPM();
	virtual float GetPeakTorqueRPM();
	virtual float GetPerfectShiftMinRPM(GearID);
	virtual float GetPerfectShiftMaxRPM(GearID);
	virtual float GetTorqueRatio();
	virtual void MatchSpeed(float);
	virtual float GetNOSCapacity();
	virtual bool IsNOSEngaged();
	virtual float GetNOSPressure();
	virtual float GetNOSFlowRate();
	virtual float GetNOSBoost();
	virtual bool HasNOS();
	virtual void ChargeNOS();
	virtual int GetNOSNumStages();
	virtual void unknown(Attrib::Collection*);
	virtual float GetMaxHorsePower();
	virtual float GetMinHorsePower();
	virtual float GetHorsePower();
	virtual float GetThrottle();
	virtual bool IsTractionControlOn();
	virtual int GetTractionControlLevel();
	virtual void SetTractionControlLevel(int);
	virtual float GetEngineTemperature();
};