#include "ConsoleControl.h"

using namespace std;

struct Player
{
	//player hp
	int base_max_hp = 100;
	int max_hp;
	int cur_hp;
	float atk_dmg;
	int dodge_chance = 15;
	int crit_rate = 20;
	float crit_dmg_mult = 1.5f;
	int life_potions = 3;
};
struct Enemy
{
	//enemy hp
	int base_max_hp = 100;
	int max_hp;
	int cur_hp = 100;
	float atk_dmg = 20;
	int dodge_chance = 15;
	int crit_rate = 20;
	int crit_dmg_mult = 1.5;
	int str_mult = 1;
};

Player player;
Enemy enemy;


void StartMessage() {
	ConsoleXY(31, 7);
	cout << "Welcome brave warrior... to the INFINITE DUNGEON!" << endl;
	ConsoleXY(25, 8);
	cout << "Every floor has only one enemy. Defeat it to go to the next floor." << endl;
	ConsoleXY(40, 9);
	cout << "Each floor has a stronger enemy" << endl;
	ConsoleXY(33, 10);
	cout << "Good luck brave warrior, may the force be with you" << endl;
	system("pause");
	system("cls");
}

void Pstats() {
	system("cls");
	cout << "Your Stats:" << endl;
	cout << "--------------" << endl;
	cout << "HP: " << player.cur_hp << endl;
	cout << "Atack dmg: " << player.atk_dmg << endl;
	cout << "Dodge chance: " << player.dodge_chance << endl;
	cout << "Crit rate: " << player.crit_rate << endl;
	cout << "Crit mult: " << player.crit_dmg_mult << endl;
	cout << "life potions: " << player.life_potions << endl;
}