# include "RPN.hpp"

/*$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error*/

int main(int argc, char **argv)
{
    if (argc != 2)
    {
		std::cerr << RED << "Error" << NORMAL << std::endl;
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
	bool 			OperationPerformed;
    while (instance.argv_splitted >> str)
    {
		OperationPerformed = false;
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
                if (instance.stack.size() < 2) 
				{
                    std::cerr << RED << "Error" << NORMAL << std::endl;
                    return (FAILURE);
                }
                number2 = instance.stack.top();
                instance.stack.pop();
                number1 = instance.stack.top();
                instance.stack.pop();
                IsThereAnError = instance.ptr->fcts(number1, number2, result);
                if (IsThereAnError != NO) 
				{
                    std::cerr << RED << "Error" << NORMAL << std::endl;
                    return (FAILURE);
                }
                instance.stack.push(result);
				OperationPerformed = true;
            }
        }
		if (!OperationPerformed)
        {
            i = 0;
            while (i < str.size())
            {
                if (!isdigit(str[i]))
                {
                    std::cerr << RED << "Error" << NORMAL << std::endl;
                    return (FAILURE);
                }
                i++;
            }
			nbr = atol(str.c_str());
            instance.stack.push(nbr);
        }
    }
    if (instance.stack.size() != 1) 
	{
		std::cerr << RED << "Error" << NORMAL << std::endl;
        return (FAILURE);
    }
    std::cout << instance.stack.top() << std::endl;
    return (SUCCESS);
}

