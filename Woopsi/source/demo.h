#ifndef _DEMO_H_
#define _DEMO_H_

#include "woopsi.h"

using namespace std;

class PacMan;
class Calculator;
class Pong;

class Demo : public Woopsi {
public:
	void startup();
	void shutdown();

private:
	PacMan* _pacMan;
	Calculator* _calculator;
	Pong* _pong;
};

#endif