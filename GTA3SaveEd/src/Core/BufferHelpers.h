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
		rStream.ignore( 4 );
	}

	template<typename IStream>
	static void Skip8( IStream& rStream )
	{
		rStream.ignore( 8 );
	}

	template<typename IStream>
	static void Skip2( IStream& rStream )
	{
		rStream.ignore( 2 );
	}

	template<typename IStream>
	static void SkipByte( IStream& rStream )
	{
		rStream.ignore();
	}

	template<typename IStream, typename NType>
	static void SkipN( IStream& rStream, NType n )
	{
		rStream.seekg( n, std::ios::cur );
	}

};
