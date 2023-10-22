
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char key[100];
char key2[100];
char password[100];
char name[100];
char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
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

// Fonction pour enregistrer les informations de connexion dans un fichier
void enregistrerFile(){
    // Crée un pointeur de fichier pour stocker le nom d'utilisateur et le mot de passe
    FILE *fp;
    // Ouvre le fichier "password.txt" en mode écriture ("w")
    fp = fopen("password.txt", "w");
    // Vérifie si le fichier a été ouvert avec succès
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    // Écrit le nom d'utilisateur et le mot de passe dans le fichier
    fprintf(fp, "%s : ", name);
    fprintf(fp, "%s\n", password);
    // Ferme le fichier
    fclose(fp);
}

// Fonction pour rechercher une clé dans un tableau de clés
void recherche(){
    // Demande à l'utilisateur de saisir la clé à rechercher
    printf("Enter the key: ");
    scanf("%s", key2);
}

int main() {

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

    // Enregistre les informations dans un fichier
    enregistrerFile();

    // Affiche le mot de passe et le nom de l'utilisateur
    printf("The password is: %s\n", password);
    printf("The name is: %s\n", name);

    return 0;
}
