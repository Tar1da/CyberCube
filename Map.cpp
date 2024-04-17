#include "Map.h"

Map::Map() :
	height(16), width(150),
	offset_x(0), offset_y(0)
{
		map = new String[16]{
	"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"0                                                                                                                                                    0",
	"0                                                                                                                                                    0",
	"0                                                                                                                                                    0",
	"0                                                                                                                                                    0",
	"0                                                                                                                                                    0",
	"0                                                                                                                                w                   0",
	"0                                                w                                                                                                   0",
	"0                                                                                                                                                    0",
	"0     w                                                                                            cccccc                                            0",
	"0                        ckckc                                            c        kkkkk                        k                                    0",
	"0                  w                   t0                                         w         t0                                                       0",
	"0                                      00              t0                                   00              t0                                       0",
	"0                                      00              00                                   00              00                                       0",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
	};
}
