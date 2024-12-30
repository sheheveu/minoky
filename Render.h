#pragma once
#include "GameClass.h"
#include "Structs.h"

#define M_PI 3.14159265358979323846
UnityEngine::Texture2D* g_WhiteTexture;
__int64 g_TestTexture;
__int64 blendMaterial = NULL;
UnityEngine::Material* gl_material = NULL;
__int64 blendMat = 0;
__int64 BlitMaterial;
__int64 BlendMaterial;
UnityEngine::Texture2D* AALineTexture;
UnityEngine::Texture2D* LineTexture;
int AALineTextureInstanceID;
int LineTextureInstanceID;
int curkey;
float menu_alpha;
float color_picker_alpha;
bool inited = false;
bool inColorPicker = false;
bool wakeup{ false };
bool sex{ false };
bool mouse_state, insert_state;
bool widget_state, old_widget_state;
bool old_mouse_state, old_insert_state;
bool is_menu_open{ true };
bool interacting;
bool main_menu_open = false;
UnityEngine::GUISkin* skin22;
UnityEngine::GUISkin* skin2;

EventType menu_event;
Vec2 widget_mouse_pos, old_widget_mouse_pos;
Vec2 window_pos{ 50, 50 }, mouse_pos, next_item_pos;
Vec2 window_sizemain;
Vec2 old_mouse_pos;
color_t MyRGB;
color_t Maincolor_t = color_t(200, 30, 30, 255);
color_t Activecolor_t = color_t(255, 60, 60, 255);

class WeaponIcons {
public:
	inline static void* p250icon;
	inline static void* medicalsyringe;
	inline static void* heal;
	inline static void* ak47;
	inline static void* mp5;
	inline static void* boltactionrifle;
	inline static void* crossbow;
	inline static void* spas12;
	inline static void* doublebarrel;
	inline static void* compoundbow;
	inline static void* huntingbow;
	inline static void* m92png;
	inline static void* thompson;
	inline static void* sarpng;
	inline static void* p250;
	inline static void* pumpshotgun;
	inline static void* revolver;
	inline static void* python;
	inline static void* hmlmg;
	inline static void* eoka;
	inline static void* customsmg;
	inline static void* lr300;
	inline static void* m249;
	inline static void* m39;
	inline static void* airdrop;
	inline static void* autoturret;
	inline static void* bear;
	inline static void* blueberry;
	inline static void* bradleyvehicle;
	inline static void* rocketlauncher;

	inline static void* bradleycrate;
	inline static void* browncrate;
	inline static void* cargoship;
	inline static void* chicken;
	inline static void* deer;
	inline static void* elitecrate;
	inline static void* greenberry;
	inline static void* hemp;
	inline static void* hog;
	inline static void* horse;
	inline static void* hotairballoon;
	inline static void* lockedcrate;
	inline static void* metalnode;
	inline static void* militarycrate;
	inline static void* minicopter;
	inline static void* mushroom;
	inline static void* polarbear;
	inline static void* potato;
	inline static void* redberry;
	inline static void* rhib;
	inline static void* rowboat;
	inline static void* samsite;
	inline static void* scrapheli;
	inline static void* shotguntrap;
	inline static void* stonenode;
	inline static void* sulfurnode;
	inline static void* toolcrate;
	inline static void* whiteberry;
	inline static void* woodcollectable;
};
WeaponIcons* WeaponIcon;
enum image_flags {
	image_flags_none = 0,
	image_flags_align_center = 1 << 0,
	image_flags_align_right = 1 << 1,
	image_flags_style_dropshadow = 1 << 2,
	image_flags_style_outline = 1 << 3,
};
enum text_flags {
	text_flags_none = 0,
	text_flags_align_center = 1 << 0,
	text_flags_align_right = 1 << 1,
	text_flags_style_dropshadow = 1 << 2,
	text_flags_style_outline = 1 << 3,
};
enum DrawListType {
	DrawType_Text = 0,
	DrawType_FilledRect = 1,
	DrawType_Rect = 2,
	DrawType_Line = 3,
	DrawType_Gradient = 4,
};

