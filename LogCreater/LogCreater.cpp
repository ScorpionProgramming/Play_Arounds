// LogCreater.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	Log* log = new Log("Log", true);
	log->write("Es ist ein Fehler aufgetreten");

	system("pause");
	log->write("Es konnte kein Objekt erstellt werden");

	system("pause");
	log->write("Versucht objekte neu zu erstellen...");
	
	system("pause");
	log->write("Objekte erfolgreich erstellt");
	delete log;
	system("pause");
	return 0;
}