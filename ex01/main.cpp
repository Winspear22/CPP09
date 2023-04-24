# include "RPN.hpp"

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
	size_t			i;
	float			number1;
	float 			number2;
	float			result;
	float			IsThereAnError;
	float			nbr;
    while (instance.argv_splitted >> str)
    {
		bool operationPerformed = false;
        if (str.size() == 1) 
		{
			i = 0;
			instance.ptr = NULL;
			while (i < 4)
			{
                if (str[0] == instance.ptr_to_funct[i].op) 
				{
                    instance.ptr = &instance.ptr_to_funct[i];
                    break;
                }
				i++;
            }
            if (instance.ptr != NULL) 
			{
                if (instance._stack.size() < 2) 
				{
                    std::cerr << "Error: Not enough elements in the stack" << std::endl;
                    return (FAILURE);
                }
                number2 = instance._stack.top();
                instance._stack.pop();
                number1 = instance._stack.top();
                instance._stack.pop();
                IsThereAnError = instance.ptr->func(number1, number2, result);
                if (IsThereAnError != NO) 
				{
                    std::cerr << "Error: Division by zero." << std::endl;
                    return (FAILURE);
                }
                instance._stack.push(result);
				operationPerformed = true;
            }
        }
		if (!operationPerformed)
        {
            i = 0;
            while (i < str.size())
            {
                if (!isdigit(str[i]))
                {
                    std::cerr << "Error: Argument contains something different from a digit or an operand." << std::endl;
                    return (FAILURE);
                }
                i++;
            }
			nbr = atol(str.c_str());
            instance._stack.push(nbr);
        }
    }
    if (instance._stack.size() != 1) 
	{
        std::cerr << "Error: Invalid input expression." << std::endl;
        return (FAILURE);
    }
    std::cout << instance._stack.top() << std::endl;
    return (SUCCESS);
}

