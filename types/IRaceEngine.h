class IRaceEngine : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x474FC0;

	virtual float GetPerfectLaunchRange(float*);
};