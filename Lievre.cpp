#include "Lievre.h"

const int SOMMEIL = 0;
const int GRAND_SAUT = 9;
const int GRANDE_GLISSADE = -12;
const int PETIT_SAUT = 1;
const int PETITE_GLISSADE = -2;

Lievre::Lievre() : Participant()
{
	static int countLievre = 1; //Compte le n ieme lievre

	setName("L" + to_string(countLievre)); //L ieme

	countLievre++;
}

Lievre::~Lievre()
{

}


/// Méthode polymorphe en fonction du participant
/// Mouvement :
///		Sommeil -> 20% : 0
///		Grand saut -> 20% : +9
///		Grande glissade -> 10% : -12
///		Petit saut -> 30% : +1
///		Petite glissade -> 20% : -2
void Lievre::bouger()
{
	int nbRandom = rand() % 100 + 1;

	if (nbRandom >= 1 && nbRandom <= 20) // Sommeil -> 20% : 0
	{
		m_pos += SOMMEIL;
	}
	else if (nbRandom > 20 && nbRandom <= 40) // Grand saut -> 20% : +9
	{
		m_pos += GRAND_SAUT;
	}
	else if (nbRandom > 40 && nbRandom <= 50) // Grande glissade -> 10% : -12
	{
		m_pos += GRANDE_GLISSADE;
	}
	else if (nbRandom > 50 && nbRandom <= 80) // Petit saut -> 30% : +1
	{
		m_pos += PETIT_SAUT;
	}
	else if (nbRandom > 80 && nbRandom <= 100) // Petite glissade -> 20% : -2
	{
		m_pos += PETITE_GLISSADE;
	}

	if (m_pos < 1)
		m_pos = 1; //Retour case départ
	else if (m_pos >= 70)
		m_pos = 70; //Fin de la partie
}
