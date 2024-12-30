#pragma once
#include "Render.h"
#include "Vars.h"
#include "Maths.h"
#include "Configs.h"

int* list_open2 = 0;
bool bComboOpenedInThisFrame = false;
static bool combo_clicked = false;

inline const wchar_t* get_keystr(int key) {
	switch (key)
	{
	case 0:
		return xor (L"Insert");
	case 113:
		return xor (L"Q");
	case 118:
		return xor (L"V");
	case 120:
		return xor (L"X");
	case 122:
		return xor (L"Z");
	case 306:
		return xor (L"CLtr");
	case 308:
		return xor (L"LAlt");;
	case 323:
		return xor (L"Space");
	case 324:
		return xor (L"Z");
	case 325:
		return xor (L"A");
	case 326:
		return xor (L"K");
	case 327:
		return xor (L"F");
	case 328:
		return xor (L"Mouse5");
	case 329:
		return xor (L"Mouse4");
	case 304:
		return xor (L"LShift");
	}
	return xor (L"soso");
}

namespace GUIElements
{

	bool ColorPickes_active[200];
	color_t ColorPickes_values[200];
	Vec2 ColorPickes_poses[200];
	bool bColorPickerOpenedInThisFrame;
	bool CreateMenu(wchar_t* title, const Vec2& pos, const Vec2& window_size, bool always_open)
	{
		if (!GUI::open) return false;

		if (!sex) {
			window_pos = pos;
			sex = true;
		}
		mouse_state = UnityEngine::Input::GetMouseButton(0);
		mouse_pos = Vec2(UnityEngine::Input::get_mousePosition().x, UnityEngine::Screen::get_height() - UnityEngine::Input::get_mousePosition().y);

		if (GUI::is_mouse_in_box({ window_pos.x, window_pos.y + 10 }, { window_pos.x + window_size.x, window_pos.y + 40 }) && mouse_state && main_menu_open) {
			window_pos.x += mouse_pos.x - old_mouse_pos.x;
			window_pos.y += mouse_pos.y - old_mouse_pos.y;
		}


		GUI::FilledRect({ window_pos.x, window_pos.y + 10 }, { window_size.x, window_size.y - 10 }, { 34, 34, 34, 230 }, 7); 
		GUI::FilledRect({ window_pos.x + 10, window_pos.y + 20 }, { window_size.x - 20, window_size.y - 30 }, color_t(45, 45, 45, 230), 7); 


		GUI::DrawLine({ window_pos.x + 10, window_pos.y + 60 }, { window_pos.x + 500, window_pos.y + 60 }, { 0, 174, 255, 255 }, 1, false);

		return true;
	}



