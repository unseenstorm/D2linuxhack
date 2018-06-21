/*
 * Copyright (C) 2010 gonzoj
 *
 * Please check the CREDITS file for further information.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "d2structs.h"
#include "types.h"

#include "version.h"

enum { MODULE_D2CLIENT, MODULE_D2COMMON, MODULE_D2GFX, MODULE_D2LANG, MODULE_D2WIN, MODULE_D2NET, MODULE_D2GAME, MODULE_D2LAUNCH, MODULE_FOG, MODULE_BNCLIENT, MODULE_STORM, MODULE_D2CMP, MODULE_D2MULTI };

#define FUNC(r, a, m, f, p, o) typedef r a (*m##_##f##_t)p; m##_##f##_t m##_##f = (m##_##f##_t) (MODULE_##m | (o << 8));
#define VAR(t, m, v, o) typedef t m##_##v##_t; m##_##v##_t *p_##m##_##v = (m##_##v##_t *) (MODULE_##m | (o << 8));

#ifdef _VERSION_1_13d

/* function pointers for version 1.14d */

/* D2Client.dll */

FUNC(unit_any *, __attribute__((stdcall)), D2CLIENT, get_player_unit, (), 0x63DD0) // from McGod's list
FUNC(void, __attribute__((stdcall)), D2CLIENT, reveal_automap_room, (room1 *room1, DWORD clip_flag, automap_layer *layer), 0x58F40) // updated 
FUNC(automap_layer *, __attribute__((regparm(3))), D2CLIENT, init_automap_layer, (DWORD layer_no), 0x58D40) // updated 
FUNC(void, __attribute__((stdcall)), D2CLIENT, print_game_string, (ms_wchar_t *message, int color), 0x9E3A0) // updated
FUNC(DWORD, __attribute__((stdcall)), D2CLIENT, get_automap_size, (), 0x5A710) // updated
FUNC(ms_wchar_t *, __attribute__((regparm(3))), D2CLIENT, get_unit_name, (unit_any *), 0x64A60) // updated
FUNC(void, __attribute__((fastcall)), D2CLIENT, add_automap_cell, (automap_cell *cell, automap_cell **node), 0x57B00) // updated
FUNC(automap_cell *, __attribute__((fastcall)), D2CLIENT, new_automap_cell, (), 0x57C30) // updated
FUNC(game_info *, __attribute__((stdcall)), D2CLIENT, get_game_info, (), 0x3A0438) // updated
FUNC(unit_any *, __attribute__((stdcall)), D2CLIENT, get_selected_unit, (), 0x17280) // updated0x11C4D8
FUNC(DWORD, __attribute__((regparm(3))), D2CLIENT, get_ui_var, (DWORD var_no), 0x538D0) // updated
FUNC(DWORD, __attribute__((fastcall)), D2CLIENT, set_ui_var, (DWORD var_no, DWORD howset, DWORD unknown), 0x55F20) // updated
FUNC(unit_any *, __attribute__((fastcall)), D2CLIENT, find_server_side_unit, (DWORD id, DWORD type), 0x639B0) // updated
//FUNC(void, __attribute__((fastcall)), D2CLIENT, exit_game, (), 0x43870) // updated
FUNC(void, __attribute__((stdcall)), D2CLIENT, receive_packet, (BYTE *packet, size_t len), 0x12AEB0) // updated 1.14

/* D2Gfx.dll */

FUNC(void, __attribute__((stdcall)), D2GFX, draw_line, (int x1, int y1, int x2, int y2, DWORD color, DWORD unk), 0xF6380) // updated
FUNC(void, __attribute__((stdcall)), D2GFX, draw_rectangle, (int x1, int y1, int x2, int y2, DWORD color, DWORD trans), 0xF6300) // updated

/* D2Win.dll */

FUNC(DWORD, __attribute__((fastcall)), D2WIN, set_text_size, (DWORD size), 0x102EF0) // updated
FUNC(void, __attribute__((fastcall)), D2WIN, draw_text, (ms_wchar_t *text, int x, int y, int color, DWORD unk), 0x102320) // updated
FUNC(DWORD, __attribute__((fastcall)), D2WIN, get_text_width_file_no, (ms_wchar_t *text, int *width, DWORD *file_no), 0x102520) // updated
FUNC(void, __attribute__((fastcall)), D2WIN, select_edit_box_text, (vaddr box, ms_wchar_t *text), 0xfdd00) // updated
FUNC(void *, __attribute__((fastcall)), D2WIN, set_control_text, (vaddr box, ms_wchar_t *text), 0xFF5A0) // updated
FUNC(void, __attribute__((fastcall)), D2WIN, set_edit_box_proc, (vaddr box, int __attribute__((stdcall)) (*call_back)(vaddr, DWORD, DWORD)), 0xFDAD0) // updated

