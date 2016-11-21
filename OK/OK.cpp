#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	int V, E;     // V - liczba wierzcholkow, E - liczba krawedzi
	cout << "Liczba wierzcholkow: ";
	cin >> V;
	E = 1;

	vector<int> *ZA = new vector<int>[V + 1];    // mozna tez wykorzystac liste, nie ma to roznicy

	for (int i = 1; i <= E; i++)       // wprowadz wierzcholki i krawedzie
	{
		int a, b;
		fstream plik;
		plik.open("Dane.txt", ios::in);
		if (plik.good())
		{
			bool flag = true;
			string linia[2];
			while (!plik.eof())
			{
				for (int i = 0;i < 2; i++)
				{
					if (plik.eof())
					{
						flag = false;
						break;
					}
					getline(plik, linia[i]);
				}
				if (flag)
				{
					a = stoi(linia[0]);
					b = stoi(linia[1]);
					ZA[a].push_back(b);
					ZA[b].push_back(a);
				}
			}
		}
	}

	for (int i = 1; i <= V; i++)     // wypisujemy graf
	{
		cout << "Sasiedzi wierzcholka " << i << ": ";
		for (vector<int>::iterator it = ZA[i].begin(); it != ZA[i].end(); ++it) cout << *it << ", ";
		
		cout << endl;
	}

	fstream plik1("Zapis.txt", ios::out );
	if (plik1.good())
	{
		for (int i = 1; i <= V; i++)
		{
			for (vector<int>::iterator it = ZA[i].begin(); it != ZA[i].end(); ++it)
			{
				plik1 << i <<endl << *it << endl;
				plik1.flush();
			}
		}
		plik1.close();
	}

	delete[]ZA;     // zwalniamy pamiec
	system("pause");
}