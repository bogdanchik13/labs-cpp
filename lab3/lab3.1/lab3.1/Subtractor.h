#pragma once
#include "ExpressionEvaluator.h"
#include <fstream>

class Subtractor : public ExpressionEvaluator
{
public:
	Subtractor(int n);
	double calculate();

	void logToScreen();
	void logToFile(const std::string& filename);

	~Subtractor();
};
