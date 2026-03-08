/********************************************************************************************
*                                                                                           *
*                                                                                           *
*                                                                                           *
* MIT License                                                                               *
*                                                                                           *
* Copyright (c) 2020 - 2026 BEAST                                                           *
*                                                                                           *
* Permission is hereby granted, free of charge, to any person obtaining a copy              *
* of this software and associated documentation files (the "Software"), to deal             *
* in the Software without restriction, including without limitation the rights              *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                 *
* copies of the Software, and to permit persons to whom the Software is                     *
* furnished to do so, subject to the following conditions:                                  *
*                                                                                           *
* The above copyright notice and this permission notice shall be included in all            *
* copies or substantial portions of the Software.                                           *
*                                                                                           *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                  *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE               *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                    *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,             *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE             *
* SOFTWARE.                                                                                 *
*********************************************************************************************
*/

#pragma once

#include <stdint.h>
#include <cstring>

// Buffer is not RAII safe, you must call free before this object exits the scope.
class FBuffer
{
public:
	FBuffer() : Size( 0 ), Data( nullptr ) {}
	FBuffer( uint32_t size, uint8_t* pData ) : Size( size ), Data( pData ) {}
	FBuffer( uint32_t size, void* pData ) : Size( size ), Data( ( uint8_t* ) pData ) {}
	~FBuffer() {}

	void Zero_Memory()
	{
		if( Data )
			std::memset( Data, 0, Size );
	}

	void Free()
	{
		if( Data )
		{
			delete[] Data;
			Data = nullptr;
			Position = Size = 0;
		}
	}

	template<typename Ty>
	Ty& Read()
	{
		Position += sizeof( Ty );
		return *( Ty* ) ( Data + ( Position - sizeof( Ty ) ) );
	}

	void Read( char* String, uint32_t size )
	{
		Position += size;
		String = ( char* ) ( Data + ( Position - size ) );
	}

	template<typename NType>
	void SkipN( NType n )
	{
		Position += n;
	}

	template<typename Ty>
	Ty* As()
	{
		return ( Ty* ) Data;
	}

	void Write( const void* pData, size_t size )
	{
		XY_CORE_ASSERT( Position + size <= Size );

		std::memcpy( Data + Position, pData, size );
		Position += size;
	}

	// Clears the buffer and then reallocates it to the specified size.
	void Allocate( size_t size )
	{
		delete[] Data;
		Data = nullptr;

		if( size == 0 )
			return;

		Data = new uint8_t[ size ];
		Size = size;
	}

	static FBuffer Copy( const void* pData, size_t size )
	{
		FBuffer buffer;

		// Allocate the buffer
		buffer.Allocate( size );

		std::memcpy( buffer.Data, pData, size );

		return buffer;
	}

	operator bool() { return Data != nullptr; }
	uint8_t& operator [] ( uint32_t Offset ) { return Data[ Offset ]; }
	uint8_t operator [] ( uint32_t Offset ) const { return Data[ Offset ]; }

public:
	size_t Size = 0u;
	size_t Position = 0u;
	uint8_t* Data = nullptr;
};
