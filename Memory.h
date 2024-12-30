#pragma once
#include <windows.h>
#include <cstddef>
#include <cstdint>
#undef ZeroMemory
class default_t
{
public:
	template<typename T>
	operator T() const { return T(); }
};
default_t const defaultt = default_t();
#define NP(type) type nonptr = defaultt; if(!this) return nonptr;
namespace dxmm::memory
{
	constexpr std::uintptr_t MinimumUserAddress = 0x0000000000010000;
	constexpr std::uintptr_t MaximumUserAddress = 0x00007FFFFFFFFFFF;
	constexpr std::uintptr_t MinimumSystemAddress = 0x8000000000000000;
	std::uintptr_t ToAddress(const void* pointer);

	void* ToPointer(std::uintptr_t address);

	const void* ToConstantPointer(std::uintptr_t address);

	bool IsUserAddress(std::uintptr_t address);

	bool IsUserAddress(const void* pointer);

	bool IsSystemAddress(std::uintptr_t address);

	bool IsSystemAddress(const void* pointer);

	bool IsAddressValid(std::uintptr_t address);

	bool IsAddressValid(const void* pointer);

	bool IsValidCheck(void* m_pPointer);

	bool IsValidPointer(__int64 m_pPointer);
	


	template< typename Type, typename PointerType >
	inline Type& Dereference(__int64 address)
	{
		return *(Type*)(address);
	}
	template<typename T = uintptr_t, typename A>
	T& Read(A address) {
		auto addresss = (DWORD64)address;
		if (addresss > 0x40000 && (addresss + sizeof(T)) < 0x7FFFFFFF0000)
			return *(T*)addresss;

		auto n = nullptr;
		return reinterpret_cast<T&>(n);
	}
	template <typename T>
	void Write(uintptr_t address, T data) {
		if (address > 0x40000 && (address + sizeof(T)) < 0x7FFFFFFF0000)
			*(T*)(address) = data;
	}
	template< typename T, typename... ArgPack >
	__forceinline T Call(std::uintptr_t address, ArgPack... arg_pack)
	{
		using Fn = T(*)(ArgPack...);
		const auto procedure = reinterpret_cast<Fn>(address);
		return procedure(arg_pack...);
	}

	template< std::size_t N, typename T = std::uintptr_t >
	__forceinline T GetVirtualAddress(void* object)
	{
		if (!dxmm::memory::IsAddressValid(object))
			return { };

		const auto procedure_array = *reinterpret_cast<std::uintptr_t**>(object);

		if (!dxmm::memory::IsAddressValid(procedure_array))
			return { };

		return T(procedure_array[N]);
	}

	template< std::size_t N, typename T, typename... ArgPack >
	__forceinline T CallVirtual(void* object, ArgPack... arg_pack)
	{
		using Fn = T(__thiscall*)(void*, ArgPack...);

		const auto procedure = GetVirtualAddress< N, Fn >(object);
		return procedure(object, arg_pack...);
	}


	void ZeroMemory(void* dest, std::size_t size);

	const void* memchr(const void* data, int value, std::size_t size);
	int memcmp(const void* source, const void* destination, std::size_t size);
	void* memcpy(void* destination, const void* source, std::size_t size);
	void* memmove(void* destination, const void* source, std::size_t size);
	void* memset(void* destination, int value, std::size_t size);

	PBYTE scan(const char* Pattern, const wchar_t* Module = nullptr);
	uintptr_t absolute(uintptr_t address, int offset, int size);
}
#pragma function( DWORD64 )
typedef unsigned __int64  DWORD64;
const void* memchr(const void* data, int value, std::size_t size);
int memcmp(const void* source, const void* destination, std::size_t size);
void* memcpy(void* destination, const void* source, std::size_t size);
void* memmove(void* destination, const void* source, std::size_t size);
void* memset(void* destination, int value, std::size_t size);

#define FIELD(field_path,name,type) type& name() { \
		NP(type) \
		static auto off = field_path; \
		return dxmm::memory::Read<type>((__int64)this + off); }
