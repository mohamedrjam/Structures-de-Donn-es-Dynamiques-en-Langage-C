En programmation, la gestion efficace de la mémoire constitue l'un des piliers fondamentaux du développement de logiciels performants. Le langage C, de par sa proximité avec le matériel et son contrôle explicite de la mémoire, offre deux grandes approches pour stocker des données : les tableaux statiques et les structures dynamiques.
Les tableaux présentent une limitation majeure : leur taille doit être connue au moment de la compilation. En pratique, de nombreuses applications nécessitent de gérer des collections dont le volume est imprévisible — files d'attente, piles d'exécution, listes d'éléments variables. L'allocation dynamique de mémoire, rendue possible par les fonctions 
malloc(), calloc() et free() de la bibliothèque <stdlib.h>, permet de répondre précisément à ce besoin en allouant et libérant de la mémoire à l'exécution (run-time).

Avantages des structures dynamiques vs tableaux
✔  Taille adaptable dynamiquement selon les besoins réels du programme
✔  Pas de gaspillage de mémoire (aucun espace pré-alloué inutilisé)
✔  Insertions et suppressions efficaces sans décalage d'éléments
✘  Surcoût en mémoire (pointeurs) et en temps (appels malloc/free)

Ce rapport présente de manière détaillée trois structures de données fondamentales : les Listes Simplement Chaînées, les Piles (LIFO) et les Files (FIFO). Pour chacune, nous décrirons la structure de données ainsi que les fonctions associées, accompagnées de leur implémentation en C.