	int table = 0;
	void Tab(wchar_t* name, int id, Vec2 tab_size = Vec2(100.f, 25.f)) {
		if (GUI::is_mouse_in_box({ window_pos.x + (id * tab_size.x) + 10, window_pos.y + 24 }, { window_pos.x + tab_size.x + (id * tab_size.x), window_pos.y + 60 }) && mouse_state && !old_mouse_state && !bColorPickerOpenedInThisFrame && !bComboOpenedInThisFrame)
			Vars::ActiveTab = id;

		GUI::DrawString({ window_pos.x + (id * tab_size.x) + tab_size.x/2+10, window_pos.y + tab_size.y/2-5  }, (name), id == Vars::ActiveTab ? color_t{ 255, 255,255, 255 } : color_t{ 255, 255,255, 140 }, text_flags::text_flags_align_center,12, disconnectwtffontuploadtoyoutube);
		GUI::StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x) + 20, window_pos.y + 58 }, { tab_size.x - 15, 3 }, id == Vars::ActiveTab ? color_t{ 12, 12, 12, 255 } : color_t{ 12,12,18, 0 });

		GUI::DrawLine({ window_pos.x + (id * tab_size.x) + 20, window_pos.y + 59 }, { window_pos.x + (id * tab_size.x) + 20, window_pos.y + 24 }, id == Vars::ActiveTab ? color_t{ 57,57,57,255 } : color_t{ 0,0,0,0 }, 1, false);

		GUI::DrawLine({ window_pos.x + (id * tab_size.x) + 19, window_pos.y + 24 }, { window_pos.x + (id * tab_size.x) + tab_size.x + 5, window_pos.y + 24 }, id == Vars::ActiveTab ? color_t{ 57,57,57,255 } : color_t{ 0,0,0,0 }, 1, false);
		GUI::DrawLine({ window_pos.x + (id * tab_size.x) + tab_size.x + 5, window_pos.y + 24 }, { window_pos.x + (id * tab_size.x) + tab_size.x + 5 , window_pos.y + 59 }, id == Vars::ActiveTab ? color_t{ 57,57,57,255 } : color_t{ 0,0,0,0 }, 1, false);
	}

	inline void CheckBox(wchar_t* title, bool& value, bool dist = false) {
		next_item_pos.y -= 2;

		if (GUI::is_mouse_in_box({ next_item_pos.x, next_item_pos.y }, { next_item_pos.x + 14, next_item_pos.y + 14 }) && mouse_state && !old_mouse_state && !bColorPickerOpenedInThisFrame && !bComboOpenedInThisFrame)
			value = !value;

		GUI::DrawString({ next_item_pos.x + 20, next_item_pos.y - 5.f }, title, dist ? color_t(255, 0, 0, 255) : color_t(255, 255, 255, 255), 0, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);


		GUI::Rect({ next_item_pos.x - 2, next_item_pos.y - 2 }, { 16, 16 }, { 100, 100, 100, 255 }, 2); 

		GUI::FilledRect({ next_item_pos.x, next_item_pos.y }, { 12, 12 }, value ? color_t(0, 174, 255, 200) : color_t(60, 60, 60, 170), 2);

		next_item_pos.y += 24;
	}


	inline void TabChild(wchar_t* title, const Vec2& pos, const Vec2& size) {
		GUI::FilledRect({ window_pos.x + pos.x, window_pos.y + pos.y }, { size.x, size.y }, { 34, 34, 34, 230 }, 5);

		GUI::DrawString({ window_pos.x + 20, window_pos.y }, title, { 255, 255, 255, 255 }, false, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);

		next_item_pos = { window_pos.x + pos.x + 15, window_pos.y + pos.y + 17 };

		GUI::DrawLine({ window_pos.x + pos.x, window_pos.y + pos.y + size.y }, { window_pos.x + pos.x + size.x, window_pos.y + pos.y + size.y }, { 0, 174, 255, 255 }, 2, false); // А¶Й«µЧІїПЯМх
	}

	inline void Slider(wchar_t* title, float& value, float min, float max, wchar_t* type = xor(L"%d")) {
		float desValue = value;
		if (GUI::is_mouse_in_box({ next_item_pos.x - 5, next_item_pos.y }, { next_item_pos.x + 160, next_item_pos.y + 25 }) && mouse_state && !inColorPicker && !bColorPickerOpenedInThisFrame && !bComboOpenedInThisFrame) {
			float m_flFilled = ((old_mouse_pos.x - next_item_pos.x) / 150);
			desValue = (max - min) * m_flFilled;
			if (desValue > max) desValue = max; if (desValue < min) desValue = min;
		}
		value = dxmm::math::clamp(dxmm::math::lerp(value, desValue, 0.1f), min, max);

		wchar_t Active[512];
		swprintf_s(Active, type, type != xor(L"%d") ? value : static_cast<int>(value));

		GUI::FilledRect({ next_item_pos.x - 2, next_item_pos.y }, { 150, 16 }, color_t(21, 21, 21, 255), 2);
		GUI::FilledRect({ next_item_pos.x - 2, next_item_pos.y }, { ((float)(value * 150) / max), 16 }, color_t(255, 170, 86, 200), 2);
		GUI::Rect({ next_item_pos.x - 3, next_item_pos.y - 1 }, { 152, 18 }, color_t(60, 60, 60, 170), 2);

		GUI::DrawString({ next_item_pos.x +73, next_item_pos.y - 3 }, title, { 255, 255, 255, 225 }, text_flags::text_flags_align_center, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);
		GUI::FilledRect({ next_item_pos.x + 154, next_item_pos.y - 1 }, { 37, 18 }, color_t(60, 60, 60, 170), 2);
		GUI::FilledRect({ next_item_pos.x + 155, next_item_pos.y }, { 35, 16 }, color_t(21, 21, 21, 255), 2);
		GUI::DrawString({ next_item_pos.x + 172, next_item_pos.y -3}, Active, { 255, 255, 255, 225 }, text_flags::text_flags_align_center, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);

		next_item_pos.y += 28;
	}
	
	template<typename value_t>
	inline void slider(wchar_t* title, wchar_t* suffix, value_t& value, value_t min, value_t max) {
		auto is_float_mode = std::is_same_v<value_t, float>;


		if (GUI::is_mouse_in_box({ next_item_pos.x - 5, next_item_pos.y }, { next_item_pos.x + 160, next_item_pos.y + 25 }) && mouse_state && !inColorPicker && !bColorPickerOpenedInThisFrame && !bComboOpenedInThisFrame) {
			float m_flFilled = ((old_mouse_pos.x - next_item_pos.x) / 150);

			if (is_float_mode) {
				value = static_cast<float>(dxmm::math::clamp(old_mouse_pos.x - (next_item_pos.x), static_cast<float>(min), 150.f - 1) / (150.f - 1) * (max - min) + min);
				value = static_cast<float>(dxmm::math::clamp(static_cast<float>(value), static_cast<float>(min), static_cast<float>(max)));
			}
			else {
				value = static_cast<int>(dxmm::math::clamp(old_mouse_pos.x - (next_item_pos.x), static_cast<float>(min), 150.f - 1) / (150.f - 1) * (max - min) + min);
				value = static_cast<int>(dxmm::math::clamp(static_cast<int>(value), static_cast<int>(min), static_cast<int>(max)));
			}
		}


		wchar_t buf[512];
		if (is_float_mode) {
			swprintf_s(buf, sizeof(buf) / sizeof(wchar_t), L"%.2f%s", value, suffix);
		}
		else {
			swprintf_s(buf, sizeof(buf) / sizeof(wchar_t), L"%d%s", static_cast<int>(value), suffix);
		}


		GUI::FilledRect({ next_item_pos.x - 2, next_item_pos.y }, { 150, 16 }, { 34, 34, 34, 230 }, 2);


		GUI::FilledRect({ next_item_pos.x - 2, next_item_pos.y }, { ((float)(value * 150) / max), 16 }, { 0, 174, 255, 200 }, 2); 


		GUI::Rect({ next_item_pos.x - 3, next_item_pos.y - 1 }, { 152, 18 }, { 100, 100, 100, 255 }, 2);


		GUI::DrawString({ next_item_pos.x + 73, next_item_pos.y - 3 }, title, { 255, 255, 255, 225 }, text_flags::text_flags_align_center, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);


		GUI::FilledRect({ next_item_pos.x + 154, next_item_pos.y - 1 }, { 37, 18 }, { 34, 34, 34, 230 }, 2);


		GUI::FilledRect({ next_item_pos.x + 155, next_item_pos.y }, { 35, 16 }, { 21, 21, 21, 255 }, 2);

		GUI::DrawString({ next_item_pos.x + 172, next_item_pos.y - 3 }, buf, { 255, 255, 255, 225 }, text_flags::text_flags_align_center, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);

		next_item_pos.y += 28;
	}


	template void slider(wchar_t* name, wchar_t* suffix, float& value, float min, float max);
	template void slider(wchar_t* name, wchar_t* suffix, int& value, int min, int max);
	inline void IntSlider(wchar_t* title, int& value, float min, float max)
	{

		if (GUI::is_mouse_in_box({ next_item_pos.x - 5, next_item_pos.y }, { next_item_pos.x + 160, next_item_pos.y + 25 }) && mouse_state && !inColorPicker && !bColorPickerOpenedInThisFrame && !bComboOpenedInThisFrame) {
			value = static_cast<int>(dxmm::math::clamp(old_mouse_pos.x - next_item_pos.x, static_cast<float>(min), (160.f - 1)) / (160.f - 1) * (max - min) + min);
			value = static_cast<int>(dxmm::math::clamp(value, static_cast<int>(min), static_cast<int>(max)));
		}

		wchar_t Active[512];
		swprintf_s(Active, sizeof(Active) / sizeof(wchar_t), L"%d", static_cast<int>(value));


		GUI::FilledRect({ next_item_pos.x - 2, next_item_pos.y }, { 150, 16 }, { 34, 34, 34, 230 }, 2);


		GUI::FilledRect({ next_item_pos.x - 2, next_item_pos.y }, { ((float)(value * 150) / max), 16 }, { 0, 174, 255, 200 }, 2); 


		GUI::Rect({ next_item_pos.x - 3, next_item_pos.y - 1 }, { 152, 18 }, { 100, 100, 100, 255 }, 2);


		GUI::DrawString({ next_item_pos.x + 73, next_item_pos.y - 3 }, title, { 255, 255, 255, 225 }, text_flags::text_flags_align_center, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);


		GUI::FilledRect({ next_item_pos.x + 154, next_item_pos.y - 1 }, { 37, 18 }, { 34, 34, 34, 230 }, 2);


		GUI::FilledRect({ next_item_pos.x + 155, next_item_pos.y }, { 35, 16 }, { 21, 21, 21, 255 }, 2);


		GUI::DrawString({ next_item_pos.x + 172, next_item_pos.y - 3 }, Active, { 255, 255, 255, 225 }, text_flags::text_flags_align_center, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);

		next_item_pos.y += 28;
	}


	void Hotkey(int* key, int* Type, bool& value, bool* GetKeyBind) {
		next_item_pos.x += 10;
		Rect TextPos = Rect(next_item_pos.x, next_item_pos.y, 200, 150);
		if (GUI::MouseInZone(Vec2{ next_item_pos.x + 130, next_item_pos.y - 5 }, { 80, 16 }) && mouse_state && !old_mouse_state && !bColorPickerOpenedInThisFrame && !bComboOpenedInThisFrame) {
			*GetKeyBind = !*GetKeyBind;
		}
		Rect textPos = Rect{ next_item_pos.x + 130, next_item_pos.y - 5, 200,150 };
		GUI::FilledRect({ next_item_pos.x + 130, next_item_pos.y - 5 }, { 50, 16 }, color_t(21, 21, 21, 255), 2);
		GUI::Rect({ next_item_pos.x + 129, next_item_pos.y - 6 }, { 52, 18 }, color_t(60, 60, 60, 170), 2);

		if (*GetKeyBind) {
			GUI::DrawString({ next_item_pos.x + 155, next_item_pos.y - 8}, xor(L"..."), color_t(255, 255, 255, 170), text_flags::text_flags_align_center, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);
			for (int code = 0; code < 329; code++) {
				if (UnityEngine::Input::GetKeyInt(code)) {
					if (code != 323) {
						*GetKeyBind = false;
						*key = code;
					}
				}
			}
		}
		else {
			GUI::DrawString(Vec2(next_item_pos.x + 155, next_item_pos.y - 8), get_keystr(*key), color_t{ 255, 255, 255, 200 }, text_flags::text_flags_align_center, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);
		}
		if (GUI::is_mouse_in_box({ next_item_pos.x + 110, next_item_pos.y }, { next_item_pos.x + 126, next_item_pos.y + 20 }) && mouse_state && !old_mouse_state && !bColorPickerOpenedInThisFrame) // && !inColorPicker
			value = !value;
		GUI::FilledRect({ next_item_pos.x + 110 , next_item_pos.y - 5 }, { 16, 16 }, color_t(21, 21, 21, 255), 2);
		GUI::Rect({ next_item_pos.x + 95 , next_item_pos.y - 6 }, { 32, 18 }, color_t(60, 60, 60, 170), 2);
		GUI::DrawString({ next_item_pos.x + 111 , next_item_pos.y - 9}, value ? xor(L"kogda otsos?") : xor(L"ялюблютебячоузик"), color_t(255, 255, 255, 255), text_flags::text_flags_align_center, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);
		if (!value)	*Type = 1; else if (value) *Type = 0;
		next_item_pos.x -= 10;
	}
	inline bool Items_ArrayGetter(void* data, int idx, wchar_t** out_text) 	{
		wchar_t* const* items = (wchar_t* const*)data;
		if (out_text)
			*out_text = items[idx];
		return true;
	}
	bool combo_(wchar_t* name, int* current_item, bool (*items_getter)(void*, int, wchar_t**), void* data, int items_count) {
		wchar_t* preview_value = NULL;
		next_item_pos.y += 9;
		if (*current_item >= 0 && *current_item < items_count) Items_ArrayGetter(data, *current_item, &preview_value);
		auto size = Vec2(195, 20);
		if (GUI::MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x + 20,size.y }) && mouse_state && !old_mouse_state && !bColorPickerOpenedInThisFrame) {
			bComboOpenedInThisFrame = !bComboOpenedInThisFrame;
			if (list_open2 != current_item)
				list_open2 = current_item;
		}
		wchar_t* item_text = xor(L"");
		GUI::FilledRect({ next_item_pos.x - 1, next_item_pos.y - 1 },{ size.x + 2, size.y + 2 }, { 23, 23, 23, 255 }, 5);
		GUI::FilledRect({ next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 30, 30, 30, 255 }, 5);
		GUI::StartGlRender(render_type::triangle, { next_item_pos.x + size.x - 1 - 5, next_item_pos.y + size.y - 15 }, { next_item_pos.x + size.x - 1 - 15, next_item_pos.y + size.y - 15 }, { 255, 255, 255,60 }, { next_item_pos.x + size.x - 1 - 10, next_item_pos.y + size.y - 5 }, 0, Vec2(screen_center.x, screen_size.y), { 10,20 });
		GUI::DrawString({ next_item_pos.x + 5, next_item_pos.y - 1  }, preview_value, color_t(255, 255, 255, 255), text_flags::text_flags_none, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);
		bool value_changed = false;
		if (bComboOpenedInThisFrame && list_open2 == current_item) {
			Vec2 PossAdding = Vec2(next_item_pos.x, next_item_pos.y);
			for (int i = 0; i < items_count; i++) {
				const bool item_selected = (i == *current_item);
				if (!Items_ArrayGetter(data, i, &item_text)) item_text = xor(L"???");
				PossAdding.y += 20;
				if (GUI::MouseInZone({ PossAdding.x, PossAdding.y }, { size.x + 20,size.y }) && mouse_state && !old_mouse_state && !bColorPickerOpenedInThisFrame) {
					value_changed = true;
					*current_item = i;
					bComboOpenedInThisFrame = false;
				}
				color_t clr = GUI::MouseInZone({ PossAdding.x, PossAdding.y }, { size.x,size.y }) && !(*current_item == i) ? color_t(40, 40, 40, 255) : color_t(30, 30, 30, 255);
				DrawList::AddFilledRect({ PossAdding.x - 1, PossAdding.y - 1 }, { size.x + 2, size.y + 2 }, { 23, 23, 23, 255 });
				DrawList::AddFilledRect({ PossAdding.x, PossAdding.y }, { size.x, size.y }, clr);
				DrawList::AddText(item_text, { PossAdding.x + 5, PossAdding.y }, color_t(255, 255, 255, 200));
				if (*current_item == i)
					DrawList::AddText(item_text, { PossAdding.x + 5, PossAdding.y + 1 }, color_t(255, 255, 255, 255));
			}
		}
		next_item_pos.y += 34;
		return value_changed;
	}
	bool Combo(wchar_t* name, int* current_item, wchar_t* const items[], int items_count)	{
		GUI::DrawString({ next_item_pos.x , next_item_pos.y - 11 }, name, color_t(255, 255, 255, 255), false, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);
		const bool value_changed = combo_(name, current_item, Items_ArrayGetter, (void*)items, items_count);
		return value_changed;
	}
	HSV ColorPickerBehavior(Rect_& RcColor, Rect_& RcAlpha, Rect_& RcHue, int col[4]) {
		static int ActiveBar = -1;
		CColor Ccol = CColor(col[0], col[1], col[2], col[3]);
		HSV hsv = HSV(Ccol.Hue(), Ccol.Saturation(), Ccol.Brightness(), Ccol.a());
		bool h = false;
		bool sv = false;
		bool a = false;
		if (mouse_state) {
			if (GUI::MouseInZone(RcColor.Min, RcColor.Max)) {
				ActiveBar = 0;
				sv = true;
				a = false;
				h = false;
			}
			else if (GUI::MouseInZone(RcHue.Min, RcHue.Max)) {
				ActiveBar = 1;
				h = true;
				sv = false;
				a = false;
			}
			else if (GUI::MouseInZone(RcAlpha.Min, RcAlpha.Max)) {
				ActiveBar = 2;
				a = true;
				sv = false;
				h = false;
			}
		}
		else ActiveBar = -1;
		switch (ActiveBar) {
		case 0:
			if (sv) {
				hsv.s = (mouse_pos.x - RcColor.Min.x) / RcColor.Max.x;
				hsv.v = 1.f - (mouse_pos.y - RcColor.Min.y) / RcColor.Max.y;
			} break;
		case 1:
			if (h)
				hsv.h = 1.f - (mouse_pos.y - RcHue.Min.y) / RcHue.Max.y;
			break;
		case 2:
			if (a)
				hsv.a = dxmm::math::clamp(((mouse_pos.x - RcAlpha.Min.x) / RcAlpha.Max.x) * 255, 0.f, 255.f);
			break;
		}
		return hsv;
	}

	void DoColorPicker(color_t& outColor, bool& Value, bool isSecond, int index = 0) {
		bool& is_active = ColorPickes_active[index];
		color_t& colorpicker_value = ColorPickes_values[index];
		Vec2& colorpicker_pos = ColorPickes_poses[index];
		float DistFromStart = isSecond ? 180 : 160;
		colorpicker_pos = { next_item_pos.x + DistFromStart, next_item_pos.y };;
		int niggacol[4] = { outColor.r, outColor.g  , outColor.b , outColor.a  };
		Vec2 pos = { next_item_pos.x + DistFromStart, next_item_pos.y };
		Rect_ Fullbb = { colorpicker_pos.x, colorpicker_pos.y, 17, 9 };
		Rect_ ColorRect = { colorpicker_pos + Vec2(15, 5), Vec2(150, 150) };
		Rect_ AlphaRect = { colorpicker_pos + Vec2(15, 160), Vec2(150, 10) };
		Rect_ HueRect = { colorpicker_pos + Vec2(170, 5), Vec2(15, 150) };
		bool is_hovered = !bComboOpenedInThisFrame && !bColorPickerOpenedInThisFrame && !bComboOpenedInThisFrame && GUI::MouseInZone({ colorpicker_pos.x, colorpicker_pos.y }, { 20,  14 });
		if (is_active) {
			for (int i = 1; i < 200; i++) {
				if (i != index && mouse_state && !old_mouse_state && !interacting && !GUI::MouseInZone({ colorpicker_pos.x - 1, colorpicker_pos.y }, { 20,  14 })
					&& !GUI::MouseInZone({ Fullbb.Min.x, Fullbb.Min.y }, { Fullbb.Max.x, Fullbb.Max.y })
					&& !GUI::MouseInZone({ colorpicker_pos.x - 1, colorpicker_pos.y }, { 200, 175 })) {
					is_active = false;
					bColorPickerOpenedInThisFrame = false;
				}
			}
		}
		else if (is_hovered && mouse_state) {
			is_active = !is_active;
		}
		GUI::FilledRect({ pos.x - 2, pos.y - 2 }, { 16, 16 }, color_t(60, 60, 60, 170), 2);
		GUI::FilledRect({ pos.x, pos.y }, { 12, 12 }, color_t(niggacol[0], niggacol[1], niggacol[2] , niggacol[3]), 2);
		if (is_active) {
			bColorPickerOpenedInThisFrame = true;
			pos = { next_item_pos.x + DistFromStart + 10, next_item_pos.y };
			Rect_ ColorRect = { pos + Vec2(15, 5), Vec2(150, 150) };
			Rect_ AlphaRect = { pos + Vec2(15, 160), Vec2(150, 10) };
			Rect_ HueRect = { pos + Vec2(170, 5), Vec2(15, 150) };
			HSV ColHSV = ColorPickerBehavior(ColorRect, AlphaRect, HueRect, niggacol);
			CColor Topr = CColor::FromHSB(ColHSV.h, 1.f, 1.f);
			Vec2 ColorPos = { dxmm::math::clamp(ColorRect.Min.x + int(Maths::roundf_r(ColHSV.s * ColorRect.Max.x)), ColorRect.Min.x + 2, ColorRect.Min.x + ColorRect.Max.x - 3), dxmm::math::clamp(ColorRect.Min.y + int((1.f - ColHSV.v) * ColorRect.Max.y), ColorRect.Min.y + 2, ColorRect.Min.y + ColorRect.Max.y - 3) };
			Vec2 HuePos = { HueRect.Min.x, dxmm::math::clamp(HueRect.Min.y + int((1.f - ColHSV.h) * HueRect.Max.y), HueRect.Min.y, HueRect.Min.y + HueRect.Max.y) };
			Vec2 AlphaPos = { dxmm::math::clamp(AlphaRect.Min.x + int(AlphaRect.Max.x * (ColHSV.a / 255.f)), AlphaRect.Min.x, AlphaRect.Min.x + AlphaRect.Max.x), AlphaRect.Min.y };
			DrawList::AddFilledRect(pos + Vec2(10, 0), Vec2(180, 175), color_t(21, 21, 21, 255));
			DrawList::AddGradient(ColorRect.Min, Vec2(150, 150), color_t(255, 255, 255, 255), color_t(Topr.r(), Topr.g(), Topr.b(), 255), false);
			DrawList::AddGradient(ColorRect.Min, Vec2(150, 150), color_t(0, 0, 0, 0), color_t(0, 0, 0, 255), true);
			DrawList::AddRect(ColorRect.Min - Vec2(1, 1), Vec2(152, 152), color_t(12, 12, 12, 255));
			//Alpha Bar
			DrawList::AddRect(AlphaRect.Min - Vec2(1, 1), Vec2(152, 12), color_t(12, 12, 12, 255));
			DrawList::AddFilledRect(AlphaRect.Min, AlphaRect.Max, color_t(niggacol[0], niggacol[1], niggacol[2], niggacol[3]));
			//Hue Bar
			DrawList::AddRect(HueRect.Min - Vec2(1, 1), Vec2(17, 152), color_t(12, 12, 12, 255));
			const color_t hue_colors[6 + 1] = { color_t(220, 30, 34, 255), color_t(220, 30, 216, 255), color_t(30, 34, 220, 255), color_t(30,220,216,255), color_t(34,219,30,255), color_t(220,187,30,255), color_t(220,33,30,255) };
			for (int i = 0; i < 6; ++i)
				DrawList::AddGradient(pos + Vec2(170, 5 + (25 * i)), Vec2(15, 25), hue_colors[i], hue_colors[i + 1], true);
			DrawList::AddRect(ColorPos - Vec2(2, 2), Vec2(4, 4), color_t(12, 12, 12, 255));
			DrawList::AddRect(ColorPos - Vec2(1, 1), Vec2(2, 2), color_t(255, 255, 255, 255));
			//Alpha Bar
			DrawList::AddRect(AlphaPos + Vec2(0, 0), Vec2(4, 10), color_t(12, 12, 12, 255));
			DrawList::AddRect(AlphaPos + Vec2(1, 1), Vec2(2, 8), color_t(255, 255, 255, 255));
			//Hue Indicator
			DrawList::AddRect(HuePos - Vec2(0, 2), Vec2(15, 4), color_t(12, 12, 12, 255));
			DrawList::AddRect(HuePos - Vec2(-1, 1), Vec2(13, 2), color_t(255, 255, 255, 255));
			colorpicker_value = color_t::FromHSB(ColHSV.h, ColHSV.s , ColHSV.v , ColHSV.a );
			outColor = color_t(colorpicker_value.r, colorpicker_value.g, colorpicker_value.b, colorpicker_value.a);
		}
		//next_item_pos.y += 4;
	}
	void end_window() {
		old_insert_state = insert_state;
		old_mouse_pos = mouse_pos;
		old_mouse_state = mouse_state;
	}
};


