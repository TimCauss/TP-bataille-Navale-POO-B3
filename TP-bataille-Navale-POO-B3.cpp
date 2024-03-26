// TP-bataille-Navale-POO-B3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace::std;

// Variables constantes du jeu
const int PLAYERSNBR = 2;
const int SHIPNBR = 4;
const int BOARDSIZE = 9;
const int BOARDSETW = 2;

const char SHIPSCHAR = 'S';
const char SEACHAR = '0';
const char MISSCHAR = '+';
const char HITCHAR = 'X';



// Créer class Joueur
// Les joueurs peuvent avec des ships et une board

class Players {
private:
    string name;
    int id;

};


// Créer class Board(taille)
// Devra contenir la taille, le plateau lui-même, 
// une méthode de représentation du board
// une méthode de placement des ships
// une méthode de gestion des tir (modification de la grille)
class Board {

private:
    int size = BOARDSIZE;
    vector<vector<char>> grid;

public:

    //Constructeur:
    Board() : grid(size, vector<char>(size, SEACHAR)) {}
    
    void print() const {

        // numéro des colonnes
        cout << "   "; // Le décallage des numéro de colonnes
        for (int col = 0; col < BOARDSIZE; ++col) {
            cout << std::setw(BOARDSETW) << col + 1;
        }
        cout << std::endl;

        // Grille
        for (int row = 0; row < BOARDSIZE; ++row) {         // On initiase la boucle avec row comme indice de ligne.
            cout << std::setw(BOARDSETW) << row + 1 << " "; // Numéro de ligne.
            for (const char& cell : grid[row]) {            // On itére ensuite sur chaque ref de cellule dans la ligne correspondante.    
                cout << std::setw(BOARDSETW) << cell;       // On retourne le contenu de la cellule (cell).
            }
            cout << std::endl;
        }
    }
};


// Créer class Ships(taille, direction, hp)


// Créer une class Game pour gérer la partie




int main()
{
    Board playerBoard;

    playerBoard.print();

    return 0;
}
