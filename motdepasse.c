
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char key[100];
char site2[100];
char password[100];
char name[100];
char site[100];
char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789#!";
int i, length;

// Fonction pour générer un mot de passe aléatoire
void randPass(){
    // Initialisation de la seed pour la génération de nombres aléatoires
    srand(time(NULL));

    // Boucle pour générer chaque caractère du mot de passe
    for (i = 0; i < length; i++) {
        // Sélection d'un caractère aléatoire parmi les caractères disponibles
        password[i] = characters[rand() % (sizeof(characters) - 1)];
    }
}

// Fonction pour supprimer les mdp actuels
void suppFile(){
    // Crée un pointeur de fichier pour stocker le nom d'utilisateur et le mot de passe
    FILE *fp;
    // Ouvre le fichier "password.txt" en mode écriture ("w")
    fp = fopen("password.txt", "w");
    // Vérifie si le fichier a été ouvert avec succès
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    // Supprime le contenu du fichier
    fprintf(fp, "");
    // Ferme le fichier
    fclose(fp);
}

// Fonction pour enregistrer les informations de connexion dans un fichier
void enregistrerFile(){
    // Crée un pointeur de fichier pour stocker le nom d'utilisateur et le mot de passe
    FILE *fp;
    // Ouvre le fichier "password.txt" en mode ajout ("a")
    fp = fopen("password.txt", "a");
    // Vérifie si le fichier a été ouvert avec succès
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    // Écrit le site, le nom d'utilisateur et le mot de passe dans le fichier
    fprintf(fp, "%s | %s : ", site,name);
    fprintf(fp, "%s\n", password);
    // Ferme le fichier
    fclose(fp);
}

// Fonction pour rechercher un mdp pour l'utilisateur
void recherche(){
    int test;
    // Demande à l'utilisateur de saisir le site
    printf("Enter site name: ");
    scanf("%s", site2);
    // Crée un pointeur de fichier pour stocker le nom d'utilisateur et le mot de passe
    FILE *fp;
    // Ouvre le fichier "password.txt" en mode ajout ("r")
    fp = fopen("password.txt", "r");
    while(!feof(fp)){
        test = fgetc(fp);
        printf("%c", test);
    }
    fclose(fp);
}

void ajoutMdp(){
    // Demande à l'utilisateur de saisir la clé à rechercher
    printf("Enter the key: ");
    scanf("%s", key);

    // Demande à l'utilisateur de saisir la longueur du mot de passe
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // Génère un mot de passe aléatoire
    randPass();    

    // Demande à l'utilisateur de saisir le nom de l'utilisateur
    printf("Enter the name of the user: ");
    scanf("%s", name);

    // Demande à l'utilisateur de saisir le site
    printf("Enter site name: ");
    scanf("%s", site);

    // Enregistre les informations dans un fichier
    enregistrerFile();

    // Affiche le mot de passe et le nom de l'utilisateur
    printf("The password is: %s\n", password);
    printf("The name is: %s\n", name);
}

// Fonction qui demande à l'utilisateur la fonction à éxécuter
void menu(){
    // Init du choix
    unsigned int choix = 0;
    // Affiche pour l'utilisateur les fonctions
    printf("- Ajouter un mdp ? '1'\n- Supprimer les mdp ? '2'\n- Quitter '3'\n");
    // Récupére le choix de l'utilisateur
    scanf("%u", &choix);
    // Vérifie le choix de l'utilisateur
    switch(choix){
        // Si choix == 1
        case 1:
            // Lance la fonction d'ajout de mdp
            ajoutMdp();
            // Quitte le switch
            break;
        // Si choix == 2
        case 2:
            // Lance la fonction de suppression de tous les mdp
            suppFile();
            // Quitte le switch
            break;
        // Peut importe le choix autre qu'au dessus
        default :
            // Quitte le switch
            break;
    }
}

// Fonction main
int main() {
    // Lance la fonction du menu
    menu();
    //recherche();
    return 0;
}
