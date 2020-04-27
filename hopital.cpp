#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class patient{
private:
	string Nom;
	int Echelle;

public:
	string nom(){
		return Nom;
	}

	int echelle(){
		return Echelle;
	}

	void get(){
		cout<< "Nom du patient: "<< Nom<< endl;
		cout<< "echelle de douleur: "<< Echelle<< endl; 
	}

	void set(){
		cout<< "Entrez votre nom:"<<endl;
		cin>> Nom;
		cout<< "Comment décrirez vous votre douleur sur une echelle de 1 à 10:"<< endl;
		cin>> Echelle;
		while ((Echelle>10)||(Echelle<1)){
			cout<< "C'est pas bon, réessayez"<< endl;
			cout<< "Comment décrirez vous votre douleur sur une echelle de 1 à 10:"<< endl;
			cin>> Echelle;
		}
	}
};

class comp{
public:
	bool operator()(patient& p1, patient& p2){
		return p1.echelle()< p2.echelle();
	}
};

class hopital{
private:
	priority_queue <patient, vector<patient>, comp> tas;
public:

	void ajouter(){
		patient nouveau;
		nouveau.set();
		tas.push(nouveau);
	}

	int nb_patients(){
		cout<< "Nombre de patients: "<< tas.size()<< endl;
	}

	void passage(){
		patient prochain= tas.top();
		cout<< "prochain patient: "<< prochain.nom()<<endl;	
		tas.pop();
	}
};


int main(int argc, char const *argv[]){	
	hopital a;

	while (1){
		cout<< "     || M E N U ||\n"<< endl;
		cout<< "Que voulez vous faire?" << endl;
		cout<< "1. Ajouter un patient" << endl;
		cout<< "2. Afficher le nombre de patients" << endl;
		cout<< "3. Afficher le nom du prochain patient" << endl;
		cout<< "4. Quitter le programme\n" << endl;
		cout<< "Votre choix:"<<endl;
		int choix;
		cin>> choix;
		switch(choix){
			case 1:
				a.ajouter();
				break;
			case 2:
				a.nb_patients();
				break;
			case 3:
				a.passage();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<< "Ce choix est indisponible, veuillez réessayer :)"<< endl;
		}
	}
	return 0;
}