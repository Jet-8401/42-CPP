#ifndef RPN_HPP
# define RPN_HPP

# define ERR_UNEXPECTED_ID "Unexpected identifier"
# define ERR_FIGURES_ONLY "Only figures/digit are accepted, not number"
# define ERR_RPN_FORMAT "RPN format not respected"
# define ERR_MISSING_OPERATOR "Missing operator"
# define ERR_DIVISION_BY_ZERO "Division by zero"

bool	evaluate_expr(const char* expresion);

#endif
