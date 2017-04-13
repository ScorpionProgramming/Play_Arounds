#pragma once
class converter
{
public:
	converter(void);
	~converter(void);

	std::string get_string8Bit(std::string text);
	std::string get_string6Bit(std::string text);

private:
	//Variablen
	std::vector<Zeichensatz> zeichenListe;

	//Hilfsvariablen
	std::string charIn8Bit(char buchstabe);
};