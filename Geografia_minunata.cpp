
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

ifstream f("data.in");
ofstream g("data.out");

vector < vector < pair < string, string> > > mat;
bool stai = 1;
int answer, corans,eur,asia,amen,oce,afr,ames,wrongans;
char answer2[40];
int j = 0, i = 0;
void setup()
{
	mat.resize(6);
	for (int d = 0; d < 6; d++)
	{
		mat[d].resize(5);
		for (int x = 0; x < 5; x++)
		{
			f >> mat[d][x].first;
		}
	}
	for (int d = 0; d < 6; d++)
	{
		for (int x = 0; x < 5; x++)
		{
			f >> mat[d][x].second;
		}
	}
}

void meniu_principal()
{
	cout  << "Apasa tasta 1 pentru a incepe jocul\n";
	cout << "Apasa tasta 0 pentru a iesi din joc\n";
	cin >> answer;
	if (!answer)
	{
		exit(0);
	}
}

void check2()
{
	if (j == 5)
	{
		i++;
		j = 0;
	}
	if (i == 6 && j == 5)
	{
		cout << "Scorul tau final este " << corans << "raspunsuri corecte si " << wrongans << "raspunsuri gresite";
	}
}

void meniu_raspuns()
{
	cout << "Apasa tasta 1 pentru a raspune din nou\n";
	cout << "Apasa tasta 2 pentru a trece la urmatoarea tara\n";
	cout << "Apasa tasta 3 pentru a vedea la cate tari ai raspuns corect momentan\n";
	cout << "Apasa tasta 4 pentru a vedea la cate tari ai raspuns gresit momentan\n";
	cout << "Apasa tasta 5 pentru a vedea cate tari mai sunt\n";
	cin >> answer;
	switch (answer)
	{
		case 1:
			break;
		case 2:
			j++;
			wrongans++;
			check2();
			break;

		case 3:
			cout << corans<<'\n';
			meniu_raspuns();
		case 4:
			cout << wrongans << '\n';
			meniu_raspuns();
		case 5:
			cout << 5 * 6 - wrongans - corans << '\n';
			meniu_raspuns();
	}
}

void wrong_answer()
{
	cout << "Ai raspuns gresit la intrebare\n";
	meniu_raspuns();
}

void cerinta_1()
{
	while (stai)
	{
		cout << "Introdu capitala tarii : " << mat[i][j].first << '\n';
		cin >> answer2;
		for (int i = 0; i < strlen(answer2); i++)
		{
			answer2[i] = tolower(answer2[i]);
		}
		if (answer2 == mat[i][j].second)
		{
			stai = 0;
			corans++;
			cout << "Felicitari, ai raspuns corect\n";
			j++;
			switch (i)
			{
			case 0:
				eur++;
			case 1:
				asia++;
			case 2:
				amen++;
			case 3:
				ames++;
			case 4:
				oce++;
			case 5:
				afr++;
			}
			check2();
		}
		else {
			wrong_answer();
		}
	}
}
int main()
{
	setup();
	meniu_principal();
	cerinta_1();
}

