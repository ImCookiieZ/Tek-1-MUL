const int collision[15][28] = {
	{403 ,404 ,152 ,152 ,152 ,152 ,152 ,152 ,152 ,707 ,708 ,708 ,708 ,708 ,709 ,152 ,608 ,433 ,433 ,433 ,609 ,152 ,0 ,0 ,468 ,470 ,608 ,609},
	{431 ,432 ,152 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,152 ,461 ,461 ,461 ,461 ,461 ,152 ,0 ,0 ,0 ,0 ,0 ,18},
	{152 ,152 ,152 ,0 ,107 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,152 ,152 ,152 ,459 ,460 ,152 ,0 ,0 ,0 ,0 ,0 ,18},
	{152 ,152 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,9 ,0 ,0 ,0 ,152 ,152 ,487 ,488 ,152 ,152 ,0 ,0 ,0 ,0 ,736},
	{152 ,152 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,735},
	{404 ,152 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,735},
	{432 ,152 ,0 ,0 ,0 ,0 ,0 ,344 ,0 ,0 ,8 ,0 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,876 ,876 ,876 ,876 ,876 ,876 ,209 ,0 ,735},
	{152 ,152 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,152 ,235 ,132 ,237 ,152 ,764},
	{152 ,0 ,0 ,140 ,0 ,0 ,0 ,0 ,0 ,0 ,344 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,263 ,264 ,265 ,152 ,152},
	{152 ,0 ,0 ,0 ,0 ,0 ,0 ,9 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,438 ,0 ,0 ,0 ,0 ,0 ,0 ,152 ,152 ,152 ,152 ,152},
	{152 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,9 ,0 ,0 ,435 ,436 ,437 ,0 ,9 ,0 ,0 ,0 ,0 ,0 ,0 ,152 ,152 ,403 ,404 ,152},
	{737 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,152 ,431 ,432 ,152},
	{735 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,8 ,8 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,152 ,152 ,152 ,152},
	{765 ,0 ,0 ,0 ,0 ,0 ,435 ,436 ,437 ,0 ,8 ,0 ,344 ,0 ,0 ,344 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{1034 ,972 ,443 ,428 ,428 ,428 ,428 ,429 ,8 ,344 ,344 ,344 ,456 ,8 ,427 ,428 ,428 ,428 ,428 ,18 ,0 ,0 ,0 ,736 ,708 ,708 ,709 ,623},
};

const int my_link[15][28] = {
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,758 ,757 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,1 ,1 ,0 ,0 ,0 ,0 ,0},
};