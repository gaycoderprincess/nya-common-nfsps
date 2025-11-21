namespace Attrib {
	class Vault;

	class Collection {
	public:
		uint8_t _mTable[0xC];
		Collection* mParent;
		uint32_t mKey;
		void* mClass;
		void* mLayout;
		Vault* mSource;
	};

	class Instance {
	public:
		Collection* mCollection;
		void* mLayoutPtr;
		uint32_t mMsgPort;
		uint32_t mFlags;

		Instance(const Collection* collection, uint32_t msgPort) {
			((Instance*(__thiscall*)(Instance*, const Collection*, uint32_t))0x52AA00)(this, collection, msgPort);
		}
		~Instance() {
			((void(__thiscall*)(Instance*))0x5301F0)(this);
		}

		static inline auto GetAttributePointer = (void*(__thiscall*)(Instance*, uint32_t attributeKey, uint32_t index))0x52B950;
	};

	auto FindCollection = (Collection*(__cdecl*)(uint32_t classKey, uint32_t collectionKey))0x52CD40;
	auto StringHash32 = (uint32_t(__cdecl*)(const char*))0x52B8D0;
};