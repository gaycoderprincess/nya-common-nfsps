class ICheater : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x402C70;

	virtual float GetCatchupCheat();
	virtual void SetCatchupCheatOverride(float);
};