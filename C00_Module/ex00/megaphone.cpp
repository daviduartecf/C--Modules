#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i ++)
		{
			std::string arg = argv[i];
			for (std::size_t j = 0; j < arg.length(); j ++)
				arg[j] = std::toupper(arg[j]);
			std::cout << arg;
			if (i < argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
