#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "ConsoleControl.h"
#include "Utils.h"

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
	int floors_completed = 0;
};
struct Enemy
{
	//enemy hp
	string name = "Great orc";
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

string action = "";


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
	cout << "Crit rate: " << player.crit_rate << endl;
	cout << "Crit mult: " << player.crit_dmg_mult << endl;
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

//Battle func
void Battle() {
	bool turn_finish;
	bool GameOver = false;
	while (GameOver == false)
	{
		cout << "current floor: " << player.floors_completed << endl;
		cout << "Player:" << endl;
		cout << "---------------" << endl;
		cout << "HP: " << player.cur_hp << endl;
		cout << "atk dmg: " << player.atk_dmg << endl;
		cout << "potions left: " << player.life_potions << endl;
		getline(cin, action);
		vector<string> split_combat_move = splitString(action, ' ');
		if (split_combat_move.size() > 0)
		{
			if (split_combat_move.size() == 1)
			{
				if (split_combat_move[0] == "help")
				{
					ShowHelp();
				}
				if (split_combat_move[0] == "stats")
				{

				}
				if (split_combat_move[0] == "atack")
				{

				}
				if (split_combat_move[0] == "potion")
				{
					//Healing
					if (player.life_potions > 0)
					{
						if (player.cur_hp == player.max_hp)
						{
							cout << "Hp at max, can't use a potion" << endl;
						}
						else
						{
							player.cur_hp += 50;
							if (player.cur_hp > player.max_hp)
							{
								player.cur_hp = player.max_hp;
							}
						}
					}
					else
					{
						cout << "Not enough potions" << endl;
					}
				}
			}
			else
			{
				cout << "wrong option" << endl;
			}
		}
		system("pause");
		system("cls");
	}

}

//Potions func

//Game Over func