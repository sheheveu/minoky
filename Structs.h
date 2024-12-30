#pragma once
class FonterapiIl2cppDavidTuev {
public:
	void* font;
	UnityEngine::GUISkin* skin;
	FonterapiIl2cppDavidTuev() {
		font = nullptr;
		skin = 0;
	}
	FonterapiIl2cppDavidTuev(void* fonttersizer, UnityEngine::GUISkin* skinname228) {
		font = fonttersizer;
		skin = skinname228;
	}
};
FonterapiIl2cppDavidTuev fluentpixelfont;
FonterapiIl2cppDavidTuev disconnectwtffontuploadtoyoutube;
struct Image {
public:
    Vec2 size;
    void* image;
    bool enable;
    Image() {
        image = nullptr;
        size = Vec2();
        enable = false;
    }
    Image(void* kartinka, Vec2 sizekartinky,bool kartinkavklychina) {
        image = kartinka;
        size = sizekartinky;
        enable = kartinkavklychina;
    }
};
color_t RGBA(float speed = 0.0008f)
{
	static int cases = 0;
	static float r = 1.00f, g = 0.00f, b = 1.00f;
	switch (cases) {
	case 0: { r -= speed; if (r <= 0) cases += 1; break; }
	case 1: { g += speed; b -= speed; if (g >= 1) cases += 1; break; }
	case 2: { r += speed; if (r >= 1) cases += 1; break; }
	case 3: { b += speed; g -= speed; if (b >= 1) cases = 0; break; }
	default: { r = 1.00f; g = 0.00f; b = 1.00f; break; }
	}

	return color_t(r * 255, g * 255, b * 255, 255.f);
}

enum class EventType : int {
	MouseDown = 0,
	MouseUp = 1,
	MouseDrag = 3,
	KeyDown = 4,
	KeyUp = 5,
	Repaint = 7
};

namespace other
{
    constexpr unsigned long long workbench1 = 2561955800;
    constexpr unsigned long long workbench2 = 601265145;
    constexpr unsigned long long workbench3 = 2764275075;
    constexpr unsigned long long toolcupboard = 247697047;
    constexpr unsigned long long droppeditem1 = 545786656;
    constexpr unsigned long long droppeditem2 = 3255145925;
    constexpr unsigned long long backpack = 1519640547;
    constexpr unsigned long long corpse1 = 2400390439;
    constexpr unsigned long long corpse2 = 3842948583;
    constexpr unsigned long long corpse3 = 1236143239;
    constexpr unsigned long long corpse4 = 2604534927;
    constexpr unsigned long long corpse5 = 391715894;

} // namespace other

namespace player {
    constexpr unsigned long long player = 4108440852ULL;
    constexpr unsigned long long scarecrow = 3473349223ULL;
    constexpr unsigned long long scientistnpc_arena = 3430609603ULL;
    constexpr unsigned long long scientistnpc_cargo = 3623670799ULL;
    constexpr unsigned long long scientistnpc_cargo_turret_any = 1639447304ULL;
    constexpr unsigned long long scientistnpc_cargo_turret_lr300 = 881071619ULL;
    constexpr unsigned long long scientistnpc_ch47_gunner = 1017671955ULL;
    constexpr unsigned long long scientistnpc_excavator = 4293908444ULL;
    constexpr unsigned long long scientistnpc_full_any = 1539172658ULL;
    constexpr unsigned long long scientistnpc_full_lr300 = 3763080634ULL;
    constexpr unsigned long long scientistnpc_full_mp5 = 3595426380ULL;
    constexpr unsigned long long scientistnpc_full_pistol = 712785714ULL;
    constexpr unsigned long long scientistnpc_full_shotgun = 1410044857ULL;
    constexpr unsigned long long scientistnpc_heavy = 1536035819ULL;
    constexpr unsigned long long scientistnpc_junkpile_pistol = 2066159302ULL;
    constexpr unsigned long long scientistnpc_oilrig = 548379897ULL;
    constexpr unsigned long long scientistnpc_patrol = 4272904018ULL;
    constexpr unsigned long long scientistnpc_peacekeeper = 2390854225ULL;
    constexpr unsigned long long scientistnpc_roam_nvg_variant = 4134517186ULL;
    constexpr unsigned long long scientistnpc_roam = 4199494415ULL;
    constexpr unsigned long long scientistnpc_roamtethered = 529928930ULL;
    constexpr unsigned long long npc_tunneldweller = 732025282ULL;
    constexpr unsigned long long npc_bandit_guard = 412745708ULL;
    constexpr unsigned long long npc_underwaterdweller = 1605597847ULL;
}

