# include "PmergeMe.hpp"

bool	CheckError( char **argv )
{
	int 	i;
	int 	j;
	long	k;
	
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]))
				return (FAILURE);
			j++;
		}
		k = atol(argv[i]);
		if (k < 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int		main( int argc, char **argv )
{
	int i;

	i = 0;
    if (argc < 3)
    {
		std::cerr << RED << "Error" << NORMAL << std::endl;
		return (FAILURE);
	}
	else
	{
		if (CheckError(argv) == FAILURE)
		{
			std::cerr << RED << "Error 2" << NORMAL << std::endl;
			return (FAILURE);
		}
		else
		{
			PmergeMe instance;
			while (i < argc - 1)
			{
				instance.my_vector.push_back(atoi(argv[i]));
				instance.my_deque.push_back(atoi(argv[i]));
				i++;
			}
			instance.vector_it = instance.my_vector.begin();
			instance.deque_it = instance.my_deque.begin();
			/*while (instance.vector_it != instance.my_vector.end())
			{
				std::cout << *instance.vector_it << std::endl;
				instance.vector_it++;
			}
			while (instance.deque_it != instance.my_deque.end())
			{
				std::cout << *instance.deque_it << std::endl;
				instance.deque_it++;
			}*/
		}
	}
    return (SUCCESS);
}