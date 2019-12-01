#include "Participant.h"

Participant::Participant() : m_name(""), m_pos(1)
{
}

Participant::~Participant()
{
}

void Participant::affichage() const
{
	cout << getName() << " : " << m_pos << "ieme case(s)" << endl;
}

string Participant::getName() const
{
	return this->m_name;
}

int Participant::getPosition() const
{
	return this->m_pos;
}

void Participant::setName(string _name)
{
	m_name = _name;
}
