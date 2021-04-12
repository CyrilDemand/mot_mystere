#include"../headers/main.h"


int jouer(){
    //la fonction qui lance le jeu
    int nombreDeMots = choisir_nombre_de_mots();
    string const chemin = "./txt/liste_de_mots.txt";
    vector<string> mots = choisir_des_mot_dans_un_fichier(chemin,nombreDeMots);
    int nombreDeCoups = 0;
    for (int i = 0; i < nombreDeMots; i++)
    {
        cout<<mots[i];
        trouver_le_mot(nombreDeCoups, mots[i]);
    }
    score(nombreDeCoups, mots,nombreDeMots);
    return 0;
}

int choisir_nombre_de_mots(){
    //demande combien de mots l'utilisateur veut trouver
    cout<<"combien de mots voulez vous trouver ? (5 max)"<<endl;
    int choix;
    cin>>choix;
    while (choix > 5)
    {
        cout<<"On a dit 5 max ! (sinon la partie serait trop longue)"<<endl;
        cin>>choix;
    }
    return choix;
}

vector<string> choisir_des_mot_dans_un_fichier(string chemin, int nombreDeMots){
    //Cette fonction retourner un tableau dynamique de mots ayant pour longueur le nombre de mots choisis
    vector<string> mots;
    ifstream monFlux(chemin);
    int nbMots = nombre_de_mots_dans_fichier(chemin);
    if(monFlux){
        int nombreAleatoire[nombreDeMots];
        monFlux.close();
        for(int i = 0;i<nombreDeMots;i++){
            srand(rand()%55);
            nombreAleatoire[i] = rand()%nbMots;
            cout<<nombreAleatoire[i]<<endl;
        }
        ifstream monFlux(chemin);
        string mot="";
        int ligne = 0;
        while (getline(monFlux,mot)) // un mot = une ligne
        {
            for (int i = 0; i < nombreDeMots; i++)
            {
                if(ligne==nombreAleatoire[i]){
                    mots.push_back(mot);
                }
            }
            ligne++;
        }
    }
    monFlux.close();
    return mots;
}

int nombre_de_mots_dans_fichier(string chemin){
    //retourne le nombre de mots dans le fichier 1 mot = 1 ligne
    ifstream monFlux(chemin);
    int nombreDeMotsDansFichier = 0;
    string ligne;
    while (getline(monFlux,ligne)) // afin de pouvoir mettre autant de nombre que l'on veut dans le dossier
    {
        nombreDeMotsDansFichier++;
    }
    monFlux.close();
    return nombreDeMotsDansFichier;
}

bool trouver_le_mot(int& nombreDeCoups,string motATrouver){
    //la fonction où l'on va chercher le mot
    string propositionUtiliateur; // ce que rentre l'utilisateur
    string motVisible = mot_etoile(motATrouver.length()); // de base l'utilisateur voit le mot sous la forme d'une suite d'étoiles
    cout<<motVisible<<endl;
    cout<<motATrouver<<endl;
    while (motVisible.compare(motATrouver)!=0 && propositionUtiliateur.compare(motATrouver)!=0)
    {
        cin>>propositionUtiliateur;
        nombreDeCoups++;
        if(propositionUtiliateur.length()==1){
            trouver_charactere(motVisible,motATrouver,propositionUtiliateur);
        }else{
            if(propositionUtiliateur.compare(motATrouver)!=0){
                cout<<"Ce mot n'est pas le bon"<<endl;
            }
        }
        cout<<motVisible<<endl;
    }
    cout<<"Vous avez trouve le mot"<<endl;
    return true;
}

string mot_etoile(int longueur){
    //retourne le mot sous la forme d'une suite d'étoiles
    string mot ="";
    for(int i = 0;i<longueur;i++){
        mot+="*";
    }
    return mot;
}

void trouver_charactere(string &motVisible,string motATrouver,string c){
    //voit si le charactere donné par l'utilisateur est dans le mot à trouver et le révèle.
    if(motVisible.find(c)){
        for (int i = 0; i < motATrouver.length(); i++)
        {
            if(motATrouver[i]==c[0]){
                motVisible[i]=c[0];
            }
        }
    }else{
        cout<<"Le mot a cherche ne contient pas le caractere entree"<<endl;
    }
    return;
}