namespace Physics {
	namespace Upgrades {
		class Tuning {
		public:
			float lowerBound;
			float upperBound;
			float position;
		};
	}

	class Tunings {
	public:
		float Value[7];
	};
}
static_assert(sizeof(Physics::Upgrades::Tuning) == 0xC);
static_assert(sizeof(Physics::Tunings) == 0x1C);