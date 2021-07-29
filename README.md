# Infinite Conquest

Projet réalisé 3 semaines en C++ avec la librairie graphique SFML pour l'UE Projet de la licence 3 d'informatique de l'UPJV

## Explications

Le joueur dispose d'un personnage (accompagné d'un familier) et doit battre des ennemies un à un.
À chaque victoire, le joueur choisit un bonus, mais les ennemies deviennent aussi de plus en plus fort.
Le nombre d'ennemis étant infini, le jeu se termine quand le joueur n'a plus de vie. Le but est donc de faire le meilleur score possible.

Durant un combat, un curseur se déplace de droite à gauche le long d'une barre.
Des pastilles vertes apparaissent à une position aléatoire sur cette barre. 
Des pastilles rouges apparaissent sur le côté droit de la barre et se déplacent vers la gauche.

Pour attaquer, le joueur doit appuyer sur la barre espace au moment où le curseur est sur une pastille verte.
L'ennemi attaque si le joueur ne parvient pas à appuyer sur une pastille rouge avant qu'elle n'atteigne le côté gauche de la barre ou si le joueur appuie sur la barre espace sans être sur une bastille.
Le familier attaque l'ennemie de manière aléatoire sans intervention du joueur.
Le personnage du joueur peut lancer une attaque faisant plus de dégâts s'il réussit un combo (en ne ratant aucune pastille) en appuyant sur la touche C.

Si le personnage est battu, il perd l'intégralité des bonus obtenus durant la partie.

## Démonstration

https://user-images.githubusercontent.com/38865028/127519216-06d11fe0-2e43-414b-81ec-69b133532649.mov
