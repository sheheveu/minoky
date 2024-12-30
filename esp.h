#pragma once

Vec3 LocalPlayerPos;

bool WorldToScreen2D(Vec3 pos, Vec2& scrm)
{

	matrix4x4 paster = dxmm::memory::Read<matrix4x4>(camera + 0x5D8);

	paster._12 = -paster._12;
	paster._13 = paster._14;

	paster._22 = -paster._22;
	paster._23 = paster._24;

	paster._32 = -paster._32;
	paster._33 = paster._34;

	paster._42 = -paster._42;
	paster._43 = paster._44;

	int заебалипастеры = screen_size.y; int умрите = screen_size.x;

	float динах = paster._14 * pos.x + paster._24 * pos.y + paster._34 * pos.z + paster._44;
	if (динах < 0.098f)  // 0.098f
	{
		scrm.x = 0;
		scrm.y = 0;
		return false;
	}
	float френдлифаер = 1 / динах;


	float еслибынеонвыбынепастили = умрите / 2 + (paster._11 * pos.x + paster._21 * pos.y + paster._31 * pos.z + paster._41) * френдлифаер * умрите / 2;
	float cmetanaymni = заебалипастеры / 2 - (paster._12 * pos.x + paster._22 * pos.y + paster._32 * pos.z  + paster._42) * френдлифаер * умрите / 2;
	
	scrm.x = еслибынеонвыбынепастили;
	scrm.y = (cmetanaymni);
	if (scrm.x >= умрите || scrm.y >= заебалипастеры || scrm.x <= 0 || scrm.y <= 0) return false;

	return true;
}
bool WorldToScreen(Vec3 pos, Vec2& scrm, Vec4& box)
{

	matrix4x4 paster = dxmm::memory::Read<matrix4x4>(camera + 0x5D8);

	paster._12 = -paster._12;
	paster._13 = paster._14;

	paster._22 = -paster._22;
	paster._23 = paster._24;

	paster._32 = -paster._32;
	paster._33 = paster._34;

	paster._42 = -paster._42;
	paster._43 = paster._44;

	int тылюбишьтанцеватьаятрахатьсвоихподружек = screen_size.y; int иниктомненикогданезапретитнассатьимсновавуши = screen_size.x;

	float сосот = paster._14 * pos.x + paster._24 * pos.y + paster._34 * pos.z + paster._44;
	if (сосот < 0.098f)  // 0.098f
	{
		scrm.x = 0;
		scrm.y = 0;
		return false;
	}
	float cupsizemoment = 1 / сосот;


	float тызнаешькакмненравитсязапахтвоеготела = иниктомненикогданезапретитнассатьимсновавуши / 2 + (paster._11 * pos.x + paster._21 * pos.y + paster._31 * pos.z + paster._41) * cupsizemoment * иниктомненикогданезапретитнассатьимсновавуши / 2;
	float этикамнивмоихджинсах = тылюбишьтанцеватьаятрахатьсвоихподружек / 2 - (paster._12 * pos.x + paster._22 * pos.y + paster._32 * (pos.z + 0) + paster._42) * cupsizemoment * тылюбишьтанцеватьаятрахатьсвоихподружек / 2;
	float Y = тылюбишьтанцеватьаятрахатьсвоихподружек / 2 - (paster._12 * pos.x + paster._22 * (pos.y + 1.8f) + paster._32 * (pos.z + 0) + paster._42) * cupsizemoment * тылюбишьтанцеватьаятрахатьсвоихподружек / 2;

	scrm.x = тызнаешькакмненравитсязапахтвоеготела;
	scrm.y = (этикамнивмоихджинсах);
	if (scrm.x >= иниктомненикогданезапретитнассатьимсновавуши || scrm.y >= тылюбишьтанцеватьаятрахатьсвоихподружек || scrm.x <= 0 || scrm.y <= 0) return false;

	box.y = Y;
	box.z = этикамнивмоихджинсах - Y;
	box.w = box.z * 0.525f;
	box.x = тызнаешькакмненравитсязапахтвоеготела - box.z / 4;

	return true;
}
void DrawSkeleton(BasePlayer* Players , color_t clr) {
	if (Vars::Visuals::PlayerEsp::Skeleton) {
		auto head_b = Players->GetTransform(head)->Position();
		auto spine4_b = Players->GetTransform(spine4)->Position();
		auto l_upperarm_b = Players->GetTransform(l_upperarm)->Position();
		auto l_forearm_b = Players->GetTransform(l_forearm)->Position();
		auto l_hand_b = Players->GetTransform(l_hand)->Position();
		auto r_upperarm_b = Players->GetTransform(r_upperarm)->Position();
		auto r_forearm_b = Players->GetTransform(r_forearm)->Position();
		auto r_hand_b = Players->GetTransform(r_hand)->Position();
		auto pelvis_b = Players->GetTransform(pelvis)->Position();
		auto l_hip_b = Players->GetTransform(l_hip)->Position();
		auto l_knee_b = Players->GetTransform(l_knee)->Position();
		auto l_foot_b = Players->GetTransform(l_foot)->Position();
		auto r_hip_b = Players->GetTransform(r_hip)->Position();
		auto r_knee_b = Players->GetTransform(r_knee)->Position();
		auto r_foot_b = Players->GetTransform(r_foot)->Position();
		auto r_toe_b = Players->GetTransform(r_toe)->Position();
		auto l_toe_b = Players->GetTransform(l_toe)->Position();
		Vec2 head, spine, l_upperarm, l_forearm, l_hand, r_upperarm, r_forearm, r_hand, pelvis, l_hip, l_knee, l_foot, r_hip, r_knee, r_foot, l_toe, r_toe;
		if (WorldToScreen2D(head_b, head) &&
			WorldToScreen2D(spine4_b, spine) &&
			WorldToScreen2D(l_upperarm_b, l_upperarm) &&
			WorldToScreen2D(l_forearm_b, l_forearm) &&
			WorldToScreen2D(l_hand_b, l_hand) &&
			WorldToScreen2D(r_upperarm_b, r_upperarm) &&
			WorldToScreen2D(r_forearm_b, r_forearm) &&
			WorldToScreen2D(r_hand_b, r_hand) &&
			WorldToScreen2D(pelvis_b, pelvis) &&
			WorldToScreen2D(l_hip_b, l_hip) &&
			WorldToScreen2D(l_knee_b, l_knee) &&
			WorldToScreen2D(l_foot_b, l_foot) &&
			WorldToScreen2D(r_hip_b, r_hip) &&
			WorldToScreen2D(r_knee_b, r_knee) &&
			WorldToScreen2D(r_toe_b, r_toe) &&
			WorldToScreen2D(l_toe_b, l_toe) &&
			WorldToScreen2D(r_foot_b, r_foot)) {
			GUI::DrawLine(head, spine, clr, 1, true);
			GUI::DrawLine(spine, l_upperarm, clr, 1, true);
			GUI::DrawLine(l_upperarm, l_forearm, clr, 1, true);
			GUI::DrawLine(l_forearm, l_hand, clr, 1, true);
			GUI::DrawLine(spine, r_upperarm, clr, 1, true);
			GUI::DrawLine(r_upperarm, r_forearm, clr, 1, true);
			GUI::DrawLine(r_forearm, r_hand, clr, 1, true);
			GUI::DrawLine(spine, pelvis, clr, 1, true);
			GUI::DrawLine(pelvis, l_hip, clr, 1, true);
			GUI::DrawLine(l_hip, l_knee, clr, 1, true);
			GUI::DrawLine(l_knee, l_foot, clr, 1, true);
			GUI::DrawLine(pelvis, r_hip, clr, 1, true);
			GUI::DrawLine(r_hip, r_knee, clr, 1, true);
			GUI::DrawLine(r_knee, r_foot, clr, 1, true);
			GUI::DrawLine(r_foot, r_toe, clr, 1, true);
			GUI::DrawLine(l_foot, l_toe, clr, 1, true);
		}
	}
}

