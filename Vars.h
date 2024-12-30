
#pragma once
Vec3 ManipulationAngle = Vec3::Zero();
Vec3 MeleeEyePos = Vec3::Zero();
class BasePlayer;
class ModelState;
class Weapon;
class BaseProjectile;

class Vec3;
class color_t;
class Item;
class Shader;
class Material;
Vec3 EyePos = Vec3::Zero();
Item* ActiveWeapon = NULL;
BaseProjectile* HeldEntity_ = NULL;
Vec3 CachedBulletTPPosition;
bool BulletTPPointVisible = false;
bool PointVisible = false;
Vec3 TempCachedPoint;
Vec3 CachedManipPoint;
Vec3 BulletTPAngle;
bool PositionVisible = false;
Vec3 BTPSeperator;
__int64 lastProjectile = 0;
Vec2 screen_size = { 0, 0 };
float flyhackDistanceVerticalMax = 0.f;
float flyhackDistanceHorizontalMax = 0.f;

Vec2 screen_center = { 0, 0 };
bool isInAir = false;
float flyhackDistanceVertical = 0.0f;
float flyhackDistanceHorizontal = 0.0f;
float flyhackPauseTime = 0.0f;
bool Manipulating = false;
bool Debugging = false;
bool Flying = false;
bool iFlying = false;
bool PSilenting = false;
bool aimbotting = false;
bool TeleportingToPlayersHead = false;
bool AutoShooting = false;
bool FakeShooting = false;
bool Zooming = false;
bool OnLaddering = false; 
bool TrashEsp = false;
bool SuicideE = false;
bool AutoLooting = false;

bool SilentStashing = false;
bool KeepTargeting = false;
bool OverridingSpeed = false;
bool ToggleFriend = false;
bool ToggleEnemy = false;
bool HotKey_PSilenting = false;
bool HotKey_Aimboting = false;
bool HotKey_Suicide = false;
bool HotKey_OnLaddering = false;

bool HotKey_Looting = false;
bool HotKeyDebugging = false;
bool HotKeyFlying = false;

bool HotKey_KeepTarget = false;
bool HotKey_Manipulation = false;
bool HotKey_AutoShoot = false;
bool HotKey_SilentStash = false;
bool HotKey_Zoom = false;
bool ProjectileShootInited = false;
bool ProjectileAttackInited = false;
bool isPredicted = false;
bool CanBhopJump = false;
float MyrepeatDelay;
bool DidPredict = false;
bool InstantHitReady = false;
int InitialDistanceDebug = 0;
Vec3 InitialVelocityDebug;



namespace Vars
{
	float percnetfbar = 1.f;
	float Flyx = 0.f;
	float Flyy = 0.f;

	int EspTextSize = 12;
	int WorldEspTextSize = 12;
	float GUITextSize = 12;
	bool VisState = false;
	int ActiveTab = 0;
	namespace Aim
	{
		bool HitBox[7];
		bool KeepTarget = false;
		float HitChance = 0;
		int AimFov = 90;
		int OverrideAimFov = 90;
		float AimRange = 400;
		bool AimBot = false;
		bool ishead = true;
		bool helicopter = false;
		bool pSilent = false;
		int pSilentSpread = 0;
		int aimbotSpread = 10;
		bool InitHooks = false;
		bool SilentMelee = false;

		bool DrawFov = true;
		int TargetBone = 47;
		bool Cross = 1;

		bool RecoilControlSystem = false;
		bool BodyAim = false;
		bool HeadAim = true;
		bool Smooth = false;
		float SmoothFactor = 1;

		int AimCombo = 0;
		int helicopterCombo = 0;
		int zmCombo = 0;

		bool InstaKill = false;

		bool IgnoreTeam = true;
		bool IgnoreVisible = true;
		bool IgnoreSleepers = true;
		bool IgnoreWounded = false;
		bool IgnoreNpc = true;
		bool IgnoreHeli = false;
		bool IgnoreTurrets = true;
		bool IgnoreSafeZone = true;
	}
	namespace HitBox
	{
		bool None = false;
		bool Head = false;
		bool Neck = false;
		bool Body = false;
		bool Hands = false;
		bool Legs = false;
	};

	namespace Exploits
	{
		int ManipPoints = 5;
		int MScanPoints = 50;
		bool BulletQueue = false;
		bool WaitForInstantHit = false;
		bool BulletTpExternded = false;
		bool isBulletTpExternded = false;
		bool AutoShootType[2] = { false, false };
		bool Visualize = true;
		int HitScanBone = 47;

		bool AutoShootNoAnim = false;
		bool AutoShootNoSound = false;


