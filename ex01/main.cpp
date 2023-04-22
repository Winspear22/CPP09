# include "RPN.hpp"

int main( int argc, char **argv )
{
    (void)argv;
    if (argc != 2)
    {
        std::cerr << RED << "Error. Not enough or too much arguments. You have " \
		<< WHITE << argc - 1 << RED << " arguments, you must have " \
		<< WHITE << "1" << RED << " argument." << NORMAL << std::endl;
        return (FAILURE);
    }
	RPN				instance(argv[1]);
	std::string 	token;
	int				i;
	while (instance.argv_splitted >> token)
	{
		if (instance.IsOperand(token) == FAILURE)
		{
			i = 0;
			while (token[i])
			{
				if (!isdigit(token[i]))
				{
					std::cerr << RED << "Error. Argument contains something different from a digit or an operand." \
					<< WHITE << " Please use only digits ranging between 0-9 and operands + - / or *." << NORMAL \
					<< std::endl;
					return (FAILURE);
				}
				i++;
			}
		}
		else
		{
			std::cout << "Good token" << std::endl;
		}
		std::cout << "toto = " << token << std::endl;
	}
	return (SUCCESS);
}