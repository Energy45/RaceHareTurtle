#pragma once

#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Participant
{
public:
	Participant();
	virtual ~Participant();

	virtual void bouger() = 0;
	virtual void affichage() const;

	string getName() const;
    unsigned int getPosition() const;

private:
	string m_name;

protected:
    unsigned int m_pos;

	void setName(string _name);
};

