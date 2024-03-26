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



// Cr�er class Joueur
// Les joueurs peuvent avec des ships et une board

class Players {
private:
    string name;
    int id;
    Board board;
    // vector de ships � faire apres

public:
    Players(const string& n) : name(n), board(Board()){
        // Cr�ation de ship � faire plus tard
    }

    //getters :
    const string& getName() {
        return name;
    }

    Board& getBoard() {
        return board;
    }

    // Faire getteur de la flotte ici



};


// Cr�er class Board(taille)
// une m�thode de placement des ships
// une m�thode de gestion des tir (modification de la grille)
class Board {

private:
    int size = BOARDSIZE;
    vector<vector<char>> grid;

public:

    //Constructeur:
    Board() : grid(size, vector<char>(size, SEACHAR)) {}
    
    void print() const {

        // num�ro des colonnes
        cout << "   "; // Le d�callage des num�ro de colonnes
        for (int col = 0; col < BOARDSIZE; ++col) {
            cout << setw(BOARDSETW) << col + 1;
        }
        cout << endl;

        // Grille
        for (int row = 0; row < BOARDSIZE; ++row) {         // On initiase la boucle avec row comme indice de ligne.
            cout << setw(BOARDSETW) << row + 1 << " "; // Num�ro de ligne.
            for (const char& cell : grid[row]) {            // On it�re ensuite sur chaque ref de cellule dans la ligne correspondante.    
                cout << setw(BOARDSETW) << cell;       // On retourne le contenu de la cellule (cell).
            }
            cout << endl;
        }
    }
};


// Cr�er class Ships(taille, direction, hp)


// Cr�er une class Game pour g�rer la partie




int main()
{
    Board playerBoard;

    playerBoard.print();

    return 0;
}