		int DesyncPercentage = 95;

		float DesyncDist = 0.95f;
		float MinDecync = 50;
		bool Pierce = false;
		bool ShootThroughTeammates = false;

		bool InstaHit = false;
		bool InstaHitSafeMode = true;

		int BahindWallType = 0;
		int PlayerOverride = 0;
		int BulletTpType = 0;
		int BehindWallType = 0;
		bool HeliOverride = false;
		bool HeliMagic = false;

		bool BahindWallStatus = false;

		bool PsilentBehindWall = false;

		bool BestBW = false;
		bool ScanUp = false;
		bool BehindWall = false;
		float BehindWallRange = 1.6;
		Vec3 BehindWallPos = { 0,0,0 };

		bool Manipulation = false;
		bool ShowManipulation = false;
		bool AutoStopOnManipulation = false;
		bool InstaKill = false;
		bool BulletTp = false;
		bool DrawBulletTp = false;
		bool Bestrange = false;

		bool MeleePsilent = false;
		bool UknMeme = false;
		bool FastThrow = true;

		bool AutoShoot = false;
		float AutoShootTimeSinceLastShot = 0.0;

		int CheckAngels = 12;
		int BehindWallScanStrength = 15;
		float DistanceToBulletTp = 0.20;
		int Optimisation = 7;
		float DesyncTime;

		float BulletTpDist = 2.5f;
		float test_dist = 0;

		bool stw = false;
		int stw_scans = 10;

		bool lv = false;
		bool lv_scanned = false;
		Vec3 lv_dir = Vec3::Zero();
	}
	namespace Visuals
	{
		bool DisableTrashEsp = false;
		namespace animals
		{
			namespace general
			{
				bool Enabled = false;
				bool Icons = false;
				float  Distance = 150;

			}
			namespace colors
			{
				color_t bear = color_t{ 203, 130, 255 };
				color_t polarBear = color_t{ 255, 255, 255 };
				color_t boar = color_t{ 203, 130, 255 };
				color_t chicken = color_t{ 203, 130, 255 };
				color_t stag = color_t{ 203, 130, 255 };
				color_t wolf = color_t{ 203, 130, 255 };
				color_t zombie = color_t{ 203, 130, 255 };
				color_t hors = color_t{ 203, 130, 255 };

			} 
		} 
		namespace Items
		{
			namespace general
			{
				bool weaponsEnable = false;
				bool otherEnable = false;

				color_t weapons = { 251, 7, 160 };
				color_t other = { 251, 7, 160 };

				float Distance = 300;
			} 

			namespace backpacks
			{
				bool enable = false;
				color_t color = { 255, 245, 166, 255 };

				float Distance = 300;
			}

			namespace corpses
			{
				bool enable = false;
				color_t  option = { 255, 245, 166, 255 };

				bool Name = true;
				float  Distance = 300;
			}

			namespace stashes
			{
				bool enable = false;
				bool HideOpenStashes = true;
				color_t  option = { 255, 245, 166, 255 };
				float  Distance = 200;
			} 

		}
		namespace Traps
		{

			bool Icons = true;
			bool Traps = true;
			bool Turrets = true;
			bool Enabled = false;
			bool HideInactive = false;
			bool HideAuthedTurrets = false;
			float  Distance = 100;
			namespace colors
			{
				color_t autoTurret = color_t{ 240, 56, 10 };
				color_t autoTurretAuthed = { 44, 222, 20 };
				color_t samSite = color_t{ 240, 56, 10 };
				color_t shotgunTrap = color_t{ 240, 56, 10 };
				color_t flameTurret = color_t{ 240, 56, 10 };
				color_t landmine = color_t{ 240, 56, 10 };
				color_t bearTrap = color_t{ 255, 245, 166 };

			} 
		} 
		namespace Collectibles {
			bool Icons = false;
			bool Food = false;
			bool Hemp = false;
			bool Ore = false;
			bool Enable = false;
			bool AntiClutter = false;
			float Distance = 300;
			float  MaxAnticlutterCount = 5;
			namespace colors {
				color_t food = color_t{ 130, 104, 38 };
				color_t mushroom = color_t{ 158, 121, 59 };
				color_t pumpkin = color_t{ 130, 104, 38 };
				color_t corn = color_t{ 249, 255, 89 };
				color_t potato = color_t{ 255, 191, 89 };
				color_t wood = color_t{ 125, 89, 42 };
				color_t stone = color_t{ 155, 155, 155 };
				color_t metal = color_t{ 86, 66, 50 };
				color_t sulfur = color_t{ 239, 201, 31 };
				color_t hemp = color_t{ 140, 227, 0 };
				color_t berryWhite = color_t{ 255, 255, 255 };
				color_t berryRed = color_t{ 255, 143, 143 };
				color_t berryBlue = color_t{ 77, 173, 245 };
				color_t berryBlack = color_t{ 30, 30, 30 };
				color_t berryGreen = color_t{ 30, 255, 30 };
				color_t berryYellow = color_t{ 255, 255, 0 };


			}
		}
		namespace Ore {
			bool Enable = false;
			bool Icons = true;
			bool Stone = true;
			bool Sulfur = true;
			bool Metal = true;
			bool AntiClutter = false;
			float Distance = 300;
			float  MaxAnticlutterCount = 5;
			namespace colors {

