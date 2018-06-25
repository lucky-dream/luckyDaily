#include"util/ascii.h"
namespace luckyDaily
{
	const int ascii::CHARACTER_PROPERTIES[128] =
	{
		/* 00 . */ US_ACP_CONTROL,
		/* 01 . */ US_ACP_CONTROL,
		/* 02 . */ US_ACP_CONTROL,
		/* 03 . */ US_ACP_CONTROL,
		/* 04 . */ US_ACP_CONTROL,
		/* 05 . */ US_ACP_CONTROL,
		/* 06 . */ US_ACP_CONTROL,
		/* 07 . */ US_ACP_CONTROL,
		/* 08 . */ US_ACP_CONTROL,
		/* 09 . */ US_ACP_CONTROL | US_ACP_SPACE,
		/* 0a . */ US_ACP_CONTROL | US_ACP_SPACE,
		/* 0b . */ US_ACP_CONTROL | US_ACP_SPACE,
		/* 0c . */ US_ACP_CONTROL | US_ACP_SPACE,
		/* 0d . */ US_ACP_CONTROL | US_ACP_SPACE,
		/* 0e . */ US_ACP_CONTROL,
		/* 0f . */ US_ACP_CONTROL,
		/* 10 . */ US_ACP_CONTROL,
		/* 11 . */ US_ACP_CONTROL,
		/* 12 . */ US_ACP_CONTROL,
		/* 13 . */ US_ACP_CONTROL,
		/* 14 . */ US_ACP_CONTROL,
		/* 15 . */ US_ACP_CONTROL,
		/* 16 . */ US_ACP_CONTROL,
		/* 17 . */ US_ACP_CONTROL,
		/* 18 . */ US_ACP_CONTROL,
		/* 19 . */ US_ACP_CONTROL,
		/* 1a . */ US_ACP_CONTROL,
		/* 1b . */ US_ACP_CONTROL,
		/* 1c . */ US_ACP_CONTROL,
		/* 1d . */ US_ACP_CONTROL,
		/* 1e . */ US_ACP_CONTROL,
		/* 1f . */ US_ACP_CONTROL,
		/* 20   */ US_ACP_SPACE | US_ACP_PRINT,
		/* 21 ! */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 22 " */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 23 # */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 24 $ */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 25 % */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 26 & */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 27 ' */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 28 ( */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 29 ) */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 2a * */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 2b + */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 2c , */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 2d - */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 2e . */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 2f / */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 30 0 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 31 1 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 32 2 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 33 3 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 34 4 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 35 5 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 36 6 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 37 7 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 38 8 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 39 9 */ US_ACP_DIGIT | US_ACP_HEXDIGIT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 3a : */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 3b ; */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 3c < */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 3d = */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 3e > */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 3f ? */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 40 @ */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 41 A */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 42 B */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 43 C */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 44 D */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 45 E */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 46 F */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 47 G */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 48 H */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 49 I */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 4a J */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 4b K */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 4c L */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 4d M */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 4e N */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 4f O */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 50 P */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 51 Q */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 52 R */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 53 S */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 54 T */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 55 U */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 56 V */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 57 W */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 58 X */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 59 Y */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 5a Z */ US_ACP_ALPHA | US_ACP_UPPER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 5b [ */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 5c \ */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 5d ] */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 5e ^ */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 5f _ */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 60 ` */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 61 a */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 62 b */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 63 c */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 64 d */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 65 e */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 66 f */ US_ACP_HEXDIGIT | US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 67 g */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 68 h */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 69 i */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 6a j */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 6b k */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 6c l */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 6d m */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 6e n */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 6f o */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 70 p */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 71 q */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 72 r */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 73 s */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 74 t */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 75 u */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 76 v */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 77 w */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 78 x */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 79 y */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 7a z */ US_ACP_ALPHA | US_ACP_LOWER | US_ACP_GRAPH | US_ACP_PRINT,
		/* 7b { */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 7c | */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 7d } */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 7e ~ */ US_ACP_PUNCT | US_ACP_GRAPH | US_ACP_PRINT,
		/* 7f . */ US_ACP_CONTROL
	};

} 