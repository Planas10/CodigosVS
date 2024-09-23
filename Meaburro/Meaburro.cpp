#include <iostream>
#include "Stats.h"

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


//Combate
void StartStats() {
	player.max_hp = player.base_max_hp;
	player.cur_hp = player.max_hp;

	enemy.max_hp = enemy.base_max_hp;
	enemy.cur_hp = enemy.max_hp;
}

void MainGame() {
	StartStats();
	StartMessage();
	Pstats();

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



int main()
{
	//MainGame();
}
