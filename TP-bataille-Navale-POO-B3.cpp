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


    bool placeShip(Ship& ship) {
        // A faire apres la verif
    }


    //Method de verif de placement
    bool canPlaceShip(int x, int y, int size, char orientation) {
        if (orientation == 'H') {
            if (y + size > BOARDSIZE) return false;

        }
    }

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



// Cr�er class Joueur

class Players {
private:
    string name;
    static int nextId;
    int id;
    Board board;
    // vector de ships � faire apres

public:
    Players(const string& n) : name(n), board(Board()){
        id = nextId++;
        // Cr�ation de ship � faire plus tard
    }

    //getters :
    const string& getName() {
        return name;
    }

    const Board& getBoard() {
        return board;
    }

    void printBoard() {
        board.print();
    }

    const int& getID() {
        return id;
    }

    // Faire getteur de la flotte ici



};



// SHIP
class Ship {
private:
    int size, x, y, hits;
    char orientation;

public:
    Ship(int(s), int(x), int(y), char(o)) : size(s), x(x), y(y), orientation(o), hits(0) {}

    // Getters:
    int getSize() {
        return size;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getOrientation() {
        return orientation;
    }

    // Methdes
    bool isSunk() {
        return hits >= size;
    }

    void hits() {
        hits++;
    }

};

// Cr�er une class Game pour g�rer la partie


//Initialisation du compteur d'ID :
int Players::nextId = 1;


int main()
{

    Players player1("Chrisophe");
    Players player2("Louis");

    cout << "Player 1 ID : " << player1.getID() << ", Name: " << player1.getName() << endl;
    player1.printBoard();

    cout << "Player 2 ID : " << player2.getID() << ", Name: " << player2.getName() << endl;
    player2.printBoard();

    return 0;
}
