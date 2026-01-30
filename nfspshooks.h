#include <vector>

namespace NyaHooks {
	namespace D3DEndSceneHook {
		std::vector<void(*)()> aFunctions;
		
		auto OrigFunction = (uint32_t(__thiscall*)(void*))nullptr;
		uint32_t __thiscall HookedFunction(void* a1) {
			for (auto& func : aFunctions) {
				func();
			}
			return OrigFunction(a1);
		}
		
		void Init() {
			if (OrigFunction) return;
			OrigFunction = (uint32_t(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x4B0A8F, &HookedFunction);
		}
	}
	
	namespace D3DResetHook {
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			return OrigFunction();
		}


		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x4B0ACC, &HookedFunction);
		}
	}

	void PlaceD3DHooks() {
		D3DEndSceneHook::Init();
		D3DResetHook::Init();
	}

	namespace InputBlockerHook {
		bool bInputsBlocked = false;

		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (bool(*)())nullptr;
		bool HookedFunction() {
			if (bInputsBlocked) return true;
			return OrigFunction();
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (bool(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6CA27D, &HookedFunction);
		}
	}

	namespace WorldServiceHook {
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			return OrigFunction();
		}


		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6DB068, &HookedFunction);
		}
	}

	namespace WndProcHook {
		std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aFunctions;

		auto OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
		LRESULT __stdcall HookedFunction(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			for (auto& func : aFunctions) {
				func(hWnd, msg, wParam, lParam);
			}
			return OrigFunction(hWnd, msg, wParam, lParam);
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x70E2B4);
			NyaHookLib::Patch(0x70E2B4, &HookedFunction);
		}
	}
	
	namespace SimServiceHook {
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(__thiscall*)(void*))nullptr;
		void __thiscall HookedFunction(void* a1) {
			for (auto& func : aFunctions) {
				func();
			}
			OrigFunction(a1);
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x67E3C3, &HookedFunction);
		}
	}

	namespace SkipFEFixes {
		auto GetVehicleKey_orig = (uint32_t(__thiscall*)(void*))nullptr;
		uint32_t __thiscall GetVehicleKeyHooked(void* a1) {
			if (!SkipFE) return GetVehicleKey_orig(a1);
			return Attrib::StringHash32(SkipFEPlayerCar);
		}

		void Init() {
			NyaHookLib::Patch<uint64_t>(0x4D4B41, 0x89F63300A9D97CA1);
			GetVehicleKey_orig = (uint32_t(__thiscall*)(void*))(*(uintptr_t*)0x983050);
			NyaHookLib::Patch(0x983050, &GetVehicleKeyHooked);
		}
	}
}