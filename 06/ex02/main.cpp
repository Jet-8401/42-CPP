#include "Base.hpp"

int	main(void)
{
	Base	base;
	Base*	generated;

	generated = base.generate();
	Base&	ref = *generated;

	base.identify(generated);
	base.identify(ref);

	delete generated;
	return (0);
}
