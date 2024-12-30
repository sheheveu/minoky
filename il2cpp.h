#pragma once
#include <Windows.h>
#include <winternl.h>


#include "XorStr.h"
#include "Crt.h"
#include "memory.h"
#include "string.h"

__int64 g_Base = 0;

typedef const char* (*il2cpp_method_get_param_name)(__int64, uint32_t);
typedef const char* (*il2cpp_method_get_name)(__int64);
typedef int(*GPC)(__int64);
typedef __int64(*AGI)(__int64);
typedef __int64(*resolve)(const char*);
typedef __int64(*Dm)();
typedef __int64(*CFN)(__int64, const char*, const char*);
typedef __int64(*Call)(__int64, __int64);
typedef __int64(*Ptr)(__int64, __int64*);
typedef __int64* (*DGA)(void*, __int64*);

namespace Il2cpp_Utils
{
	__declspec(noinline) PBYTE GetModuleBase_Wrapper(const char* ModuleName)
	{
		PPEB_LDR_DATA Ldr = ((PTEB)__readgsqword(FIELD_OFFSET(NT_TIB, Self)))->ProcessEnvironmentBlock->Ldr; void* ModBase = nullptr;
		for (PLIST_ENTRY CurEnt = Ldr->InMemoryOrderModuleList.Flink; CurEnt != &Ldr->InMemoryOrderModuleList; CurEnt = CurEnt->Flink) {
			LDR_DATA_TABLE_ENTRY* pEntry = CONTAINING_RECORD(CurEnt, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
			PUNICODE_STRING BaseDllName = (PUNICODE_STRING)&pEntry->Reserved4[0];
			if (!ModuleName || StrCmp(ModuleName, BaseDllName->Buffer, false))
				return (PBYTE)pEntry->DllBase;
		}

		return nullptr;
	}
	ULONG64 GetExport(ULONG64 hDll, const char* Name)
	{
		PIMAGE_NT_HEADERS NT_Head = (PIMAGE_NT_HEADERS)(hDll + ((PIMAGE_DOS_HEADER)hDll)->e_lfanew);
		PIMAGE_EXPORT_DIRECTORY ExportDir = (PIMAGE_EXPORT_DIRECTORY)(hDll + NT_Head->OptionalHeader.DataDirectory[0].VirtualAddress);

		for (DWORD i = 0; i < ExportDir->NumberOfNames; i++)
		{
			USHORT Ordinal = ((USHORT*)(hDll + ExportDir->AddressOfNameOrdinals))[i];
			const char* ExpName = (const char*)hDll + ((DWORD*)(hDll + ExportDir->AddressOfNames))[i];

			for (int i = 0; ExpName[i] == Name[i]; i++) if (!ExpName[i])
				return hDll + ((DWORD*)(hDll + ExportDir->AddressOfFunctions))[Ordinal];
		} return 0;
	}
}
namespace Il2cpp {
	il2cpp_method_get_param_name method_get_param_name = 0;
	il2cpp_method_get_name method_get_name = 0;
	Ptr class_get_methods = 0;
	Ptr class_get_fields = 0;
	Dm domain_get = 0;
	Dm thread_attach = 0;
	DGA domain_get_assemblies = 0;
	AGI assembly_get_image = 0;
	CFN class_from_name = 0;
	AGI field_get_offset = 0;
	Ptr field_static_get_value = 0;
	GPC method_get_param_count = 0;
	Call array_new = 0;
	resolve new_string = 0;
	AGI type_get_object = 0;
	AGI class_get_type = 0;
	resolve resolve_icall = 0;
	AGI object_new = 0;
	AGI runtime_class_init = 0;
	void Il2cppInit()
	{
		runtime_class_init = (AGI)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_runtime_class_init")));
		//std::cout << "runtime_class_init: " << runtime_class_init << std::endl;

		method_get_param_name = (il2cpp_method_get_param_name)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_method_get_param_name")));
		//std::cout << "method_get_param_name: " << method_get_param_name << std::endl;

		method_get_name = (il2cpp_method_get_name)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_method_get_name")));
		//std::cout << "method_get_name: " << method_get_name << std::endl;

		class_get_methods = (Ptr)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_class_get_methods")));
		//std::cout << "class_get_methods: " << class_get_methods << std::endl;

		class_get_fields = (Ptr)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_class_get_fields")));
		//std::cout << "class_get_fields: " << class_get_fields << std::endl;

		domain_get = (Dm)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_domain_get")));
		//std::cout << "domain_get: " << domain_get << std::endl;

		thread_attach = (Dm)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_thread_attach")));
		//std::cout << "thread_attach: " << thread_attach << std::endl;

		domain_get_assemblies = (DGA)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_domain_get_assemblies")));
		//std::cout << "domain_get_assemblies: " << domain_get_assemblies << std::endl;

		assembly_get_image = (AGI)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_assembly_get_image")));
		//std::cout << "assembly_get_image: " << assembly_get_image << std::endl;

		class_from_name = (CFN)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_class_from_name")));
		//std::cout << "class_from_name: " << class_from_name << std::endl;

		field_get_offset = (AGI)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_field_get_offset")));
		//std::cout << "field_get_offset: " << field_get_offset << std::endl;

		field_static_get_value = (Ptr)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_field_static_get_value")));
		//std::cout << "field_static_get_value: " << field_static_get_value << std::endl;

		method_get_param_count = (GPC)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_method_get_param_count")));
		//std::cout << "method_get_param_count: " << method_get_param_count << std::endl;

		array_new = (Call)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_array_new")));
		//std::cout << "array_new: " << array_new << std::endl;

		new_string = (resolve)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_string_new")));
		//std::cout << "new_string: " << new_string << std::endl;

		type_get_object = (AGI)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_type_get_object")));
		//std::cout << "type_get_object: " << type_get_object << std::endl;

		class_get_type = (AGI)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_class_get_type")));
		//std::cout << "class_get_type: " << class_get_type << std::endl;

		resolve_icall = (resolve)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_resolve_icall")));
		//std::cout << "resolve_icall: " << resolve_icall << std::endl;

		object_new = (AGI)(Il2cpp_Utils::GetExport(g_Base, xor ("il2cpp_object_new")));
		//std::cout << "object_new: " << object_new << std::endl;

	}
	__int64 Il2cppArray(__int64 klass, __int64 size) {
		__int64 arr = array_new(klass, size);
		return arr;
	}
	inline __int64 InitClass(const char* name, const char* name_space = xor("")) {
		__int64 domain = domain_get();
		__int64 nrofassemblies = 0;
		__int64* assemblies;
		assemblies = domain_get_assemblies((void*)domain, &nrofassemblies);
		for (int i = 0; i < nrofassemblies; i++) {
			__int64 img = assembly_get_image(assemblies[i]);
			__int64 kl = class_from_name(img, name_space, name);
			if (!kl) continue;
			return kl;
		}
		return 0;
	}
	__int64 TypeGetObject(const char* name_space, const char* name)	{
		auto klass = InitClass(name, name_space);
		return type_get_object(class_get_type(klass));
	}

