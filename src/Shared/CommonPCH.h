#pragma once

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN
#define WINRT_LEAN_AND_MEAN
#define WINRT_NO_MODULE_LOCK

// Windows 头文件

// 从 windows.h 里排除不需要的 API
#define NOMINMAX	// 使用 std::min 和 std::max 而不是宏
#define NOGDICAPMASKS
#define NOICONS
#define NOATOM
#define NOCLIPBOARD
#define NODRAWTEXT
#define NOMEMMGR
#define NOMETAFILE
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

#include <windows.h>
#include <windowsx.h>
#include <dwmapi.h>
#include <ShlObj.h>
#include <shellapi.h>
#include <Shlwapi.h>

// 修复 C++/WinRT 头文件的警告
#undef GetCurrentTime
#undef GetNextSibling

// DirectX 头文件
#include <d3d11_4.h>
#include <dxgi1_6.h>

// C++ 运行时头文件
#include <cstdlib>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <functional>
#include <span>

// C++/WinRT 头文件
#include <unknwn.h>
#include <restrictederrorinfo.h>
#include <hstring.h>
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.Metadata.h>
#include <winrt/Windows.System.h>


namespace winrt {
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Foundation::Metadata;
using namespace Windows::System;
}

// 确保已编译 CONAN 依赖
#if !__has_include(<fmt/format.h>)
static_assert(false, "Build CONAN_INSTALL first!")
#endif

// fmt
#include <fmt/format.h>
#include <fmt/xchar.h>
#include <fmt/printf.h>


#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "Comctl32.lib")
#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib, "d3d11.lib")

using namespace std::string_literals;
using namespace std::string_view_literals;


// 宏定义

#define DEFINE_FLAG_ACCESSOR(Name, FlagBit, FlagsVar) \
	bool Name() const noexcept { return FlagsVar & FlagBit; } \
	void Name(bool value) noexcept { \
		if (value) { \
			FlagsVar |= FlagBit; \
		} else { \
			FlagsVar &= ~FlagBit; \
		} \
	}
