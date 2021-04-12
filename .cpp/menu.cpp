#include"../headers/main.h"

int menu(){
    //le menu
    cout<<"========Menu========\n1.Jouer\n2.Regles\n3.Scores\n4.Quitter"<<endl;
    string choixUtilisateur;
    getline(cin,choixUtilisateur);
    bool partieFini = false;
    while(!partieFini){
        if (choixUtilisateur.compare("1")==0)
        {
            jouer();
            return 0;
        }else if(choixUtilisateur.compare("2")==0){
            regles();
        }else if(choixUtilisateur.compare("3")==0){
            afficher_scores();
        }else if(choixUtilisateur.compare("4")==0){
            return 0;
        }else{
            cout<<"Ce que vous avez entre n'est pas bon"<<endl;
        }
        getline(cin,choixUtilisateur); 
    }
    return 0;
}

int regles(){
    // les règles
    cout<<"Quand vous lancez le jeu, on va vous demander combien de mots voulez vous deviner.(5 max)\n"<<
    "Vous pouvez donner un charactère ou plusieurs comme au pendu"<<
    "Ces mots vont etre choisis depuis une liste vous devrez les trouver un part un en faisant le moins d'essais possible.\n"<<
    "Vos scores seront enregistres dans un .txt .\n"<<
    "Bonne chance !"<<endl;
    retour_menu();
    return 0;
}

int retour_menu(){
    cout<<"1.Retour au menu"<<endl;
    string choixUtilisateur;
    getline(cin,choixUtilisateur);
    while(choixUtilisateur.compare("1")!=0){
        cout<<"Ce que vous avez ecrit n'est pas bon"<<endl;
        getline(cin,choixUtilisateur);
    }
    menu(); 
    return 0;
}