	inline const __int64 FindType(const __int64 object) {
		auto get_type = class_get_type(object);
		return type_get_object(get_type);
	}

	__int64 GetObjectTypeNew(const char* name_space, const char* name) {
		auto klass = InitClass(name, name_space);
		return object_new(klass);
	}
	inline __int64 Method(const char* kl, const char* name, int argument_number = -1, char* arg_name = xor(""), const char* name_space = xor(""), int selected_argument = -1) {
		__int64 iter = 0;
		auto klass = InitClass(kl, name_space);
		if (dxmm::memory::IsValidPointer(klass)) {
			while (__int64 f = class_get_methods(klass, &iter)) {
				if (dxmm::memory::IsValidPointer(f)) {
					const auto st = method_get_name(f);
					if (dxmm::memory::IsValidPointer((__int64)st))
					{
						if (dxmm::string::strcmpb(st, name)) {
							if (selected_argument >= 0 && arg_name) {
								int method_count = method_get_param_count(f);
								if (selected_argument > method_count || (argument_number >= 0 && method_count != argument_number)) continue;
								const char* argname;
								if (method_count > 0) {
									argname = method_get_param_name(f, selected_argument - 1);
								}
								else argname = (char*)xor("-");
								if (!argname || !dxmm::string::strcmpb(argname, arg_name)) continue;
							}
							return f;
						}
					}
				}
			}
		}
		return 0;
	}
	__int64 Field(__int64 klass, char* field_name, bool get_offset = true) {
		__int64 out = 0;
		__int64 il2cpp_field;
		while (il2cpp_field = class_get_fields(klass, &out)) {
			char* name = (char*)dxmm::memory::Read<__int64>(il2cpp_field);
			if (!name) break;
			if (!dxmm::string::strcmpb(name, field_name)) continue;	
			if (!get_offset) return il2cpp_field;
			__int64 offset = field_get_offset(il2cpp_field);
			return offset;
		}
		return 0;
	}
	__int64 GetValue(const char* kl, char* name, bool get_offset = true) {
		auto klass = InitClass(kl);
		if (get_offset) {
			auto field_offset = Field(klass, name);
			return field_offset;
		}
		else {
			auto _field = Field(klass, name, false);
			__int64 ret;
			field_static_get_value(_field, &ret);
			return ret;
		}
		return 0;
	}
	__int64 GetOffset(const char* kl, char* name, bool get_offset = true) {
		auto klass = InitClass(kl);
		auto field_offset = Field(klass, name);
		return field_offset;
	}