struct RenderObject {
	DrawListType Type;
	Vec2         Pos;
	Vec2         PosStart;
	Vec2         PosEnd;
	Vec2         Size;
	color_t     Color_;
	color_t     OtherColor;
	wchar_t* Text;
	bool Invertered;
	RenderObject(DrawListType Type = DrawType_Text, Vec2 Pos = Vec2(0, 0), Vec2 Size2 = Vec2(0, 0), Vec2 PosStart2 = Vec2(0, 0), Vec2 PosEnd2 = Vec2(0, 0),
		color_t color2 = color_t(255, 255, 255, 255), color_t color3 = color_t(255, 255, 255, 255),
		wchar_t* text = xor (L""), bool Vertical = false) {
		this->Type = Type;
		this->Pos = Pos;
		this->PosStart = PosStart2;
		this->PosEnd = PosEnd2;
		this->Size = Size2;
		this->Color_ = color2;
		this->OtherColor = color3;
		this->Text = text;
		this->Invertered = Vertical;
	}
};

class DrawList {
public:
	inline static void AddGradient(Vec2 Pos, Vec2 Size, color_t Color1, color_t Color2, bool Invertered);
	inline static void AddText(wchar_t* text, Vec2 position, color_t Color);
	inline static void AddFilledRect(Vec2 Pos, Vec2 Size, color_t Color);
	inline static void AddRect(Vec2 Pos, Vec2 Size, color_t Color);
};
inline MyVector<RenderObject> Drawlist;
void DrawList::AddGradient(Vec2 Pos, Vec2 Size, color_t Color1, color_t Color2, bool Invertered) {

	auto obj = RenderObject(DrawType_Gradient, Pos, Size, Vec2(0, 0), Vec2(0, 0), Color1, Color2, xor (L""), Invertered);
	Drawlist.push_back(obj);
}
void DrawList::AddText(wchar_t* text, Vec2 position, color_t Color) {
	auto obj = RenderObject(DrawType_Text, position, Vec2(0, 0), Vec2(0, 0), Vec2(0, 0), Color, Color, text, false);
	Drawlist.push_back(obj);
}
void DrawList::AddFilledRect(Vec2 Pos, Vec2 Size, color_t Color) {
	auto obj = RenderObject(DrawType_FilledRect, Pos, Size, Vec2(0, 0), Vec2(0, 0), Color, Color, xor (L""), false);
	Drawlist.push_back(obj);
}
void DrawList::AddRect(Vec2 Pos, Vec2 Size, color_t Color) {
	auto obj = RenderObject(DrawType_Rect, Pos, Size, Vec2(0, 0), Vec2(0, 0), Color, Color, xor (L""), false);
	Drawlist.push_back(obj);
}

