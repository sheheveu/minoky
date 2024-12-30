#pragma once
#include <cstddef>

#if defined( InitializeObjectAttributes )
#undef InitializeObjectAttributes
#endif // InitializeObjectAttributes

namespace dxmm::string
{
	std::size_t strlen( const char* const string );
	std::size_t wcslen( const wchar_t* const string );

	std::size_t strnlen( const char* const string, std::size_t size );
	std::size_t wcsnlen( const wchar_t* const string, std::size_t size );

	char* strstr( const char* _Str, char const* _SubStr );

	char* strcpy( char* destination, const char* const source );
	wchar_t* wcscpy( wchar_t* destination, const wchar_t* const source );

	char* strncpy( char* destination, const char* const source, std::size_t size );
	wchar_t* wcsncpy( wchar_t* destination, const wchar_t* const source, std::size_t size );


	bool strcmpb(const char* const left, const char* const right);
	int strcmp( const char* const left, const char* const right );
	int wcscmp( const wchar_t* const left, const wchar_t* const right );

	int strncmp( const char* const left, const char* const right, std::size_t size );
	int wcsncmp( const wchar_t* const left, const wchar_t* const right, std::size_t size );

	char tolower( char character );
	wchar_t towlower( wchar_t character );

	char toupper( char character );
	wchar_t towupper( wchar_t character );

	int stricmp( const char* const left, const char* const right );
	int wcsicmp( const wchar_t* const left, const wchar_t* const right );

	int strnicmp( const char* const left, const char* const right, std::size_t size );
	int wcsnicmp( const wchar_t* const left, const wchar_t* const right, std::size_t size );
}