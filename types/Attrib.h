namespace Attrib {
	class Vault;
	class Definition;
	class ClassPrivate;
	class Collection;

	struct Private {
		uint8_t mData[8];
	};

	class StringKey {
	public:
		unsigned int mHash32;
		const char *mString;
	};

	class RefSpec {
	public:
		unsigned int mClassKey;
		unsigned int mCollectionKey;
		const Collection *mCollectionPtr;
	};

	class Class {
	public:
		unsigned int mKey;
		ClassPrivate* mPrivates;

		auto GetFirstCollection() { auto f = (uint32_t(__thiscall*)(Class*))0x52C890; return f(this); }
		auto GetNextCollection(uint32_t prev) { auto f = (uint32_t(__thiscall*)(Class*, uint32_t))0x52C8B0; return f(this, prev); }
	};

	class ClassPrivate : public Class {
	public:
		uint8_t _8[0x18];
		uint16_t mLayoutSize;
		uint16_t mNumDefinitions;
		Definition* mDefinitions;
		Vault* mSource;
		void* mStaticData;
	};

	class Database {
	public:
		static inline auto& sThis = *(Database**)0xAB0E60;

		auto GetClass(uint32_t k) { auto f = (Class*(__thiscall*)(Database*, uint32_t))0x52CA70; return f(this, k); }
	};

	class Array {
	public:
		uint16_t mAlloc;
		uint16_t mCount;
		uint16_t mSize;
		uint16_t mEncodedTypePad;
	};

	class Node {
	public:
		uint32_t mKey;
		union {
			void* mPtr;
			Attrib::Array* mArray;
			uint32_t mValue;
			uint32_t mOffset;
		};
		uint16_t mTypeIndex;
		uint8_t mMax;
		uint8_t mFlags;
	};

	class Collection {
	public:
		uint8_t _mTable[0xC];
		Collection* mParent;
		uint32_t mKey;
		Class* mClass;
		void* mLayout;
		Vault* mSource;

		static inline auto GetData = (void*(__thiscall*)(Collection*, uint32_t attributeKey, uint32_t index))0x52B5D0;
		static inline auto GetNode = (Attrib::Node*(__thiscall*)(Collection*, uint32_t attributeKey, const Attrib::Collection **container))0x52B530;
	};

	class Instance {
	public:
		Collection* mCollection;
		void* mLayoutPtr;
		uint32_t mMsgPort;
		uint32_t mFlags;

		Instance() {}

		Instance(const Collection* collection, uint32_t msgPort) {
			((Instance*(__thiscall*)(Instance*, const Collection*, uint32_t))0x52AA00)(this, collection, msgPort);
		}
		//~Instance() {
		//	((void(__thiscall*)(Instance*))0x5301F0)(this);
		//}
		void ctor(const Collection* collection, uint32_t msgPort) {
			((Instance*(__thiscall*)(Instance*, const Collection*, uint32_t))0x52AA00)(this, collection, msgPort);
		}
		void dtor() {
			((void(__thiscall*)(Instance*))0x5301F0)(this);
		}

		static inline auto GetAttributePointer = (void*(__thiscall*)(Instance*, uint32_t attributeKey, uint32_t index))0x52B950;
	};

	auto FindCollection = (Collection*(*)(uint32_t classKey, uint32_t collectionKey))0x52CD40;
	auto StringHash32 = (uint32_t(*)(const char*))0x52B8D0;
	auto StringToLowerCaseKey = (uint32_t(*)(const char*))0x52B9C0;
};