void DrawNewMenu() {

	if (!GUI::open) return;
	main_menu_open = GUIElements::CreateMenu(xor(L"чоузи"), { 500, 50 }, { 460 + 50 , 410 }, false);
	GUIElements::Tab(xor(L"когда"), 0, Vec2(146, 80));
	GUIElements::Tab(xor(L"дети"), 1, Vec2(146, 80));
	GUIElements::Tab(xor(L"и"), 2, Vec2(146, 80));
	switch (Vars::ActiveTab) {
	case 0:

		GUIElements::TabChild(xor(L""), { 25, 70 }, { 223, 240+75 });
		{
			GUIElements::DoColorPicker(ColorPicker::Fov, ColorPicker::FovBool, true, 0);
			GUIElements::CheckBox(xor(L"новая"), Vars::Aim::DrawFov);
			GUIElements::slider(xor(L"пастуля"),xor(L""), Vars::Aim::OverrideAimFov, 0, 1500);
			GUIElements::CheckBox(xor (L"чтобы"), Vars::Visuals::Connection);


		}

		GUIElements::TabChild(xor(L""), { 263, 70 }, { 223, 240 + 75 });
		{
			GUIElements::Hotkey(&Vars::Keys::Aimbot, &Vars::Keys::AimbotType, Vars::Keys::AimbotVal, &HotKey_Aimboting);
			GUIElements::CheckBox(xor (L"всю"), Vars::Aim::AimBot);
			GUIElements::IntSlider(xor (L"жизнь"), Vars::Aim::aimbotSpread, 1, 20);
			GUIElements::CheckBox(xor (L"юзали"), Vars::Aim::ishead);
		}


		break;
	case 1:
		GUIElements::TabChild(xor(L""), { 25, 70 }, { 223, 240 + 75 });
		{
			GUIElements::CheckBox(xor (L"и"), Vars::Visuals::PlayerEsp::NpcEsp);
			GUIElements::CheckBox(xor (L"обновляли"), Vars::Visuals::PlayerEsp::Box);
			GUIElements::CheckBox(xor(L"я"), Vars::Visuals::PlayerEsp::NameEsp);
			GUIElements::CheckBox(xor (L"ебал"), Vars::Visuals::PlayerEsp::ShowPlayerFlags);
			GUIElements::CheckBox(xor(L"рот"), Vars::Visuals::PlayerEsp::DistanceEsp);
			GUIElements::CheckBox(xor(L"свой"), Vars::Visuals::PlayerEsp::Skeleton);
			GUIElements::CheckBox(xor (L"же"), Vars::Visuals::PlayerEsp::WeaponEsp);
			GUIElements::CheckBox(xor (L"хуй"), Vars::Visuals::PlayerEsp::WeaponIcon);
			GUIElements::DoColorPicker(ColorPicker::PlayerColor, ColorPicker::PlayerColorBool, true, 22);
			GUIElements::DoColorPicker(ColorPicker::PlayerColorInVisible, ColorPicker::PlayerColorInVisibleBool, false, 23);
			GUIElements::CheckBox(xor (L"это"), Vars::Visuals::PlayerEsp::VisibleCheck);
		}
		
		GUIElements::TabChild(xor (L""), { 263, 70 }, { 223, 240 + 75 });
		{
			GUIElements::CheckBox(xor (L"оружие"), Vars::Visuals::Traps::Enabled);
			GUIElements::CheckBox(xor (L"главное"), Vars::Visuals::animals::general::Enabled);
			GUIElements::CheckBox(xor (L"не"), Vars::Visuals::Items::corpses::enable);
			GUIElements::CheckBox(xor (L"стрелять"), Vars::Visuals::Collectibles::Hemp);
			GUIElements::CheckBox(xor (L"по"), Vars::Visuals::Collectibles::Enable);
			GUIElements::CheckBox(xor (L"своим"), Vars::Visuals::Vehicles::Enable);
		}

		break;
	case 2:
		GUIElements::TabChild(xor (L""), { 25, 70 }, { 223, 240 + 75 }); {
			GUIElements::CheckBox(xor (L"а"), Vars::Visuals::RadTown::Enable);
			GUIElements::CheckBox(xor (L"у"), Vars::Visuals::RadTown::Tietong);
			GUIElements::CheckBox(xor (L"рута"), Vars::Visuals::RadTown::Normal);
			GUIElements::CheckBox(xor (L"мать"), Vars::Visuals::RadTown::Military);
			GUIElements::CheckBox(xor (L"шлюха"), Vars::Visuals::RadTown::Airdrop);
			GUIElements::CheckBox(xor (L"сгнившая"), Vars::Visuals::RadTown::gj);
			GUIElements::CheckBox(xor (L"а"), Vars::Visuals::RadTown::Elite);
			GUIElements::CheckBox(xor (L"вот"), Vars::Visuals::RadTown::Shiwuhezi);
		}

		GUIElements::TabChild(xor (L""), { 263, 70 }, { 223, 240 + 75 });
		{
			GUIElements::CheckBox(xor (L"она"), Vars::Visuals::Ore::Enable);
			GUIElements::CheckBox(xor (L"79236492557"), Vars::Visuals::Ore::Stone);
			GUIElements::CheckBox(xor (L"а"), Vars::Visuals::Ore::Sulfur);
			GUIElements::CheckBox(xor (L"вот"), Vars::Visuals::Ore::Metal);


			GUIElements::IntSlider(xor (L"он"), Vars::EspTextSize, 0, 30);
			GUIElements::IntSlider(xor (L"Заболотный Андрей Владимирович"), Vars::WorldEspTextSize, 0, 30);
		}

		break;
	}
	GUIElements::end_window();
	for (const auto obj : Drawlist) {
		if (obj.Type == DrawType_Text)
			GUI::DrawString({ obj.Pos.x, obj.Pos.y }, (obj.Text), obj.Color_, 0, Vars::GUITextSize, disconnectwtffontuploadtoyoutube);
		else if (obj.Type == DrawType_FilledRect)
			GUI::StartGlRender(render_type::box, obj.Pos, obj.Size, obj.Color_);
		else if (obj.Type == DrawType_Gradient)
			GUI::StartGlRender(render_type::gradient, obj.Pos, obj.Size, obj.Color_, Vec2::Zero(), 0, Vec2::Zero(), Vec2::Zero(), 0, obj.Invertered, obj.OtherColor);
		else if (obj.Type == DrawType_Rect)
			GUI::StartGlRender(render_type::boxoutline, obj.Pos, obj.Size, obj.Color_);
	}
	Drawlist.clear();

	return;
}