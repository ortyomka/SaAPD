#include <iostream>
#include <string>
#include "Expression.h"

double Calculate(const std::string &expression)
{
	Expression *pExpression = CreateExpression(expression);
	const double result = CalculateExpression(pExpression);
	DisposeExpression(pExpression);

	return result;
}

void PrintExpressionResult(const std::string &expression)
{
	try
	{
		const double result = Calculate(expression);
		std::cout << "'" << expression << "' = " << result << std::endl;
	}
	catch (const std::exception &ex)
	{
		std::cerr << "Error in '" << expression << "': " << ex.what() << std::endl;
	}
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	PrintExpressionResult("1.2");
	PrintExpressionResult("404");
	PrintExpressionResult("   404  ");
	PrintExpressionResult("3 * 3 * 3");
	PrintExpressionResult("12 / 12 / 12");
	PrintExpressionResult("25 + 17 / 45 / 2");
	PrintExpressionResult("42 + 42 / 2 * 2");
	PrintExpressionResult(" 4 * 4 + 3 * 3 + 2 * 2 ");
	PrintExpressionResult(" + 2 - - 2 - 4");
	PrintExpressionResult("-(2 - 3) * 2");
	PrintExpressionResult("(4 * 6 - 7) * 3 - 9 * (5 - (6 + 3))");
	PrintExpressionResult("(4.2 * 6 - 7.2) * 3.45 - 9.0005 * (5.1 - (6 + 3))");

	return 0;
}
