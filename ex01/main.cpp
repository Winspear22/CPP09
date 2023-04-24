# include "RPN.hpp"

void printStack(std::stack<int> stackCopy) {
    while (!stackCopy.empty()) {
        std::cout << PURPLE << stackCopy.top() << NORMAL << " ";
        stackCopy.pop();
    }
    std::cout << std::endl;
}


/*int main( int argc, char **argv )
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
			instance._number = atoi(token.c_str());
			instance._stack.push(instance._number);
		}
		else
		{
			if (instance.GetStack().size() < 2)
			{
				std::cout << RED << "Error. Not enough elements in the stack" << NORMAL << std::endl;
				return (FAILURE);
			}
			int n2 = instance._stack.top();
			instance._stack.pop();
			int n1 = instance._stack.top();
			instance._stack.pop();
			int ret;

			switch (token[0])
			{*/
				/*case '+':
					ret = n1 + n2;
					break;
				case '-':
					ret = n1 - n2;
					break;
				case '*':
					ret = n1 * n2;
					break;
				case '/':
					if (n2 == 0)
					{
						std::cout << RED << "Error, you divided by zero." << NORMAL << std::endl;
						return (FAILURE);
					}
					ret = n1 / n2;
					break;
				default:
				{
					std::cout << RED << "Error: invalid operator." << NORMAL << std::endl;
					return (FAILURE);
				}*/
			/*	if (token.at(0) == '+')
					ret = n1 + n2;
				else if (token.at(0) == '*')
					ret = n1 * n2;
				else if (token.at(0) == '-')
					ret = n1 - n2;
				else if (token.at(0) == '/')
				{
					if (n2 == 0)
					{
						std::cout << RED << "Error, you divided by zero." << NORMAL << std::endl;
						return (FAILURE);
					}
					else
						ret = n1 / n2;
				}
				else
				{
					std::cout << RED << "Error: invalid operator." << NORMAL << std::endl;
					return (FAILURE);
				}
			}
			instance._stack.push(ret);
			printStack(instance._stack);
		}
	}
	if (instance._stack.size() != 1)
	{
		std::cout << RED << "Invalid input expression" << NORMAL << std::endl;
		return (FAILURE);
	}
	std::cout << instance._stack.top() << std::endl;
	return (SUCCESS);
}
*/
/*$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>*/
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error. Not enough or too much arguments. You have " \
		<< WHITE << argc - 1 << RED << " arguments, you must have " \
		<< WHITE << "1" << RED << " argument." << NORMAL << std::endl;
        return (FAILURE);
    }

    RPN				instance(argv[1]);
	std::string 	str;
	int				i;
    while (instance.argv_splitted >> str)
    {
        if (str.size() == 1) 
		{
			i = 0;
            //OperatorFunction *instance->opFunc = NULL;
			while (i < 4)
			{
                if (str[0] == instance.operatorFunctions[i].op) 
				{
                    instance.opFunc = &instance.operatorFunctions[i];
                    break;
                }
				i++;
            }
            if (instance.opFunc != NULL) 
			{
                if (instance._stack.size() < 2) 
				{
                    std::cerr << "Error: Not enough elements in the stack" << std::endl;
                    return (FAILURE);
                }
                float n2 = instance._stack.top();
                instance._stack.pop();
                float n1 = instance._stack.top();
                instance._stack.pop();
                float ret;
                float status = instance.opFunc->func(n1, n2, ret);
                if (status != 0) 
				{
                    std::cerr << "Error: Division by zero." << std::endl;
                    return (FAILURE);
                }
                instance._stack.push(ret);
                continue;
            }
        }
		else
		{
			for (size_t i = 0; i < str.size(); i++) 
			{
				if (!isdigit(str[i])) 
				{
					std::cerr << "Error: Argument contains something different from a digit or an operand." << std::endl;
					return (FAILURE);
            }
			}
        }
        float num = atol(str.c_str());
        instance._stack.push(num);
    }

    if (instance._stack.size() != 1) 
	{
        std::cerr << "Error: Invalid input expression." << std::endl;
        return (FAILURE);
    }
    std::cout << instance._stack.top() << std::endl;
    return (SUCCESS);
}

