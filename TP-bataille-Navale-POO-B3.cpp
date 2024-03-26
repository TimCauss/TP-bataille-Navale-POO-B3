// TP-bataille-Navale-POO-B3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace::std;

// Variables constantes du jeu
const int PLAYERSNBR = 2;
const int SHIPNBR = 4;
const int BOARDSIZE = 9;

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
class Boards {

private:
    int size = BOARDSIZE;
    vector<vector<char>> grid;


};


// Créer class Ships(taille, direction, hp)




int main()
{
    std::cout << "Hello World!\n";
}
