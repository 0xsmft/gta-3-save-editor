#pragma once

#include <string>

class FBufferHelpers
{
public:
	template<typename IStream>
	static uint32_t ReadBlockHeader( IStream& rStream, const char* pExpectedHeader )
	{
		char magic[ 4 ]{ 0 };
		rStream.read( reinterpret_cast< char* >( &magic ), 4 );

		if( std::memcmp( magic, pExpectedHeader, 4 ) != 0 )
			__debugbreak();

		uint32_t blockSize = 0;
		rStream.read( reinterpret_cast< char* >( &blockSize ), sizeof( uint32_t ) );

		return blockSize;
	}

	template<typename Ty, typename IStream>
	static void ReadObject( Ty& rObject, IStream& rStream )
	{
		rStream.read( reinterpret_cast< char* >( &rObject ), sizeof( Ty ) );
	}

	template<typename IStream>
	static void Skip4( IStream& rStream )
	{
		uint32_t x = 0u;
		rStream.read( reinterpret_cast< char* >( &x ), sizeof( uint32_t ) );
	}

	template<typename IStream>
	static void Skip8( IStream& rStream )
	{
		uint64_t x = 0u;
		rStream.read( reinterpret_cast< char* >( &x ), sizeof( uint64_t ) );
	}

	template<typename IStream>
	static void Skip2( IStream& rStream )
	{
		uint16_t x = 0;
		rStream.read( reinterpret_cast< char* >( &x ), sizeof( uint16_t ) );
	}

	template<typename IStream>
	static void SkipByte( IStream& rStream )
	{
		uint8_t x = 0;
		rStream.read( reinterpret_cast< char* >( &x ), sizeof( uint8_t ) );
	}
};
