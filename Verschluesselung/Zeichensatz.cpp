#include "stdafx.h"
#include "Zeichensatz.h"


Zeichensatz::Zeichensatz(void)
{
	this->m_binaer = "000000";
	this->m_dez = 0;
	this->m_zeichen = 'A';
}

Zeichensatz::~Zeichensatz(void)
{
}

Zeichensatz::Zeichensatz(int dez, std::string binear, char zeichen){
	this->m_binaer		= binear; 
	this->m_dez			= dez;
	this->m_zeichen		= zeichen;
}