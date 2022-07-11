/*
	* @file main.cpp
	* @author Шевченко О. В., гр. 515-і1
	* @date 7 липня 2022
	* @brief літня практика
	*
	* Завдання(46. Розробити програму, що випадковим чином розташовує на
шаховій дошці розміром 8x8 вісім ферзів так, щоб вони не загрожували один
одному)
	*/

#ifndef SETQUEEN_H
#define SETQUEEN_H


void Board();
bool tryQueen(int a, int b);
void setQueen(int a);

#endif
