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

// Cr�er class Joueur
// Les joueurs peuvent avec des ships et une board

class Players {
private:
    string name;
    int id;

};


// Cr�er class Board(taille)
// Devra contenir la taille, le plateau lui-m�me, 
// une m�thode de repr�sentation du board
// une m�thode de placement des ships
// une m�thode de gestion des tir (modification de la grille)
class Boards {

private:
    int size = BOARDSIZE;
    vector<vector<char>> grid;


};


// Cr�er class Ships(taille, direction, hp)




int main()
{
    std::cout << "Hello World!\n";
}