namespace GUI {
	bool open = true;
	void InitAssets() {
		if (!Unity::MyFont) Unity::MyFont = UnityEngine::AssetBundle::LoadFromFile(xor (L"C:\\AssetsCheat"));
	}
	void Init() {
		GUI::InitAssets();
		if (Unity::MyFont) {
			WeaponIcon->medicalsyringe = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/medicalsyringe.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->heal = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/heal.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->ak47 = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/ak47.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->mp5 = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/mp5.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->boltactionrifle = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/boltactionrifle.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->crossbow = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/crossbow.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->spas12 = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/spas12.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->doublebarrel = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/doublebarrel.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->compoundbow = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/compoundbow.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->huntingbow = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/huntingbow.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->m92png = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/m92.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->thompson = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/thompson.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->sarpng = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/sar.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->p250 = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/p250.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->pumpshotgun = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/pumpshotgun.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->revolver = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/revolver.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->python = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/python.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->hmlmg = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/hmlmg.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->eoka = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/eoka.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->customsmg = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/customsmg.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->lr300 = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/lr300.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->m249 = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/m249.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->m39 = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/m39.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->airdrop = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/airdrop.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->autoturret = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/autoturret.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->bear = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/bear.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->blueberry = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/blueberry.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->rocketlauncher = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/rocketlauncher2.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->bradleyvehicle = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/bradleyvehicle.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->bradleycrate = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/bradleycrate.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->browncrate = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/browncrate.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->cargoship = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/cargoship.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->chicken = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/chicken.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->deer = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/deer.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->elitecrate = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/elitecrate.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->greenberry = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/greenberry.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->hemp = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/hemp.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->hog = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/hog.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->horse = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/horse.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->hotairballoon = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/hotairballoon.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->lockedcrate = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/lockedcrate.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->metalnode = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/metalnode.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->militarycrate = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/militarycrate.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->minicopter = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/minicopter.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->mushroom = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/mushroom.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->polarbear = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/polarbear.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->potato = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/potato.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->redberry = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/redberry.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->rhib = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/rhib.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->rowboat = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/rowboat.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->samsite = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/samsite.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->scrapheli = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/scrapheli.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->shotguntrap = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/shotguntrap.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->stonenode = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/stonenode.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->sulfurnode = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/sulfurnode.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->toolcrate = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/toolcrate.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->whiteberry = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/whiteberry.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			WeaponIcon->woodcollectable = Unity::MyFont->LoadAsset<void*>(xor (L"assets/icons/woodcollectable.png"), Type::GetType(xor (L"UnityEngine.Texture2D, UnityEngine.CoreModule")));
			void* currentFont = Unity::MyFont->LoadAsset<void*>(xor (L"assets/baloobhai2-bold.ttf"), Type::GetType(xor (L"UnityEngine.Font, UnityEngine.TextRenderingModule")));
			void* currentFont2 = Unity::MyFont->LoadAsset<void*>(xor (L"assets/baloobhai2-bold.ttf"), Type::GetType(xor (L"UnityEngine.Font, UnityEngine.TextRenderingModule")));
			fluentpixelfont = FonterapiIl2cppDavidTuev(currentFont2, skin2);
			disconnectwtffontuploadtoyoutube = FonterapiIl2cppDavidTuev(currentFont, skin22);
			UnityEngine::GUI::get_skin()->set_font(fluentpixelfont.font);
		}
	}

	void FilledRect(Vec2 position, Vec2 size, color_t color, float rounding = 0.f) {
		if (const auto whiteTexture = UnityEngine::Texture2D::get_whiteTexture()) {
			UnityEngine::Vector4 round_vec4 = UnityEngine::Vector4(0, 0, 0, 0);

			UnityEngine::GUI::DrawTexture3(UnityEngine::Rect(position.x, position.y, size.x, size.y), whiteTexture, 0, false, 0.f, *(UnityEngine::Color*)(&color), UnityEngine::Vector4(0.f, 0.f, 0.f, 0.f), UnityEngine::Vector4(rounding, rounding, rounding, rounding), true);
		}
	}
	void FilledRectR(Vec2 position, Vec2 size, color_t color, float roundingx = 0.f, float roundingy = 0.f, float roundingxd = 0.f, float roundingyd = 0.f) {
		if (const auto whiteTexture = UnityEngine::Texture2D::get_whiteTexture()) {
			UnityEngine::Vector4 round_vec4 = UnityEngine::Vector4(0, 0, 0, 0);

			UnityEngine::GUI::DrawTexture3(UnityEngine::Rect(position.x, position.y, size.x, size.y), whiteTexture, 0, false, 0.f, *(UnityEngine::Color*)(&color), UnityEngine::Vector4(0.f, 0.f, 0.f, 0.f), UnityEngine::Vector4(roundingx, roundingy, roundingxd, roundingyd), true);
		}
	}

	void Rect(Vec2 position, Vec2 size, color_t color, float rounding = 0.f) {
		if (const auto whiteTexture = UnityEngine::Texture2D::get_whiteTexture()) {
			UnityEngine::GUI::DrawTexture2(UnityEngine::Rect(position.x, position.y, size.x, size.y), whiteTexture, 0, false, 0.f, *(UnityEngine::Color*)(&color), 1.f, rounding);
		}
	}