float GetFov(Vec3 Pos) {
	Vec2 ScreenPos;
	if (!WorldToScreen2D(Pos, ScreenPos)) return 1000.f;
	return Vec2(UnityEngine::Screen::get_width() / 2, UnityEngine::Screen::get_height() / 2).distance_2d(ScreenPos);
}

Vec3 CalcAngle(const Vec3& from, const Vec3& to) {
	Vec3 dx; Vec3 angle; dx = from - to;

	angle.x = std::asin(dx.y / dxmm::math::sqrt(dx.x * dx.x + dx.y * dx.y + dx.z * dx.z)) * 180.0f / M_PI;
	angle.y = -std::atan2(dx.x, -dx.z) * 180.0f / M_PI;

	return angle;
}

void NormalizeAngle(Vec3& angle) {
	if (angle.x > 89.0f)angle.x = 89.0f;
	if (angle.x < -89.0f)angle.x = -89.0f;
	while (angle.y > 180.0f) {
		angle.y -= 360.0f;
	}
	while (angle.y < -180.0f) {
		angle.y += 360.0f;
	}
}

inline void drawFov() {
	float AimFov = Vars::Aim::OverrideAimFov * 2;;
	color_t fovColor = ColorPicker::Fov.unity();
	GUI::Rect({ (float)screen_center.x - AimFov / 2, (float)screen_center.y - AimFov / 2 }, { AimFov, AimFov }, fovColor, 999);
}
class c_getitemicon
{
public:
	Vec2 size = Vec2(0, 0);
	wchar_t* name = xor (L"");
	void* texture;

}; inline c_getitemicon getitem;
c_getitemicon get_icon_name(BasePlayer* player) {
	c_getitemicon item;
	Item* ActWeapon = player->GetHeldItem();
	switch (ActWeapon->info()->itemid())
	{
	case 442886268:
		item.texture = WeaponIcon->rocketlauncher;
		item.name = xor (L"rocketlauncher");
		item.size = Vec2(27, 11);
		break;
	case 1079279582:

		item.texture = WeaponIcon->medicalsyringe;
		item.name = xor (L"medical-syringe");
		item.size = Vec2(21, 7);
		break;
	case -2072273936:

		item.texture = WeaponIcon->heal;
		item.name = xor (L"heal");
		item.size = Vec2(21, 7);
		break;
	case 1545779598:
		item.texture = WeaponIcon->ak47;
		item.name = xor (L"ak47");
		item.size = Vec2(26, 10);
		break;
	case -1335497659:
		item.texture = WeaponIcon->ak47;
		item.name = xor (L"ak47");
		item.size = Vec2(26, 10);
		break;
	case 1318558775:

		item.texture = WeaponIcon->mp5;
		item.name = xor (L"mp5");
		item.size = Vec2(21, 9);
		break;
	case 1588298435:
		item.texture = WeaponIcon->boltactionrifle;
		item.name = xor (L"bolt-action-rifle");
		item.size = Vec2(26, 8);
		break;
	case 1965232394:
		item.texture = WeaponIcon->crossbow;
		item.name = xor (L"crossbow");
		item.size = Vec2(23, 8);
		break;
	case -41440462:
		item.texture = WeaponIcon->spas12;
		item.name = xor (L"spas-12");
		item.size = Vec2(25, 6);
		break;
	case -765183617:
		item.texture = WeaponIcon->doublebarrel;
		item.name = xor (L"double-barrel");
		item.size = Vec2(24, 6);
		break;
	case 884424049:
		item.texture = WeaponIcon->compoundbow;
		item.name = xor (L"compound-bow");
		item.size = Vec2(32, 10);
		break;
	case 1443579727:
		item.texture = WeaponIcon->huntingbow;
		item.name = xor (L"hunting-bow");
		item.size = Vec2(31, 8);
		break;
	case -852563019:
		item.texture = WeaponIcon->m92png;
		item.name = xor (L"m92");
		item.size = Vec2(18, 12);
		break;
	case -1758372725:
		item.texture = WeaponIcon->thompson;
		item.name = xor (L"thompson");
		item.size = Vec2(28, 10);
		break;
	case -904863145:
		item.texture = WeaponIcon->sarpng;
		item.name = xor (L"sar");
		item.size = Vec2(26, 9);
		break;
	case 818877484:
		item.texture = WeaponIcon->p250;
		item.name = xor (L"p250");
		item.size = Vec2(15, 12);
		break;
	case 795371088:
		item.texture = WeaponIcon->pumpshotgun;
		item.name = xor (L"pump-shotgun");
		item.size = Vec2(26, 7);
		break;
	case 649912614:
		item.texture = WeaponIcon->revolver;
		item.name = xor (L"revolver");
		item.size = Vec2(18, 12);
		break;
	case 1373971859:
		item.texture = WeaponIcon->python;
		item.name = xor (L"python");
		item.size = Vec2(21, 11);
		break;
	case -1214542497:
		item.texture = WeaponIcon->hmlmg;
		item.name = xor (L"hmlmg");
		item.size = Vec2(22, 8);
		break;
	case -75944661:
		item.texture = WeaponIcon->eoka;
		item.name = xor (L"eoka");
		item.size = Vec2(14, 8);
		break;
	case 1796682209:
		item.texture = WeaponIcon->customsmg;
		item.name = xor (L"custom-smg");
		item.size = Vec2(21, 12);
		break;
	case -1812555177:
		item.texture = WeaponIcon->lr300;
		item.name = xor (L"lr300");
		item.size = Vec2(21, 10);
		break;
	case -2069578888:
		item.texture = WeaponIcon->m249;
		item.name = xor (L"m249");
		item.size = Vec2(32, 10);
		break;
	case 28201841:
		item.texture = WeaponIcon->m39;
		item.name = xor (L"m39");
		item.size = Vec2(28, 10);
		break;
	default:
		item.texture = nullptr;
		break;
	}
	return item;
}

