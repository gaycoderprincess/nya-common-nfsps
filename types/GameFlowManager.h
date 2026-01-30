class GameFlowManager {
public:
	void* pSingleFunction;
	uint32_t SingleFunctionParam;
	const char* pSingleFunctionName;
	void* pLoopingFunction;
	const char* pLoopingFunctionName;
	bool WaitingForCallback;
	const char* pCallbackName;
	uint32_t CallbackPhase;
	uint32_t CurrentGameFlowState;

	static inline auto UnloadTrack = (void(__thiscall*)(GameFlowManager*))0x6DBC60;
	static inline auto LoadFrontend = (void(__thiscall*)(GameFlowManager*))0x6D3230;
	static inline auto UnloadFrontend = (void(__thiscall*)(GameFlowManager*))0x6D3290;
};
static_assert(sizeof(GameFlowManager) == 0x24);

auto& TheGameFlowManager = *(GameFlowManager*)0xABB4F0;