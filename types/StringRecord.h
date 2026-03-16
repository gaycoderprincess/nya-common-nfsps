namespace EA {
	namespace Localizer {
		namespace LocalizerManager {
			class LanguageStringRecord {
			public:
				uint32_t mHash;
				const char* mPackedString;
			};

			class LanguageFileInfo {
			public:
				char mStringCategory[16];
				unsigned int mNumberStringRecords;
				uint8_t *mPackedStringTables;
				LanguageStringRecord *mRecordTables;
			};
			static_assert(offsetof(LanguageFileInfo, mRecordTables) == 0x18);
			auto& mCategories = *(LanguageFileInfo**)0xAB28F8;
			auto& mMaxCategories = *(uint32_t*)0xA55134;
		}
	}
}