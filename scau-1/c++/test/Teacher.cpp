#include <iostream>
#include "Teacher.h"
#include <string>
using namespace std;


Teacher::Teacher(string name, int score):m_strName(name), m_iScore(score){}

void Teacher::setName(string name)
{
	m_strName = name;
}

string Teacher::getName()
{
	return m_strName;
}

void Teacher::setScore(int score)
{
	m_iScore = score;
}

int Teacher::getScore()
{
	return m_iScore;
}
