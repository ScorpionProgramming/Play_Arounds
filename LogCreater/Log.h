#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>  // fuer setfill führende Nullen etc.
class Log
{
private:
	std::string m_dateiName; //Name der Datei die geoeffnet werden soll
	bool m_consoleLog;
	time_t m_t; //aktuelle uhrzeit
	struct tm *mpt_now; // time struktur
	//std::ofstream m_datei; //datei die erstellt wird

public:
	Log(std::string dateiName, bool consoleLog);
	void write(std::string text);
	~Log(void);
};