				color_t stone = color_t{ 155, 155, 155 };
				color_t sulfur = color_t{ 239, 201, 31 };
				color_t metal = color_t{ 86, 66, 50 };


			}
		}
		namespace Vehicles {
			bool Icons = false;

			bool Enable = false;
			bool AntiClutter = false;
			float Distance = 300;
			float  HeliDistance = 500;
			float  BoatDistance = 350;
			float  PatrolDistance = 1500;
			float  OtherDistance = 350;
			float  MaxAnticlutterCount = 5;
			namespace colors {
				color_t mini = color_t{ 118, 191, 255 };
				color_t attackHeli = color_t{ 118, 191, 255 };
				color_t scrapHeli = color_t{ 71, 121, 165 };
				color_t boat = color_t{ 145, 103, 48 };
				color_t rhib = color_t{ 145, 103, 48 };
				color_t tugboat = color_t{ 145, 103, 48 };
				color_t submarineSolo = color_t{ 145, 103, 48 };
				color_t submarineDuo = color_t{ 145, 103, 48 };
				color_t horse = color_t{ 88, 217, 255 };
				color_t baloon = color_t{ 79, 54, 21 };
				color_t patrol = color_t{ 211, 127, 10 };
				color_t bradley = color_t{ 211, 127, 10 };
				color_t chinook = color_t{ 211, 127, 10 };

			}
		}
		namespace RadTown {
			bool Enable = false;
			bool Icons = true;
			bool Normal = false;
			bool Military = true;
			bool Elite = true;
			bool Airdrop = true;
			bool gj = true;
			bool Tietong = false;
			bool Shiwuhezi = false;

			bool AntiClutter = false;
			float Distance = 300;
			float  MaxAnticlutterCount = 5;
			namespace colors {
				color_t barrels = color_t{ 153, 221, 255 };
				color_t crates = color_t{ 255, 255, 153 };
				color_t military = color_t{ 128, 255, 149 };
				color_t heli = color_t{ 128, 255, 149 };
				color_t elite = color_t{ 128, 255, 149 };
				color_t toolbox = color_t{ 255, 204, 179 };
				color_t foodbox = color_t{ 209, 193, 19 };
				color_t airdrop = color_t{ 255, 0, 0 };
				color_t Tietong = color_t{ 255, 255, 255 };
				color_t Shiwuhezi = color_t{ 255, 255, 255 };
			}
		}


	
		bool BulletTraces = false;
		bool Connection = false;
		bool HitMarker = false;
		bool DesyncBar = false;
		bool Workbeanch = false;
		bool VendingMachine = false;

		namespace PlayerEsp
		{
			bool LookDirection = false;
			bool ShowPlayerFlags = false;

			bool TeamID = false;

			bool ShowAmmo = false;
			bool TargetInfo = false;
			bool Radar = false;
			bool Radar_ld = false;
			bool LookingAtU = false;
			float LookingAtU_dist = 400;
			float LookingAtU_sensitivity = 5;
			int LookingAtUCombo = 0;
			bool PlayerChams = false;
			bool ClothChams = false;
			bool ArmChams = false;
			bool WeaponChams = false;
			int ChamsType = 0;
			int ClothChamsType = 0;
			int ArmChamsType = 0;
			int WeaponChamsType = 0;

			bool OOFindicators = false;
			float OOFDist = 140;

			bool MovmentLine = false;
			bool TargetLine = false;
			bool TeamEsp = false;
			bool NpcEsp = false;
			bool SleeperEsp = false;

			bool TargetHotBar = false;

			bool DistanceEsp = false;

			bool Skeleton = false;
			bool Box = false;
			int PlayerChamsType = 0;
			int BoxEsp = 0;
			bool HealthEsp;
			bool NameEsp = false;
			bool VisibleCheck = true;
			bool WeaponEsp = false;
			bool WeaponIcon = false;
		}
	}

