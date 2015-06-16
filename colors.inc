/*
	Colors Include (colors.inc)
	* Most used and flexible colors and embeded colors list!
	* Now avaliable color crasher fix(optional though)
	* 2 handy player functions !

 	Author: (creator)
	* Gammix

	Contributors:
	* Crayder - GetColorBetweenColors function
	* Unknown - for colors list

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/
/*
FUNCTIONS:
native SetPlayerMarkerVisibility(playerid, alpha = 0xFF, forplayerid = -1);
native TogglePlayerMarker(playerid, bool:toggle, forplayerid = -1);
native _
native ConvertColorTransparency(color, alpha = 0xFF);
native HexToInt(hexcolor, &r, &g, &b, &a);
native IntToHex(r, g, b, a = 255);
native GetColorBetweenColors(ColorA, ColorB, Float:Percent);
*/

static bool:gPlayerMarker[MAX_PLAYERS];

//player functions
stock SetPlayerMarkerVisibility(playerid, alpha = 0xFF, forplayerid = -1)
{
	if(forplayerid < 0) return SetPlayerColor(playerid, COLOR_SetTransparency(GetPlayerColor(playerid), alpha));//set color for all
	else return SetPlayerMarkerForPlayer(playerid, forplayerid, COLOR_SetTransparency(GetPlayerColor(playerid), alpha));//set color for a specific player
}

stock TogglePlayerMarker(playerid, bool:toggle)
{
    gPlayerMarker[playerid] = toggle;
	return true;
}

stock IsPlayerMarkerToggled(playerid)
{
	return gPlayerMarker[playerid];
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	if(IsPlayerMarkerToggled(playerid))
	{
		SetPlayerMarkerForPlayer(forplayerid, playerid, (GetPlayerColor(playerid) & 0xFFFFFF00));
	}
	else
	{
	    SetPlayerMarkerForPlayer(forplayerid, playerid, (GetPlayerColor(playerid) & 0xFFFFFF00) | 0xFF);
	}

	#if defined COLOR_OnPlayerStreamIn
       	return COLOR_OnPlayerStreamIn(playerid, forplayerid);
	#else
	   	return 1;
	#endif
}
#if defined _ALS_OnPlayerStreamIn
    #undef OnPlayerStreamIn
#else
    #define _ALS_OnPlayerStreamIn
#endif
#define OnPlayerStreamIn COLOR_OnPlayerStreamIn
#if defined COLOR_OnPlayerStreamIn
    forward COLOR_OnPlayerStreamIn(playerid, forplayerid);
#endif

