#include <cctype>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <stack>
#include <sys/types.h>
#include "RPN.hpp"

static bool is_sign(const char c)
{
	return (c == '+' || c == '-');
}

static bool is_op(const char c)
{
	return (is_sign(c) || c == '/' || c == '*');
}

static void	parsing_error(const char* reason, const char* line, long int index)
{
	std::cerr << "Error: " << reason << "\n" << line << std::endl;
	if (index != -1)
		std::cerr << std::setw(index + 1) << '^' << std::endl;
}

// Throw an error if the expression contain a number or the symbols operation
// don't match those: '+', '-', '*', '/'
static bool	validate(const char* expression, bool& is_number, uint& i)
{
	is_number = std::isdigit(expression[i]);
	if (!is_number && expression[i] && is_sign(expression[i]) && std::isdigit(expression[i + 1]))
	{
		++i;
		is_number = true;
	}
	if (!is_number && !is_op(expression[i]))
		return (parsing_error(ERR_UNEXPECTED_ID, expression, i), 0);
	if (expression[i] && is_number && std::isdigit(expression[i + 1]))
		return (parsing_error(ERR_FIGURES_ONLY, expression, i), 0);
	return (1);
}

float	do_op(float l_value, float r_value, const char c, bool& division_by_zero)
{
	switch (c) {
		case '+':
			return (l_value + r_value);
		case '-':
			return (l_value - r_value);
		case '/':
			if (r_value == 0)
				return (division_by_zero = true, 0);
			return (l_value / r_value);
		case '*':
			return (l_value * r_value);
	}
	return (0);
}

// main function that start to parse the expression.
bool	evaluate_expr(const char* expression)
{
	std::stack<float>	stack;
	bool					is_number = 0;
	bool					division_by_zero = 0;
	float				r_value = 0;
	float				result = 0;

	for (uint i = 0; i < std::strlen(expression); i++) {
		if (std::isspace(expression[i]))
			continue ;
		if (!validate(expression, is_number, i))
			return (0);
		if (is_number) {
			result = static_cast<float>(expression[i] - '0');
			if (i != 0 && expression[i - 1] == '-')
				result = -result;
			stack.push(result);
			continue ;
		}
		if (stack.size() < 2)
			return (parsing_error(ERR_RPN_FORMAT, expression, i), 0);
		r_value = stack.top();
		stack.pop();
		result = do_op(stack.top(), r_value, expression[i], division_by_zero);
		if (division_by_zero)
			return (parsing_error(ERR_DIVISION_BY_ZERO, expression, i), 0);
		stack.pop();
		stack.push(result);
	}
	if (stack.size() != 1)
		return (parsing_error(ERR_MISSING_OPERATOR, expression, -1), 0);
	std::cout << "Result: " << stack.top() << std::endl;
	return (1);
}