	void MultiColorFilledRect(Vec2 position, Vec2 size, color_t colors[]) {

		gl_material->SetPass(0);

		UnityEngine::GL::PushMatrix();
		UnityEngine::GL::Begin(UnityEngine::GL::Mode::Quads);

		UnityEngine::GL::Color(UnityEngine::Color(colors[0].r, colors[0].g, colors[0].b, colors[0].a));
		UnityEngine::GL::Vertex3(position.x, position.y, 0);

		UnityEngine::GL::Color(UnityEngine::Color(colors[1].r, colors[1].g, colors[1].b, colors[1].a));
		UnityEngine::GL::Vertex3(position.x + size.x, position.y, 0);

		UnityEngine::GL::Color(UnityEngine::Color(colors[2].r, colors[2].g, colors[2].b, colors[2].a));
		UnityEngine::GL::Vertex3(position.x + size.x, position.y + size.y, 0);

		UnityEngine::GL::Color(UnityEngine::Color(colors[3].r, colors[3].g, colors[3].b, colors[3].a));
		UnityEngine::GL::Vertex3(position.x, position.y + size.y, 0);

		UnityEngine::GL::Color(UnityEngine::Color(colors[0].r, colors[0].g, colors[0].b, colors[0].a));
		UnityEngine::GL::Vertex3(position.x, position.y, 0);

		UnityEngine::GL::End();
		UnityEngine::GL::PopMatrix();
	}

	Vec2 CalcTextSize(Str text, int size) {
		const auto skin = UnityEngine::GUI::get_skin();

		if (!skin)return Vec2();
		const auto labelStyle = skin->label;
		if (!labelStyle) return Vec2();
		labelStyle->fontSize = size;
		auto result = labelStyle->CalcSize(&text);
		return Vec2(result.x, result.y);
	}

	void DrawString(Vec2 position, Str text, color_t color, int flags = text_flags::text_flags_none, int size = 10, FonterapiIl2cppDavidTuev structuresbysamoletpvtoestratkavvisualstudio = FonterapiIl2cppDavidTuev()) {
		const auto content = UnityEngine::GUIContent::Temp(&text);
		const auto skin = UnityEngine::GUI::get_skin();
		if (!skin) return;
		const auto labelStyle = skin->label;
		if (!labelStyle) return;
		labelStyle->fontSize = size;
		auto textSize = labelStyle->CalcSize(&text);
		if (flags & text_flags::text_flags_align_center) {
			position.x -= textSize.x / 2;
		}
		if (flags & text_flags::text_flags_align_right) {
			position.x -= textSize.x;
		}
		if (flags & text_flags::text_flags_style_outline) {
			UnityEngine::GUI::set_color(UnityEngine::Color(0.f, 0.f, 0.f, color.a));
			UnityEngine::GUI::Label(UnityEngine::Rect(position.x, position.y + 1, textSize.x, textSize.y), content, labelStyle);
			UnityEngine::GUI::Label(UnityEngine::Rect(position.x + 1, position.y, textSize.x, textSize.y), content, labelStyle);
			UnityEngine::GUI::Label(UnityEngine::Rect(position.x, position.y - 1, textSize.x, textSize.y), content, labelStyle);
			UnityEngine::GUI::Label(UnityEngine::Rect(position.x - 1, position.y, textSize.x, textSize.y), content, labelStyle);
		}

		if (flags & text_flags::text_flags_style_dropshadow) {
			UnityEngine::GUI::set_color(UnityEngine::Color(0.f, 0.f, 0.f, color.a));
			UnityEngine::GUI::Label(UnityEngine::Rect(position.x + 1, position.y + 1, textSize.x, textSize.y), content, labelStyle);
		}

		UnityEngine::GUI::set_color(UnityEngine::Color(color.r, color.g, color.b, color.a));
		UnityEngine::GUI::Label(UnityEngine::Rect(position.x, position.y, textSize.x, textSize.y), content, labelStyle);
	}


	void PushClipRect(Vec2 mins, Vec2 maxs, bool allow_intersections) {
		UnityEngine::GUIClip::Push(UnityEngine::Rect(mins.x, mins.y, dxmm::math::fabsf(maxs.x - mins.x), dxmm::math::fabsf(maxs.y - mins.y)), UnityEngine::Vector2(), UnityEngine::Vector2(), false);
	}

	void PopClipRect() {
		return UnityEngine::GUIClip::Pop();
	}

	void Image(Vec2 position, Vec2 size, void* sourceTexture, color_t color, int flags = image_flags::image_flags_none) {
		UnityEngine::GUI::set_color(UnityEngine::Color(color.r, color.g, color.b, color.a));
		if (flags & image_flags::image_flags_align_center)
			position.x -= size.x / 2;
		if (flags & image_flags::image_flags_align_right)
			position.x -= size.x;
		UnityEngine::GUI::DrawTexture(UnityEngine::Rect(position.x, position.y, size.x, size.y), reinterpret_cast<UnityEngine::Texture2D*>(sourceTexture));
	}