/* D2Lang.dll */

FUNC(ms_wchar_t *, __attribute__((fastcall)), D2LANG, get_local_text, (DWORD local_text_no), 0x124A30) // updated

/* D2Net.dll */

FUNC(void, __attribute__((stdcall)), D2NET, send_packet, (size_t len, DWORD arg, BYTE *packet), 0x12AE50) // updated
FUNC(void, __attribute__((stdcall)), D2NET, receive_packet, (BYTE *packet, size_t len), 0x12AEB0) // updated

/* D2Common.dll */

FUNC(void, __attribute__((stdcall)), D2COMMON, add_room_data, (act *act, DWORD level_no, int x, int y, room1 *room1), 0x21A070) // updated
FUNC(void, __attribute__((stdcall)), D2COMMON, remove_room_data, (act *act, DWORD level_no, int x, int y, room1 *room1), 0x21A0C0) // updated
FUNC(automap_layer2 *, __attribute__((fastcall)), D2COMMON, get_layer, (DWORD level_no), 0x21E470) // updated
FUNC(level *, __attribute__((fastcall)), D2COMMON, get_level, (act_misc *misc, DWORD level_no), -0x242AE0) // updated
FUNC(void, __attribute__((stdcall)), D2COMMON, init_level, (level *level), 0x2424A0) // updated
FUNC(object_txt *, __attribute__((stdcall)), D2COMMON, get_object_txt, (DWORD obj_no), 0x240E90) // updated
FUNC(DWORD, __attribute__((stdcall)), D2COMMON, get_unit_stat, (unit_any *unit, DWORD stat, DWORD stat2), 0x225480) // updated

#undef FUNC

/* variable pointers for version 1.13d */

/* D2Client.dll */

VAR(automap_layer *, D2CLIENT, automap_layer, 0x11CF28) // updated
VAR(automap_layer *, D2CLIENT, first_automap_layer, 0x11CF24) // updated 
VAR(int, D2CLIENT, divisor, 0x311254) // from McGod's list
VAR(POINT, D2CLIENT, offset, 0x3A5198) // from McGod's list
VAR(DWORD, D2CLIENT, automap_on, 0x3A27E8) // from McGod's list
VAR(unit_any *, D2CLIENT, player_unit, 0x3A6A70) // from McGod's list
//VAR(DWORD, D2CLIENT, ping, 0x108764) // from McGod's list

/* D2Win.dll */

VAR(DWORD, D2WIN, first_control, 0x3D55BC) // from McGod's list

#undef VAR

#elif defined _VERSION_1_13c

/* function pointers for version 1.13c */

/* D2Client.dll */

FUNC(unit_any *, __attribute__((stdcall)), D2CLIENT, get_player_unit, (), 0xA4D60) // updated 6FB54D60:   a1 fc bb bc 6f          mov    0x6FBCBBFC,%eax
FUNC(void, __attribute__((stdcall)), D2CLIENT, reveal_automap_room, (room1 *room1, DWORD clip_flag, automap_layer *layer), 0x62580) // updated
FUNC(automap_layer *, __attribute__((regparm(3))), D2CLIENT, init_automap_layer, (DWORD layer_no), 0x62710) // updated
FUNC(void, __attribute__((stdcall)), D2CLIENT, print_game_string, (ms_wchar_t *message, int color), 0x7D850) // updated
FUNC(DWORD, __attribute__((stdcall)), D2CLIENT, get_automap_size, (), 0x5F080) // updated 6FB0F080:   a1 b0 c1 bc 6f          mov    0x6FBCC1b0,%eax
FUNC(ms_wchar_t *, __attribute__((regparm(3))), D2CLIENT, get_unit_name, (unit_any *), 0xA5D90) // updated
FUNC(void, __attribute__((fastcall)), D2CLIENT, add_automap_cell, (automap_cell *cell, automap_cell **node), 0x61320) // updated
FUNC(automap_cell *, __attribute__((fastcall)), D2CLIENT, new_automap_cell, (), 0x5F6B0) // updated
FUNC(game_info *, __attribute__((stdcall)), D2CLIENT, get_game_info, (), 0x108B0) // updated 6FAC08B0:   a1 80 b9 bc 6f          mov    0x6FBCB980,%eax
FUNC(unit_any *, __attribute__((stdcall)), D2CLIENT, get_selected_unit, (), 0x51A80) // updated
FUNC(DWORD, __attribute__((regparm(3))), D2CLIENT, get_ui_var, (DWORD var_no), 0xBE400) // updated
FUNC(DWORD, __attribute__((fastcall)), D2CLIENT, set_ui_var, (DWORD var_no, DWORD howset, DWORD unknown), 0xC2790) // updated
FUNC(unit_any *, __attribute__((fastcall)), D2CLIENT, find_server_side_unit, (DWORD id, DWORD type), 0xA5B40) // updated

