
#include <iostream>
using namespace std;


const int lignes = 3;
const int colonnes = 3;

void initialiserLeTableau(char tab[lignes][colonnes]) {
    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            tab[i][j] = ' ';
        }

    }

}

void afficherTable(char tab[lignes][colonnes]) {
    cout << endl;
    /*cout << "1   2   3" << endl;
    cout << "----------" << endl;*/
    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            cout << tab[i][j];
            if (j < colonnes - 1) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < lignes -1) {
            cout << "--|---|--" << endl;
        }
    }
    cout << endl;
}

void faireUnStep(char tab[lignes][colonnes], char caractere, int ligne, int colonne) {
    tab[ligne][colonne] = caractere;
}


bool valideStep(char tab[lignes][colonnes], int ligne, int colonne) {
    if (ligne < 0 || ligne >= lignes || colonne < 0 || colonne >= colonnes) {
        return false;
    }
    if (tab[ligne][colonne] != ' ') {
        return false;
    }
    return true;
}


bool aGagner(char tab[lignes][colonnes], char joueur) {

    for (int i = 0; i < lignes; i++)
    {
        if (tab[i][0] == joueur && tab[i][1] == joueur && tab[i][2] == joueur) {
            return true;
        }
    }
    for (int j = 0; j < colonnes; j++)
    {
        if (tab[0][j] == joueur && tab[1][j] == joueur && tab[2][j] == joueur) {
            return true;
        }
    }
    if (tab[0][0] == joueur && tab[1][1] == joueur && tab[2][2] == joueur) {
        return true;
    }
    if (tab[0][2] == joueur && tab[1][1] == joueur && tab[2][0] == joueur) {
        return true;
    }
    // aucun gagant
    return false;
}

bool etMarquee(char tab[lignes][colonnes]) {
    for (int ligne = 0; ligne < lignes; ligne++)
    {
        for (int col = 0; col < colonnes; col++)
        {
            if (tab[ligne][col] == ' ') {
                return false;
            }
        }
    }
    if (!aGagner(tab, 'X') && !aGagner(tab, 'O')) {
        return true;
    }
    else {
        return false;
    }
}


bool jouerEncore() {
    char choix;
        cout << "Voulez-vous joue encore? (y/n): ";
        cin >> choix;
    while (choix != 'y' && choix != 'n') {
        cout << "Choix invalide. Réessayez 'y' ou 'n': ";
        cin >> choix;
    }
    return choix == 'y';
}

void afficherResultat(char resultat, char j1, char j2, int score1, int score2) {

    cout << endl;
    if (resultat == 'X') {
        cout << "Joueur " << j1 << " a gagner!" << endl;
        score1++;
    }
    else if (resultat == 'O') {
        cout << "Joueur " << j2 << " a gagner!" << endl;
        score2++;
    }
    else {
        cout << "Draw!" << endl;
    }
    cout << "Score: " << j1 << " = " << score1 << ", " << j2 << " = " << score2 << endl;
}

int main()
{

   /* int ligne = 0;
    int cols = 0;
    char tab[lignes][colonnes];

    initialiserLeTableau(tab);
    afficherTable(tab);
    do{
        do{
    cout << "Entrer une ligne de (0-2) et colonne de (0-2) separee par un espace: " << endl;
    cin >> ligne;
    cin >> cols;
        } while (ligne < 0 || ligne >= 2 || cols < 0 || cols >= 2 || tab[ligne][cols] !=' ');
    for (int i = 0; i < lignes; i++)
    {
        for (int j= 0; j < colonnes; j++)
        {
            tab[ligne][cols] = 'X';
        }

    }

    afficherTable(tab);
    } while (jouerEncore());*/

    char tab[lignes][colonnes];
    char j1 = 'X';
    char j2 = 'O';
    int score1 = 0;
    int score2 = 0;
    char jActuelle;
    bool gameOver = false;

    do {
        initialiserLeTableau(tab);
        jActuelle = (rand() % 2 == 0) ? j1  :  j2;
        cout << endl;
        while (!gameOver) {
            afficherTable(tab);
            cout <<"Joueur actuelle '" << jActuelle << "' ," << "Entrer une ligne de (1-3) et colonne de (1-3) separee par un espace: ";
            int ligne, col;
            cin >> ligne >> col;

            if (valideStep(tab, ligne - 1, col - 1)) {
                faireUnStep(tab, jActuelle, ligne - 1, col - 1);

                if (aGagner(tab, jActuelle)) {
                    gameOver = true;
                    if (jActuelle == j1) {
                        score1++;
                        afficherResultat('X', j1, j2, score1, score2);
                    }
                    else {
                        score2++;
                        afficherResultat('O', j1, j2, score1, score2);
                    }
                }
                else if (etMarquee(tab)) {
                    gameOver = true;
                    afficherResultat('D', j1, j2, score1, score2);
                }
                else {
                    jActuelle = (jActuelle == j1) ? j2 : j1;
                }
            }
            else {
                cout << "Invalid step! Reessayez" << endl;
            }
        }
    } while (jouerEncore());

    
}