	namespace Weapon
	{
		bool RapidFire = false;
		bool FullAuto = false;
		bool SilentReload = false;
		bool ChangeVelScale = true;
		bool OVChangeVelScale = false;
		float BulletSpeed = 1;
		float OVBulletSpeed = 1;
		bool CustomHitMat = false;

		bool LongMelee = false;
		bool NoDeployDelay = false;
		bool InstaEoka = false;
		bool NoRecoil = false;
		bool NoSpread = false;
		bool NoSway = false;
		float Recoil = 100;
		float Spread = 100;
		float pSilentSpread = 0.02;
		bool NoBob = false;
		bool NoLower = false;
		bool NoPunch = false;
		bool NoAnimation = false;
		bool NoBurst = false;

		bool FastBullet = false;
		bool FatBullet = false;
		float FatBulletValue = 0.1;
		float MeleeRadius = 2.15;
		int FireRate = 0;
	}

	namespace Misc
	{
		namespace flyhack {
			bool AbsoluteFlyHack = false;
			bool NoTerrainCollision = false;
		}

		bool AutoUpGrade = false;
		int Grade = 0;
		bool autoHeal = false;
		bool WaterMark = true;
		int Indicator = 0;
		bool Bhop = false;
		bool AlwaysHotSpot = false;
		bool HitSound = false;
		bool InteractiveFly = false;
		bool AntiInsideTerrain = false;
		int FlySpeed = 1;

		bool AutoPickupCollect = false;
		bool AutoPickupLoot = false;
		bool just_shot = false;
		float fixed_time_last_shot = 0.0f;
		bool did_reload = false;
		inline float reload_time = 0.f;
		inline bool reload_reset = false;
		inline bool reload_reset_2 = false;
		float time_since_last_shot = 0.0f;
		float time_since_last_shotauto = 0.0f;
		float rl_time = 0.0;

		bool InteractiveDebug = false;
		bool MassSuicide = false;
		bool DoorKnocker = false;

		bool BuildAsUWant = false;
		bool RayLenthChanger = false;
		float RayleighValue = 0;

		bool DrawColliders = false;
		bool FastLoot = false;
		bool NoClip = false;
		bool LockToPlayersHead = false;
		bool SpiderManBypass = false;

		bool OnLadder = false;

		bool LootTW = false;
		bool InstaRevive = false;
		bool AntiFlyKick = false;
		bool SilentStash = false;
		bool SilentTurret = false;
		bool StopRecycler = false;

		bool FakeShoot = false;

		bool FlyHackBar = true;
		float VerticalFly = 0.0f;
		float HorizontalFly = 0.0f;
		float MaxVerticalFly = 0.0f;
		float MaxHorizontalFly = 0.0f;

		bool DebugCamera = true;
		/*  bool AutoFarmStone = false;
		  bool AutoFarmMetal = false;
		  bool AutoFarmSulfur = false;*/
		bool SilentFarmOre = false;
		bool SilentFarmTree = false;
		bool RemoveCollision = false;
		bool Jesus = false;


		int AutoFarmOres = 0;
		int AutoBotMode = 0;
		int HammerSpamMode = 0;

		bool DoJump = false;
		float AutoBotJumpHeight = 5.5;

		Vec3 WalkToDir{};

		bool WalkTo = false;
		bool JitterAA = false;

		float jitter = 1;
		float jitter_speed = 10;

		float spin_speed = 70;
		float spin = 0;

		bool ShootMounted = false;
		bool OmniSprint = false;
		bool WalkOnWater = false;
		bool JumpShoot = false;

		bool capsuleHeight = false;


		bool BrightNight = false;
		bool SkyColor = false;
		bool AmbientColor = false;

		bool SkyFall = false;
		bool TimeChanger = false;
		float GameTime = 12;

		bool AspectRatio = false;
		float Aspect = 1.7;

		bool HammerSpam = false;

		bool SpiderMan = false;
		bool InfinityJump = false;
		bool AdminFlag = false;
		bool BlockCommands = false;
		bool NoFallDamage = false;

		bool PlayerFovBool = false;
		int PlayerFov = 90;

		bool PlayerZoomBool = false;
		int Zoom = 30;

		Vec3 to_path[10];
		bool tp_gotpath = false;
	}

	namespace Keys
	{
		int InteractiveDebugKey = 0;
		int InteractiveDebugType = 0;
		bool InteractiveDebugVal = 0;
		bool InteractiveDebug = false;
		bool isInteractiveDebug = false;


