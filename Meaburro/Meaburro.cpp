#include <iostream>
#include <random>
#include "FuncManager.h"

using namespace std;

//3N+1
float n;
float m;
div_t a;

void CheckParOdd() {
	a = div(n, 2);
}
void cosa1() {
	cout << "Dame un numero: ";
	cin >> n;
	while (n > 1)
	{
		CheckParOdd();
		if (a.rem == 0)
		{
			n = n / 2;
		}
		else
		{
			n = 3 * n + 1;
		}
		cout << n << endl;
	}
}

//3N+1 automatico
void cosa2() {
	n = 1;
	m = n;
	for (size_t i = 0; i < 100; i++)
	{
		cout << n << endl;
		while (n > 1)
		{
			CheckParOdd();
			if (a.rem == 0)
			{
				n = n / 2;
			}
			else
			{
				n = 3 * n + 1;
			}
			cout << n << endl;
		}
		m = m + 1;
		n = m;
		system("pause");
	}
}

//Tres en raya
const int x = 3;
const int y = 3;
bool Awinner;
int playerW;
char MAP[x][y] = {
{ '#','#','#' },
{ '#','#','#' },
{ '#','#','#' },
};

void CreateMap() {
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			cout << MAP[i][j];
		}
		cout << endl;
	}
}

void CheckWinner(int a, int b) {
	//Comprobar filas ganadoras
	for (size_t i = 0; i < 2; i++)
	{
		if (MAP[i][0] == MAP[i][1] && MAP[i][1] == MAP[i][2] && MAP[i][0] != '#') { Awinner = true; }
	}
	//Comprobar columnas ganadoras
	for (size_t i = 0; i < 2; i++)
	{
		if (MAP[0][i] == MAP[1][i] && MAP[1][i] == MAP[2][i] && MAP[0][i] != '#') { Awinner = true; }
	}
	//Comprovar diagonal 1
	if (MAP[0][0] == MAP[1][1] && MAP[1][1] == MAP[2][2] && MAP[1][1] != '#') { Awinner = true; }
	//Comprovar diagonal 2
	if (MAP[2][0] == MAP[1][1] && MAP[1][1] == MAP[0][2] && MAP[1][1] != '#') { Awinner = true; }

	//Comprovar quien gana
	if (Awinner == true)
	{
		switch (MAP[a][b])
		{
		case 'O':
			playerW = 1;
			break;
		case 'X':
			playerW = 2;
			break;
		default:
			break;
			
		}
	}
}

void TresEnRaya() {
	Awinner = false;
	cout << "Tres en raya" << endl; cout << "Elije casilla escribiendo coordenadas" << endl; cout << "[fila 0-2][columna 0-2]" << endl;
	int a = 0;
	int b = 0;
	bool p1turndone = false;
	bool p2turndone = false;
	int turnos = 9;
	bool canPlaceXO = false;
	while (turnos > 0)
	{
		system("cls");
		CreateMap();
		//Turno jugador 1
		while (p1turndone == false) {
			cout << "turno jugador 1: " << endl;
			cin >> a; cin >> b;
			if (a > 2 || a < 0 || b > 2 || b < 0 || MAP[a][b] != '#'){
				cout << "Movimiento no valido" << endl;
				canPlaceXO = false;
			}
			else { canPlaceXO = true; }
			if (canPlaceXO)	{
				MAP[a][b] = 'O';
				p1turndone = true;
				p2turndone = false;
			}
		}
		CheckWinner(a, b);
		if (Awinner == true)
		{
			break;
		}
		system("cls");
		CreateMap();
		//Turno jugador 2
		while (p2turndone == false) {
			cout << "turno jugador 2: " << endl;
			cin >> a; cin >> b;
			if (a > 2 || a < 0 || b > 2 || b < 0 || MAP[a][b] != '#') {
				cout << "Movimiento no valido" << endl;
				canPlaceXO = false;
			}
			else { canPlaceXO = true; }
			if (canPlaceXO)	{
				MAP[a][b] = 'X';
				p2turndone = true;
				p1turndone = false;
			}
		}
		CheckWinner(a, b);
		if (Awinner == true)
		{
			break;
		}
	}
	//Mostrar mensaje segun el ganador
	switch (playerW)
	{
	case 1:
		system("cls");
		CreateMap();
		cout << "Gana jugador 1";
		break;
	case 2:
		system("cls");
		CreateMap();
		cout << "Gana jugador 2";
		break;
	default:
		break;
	}
}

void ejercicioNota() {
	int x;

	while (true)
	{
		cout << "Dame una nota entre 0 y 10: " << endl;
		cin >> x;
		if (x >= 0 && x <= 10)
		{
			if (x >= 0 && x < 3)
			{
				cout << "Muy deficiente";
				break;
			}
			if (x >= 3 && x < 5)
			{
				cout << "Insuficiente";
				break;
			}
			if (x >= 5 && x < 6)
			{
				cout << "Bien";
				break;
			}
			if (x >= 6 && x < 9)
			{
				cout << "Notable";
				break;
			}
			if (x >= 9 && x == 10)
			{
				cout << "Sobresaliente";
				break;
			}
		}
		else
		{
			system("cls");
			cout << "Dame una nota valida" << endl;
		}
	}
}