	void InitGL() {
		if ((gl_material == NULL && !inited)) {
			gl_material = reinterpret_cast<UnityEngine::Material*>(Il2cpp::object_new(Il2cpp::InitClass(xor ("Material"), xor ("UnityEngine"))));
		}
		const auto shader = UnityEngine::Shader::Find(xor (L"Hidden/Internal-Colored"));
		UnityEngine::Material::CreateWithShader(gl_material, shader);
		if (!inited) {
			UnityEngine::Object::DontDestroyOnLoad(gl_material);
			inited = true;
		}
	}

	inline void StartGlRender(render_type type, Vec2 pos = Vec2::Zero(), Vec2 size = Vec2::Zero(), color_t col = { 255,0,0,255 }, Vec2 center = Vec2::Zero(), float radius = 0.f, Vec2 start = Vec2::Zero(), Vec2 end = Vec2::Zero(), float thickness = 0, bool inverted = false, color_t col2 = { 255,0,0,255 }) {
		if (gl_material && inited) {
			gl_material->SetPass(0);
			if (type == render_type::triangle) UnityEngine::GL::Begin(UnityEngine::GL::Mode::Triangles);
			if (type == render_type::box)  UnityEngine::GL::Begin(UnityEngine::GL::Mode::TriangleStrip);
			if (type == render_type::gradient)  UnityEngine::GL::Begin(UnityEngine::GL::Mode::TriangleStrip);
			if (type == render_type::fov || type == render_type::boxoutline)  UnityEngine::GL::Begin(UnityEngine::GL::Mode::LineStrip);
			else UnityEngine::GL::Begin(UnityEngine::GL::Mode::Lines);
			if (type != render_type::gradient) 	UnityEngine::GL::Color(UnityEngine::Color(col.r, col.g, col.b, col.a));
			if (type == render_type::gradient) {
				if (!inverted) {
					UnityEngine::GL::Color(UnityEngine::Color(col.r, col.g, col.b, col.a));

					UnityEngine::GL::Vertex3(pos.x, pos.y, 0);
					UnityEngine::GL::Vertex3(pos.x, pos.y + size.y, 0);
					UnityEngine::GL::Color(UnityEngine::Color(col2.r, col2.g, col2.b, col2.a));
					UnityEngine::GL::Vertex3(pos.x + size.x, pos.y + size.y, 0);
					UnityEngine::GL::Vertex3(pos.x + size.x, pos.y, 0);
					UnityEngine::GL::Color(UnityEngine::Color(col.r, col.g, col.b, col.a));
					UnityEngine::GL::Vertex3(pos.x, pos.y, 0);
				}
				else {
					UnityEngine::GL::Color(UnityEngine::Color(col2.r, col2.g, col2.b, col2.a));
					UnityEngine::GL::Vertex3(pos.x, pos.y + size.y, 0);
					UnityEngine::GL::Vertex3(pos.x + size.x, pos.y + size.y, 0);
					UnityEngine::GL::Color(UnityEngine::Color(col.r, col.g, col.b, col.a));
					UnityEngine::GL::Vertex3(pos.x + size.x, pos.y, 0);
					UnityEngine::GL::Vertex3(pos.x, pos.y, 0);
					UnityEngine::GL::Color(UnityEngine::Color(col2.r, col2.g, col2.b, col2.a));
					UnityEngine::GL::Vertex3(pos.x, pos.y + size.y, 0);
					UnityEngine::GL::Vertex3(pos.x + size.x, pos.y + size.y, 0);
				}
			}
			if (type == render_type::line) {
				UnityEngine::GL::Vertex3(start.x, start.y, 0);
				UnityEngine::GL::Vertex3(end.x, end.y, 0);
			}
			if (type == render_type::fov) {
				for (float num = 0.f; num < 6.2831855; num += 0.1f) {
					UnityEngine::GL::Vertex3(dxmm::math::cos(num) * radius + center.x, dxmm::math::sin(num) * radius + center.y, 0);
					UnityEngine::GL::Vertex3(dxmm::math::cos(num + 0.1f) * radius + center.x, dxmm::math::sin(num + 0.1f) * radius + center.y, 0);
				}
			}
			if (type == render_type::box) {
				UnityEngine::GL::Vertex3(pos.x + 0.5f, pos.y + 0.5f, 0);
				UnityEngine::GL::Vertex3(pos.x + size.x + 0.5f, pos.y + 0.5f, 0);
				UnityEngine::GL::Vertex3(pos.x + size.x + 0.5f, pos.y + size.y + 0.5f, 0);
				UnityEngine::GL::Vertex3(pos.x + 0.5f, pos.y + size.y + 0.5f, 0);
				UnityEngine::GL::Vertex3(pos.x + 0.5f, pos.y + 0.5f, 0);
			}
			if (type == render_type::boxoutline) {
				UnityEngine::GL::Vertex3(pos.x + 0.5f, pos.y + 0.5f, 0);
				UnityEngine::GL::Vertex3(pos.x + size.x + 0.5f, pos.y + 0.5f, 0);
				UnityEngine::GL::Vertex3(pos.x + size.x + 0.5f, pos.y + size.y + 0.5f, 0);
				UnityEngine::GL::Vertex3(pos.x + 0.5f, pos.y + size.y + 0.5f, 0);
				UnityEngine::GL::Vertex3(pos.x + 0.5f, pos.y + 0.5f, 0);
			}
			if (type == render_type::triangle) {
				UnityEngine::GL::Vertex3(pos.x, pos.y, 0);
				UnityEngine::GL::Vertex3(size.x, size.y, 0);
				UnityEngine::GL::Vertex3(center.x, center.y, 0);
			}
			UnityEngine::GL::End();
		}
	}

