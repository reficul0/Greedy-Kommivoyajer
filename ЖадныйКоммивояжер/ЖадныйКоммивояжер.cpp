// ЖадныйКоммивояжер.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "GreedyKommivoyajer.h"
#include <iostream>

int main()
{
	size_t countOfCitys(0), startCity(0);
	puts("Enter count of citys :");
	scanf_s("%d", &countOfCitys);
	puts("Enter start city :");
	scanf_s("%d", &startCity);

	try
	{

		GreedyKommivoyajer gk(countOfCitys, startCity),
			obj;
		gk.PrintATableOfRoadVal();
		gk.CalculateMinimalWay();
		std::cout << gk << std::endl;

		//obj = gk;
		//std::cout << obj << std::endl;

	}
	
catch (const bool &i)
{
	if (i)
		puts("Memory leack when creating at array of pointers in tableOfRoadVal");
	else
		puts("Memory leack when creating at array of integer in tableOfRoadVal");
}

catch (...) {

	std::cout << "EROOOORRR";
}

	return 0;
}

