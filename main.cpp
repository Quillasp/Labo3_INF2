#include "tri.h"
#include "Date.h"
#include "Point.h"

using namespace std;

enum Couleur {orange, gray, cyan};
using VectString = vector<string>;
using VectCouleur = vector<Couleur>;
using VectDate = vector<Date>;
using VectPoint = vector<Point>;

ostream& operator<<(ostream& os, const Couleur& couleur);

int main()
{
	// vecteurs à trier
	VectString vString = {"pomme", "citron", "orange", "banane"};
	VectCouleur vCouleur = {Couleur::orange, Couleur::gray, Couleur::cyan};
	VectPoint vPoint = {{1, 2}, {3, 4}, {5, 5}, {-1, 7}, {3, 1}};
	VectDate vDate = {{1, 2, 1927}, {3, 4, 2002}, {5, 5, 2001}};

	test(vString);
	cout << endl;
	test(vCouleur);
	cout<<endl;
	test(vDate);
	cout<<endl;
	test(vPoint);
}

ostream& operator<<(ostream& os, const Couleur& couleur)
{
	switch(couleur)
	{
		case 0:
			os << "orange";
			break;
		case 1:
			os << "gray";
			break;
		case 2:
			os << "cyan";
			break;
	}

    return os;
}