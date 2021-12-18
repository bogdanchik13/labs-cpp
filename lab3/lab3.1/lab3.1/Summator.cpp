#include "Summator.h"
#include <iostream>

using namespace std;

Summator::Summator(int n) : ExpressionEvaluator(n) { }

double Summator::calculate()
{
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += operands[i];
	return sum;
}

void Summator::logToScreen()
{
	cout << "<Summator>" << endl;
	for (int i = 0; i < size; i++)
	{
		if (operands[i] >= 0)
		{
			cout << operands[i] << " ";
		}
		else
		{
			cout << '(' << operands[i] << ')' << " ";
		}
	}

	operands[0] >= 0 ? cout << "\n " << operands[0] << " " : cout << "\n" << '(' << operands[0] << ')' << " ";

	for (int i = 1; i < size; i++)
	{
		if (operands[i] >= 0)
			cout << "plus" << " " << operands[i] << " ";
		else
			cout << "plus" << " " << '(' << operands[i] << ')' << " ";
	}

	cout << "\n" << "Result = " << " " << calculate() << endl << endl;
}

void Summator::logToFile(const std::string& filename)
{
	ofstream stream;
	stream.open(filename, ios_base::app);

	stream << "<Summator>" << endl;
	for (int i = 0; i < size; i++)
	{
		if (operands[i] >= 0)
		{
			stream << operands[i] << " ";
		}
		else
		{
			stream << '(' << operands[i] << ')' << " ";
		}
	}

	operands[0] >= 0 ? stream << "\n " << operands[0] << " " : stream << "\n" << '(' << operands[0] << ')' << " ";

	for (int i = 1; i < size; i++)
	{
		if (operands[i] >= 0)
			stream << "plus" << " " << operands[i] << " ";
		else
			stream << "plus" << " " << '(' << operands[i] << ')' << " ";
	}

	stream << "\n" << "Result = " << " " << calculate() << endl << endl;

	stream.close();
}


Summator::~Summator()
{
	//delete[] operands;
}
