-------------------------------------------------------------------------
		GOALS
-------------------------------------------------------------------------

Parseur: tetriminos.
	- un seul fichier en entree
	- les  tetriminos sont sur 4 lignes de 4 chars + 1 \noreturn
	- return l"usage" et quitter de maniere propre si parseur non respecte
	- chaque caracteree est soit un # soit un .
	- pas plus de 4 #
	- forme de tetris respectee, contact entre tetriminos
	- jamais plus de 26 tetriminos.

Stockage: tetriminos
	- stocker le nom de la piece
	- stocker sa position de maniere a ce qu'elle soit exploitable'
	- il y a un total de 19 positions possible de tetriminos sachant
		 qu'ils ne sont aucun cas tournable'.
	
	

Backtracking.
	- stocker les tetriminos sous int et les agencer dans la grille en fonction
	-

A faire pendant la prochaine session:
	//-Open_ang get file
	- parse file
	//- cut pieces**
	//-find out minimal grid size
	//-fillit.h
	- Norminette

DECALAGE BINAIRE
	//- On cherche a obtenir la "forme absolue" de la piece, soit sa forme deplacee
	//	vers en haut a gauche au maximum
	//- Chopper le premier # de la colonne et deplacer vers la gauche en fonction
	//- decaler encore si les lignes sont vides up-top;


	Bonus points:
	- Makefile
	- Backtracking

-------------------------------------------------------------------------
	Fonctionnement
-------------------------------------------------------------------------

On possede une grille et on essaie de placer les tetriminos dans totes les
cpmbinations possible jusqua ce que ca rentre. Si toutes positions ont etes
faites et qu'aucune n'est valide on augmente la taille de la grille pour
ressayer jusqua ce que ca marche


idee 1: stocker les tetriminos en 1 it en fonction de leur forme et faire
ldes fonctions de placements qui les mettrai  

COUPER LES PIECES:

pour couper les pieces:
- Commencer par les extrraire du fichier en et les regrouper par 16 bits
- Stocker les serie de 16 dans un tableau de str;
- check la str, si la ligne est vide, on rappelle ;

GRILLE EN INT ?

- comparaison entre bits = plus rapide que comparaison entre chars
	- comparer la forme absolue de la piece avec une grille faite en int
	- et stocker dans la piece son placement final pour son affichage plus tard
		(genre fouttre une condition au niveau du backtracking qui dit
		 que tu stocke si la prochaine piece a reeussi a se placer)
-
		
TETRIMINOS_PARSING:

-Check le format des tetriminos
	- 4 char par ligne
	- 4 lignes par tetri
	- 4 hash par tetri
	- les char ne sont pas autres que # et . ou '\n'

-Check la forme des tetriminos
	- si un hash est present et qu''il y en avait un avant, ils sont relies

-Check la separation inter-tetriminos
	- Si il y a deux tetriminos, ils sont separes par un '\n.'
	- Si un '\n' est present mais qu'il n'ya a pas de tetri -> error

-Check le nombre total de tetriminos
	- pas plus de 26 tetriminos or die.

-------------------------------------------------------------------------
		BUGS
-------------------------------------------------------------------------

ligne = 2;
T = 4;
L = 4;
L inverse = 4;
carre = 1;
escaliers = 4;

