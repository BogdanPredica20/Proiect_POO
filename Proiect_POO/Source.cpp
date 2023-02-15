#include<iostream>
#include<stdio.h>
#include<vector>
#include<fstream>
#include<string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Produs {
protected:
	float pret;
	string nume_prod;
public:
	Produs(){}
	Produs(string nume_prod, float pret) {
		this->nume_prod = nume_prod;
		this->pret = pret;
	}

};

class Laptop: public Produs {
private:
	string procesor;
	int ram;
	float diagonala;
public:

	Laptop(string nume_prod, float pret, string procesor, int ram, float diagonala) :Produs(nume_prod, pret) {
		this->procesor = procesor;
		this->ram = ram;
		this->diagonala = diagonala;
	}

	void setPret_lap(int new_pret) {
		if (new_pret != this->pret)
			this->pret = new_pret;
	}


	int getPret_lap() {
		return this->pret;
	}

	string getnume() {
		return this->nume_prod;
	}

	~Laptop(){}

	friend ofstream& operator<< (ofstream& output, Laptop &lap);
	friend void comenzi();
};

ofstream& operator<< (ofstream& output, Laptop &lap) {
	output <<endl<<"Laptop: " << lap.nume_prod << "  Pret: " << lap.pret << "  Procesor: " << lap.procesor << "  Ram: " << lap.ram << "  Diagonala: " << lap.diagonala;
	return output;
}

class Telefon: public Produs {
private:
	int ram;
	float dim_ecran;
	int mem_interna;
public:
	Telefon(string nume_prod, float pret, int ram, float dim_ecran, int mem_interna):Produs(nume_prod,pret) {
		this->ram = ram;
		this->dim_ecran = dim_ecran;
		this->mem_interna = mem_interna;
	}

	void setPret_tel(int new_pret) {
		if(new_pret!=this->pret)
			this->pret = new_pret;
	}

	int getPret_tel() {
		return this->pret;
	}

	~Telefon(){}

	friend ofstream& operator<< (ofstream& output, Telefon& tf);
};

ofstream& operator<< (ofstream& output, Telefon& tf) {
	output << endl << "Telefon: " << tf.nume_prod << "  Pret: " << tf.pret<<"  Diagonala: "<< tf.dim_ecran << "  Ram: " << tf.ram << "  Memorie interna: " << tf.mem_interna;
	return output;
}

class Televizor : public Produs {
private:

	float diagonala;
	bool hd;
	bool hdmi;
public:
	Televizor(string nume_prod, float diagonala, bool hd, bool hdmi,float pret) :Produs(nume_prod, pret) {
		this->diagonala = diagonala;
		this->hd = hd;
		this->hdmi = hdmi;

	}
	
	void setPret_tv(int new_pret) {
		if (new_pret != this->pret)
			this->pret = new_pret;
	}

	int getPret_tv() {
		return this->pret;
	}

	~Televizor() {}

	friend ofstream& operator<< (ofstream& output, Televizor& tele);
};

ofstream& operator<< (ofstream& output, Televizor& tele) {
	output << endl << "Televizor: " << tele.nume_prod << "  Diagonala: " << tele.diagonala << "  Hd: " << tele.hd << "  Hdmi: " << tele.hdmi << "  Pret: " << tele.pret;
	return output;
}

class Mouse : public Produs {
private:
	int dpi;
	int lungime_cablu;

public:
	Mouse(string nume, float pret, int dpi, int lungime_cablu) : Produs(nume, pret) {
		this->dpi = dpi;
		this->lungime_cablu = lungime_cablu;

	}
	void setPret_mouse(float pret) {
		this->pret = pret;
	}
	float getPret_mouse() {
		return this->pret;
	}

	friend ofstream& operator<< (ofstream& output, Mouse& mo);
};

ofstream& operator<< (ofstream& output, Mouse& mo) {
	output << endl << "Mouse: " << mo.nume_prod << "  Pret: " << mo.pret << "  Dpi: " << mo.dpi << "  Lungime cablu: " << mo.lungime_cablu;
	return output;
}

