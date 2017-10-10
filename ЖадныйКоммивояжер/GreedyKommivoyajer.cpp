#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <ostream>
#include <time.h>
#include "GreedyKommivoyajer.h"

void GreedyKommivoyajer::NewSqrMatrix()
{
	srand(time(NULL));
	
		if (countOfCity < 2)
			return;

		if (tableOfRoadVal = new int*[countOfCity])
		{
			for (size_t i(0); i < countOfCity; i++)
				if (!(tableOfRoadVal[i] = new int[countOfCity]))
					throw true;
			MatrixRandValue();
		}
		else
			throw false;
	
}
void GreedyKommivoyajer::MatrixRandValue()
{
	if (tableOfRoadVal)
	{
		for (size_t i(0); i < countOfCity; i++)
			if (tableOfRoadVal[i])
				for (size_t j(0); j < countOfCity; j++)
					if (i == j)
						tableOfRoadVal[i][j] = 0;
					else
						tableOfRoadVal[i][j] = rand() % 100 + 1;

	}
}
void GreedyKommivoyajer::CalculateMinimalWay()
{
	if (countOfCity > 1)
	{
		minWay = 0;
		size_t minVal(0), StrIx(startCityIx - 1), minValStrIx(1);

		for (size_t ix(0); ix < countOfCity; ++ix)
		{
			for (size_t i(0); i < countOfCity; ++i)
				if (tableOfRoadVal[StrIx][i])
				{
					minVal = tableOfRoadVal[StrIx][i];
					minValStrIx = i;
					break;
				}
			for (size_t i(0); i < countOfCity; ++i)
			{
				if (tableOfRoadVal[i] && tableOfRoadVal[StrIx][i] < minVal && tableOfRoadVal[StrIx][i])
				{
					minVal = tableOfRoadVal[StrIx][i];
					minValStrIx = i;
				}
			}
			minWay += minVal;
			for (size_t i(0); i < countOfCity; i++)
				if (tableOfRoadVal[i])
					tableOfRoadVal[i][minValStrIx] = 0;
			if ((ix < countOfCity - 2) && (countOfCity != 2))
			{
				tableOfRoadVal[minValStrIx][StrIx] = 0;
				tableOfRoadVal[minValStrIx][startCityIx - 1] = 0;
			}
			delete[]tableOfRoadVal[StrIx];
			tableOfRoadVal[StrIx] = nullptr;
			StrIx = minValStrIx;
			printf("%d", ix + 1); PrintATableOfRoadVal();
		}
		delete[] tableOfRoadVal;
		tableOfRoadVal = nullptr;
	}
}

void GreedyKommivoyajer::PrintATableOfRoadVal()
{
	if (tableOfRoadVal)
	{
		puts("Table of roads values :");
		for (size_t i(0); i < countOfCity + 1; ++i)
			printf("%d\t", i);
		printf("\n");
		for (int i(0); i < countOfCity; ++i)
		{
			printf("%d", i + 1);
			for (size_t j(0); j < countOfCity; ++j)
			{
				if (tableOfRoadVal[i] && tableOfRoadVal[i][j])
					printf("\t%d", tableOfRoadVal[i][j]);
				else if (tableOfRoadVal[i])
					printf("\t0");
				else
					printf("\t-");
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		puts("Matrix is't created.");
	}
}
void GreedyKommivoyajer::PrintAKommovoyajerObj()
{
	PrintATableOfRoadVal();
	printf("Count of citis : %d\n", countOfCity);
	printf("Start city index : &d\n", startCityIx);
	if (CalcStatus())
		printf("The minimal way : %d\n", minWay);
	else
		puts("A minimal way is't calculated.");
}
std::ostream& operator<<(std::ostream &os, GreedyKommivoyajer &obj)
{
	obj.PrintATableOfRoadVal();
	os << "Count of citis : " << obj.countOfCity << std::endl;
	os << "Start city index : " << obj.startCityIx << std::endl;
	if (obj.CalcStatus())
		os << "The minimal way : " << obj.minWay << std::endl;
	else
		os << "A minimal way is't calculated." << std::endl;
	return os;
}

GreedyKommivoyajer GreedyKommivoyajer::operator=(GreedyKommivoyajer &obj)
{
	if (tableOfRoadVal)
	{
		for (size_t i(0); i < countOfCity; ++i)
			if (tableOfRoadVal[i])
				delete[] tableOfRoadVal[i];
		delete[] tableOfRoadVal;
		tableOfRoadVal = nullptr;
	}
	minWay = obj.minWay;
	countOfCity = obj.countOfCity;
	startCityIx = obj.startCityIx;

	if (obj.tableOfRoadVal)
	{
		NewSqrMatrix();
		for (size_t i(0); i < countOfCity; i++)
		{
			if (obj.tableOfRoadVal[i])
				for (size_t j(0); j < countOfCity; j++)
					if (i == j)
						tableOfRoadVal[i][j] = 0;
					else
						tableOfRoadVal[i][j] = obj.tableOfRoadVal[i][j];
			else
				tableOfRoadVal[i] = nullptr;
		}
	}
	else
		tableOfRoadVal = nullptr;
	return *this;
}

GreedyKommivoyajer::GreedyKommivoyajer(int countOfCity, int startCityIx)
{
	minWay = -1;
	if (countOfCity <= 0 || startCityIx <= 0 || startCityIx > countOfCity)
	{
		tableOfRoadVal = nullptr;
		GreedyKommivoyajer::countOfCity = 0;
		GreedyKommivoyajer::startCityIx = 0;
	}
	else
	{
		GreedyKommivoyajer::countOfCity = countOfCity;
		GreedyKommivoyajer::startCityIx = startCityIx;

		if (countOfCity == 1)
		{
			tableOfRoadVal = nullptr;
			minWay = 0;
		}
		else
		{
			NewSqrMatrix();
			MatrixRandValue();
		}
	}
}
GreedyKommivoyajer::~GreedyKommivoyajer()
{
	if (tableOfRoadVal)
	{
		for (int i(0); i < countOfCity; ++i)
			if (tableOfRoadVal[i])
				delete[] tableOfRoadVal[i];//
		delete[] tableOfRoadVal;
		tableOfRoadVal = nullptr;
	}

}
