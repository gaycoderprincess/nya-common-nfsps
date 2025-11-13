class FeGarageMain {
public:
	static inline auto& spInstance = *(FeGarageMain**)0xB32AAC;

	static inline auto SetRideInfo = (const char*(__thiscall*)(FeGarageMain*, uint32_t car_handle, BLUEPRINT_NUMBER num))0x7E6EF0;
};