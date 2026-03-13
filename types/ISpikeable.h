enum eTireDamage {
	TIRE_DAMAGE_NONE = 0,
	TIRE_DAMAGE_PUNCTURED = 1,
	TIRE_DAMAGE_BLOWN = 2,
};

class ISpikeable : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x473CE0;

	virtual eTireDamage GetTireDamage(unsigned int);
	virtual unsigned int GetNumBlowouts();
	virtual void Puncture(unsigned int);
};