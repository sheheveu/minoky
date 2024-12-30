#pragma once
#include "Menu.h"
#include "loop.h"
#include "esp.h"

#pragma comment(linker, "/merge:.CRT=.rdata" )
#pragma comment(linker, "/merge:.pdata=.rdata" )
#pragma comment(linker, "/merge:.rdata=.text" )
#pragma comment(linker, "/merge:_RDATA=.text" )
#pragma comment(linker, "/MERGE:.rdata=INIT")
#pragma comment(linker, "/MERGE:.pdata=INIT")
#pragma comment(linker, "/MERGE:.CRT=INIT")

bool wake = true;
UnityEngine::GameObject* __go;

void* Skin = NULL;
void* Texture = NULL;
void* LabelStyle = NULL;

__int64 GetFunction(const char* modename, const char* func) {
    return Il2cpp_Utils::GetExport((__int64)Il2cpp_Utils::GetModuleBase_Wrapper(modename), func);
}

bool init() {
    static bool isInited = false;
    if (!isInited) {
        g_Base = (__int64)Il2cpp_Utils::GetModuleBase_Wrapper(xor ("GameAssembly.dll"));
        
        Il2cpp::Il2cppInit();

        __go = reinterpret_cast<UnityEngine::GameObject*>(Il2cpp::object_new(Il2cpp::InitClass(xor ("GameObject"), xor ("UnityEngine"))));
        UnityEngine::GameObject::Internal_CreateGameObject(__go, xor (L""));
        __go->AddComponent((void*)Il2cpp::TypeGetObject(xor (""), xor ("DevControls")));
        UnityEngine::Object::DontDestroyOnLoad(__go);

        isInited = true;
    }
	return isInited;
}


bool key_state[329];
bool prev_key_state[329];
void get_key_states() {
	for (int i{ 0 }; i < 329; i++) {
		prev_key_state[i] = key_state[i];
		key_state[i] = UnityEngine::Input::GetKeyInt(i);
	}
}
bool is_key_pressed(int key_code) {
	return key_state[key_code] && !prev_key_state[key_code];
}
bool is_key_held(int key_code) {
	return key_state[key_code];
}


