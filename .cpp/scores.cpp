#include"../headers/main.h"

int afficher_scores(){
    //affiche les scores déjà existant
    string chemin = "scores.txt";
    ifstream monFlux(chemin);
    string ligne;
    if(monFlux){
        while (getline(monFlux,ligne)) // afin de pouvoir mettre autant de nombre que l'on veut dans le dossier
        {
            cout<<ligne<<endl;
        }
        retour_menu();
    }else{
        cout<<"Vous n'avez pas encore de scores !"<<endl;
        retour_menu();
    }
    return 0;
}

void score(int nombreCoups, vector<string> mots,int nombreDeMots){
    //fonction qui va demander le prenom pour ensuite sauvegarder le score
    cout<<"Quel est votre beau prenom ? (afin de pouvoir sauvegarder votre score :D )"<<endl;
    string prenom;
    cin>>prenom;
    sauvegarde_scores(prenom,nombreCoups,mots,nombreDeMots);
}

void sauvegarde_scores(string prenom,int nombreCoups,vector<string> mots,int nombreDeMots){
    //nom de la fonction assez explicite
    string chemin = "scores.txt";
    ofstream monFlux(chemin);
    monFlux<<scores_to_string(prenom,nombreCoups,mots,nombreDeMots)<<endl;
}

string scores_to_string(string prenom,int nombreCoups, vector<string> mots,int taille){
    //retourne ce que l'on doit mettre dans le fichier sous la forme d'une chaine de charactères
    string res;
    res+=prenom+" Nombre de coups: ";
    ostringstream os;
    os<<nombreCoups;
    res+=os.str();
    res+=", mot trouves: ";
    for(int i = 0;i<taille;i++){
        res+=mots[i]+", ";
    }
    cout<<res<<endl;
    return res;
}