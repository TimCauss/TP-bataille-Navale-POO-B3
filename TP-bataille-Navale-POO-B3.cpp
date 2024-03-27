// TP-bataille-Navale-POO-B3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <Windows.h>



using namespace::std;

// Variables constantes du jeu
const int PLAYERSNBR = 2;
const int SHIPNBR = 4;
const int BOARDSIZE = 9;
const int BOARDSETW = 2;

const char SHIPSCHAR = 'X';
const char SEACHAR = '0';
const char MISSCHAR = '+';
const char HITCHAR = 'H';


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

    //setter

    void setPosition(int x, int y, char orientation) {
        this->x = x;
        this->y = y;
        this->orientation = orientation;
    }

    // Methodes

    bool isSunk() {
        return hits >= size;
    }

    void hit() {
        hits++;
    }

};

class Board {

private:
    int size = BOARDSIZE;
    char grid[BOARDSIZE][BOARDSIZE];

public:

    //Constructeur:
    Board() {
        for (int i = 0; i < BOARDSIZE; ++i) {
            for (int j = 0; j < BOARDSIZE; ++j) {
                grid[i][j] = SEACHAR;
            }
        }
    }


    //Method de verif de placement
    bool verifPlaceShip(int x, int y, int size, char orientation) {
        if (orientation == 'H') {
            if (y + size > BOARDSIZE) return false;
            for (int i = 0; i < size; ++i) {
                if (grid[x][y + i] == SHIPSCHAR) return false;
            }
        }
        else if (orientation == 'V') {
            if (x + size > BOARDSIZE) return false;
            for (int i = 0; i < size; ++i) {
                if (grid[x + i][y] == SHIPSCHAR) return false;
            }
        }
        return true;
    }

    bool placeShip(Ship& ship) {
       int size = ship.getSize();
       int x = ship.getX();
       int y = ship.getY();
       char orientation = ship.getOrientation();

       if (!verifPlaceShip(x, y, size, orientation)) return false;

       if (orientation == 'H') {
           for (int i = 0; i < size; i++) {
               grid[x][y + i] = SHIPSCHAR;
           }
       }
       else if (orientation == 'V') {
           for (int i = 0; i < size;  i++) {
               grid[x + i][y] = SHIPSCHAR;
           }
       }
       return true;
    }

    // Méthode pour gérer les tirs
    // TODO : Vérifier si le bateau est coulé
    bool attack(int x, int y) {
        x--;
        y--;
        // On verif si les coord sont sur la map:
        if (x < 0 || x >= BOARDSIZE || y < 0 || y >= BOARDSIZE) {
            cout << "Frerot t'es en dehors de la map ! " << endl;
            return false;
        }

        // On vérif s'il y a un bateau :
        if (grid[x][y] == SHIPSCHAR) {
            grid[x][y] = HITCHAR;
            // TODO verif bateau coulé
            return true;
        }
        else {
            grid[x][y] = MISSCHAR;
            return false;
        }
    }

    bool areAllShipsSunk() const {
        for (int i = 0; i < BOARDSIZE; ++i) {
            for (int j = 0; j < BOARDSIZE; ++j) {
                if (grid[i][j] == SHIPSCHAR) {
                    return false;
                }
            }
        }
        return true;
    }


    void print() const {

        // numéro des colonnes
        cout << "   ";              // Le décallage des numéro de colonnes
        for (int col = 0; col < BOARDSIZE; ++col) {
            cout << setw(BOARDSETW) << col + 1;
        }
        cout << endl;

        // Grille
        for (int row = 0; row < BOARDSIZE; ++row) {         // On initiase la boucle de chaque ligne.
            cout << setw(BOARDSETW) << row + 1 << " ";      // Numéro de ligne.
            for (const char& cell : grid[row]) {            // On itére ensuite sur chaque ref de cellule dans la ligne correspondante.    
                cout << setw(BOARDSETW) << cell;            // On retourne le contenu de la cellule (cell).
            }
            cout << endl;
        }
    }
};

// Class Player

class Player {
private:
    string name;
    static int nextId;
    int id;
    Board board;
    vector<Ship> fleet;

public:
    Player(const string& n) : name(n), board(Board()){
        id = nextId++;
        initializeFleet();      // On initialise d'abord !!!
        placeFleet();           // on place ensuite les ships du joueur
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

    // appel de la méthode attaque de la class board pour vérifier le tir de la board du joueur
    bool attack(int x, int y) {
        return board.attack(x, y);
    }


    bool hasLost() {
        return board.areAllShipsSunk();
    }


private:

    // Append les ship à la flotte du joueur !! doc vector pour trouver un append => emplace_back
    void initializeFleet() { // TODO A mettre dans une boucle qui tourne SHIPNBR fois
        fleet.emplace_back(2, 0, 0, 'H');
    }

    void placeFleet() { // TODO: Faire une boucle de placement
        for (Ship& ship : fleet) {
            bool placed = false;
            while (!placed) {
                char orientation = 'H';
                int x = rand() % BOARDSIZE;
                int y = rand() % BOARDSIZE;

                int randomNum = rand() % 2 ; // A debug !!!
                if (randomNum == 0) {
                    orientation = 'H';
                }
                else {
                    orientation = 'V';
                }

                // on update la pos du bateau :
                ship.setPosition(x, y, orientation);
                // On vérif le placement
                placed = board.verifPlaceShip(x, y, ship.getSize(), orientation);
                if (placed) {
                    board.placeShip(ship);
                }
            }
        }
    }
};

//Games :              
class Game {
private:
    string playerName1;
    string playerName2;
    vector<Player> players;
    int currentPlayerIndex = 0;


public:

    Game() {
        string name1, name2;
        cout << "Entrer le nom du joueur 1: ";
        cin >> playerName1;
        cout << "\nEntrer le nom du joueur 2: ";
        cin >> playerName2;

        players.emplace_back(playerName1);
        players.emplace_back(playerName2);

    }

    //Boucle de gameplay
    void run() {
        cout << "Début du jeu !" << endl;
        while (!GameOver()) {
            Player& currentPlayer = players[currentPlayerIndex];
            Player& enemyPlayer = players[(currentPlayerIndex + 1) % PLAYERSNBR];
            enemyPlayer.printBoard();
            cout << u8"Au tour de " << players[currentPlayerIndex].getName() << " !" << endl;
            int x, y;
            cout << u8"Entrer les coordonnées du tir (numéro de ligne): ";
            cin >> x;
            cout << u8"\nEntrer les coordonnées du tir (numéro de colonne): ";
            cin >> y;
            cout << endl;

            bool hit = enemyPlayer.attack(x, y);
            if (hit) {
                cout << "Dans le mille !" << endl;
            }
            else {
                cout << u8"Raté !" << endl;
            }

            // Vérifier si le joueur a gagné après l'attaque
            if (enemyPlayer.hasLost()) { 
                cout << currentPlayer.getName() << u8" a gagné ! YOUHOUUUUU !" << endl << endl;
                break; // 
            }

            currentPlayerIndex = (currentPlayerIndex + 1) % PLAYERSNBR;
        }
    }

private:
    // Condition de fin
    
    bool GameOver() {
        for (Player& player : players) {
            if (player.hasLost()) {
                return true;
            }
        }
        return false;
    }

};


//Initialisation du compteur d'ID :
int Player::nextId = 1;


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0)); // On génére la seed du random
    
    Game game;
    game.run();


    return 0;
}
