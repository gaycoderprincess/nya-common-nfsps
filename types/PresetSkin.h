class CarPaintPartRecordPacked {
public:
	uint16_t group;
	uint16_t hue;
	float saturation;
	float variance;
};
static_assert(sizeof(CarPaintPartRecordPacked) == 0xC);

class VinylColor {
public:
	uint32_t huePartNameHash;
	uint8_t saturation;
	uint8_t brightness;
};
static_assert(sizeof(VinylColor) == 0x8);

class VinylLayer {
public:
	uint32_t vinylPartNameHash;
	VinylSystem::VinylTransformPacked transform;
	VinylColor colors[4];
};
static_assert(sizeof(VinylLayer) == 0x2C);

class PresetSkin : bTNode<PresetSkin> {
public:
	char PresetName[32]; // +8
	CarPaintPartRecordPacked BodyPaint; // +28
	VinylLayer VectorVinyl; // +34
};
static_assert(sizeof(PresetSkin) == 0x60);

auto& PresetSkinList = *(bList<PresetSkin>*)0xA83C10;

auto FindFEPresetSkin = (void(__cdecl*)(uint32_t hash))0x76B8C0;