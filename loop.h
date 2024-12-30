#pragma once
#include <vector>

BasePlayer* LocalPlayer;
uint64_t camera;
std::vector<uint64_t*> q_play;
std::vector<uint64_t*> q_ai;
std::vector<uint64_t*> q_ore;
std::vector<uint64_t*> q_animals;
std::vector<uint64_t*> q_collectable;
std::vector<uint64_t*> q_radtown;
std::vector<uint64_t*> q_qt;
std::vector<uint64_t*> q_traps;
std::vector<uint64_t*> q_dl;
std::vector<uint64_t*> q_vehicles;
std::vector<uint64_t*> q_st;

void entityList_loop()
{
	q_ai.clear();
	q_play.clear();
	q_ore.clear();
	q_collectable.clear();
	q_animals.clear();
	q_radtown.clear();
	q_qt.clear();
	q_traps.clear();
	q_dl.clear();
	q_vehicles.clear();
	q_st.clear();


	camera = dxmm::memory::Read<uint64_t>(dxmm::memory::Read<uint64_t>(dxmm::memory::Read<uint64_t>(dxmm::memory::Read<uint64_t>(g_Base + offsets::MainCamera_TypeInfo) + 0xb8) + 0x8) + 0x10);
	uint64_t BaseNetWorkable = dxmm::memory::Read<uint64_t>(g_Base + offsets::BaseNetWorkable);
	uint64_t static_fields = dxmm::memory::Read<uint64_t>(BaseNetWorkable + 0xB8);
	uint64_t wrapper_class_ptr = dxmm::memory::Read<uint64_t>(static_fields + 0x8);
	uint64_t wrapper_class = decrypt::networkable_key(wrapper_class_ptr);
	uint64_t parent_static_fields = dxmm::memory::Read<uint64_t>(wrapper_class + 0x10);
	uint64_t parent_class = decrypt::networkable_key(parent_static_fields);
	uint64_t entity = dxmm::memory::Read<uint64_t>(parent_class + 0x20);

	uint32_t entity_size = dxmm::memory::Read<uint32_t>(entity + 0x18);
	uint64_t entity_array = dxmm::memory::Read<uint64_t>(entity + 0x10);

	for (size_t i = 0; i < entity_size; i++) {
		auto entity_entity_p = dxmm::memory::Read<uint64_t*>((uint64_t)entity_array + 0x20 + (i * 0x8));
		auto prefabID = dxmm::memory::Read<uint32_t>((uint64_t)entity_entity_p + offsets::prefabID);

		switch (prefabID) {
		case player::player: {
			if (i == 0) {
				LocalPlayer = (BasePlayer*)entity_entity_p;
				//continue;
			}
			q_play.push_back(entity_entity_p);
			continue;
		}
		case player::scientistnpc_arena:
		case player::scientistnpc_cargo:
		case player::scientistnpc_cargo_turret_lr300:
		case player::scientistnpc_ch47_gunner:
		case player::scientistnpc_excavator:
		case player::scientistnpc_full_any:
		case player::scientistnpc_full_lr300:
		case player::scientistnpc_full_mp5:
		case player::scientistnpc_full_pistol:
		case player::scientistnpc_full_shotgun:
		case player::scientistnpc_heavy:
		case player::scientistnpc_junkpile_pistol:
		case player::scientistnpc_oilrig:
		case player::scientistnpc_patrol:
		case player::scientistnpc_peacekeeper:
		case player::scientistnpc_roam:
		case player::scientistnpc_roam_nvg_variant:
		case player::scientistnpc_roamtethered:
		case player::npc_tunneldweller:
		case player::npc_bandit_guard:
		case player::npc_underwaterdweller:
		case player::scarecrow: {
			q_ai.push_back(entity_entity_p);
			continue;
		}
		case ore::metal:
		case ore::metal2:
		case ore::metal3:
		case ore::metal4:
		case ore::sulfur:
		case ore::sulfur2:
		case ore::sulfur3:
		case ore::sulfur4:
		case ore::stone:
		case ore::stone2:
		case ore::stone3:
		case ore::stone4: {
			q_ore.push_back((uint64_t*)entity_entity_p);
			continue;
		}
		case animals::bear:
		case animals::polarBear:
		case animals::boar:
		case animals::chicken:
		case animals::stag:
		case animals::wolf:
		case animals::zombie:
		{
			q_animals.push_back((uint64_t*)entity_entity_p);
			continue;
		}
		case collectable::hemp:
		{
			q_collectable.push_back((uint64_t*)entity_entity_p);
			continue;
		}
		case radtown::crate_basic:
		case radtown::crate_elite:
		case radtown::crate_mine:
		case radtown::crate_normal:
		case radtown::crate_normal2:
		case radtown::crate_normal_food:
		case radtown::crate_normal_medical:
		case radtown::crate_tools:
		case radtown::crate_underwater_advanced:
		case radtown::crate_underwater_basic:
		case radtown::crate_bradley:
		case radtown::crate_heli:
		case radtown::crate_food:
		case radtown::airdrop: {

			q_radtown.push_back((uint64_t*)entity_entity_p);
			continue;

		}
		case traps::autoturret:
		case traps::flameturret:
		case traps::guntrap:
		case traps::samDeployed:
		case traps::samStatic:
		case traps::landdmine:
		case traps::beartrap:
		{
			q_traps.push_back((uint64_t*)entity_entity_p);
			continue;

		}
		case dl::droppeditem1:
		case dl::droppeditem2:
		{
			q_dl.push_back((uint64_t*)entity_entity_p);
			continue;
		}
		case vehicles::rhib:
		case vehicles::rowboat:
		case vehicles::tugboat:
		case vehicles::horse:
		case vehicles::mini:
		case vehicles::scrap:
		case vehicles::airballoon:
		case vehicles::submarinesolo:
		case vehicles::submarineduo:
		case vehicles::bradleyapc:
		case vehicles::patrolheli:
		case vehicles::chinook:
		{
			q_vehicles.push_back((uint64_t*)entity_entity_p);
			continue;
		}
		case other::corpse1:
		case other::corpse2:
		case other::corpse3:
		case other::corpse4:
		case other::corpse5:
		{
			q_st.push_back((uint64_t*)entity_entity_p);
			continue;
		}
		q_qt.push_back((uint64_t*)entity_entity_p);
		}

	}
}