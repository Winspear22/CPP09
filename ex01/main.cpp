# include "RPN.hpp"

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
        if (str.size() == 1) // Est-ce un opérateur ?
		{
			i = 0;
			instance.ptr = NULL;
			while (i < 4) // Nombre de types d'opération, 4 car : + - * /
			{
                if (str[0] == instance.ptr_to_funct[i].op)  //pointeur sur fonctions pour vérifier quelle opération c'est
				{
                    instance.ptr = &instance.ptr_to_funct[i]; // ptr va contenir l'opération qui va être utilisée
                    break;
                }
				i++;
            }
            if (instance.ptr != NULL) // Si tu as trouvé une opération à faire (+ * - /)
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
		if (!OperationPerformed) // Est-ce un nombre ?
        {
            i = 0;
            while (i < str.size()) // Je vérifie que toute la chaîne est composée de nombre
            {
                if (!isdigit(str[i]))
                {
                    std::cerr << RED << "Error" << NORMAL << std::endl;
                    return (FAILURE);
                }
                i++;
            }
			nbr = atol(str.c_str());
            if (nbr >= 10) // Si le nombre est supérieur ou égal à 10, c'est une erreur
            {
                std::cerr << RED << "Error: Number is not less than " << WHITE << "10" << NORMAL << std::endl;
                return (FAILURE);
            }
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

