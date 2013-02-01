//Poker.h
#ifndef _POKER_H_
#define _POKER_H_

#include <iostream>
#include "time.h"
using namespace std;

struct Card{
     int a[5];
	 int num;
};

class Poker
{
public:
	Poker::Poker();
	void Deal();
	void Play();
private:
    int	m_oringal[10];
    Card A;
	Card B;
};

#endif