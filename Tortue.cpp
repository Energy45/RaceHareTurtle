#include "Tortue.h"

const int MARCHE_PENIBLE_RAPIDE = 3;
const int GLISSADE = -6;
const int MARCHE_PENIBLE_LENTE = 1;

Tortue::Tortue() : Participant()
{
	static int countTortue = 1; // Compte n ieme tortue

	setName("T" + to_string(countTortue)); // Set le nom 

	countTortue++;
}

Tortue::~Tortue()
{
}

/// M�thode polymorphe en fonction du participant
/// Mouvement :
///		Marche p�nible rapide -> 50% : +3
///		Glissade -> 20% : -6
///		Marche p�nible lente -> 30% : +1
void Tortue::bouger()
{
	int nbRandom = rand() % 100 + 1; // De 1 a 100

	if (nbRandom >= 1 && nbRandom <= 50) // Marche p�nible rapide -> 50% : +3
	{
		m_pos += MARCHE_PENIBLE_RAPIDE;
	}
	else if (nbRandom > 50 && nbRandom <= 70) // Glissade -> 20% : -6
	{
		m_pos += GLISSADE;
	}
	else if (nbRandom > 70 && nbRandom <= 100) // Glissade -> 20% : -6
	{
		m_pos += MARCHE_PENIBLE_LENTE;
	}

	if (m_pos < 1)
		m_pos = 1; //Retour case d�part
	else if (m_pos >= 70)
		m_pos = 70; //Fin de la partie
}
