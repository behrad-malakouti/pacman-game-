///Generated By behrad malakouti and sepehr alipour from Helli 5 school
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

string m[7][7];
int score = 0;

struct Hero
{
	int x, y;
	set_hero()
	{
		m[y][x] = "H";
	}                                 //hero structure includes -> hero x, hero y and a function that sets the hero position in map
};

struct Enemy
{
	int x, y;
	set_enemy()
	{
		m[y][x] = "E";
	}
};									 //Enemy structure includes -> Enemy x, Enemy y and a function that sets the Enemy position in map

Hero h;   //Declare an Object from Hero struc
Enemy e;  //Declare an Object from Enemy struc


static void show_map()               ///This Function prints the map
{
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
			cout << m[i][j] << "\t";
		cout << "\n\n";
	}
}

void move_hero(int x, int y)     ///This Function gets the now x and now y of Hero and then it move the hero in the keys ways
{
	getch();                   //getch function get the button that is pressed
	getch();
	h.x = x;
	h.y = y;

	if(GetAsyncKeyState(VK_UP) && h.y - 1 != 0)          /*I use GetAsyncKeyState for checking the arrows key and then moving hero(1 unit) in */
	{								     				 /*the path that is defined by the specific arrow key.*/
		h.y -= 1;
		m[y][x] = "";
		if(m[h.y][h.x] == ".")
			score++;
		m[h.y][h.x] = "H";
	}
	else
		if(GetAsyncKeyState(VK_DOWN) && h.y + 1 != 6)
		{
			h.y += 1;
			m[y][x] = "";
			if(m[h.y][h.x] == ".")
				score++;
			m[h.y][h.x] = "H";
		}
		else
			if(GetAsyncKeyState(VK_RIGHT) && h.x + 1 != 6)
			{
				h.x += 1;
				m[y][x] = "";
				if(m[h.y][h.x] == ".")
					score++;
				m[h.y][h.x] = "H";
			}
			else
				if(GetAsyncKeyState(VK_LEFT) && h.x - 1 != 0)
				{
					h.x -= 1;
					m[y][x] = "";
					if(m[h.y][h.x] == ".")
						score++;
					m[h.y][h.x] = "H";
				}
}


static void set_map()                ///setting map function -> objects in map includes: Hero, Enemy, Dots, Walls
{
	int i2, j2, walls = 0;

	for(int i = 0; i < 7; i++)
	{
		if(i == 0 || i == 6)
		{
			for(int j = 0; j < 7; j++)
				m[i][j] = "#";
		}
		else
		{
			for(int j = 0; j < 7; j++)
			{
				if(j == 0 || j == 6)
					m[i][j] = "#";
			}
		}
	}    //Borders finished!


	h.x = 1;
	h.y = 1;
	h.set_hero();   /*Set Hero x and y in map*/

	e.x = 5;
	e.y = 5;
	e.set_enemy();  /*Set Enemy x and y in map*/

	while(walls < 15)
	{
		i2 = rand() % 7;
		j2 = rand() % 7;
		if(m[i2][j2] != "#" && m[i2][j2] != "H" && m[i2][j2] != "E")
		{
			m[i2][j2] = "#";
			walls++;
		}
	}                  /*Creating random system for walls in 1 to 5 x and y(1 to 5 because of borders)*/


	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(m[i][j] != "H" && m[i][j] != "E" && m[i][j] != "#")
				m[i][j] = ".";
			cout << m[i][j] << "\t";
		}
		cout << "\n\n";                   //Generating dots and Printing map(I don't use the show_map() function because I want to generate dots)
	}
}

void findpath(int hx, int hy, int ex, int ey)    ///a function that gets the hero and enemy x and y and then moves enemy to hero x and y
{
	if(hx < ex)
	{
		e.x -= 1;
		if (hy < ey)
			e.y -= 1;
		else
			e.y += 1;
	}
	else
	{
		e.x += 1;
		if(hy < ey)
			e.y -= 1;
		else
			e.y += 1;
	}

	m[ey][ex] = "";
	m[e.y][e.x] = "E";
}

int main()
{
	srand(time(NULL));    /*Generating random Seed*/

	string name;
	cout << "Please enter your name: ";               /*asking for the name*/
	cin >> name;

	bool running = true, win = false;

	set_map();
	Sleep(1000);               /*I use Sleep function because Sleep makes the progarm easy to play!:)*/

	while(running)
	{
		system("cls");       				   /*clearing system*/

		cout << "Score is " << score << ".\n"; /*Showing the Score on the Screen*/

		move_hero(h.x, h.y);   				   /*Moving hero from it's current x and y to a path which is defined by the arrow keys*/

		findpath(h.x, h.y, e.x, e.y);          /*calling the findpath function with hero and enemy x and y arguments*/

		show_map();            				   /*show the map after moving hero*/
		Sleep(1000);           				   /*Waiting for 1 second*/

		if(h.x == e.x && h.y == e.y)
			break;                             /*the losing condition*/

		if(score == 8)
		{                                      /*the winning condition*/
			win = true;
			break;
		}
	}

	if(win == false)
	{
		system("cls");
		cout << name << " losed and " << name << " Score is " << score << ":)\n\n";
		cout << "Thanks for Using Our Application:)\n";
		cout << "Generated By Behrad Malakouti and Sepehr Alipour From Helli 5 School.\n";     /*losing message*/
	}
	else
	{
		system("cls");
		cout << "--------------********************--------------\n";
		cout << "*********" << name << " won and " << name << " Score is " << score << ":)*********\n";     /*winning message*/
		cout << "--------------********************--------------\n\n";
		cout << "Thanks for Using Our Application:)\n";
		cout << "Generated By Behrad Malakouti and Sepehr Alipour From Helli 5 School.\n";
	}

	cin.get();
	cin.get();
	return 0;
}
