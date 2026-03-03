#pragma once

//////////////////////////////////////////////////////////////////////////
// VERSION
template<typename Ty>
consteval auto XY_MAKE_VERSION( Ty major, Ty minor, Ty patch ) { return ( ( ( ( unsigned int ) ( major ) ) << 22 ) | ( ( ( unsigned int ) ( minor ) ) << 12 ) | ( ( unsigned int ) ( patch ) ) ); }

constexpr auto XY_CURRENT_VERSION = XY_MAKE_VERSION( 0, 0, 1 );
constexpr auto XY_CURRENT_VERSION_STRING = "0.0.1";

#define XY_DECODE_VERSION(source, major, minor, patch) \
patch = (source) & 0xFF; \
minor = ((source) >> 12) & 0x3FF;\
major = (source) >> 22

#define XY_DECODE_VER_STRING( sourceVersion, string ) \
{ \
uint32_t major, minor, patch; \
XY_DECODE_VERSION( sourceVersion, major, minor, patch ); \
string = std::format( "{0}.{1}.{2}", major, minor, patch ); \
}

namespace Core {

	inline void BreakDebug()
	{
#if !defined(XY_DIST)
#if defined( _WIN32 )
		__debugbreak();
#else
		raise( SIGTRAP );
#endif // _MSC_VER
#endif
	}

}

constexpr unsigned int MAX_FRAMES_IN_FLIGHT = 3u;

#define XY_SINGLETON_LAZY( x ) static inline x& Get() { static x _; return _; }
