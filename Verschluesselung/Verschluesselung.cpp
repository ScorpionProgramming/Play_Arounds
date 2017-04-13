// Verschluesselung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Der text der verschlüsselt werden soll
	std::string text		= "Polyfon zwitschernd assen Maexchens Voegel Rueben, Joghurt und Quark";
	//das Ergebnis des zu verschlüsselnen Textes sollte folgendermaßen aussehen: (zum vergleich)
	std::string ergebnis	= "UG9seWZvbiB6d2l0c2NoZXJuZCBhw59lbiBNw6R4Y2hlbnMgVsO2Z2VsIFLDvGJlbiwgSm9naHVydCB1bmQgUXVhcms=";
	converter cvtr; 

	std::string convertierter_str = cvtr.get_string6Bit(text);

	std::string rueckconvertierter = cvtr.get_string8Bit(convertierter_str);

	std::cout << "Anfangstext: \n" << text << std::endl;
	std::cout << "\nKonvertierter String:\n"<<convertierter_str << std::endl; 
	std::cout << "\nZurueckkonvertierer String:\n" <<rueckconvertierter << std::endl;
	std::cout << "\n\n\n" << cvtr.get_string8Bit("UG9seWZvbiB6d2l0c2NoZXJuZCBhw59lbiBNw6R4Y2hlbnMgVsO2Z2VsIFLDvGJlbiwgSm9naHVydCB1bmQgUXVhcms=") << std::endl;
	std::cout << " " << std::endl;

	system("PAUSE");
	return 0;
}

