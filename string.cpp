#include "string.h"

namespace dxmm::string
{
	std::size_t strlen( const char* const string )
	{
		std::size_t length = 0;

		while ( string[ length ] != '\0' )
			length++;

		return length;
	}

	std::size_t wcslen( const wchar_t* const string )
	{
		std::size_t length = 0;

		while ( string[ length ] != L'\0' )
			length++;

		return length;
	}

	std::size_t strnlen( const char* const string, std::size_t size )
	{
		for ( std::size_t i = 0; i < size; i++ )
		{
			if ( string[ i ] == '\0' )
				return i;
		}

		return size;
	}

	std::size_t wcsnlen( const wchar_t* const string, std::size_t size )
	{
		for ( std::size_t i = 0; i < size; i++ )
		{
			if ( string[ i ] == L'\0' )
				return i;
		}

		return size;
	}
	unsigned int m_wcslen(const wchar_t* str)
	{
		int cnt = 0;
		if (!str)
			return 0;
		for (; *str != '\0'; ++str)
			++cnt;

		return cnt;
	}

	char* strstr( const char* _Str, char const* _SubStr )
	{
		const char* bp = _SubStr;
		const char* back_pos;
		while ( *_Str != 0 && _Str != 0 && _SubStr != 0 )
		{
			back_pos = _Str;
			while ( tolower( *back_pos++ ) == tolower( *_SubStr++ ) )
			{
				if ( *_SubStr == 0 )
				{
					return ( char* ) ( back_pos - strlen( bp ) );
				}
			}
			++_Str;
			_SubStr = bp;
		}
		return 0;
	}

	char* strcpy( char* destination, const char* const source )
	{
		for ( std::size_t i = 0; source[ i ] != '\0'; i++ )
			destination[ i ] = source[ i ];

		return destination;
	}

	wchar_t* wcscpy( wchar_t* destination, const wchar_t* const source )
	{
		for ( std::size_t i = 0; source[ i ] != L'\0'; i++ )
			destination[ i ] = source[ i ];

		return destination;
	}

	char* strncpy( char* destination, const char* const source, std::size_t size )
	{
		for ( std::size_t i = 0; i < size; i++ )
		{
			if ( source[ i ] == '\0' )
				break;

			destination[ i ] = source[ i ];
		}

		return destination;
	}

	wchar_t* wcsncpy( wchar_t* destination, const wchar_t* const source, std::size_t size )
	{
		for ( std::size_t i = 0; i < size; i++ )
		{
			if ( source[ i ] == L'\0' )
				break;

			destination[ i ] = source[ i ];
		}

		return destination;
	}
	bool strcmpb(const char* const a, const char* const b) {

		if (!a || !b) return !a && !b;

		int ret = 0;
		unsigned char* p1 = (unsigned char*)a;
		unsigned char* p2 = (unsigned char*)b;
		while (!(ret = *p1 - *p2) && *p2)
			++p1, ++p2;

		return ret == 0;
	}
	int strcmp( const char* const left, const char* const right )
	{
		std::size_t i = 0;

		while ( left[ i ] == right[ i ] )
		{
			if ( left[ i ] == '\0' )
				return 0;

			i++;
		}

		return ( left[ i ] - right[ i ] );
	}

	int wcscmp( const wchar_t* const left, const wchar_t* const right )
	{
		std::size_t i = 0;

		while ( left[ i ] == right[ i ] )
		{
			if ( left[ i ] == L'\0' )
				return 0;

			i++;
		}

		return ( left[ i ] - right[ i ] );
	}


	int strncmp( const char* const left, const char* const right, std::size_t size )
	{
		std::size_t i = 0;

		while ( left[ i ] == right[ i ] )
		{
			if ( i >= size )
				break;

			if ( left[ i ] == '\0' )
				return 0;

			i++;
		}

		return ( left[ i ] - right[ i ] );
	}

	int wcsncmp( const wchar_t* const left, const wchar_t* const right, std::size_t size )
	{
		std::size_t i = 0;

		while ( left[ i ] == right[ i ] )
		{
			if ( i >= size )
				break;

			if ( left[ i ] == L'\0' )
				return 0;

			i++;
		}

		return ( left[ i ] - right[ i ] );
	}

	char tolower( char character )
	{
		if ( character >= 'A' && character <= 'Z' )
			return ( character - ( 'A' - 'a' ) );

		return character;
	}

	wchar_t towlower( wchar_t character )
	{
		if ( character >= L'A' && character <= L'Z' )
			return ( character - ( L'A' - L'a' ) );

		return character;
	}

	char toupper( char character )
	{
		if ( character >= 'a' && character <= 'z' )
			return ( character - ( 'a' - 'A' ) );

		return character;
	}

	wchar_t towupper( wchar_t character )
	{
		if ( character >= L'a' && character <= L'z' )
			return ( character - ( L'a' - L'A' ) );

		return character;
	}

	int stricmp( const char* const left, const char* const right )
	{
		std::size_t i = 0;

		while ( toupper( left[ i ] ) == toupper( right[ i ] ) )
		{
			if ( left[ i ] == '\0' )
				return 0;

			i++;
		}

		return ( toupper( left[ i ] ) - toupper( right[ i ] ) );
	}

	int wcsicmp( const wchar_t* const left, const wchar_t* const right )
	{
		std::size_t i = 0;

		while ( towupper( left[ i ] ) == towupper( right[ i ] ) )
		{
			if ( left[ i ] == L'\0' )
				return 0;

			i++;
		}

		return ( towupper( left[ i ] ) - towupper( right[ i ] ) );
	}

	int strnicmp( const char* const left, const char* const right, std::size_t size )
	{
		std::size_t i = 0;

		while ( toupper( left[ i ] ) == toupper( right[ i ] ) )
		{
			if ( i >= size )
				break;

			if ( left[ i ] == '\0' )
				return 0;

			i++;
		}

		return ( toupper( left[ i ] ) - toupper( right[ i ] ) );
	}

	int wcsnicmp( const wchar_t* const left, const wchar_t* const right, std::size_t size )
	{
		std::size_t i = 0;

		while ( towupper( left[ i ] ) == towupper( right[ i ] ) )
		{
			if ( i >= size )
				break;

			if ( left[ i ] == L'\0' )
				return 0;

			i++;
		}

		return ( towupper( left[ i ] ) - towupper( right[ i ] ) );
	}
}