void OnGUI(__int64 rcx) {

	entityList_loop();
	GUI::InitializeAADrawing();
	if (LineTexture) g_WhiteTexture = LineTexture;
	GUI::InitGL();
	GUI::Init();

	if (gl_material && inited) {
		static bool InitColors = false;
		if (!InitColors) {
			Vars::Visuals::animals::colors::bear = color_t{ 203.f, 130.f, 255.f };
			Vars::Visuals::animals::colors::polarBear = color_t{ 255.f, 255.f, 255.f };
			Vars::Visuals::animals::colors::boar = color_t{ 203.f, 130.f, 255.f };
			Vars::Visuals::animals::colors::chicken = color_t{ 203.f, 130.f, 255.f };
			Vars::Visuals::animals::colors::stag = color_t{ 203.f, 130.f, 255.f };
			Vars::Visuals::animals::colors::wolf = color_t{ 203.f, 130.f, 255.f };
			Vars::Visuals::animals::colors::zombie = color_t{ 203.f, 130.f, 255.f };

			Vars::Visuals::Items::general::weapons = color_t{ 251.f, 7.f, 160.f };
			Vars::Visuals::Items::general::other = color_t{ 251.f, 7.f, 160.f };

			Vars::Visuals::Items::backpacks::color = color_t{ 255.f, 245.f, 166.f, 255.f };
			Vars::Visuals::Items::corpses::option = color_t{ 255.f, 245.f, 166.f, 255.f };

			Vars::Visuals::Traps::colors::autoTurret = color_t{ 240.f, 56.f, 10.f };
			Vars::Visuals::Traps::colors::autoTurretAuthed = color_t{ 44.f, 222.f, 20.f };
			Vars::Visuals::Traps::colors::samSite = color_t{ 240.f, 56.f, 10.f };
			Vars::Visuals::Traps::colors::shotgunTrap = color_t{ 240.f, 56.f, 10.f };
			Vars::Visuals::Traps::colors::flameTurret = color_t{ 240.f, 56.f, 10.f };
			Vars::Visuals::Traps::colors::landmine = color_t{ 240.f, 56.f, 10.f };
			Vars::Visuals::Traps::colors::bearTrap = color_t{ 255.f, 245.f, 166.f };

			Vars::Visuals::Collectibles::colors::food = color_t{ 130.f, 104.f, 38.f };
			Vars::Visuals::Collectibles::colors::mushroom = color_t{ 158.f, 121.f, 59.f };
			Vars::Visuals::Collectibles::colors::pumpkin = color_t{ 130.f, 104.f, 38.f };
			Vars::Visuals::Collectibles::colors::corn = color_t{ 249.f, 255.f, 89.f };
			Vars::Visuals::Collectibles::colors::potato = color_t{ 255.f, 191.f, 89.f };
			Vars::Visuals::Collectibles::colors::wood = color_t{ 125.f, 89.f, 42.f };
			Vars::Visuals::Collectibles::colors::stone = color_t{ 155.f, 155.f, 155.f };
			Vars::Visuals::Collectibles::colors::metal = color_t{ 86.f, 66.f, 50.f };
			Vars::Visuals::Collectibles::colors::sulfur = color_t{ 239.f, 201.f, 31.f };
			Vars::Visuals::Collectibles::colors::hemp = color_t{ 140.f, 227.f, 0.f };
			Vars::Visuals::Collectibles::colors::berryWhite = color_t{ 255.f, 255.f, 255.f };
			Vars::Visuals::Collectibles::colors::berryRed = color_t{ 255.f, 143.f, 143.f };
			Vars::Visuals::Collectibles::colors::berryBlue = color_t{ 77.f, 173.f, 245.f };
			Vars::Visuals::Collectibles::colors::berryBlack = color_t{ 30.f, 30.f, 30.f };
			Vars::Visuals::Collectibles::colors::berryGreen = color_t{ 30.f, 255.f, 30.f };
			Vars::Visuals::Collectibles::colors::berryYellow = color_t{ 255.f, 255.f, 0.f };

			Vars::Visuals::Ore::colors::stone = color_t{ 155.f, 155.f, 155.f };
			Vars::Visuals::Ore::colors::sulfur = color_t{ 239.f, 201.f, 31.f };
			Vars::Visuals::Ore::colors::metal = color_t{ 86.f, 66.f, 50.f };

			Vars::Visuals::Vehicles::colors::mini = color_t{ 118.f, 191.f, 255.f };
			Vars::Visuals::Vehicles::colors::attackHeli = color_t{ 118.f, 191.f, 255.f };
			Vars::Visuals::Vehicles::colors::scrapHeli = color_t{ 71.f, 121.f, 165.f };
			Vars::Visuals::Vehicles::colors::boat = color_t{ 145.f, 103.f, 48.f };
			Vars::Visuals::Vehicles::colors::rhib = color_t{ 145.f, 103.f, 48.f };
			Vars::Visuals::Vehicles::colors::tugboat = color_t{ 145.f, 103.f, 48.f };
			Vars::Visuals::Vehicles::colors::submarineSolo = color_t{ 145.f, 103.f, 48.f };
			Vars::Visuals::Vehicles::colors::submarineDuo = color_t{ 145.f, 103.f, 48.f };
			Vars::Visuals::Vehicles::colors::horse = color_t{ 88.f, 217.f, 255.f };
			Vars::Visuals::Vehicles::colors::baloon = color_t{ 79.f, 54.f, 21.f };
			Vars::Visuals::Vehicles::colors::patrol = color_t{ 211.f, 127.f, 10.f };
			Vars::Visuals::Vehicles::colors::bradley = color_t{ 211.f, 127.f, 10.f };
			Vars::Visuals::Vehicles::colors::chinook = color_t{ 211.f, 127.f, 10.f };

			Vars::Visuals::RadTown::colors::barrels = color_t{ 153.f, 221.f, 255.f };
			Vars::Visuals::RadTown::colors::crates = color_t{ 255.f, 255.f, 153.f };
			Vars::Visuals::RadTown::colors::military = color_t{ 128.f, 255.f, 149.f };
			Vars::Visuals::RadTown::colors::heli = color_t{ 128.f, 255.f, 149.f };
			Vars::Visuals::RadTown::colors::elite = color_t{ 128.f, 255.f, 149.f };
			Vars::Visuals::RadTown::colors::toolbox = color_t{ 255.f, 204.f, 179.f };
			Vars::Visuals::RadTown::colors::foodbox = color_t{ 209.f, 193.f, 19.f };
			Vars::Visuals::RadTown::colors::airdrop = color_t{ 255.f, 255.f, 255.f };


			ColorPicker::Fov = color_t(255.f, 255.f, 255.f, 255.f);

			ColorPicker::SkyColor = color_t(255.f, 80.f, 180.f, 255.f);
			ColorPicker::AmbientColor = color_t(255.f, 80.f, 180.f, 255.f);

			ColorPicker::BulletTracer = color_t(204.f, 108.f, 231.f, 200.f);
			ColorPicker::OOFVisible = color_t(190.f, 138.f, 221.f, 255.f);

			ColorPicker::OOFInVisible = color_t(255.f, 255.f, 255.f, 255.f);
			ColorPicker::PlayerChamsVisible = color_t(220.f, 20.f, 60.f, 255.f);
			ColorPicker::PlayerChamsInVisible = color_t(127.f, 255.f, 0.f, 255.f);

			ColorPicker::HandChams2 = color_t(230.f, 31.f, 0.f, 255.f);
			ColorPicker::HandChams = color_t(127.f, 255.f, 0.f, 255.f);
			ColorPicker::ArmChamsColor = color_t{ 3.f, 221.f, 255.f, 255.f };
			ColorPicker::ClothesChamsColor = color_t{ 3.f, 221.f, 255.f, 255.f };
			ColorPicker::WeaponChamsColor = color_t{ 3.f, 221.f, 255.f, 255.f };
			ColorPicker::ChamsColor = color_t{ 3.f, 221.f, 255.f, 255.f };
			ColorPicker::ChamsColorInVisible = color_t{ 255.f, 0.f, 0.f, 255.f };
			ColorPicker::ChamsColor = color_t(230.f, 31.f, 0.f, 255.f);

			ColorPicker::PlayerColor = color_t{ 255.f, 40.f, 40.f, 255.f };
			ColorPicker::PlayerColorInVisible = color_t{ 152.f, 245.f, 249.f, 255.f };
			ColorPicker::TeammeatsColor = color_t{ 102.f, 204.f, 0.f, 255.f };
			ColorPicker::NpcColor = color_t{ 77.f, 173.f, 245.f };
			ColorPicker::SleepersColor = color_t{ 255.f, 128.f, 0.f, 255.f };
			ColorPicker::ConnectionRgb = color_t(255.f, 69.f, 0.f, 200.f);

			InitColors = true;
		}
		get_key_states();
		if (is_key_pressed(278))
			GUI::open = !GUI::open;
		static bool isManipulating = false;
		isManipulating = GUI::KeyBind(Vars::Keys::ManipulationKey, Vars::Keys::Manip, Vars::Keys::isManip, Vars::Keys::ManipulationKeyType) || Vars::Keys::ManipulationKey == 0 || Vars::Keys::ManipulationKey == 27;
		Manipulating = isManipulating;
		static bool isDebugging = false;
		isDebugging = GUI::KeyBind(Vars::Keys::InteractiveDebugKey, Vars::Keys::InteractiveDebug, Vars::Keys::isInteractiveDebug, Vars::Keys::InteractiveDebugType) || Vars::Keys::InteractiveDebugKey == 0 || Vars::Keys::InteractiveDebugKey == 27;
		Debugging = isDebugging;
		static bool isFlyinh = false;
		isFlyinh = GUI::KeyBind(Vars::Keys::InteractiveFlyKey, Vars::Keys::InteractiveFly, Vars::Keys::isInteractiveFly, Vars::Keys::InteractiveFlyType) || Vars::Keys::InteractiveFlyKey == 0 || Vars::Keys::InteractiveFlyKey == 27;
		Flying = isFlyinh;
		static bool ispSilenting = false;
		ispSilenting = GUI::KeyBind(Vars::Keys::pSilent, Vars::Keys::pSilenting, Vars::Keys::ispSilent, Vars::Keys::pSilentType) || Vars::Keys::pSilent == 0 || Vars::Keys::pSilent == 27;
		PSilenting = ispSilenting;

		static bool isaimbotting = false;
		isaimbotting = GUI::KeyBind(Vars::Keys::Aimbot, Vars::Keys::aimbotting, Vars::Keys::Aimboting, Vars::Keys::AimbotType) || Vars::Keys::Aimbot == 0 || Vars::Keys::Aimbot == 27;
		aimbotting = isaimbotting;

		static bool isTeleportingToPlayersHead = false;
		isTeleportingToPlayersHead = GUI::KeyBind(Vars::Keys::TptoHead, Vars::Keys::TptoHeading, Vars::Keys::isTptoHead, Vars::Keys::TptoHeadType) || Vars::Keys::TptoHead == 0 || Vars::Keys::TptoHead == 27;
		TeleportingToPlayersHead = isTeleportingToPlayersHead;
		static bool isAutoShooting = false;
		isAutoShooting = GUI::KeyBind(Vars::Keys::AutoShoot, Vars::Keys::AutoShooting, Vars::Keys::isAutoShooting, Vars::Keys::AutoShootType) || Vars::Keys::AutoShoot == 0 || Vars::Keys::AutoShoot == 27;
		AutoShooting = isAutoShooting;
		static bool isFakeShooting = false;
		isFakeShooting = GUI::KeyBind(Vars::Keys::FakeShootKey, Vars::Keys::FakeShoot, Vars::Keys::isFakeShoot, Vars::Keys::FakeShootType) || Vars::Keys::FakeShootKey == 0 || Vars::Keys::FakeShootKey == 27;
		FakeShooting = isFakeShooting;
		static bool isZoominging = false;
		isZoominging = GUI::KeyBind(Vars::Keys::Zoom, Vars::Keys::Zooming, Vars::Keys::isZoom, Vars::Keys::ZoomType) || Vars::Keys::Zoom == 0 || Vars::Keys::Zoom == 27;
		Zooming = isZoominging;
		static bool isOnLaddering = false;
		isOnLaddering = GUI::KeyBind(Vars::Keys::OnLadder, Vars::Keys::OnLaddering, Vars::Keys::isOnLadder, Vars::Keys::OnLadderType) || Vars::Keys::OnLadder == 0 || Vars::Keys::OnLadder == 27;
		OnLaddering = isOnLaddering;
		static bool isSuicide = false;
		isSuicide = GUI::KeyBind(Vars::Keys::Suicide, Vars::Keys::Suiciding, Vars::Keys::IsSuicide, Vars::Keys::SuicideType) || Vars::Keys::Suicide == 0 || Vars::Keys::Suicide == 27;
		SuicideE = isSuicide;
		static bool isLooting = false;
		isLooting = GUI::KeyBind(Vars::Keys::AutoLoot, Vars::Keys::AutoShooting, Vars::Keys::IsAutoLoot, Vars::Keys::AutoLootType) || Vars::Keys::AutoLoot == 0 || Vars::Keys::AutoLoot == 27;
		AutoLooting = isLooting;
		static bool isTrashEsp = false;
		isTrashEsp = GUI::KeyBind(Vars::Keys::TrashEsp, Vars::Keys::TrashEsping, Vars::Keys::isOnLadder, Vars::Keys::TrashEspType) || Vars::Keys::TrashEsp == 0 || Vars::Keys::TrashEsp == 27;
		TrashEsp = isTrashEsp;
		static bool isSilentStashing = false;
		isSilentStashing = GUI::KeyBind(Vars::Keys::SilentStash, Vars::Keys::SilentStashing, Vars::Keys::isSilentStash, Vars::Keys::SilentStashType) || Vars::Keys::SilentStash == 0 || Vars::Keys::SilentStash == 27;
		SilentStashing = isSilentStashing;
		static bool isKeepTargeting = false;
		isKeepTargeting = GUI::KeyBind(Vars::Keys::KeepTarget, Vars::Keys::KeepTargeting, Vars::Keys::isKeepTarget, Vars::Keys::KeepTargetType) || Vars::Keys::KeepTarget == 0 || Vars::Keys::KeepTarget == 27;
		KeepTargeting = isKeepTargeting;
		static bool isOverridingSpeed = false;
		isOverridingSpeed = GUI::KeyBind(Vars::Keys::OVBulletSpeed, Vars::Keys::OVBulletSpeeding, Vars::Keys::isOVBulletSpeed, Vars::Keys::OVBulletSpeedType) || Vars::Keys::OVBulletSpeed == 0 || Vars::Keys::OVBulletSpeed == 27;
		OverridingSpeed = isOverridingSpeed;
		static bool isToggleFriend = false;
		isToggleFriend = GUI::KeyBind(Vars::Keys::ToggleFriend, Vars::Keys::ToggleFriend_, Vars::Keys::isToggleFriend, Vars::Keys::ToggleFriendType) || Vars::Keys::ToggleFriend == 0 || Vars::Keys::ToggleFriend == 27;
		ToggleFriend = isToggleFriend;
		static bool isToggleEnemy = false;
		isToggleEnemy = GUI::KeyBind(Vars::Keys::ToggleEnemy, Vars::Keys::ToggleEnemy_, Vars::Keys::isToggleEnemy, Vars::Keys::ToggleEnemyType) || Vars::Keys::ToggleEnemy == 0 || Vars::Keys::ToggleEnemy == 27;
		ToggleEnemy = isToggleEnemy;

		if (UnityEngine::Event::get_current()->type == UnityEngine::Event::EventType::Repaint) {
			screen_size = { (float)UnityEngine::Screen::get_width(),(float)UnityEngine::Screen::get_height() };
			screen_center = { UnityEngine::Screen::get_width() / 2.0f, UnityEngine::Screen::get_height() / 2.0f };
			Draw();
			DrawNewMenu();
			
		}
	}
}

DWORD WINAPI Star(LPVOID lpParam) {
	if (AllocConsole()) {
		FILE* stream;
		freopen_s(&stream, xor ("CONOUT$"), xor ("w"), stdout);
		freopen_s(&stream, xor ("CONOUT$"), xor ("w"), stderr);
		std::ios::sync_with_stdio();
		if (init())
		{
		}
		else
		{
		}
		Il2cpp_Hook(&OnGUI, xor ("OnGUI"), xor ("DevControls"), xor (""), 0);
	}
	return 0;
}

bool DllMain(__int64 hmodule) {

	if (init())
	{
		Il2cpp_Hook(&OnGUI, xor ("OnGUI"), xor ("DevControls"), xor (""), 0);
		return true;
	}
	//CreateThread(NULL, 0, Star, 0, 0, 0);
	//скуф опять дал жизнь пастерам 
	//шведу пастить запрещено , поставновление в суде имеется
	//sensivity <3
	return false;
}