#pragma once
#ifndef _GREEDYKOMMIVOYAJER_H_
#define _GREEDYKOMMIVOYAJER_H_

class GreedyKommivoyajer
{
private:
	int **tableOfRoadVal, minWay;
	size_t countOfCity, startCityIx;
	void NewSqrMatrix();
	void MatrixRandValue();
public:
	bool CalcStatus()
	{
		return minWay != -1;
	}
	int ReturnAMinimalWay()
	{
		return minWay;
	}
	void CalculateMinimalWay();

	void PrintATableOfRoadVal();
	void PrintAKommovoyajerObj();
	friend std::ostream& operator<<(std::ostream &os, GreedyKommivoyajer &obj);

	GreedyKommivoyajer operator=(GreedyKommivoyajer &gk);


	GreedyKommivoyajer(int countOfCity = 0, int startCityIx = 0);
	~GreedyKommivoyajer();
};
#endif // !_GREEDYKOMMIVOYAJER_H_

