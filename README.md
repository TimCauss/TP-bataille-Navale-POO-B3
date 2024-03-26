#Projet de cours de 3eme année Bachelor

##Projet Bataille Navale en C++

###Créer un jeu de bataille naval pour 2 joueurs en orienté objet.

Déscription :
Pour ce jeu j'ai choisi de créer 3 objets distincts :
1. Boards
- Responsabilité : Gérer la grille de jeu pour chaque joueur, y compris la visualisation de la grille, l'emplacement des navires et le suivi des tirs.
2. Players
- Responsabilité : Représenter chaque joueur, contenant leurs informations (nom, score...), leur plateau de jeu (Board) et leurs navires (Ships).
3. Ships
- Responsabilité : Gérer les caractéristiques des navires (taille, points de vie, position...), ainsi que leur état (intact, touché, coulé).


1 - Création de la classe board:

Je commence par créer la classe Board pour tester son affichage, afin d'avoir une bonne base pour le plateau du jeu.

J'ai créé un constructeur qui utilise un vector de char dans un vector afin d'avoir un vector en 2D. Il est initialisé avec la constante BOARDSIZE pour définir sa taille et rempli de la constante de type char, SEACHAR.

Pour des raisons de lisibilité et de facilité du gameplay, j'ai ajouté les numéros des colonnes et des lignes, en utilisant une simple boucle for qui s'incrémente pour les colonnes.

Les numéros de colonnes étaient dans un premier temps décalés. J'ai dû insérer un cout contenant le nombre d'espaces suffisant pour réaligner tout cela. Pour gérer l'espacement de la grille, j'utilise la méthode setw(int) qui me permet de gérer les espacements dans les sorties standards. Je passe une constante BOARDSETW dans setw() pour gérer tous les espacements en même temps.

Pour générer l'affichage de la grille, on utilise une boucle for pour itérer sur les lignes.
Avant d'afficher la ligne, on affiche le numéro de la ligne (qu'on incrémente à chaque boucle).
On itère ensuite dans une boucle interne pour afficher chaque "cellule" 

Un appel à l'objet puis un print de l'objet permet d'afficher la grille :
![image](https://github.com/TimCauss/TP-bataille-Navale-POO-B3/assets/96956172/86eb58b3-5b88-49b4-b9f2-34ef92f35e29)