	PBYTE FindPattern(const char* Pattern, const char* Module = nullptr)
	{
#define InRange(x, a, b) (x >= a && x <= b) 
#define GetBits(x) (InRange(x, '0', '9') ? (x - '0') : ((x - 'A') + 0xA))
#define GetByte(x) ((BYTE)(GetBits(x[0]) << 4 | GetBits(x[1])))
		PBYTE ModuleStart = (PBYTE)Il2cpp_Utils::GetModuleBase_Wrapper(Module); if (!ModuleStart) return nullptr;
		PIMAGE_NT_HEADERS NtHeader = ((PIMAGE_NT_HEADERS)(ModuleStart + ((PIMAGE_DOS_HEADER)ModuleStart)->e_lfanew));
		PBYTE ModuleEnd = (PBYTE)(ModuleStart + NtHeader->OptionalHeader.SizeOfImage - 0x1000); ModuleStart += 0x1000;
		PBYTE FirstMatch = nullptr;
		const char* CurPatt = Pattern;
		for (; ModuleStart < ModuleEnd; ++ModuleStart) {
			bool SkipByte = (*CurPatt == '\?');
			if (SkipByte || *ModuleStart == GetByte(CurPatt)) {
				if (!FirstMatch) FirstMatch = ModuleStart;
				SkipByte ? CurPatt += 2 : CurPatt += 3;
				if (CurPatt[-1] == 0) return FirstMatch;
			}
			else if (FirstMatch) {
				ModuleStart = FirstMatch;
				FirstMatch = nullptr;
				CurPatt = Pattern;
			}
		}

		return nullptr;
	}
}
namespace System {
	class String {
	public:
		char pad_0000[0x10];
		int len;
		wchar_t buffer[0];
		static String* newString(const char* text)
		{
			return (String*)Il2cpp::new_string(text);
		}
	};
}
__int64 Il2cpp_Hook(void* our_func, const char* function_to_hook, const char* class_to_hook, const char* name_space = xor(""), int argument_number = -1, char* argument_name = xor("")) {
	auto il2cpp_method = Il2cpp::Method(class_to_hook, function_to_hook, argument_number, argument_name, name_space);
	*reinterpret_cast<void**>(il2cpp_method) = our_func;
	return il2cpp_method;
}
__int64 HookVirtualFunction(const char* classname, const char* function_to_hook, void* our_func, const char* name_space = xor(""), int argnum = -1, char* argname = xor("")) {
	__int64 search = *reinterpret_cast<__int64*>(Il2cpp::Method(classname, function_to_hook, argnum, argname, name_space));
	__int64 table = Il2cpp::InitClass(classname, name_space);
	if (search == (__int64)our_func) return (__int64)our_func;
	for (__int64 i = table; i <= table + 0x1500; i += 0x1) {
		__int64 addr = *reinterpret_cast<__int64*>(i);
		if (addr == search) {
			*reinterpret_cast<__int64*>(i) = (__int64)our_func;
			return addr;
		}
	}
}
void QwordSwap(void* ourFunc, __int64 funcToHook, __int64& orig) {
	orig = *(__int64*)funcToHook;
	*(__int64*)(funcToHook) = (__int64)ourFunc;
}