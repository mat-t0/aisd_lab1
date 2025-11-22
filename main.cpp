#include <stdio.h>
#include <iostream>
#include <locale.h>
#include "doubList.hpp"
#include "dArray.hpp"
#include "stack.hpp"
#include "sort.hpp"

void main() {
	setlocale(LC_ALL, "rus");


	
	std::string expr = "( 14 + 2 ) * 13";
	sortStation station(expr);
	station.printPostfix(); 


}