	color_t PercentColor(float percent)
	{

		return color_t(255.f, 255.f, 255.f, 255.f).hsv(percent / 3.f, 1.f, 1.f, 1.f);
	}

	inline void DrawBar(Vec2 start, Vec2 end, float a, float b, bool full = true) {
		if (a < 0) return;
		if (full)
			FilledRect({ start.x, start.y }, { end.x, end.y + 1 }, color_t(0, 0, 0, 255), 0);
		if ((a / b) > 1)
			a = b;
		FilledRect({ start.x + 1, start.y + 1 }, { (end.x * (a / b)) - 1, end.y - 1 }, color_t(255, 255, 0, 255), 0);
		StartGlRender(render_type::boxoutline, { start.x, start.y }, { end.x, end.y }, color_t(0, 0, 0, 255));
	}

	inline void FlyHackBar(Vec2 start, Vec2 end, float a, float b, bool full = true) {
		if (a < 0) return;
		if (full)
			FilledRect({ start.x, start.y }, { end.x, end.y + 1 }, color_t(0, 0, 0, 255), 0);
		if ((a / b) > 1)
			a = b;
		FilledRect({ start.x + 1, start.y + 1 }, { (end.x * ((b - a) / b)), end.y - 1 }, PercentColor((b - a) / b), 0);
		StartGlRender(render_type::boxoutline, { start.x, start.y }, { end.x, end.y }, color_t(0, 0, 0, 255));
	}

	void InitializeAADrawing() {
		if (!UnityEngine::Object::FindObjectFromInstanceID(AALineTextureInstanceID)) {
			AALineTexture = reinterpret_cast<UnityEngine::Texture2D*>(Il2cpp::object_new(Il2cpp::InitClass(xor ("Texture2D"), xor ("UnityEngine"))));
			UnityEngine::Texture2D::Create(AALineTexture, 1, 3, 1, GraphicsFormat::R8G8B8A8_SRGB, TextureColorSpace::Linear, TextureCreationFlags::None, 0, xor (L""));
			AALineTextureInstanceID = UnityEngine::Object::GetInstanceID(AALineTexture);
			AALineTexture->SetPixel(0, 0, { 255, 255, 255, 0 });
			AALineTexture->SetPixel(0, 1, { 255, 255, 255, 255 });
			AALineTexture->SetPixel(0, 2, { 255, 255, 255, 0 });
			AALineTexture->Apply(true);
		}
		if (!UnityEngine::Object::FindObjectFromInstanceID(LineTextureInstanceID)) {
			LineTexture = reinterpret_cast<UnityEngine::Texture2D*>(Il2cpp::object_new(Il2cpp::InitClass(xor ("Texture2D"), xor ("UnityEngine"))));
			UnityEngine::Texture2D::Create(LineTexture, 1, 1, 1, GraphicsFormat::R8G8B8A8_SRGB, TextureColorSpace::Linear, TextureCreationFlags::None, 0, xor (L""));
			LineTextureInstanceID = UnityEngine::Object::GetInstanceID(LineTexture);
			LineTexture->SetPixel(0, 1, { 255, 255, 255, 255 });
			LineTexture->Apply(true);
		}
	}

