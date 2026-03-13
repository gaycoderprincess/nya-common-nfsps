class ITiptronic : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x407F10;

	virtual bool SportShift(GearID);
};