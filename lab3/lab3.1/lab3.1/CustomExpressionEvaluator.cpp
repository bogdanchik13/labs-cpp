#include "CustomExpressionEvaluator.h"
#include <iostream>

using namespace std;

CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) {}

double CustomExpressionEvaluator::calculate()
{
	double res = 0;
	double temp = (operands[0] + operands[1]) / 2;
	for (int i = 2; i < size; i++)
		res += operands[i];
	return temp + res;
}

void CustomExpressionEvaluator::logToScreen()
{
	cout << "<CustomExpressionEvaluator>" << endl;

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

	if (operands[0] >= 0 && operands[1] >= 0)
		cout << "\n" << '(' << operands[0] << " " << "plus " << operands[1] << ')' << " " << "divide " << "2" << " ";

	if (operands[0] >= 0 && operands[1] <= 0)
		cout << "\n" << '(' << operands[0] << " " << "plus " << '(' << operands[1] << ')' << ')' << " " << "divide " << "2" << " ";

	if (operands[0] <= 0 && operands[1] >= 0)
		cout << "\n" << '(' << '(' << operands[0] << " " << ')' << "plus" << operands[1] << ')' << " " << "divide " << "2 " << " ";

	if (operands[0] <= 0 && operands[1] <= 0)
		cout << "\n" << '(' << '(' << operands[0] << " " << ')' << "plus " << '(' << operands[1] << ')' << ')' << " " << "divide " << "2" << " ";

	for (int i = 2; i < size; i++)
	{
		if (operands[i] >= 0)
			cout << "plus" << " " << operands[i] << " ";
		else
			cout << "plus" << " " << '(' << operands[i] << ')' << " ";
	}

	cout << "\n" << "Result = " << " " << calculate() << endl << endl;

}

void CustomExpressionEvaluator::logToFile(const std::string& filename)
{
	ofstream stream;
	stream.open(filename, ios_base::app);

	stream << "<CustomExpressionEvaluator>" << endl;

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

	if (operands[0] >= 0 && operands[1] >= 0)
		stream << "\n" << '(' << operands[0] << " " << "plus " << operands[1] << ')' << " " << "divide " << "2" << " ";

	if (operands[0] >= 0 && operands[1] <= 0)
		stream << "\n" << '(' << operands[0] << " " << "plus " << '(' << operands[1] << ')' << ')' << " " << "divide " << "2" << " ";

	if (operands[0] <= 0 && operands[1] >= 0)
		stream << "\n" << '(' << '(' << operands[0] << " " << ')' << "plus" << operands[1] << ')' << " " << "divide " << "2 " << " ";

	if (operands[0] <= 0 && operands[1] <= 0)
		stream << "\n" << '(' << '(' << operands[0] << " " << ')' << "plus " << '(' << operands[1] << ')' << ')' << " " << "divide " << "2" << " ";

	for (int i = 2; i < size; i++)
	{
		if (operands[i] >= 0)
			stream << "plus" << " " << operands[i] << " ";
		else
			stream << "plus " << " " << '(' << operands[i] << ')' << " ";
	}

	stream << "\n" << "Result = " << " " << calculate() << endl << endl;

	stream.close();
}



void CustomExpressionEvaluator::shuffle()
{
	for (int i = 0; i < size; i++)
	{
		if (operands[i] > 0)
		{
			int min = i;
			for (int j = i + 1; j < size; j++)
			{
				if (operands[j] > 0 && operands[j] < operands[min])
					min = j;
			}
			if (min != i) swap(operands[i], operands[min]);
		}
	}
}





void CustomExpressionEvaluator::shuffle(size_t left, size_t right)
{
	double tmp;
	tmp = operands[left];
	operands[left] = operands[right];
	operands[right] = tmp;
}

CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
	//delete[] operands;
}
