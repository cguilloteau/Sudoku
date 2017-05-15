class Grille {
public:
    /** \fn Grille()
	 *
	 *\brief Constructeur permettant de créer une grille. Aucun attribut n'est initialisé dans le constructeur. Ils le seront plus tard via la fonction allocationTaille.
	 *
	 */
	Grille();
	virtual ~Grille();


	/** \fn allocationTaille(int laTaille)
    *
    *\brief fonction permettant d'allouer les dimensions du tableau dynamique en fonction de la taille qui a été choisie préalablement.
    *
    */

	void allocationTaille(int laTaille);

	/** \fn int getTaille()const
    *
    *\brief Getteur permettant de récupérer la valeur de l'attribut Taille pour un objet Grille.
    *
    *\return le nombre de lignes ou de colonnes d'une grille de Jeu.
    */

	int getTaille()const;

	/** \fn setTaille(int uneTaille)
    *
  	 *\brief Setteur permettant de modifier la valeur de l'attribut Taille pour un objet Grille.
    *
    */
	void setTaille(int uneTaille);

	/** \fn chgtValeur(const int lig, const int col, const int val)
    *
    *\brief fonction permettant de modifier la valeur d'une case de la grille choisie en fonction de sa position sur la grille ( ligne et colonne ).
    *
    */


	void chgtValeur(const int lig, const int col, const int val);

	/** \fn obtenirValeur(const int lig, const int col)
    *
    *\brief fonction permettant de récupérer la valeur d'une case de la grille choisie en fonction de sa position sur la grille ( ligne et colonne ).
    *
    *\return la valeur de la case.
    */

	int obtenirValeur(const int lig, const int col);

	/** \fn copier(Grille uneGrille)
    *
  	 *\brief fonction permettant copier le contenu d'une grille dans une autre
    */

	void copier(Grille uneGrille);

	/** \fn afficher()
    *
    *\brief fonction permettant d'afficher la grille de manière esthétique sur le terminal
    */
	void afficher();