	color_t colorFromPercentage(double percentage) {
		int greenR = 255, greenG = 0, greenB = 0;
		int redR = 0, redG = 255, redB = 0;
		int currentR = dxmm::math::roundf(greenR + (redR - greenR) * (percentage));
		int currentG = dxmm::math::roundf(greenG + (redG - greenG) * (percentage));
		int currentB = dxmm::math::roundf(greenB + (redB - greenB) * (percentage));
		return color_t(currentR, currentG, currentB, 255);
	}
	inline void DrawLine(Vec2 PointA, Vec2 PointB, color_t clr, float Width, bool AntiAlias) {
		GUI::InitializeAADrawing();
		float DeltaX = PointB.x - PointA.x;
		float DeltaY = PointB.y - PointA.y;
		float Length = dxmm::math::sqrt(DeltaX * DeltaX + DeltaY * DeltaY);
		UnityEngine::Texture2D* Texture = AntiAlias ? AALineTexture : g_WhiteTexture;
		if (AntiAlias) Width *= 3.f;
		float WidthDeltaX = Width * DeltaY / Length;
		float WidthDeltaY = Width * DeltaX / Length;
		Matrix4x4Line Matrix = Matrix4x4Line().Identity();
		Matrix.m00 = DeltaX;
		Matrix.m01 = -WidthDeltaX;
		Matrix.m03 = PointA.x + 0.5f * WidthDeltaX;
		Matrix.m10 = DeltaY;
		Matrix.m11 = WidthDeltaY;
		Matrix.m13 = PointA.y - 0.5f * WidthDeltaY;
		UnityEngine::GL::PushMatrix();
		UnityEngine::GL::MultMatrix(Matrix);
		UnityEngine::GUI::set_color(UnityEngine::Color(clr.r, clr.g, clr.b, clr.a));
		UnityEngine::GUI::DrawTexture(UnityEngine::Rect(0, 0, 1, 1), reinterpret_cast<UnityEngine::Texture2D*>(Texture));
		UnityEngine::GL::PopMatrix();
	}

	inline bool is_mouse_in_box(const Vec2& pos1, const Vec2& pos2) {
		if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y) return false;
		if (old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y) return false;
		return true;
	}
	inline bool MouseInZone(Vec2 pos, Vec2 size) {
		if (mouse_pos.x > pos.x && mouse_pos.y > pos.y)
			if (mouse_pos.x < pos.x + size.x && mouse_pos.y < pos.y + size.y)
				return true;
		return false;
	}

	bool KeyBind(int key, bool& Pressed, bool& isAlready, int Type = 0) {
		if (Type == 0) {
			if (UnityEngine::Event::get_current()->type == UnityEngine::Event::EventType::KeyDown) {
				bool cur = UnityEngine::Input::GetKeyInt(key);
				if (cur) {
					if (!isAlready) {
						isAlready = true;
						Pressed = !Pressed;
					}
					else if (isAlready)
					{
						isAlready = false;
					}
				}
			}
			else if (UnityEngine::Event::get_current()->type == UnityEngine::Event::EventType::KeyUp) {
				bool cur = UnityEngine::Input::GetKeyInt(key);
				if (cur) {
					if (!isAlready) {
						isAlready = true;
						Pressed = !Pressed;
					}
					else if (isAlready) {
						isAlready = false;
					}
				}
			}
			return Pressed;
		}
		if (Type == 1) {
			if (UnityEngine::Input::GetKeyInt(key)) {
				return true;
			}
		}
		return false;
	}
}