/* D2Gfx.dll */

FUNC(void, __attribute__((stdcall)), D2GFX, draw_line, (int x1, int y1, int x2, int y2, DWORD color, DWORD unk), -10010) // updated
FUNC(void, __attribute__((stdcall)), D2GFX, draw_rectangle, (int x1, int y1, int x2, int y2, DWORD color, DWORD trans), -10014) // updated

/* D2Win.dll */

FUNC(DWORD, __attribute__((fastcall)), D2WIN, set_text_size, (DWORD size), -10184) // updated
FUNC(void, __attribute__((fastcall)), D2WIN, draw_text, (ms_wchar_t *text, int x, int y, int color, DWORD unk), -10150) // updated
FUNC(DWORD, __attribute__((fastcall)), D2WIN, get_text_width_file_no, (ms_wchar_t *text, int *width, DWORD *file_no), -10177) // updated
FUNC(void, __attribute__((fastcall)), D2WIN, select_edit_box_text, (vaddr box, ms_wchar_t *text), -10021) // updated
FUNC(void *, __attribute__((fastcall)), D2WIN, set_control_text, (vaddr box, ms_wchar_t *text), -10042) // updated
FUNC(void, __attribute__((fastcall)), D2WIN, set_edit_box_proc, (vaddr box, int __attribute__((stdcall)) (*call_back)(vaddr, DWORD, DWORD)), -10170) // updated

/* D2Lang.dll */

FUNC(ms_wchar_t *, __attribute__((fastcall)), D2LANG, get_local_text, (DWORD local_text_no), -10003) // updated

/* D2Common.dll */

FUNC(void, __attribute__((stdcall)), D2COMMON, add_room_data, (act *act, DWORD level_no, int x, int y, room1 *room1), -10401) // updated
FUNC(void, __attribute__((stdcall)), D2COMMON, remove_room_data, (act *act, DWORD level_no, int x, int y, room1 *room1), -11099) // updated
FUNC(automap_layer2 *, __attribute__((fastcall)), D2COMMON, get_layer, (DWORD level_no), -10749) // updated
FUNC(level *, __attribute__((fastcall)), D2COMMON, get_level, (act_misc *misc, DWORD level_no), 0x2D9B0) // updated 6FD7E594:   e8 17 f4 ff ff          call   0x6FD7D9B0
FUNC(void, __attribute__((stdcall)), D2COMMON, init_level, (level *level), 0x2E360) // updated
FUNC(object_txt *, __attribute__((stdcall)), D2COMMON, get_object_txt, (DWORD obj_no), -10688) // updated
FUNC(DWORD, __attribute__((stdcall)), D2COMMON, get_unit_stat, (unit_any *unit, DWORD stat, DWORD stat2), -10973) // updated 0x6FD88B70

#undef FUNC

/* variable pointers for version 1.13c */

/* D2Client.dll */

VAR(automap_layer *, D2CLIENT, automap_layer, 0x11C1C4) // updated
VAR(automap_layer *, D2CLIENT, first_automap_layer, 0x11C1C0) // updated
VAR(int, D2CLIENT, divisor, 0xF16B0) // updated
VAR(POINT, D2CLIENT, offset, 0x11C1F8) // updated
VAR(DWORD, D2CLIENT, automap_on, 0x11B9AC) // updated
VAR(unit_any *, D2CLIENT, player_unit, 0x11BBFC) // updated

/* D2Win.dll */

VAR(DWORD, D2WIN, first_control, 0x214A0) // updated

#undef VAR

#elif defined _VERSION_1_12

/* function pointers for version 1.12a (from D2BS) */

/* D2Client.dll */

