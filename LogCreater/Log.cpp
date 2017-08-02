#include "stdafx.h"
#include "Log.h"


Log::Log(std::string dateiName, bool consoleLog)
{
	m_dateiName = dateiName;
	m_consoleLog = consoleLog;
	
	m_dateiName = m_dateiName + ".txt";
	//m_datei = std::ofstream(m_dateiName);
	std::ofstream datei(m_dateiName);

	//Start des Logs in die Datei schreiben
	if(datei.is_open()){
	m_t = time(0);
		mpt_now = localtime(&m_t);
		datei << "Log erstellt am " << std::setfill('0') << std::setw(2) << (mpt_now->tm_mday) << '.'
				<< std::setfill('0') << std::setw(2) << (mpt_now->tm_mon + 1) << '.' 
				<< std::setfill('0') << std::setw(4) << (mpt_now->tm_year + 1900) << " um " 
				<< std::setfill('0') << std::setw(2) << (mpt_now->tm_hour) << ':'
				<< std::setfill('0') << std::setw(2) << (mpt_now->tm_min) << ':'
				<< std::setfill('0') << std::setw(2) << (mpt_now->tm_sec) << "Uhr.\n";
		datei << "---------------------------------------------------------------------------\n";
	}
	//Falls es in die Console geschrieben werden sollen 
	if(m_consoleLog){
		std::cout << "Log erstellt am " << std::setfill('0') << std::setw(2) << (mpt_now->tm_mday) << '.'
			<< std::setfill('0') << std::setw(2) << (mpt_now->tm_mon + 1) << '.' 
			<< std::setfill('0') << std::setw(4) << (mpt_now->tm_year + 1900) << " um " 
			<< std::setfill('0') << std::setw(2) << (mpt_now->tm_hour) << ':'
			<< std::setfill('0') << std::setw(2) << (mpt_now->tm_min) << ':'
			<< std::setfill('0') << std::setw(2) << (mpt_now->tm_sec) << "Uhr.\n" 
			<< "---------------------------------------------------------------------------\n"
			<< std::endl;
	}

	if(datei.is_open()){
		datei.close();
	}
}

void Log::write(std::string text){
	std::ofstream datei(m_dateiName, std::ios::app);

	if(datei.is_open()){
		m_t = time(0);
		mpt_now = localtime(&m_t);
		datei << std::setfill('0') << std::setw(2) << (mpt_now->tm_hour) << ':'
				<< std::setfill('0') << std::setw(2) << (mpt_now->tm_min) << ':'
				<< std::setfill('0') << std::setw(2) << (mpt_now->tm_sec) << " "
				<< "\t"+text << "\n"; //text hinzufugen
	}
	if(m_consoleLog){
		std::cout	<< std::setfill('0') << std::setw(2) << (mpt_now->tm_hour) << ':'
					<< std::setfill('0') << std::setw(2) << (mpt_now->tm_min) << ':'
					<< std::setfill('0') << std::setw(2) << (mpt_now->tm_sec) << " "
					<< "\t"+text << "\n"; //text hinzufugen
	}

	if(datei.is_open()){
		datei.close();
	}
}

void Log::emptyRow(){
	std::ofstream datei(m_dateiName, std::ios::app);

	if(datei.is_open()){
		datei << "\n";
	}

	if(m_consoleLog){
		std::cout << "\n" << std::endl;
	}
}

Log::~Log(void)
{
	std::ofstream datei(m_dateiName, std::ios::app);
	m_t = time(0);
	mpt_now = localtime(&m_t);
	datei << "\nEnde des Logs um " 
			<< std::setfill('0') << std::setw(2) << (mpt_now->tm_hour) << ':'
			<< std::setfill('0') << std::setw(2) << (mpt_now->tm_min) << ':'
			<< std::setfill('0') << std::setw(2) << (mpt_now->tm_sec) << "Uhr.\n";

	if(m_consoleLog){
		std::cout	<< "Ende des Logs um " 
					<< std::setfill('0') << std::setw(2) << (mpt_now->tm_hour) << ':'
					<< std::setfill('0') << std::setw(2) << (mpt_now->tm_min) << ':'
					<< std::setfill('0') << std::setw(2) << (mpt_now->tm_sec) << "Uhr.\n";
	}

	if(datei.is_open()){
		datei.close();
	}

	//delete mpt_now;
}