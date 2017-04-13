#include "stdafx.h"
#include "converter.h"
#include <bitset>


converter::converter(void)
{
	Zeichensatz zeichen = Zeichensatz( 0, "000000",'A');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 1, "000001",'B');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 2, "000010",'C');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 3, "000011",'D');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 4, "000100",'E');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 5, "000101",'F');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 6, "000110",'G');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 7, "000111",'H');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 8, "001000",'I');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 9, "001001",'J');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 10, "001010",'K');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 11, "001011",'L');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 12, "001100",'M');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 13, "001101",'N');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 14, "001110",'O');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 15, "001111",'P');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 16, "010000",'Q');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 17, "010001",'R');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 18, "010010",'S');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 19, "010011",'T');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 20, "010100",'U');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 21, "010101",'V');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 22, "010110",'W');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 23, "010111",'X');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 24, "011000",'Y');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 25, "011001",'Z');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 26, "011010",'a');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 27, "011011",'b');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 28, "011100",'c');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 29, "011101",'d');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 30, "011110",'e');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 31, "011111",'f');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 32, "100000",'g');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 33, "100001",'h');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 34, "100010",'i');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 35, "100011",'j');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 36, "100100",'k');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 37, "100101",'l');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 38, "100110",'m');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 39, "100111",'n');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 40, "101000",'o');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 41, "101001",'p');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 42, "101010",'q');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 43, "101011",'r');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 44, "101100",'s');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 45, "101101",'t');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 46, "101110",'u');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 47, "101111",'v');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 48, "110000",'w');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 49, "110001",'x');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 50, "110010",'y');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 51, "110011",'z');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 52, "110100",'0');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 53, "110101",'1');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 54, "110110",'2');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 55, "110111",'3');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 56, "111000",'4');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 57, "111001",'5');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 58, "111010",'6');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 59, "111011",'7');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 60, "111100",'8');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 61, "111101",'9');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 62, "111110",'+');
	zeichenListe.push_back(zeichen);
	zeichen = Zeichensatz( 63, "111111",'/');
	zeichenListe.push_back(zeichen);
}

converter::~converter(void)
{
}

//wandelt einen Buchstaben in 8 Bit um zB A = 01000001
std::string converter::charIn8Bit(char buchstabe){
	//int stelle = (int)buchstabe;
	return std::bitset<8>(buchstabe).to_string();
}

/*
	den übergebenen String wieder in 6Bits konvertieren.
	Den String von Bits dann in 8 Bitfolgen wieder in ASCII Buchstaben umwandeln.
*/
std::string converter::get_string8Bit(std::string text){
	std::string bits, hilfs, erg = "";
	
	//nur wenn am ende ein Gleichheitszeichen ist, ist das im richtigen Format.
	if(text.at(text.size()-1) == '='){
		text = text.substr(0, text.size()-1); //gleichheitszeichen wegnehmen
		for(unsigned int i = 0; i < text.size(); i++){
			for(unsigned int j = 0; j < zeichenListe.size(); j++){
				if(zeichenListe[j].m_zeichen == text.at(i)){
					bits = bits + zeichenListe[j].m_binaer;
					break;
				}
			}
		}
	}

	//bits wieder durch acht teilbar machen...
	if(bits.size() % 8 != 0){
		bits = bits.substr(0,bits.size()-(bits.size() % 8));
	}
	
	for(unsigned int i = 0; i < bits.size(); i+=8){
		unsigned long l;
		char c;
		hilfs = bits.substr(i, 8);
		l = std::bitset<8>(hilfs).to_ulong();
		c = static_cast<unsigned char>( l );
		erg += c;
	}

	return erg;
}

/*
	Einen String erst in Binär umwandeln d.h. 8 Bits (zB A = 01001011)
	Den Binärstring in 6Bits unterteilen und die dann mit der Tabelle als Buchstaben ausgeben
	Ist der String nicht durch 6 Teilbar, solange Nullen dranhängen,
	bis die Länge durch 6 Teilbar ist.
*/
std::string converter::get_string6Bit(std::string text){
	std::string bits,hilfs;
	std::string erg = "";
	for(unsigned int i = 0; i < text.size(); i++){
		bits = bits + this->charIn8Bit(text.at(i));
	}
	
	//Bits teilbar durch 6 machen
	while((bits.size() % 6) != 0){
		bits += "0";
	}

	//jeweils 6 bits in der tabelle vergleichen und den buchstaben in den ausgabe String schreiben
	for(unsigned int i = 0; i < bits.size(); i+=6){
		hilfs = ""; //könnte eventuell weg
		hilfs = bits.substr(i, 6);
		for(unsigned int j = 0; j < zeichenListe.size(); j++){
			if(zeichenListe[j].m_binaer.compare(hilfs) == 0){
				erg = erg + zeichenListe[j].m_zeichen;
				break;
			}
		}
	}
	erg = erg + "=";

	return erg;
}
