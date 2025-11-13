#include <vector>

namespace NyaHooks {
	std::vector<void(*)()> aEndSceneFuncs;
	std::vector<void(*)()> aWorldServiceFuncs;
	std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aWndProcFuncs;

	auto EndSceneOrig = (uint32_t(__thiscall*)(void*))nullptr;
	uint32_t __thiscall EndSceneHook(void* a1) {
		for (auto& func : aEndSceneFuncs) {
			func();
		}
		return EndSceneOrig(a1);
	}

	auto WorldServiceOrig = (void(__cdecl*)())nullptr;
	void WorldServiceHook() {
		for (auto& func : aWorldServiceFuncs) {
			func();
		}
		return WorldServiceOrig();
	}

	auto WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
	LRESULT __stdcall WndProcHook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		for (auto& func : aWndProcFuncs) {
			func(hWnd, msg, wParam, lParam);
		}
		return WndProcOrig(hWnd, msg, wParam, lParam);
	}

	void PlaceD3DHooks() {
		if (!EndSceneOrig) {
			EndSceneOrig = (uint32_t(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x4B0A8F, &EndSceneHook);
			//D3DResetOrig = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x5055AD, &D3DResetHook);
		}
	}

	void PlaceWorldServiceHook() {
		if (!WorldServiceOrig) {
			WorldServiceOrig = (void(__cdecl*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6DB068, &WorldServiceHook);
		}
	}

	void PlaceWndProcHook() {
		if (!WndProcOrig) {
			WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x70E2B4);
			NyaHookLib::Patch(0x70E2B4, &WndProcHook);
		}
	}
}