		int InteractiveFlyKey = 0;
		int InteractiveFlyType = 0;
		bool InteractiveFlyVal = 0;
		bool InteractiveFly = false;
		bool isInteractiveFly = false;

		int FakeShootKey = 0;
		int FakeShootType = 0;
		bool FakeShootVal = 0;
		bool FakeShoot = false;
		bool isFakeShoot = false;

		int Suicide = 0;
		int SuicideType = 0;
		bool SuicideVal = 0;
		bool Suiciding = false;
		bool IsSuicide = false;

		int AutoLoot = 0;
		int AutoLootType = 0;
		bool AutoLootVal = 0;
		bool AutoLooting = false;
		bool IsAutoLoot = false;

		int pSilent = 0;
		int pSilentType = 0;
		bool pSilentVal = 0;
		bool pSilenting = false;
		bool ispSilent = false;

		int Aimbot = 0;
		int AimbotType = 0;
		bool AimbotVal = 0;
		bool aimbotting = false;
		bool Aimboting = false;


		int TptoHead = 0;
		int TptoHeadType = 0;
		bool TptoHeadVal = 0;
		bool TptoHeading = false;
		bool isTptoHead = false;

		int OVBulletSpeed = 0;
		int OVBulletSpeedType = 0;
		bool OVBulletSpeedVal = 0;
		bool OVBulletSpeeding = false;
		bool isOVBulletSpeed = false;

		int ToggleFriend = 0;
		int ToggleFriendType = 0;
		bool ToggleFriendVal = 0;
		bool ToggleFriend_ = false;
		bool isToggleFriend = false;

		int ToggleEnemy = 0;
		int ToggleEnemyType = 0;
		bool ToggleEnemyVal = 0;
		bool ToggleEnemy_ = false;
		bool isToggleEnemy = false;

		int LTW = 0;
		int AimKey = 0;

		int ManipulationKey = 0; // InstaKill
		int ManipulationKeyType = 0; // InstaKill
		bool ManipulationVal = 0;
		bool Manip = false;
		bool isManip = false;

		int FlyKey = 0; // InstaKill
		int FlyKeyType = 0; // InstaKill
		bool FlyVal = 0;
		bool Fly = false;
		bool isFly = false;

		int InstaKillKey = 0;

		int AutoShoot = 0;
		int AutoShootType = 0;
		bool AutoShootVal = 0;
		bool AutoShooting = false;
		bool isAutoShooting = false;

		int InstaRevive = 0;
		int InstaReviveType = 0;
		bool InstaReviveVal = 0;
		bool InstaReviving = false;
		bool isInstaReviving = false;

		int VelOV = 0;
		int NoClip = 0;

		int TrashEsp = 0;
		int TrashEspType = 0;
		bool TrashEspVal = 0;
		bool TrashEsping = false;
		bool isTrashEsp = false;

		int OnLadder = 0;
		int OnLadderType = 0;
		bool OnLadderVal = 0;
		bool OnLaddering = false;
		bool isOnLadder = false;

		int Zoom = 0;
		int ZoomType = 0;
		bool ZoomVal = 0;
		bool Zooming = false;
		bool isZoom = false;

		int SilentStash = 0;
		int SilentStashType = 0;
		bool SilentStashVal = 0;
		bool SilentStashing = false;
		bool isSilentStash = false;

		int KeepTarget = 0;
		int KeepTargetType = 0;
		bool KeepTargetVal = 0;
		bool KeepTargeting = false;
		bool isKeepTarget = false;

		int SilentTurret = 0;
		// int KeepTargetKey = 0;
		int Test = 278;
		bool Testing = false;
		bool isAlready = false;
	}

	namespace Radar
	{
		Vec2 Pos{ 50,50 };
		Vec2 Size{ 200,200 };
		Vec2 old_mouse_pos;
		Vec2 mouse_pos;

		bool MouseInBox(const Vec2& pos1, const Vec2& pos2) {
			if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y)
				return false;
			if (old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y)
				return false;

			return true;
		}

		void EndWindow() {
			old_mouse_pos = mouse_pos;
		}
	}

	namespace Belt
	{
		Vec2 Pos{ 50 , 50 };
		Vec2 Size{ 475 , 75 };
		Vec2 old_mouse_pos;
		Vec2 mouse_pos;


		bool MouseInBox(const Vec2& pos1, const Vec2& pos2) {
			if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y)
				return false;
			if (old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y)
				return false;

			return true;
		}

		void EndWindow() {
			old_mouse_pos = mouse_pos;
		}
	}

	namespace Config
	{
		bool OutLineText = true;

	}

}
