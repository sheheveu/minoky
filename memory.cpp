#include <windows.h>

#include "memory.h"

constexpr std::uintptr_t MinimumUserAddress = 0x0000000000010000;
constexpr std::uintptr_t MaximumUserAddress = 0x00007FFFFFFFFFFF;

constexpr std::uintptr_t MinimumSystemAddress = 0x8000000000000000;

namespace dxmm::memory
{
	std::uintptr_t ToAddress( const void* pointer )
	{
		return reinterpret_cast< std::uintptr_t >( pointer );
	}

	void* ToPointer( std::uintptr_t address )
	{
		return reinterpret_cast< void* >( address );
	}

	const void* ToConstantPointer( std::uintptr_t address )
	{
		return reinterpret_cast< const void* >( address );
	}

	bool IsUserAddress( std::uintptr_t address )
	{
		return ( address >= MinimumUserAddress &&
			address <= MaximumUserAddress );
	}

	bool IsUserAddress( const void* pointer )
	{
		const auto address = ToAddress( pointer );
		return IsUserAddress( address );
	}

	bool IsSystemAddress( std::uintptr_t address )
	{
		return ( address >= MinimumSystemAddress );
	}

	bool IsSystemAddress( const void* pointer )
	{
		const auto address = ToAddress( pointer );
		return IsSystemAddress( address );
	}

	bool IsAddressValid( std::uintptr_t address )
	{
		return IsUserAddress( address );
	}

	bool IsAddressValid( const void* pointer )
	{
		const auto address = ToAddress( pointer );
		return IsAddressValid( address );
	}

	bool IsValidCheck(void* m_pPointer)
	{
		if (reinterpret_cast<__int64>(m_pPointer) <= 0x400000 || reinterpret_cast<__int64>(m_pPointer) >= 0x7fffffffffff)
			return false;

		return true;
	}

	bool IsValidPointer(__int64 m_pPointer)
	{
		return IsValidCheck(reinterpret_cast<void*>(m_pPointer));
	}
	const void* memchr( const void* destination, int value, std::size_t size )
	{
		if ( size )
		{
			const char* p = ( const char* ) destination;
			do
			{
				if ( *p++ == value ) return ( void* ) ( p - 1 );
			} while ( --size != 0 );
		}
		return 0;
	}

	int memcmp( const void* source, const void* destination, std::size_t size )
	{
		if ( size != 0 )
		{
			const unsigned char* p1 = ( unsigned char* ) source, * p2 = ( unsigned char* ) destination;
			do
			{
				if ( *p1++ != *p2++ ) return ( *--p1 - *--p2 );
			} while ( --size != 0 );
		}
		return 0;
	}

	void* memcpy( void* destination, const void* source, std::size_t size )
	{
		char* char_dest = ( char* ) destination;
		char* char_src = ( char* ) source;
		if ( ( char_dest <= char_src ) || ( char_dest >= ( char_src + size ) ) )
		{
			while ( size > 0 )
			{
				*char_dest = *char_src;
				char_dest++;
				char_src++;
				size--;
			}
		}
		else
		{
			char_dest = ( char* ) destination + size - 1;
			char_src = ( char* ) source + size - 1;
			while ( size > 0 )
			{
				*char_dest = *char_src;
				char_dest--;
				char_src--;
				size--;
			}
		}
		return destination;
	}

	void* memmove( void* destination, const void* source, std::size_t size )
	{
		char* char_dest = ( char* ) destination;
		char* char_src = ( char* ) source;
		if ( ( char_dest <= char_src ) || ( char_dest >= ( char_src + size ) ) )
		{
			while ( size > 0 )
			{
				*char_dest = *char_src;
				char_dest++;
				char_src++;
				size--;
			}
		}
		else
		{
			char_dest = ( char* ) destination + size - 1;
			char_src = ( char* ) source + size - 1;
			while ( size > 0 )
			{
				*char_dest = *char_src;
				char_dest--;
				char_src--;
				size--;
			}
		}
		return destination;
	}

	void* memset( void* destination, int value, std::size_t size )
	{
		int           i;
		unsigned char* p = ( unsigned char* ) destination;
		i = 0;
		while ( size > 0 )
		{
			*p = value;
			p++;
			size--;
		}
		return( destination );
	}

	void ZeroMemory( void* dest, std::size_t size )
	{
		memset( dest, 0, size );
	}

	
	uintptr_t absolute( uintptr_t address, int offset, int size )
	{
		uintptr_t addrs = address + size + *( int* ) ( address + offset );
		return addrs;
	}
}

#pragma function( memchr )
const void* memchr( const void* s, int c, std::size_t n )
{
	if ( n )
	{
		const char* p = ( const char* ) s;
		do
		{
			if ( *p++ == c ) return ( void* ) ( p - 1 );
		} while ( --n != 0 );
	}
	return 0;
}

#pragma function( memcmp )
int memcmp( const void* s1, const void* s2, std::size_t n )
{
	if ( n != 0 )
	{
		const unsigned char* p1 = ( unsigned char* ) s1, * p2 = ( unsigned char* ) s2;
		do
		{
			if ( *p1++ != *p2++ ) return ( *--p1 - *--p2 );
		} while ( --n != 0 );
	}
	return 0;
}


#pragma function( memcpy )
void* memcpy( void* dest, const void* src, std::size_t count )
{
	char* char_dest = ( char* ) dest;
	char* char_src = ( char* ) src;
	if ( ( char_dest <= char_src ) || ( char_dest >= ( char_src + count ) ) )
	{
		while ( count > 0 )
		{
			*char_dest = *char_src;
			char_dest++;
			char_src++;
			count--;
		}
	}
	else
	{
		char_dest = ( char* ) dest + count - 1;
		char_src = ( char* ) src + count - 1;
		while ( count > 0 )
		{
			*char_dest = *char_src;
			char_dest--;
			char_src--;
			count--;
		}
	}
	return dest;
}

#pragma function( memmove )
void* memmove( void* destination, const void* source, std::size_t size )
{
	char* char_dest = ( char* ) destination;
	char* char_src = ( char* ) source;
	if ( ( char_dest <= char_src ) || ( char_dest >= ( char_src + size ) ) )
	{
		while ( size > 0 )
		{
			*char_dest = *char_src;
			char_dest++;
			char_src++;
			size--;
		}
	}
	else
	{
		char_dest = ( char* ) destination + size - 1;
		char_src = ( char* ) source + size - 1;
		while ( size > 0 )
		{
			*char_dest = *char_src;
			char_dest--;
			char_src--;
			size--;
		}
	}
	return destination;
}

#pragma function( memset )
void* memset( void* src, int val, std::size_t count )
{
	__stosb( ( unsigned char* ) ( ( unsigned long long )( volatile char* )src ), val, count );
	return src;
}
