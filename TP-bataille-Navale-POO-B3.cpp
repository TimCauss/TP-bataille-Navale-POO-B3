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

        std::cout << "   "; // Le décallage des numéro de colonnes
        for (int col = 0; col < BOARDSIZE; ++col) {
            std::cout << std::setw(2) << col + 1;
        }
        std::cout << std::endl;

        for (int row = 0; row < BOARDSIZE; ++row) {
            std::cout << std::setw(2) << row + 1 << " ";
            for (const char& cell : grid[row]) {
                std::cout << std::setw(2) << cell;
            }
            std::cout << std::endl;
        }
    }
};


// Créer class Ships(taille, direction, hp)




int main()
{
    Board playerBoard;

    playerBoard.print();

    return 0;
}