FUNC(unit_any *, __attribute__((stdcall)), D2CLIENT, get_player_unit, (), 0x1E490)
FUNC(void, __attribute__((stdcall)), D2CLIENT, reveal_automap_room, (room1 *room1, DWORD clip_flag, automap_layer *layer), 0x404C0)
FUNC(automap_layer *, __attribute__((regparm(3))), D2CLIENT, init_automap_layer, (DWORD layer_no), 0x40650)
FUNC(void, __attribute__((stdcall)), D2CLIENT, print_game_string, (ms_wchar_t *message, int color), 0x71740)
FUNC(void, __attribute__((fastcall)), D2CLIENT, add_automap_cell, (automap_cell *cell, automap_cell **node), 0x3F090)
FUNC(automap_cell *, __attribute__((fastcall)), D2CLIENT, new_automap_cell, (), 0x3D5B0)
FUNC(DWORD, __attribute__((stdcall)), D2CLIENT, get_automap_size, (), 0x3CFC0)
FUNC(ms_wchar_t *, __attribute__((regparm(3))), D2CLIENT, get_unit_name, (unit_any *), 0x1F3D0)
FUNC(unit_any *, __attribute__((stdcall)), D2CLIENT, get_selected_unit, (), 0x6ECA0)
FUNC(DWORD, __attribute__((regparm(3))), D2CLIENT, get_ui_var, (DWORD var_no), 0x8AA90)
FUNC(DWORD, __attribute__((fastcall)), D2CLIENT, set_ui_var, (DWORD var_no, DWORD howset, DWORD unknown), 0x8EF00)
FUNC(unit_any *, __attribute__((fastcall)), D2CLIENT, find_server_side_unit, (DWORD id, DWORD type), 0x1F1C0)
FUNC(game_info *, __attribute__((stdcall)), D2CLIENT, get_game_info, (), 0x120F0)

/* D2Gfx.dll */

FUNC(void, __attribute__((stdcall)), D2GFX, draw_line, (int x1, int y1, int x2, int y2, DWORD color, DWORD unk), 0x7CA0)
FUNC(void, __attribute__((stdcall)), D2GFX, draw_rectangle, (int x1, int y1, int x2, int y2, DWORD color, DWORD trans), -10062)

/* D2Win.dll */

FUNC(DWORD, __attribute__((fastcall)), D2WIN, set_text_size, (DWORD size), -10010)
FUNC(void, __attribute__((fastcall)), D2WIN, draw_text, (ms_wchar_t *text, int x, int y, int color, DWORD unk), -10001)
FUNC(DWORD, __attribute__((fastcall)), D2WIN, get_text_width_file_no, (ms_wchar_t *text, int *width, DWORD *file_no), -10096)
FUNC(void, __attribute__((fastcall)), D2WIN, select_edit_box_text, (vaddr box, ms_wchar_t *text), -10035)
FUNC(void *, __attribute__((fastcall)), D2WIN, set_control_text, (vaddr box, ms_wchar_t *text), -10095)
FUNC(void, __attribute__((fastcall)), D2WIN, set_edit_box_proc, (vaddr box, int __attribute__((stdcall)) (*call_back)(vaddr, DWORD, DWORD)), -10113)

/* D2Lang.dll */

FUNC(ms_wchar_t *, __attribute__((fastcall)), D2LANG, get_local_text, (DWORD local_text_no), -10005)

/* D2Common.dll */

FUNC(void, __attribute__((stdcall)), D2COMMON, add_room_data, (act *act, DWORD level_no, int x, int y, room1 *room1), -10184)
FUNC(void, __attribute__((stdcall)), D2COMMON, remove_room_data, (act *act, DWORD level_no, int x, int y, room1 *room1), -11009)
FUNC(automap_layer2 *, __attribute__((fastcall)), D2COMMON, get_layer, (DWORD level_no), 0x73870)
FUNC(level *, __attribute__((fastcall)), D2COMMON, get_level, (act_misc *misc, DWORD level_no), -11020)
FUNC(object_txt *, __attribute__((stdcall)), D2COMMON, get_object_txt, (DWORD obj_no), 0x37300)
FUNC(void, __attribute__((stdcall)), D2COMMON, init_level, (level *level), -10721)
FUNC(DWORD, __attribute__((stdcall)), D2COMMON, get_unit_stat, (unit_any *unit, DWORD stat, DWORD stat2), 0x34E20)

#undef FUNC

/* variable pointers (from D2BS) */

/* D2Client.dll */

VAR(automap_layer *, D2CLIENT, automap_layer, 0x11C2B4)
VAR(automap_layer *, D2CLIENT, first_automap_layer, 0x11C2B0)
VAR(int, D2CLIENT, divisor, 0xF3B98)
VAR(POINT, D2CLIENT, offset, 0x11C2E8)
VAR(DWORD, D2CLIENT, automap_on, 0x102B80)
VAR(unit_any *, D2CLIENT, player_unit, 0x11C3D0)

/* D2Win.dll */

VAR(DWORD, D2WIN, first_control, 0x5C718)

#undef VAR

#else

	#error NO VERSION SPECIFIED

#endif