public OnPlayerSpawn(playerid)
{
	if(IsPlayerMarkerToggled(playerid))
	{
		for(new i; i < MAX_PLAYERS; i++)
		{
			SetPlayerMarkerForPlayer(i, playerid, (GetPlayerColor(playerid) & 0xFFFFFF00));
		}
	}
	else
	{
 		for(new i; i < MAX_PLAYERS; i++)
		{
			SetPlayerMarkerForPlayer(i, playerid, (GetPlayerColor(playerid) & 0xFFFFFF00) | 0xFF);
		}
	}

	#if defined COLOR_OnPlayerSpawn
       	return COLOR_OnPlayerSpawn(playerid);
	#else
	   	return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn COLOR_OnPlayerSpawn
#if defined COLOR_OnPlayerSpawn
    forward COLOR_OnPlayerSpawn(playerid);
#endif

//color functions
stock ConvertColorTransparency(color, alpha = 0xFF)
{
    static newcolor;

    alpha = clamp(alpha, 0x00, 0xFF);

    newcolor = (color & ~0xFF) | alpha;
    return newcolor;
}

stock HexToInt(hexcolor, &r, &g, &b, &a)
{
	r = ( hexcolor >>> 24 ) & 0xFF;
	g = ( hexcolor >>> 16 ) & 0xFF;
	b = ( hexcolor >>> 8 ) & 0xFF;
	a = hexcolor & 0xFF;
}


stock IntToHex(r, g, b, a = 255)//make a color
{
	return 	(r * 16777216) 	+
			(g * 65536)		+
			(g * 256)		+
			a;
}

stock GetColorBetweenColors(ColorA, ColorB, Float:Percent)
{
	new R1, G1, B1, A1, R2, G2, B2, A2;

	HexToInt(ColorA, R1, G1, B1, A1);
	HexToInt(ColorB, R2, G2, B2, A2);

	return IntToHex(
		floatround(Percent * (R2-R1)) + R1,
        	floatround(Percent * (G2-G1)) + G1,
        	floatround(Percent * (B2-B1)) + B1,
        	floatround(Percent * (A2-A1)) + A1
	);
}

//Embeded colors
//different embeded color shades of red
#define INDIAN_RED 				"{CD5C5C}"
#define LIGHT_CORAL 			"{F08080}"
#define SALMON 					"{FA8072}"
#define DARK_SALMON 			"{E9967A}"
#define LIGHT_SALMON 			"{FFA07A}"
#define CRIMSON 				"{DC143C}"
#define RED 					"{FF0000}"
#define FIREBRICK	 			"{B22222}"
#define DARK_RED 				"{8B0000}"

//different embeded color shades of pink
#define PINK 					"{FFC0CB}"
#define LIGHT_PINK 				"{FFB6C1}"
#define HOT_PINK 				"{FF69B4}"
#define DEEP_PINK 				"{FF1493}"
#define MEDIUM_VIOLET_RED 		"{C71585}"
#define PALE_VIOLET_RED 		"{DB7093}"

//different embeded color shades of Orange
#define CORAL 					"{FF7F50}"
#define TOMATO 					"{FF6347}"
#define ORANGE_RED 				"{FF4500}"
#define DARK_ORANGE 			"{FF8C00}"
#define ORANGE 					"{FFA500}"

//different embeded color shades of Yellow
#define GOLD 					"{FFD700}"
#define YELLOW		 			"{FFFF00}"
#define LIGHT_YELLOW 			"{FFFFE0}"
#define LEMON_CHIFFON 			"{FFFACD}"
#define LIGHT_GOLDENROD_YELLOW 	"{FAFAD2}"
#define PAPAYAWHIP 				"{FFEFD5}"
#define MOCCASIN 				"{FFE4B5}"
#define PEACHPUFF 				"{FFDAB9}"
#define PALE_GOLDENROD 			"{EEE8AA}"
#define KHAKI 					"{F0E68C}"
#define DARK_KHAKI 				"{BDB76B}"

//different embeded color shades of Purple
#define LAVENDER 				"{E6E6FA}"
#define THISTLE 				"{D8BFD8}"
#define PLUM 					"{DDA0DD}"
#define VIOLET 					"{EE82EE}"
#define ORCHID 					"{DA70D6}"
#define FUCHSIA 				"{FF00FF}"
#define MAGENTA 				"{FF00FF}"
#define MEDIUM_ORCHID 			"{BA55D3}"
#define MEDIUM_PURPLE 			"{9370DB}"
#define AMETHYST 				"{9966CC}"
#define BLUE_VIOLET 			"{8A2BE2}"
#define DARK_VIOLET 			"{9400D3}"
#define DARK_ORCHID 			"{9932CC}"
#define DARK_MAGENTA			"{8B008B}"
#define PURPLE 					"{800080}"
#define INDIGO 					"{4B0082}"
#define SLATE_BLUE 				"{6A5ACD}"
#define DARK_SLATE_BLUE 		"{483D8B}"
#define MEDIUM_SLATEBLUE 		"{7B68EE}"

//different embeded color shades of Green
#define GREEN_YELLOW 			"{ADFF2F}"
#define CHARTREUSE 				"{7FFF00}"
#define LAWN_GREEN 				"{7CFC00}"
#define LIME 					"{00FF00}"
#define LIME_GREEN 				"{32CD32}"
#define PALE_GREEN 				"{98FB98}"
#define LIGHT_GREEN 			"{90EE90}"
#define MEDIUM_SPRING_GREEN 	"{00FA9A}"
#define SPRING_GREEN 			"{00FF7F}"
#define MEDIUM_SEA_GREEN 		"{3CB371}"
#define SEA_GREEN 				"{2E8B57}"
#define FOREST_GREEN 			"{228B22}"
#define GREEN 					"{008000}"
#define DARK_GREEN 				"{006400}"
#define YELLOW_GREEN 			"{9ACD32}"
#define OLIVED_RAB 				"{6B8E23}"
#define OLIVE 					"{808000}"
#define DARK_OLIVE_GREEN 		"{556B2F}"
#define MEDIUM_AQUA_MARINE 		"{66CDAA}"
#define DARK_SEA_GREEN 			"{8FBC8F}"
#define LIGHT_SEA_GREEN 		"{20B2AA}"
#define DARK_CYAN	 			"{008B8B}"
#define TEAL 					"{008080}"

//different embeded color shades of Blue/Cyan
#define AQUA 					"{00FFFF}"
#define CYAN 					"{00FFFF}"
#define LIGHT_CYAN 				"{E0FFFF}"
#define PALE_TURQUOISE 			"{AFEEEE}"
#define AQUA_MARINE 			"{7FFFD4}"
#define TURQUOISE 				"{40E0D0}"
#define MEDIUM_TURQUOISE 		"{48D1CC}"
#define DARK_TURQUOISE 			"{00CED1}"
#define CADET_BLUE	 			"{5F9EA0}"
#define STEEL_BLUE 				"{4682B4}"
#define LIGHT_STEEL_BLUE 		"{B0C4DE}"
#define POWDER_BLUE 			"{B0E0E6}"
#define LIGHT_BLUE 				"{A9C4E4}"
#define SKY_BLUE 				"{87CEEB}"
#define LIGHT_SKYBLUE 			"{87CEFA}"
#define DEEP_SKY_BLUE 			"{00BFFF}"
#define DODGER_BLUE 			"{1E90FF}"
#define CORN_FLOWER_BLUE 		"{6495ED}"
#define MEDIUMSLATE_BLUE 		"{7B68EE}"
#define ROYAL_BLUE 				"{4169E1}"
#define BLUE 					"{0000FF}"
#define MEDIUM_BLUE 			"{0000CD}"
#define DARK_BLUE 				"{00008B}"
#define NAVY 					"{000080}"
#define MIDNIGHT_BLUE 			"{191970}"

//different embeded color shades of Brown
#define CORN_SILK 				"{FFF8DC}"
#define BLANCHED_ALMOND 		"{FFEBCD}"
#define BISQUE 					"{FFE4C4}"
#define NAVAJO_WHITE 			"{FFDEAD}"
#define WHEAT 					"{F5DEB3}"
#define BURLY_WOOD 				"{DEB887}"
#define TAN 					"{D2B48C}"
#define ROSY_BROWN 				"{BC8F8F}"
#define SANDY_BROWN 			"{F4A460}"
#define DARK_GOLDENROD 			"{B8860B}"
#define PERU 					"{CD853F}"
#define SADDLE_BROWN 			"{8B4513}"
#define SIENNA 					"{A0522D}"
#define BROWN 					"{A52A2A}"
#define MAROON 					"{800000}"

//different embeded color shades of Grey
#define WHITE 					"{FFFFFF}"
#define GAINSBORO 				"{DCDCDC}"
#define LIGHT_GREY 				"{D3D3D3}"
#define SILVER 					"{C0C0C0}"
#define DARK_GRAY 				"{A9A9A9}"
#define GRAY 					"{808080}"
#define DIM_GRAY 				"{696969}"
#define LIGHT_SLATE_GRAY		"{778899}"
#define SLATE_GRAY 				"{708090}"
#define DARK_SLATE_GRAY 		"{2F4F4F}"
#define BLACK 					"{000000}"

//HEX colors
//different color shades of red
#define COLOR_INDIAN_RED 		0xCD5C5CFF
#define COLOR_LIGHT_CORAL 		0xF08080FF
#define COLOR_SALMON 			0xFA8072FF
#define COLOR_DARK_SALMON 		0xE9967AFF
#define COLOR_LIGHT_SALMON 		0xFFA07AFF
#define COLOR_CRIMSON 			0xDC143CFF
#define COLOR_RED 				0xFF0000FF
#define COLOR_FIREBRICK	 		0xB22222FF
#define COLOR_DARK_RED 			0x8B0000FF

//different color shades of pink
#define COLOR_PINK 				0xFFC0CBFF
#define COLOR_LIGHT_PINK 		0xFFB6C1FF
#define COLOR_HOT_PINK 			0xFF69B4FF
#define COLOR_DEEP_PINK 		0xFF1493FF
#define COLOR_MEDIUM_VIOLET_RED 0xC71585FF
#define COLOR_PALE_VIOLET_RED 	0xDB7093FF

//different color shades of Orange
#define COLOR_CORAL 			0xFF7F50FF
#define COLOR_TOMATO 			0xFF6347FF
#define COLOR_ORANGE_RED 		0xFF4500FF
#define COLOR_DARK_ORANGE 		0xFF8C00FF
#define COLOR_ORANGE 			0xFFA500FF

//different color shades of Yellow
#define COLOR_GOLD 				0xFFD700FF
#define COLOR_YELLOW		 	0xFFFF00FF
#define COLOR_LIGHT_YELLOW 		0xFFFFE0FF
#define COLOR_LEMON_CHIFFON 	0xFFFACDFF
#define COLOR_LIGHT_GOLDENROD_YELLOW 0xFAFAD2FF
#define COLOR_PAPAYAWHIP 		0xFFEFD5FF
#define COLOR_MOCCASIN 			0xFFE4B5FF
#define COLOR_PEACHPUFF 		0xFFDAB9FF
#define COLOR_PALE_GOLDENROD 	0xEEE8AAFF
#define COLOR_KHAKI 			0xF0E68CFF
#define COLOR_DARK_KHAKI 		0xBDB76BFF

//different color shades of Purple
#define COLOR_LAVENDER 			0xE6E6FAFF
#define COLOR_THISTLE 			0xD8BFD8FF
#define COLOR_PLUM 				0xDDA0DDFF
#define COLOR_VIOLET 			0xEE82EEFF
#define COLOR_ORCHID 			0xDA70D6FF
#define COLOR_FUCHSIA 			0xFF00FFFF
#define COLOR_MAGENTA 			0xFF00FFFF
#define COLOR_MEDIUM_ORCHID 	0xBA55D3FF
#define COLOR_MEDIUM_PURPLE 	0x9370DBFF
#define COLOR_AMETHYST 			0x9966CCFF
#define COLOR_BLUE_VIOLET 		0x8A2BE2FF
#define COLOR_DARK_VIOLET 		0x9400D3FF
#define COLOR_DARK_ORCHID 		0x9932CCFF
#define COLOR_DARK_MAGENTA		0x8B008BFF
#define COLOR_PURPLE 			0x800080FF
#define COLOR_INDIGO 			0x4B0082FF
#define COLOR_SLATE_BLUE 		0x6A5ACDFF
#define COLOR_DARK_SLATE_BLUE 	0x483D8BFF
#define COLOR_MEDIUM_SLATEBLUE 	0x7B68EEFF

//different color shades of Green
#define COLOR_GREEN_YELLOW 		0xADFF2FFF
#define COLOR_CHARTREUSE 		0x7FFF00FF
#define COLOR_LAWN_GREEN 		0x7CFC00FF
#define COLOR_LIME 				0x00FF00FF
#define COLOR_LIME_GREEN 		0x32CD32FF
#define COLOR_PALE_GREEN 		0x98FB98FF
#define COLOR_LIGHT_GREEN 		0x90EE90FF
#define COLOR_MEDIUM_SPRING_GREEN 0x00FA9AFF
#define COLOR_SPRING_GREEN 		0x00FF7FFF
#define COLOR_MEDIUM_SEA_GREEN 	0x3CB371FF
#define COLOR_SEA_GREEN 		0x2E8B57FF
#define COLOR_FOREST_GREEN 		0x228B22FF
#define COLOR_GREEN 			0x008000FF
#define COLOR_DARK_GREEN 		0x006400FF
#define COLOR_YELLOW_GREEN 		0x9ACD32FF
#define COLOR_OLIVED_RAB 		0x6B8E23FF
#define COLOR_OLIVE 			0x808000FF
#define COLOR_DARK_OLIVE_GREEN 	0x556B2FFF
#define COLOR_MEDIUM_AQUA_MARINE 0x66CDAAFF
#define COLOR_DARK_SEA_GREEN 	0x8FBC8FFF
#define COLOR_LIGHT_SEA_GREEN 	0x20B2AAFF
#define COLOR_DARK_CYAN	 		0x008B8BFF
#define COLOR_TEAL 				0x008080FF

//different color shades of Blue/Cyan
#define COLOR_AQUA 				0x00FFFFFF
#define COLOR_CYAN 				0x00FFFFFF
#define COLOR_LIGHT_CYAN 		0xE0FFFFFF
#define COLOR_PALE_TURQUOISE 	0xAFEEEEFF
#define COLOR_AQUA_MARINE 		0x7FFFD4FF
#define COLOR_TURQUOISE 		0x40E0D0FF
#define COLOR_MEDIUM_TURQUOISE 	0x48D1CC
#define COLOR_DARK_TURQUOISE 	0x00CED1FF
#define COLOR_CADET_BLUE	 	0x5F9EA0FF
#define COLOR_STEEL_BLUE 		0x4682B4FF
#define COLOR_LIGHT_STEEL_BLUE 	0xB0C4DEFF
#define COLOR_POWDER_BLUE 		0xB0E0E6FF
#define COLOR_LIGHT_BLUE 		0xA9C4E4FF
#define COLOR_SKY_BLUE 			0x87CEEBFF
#define COLOR_LIGHT_SKYBLUE 	0x87CEFAFF
#define COLOR_DEEP_SKY_BLUE 	0x00BFFFFF
#define COLOR_DODGER_BLUE 		0x1E90FFFF
#define COLOR_CORN_FLOWER_BLUE 	0x6495EDFF
#define COLOR_MEDIUMSLATE_BLUE 	0x7B68EEFF
#define COLOR_ROYAL_BLUE 		0x4169E1FF
#define COLOR_BLUE 				0x0000FFFF
#define COLOR_MEDIUM_BLUE 		0x0000CDFF
#define COLOR_DARK_BLUE 		0x00008BFF
#define COLOR_NAVY 				0x000080FF
#define COLOR_MIDNIGHT_BLUE 	0x191970FF

//different color shades of Brown
#define COLOR_CORN_SILK 		0xFFF8DCFF
#define COLOR_BLANCHED_ALMOND 	0xFFEBCDFF
#define COLOR_BISQUE 			0xFFE4C4FF
#define COLOR_NAVAJO_WHITE 		0xFFDEADFF
#define COLOR_WHEAT 			0xF5DEB3FF
#define COLOR_BURLY_WOOD 		0xDEB887FF
#define COLOR_TAN 				0xD2B48CFF
#define COLOR_ROSY_BROWN 		0xBC8F8FFF
#define COLOR_SANDY_BROWN 		0xF4A460FF
#define COLOR_DARK_GOLDENROD 	0xB8860BFF
#define COLOR_PERU 				0xCD853FFF
#define COLOR_SADDLE_BROWN 		0x8B4513FF
#define COLOR_SIENNA 			0xA0522DFF
#define COLOR_BROWN 			0xA52A2AFF
#define COLOR_MAROON 			0x800000FF

//different color shades of Grey
#define COLOR_WHITE 			0xFFFFFFFF
#define COLOR_GAINSBORO 		0xDCDCDCFF
#define COLOR_LIGHT_GREY 		0xD3D3D3FF
#define COLOR_SILVER 			0xC0C0C0FF
#define COLOR_DARK_GRAY 		0xA9A9A9FF
#define COLOR_GRAY 				0x808080FF
#define COLOR_DIM_GRAY 			0x696969FF
#define COLOR_LIGHT_SLATE_GRAY 	0x778899FF
#define COLOR_SLATE_GRAY 		0x708090FF
#define COLOR_DARK_SLATE_GRAY 	0x2F4F4FFF
#define COLOR_BLACK 			0x000000FF
