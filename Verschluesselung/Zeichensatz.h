#pragma once
class Zeichensatz
{
public:
	Zeichensatz(void);
	Zeichensatz(int dez, std::string binear, char zeichen);
	~Zeichensatz(void);
	int m_dez;
	std::string m_binaer;
	char m_zeichen;
};

