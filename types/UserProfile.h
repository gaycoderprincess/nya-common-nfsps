class UserProfile {
public:
	uint8_t _MemcardSaveable[0x18]; // +0
	char mName[32]; // +18
	uint8_t _mPlaylist[0x208]; // +38 placeholder
	FEPlayerCarDB mCarStable; // +240

	static inline auto spUserProfiles = (UserProfile**)0xAB0EAC; // spUserProfiles[4]
};