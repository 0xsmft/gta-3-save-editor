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

	template<typename OStream>
	static void WriteBlockHeader( OStream& rStream, const char* pHeader, uint32_t blockSize )
	{
		rStream.write( pHeader, 4 );
		rStream.write( reinterpret_cast< char* >( &blockSize ), sizeof( uint32_t ) );
	}

	template<typename Ty, typename IStream>
	static void ReadObject( Ty& rObject, IStream& rStream )
	{
		rStream.read( reinterpret_cast< char* >( &rObject ), sizeof( Ty ) );
	}

	template<typename Ty, typename OStream>
	static void WriteObject( const Ty& rObject, OStream& rStream )
	{

		rStream.write( reinterpret_cast< const char* >( &rObject ), sizeof( Ty ) );
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

	template<typename OStream>
	static void Write4( OStream& rStream )
	{
		uint32_t x = 0u;
		WriteObject( x, rStream );
	}

	template<typename OStream>
	static void WriteByte( OStream& rStream )
	{
		uint8_t x = 0;
		WriteObject( x, rStream );
	}

	template<typename OStream, typename NType>
	static void WriteN( OStream& rStream, NType n )
	{
		for( NType i = 0; i < n; ++i )
		{
			WriteByte( rStream );
		}
	}

};
