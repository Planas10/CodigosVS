#include <iostream>
#include <vector>
#include <string>
#include "ConsoleControl.h"
#include "Utils.h"

using namespace std;

struct Player
{
	//player hp
	int base_max_hp = 100;
	int max_hp;
	int cur_hp;
	int atk_dmg = 10;
	int no_crit_atk_dmg;
	int dodge_chance = 10;
	int crit_rate = 10;
	int crit_dmg_mult = 2;
	int life_potions = 3;
	int potion_heal = 50;
	int floors_completed = 0;
};
struct Enemy
{
	//enum enemytypes {ORC, TROLL, GREAT_ORC, DEMON};
	const string names[5] = {"Orc", "Great Orc", "Troll", "Demon", "Great Demon"};
	string name;
	int base_max_hp = 100;
	int max_hp;
	int cur_hp = 100;
	int atk_dmg = 10;
	int no_crit_atk_dmg;
	//dodge_chance 10%
	//crit_rate 10%
	int crit_dmg_mult = 2;
	int str_mult = 1;
};

Player player;
Enemy enemy;

string action = "";

void StartStats() {
	player.max_hp = player.base_max_hp;
	player.cur_hp = player.max_hp;
	player.no_crit_atk_dmg = player.atk_dmg;

	enemy.max_hp = enemy.base_max_hp;
	enemy.cur_hp = enemy.max_hp;
	enemy.no_crit_atk_dmg = enemy.atk_dmg;
	enemy.name = enemy.names[rand() % 5];
}

void StartMessage() {
	system("cls");
	ConsoleXY(31, 7);
	cout << "Welcome brave warrior... to the INFINITE DUNGEON!" << endl;
	ConsoleXY(25, 8);
	cout << "Every floor has only one enemy. Defeat it to go to the next floor." << endl;
	ConsoleXY(40, 9);
	cout << "Each floor has a stronger enemy" << endl;
	ConsoleXY(33, 10);
	cout << "Good luck brave warrior, may the force be with you" << endl;
	system("pause");
}

void Pstats() {
	system("cls");
	cout << "Your Stats:" << endl;
	cout << "--------------" << endl;
	cout << "HP: " << player.cur_hp << endl;
	cout << "Atack dmg: " << player.atk_dmg << endl;
	cout << "Dodge chance: " << player.dodge_chance << endl;
	cout << "Crit rate: " << player.crit_rate << "%" << endl;
	cout << "x" << "Crit mult: " << player.crit_dmg_mult << endl;
	cout << "life potions: " << player.life_potions << endl;
}

//HowToPlay func
void HowToPlay() {
	system("cls");
	ConsoleXY(31, 7);
	cout << "Before starting, you need to know how this works." << endl;
	ConsoleXY(25, 8);
	cout << "To do anything you need to write down a command." << endl;
	ConsoleXY(33, 9);
	cout << "You can use the commands listed below." << endl;
	ConsoleXY(33, 10);
	cout << "[help, stats, attack, potion]" << endl;
	system("pause");
	system("cls");
	ConsoleXY(31, 7);
	cout << "Now you are ready to face the INFINITE DUNGEON!!" << endl;
	system("pause");
	system("cls");
}

void ShowHelp() {
	system("cls");
	cout << "[Stats]-> Show your current stats" << endl;
	cout << "[Atack]-> Atacks your enemy" << endl;
	cout << "[Potion] -> Use a potion to restore 50hp" << endl;
}

void ShowInGameStats() {
	system("cls");
	cout << "current floor: " << player.floors_completed << endl;
	cout << "Player:" << endl;
	cout << "- - - - - -" << endl;
	cout << "HP: " << player.cur_hp << endl;
	cout << "atk dmg: " << player.atk_dmg << endl;
	cout << "potions left: " << player.life_potions << endl;
	cout << "---------------------------------" << endl;
	ConsoleXY(20, 1);
	cout << "Enemy:" << endl;
	ConsoleXY(20, 2);
	cout << "- - - - - -" << endl;
	ConsoleXY(20, 3);
	cout << "HP: " << enemy.cur_hp << endl;
	ConsoleXY(20, 4);
	cout << "atk dmg: " << enemy.atk_dmg << endl;
	ConsoleXY(0, 7);
	cout << "actions: [help][stats][attack][potion]" << endl << endl;
	cout << "What will you do: ";
}

void NextEnemy() {
	enemy.str_mult++;
	enemy.max_hp = enemy.base_max_hp * enemy.str_mult;
	enemy.cur_hp = enemy.max_hp;
	enemy.no_crit_atk_dmg = enemy.atk_dmg * enemy.str_mult;
	enemy.name = enemy.names[rand() % 5];
}