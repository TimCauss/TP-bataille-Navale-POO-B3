// TP-bataille-Navale-POO-B3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
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



//Games :                   // pense bete std::array<int, 3> a = {1, 2, 3};
class Game {
private:
    string playerName1;
    string playerName2;


    // A TERMINER
    /*
    Game() {
        players[0] = Player(playerName1);
        players[1] = Player(playerName2);
    }
    */

    void run(){
        //A faire, méthode pour une boucle de gameplay
    }


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

    //setter

    void setPosition(int x, int y, char orientation) {
        this->x = x;
        this->y = y;
        this->orientation = orientation;
    }

    // Methdes

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
        placeFleet();           // on place les ships du joueur
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

private:

    //void initializeFleet()

    void placeFleet() { // TODO: Faire une boucle de placement
        for (Ship& ship : fleet) {
            bool placed = false;
            while (!placed) {
                char orientation = 'H';
                int x = rand() % BOARDSIZE;
                int y = rand() % BOARDSIZE;

                int randomNum = rand() % 2 ;
                if (randomNum == 0) {
                    char orientation = 'H';
                }
                else {
                    char orientation = 'V';
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


//Initialisation du compteur d'ID :
int Player::nextId = 1;


int main()
{
    srand(time(0)); // On génére la seed du random de la partie basé sur le temps (a optimiser pour une meilleur random)

    Player player1("Chrisophe");
    Player player2("Louis");


    cout << "Player 1 ID : " << player1.getID() << ", Name: " << player1.getName() << endl;
    player1.printBoard();
    cout << endl << endl;
    cout << "Player 2 ID : " << player2.getID() << ", Name: " << player2.getName() << endl;
    player2.printBoard();

    return 0;
}
