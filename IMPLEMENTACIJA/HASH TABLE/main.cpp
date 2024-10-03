#include"OpenScatterTable.h"

void main()
{
	try {
		OpenScatterTable tablica(32);

    // uvesti tablicu i funkciju
		

		cout << "Broj igraca rodjenih 2004: " << tablica.countPlayersBornIn("2004") << endl;

	}
	catch (exception* e) // signup baca exception kad nema mesta vise u tablici
	{
		cout << e->what() << endl;
	}
}
