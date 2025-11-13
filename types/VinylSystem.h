namespace VinylSystem {
	class VinylTransformPacked {
	public:
		int16_t translationX;
		int16_t translationY;
		int8_t rotation;
		int8_t scaleX;
		int8_t scaleY;
		int8_t _bf_7;
	};
}
static_assert(sizeof(VinylSystem::VinylTransformPacked) == 0x8);