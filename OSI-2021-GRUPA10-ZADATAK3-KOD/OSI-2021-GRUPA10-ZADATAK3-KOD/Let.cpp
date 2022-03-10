



#include "Let.h"



int Let::getID() const
{
	return ID;
}

std::string Let::getVrijeme_polijetanja() const
{
	return vrijeme_polijetanja;
}

std::string Let::getVrijeme_slijetanja() const
{
	return vrijeme_slijetanja;
}

Datum Let::getDatum() const
{
	return datum;
}

std::string Let::getOpis() const
{
	return opis;
}

int Let::getBr_mjesta() const
{
	return br_mjesta;
}

int Let::getBr_slobodnih_mjesta() const
{
	return br_slobodnih_mjesta;
}


void Let::setID(int id)
{
	this->ID = id;
}

void Let::setVrijeme_polijetanja(std::string vr_p)
{
	this->vrijeme_polijetanja = vr_p;
}

void Let::setVrijeme_slijetanja(std::string vr_s)
{
	this->vrijeme_slijetanja = vr_s;
}

void Let::setDatum(Datum dat)
{
	this->datum = dat;
}

void Let::setDatum(int d, int m, int g)
{
	(this->datum).setDan(d);
	(this->datum).setMjesec(m);
	(this->datum).setGodina(g);
}

void Let::setOpis(std::string op)
{
	this->opis = op;
}
void Let::setStatus(std::string st)
{
	this->status = st;
}

void Let::setBr_mjesta(int br1)
{
	this->br_mjesta = br1;
}

void Let::setBr_slobodnih_mjesta(int br2)
{
	this->br_slobodnih_mjesta = br2;
}

std::string Let::getStatus() const
{
	return status;
}

// Ucitava podatke o letu iz fajla i dodjeljuje vrijednosti proslijedjenom objektu (this)
void Let::ucitajLet(ifstream& file)
{

	string t_ID;
	string t_vrijeme_polijetanja;
	string t_vrijeme_slijetanja;
	string t_opis;
	string t_status;
	string t_br_mjesta;
	string t_br_slobodnih_mjesta;

	string nothing;

	getline(file, t_ID, ',');
	this->setID(stoi(t_ID));

	getline(file, t_vrijeme_polijetanja, ',');
	this->setVrijeme_polijetanja(t_vrijeme_polijetanja);

	getline(file, t_vrijeme_slijetanja, ',');
	this->setVrijeme_slijetanja(t_vrijeme_slijetanja);

	file >> this->datum;
	getline(file, nothing, ',');										// Da dodje do zareza i da ga preskoci, idemo dalje, na opis.

	getline(file, t_opis, ',');
	this->setOpis(t_opis);

	getline(file, t_br_mjesta, ',');
	this->setBr_mjesta(stoi(t_br_mjesta));

	getline(file, t_br_slobodnih_mjesta, ',');
	this->setBr_slobodnih_mjesta(stoi(t_br_slobodnih_mjesta));

	getline(file, t_status, '\n');
	this->setStatus(t_status);


}


// Ispisuje jedan let u formatiranom obliku
void Let::ispisi_let() const
{
	cout << " " << setw(9) << left << this->getID();
	cout << setw(24) << left << this->getVrijeme_polijetanja();
	cout << setw(23) << left << this->getVrijeme_slijetanja();
	cout << this->getDatum() << "       ";
	cout << setw(33) << left << this->getOpis();
	cout << setw(23) << left << this->getBr_mjesta();
	cout << setw(26) << left << this->getBr_slobodnih_mjesta();
	cout << setw(21) << left << this->getStatus() << endl;
}

std::istream& operator>>(std::istream& is, Let& l) {

		std::cin.ignore();
		std::cout << "Unesite ID leta: " << std::endl;
		//std::getline(std::cin, l.ID, '\n');
		std::string id;
		std::getline(std::cin, id, '\n');
		//if(std::isdigit(id) == 0)
		for (char const& c : id) {
			if (std::isdigit(c) == 0) throw std::exception("ID mora biti broj!");
		}
		//is >> l.ID;
		l.ID = std::stoi(id);
		//std::cin.ignore();
		std::cout << "Unesite vrijeme polijetanja (u formatu hh:mm): " << std::endl;
		std::getline(std::cin, l.vrijeme_polijetanja, '\n');
		//is >> l.vrijeme_polijetanja;
		std::cout << "Unesite vrijeme slijetanja: (u formatu hh:mm)" << std::endl;
		std::getline(std::cin, l.vrijeme_slijetanja, '\n');
		//is >> l.vrijeme_slijetanja;
		std::cout << "Unesite datum: " << std::endl;
		is >> l.datum;
		std::cin.ignore();
		std::cout << "Unesite opis: " << std::endl;
		std::getline(std::cin, l.opis, '\n');
		l.status = "spreman";
		//is >> l.opis;
		std::cout << "Unesite broj mjesta: " << std::endl;
		is >> l.br_mjesta;
		//std::cout << "Unesite broj slobodnih mjesta: " << std::endl;
		//is >> l.br_slobodnih_mjesta;
		l.br_slobodnih_mjesta = l.br_mjesta;
		return is;
	
	/*catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return is;
	}*/
	
}


std::ostream& operator<<(std::ofstream& ofs, const Let& l) {
	ofs << l.ID << ',' << l.vrijeme_polijetanja << ',' << l.vrijeme_slijetanja << ','
		<< l.datum << ',' << l.opis << ',' << l.br_mjesta << ',' << l.br_slobodnih_mjesta << ',' << l.status << std::endl;
	return ofs;
}
























