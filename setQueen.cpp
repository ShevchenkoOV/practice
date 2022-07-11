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
	
#include "setQueen.h"
#include <iostream>

const int SIZE = 8; // Розмір дошки
 
int board[SIZE][SIZE];
int results_count = 0; // кількість вирішень

void Board()
{
    for(int a = 0; a < SIZE; ++a)
    {
        for(int b = 0; b < SIZE; ++b)
        {
            std::cout <<'|'<< ((board[a][b]) ? "Q" : ".");
        }
        std::cout <<'|'<< '\n';
    }
}
 
// Функція tryQueen() - перевіряє, чи немає уже встановлених ферзів по діагоналях та вертикалях
bool tryQueen(int a, int b)
{
    for(int i = 0; i < a; ++i)
    {
        if(board[i][b])
        {
            return false;
        }
    }
    
    for(int i = 1; i <= a && b-i >= 0; ++i)
    {
        if(board[a-i][b-i])
        {
            return false;
        }
    }
    
    for(int i = 1; i <= a && b+i < SIZE; i++)
    {
        if(board[a-i][b+i])
        {
            return false;
        }
    }
    
    return true;
}
 
// Функція setQueen() - пошур результатів вирішення.
void setQueen(int a) // a - номер чергового рядку в який потрібно поставити відповідного ферзя.
{
    if(a == SIZE)
    {
        std::cout <<"\n"<< "Результат № " << ++results_count << "\n";
        Board();
        return; 
    }
    
    for(int i = 0; i < SIZE; ++i)
    {
        // перевірка, що ферзь буде один на вертикалі, горизонталі та діагоналях.
        if(tryQueen(a, i))
        {
            board[a][i] = 1;
            setQueen(a+1);
            board[a][i] = 0;
        }
    }
    
    return; 
}