class Monitor : public Produs {
private:
	int hz;
	float diagonala;

public:
	Monitor(string nume_prod, float pret, int hz, float diagonala) : Produs(nume_prod, pret) {
		this->hz = hz;
		this->diagonala = diagonala;

	}
	void setPret_monitor(float pret) {
		this->pret = pret;
	}
	float getPret_monitor() {
		return this->pret;
	}
	
	friend ofstream& operator<< (ofstream& output, Monitor& mon);
};

ofstream& operator<< (ofstream& output, Monitor& mon) {
	output << endl << "Monitor: " << mon.nume_prod << "  Pret: " << mon.pret << "  Hz: " << mon.hz << "  Diagonala: " << mon.diagonala;
	return output;
}

class Casti : public Produs {
private:
	bool wireless;
	bool anulare_digitala;

public:
	Casti(string nume, float pret, bool wireless, bool anulare_digitala) : Produs(nume, pret) {
		this->wireless = wireless;
		this->anulare_digitala = anulare_digitala;

	}
	void setPret_casti(float pret) {
		this->pret = pret;
	}
	float getPret_casti() {
		return this->pret;
	}

	friend ofstream& operator<< (ofstream& output, Casti& casti);
};

ofstream& operator<< (ofstream& output, Casti& casti) {
	output << endl << "Casti: " << casti.nume_prod << "  Pret: " << casti.pret << "  Wireless: " << casti.wireless << "  Anulare digitala: " << casti.anulare_digitala;
	return output;
}

void introduce_stoc() {
	Laptop l1("Asus", 3500, "Intel-i7", 8, 15.6);
	Laptop l2("Apple", 7500, "Intel-i5", 16, 13.3);
	Laptop l3("Lenovo", 5000, "AMD-Ryzen5", 16, 15.2);

	ofstream fisOut("produse.txt");
	fisOut << l1;
	fisOut << l2;
	fisOut << l3;

	Telefon tf1("Samsung", 3199, 6, 6, 256);
	Telefon tf2("Huawei", 1899.99, 4, 6.4, 64);
	Telefon tf3("iPhone", 4999.99, 8, 6.1, 128);

	fisOut << endl;
	fisOut << tf1;
	fisOut << tf2;
	fisOut << tf3;

	Monitor m1("HP", 700, 120, 20);
	Monitor m2("Philips", 830, 120, 24);
	Monitor m3("Lenovo", 706, 120, 27);

	fisOut << endl;
	fisOut << m1;
	fisOut << m2;
	fisOut << m3;

	Casti c1("Sony", 79.99, false, false);
	Casti c2("Sennheiser", 879, false, true);
	Casti c3("Audio-Technica", 249, true, true);

	fisOut << endl;
	fisOut << c1;
	fisOut << c2;
	fisOut << c3;

	Televizor tv1("Samsung", 60, 1, 1, 1299.99);
	Televizor tv2("Lg", 50, 1, 1, 949.99);
	Televizor tv3("Orion", 75, 1, 1, 2199.99);

	fisOut << endl;
	fisOut << tv1;
	fisOut << tv2;
	fisOut << tv3;

	Mouse mo1("Logitech", 130, 3200, 3);
	Mouse mo2("Razer", 150, 2400, 3);
	Mouse mo3("Redragon", 80, 3200, 2);

	fisOut << endl;
	fisOut << mo1;
	fisOut << mo2;
	fisOut << mo3;

	fisOut.close();
}

void comenzi() {
	int id_comanda;
	string data;
	string produs;
	string categorie;
	string status_com;
	int cant;
	float pret;
	ifstream fisIn("Comenzi.txt");
	ofstream fout("Vanzari.txt");
	while (true) {
		fisIn >> id_comanda;
		fisIn >> data;
		fisIn >> status_com;
		fisIn >> categorie;
		fisIn >> produs;
		fisIn >> cant;
		fisIn >> pret;
		if (status_com == "Confirmat")
		{
			if (fisIn.eof())
				break;
			fout << "Id_comada: " << id_comanda << endl;
			fout <<"Data comenzii: "<< data << endl;
			fout << "---------------------------" << endl;
			fout << "Produs: " << produs << endl;
			fout << "Categorie: " << categorie << endl;
			fout << "Total de plata: " << pret * cant << endl << endl<<endl;
		}
		else
		{
			if (fisIn.eof())
				break;
		}
	}
}

int main() {
	introduce_stoc();
	comenzi();
}