void ejercicioComparacionNumeros() {
	int x;
	int y;
	int z;

	cout << "Dame un numero x: ";
	cin >> x; cout << endl;
	cout << "Dame un numero y: ";
	cin >> y; cout << endl;
	cout << "Dame un numero z: ";
	cin >> z; cout << endl;

	if (x == y && y == z)
	{
		cout << "Son todos iguales" << endl;
	}
	else
	{
		if (x > y)
		{
			if (x > z)
			{
				cout << x << " es mayor que el resto" << endl;
			}
			else
			{
				cout << z << " es mayor que el resto" << endl;
			}
		}
		else
		{
			if (y > z)
			{
				cout << y << " es mayor que el resto" << endl;
			}
			else
			{
				cout << z << " es mayor que el resto" << endl;
			}
		}
	}
}


//Infinite Dungeon

void PlayerTurn(bool turn) {
	bool invalidAction = false;
	while (!turn)
	{
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
					Pstats();
				}
				if (split_combat_move[0] == "attack")
				{
					//enemy dodge
					int eDodgeChance = rand() % 5 + 1;
					if (eDodgeChance == 1)
					{
						cout << endl << "lmao, you got dodged, skill issue" << endl;
						turn = true;
					}
					else
					{
						//player crit
						int pCritChance = rand() % 5 + 1;
						if (pCritChance == 1)
						{
							cout << "Crit!! ";
							player.atk_dmg *= player.crit_dmg_mult;
						}
						enemy.cur_hp -= player.atk_dmg;
						cout << endl << "Enemy loses " << player.atk_dmg << "Hp" << endl;
						player.atk_dmg = player.no_crit_atk_dmg;
						turn = true;
					}
				}
				if (split_combat_move[0] == "potion")
				{
					//Healing
					if (player.life_potions > 0)
					{
						if (player.cur_hp == player.max_hp)
						{
							cout << endl << "Hp at max, can't use a potion" << endl;
							invalidAction = true;
						}
						else
						{
							player.cur_hp += player.potion_heal;
							if (player.cur_hp > player.max_hp)
							{
								cout << endl << "You recovered " << player.cur_hp - player.max_hp << "Hp" << endl;
								player.cur_hp = player.max_hp;
							}
							else
							{
								cout << endl << "You recovered " << player.potion_heal<< "Hp" << endl;
							}
							turn = true;
							player.life_potions--;
						}
					}
					else
					{
						cout << "Not enough potions" << endl << endl;
						invalidAction = true;
					}
				}
			}
			else
			{
				cout << "wrong option" << endl << endl;
				invalidAction = true;
			}
		}
		if (invalidAction)
		{
			system("pause");
			system("cls");
			ShowInGameStats();
			invalidAction = false;
		}
	}
}

void EnemyTurn(bool turn) {
	//enemy dodge
	cout << endl;
	int pDodgeChance = rand() % 5 + 1;
	if (pDodgeChance == 1)
	{
		cout << "Dodged lmao" << endl << endl;
		!turn;
	}
	else
	{
		//player crit
		int eCritChance = rand() % 5 + 1;
		if (eCritChance == 2)
		{
			cout << "Crit!! ";
			enemy.atk_dmg *= enemy.crit_dmg_mult;
		}
		player.cur_hp -= enemy.atk_dmg;
		cout << "You lose " << enemy.atk_dmg << "Hp" << endl << endl;
		enemy.atk_dmg = enemy.no_crit_atk_dmg;
		!turn;
	}
}

//Battle func
void Battle() {
	StartStats();
	bool turn_finish = false;
	bool GameOver = false;
	bool win = false;
	while (GameOver == false)
	{
		bool enemydefeated = false;
		while (enemydefeated == false)
		{
			ShowInGameStats();
			//Player turn
			PlayerTurn(turn_finish);
			if (enemy.cur_hp < 0 || enemy.cur_hp == 0) { enemydefeated = true; }
			if (enemydefeated) { 
				NextEnemy(); break;
			}
			//Enemy turn
			EnemyTurn(turn_finish);
			if (player.cur_hp < 0 || player.cur_hp == 0)
			{
				win = false;
				GameOver = true;
			}
			if (GameOver) { break; }
			system("pause");
			system("cls");
		}
	}
	if (win)
	{
		cout << "Victory" << endl;
	}
	else
	{
		cout << "Lmao skill issue you lose" << endl;
	}
}

void MainGame() {
	StartMessage();
	HowToPlay();
	Battle();
}

int main()
{
	MainGame();
}
