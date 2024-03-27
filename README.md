#Projet de cours de 3eme année Bachelor

##Projet Bataille Navale en C++

###Créer un jeu de bataille naval pour 2 joueurs en orienté objet.

Déscription :
Pour ce jeu j'ai choisi de créer 3 objets distincts :
1. Boards
- Responsabilité : Gérer la grille de jeu pour chaque joueur, y compris la visualisation de la grille, l'emplacement des navires et le suivi des tirs.
2. Players
- Responsabilité : Représenter chaque joueur, contenant leurs informations (nom, score...), leur plateau de jeu (Board) et leurs flottes (Ships).
3. Ships
- Responsabilité : Gérer les caractéristiques des navires (taille, points de vie, position...), ainsi que leur état (intact, touché, coulé).
4. Game
- Responsabilité : Gérer les objets et le jeu (initialisation de la partie, création des instances, gestion des conditions de victoire).

1 - Création de la classe board:

Je commence par créer la classe Board pour tester son affichage, afin d'avoir une bonne base pour le plateau du jeu.

J'ai créé un constructeur qui utilise un tableau en 2D. Il est initialisé avec la constante BOARDSIZE pour définir sa taille et rempli de la constante de type char, SEACHAR.

Pour des raisons de lisibilité et de facilité du gameplay, j'ai ajouté les numéros des colonnes et des lignes, en utilisant une simple boucle for qui s'incrémente pour les colonnes.

Les numéros de colonnes étaient dans un premier temps décalés. J'ai dû insérer un cout contenant le nombre d'espaces suffisant pour réaligner tout cela. Pour gérer l'espacement de la grille, j'utilise la méthode setw(int) qui me permet de gérer les espacements dans les sorties standards. Je passe une constante BOARDSETW dans setw() pour gérer tous les espacements en même temps.

Pour générer l'affichage de la grille, on utilise une boucle for pour itérer sur les lignes.
Avant d'afficher la ligne, on affiche le numéro de la ligne (qu'on incrémente à chaque boucle).
On itère ensuite dans une boucle interne pour afficher chaque "cellule" 

Un appel à l'objet puis un print de l'objet permet d'afficher la grille :
![image](https://github.com/TimCauss/TP-bataille-Navale-POO-B3/assets/96956172/86eb58b3-5b88-49b4-b9f2-34ef92f35e29)


Après cette étape j'ai décidé de m'attaquer à la construction de la classe player.

2 - Création de la classe Player:

J'ai décidé que le joueur aura un nom, un id, sa grille et son vector de shipset décidé des attribus en conséqence puis fait un constructeur.
La liste d'initialisation du constructeur set directement le nom, et la board du joeur.
Dans les instruction du constructeur j'ajoute la valeur du compteur static (nextId) à l'id du joueur puis je l'incrémente pour le prochains joueur.
Je laisse un commentaire pour créer l'initialisation du vecteur de ships.

J'ai ensuite fait des getters pour récupérer le nom, le board l'id.
Et une méthode pour print le board du joueur via l'appel de son instance.

Je change le main pour tester la nouvelle classe :
![image](https://github.com/TimCauss/TP-bataille-Navale-POO-B3/assets/96956172/5b0ba757-56e8-47de-a558-76fa8cc4688b)
Ca fonctionne correctement.
j'ai eu quelque soucis pour l'ID j'ai du apprendre sur internet pour sortir un compteur int static qui était déclaré en global

3 - Creation de la class Ship :
Comme d'habitude, on commence par les attributs j'ai choisis ici de stocker la taille, la coordonnée x, la coordonnée y, les hits et l'orientation.
L'orientation sera un char qui représente H pour horizontal ou V pour vertical.
Je fais un constructeur qui set toutes les varleur à l'appel d'une instance sauf hits qui sera défini à 0 lors de l'appel.

Je m'attaque aux getters, un pour chaque attributs.
Ensuite une méthode isSunk qui renvoie un bool si les hits sont égaux ou supérieur à la taille.
Et finalement une méthode qui incrémente le hits à son appel.

4 - Ajout de méthodes dans la class Board :

Pour placer les bateaux j'ai besoin d'une méthode dédié à cela dans la class board, mais je dois d'abord vérifier si le bateau peut être placé.
J'ai donc fait une méthode de vérification qui retourne un bool en comparant :

  Si l'orientation est horizontal : la coordonée y + la taille à la BOARDSIZE. (false)
    Puis on itére sur toute la taille pour chercher dans les coordonnées y si on trouve un SHIPCHAR (qui représente la lettre d'une partie de bateau sur le plateau). (false)

  Si l'orientation est vertical : la coordonnée x + la taille à la BOARDSIZE. (false)
    Puis on itére sur toute la taille pour chercher dans les coordonnées x si on trouve un SHIPCHAR. (false)
Si tous les tests passent, on retour true et on peu donc placer le bateau.
On appelera ensuite cette méthode pour vérifier l'emplacement des bateau.

Je m'attaque ensuite à la méthode de placement des bateaux, 
Je récupère les attributs de la ref de l'objet Ship
Je vais utiliser la même technique que la vérification dans les boucles sans qu'on va set les char à la place de les comparer. 
Pour une vérification, elle retourne false si elle ne peu pas placer le bateau et true apres le placement (je ne sais pas encore comment je vais l'utiliser).

5 - Initialisation des bateaux :

J'ai réfléchit pendant pas mal de temps pour savoir si je codais cette méthode dans la class Game, Board ou Player.
J'ai décidé de la mettre dans la class player. C'est pour moi plus représentatif sachant que chaque bateau ira se mettre dans un array ou vector contenu dans l'instance du joueur.

J'ai ajouté donc deux méthodes une qui initialise les bateaux dans l'instance du joueur et l'autre qui les places.
Ca m'a pris quelques heures... J'ai mis quelque temps à trouver la technique de génération du random aléatoire pour le placement.

![image](https://github.com/TimCauss/TP-bataille-Navale-POO-B3/assets/96956172/308c71d0-2ff7-41b9-bd0e-c09e6826ef15)

Maintenant que nous avons nos ship je vai pouvoir commencer la boucle de gameplay.

6 - Class Game:

Pour gérer le jeu et les objets j'ai décidé de créer une class Game.
Elle aura pour attributs les noms des joueurs, et un tableau des joueurs.

elle comprendra la construction des joueurs, et la gestion de la boucle de gameplay et de la condition de victoire.

en parrallèle : 
- j'ai ajouté une méthode vérification des tir dans la class Board.
- Un appel à cette méthode dans la class joueur.

La classe game contient une méthode GameOver qui va vérifier la grid ennemy pour savoir s'il reste des bateaux.
Je voulais faire une gestion complète de la flote via les instance des ships mais je n'ai pas le temps.