float MaxRange; BasePlayer* target_ply = NULL;
void DrawPlayers() {
	wchar_t buf[128];
	float Center;  MaxRange = Vars::Aim::OverrideAimFov; BasePlayer* Ctarget_ply = NULL;
	for (size_t i = 0; i < q_play.size(); i++)
	{
		BasePlayer* Players = (BasePlayer*)q_play[i];
		if (Players->lifestate() == BasePlayer::LifeState::Dead) continue;
		Vec3 Pos = Players->GetOriginPosition(); Vec2 RetPos; Vec4 Box;
		if(Players->isSleeping())continue;
		if (WorldToScreen(Pos, RetPos, Box))
		{
			color_t clr = ColorPicker::PlayerColor.unity();;
			if (Vars::Visuals::PlayerEsp::VisibleCheck)
			{ 
				EyePos = dxmm::memory::Read<Vec3>(camera + 0x454);
				clr = Physics::is_visible(EyePos, Players->GetTransform(47)->Position()) ? ColorPicker::PlayerColor.unity() : ColorPicker::PlayerColorInVisible.unity();
			}
			if (Vars::Visuals::PlayerEsp::Box)
			{
				GUI::Rect({ Box .x,Box .y}, { Box .w,Box .z}, clr);
				GUI::Rect({ Box.x - 1,Box.y - 1 } , { Box.w + 2,Box.z + 2 } , { 0, 0, 0, 255 });
				GUI::Rect({ Box.x + 1,Box.y + 1 } , { Box.w - 2,Box.z - 2 } , { 0, 0, 0, 255 });
			}
			if (Vars::Visuals::PlayerEsp::NameEsp)
			{
				GUI::DrawString({ RetPos.x ,RetPos.y - Box.z - 7 - Vars::EspTextSize }, Players->_displayName(), clr, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
			}
			if (Vars::Visuals::PlayerEsp::ShowPlayerFlags)
			{
				int Team = Players->currentTeam();
				if (Team)
				{
					GUI::FilledRect({ RetPos.x - 19 / 2,RetPos.y - Box.z - 7 - Vars::EspTextSize * 2 - 6 }, { 19,19 }, clr, 999);
					swprintf_s(buf, xor (L"%d"), Team);
					Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
					GUI::DrawString({ RetPos.x ,RetPos.y - Box.z - 7 - Vars::EspTextSize * 2 - 6 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				}
				
			}
			int Point_X = 0; bool NO = false;
			if (Vars::Visuals::PlayerEsp::WeaponEsp && Vars::Visuals::PlayerEsp::WeaponIcon) {
				
				NO = get_icon_name(Players).texture != nullptr;
				if (NO)
				{
					GUI::Image({ RetPos.x,RetPos.y + 3 }, get_icon_name(Players).size, get_icon_name(Players).texture, clr, image_flags::image_flags_align_center);
					Point_X += get_icon_name(Players).size.y;
				}
			}
			if (Vars::Visuals::PlayerEsp::WeaponIcon && !NO  || Vars::Visuals::PlayerEsp::WeaponEsp && !Vars::Visuals::PlayerEsp::WeaponIcon)
			{
				if (Vars::Visuals::PlayerEsp::WeaponEsp)
				{
					auto item = Players->GetHeldItem();
					if (item != nullptr)
					{
						const auto name = item->info()->displayName()->english();
						GUI::DrawString({ RetPos.x,RetPos.y }, name, clr, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
						Point_X += Vars::EspTextSize;
					}
				}
			}
			swprintf_s(buf, xor (L"%dm"), (int)LocalPlayerPos.distance(Pos));
			Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
			if(Vars::Visuals::PlayerEsp::DistanceEsp)GUI::DrawString({ RetPos .x,RetPos .y + Point_X }, buf, clr, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
			DrawSkeleton(Players, clr);
		}
		Center = GetFov(Players->GetTransform(47)->Position());
		if (MaxRange > Center && Physics::is_visible(EyePos, Players->GetTransform(47)->Position())) {
			MaxRange = Center;
			Ctarget_ply = Players;
		}
	}

	if (Ctarget_ply && !Ctarget_ply->GetOriginPosition().IsZero())
	{
		target_ply = Ctarget_ply;

		Vec2 screenpos2;
		if (WorldToScreen2D(target_ply->GetTransform(47)->Position(), screenpos2)) {
			if (Vars::Visuals::Connection) {
				color_t clr = ColorPicker::ConnectionRgb.unity();
				GUI::DrawLine(screen_center, screenpos2, clr, 1, true);
			}
		}
		if (Vars::Aim::AimBot && target_ply && aimbotting) {
			Vec3 xc; xc.y = 0.2f;
			Vec3 LocalAngle = LocalPlayer->input()->bodyAngles();
			Vec3 LocalPos = LocalPlayer->GetTransform(47)->Position();
			Vec3 EnemyPos = Vars::Aim::ishead ? target_ply->GetTransform(47)->Position() : target_ply->GetTransform(22)->Position() - xc;
			Vec3 Offset = CalcAngle(LocalPos, EnemyPos);
			Offset -= LocalAngle; NormalizeAngle(Offset); Offset /= Vars::Aim::aimbotSpread; Vec3 AngleToAim = LocalAngle + Offset;

			LocalPlayer->input()->bodyAngles() = AngleToAim;
		}
	}

}
void DrawAi() {
	wchar_t buf[128];

	for (size_t i = 0; i < q_ai.size(); i++)
	{
		BasePlayer* Ai = (BasePlayer*)q_ai[i];
		Vec3 Pos = Ai->GetOriginPosition(); Vec2 RetPos; Vec4 Box;
		if (WorldToScreen(Pos, RetPos, Box))
		{
			if (Vars::Visuals::PlayerEsp::Box)
			{
				GUI::Rect({ Box.x,Box.y }, { Box.w,Box.z }, ColorPicker::NpcColor.unity());
				GUI::Rect({ Box.x - 1,Box.y - 1 }, { Box.w + 2,Box.z + 2 }, { 0, 0, 0, 255 });
				GUI::Rect({ Box.x + 1,Box.y + 1 }, { Box.w - 2,Box.z - 2 }, { 0, 0, 0, 255 });
			}
			if (Vars::Visuals::PlayerEsp::NameEsp)GUI::DrawString({ RetPos.x ,RetPos.y - Box.z - 7 - Vars::EspTextSize }, xor(L"Scientists"), ColorPicker::NpcColor.unity(), text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
			swprintf_s(buf, xor (L"%dm"), (int)LocalPlayerPos.distance(Pos));
			Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
			if (Vars::Visuals::PlayerEsp::DistanceEsp)GUI::DrawString({ RetPos.x,RetPos.y }, buf, ColorPicker::NpcColor.unity(), text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
			DrawSkeleton(Ai, ColorPicker::NpcColor.unity());
		}
	}

}
void DrawTraps() {
	wchar_t buf[128];

	for (size_t i = 0; i < q_traps.size(); i++)
	{
		BaseEntity* Traps = (BaseEntity*)q_traps[i];
		Vec3 Pos = Traps->GetOriginPosition(); Vec2 RetPos; Vec4 Box;
		auto prefabID = Traps->prefabID();
		swprintf_s(buf, xor (L"%dm"), (int)LocalPlayerPos.distance(Pos));
		Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
		if (WorldToScreen(Pos, RetPos, Box))
		{
			switch (prefabID) {
			case traps::autoturret: {
				GUI::Image({ RetPos.x,RetPos.y }, { 12,12 }, WeaponIcon->autoturret, color_t{ 255, 0, 0, 255 }, image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case traps::flameturret: {
				GUI::DrawString({ RetPos.x,RetPos.y }, xor(L"Ез»рЕЪМЁ"), color_t{255, 0, 0, 255}, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case  traps::guntrap: {
				GUI::Image({ RetPos.x,RetPos.y }, { 16,14 }, WeaponIcon->shotguntrap, color_t{ 255, 0, 0, 255 }, image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y  + 12 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case traps::samDeployed: {
				
				GUI::Image({ RetPos.x,RetPos.y }, { 12,14 }, WeaponIcon->samsite, color_t{ 255, 0, 0, 255 }, image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y+ 12 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;

			}
			case traps::samStatic: {
				GUI::Image({ RetPos.x,RetPos.y }, { 12,14 }, WeaponIcon->samsite, color_t{ 255, 0, 0, 255 }, image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y  + 12 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;

			}
			case traps::landdmine: {
				GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"µШАЧ"), color_t{ 255, 0, 0, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case traps::beartrap: {
				
				GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"І¶КЮјР"), color_t{ 255, 0, 0, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			}
		}
	}

}
void DrawCorpse()
{
	wchar_t buf[128];
	for (size_t i = 0; i < q_st.size(); i++)
	{
		BaseEntity* St = (BaseEntity*)q_st[i];
		Vec3 Pos = St->GetOriginPosition(); Vec2 RetPos; Vec4 Box;
		swprintf_s(buf, xor (L"%dm"), (int)LocalPlayerPos.distance(Pos));
		Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
		if (WorldToScreen(Pos, RetPos, Box))
		{
			GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"К¬Ме°ь"), Vars::Visuals::Items::backpacks::color.unity(), text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
			GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
		}
	}
}
void DrawHemp()
{
	wchar_t buf[128];
	for (size_t i = 0; i < q_collectable.size(); i++)
	{
		BaseEntity* DM = (BaseEntity*)q_collectable[i];
		Vec3 Pos = DM->GetOriginPosition(); Vec2 RetPos; Vec4 Box;
		swprintf_s(buf, xor (L"%dm"), (int)LocalPlayerPos.distance(Pos));
		Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
		if (WorldToScreen(Pos, RetPos, Box))
		{
			GUI::Image({ RetPos.x,RetPos.y }, { 10,12 }, WeaponIcon->hemp, Vars::Visuals::Collectibles::colors::hemp.unity(), image_flags::image_flags_align_center);
			GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
		}
	}
}
void DrawAnimals()
{
	wchar_t buf[128];
	for (size_t i = 0; i < q_animals.size(); i++)
	{
		BaseEntity* dw = (BaseEntity*)q_animals[i];
		Vec3 Pos = dw->GetOriginPosition(); Vec2 RetPos; Vec4 Box;
		auto prefabID = dw->prefabID();
		swprintf_s(buf, xor (L"%dm"), (int)LocalPlayerPos.distance(Pos));
		Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
		if (WorldToScreen(Pos, RetPos, Box))
		{
			switch (prefabID) {
			case animals::bear: {
				GUI::Image({ RetPos.x,RetPos.y }, { 17,12 }, WeaponIcon->bear, Vars::Visuals::animals::colors::bear.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case animals::boar: {
				GUI::Image({ RetPos.x,RetPos.y }, { 20,12 }, WeaponIcon->hog, Vars::Visuals::animals::colors::boar.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case animals::chicken: {
				GUI::Image({ RetPos.x,RetPos.y }, { 12,13 }, WeaponIcon->chicken, Vars::Visuals::animals::colors::chicken.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 11 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case animals::polarBear: {
				GUI::Image({ RetPos.x,RetPos.y }, { 17,12 }, WeaponIcon->polarbear, Vars::Visuals::animals::colors::polarBear.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;

			}
			case animals::stag: {
				GUI::Image({ RetPos.x,RetPos.y }, { 17,12 }, WeaponIcon->deer, Vars::Visuals::animals::colors::stag.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;

			}
			case animals::wolf: {
				GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"АЗ"), Vars::Visuals::animals::colors::wolf.unity(), text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			}
		
		}
		

	}
}
void DrawRadTown()
{
	wchar_t buf[128];
	for (size_t i = 0; i < q_radtown.size(); i++)
	{
		BaseEntity* wz = (BaseEntity*)q_radtown[i];
		Vec3 Pos = wz->GetOriginPosition(); Vec2 RetPos; Vec4 Box;
		auto prefabID = wz->prefabID();
		swprintf_s(buf, xor (L"%dm"), (int)LocalPlayerPos.distance(Pos));
		Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
		if (WorldToScreen(Pos, RetPos, Box))
		{
			switch (prefabID) {
			case radtown::barrel1:
			case radtown::barrel2:
			case radtown::barrel_1:
			case radtown::barrel_2:
			case radtown::barrel_oil: {
				if (!Vars::Visuals::RadTown::Tietong)continue;
				GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"Н°"), color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case radtown::crate_basic:
			case radtown::crate_underwater_basic:
			case radtown::crate_normal2:
			case radtown::crate_normal_medical: {
				if (!Vars::Visuals::RadTown::Normal)continue;
				GUI::Image({ RetPos.x,RetPos.y }, { 14,14 }, WeaponIcon->browncrate, Vars::Visuals::RadTown::colors::crates.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 12 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case radtown::crate_normal:
			case radtown::crate_bradley:
			{
				if (!Vars::Visuals::RadTown::Military) continue;
				GUI::Image({ RetPos.x,RetPos.y }, { 23,12 }, WeaponIcon->militarycrate, Vars::Visuals::RadTown::colors::military.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 11 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case radtown::crate_heli: {
				if (!Vars::Visuals::RadTown::Military)continue;
				GUI::Image({ RetPos.x,RetPos.y }, { 23,11 }, WeaponIcon->elitecrate, Vars::Visuals::RadTown::colors::heli.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 9 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;

			}
			case radtown::crate_elite:
			case radtown::crate_underwater_advanced: {
				if (!Vars::Visuals::RadTown::Elite)continue;
				GUI::Image({ RetPos.x,RetPos.y }, { 23,11 }, WeaponIcon->elitecrate, Vars::Visuals::RadTown::colors::elite.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 9 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;

			}
			case radtown::crate_tools: {
				if (!Vars::Visuals::RadTown::gj)continue;
					GUI::Image({ RetPos.x,RetPos.y }, { 15,12 }, WeaponIcon->toolcrate, Vars::Visuals::RadTown::colors::toolbox.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 9 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case radtown::crate_food:
			case radtown::crate_normal_food: {
				if (!Vars::Visuals::RadTown::Shiwuhezi)continue;
				GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"КіОпПд"), Vars::Visuals::RadTown::colors::foodbox.unity(), text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case radtown::airdrop: {
				if (!Vars::Visuals::RadTown::Airdrop)continue;
				GUI::Image({ RetPos.x,RetPos.y }, { 14,15 }, WeaponIcon->airdrop, Vars::Visuals::RadTown::colors::airdrop.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 13 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			}

		}


	}
}
void DrawOres() 
{
	wchar_t buf[128];
	for (size_t i = 0; i < q_ore.size(); i++)
	{
		BaseEntity* ks = (BaseEntity*)q_ore[i];
		Vec3 Pos = ks->GetOriginPosition(); Vec2 RetPos; Vec4 Box;
		auto prefabID = ks->prefabID();
		swprintf_s(buf, xor (L"%dm"), (int)LocalPlayerPos.distance(Pos));
		Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
		if (WorldToScreen(Pos, RetPos, Box))
		{
			switch (prefabID) {
			case ore::stone:
			case ore::stone2:
			case ore::stone3:
			case ore::stone4: {
				if (!Vars::Visuals::Ore::Stone)continue;
				GUI::Image({ RetPos.x,RetPos.y }, { 17,12 }, WeaponIcon->stonenode, Vars::Visuals::Ore::colors::stone.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case ore::sulfur:
			case ore::sulfur2:
			case ore::sulfur3:
			case ore::sulfur4: {
				if (!Vars::Visuals::Ore::Sulfur)continue;
				GUI::Image({ RetPos.x,RetPos.y }, { 17,12 }, WeaponIcon->sulfurnode, Vars::Visuals::Ore::colors::sulfur.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case ore::metal:
			case ore::metal2:
			case ore::metal3:
			case ore::metal4: {
				if (!Vars::Visuals::Ore::Metal)continue;
				GUI::Image({ RetPos.x,RetPos.y }, { 17,12 }, WeaponIcon->metalnode, Vars::Visuals::Ore::colors::metal.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			}

		}


	}

}
void DrawVehicles()
{
	wchar_t buf[128];
	for (size_t i = 0; i < q_vehicles.size(); i++)
	{
		BaseEntity* zj = (BaseEntity*)q_vehicles[i];
		Vec3 Pos = zj->GetOriginPosition(); Vec2 RetPos; Vec4 Box;
		auto prefabID = zj->prefabID();
		swprintf_s(buf, xor (L"%dm"), (int)LocalPlayerPos.distance(Pos));
		Vec2 textSize = GUI::CalcTextSize(buf, Vars::EspTextSize);
		if (WorldToScreen(Pos, RetPos, Box))
		{
			switch (prefabID) {
			case vehicles::mini: {
				GUI::Image({ RetPos.x,RetPos.y }, { 19,11 }, WeaponIcon->minicopter, Vars::Visuals::Vehicles::colors::mini.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 9 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case vehicles::scrap: {
				GUI::Image({ RetPos.x,RetPos.y }, { 22,11 }, WeaponIcon->scrapheli, Vars::Visuals::Vehicles::colors::scrapHeli.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 9 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case vehicles::rowboat: {
				GUI::Image({ RetPos.x,RetPos.y }, { 21,7 }, WeaponIcon->rowboat, Vars::Visuals::Vehicles::colors::boat.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 7 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case vehicles::rhib: {
				GUI::Image({ RetPos.x,RetPos.y }, { 24,9 }, WeaponIcon->rhib, Vars::Visuals::Vehicles::colors::rhib.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 7 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case vehicles::tugboat: {
				GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"НПґ¬"), Vars::Visuals::Vehicles::colors::tugboat.unity(), text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case vehicles::submarinesolo: {
				GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"µҐИЛЗ±Н§"), Vars::Visuals::Vehicles::colors::submarineSolo.unity(), text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case vehicles::submarineduo: {
				GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"Л«ИЛЗ±Н§"), Vars::Visuals::Vehicles::colors::submarineDuo.unity(), text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case vehicles::patrolheli: {
				GUI::DrawString({ RetPos.x,RetPos.y }, xor (L"ОдЧ°Ц±Йэ»ъ"), Vars::Visuals::Vehicles::colors::patrol.unity(), text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				GUI::DrawString({ RetPos.x,RetPos.y + Vars::EspTextSize }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case vehicles::horse: {
				GUI::Image({ RetPos.x,RetPos.y }, { 13,12 }, WeaponIcon->horse, Vars::Visuals::Vehicles::colors::horse.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			case vehicles::airballoon: {
				GUI::Image({ RetPos.x,RetPos.y }, { 13,12 }, WeaponIcon->hotairballoon, Vars::Visuals::Vehicles::colors::baloon.unity(), image_flags::image_flags_align_center);
				GUI::DrawString({ RetPos.x,RetPos.y + 10 }, buf, color_t{ 255, 255, 255, 255 }, text_flags::text_flags_style_outline | text_flags::text_flags_align_center, Vars::EspTextSize, fluentpixelfont);
				continue;
			}
			}

		}


	}

}
void Draw() {

	if (!LocalPlayer)return;
	LocalPlayerPos = LocalPlayer->GetOriginPosition();
	if (Vars::Aim::DrawFov)drawFov();
	DrawPlayers();
	if(Vars::Visuals::PlayerEsp::NpcEsp)DrawAi();
	if(Vars::Visuals::Traps::Enabled)DrawTraps();
	if (Vars::Visuals::Items::corpses::enable)DrawCorpse();
	if (Vars::Visuals::Collectibles::Hemp)DrawHemp();
	if (Vars::Visuals::animals::general::Enabled)DrawAnimals();
	if (Vars::Visuals::RadTown::Enable)DrawRadTown();
	if (Vars::Visuals::Ore::Enable)DrawOres();
	if (Vars::Visuals::Vehicles::Enable)DrawVehicles();
}