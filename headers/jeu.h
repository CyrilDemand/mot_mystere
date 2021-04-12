#include<string>
#include<vector>

using namespace std;

int choisir_nombre_de_mots();
vector<string> choisir_des_mot_dans_un_fichier(string chemin, int nombreDeMots);
int nombre_de_mots_dans_fichier(string chemin);
int jouer();
bool trouver_le_mot(int& nombreDeCoups,string motATrouver);
string mot_etoile(int longueur);
void trouver_charactere(string &motVisible,string motATrouver,string c);