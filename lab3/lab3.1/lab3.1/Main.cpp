#include <iostream>
#include <string>
#include "ILoggable.h"
#include "IShuffle.h"
#include "Summator.h"
#include "Subtractor.h"
#include "CustomExpressionEvaluator.h"

int main()
{
	ExpressionEvaluator* ex[3];

	ex[0] = new Summator(3);
	double* ops_sum = new double[3]{ 1.5, 4, 2.5 };
	ex[0]->setOperands(ops_sum, 3);

	ex[1] = new Subtractor(4);
	double* ops_mult = new double[4]{ 10.5, 2.5, -3, 1.5 };
	ex[1]->setOperands(ops_mult, 4);

	ex[2] = new CustomExpressionEvaluator(6);
	double* ops_custom = new double[6]{ 5, 15, -8, 1, 2, 3 };
	for (int i = 0; i < 6; ++i)
		ex[2]->setOperand(i, ops_custom[i]);

	for (int i = 0; i < 3; ++i)
	{
		ex[i]->logToScreen();
		ex[i]->logToFile("Log.txt");
	}

	for (int i = 0; i < 3; ++i)
	{
		IShuffle* is = dynamic_cast<IShuffle*>(ex[i]);
		if (is)
		{
			is->shuffle();
			ex[i]->logToScreen();
		}
	}

	for (int i = 0; i < 3; i++)
		delete ex[i];


	return 0;
}