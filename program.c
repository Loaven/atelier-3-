#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Procédure pour afficher le texte correspondant au choix
void afficher_choix(int choix) {
    switch (choix) {
        case 1:
            printf("Pierre");
            break;
        case 2:
            printf("Feuille");
            break;
        case 3:
            printf("Ciseaux");
            break;
        case 4:
            printf("Lézard");
            break;
        case 5:
            printf("Spock");
            break;
        default:
            printf("Inconnu");
            break;
    }
}

// Définition de la procédure afficher_bilan
void afficher_bilan(int scoreJoueur, int scoreOrdi) {
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous : %d | Ordi : %d\n", scoreJoueur, scoreOrdi);

    if (scoreJoueur > scoreOrdi) {
        printf("Bravo, vous avez gagné la partie !\n");
    } else if (scoreOrdi > scoreJoueur) {
        printf("L'ordinateur remporte la partie...\n");
    } else {
        printf("Match nul parfait !\n");
    }
}

int main(void) {
    int scoreJoueur = 0;
    int scoreOrdi = 0;

    int manche = 1;
    int choixJoueur;
    int choixOrdi;

    printf("=== PIERRE, FEUILLE, CISEAUX, LEZARD, SPOCK (7 Manches / avantage décisif de 2) ===\n");

    while (manche <= 7 
           && scoreJoueur - scoreOrdi < 2 
           && scoreOrdi - scoreJoueur < 2) 
    {
        printf("--- Manche %d/7 ---\n", manche);

        // Saisie du joueur
        bool incorrect;

        do {
          // Affichage du menu avec la boucle for (de 1 à 5)
            printf("Choix (");
            for (int i = 1; i <= 5; i++) {
                printf("%d = ", i);
                afficher_choix(i);
                if (i < 5) printf(", ");
            }
            printf(") : ");

            scanf("%d", &choixJoueur);
            incorrect = choixJoueur < 1 || 5 < choixJoueur;

            if (incorrect) {
                printf("Non valide, valeurs de 1 à 5 acceptées\n");
            }
        } while (incorrect);

        // Choix aléatoire de l'ordinateur (1, 2, 3, 4 ou 5)
        choixOrdi = (rand() % 5) + 1;

        // Affichage du choix de l'ordinateur via la procédure
        printf("L'ordinateur a choisi : ");
        afficher_choix(choixOrdi);
        printf("\n");


        // Détermination du gagnant de la manche
        if (choixJoueur == choixOrdi) {
            printf("Égalité !\n");
        } 
        else if ((choixJoueur == 1 && (choixOrdi == 3 || choixOrdi == 4)) ||
                 (choixJoueur == 2 && (choixOrdi == 1 || choixOrdi == 5)) ||
                 (choixJoueur == 3 && (choixOrdi == 2 || choixOrdi == 4)) ||
                 (choixJoueur == 4 && (choixOrdi == 2 || choixOrdi == 5)) ||
                 (choixJoueur == 5 && (choixOrdi == 1 || choixOrdi == 3))) 
        {
            printf("Vous gagnez cette manche !\n");
            scoreJoueur = scoreJoueur + 1;
        } 
        else {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi = scoreOrdi + 1;
        }

        printf("Score actuel -> Vous : %d | Ordi : %d\n\n", scoreJoueur, scoreOrdi);
        manche = manche + 1;
    }
    // Appel de la procédure pour afficher le bilan
    afficher_bilan(scoreJoueur, scoreOrdi);

    return 0;
}