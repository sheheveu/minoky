#pragma once


namespace offsets
{
    constexpr auto BaseNetWorkable = 0xDB0B828;
    constexpr auto MainCamera_TypeInfo = 229463832;
    constexpr auto ConsoleSystem_Index_TypeInfo = 163304768;
    constexpr auto il2cpp_gchandle_base = 0xDE54290;
    constexpr auto TOD_Sky = 0xDBB7FC8;

    constexpr auto prefabID = 0x30;

    namespace base_player
    {
        constexpr auto lifestate = 0x214;

        constexpr auto PlayerInventory = 0x630;
        constexpr auto CurrentTeam = 0x3F8;
        constexpr auto clActiveItem = 0x438;
        constexpr auto model = 0xC8;
        constexpr auto playerFlags = 0x538;
        constexpr auto _displayName = 0x2E0;
        constexpr auto PlayerInput = 0x290;
        constexpr auto PlayerEyes = 0x268;
        constexpr auto baseMovement = 0x2A0;
    }

    namespace Player_Input
    {
        constexpr auto bodyAngles = 0x44;
    }

    namespace Player_Eyes
    {
        constexpr auto BodyRotation = 0x50;
    }

    namespace model
    {
        constexpr auto boneTransforms = 0x50;
    }

    namespace player_model
    {
        constexpr auto newVelocity = 0x1EC;
        constexpr auto visible = 0x23C;
    }

    namespace player_inventory
    {
        constexpr auto containerBelt = 0x58;
        constexpr auto containerWearing = 0x30;
    }

    namespace PlayerWalkMovement
    {
        constexpr auto gravityMultiplier = 0x8C;

        constexpr auto groundAngle = 0xC8 + 8;
        constexpr auto groundAngleNew = 0xD0 + 8;

        constexpr auto groundTime = 0xDC;
        constexpr auto jumpTime = 0xE0;
        constexpr auto landTime = 0xE4;

    }

    namespace AttackEntity
    {
        constexpr auto deployDelay = 0x210;
        constexpr auto repeatDelay = 0x214;
        constexpr auto successFraction = 0x3B8;

    }

    namespace recoil
    {
        constexpr auto newRecoilOverride = 0x80;
        namespace RecoilProperties
        {
            constexpr auto ADSScale = 0x30;
        }
    }


    namespace BaseProjectile
    {
        constexpr auto automatic = 0x2b8;
        constexpr auto recoil = 0x328;

        constexpr auto aimCone = 0x320;
        constexpr auto hipAimCone = 0x324;
        constexpr auto aimconePenaltyPerShot = 0x328;
        constexpr auto aimConePenaltyMax = 0x32C;
    }

    namespace item
    {
        constexpr auto ItemList = 0x10;
        constexpr auto Items = 0x10;
        constexpr auto heldEntity = 0x88;
        constexpr auto info = 0xC0;
        constexpr auto uid = 0x70;
    }

    namespace ItemDefinition 
    {
        constexpr auto iconSprite = 0x40; 
        constexpr auto category = 0x48; 
        constexpr auto itemid = 0x20;
        constexpr auto displayName = 0x30;
        constexpr auto shortname = 0x28;
    
    }

}

uint32_t __ROR4__(uint32_t Value, uint32_t Count) {
    uint32_t ValueMask = (8 * sizeof(Value) - 1);
    Count &= ValueMask;
    return (Value >> Count) | (Value << ((ValueMask + 1 - Count) & ValueMask));
}

bool TEST_BITD(uint32_t Value, uint32_t BitPosition) {
    return (Value & (1 << BitPosition)) != 0;
}

uintptr_t Il2cppGetHandle(int32_t ObjectHandleID) {
    uint64_t rdi_1 = ((uint64_t)(ObjectHandleID >> 3));
    uint64_t rcx_1 = ((uint64_t)((ObjectHandleID & 7) - 1));
    if ((rdi_1 < dxmm::memory::Read<uint32_t>((rcx_1 * 0x28) + (g_Base + offsets::il2cpp_gchandle_base + 0x10)) && TEST_BITD(dxmm::memory::Read<uint32_t>(dxmm::memory::Read<uintptr_t>(g_Base + offsets::il2cpp_gchandle_base + (rcx_1 * 0x28)) + ((((uint64_t)rdi_1) >> 5) << 2)), (rdi_1 & 0x1f))))
    {
        uintptr_t ObjectArray = dxmm::memory::Read<uintptr_t>((rcx_1 * 0x28) + (g_Base + offsets::il2cpp_gchandle_base + 0x8)) + (rdi_1 << 3);
        if (dxmm::memory::Read<BYTE>((rcx_1 * 0x28) + (g_Base + offsets::il2cpp_gchandle_base + 0x14)) > 1)
        {
            return  dxmm::memory::Read<uintptr_t>(ObjectArray);
        }
        else
        {
            uint32_t eax = dxmm::memory::Read<uint32_t>(ObjectArray);
            eax = ~eax;
            return eax;
        }
    }
}

namespace decrypt
{
    uint64_t decrypt_uint32(uintptr_t encrypted_value)
    {
        uint64_t* v1; // rdx
        int v2;       // er8
        int v3;       // eax
        uint64_t v5;  // [rsp+0h] [rbp-18h] BYREF

        v1 = &v5;
        v2 = 2;
        memcpy(&v5, &encrypted_value, sizeof(encrypted_value));

        do {
            v3 = *(DWORD*)v1;
            v1 = (uint64_t*)((char*)v1 + 4);

            *((DWORD*)v1 - 1) = (((v3 ^ 0x56AD48A9) - 1318419260) << 11) |
                (((v3 ^ 0x56AD48A9u) - 1318419260) >> 21);

            --v2;
        } while (v2);

        return v5;

    }

    uint64_t networkable_key(uint64_t wrapper) {
        __m128* v5; // rcx
        int v7; // eax
        int v6; // edx
        __m128 v24; // [rsp+20h] [rbp-28h] BYREF
        v5 = &v24;
        v6 = 2;
        v24 = dxmm::memory::Read<__m128>(wrapper + 0x18);
        do
        {
            v7 = *(DWORD*)v5;
            v5 = (__m128*)((char*)v5 + 4);
            *((DWORD*)v5 - 1) = ((v7 - 1513729077) ^ 0xED3D74B4) + 536869201;
            --v6;
        } while (v6);
        signed __int64 v9 = *reinterpret_cast<signed __int64*>(&v24);
        return Il2cppGetHandle(v9);


    }


    uint64_t inventory_key(uint64_t pointer)
    {
        auto il2cpp_object = Il2cppGetHandle((std::int32_t)decrypt_uint32(dxmm::memory::Read<std::uint64_t>(pointer + 0x18)));
        return il2cpp_object;
    }

}