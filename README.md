circles = [] // [(1, 1, 10), (3, 5, 7), ...]

while true
	je choisi une position random
	si elle n'est pas valide
		je recommence
	je calcule la taille max possible (penser au bordure, aux autre cercle, et a une taille max generique)
	je choisi une taille random dans ces limites
	je dessine mon cercle
	j'enregistre le cercle dans ma liste