namespace vehicles
{
    constexpr unsigned long long rhib = 2226588638;
    constexpr unsigned long long rowboat = 1283317166;
    constexpr unsigned long long tugboat = 268742921;
    constexpr unsigned long long horse = 2421623959;
    constexpr unsigned long long mini = 2278499844;
    constexpr unsigned long long scrap = 3484163637;
    constexpr unsigned long long airballoon = 3111236903;
    constexpr unsigned long long submarinesolo = 3623991100;
    constexpr unsigned long long submarineduo = 903349679;
    constexpr unsigned long long bradleyapc = 1456850188;
    constexpr unsigned long long patrolheli = 3029415845;
    constexpr unsigned long long chinook = 1514383717;
}
namespace ore {
    constexpr unsigned long long metal = 3774647716ULL;
    constexpr unsigned long long metal2 = 3345228353ULL;
    constexpr unsigned long long metal3 = 4225479497ULL;
    constexpr unsigned long long metal4 = 3327726152ULL;
    constexpr unsigned long long sulfur = 3058967796ULL;
    constexpr unsigned long long sulfur2 = 152562243ULL;
    constexpr unsigned long long sulfur3 = 2204178116ULL;
    constexpr unsigned long long sulfur4 = 1227527004ULL;
    constexpr unsigned long long stone = 4124824587ULL;
    constexpr unsigned long long stone2 = 960501790ULL;
    constexpr unsigned long long stone3 = 723721358ULL;
    constexpr unsigned long long stone4 = 266547145ULL;
}

namespace dl
{
    constexpr unsigned long long droppeditem1 = 545786656;
    constexpr unsigned long long droppeditem2 = 3255145925;

}

namespace animals
{
    constexpr unsigned long long bear = 1799741974ULL;
    constexpr unsigned long long polarBear = 749308997ULL;
    constexpr unsigned long long boar = 502341109ULL;
    constexpr unsigned long long chicken = 152398164ULL;
    constexpr unsigned long long stag = 1378621008ULL;
    constexpr unsigned long long wolf = 2144238755ULL;
    constexpr unsigned long long zombie = 2805320019ULL;
} // namespace animals


namespace collectable
{
    constexpr unsigned long long hemp = 3006540952ULL;
    constexpr unsigned long long mushroom1 = 2697239269ULL;
    constexpr unsigned long long mushroom2 = 178882626ULL;
    constexpr unsigned long long pumpkin = 2251957318ULL;
    constexpr unsigned long long corn = 3019211920ULL;
    constexpr unsigned long long berry_white = 1989241797ULL;
    constexpr unsigned long long berry_black = 3408978181ULL;
    constexpr unsigned long long berry_blue = 2764599810ULL;
    constexpr unsigned long long berry_yellow = 3056106441ULL;
    constexpr unsigned long long berry_red = 1378329388ULL;
    constexpr unsigned long long berry_green = 3306182606ULL;
    constexpr unsigned long long potato = 726972295ULL;
    constexpr unsigned long long collectSulfur = 2972237931ULL;
    constexpr unsigned long long collectStone = 2422310333ULL;
    constexpr unsigned long long collectWood = 2107058515ULL;
    constexpr unsigned long long collectMetal = 4060169083ULL;
} // namespace collectable


namespace radtown
{
    constexpr unsigned long long barrel1 = 966676416ULL;
    constexpr unsigned long long barrel2 = 555882409ULL;
    constexpr unsigned long long barrel_1 = 3364121927ULL;
    constexpr unsigned long long barrel_2 = 3269883781ULL;
    constexpr unsigned long long barrel_oil = 3438187947ULL;
    constexpr unsigned long long crate_basic = 1603759333ULL;
    constexpr unsigned long long crate_elite = 3286607235ULL;
    constexpr unsigned long long crate_mine = 1071933290ULL;
    constexpr unsigned long long crate_normal = 2857304752ULL;
    constexpr unsigned long long crate_normal2 = 1546200557ULL;
    constexpr unsigned long long crate_normal_food = 2066926276ULL;
    constexpr unsigned long long crate_normal_medical = 1791916628ULL;
    constexpr unsigned long long crate_tools = 1892026534ULL;
    constexpr unsigned long long crate_underwater_advanced = 2803512399ULL;
    constexpr unsigned long long crate_underwater_basic = 3852690109ULL;
    constexpr unsigned long long crate_bradley = 1737870479ULL;
    constexpr unsigned long long crate_heli = 1314849795ULL;
    constexpr unsigned long long crate_food = 2896170989ULL;
    constexpr unsigned long long airdrop = 3632568684ULL;
} // namespace radtown

namespace traps
{
    constexpr unsigned long long autoturret = 3312510084;
    constexpr unsigned long long flameturret = 4075317686;
    constexpr unsigned long long guntrap = 1348746224;
    constexpr unsigned long long samStatic = 1102446446344;
    constexpr unsigned long long samDeployed = 1101571403615;
    constexpr unsigned long long landdmine = 1463807579;
    constexpr unsigned long long beartrap = 922529517;
} // namespace traps