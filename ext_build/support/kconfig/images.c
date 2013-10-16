// $HeadURL: http://forge-urd44.osn.sagem/svn/sc.stb-lib-opal/BO/branches/BO_sc.stb-lib-opal/scripts/kconfig/images.c $
// $Id: images.c 2416 2011-03-09 11:23:02Z g178508 $

/*
 * Copyright (C) 2002 Roman Zippel <zippel@linux-m68k.org>
 * Released under the terms of the GNU GPL v2.0.
 */

static const char *xpm_load[] = {
"22 22 5 1",
". c None",
"# c #000000",
"c c #838100",
"a c #ffff00",
"b c #ffffff",
"......................",
"......................",
"......................",
"............####....#.",
"...........#....##.##.",
"..................###.",
".................####.",
".####...........#####.",
"#abab##########.......",
"#babababababab#.......",
"#ababababababa#.......",
"#babababababab#.......",
"#ababab###############",
"#babab##cccccccccccc##",
"#abab##cccccccccccc##.",
"#bab##cccccccccccc##..",
"#ab##cccccccccccc##...",
"#b##cccccccccccc##....",
"###cccccccccccc##.....",
"##cccccccccccc##......",
"###############.......",
"......................"};

static const char *xpm_save[] = {
"22 22 5 1",
". c None",
"# c #000000",
"a c #838100",
"b c #c5c2c5",
"c c #cdb6d5",
"......................",
".####################.",
".#aa#bbbbbbbbbbbb#bb#.",
".#aa#bbbbbbbbbbbb#bb#.",
".#aa#bbbbbbbbbcbb####.",
".#aa#bbbccbbbbbbb#aa#.",
".#aa#bbbccbbbbbbb#aa#.",
".#aa#bbbbbbbbbbbb#aa#.",
".#aa#bbbbbbbbbbbb#aa#.",
".#aa#bbbbbbbbbbbb#aa#.",
".#aa#bbbbbbbbbbbb#aa#.",
".#aaa############aaa#.",
".#aaaaaaaaaaaaaaaaaa#.",
".#aaaaaaaaaaaaaaaaaa#.",
".#aaa#############aa#.",
".#aaa#########bbb#aa#.",
".#aaa#########bbb#aa#.",
".#aaa#########bbb#aa#.",
".#aaa#########bbb#aa#.",
".#aaa#########bbb#aa#.",
"..##################..",
"......................"};

static const char *xpm_back[] = {
"22 22 3 1",
". c None",
"# c #000083",
"a c #838183",
"......................",
"......................",
"......................",
"......................",
"......................",
"...........######a....",
"..#......##########...",
"..##...####......##a..",
"..###.###.........##..",
"..######..........##..",
"..#####...........##..",
"..######..........##..",
"..#######.........##..",
"..########.......##a..",
"...............a###...",
"...............###....",
"......................",
"......................",
"......................",
"......................",
"......................",
"......................"};

static const char *xpm_tree_view[] = {
"22 22 2 1",
". c None",
"# c #000000",
"......................",
"......................",
"......#...............",
"......#...............",
"......#...............",
"......#...............",
"......#...............",
"......########........",
"......#...............",
"......#...............",
"......#...............",
"......#...............",
"......#...............",
"......########........",
"......#...............",
"......#...............",
"......#...............",
"......#...............",
"......#...............",
"......########........",
"......................",
"......................"};

static const char *xpm_single_view[] = {
"22 22 2 1",
". c None",
"# c #000000",
"......................",
"......................",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"..........#...........",
"......................",
"......................"};

static const char *xpm_split_view[] = {
"22 22 2 1",
". c None",
"# c #000000",
"......................",
"......................",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......#......#........",
"......................",
"......................"};

static const char *xpm_symbol_no[] = {
"12 12 2 1",
"  c white",
". c black",
"            ",
" .......... ",
" .        . ",
" .        . ",
" .        . ",
" .        . ",
" .        . ",
" .        . ",
" .        . ",
" .        . ",
" .......... ",
"            "};

static const char *xpm_symbol_mod[] = {
"12 12 2 1",
"  c white",
". c black",
"            ",
" .......... ",
" .        . ",
" .        . ",
" .   ..   . ",
" .  ....  . ",
" .  ....  . ",
" .   ..   . ",
" .        . ",
" .        . ",
" .......... ",
"            "};

static const char *xpm_symbol_yes[] = {
"12 12 2 1",
"  c white",
". c black",
"            ",
" .......... ",
" .        . ",
" .        . ",
" .      . . ",
" .     .. . ",
" . .  ..  . ",
" . ....   . ",
" .  ..    . ",
" .        . ",
" .......... ",
"            "};

static const char *xpm_choice_no[] = {
"12 12 2 1",
"  c white",
". c black",
"            ",
"    ....    ",
"  ..    ..  ",
"  .      .  ",
" .        . ",
" .        . ",
" .        . ",
" .        . ",
"  .      .  ",
"  ..    ..  ",
"    ....    ",
"            "};

static const char *xpm_choice_yes[] = {
"12 12 2 1",
"  c white",
". c black",
"            ",
"    ....    ",
"  ..    ..  ",
"  .      .  ",
" .   ..   . ",
" .  ....  . ",
" .  ....  . ",
" .   ..   . ",
"  .      .  ",
"  ..    ..  ",
"    ....    ",
"            "};

static const char *xpm_menu[] = {
"12 12 2 1",
"  c white",
". c black",
"            ",
" .......... ",
" .        . ",
" . ..     . ",
" . ....   . ",
" . ...... . ",
" . ...... . ",
" . ....   . ",
" . ..     . ",
" .        . ",
" .......... ",
"            "};

static const char *xpm_menu_inv[] = {
"12 12 2 1",
"  c white",
". c black",
"            ",
" .......... ",
" .......... ",
" ..  ...... ",
" ..    .... ",
" ..      .. ",
" ..      .. ",
" ..    .... ",
" ..  ...... ",
" .......... ",
" .......... ",
"            "};

static const char *xpm_menuback[] = {
"12 12 2 1",
"  c white",
". c black",
"            ",
" .......... ",
" .        . ",
" .     .. . ",
" .   .... . ",
" . ...... . ",
" . ...... . ",
" .   .... . ",
" .     .. . ",
" .        . ",
" .......... ",
"            "};

static const char *xpm_void[] = {
"12 12 2 1",
"  c white",
". c black",
"            ",
"            ",
"            ",
"            ",
"            ",
"            ",
"            ",
"            ",
"            ",
"            ",
"            ",
"            "};
