// LogCreater.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	Log log = Log("Log", true);
	log.write("Es ist ein Fehler aufgetreten");
	system("pause");
	return 0;
}