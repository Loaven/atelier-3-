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
// 1. Condition d'arrêt
bool partie_en_cours(int manche, int scoreJoueur, int scoreOrdi) {
    return (manche <= 7 
            && scoreJoueur - scoreOrdi < 2 
            && scoreOrdi - scoreJoueur < 2);
}
// 2. Saisie du joueur
int saisie_joueur(void) {
    int choix;
    bool incorrect;

    do {
        printf("Choix (");
        for (int i = 1; i <= 5; i++) {
            printf("%d = ", i);
            afficher_choix(i);
            if (i < 5) printf(", ");
        }
        printf(") : ");

        scanf("%d", &choix);
        incorrect = choix < 1 || 5 < choix;

        if (incorrect) {
            printf("Non valide, valeurs de 1 à 5 acceptées\n");
        }
    } while (incorrect);

    return choix;
}
// 3. Test de victoire
bool joueur1_gagne(int c1, int c2) {
    return ((c1 == 1 && (c2 == 3 || c2 == 4)) ||
            (c1 == 2 && (c2 == 1 || c2 == 5)) ||
            (c1 == 3 && (c2 == 2 || c2 == 4)) ||
            (c1 == 4 && (c2 == 2 || c2 == 5)) ||
            (c1 == 5 && (c2 == 1 || c2 == 3)));
}

int main(void) {
    int scoreJoueur = 0;
    int scoreOrdi = 0;
    int manche = 1;

    printf("=== PIERRE, FEUILLE, CISEAUX, LEZARD, SPOCK (7 Manches / avantage décisif de 2) ===\n");

    // Utilisation de la fonction partie_en_cours
    while (partie_en_cours(manche, scoreJoueur, scoreOrdi)) {
        printf("--- Manche %d/7 ---\n", manche);

// Initialisation de choixJoueur via la fonction saisie_joueur
        int choixJoueur = saisie_joueur();

        // Choix ordinateur
        int choixOrdi = (rand() % 5) + 1;
        printf("L'ordinateur a choisi : ");
        afficher_choix(choixOrdi);
        printf("\n");

        // Détermination du vainqueur avec joueur1_gagne
        if (choixJoueur == choixOrdi) {
            printf("Égalité !\n");
        } 
        else if (joueur1_gagne(choixJoueur, choixOrdi)) {
            printf("Vous gagnez cette manche !\n");
            scoreJoueur++;
        } 
        else {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi++;
        }

        printf("Score actuel -> Vous : %d | Ordi : %d\n\n", scoreJoueur, scoreOrdi);
        manche++;
    }

    afficher_bilan(scoreJoueur, scoreOrdi);

    return 0;
}