#pragma once
#include "pch.h"
#include <AppxPackaging.h>


namespace winrt::Magpie::App {

struct AppXHelper {
	class AppXReader {
	public:
		bool Initialize(HWND hWnd) noexcept;

		std::wstring GetDisplayName() const noexcept;

		std::wstring GetIconPath(uint32_t preferredSize, bool preferLightTheme) const noexcept;

	private:
		bool _ResolveApplication(const std::wstring& praid) noexcept;

		std::wstring _packageFullName;
		std::wstring _packagePath;
		com_ptr<IAppxManifestApplication> _appxApp;
	};
};

}
