#include "Subtractor.h"
#include <iostream>

using namespace std;

Subtractor::Subtractor(int n) : ExpressionEvaluator(n) { }

double Subtractor::calculate()
{
	double mult = operands[0];
	for (int i = 1; i < size; i++)
		mult -= operands[i];
	return mult;
}

void Subtractor::logToScreen()
{
	cout << "<Subtractor>" << endl;

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
			cout << "subtract" << " " << operands[i] << " ";
		else
			cout << "subtract" << " " << '(' << operands[i] << ')' << " ";
	}

	cout << "\n" << "Result = " << " " << calculate() << endl << endl;
}

void Subtractor::logToFile(const std::string& filename)
{
	ofstream stream;
	stream.open(filename, ios_base::app);

	stream << "<Subtractor>" << endl;

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
			stream << "subtract" << " " << operands[i] << " ";
		else
			stream << "subtract" << " " << '(' << operands[i] << ')' << " ";
	}

	stream << "\n" << "Result = " << " " << calculate() << endl << endl;

	stream.close();
}


Subtractor::~Subtractor()
{
	//delete[] operands;
}
