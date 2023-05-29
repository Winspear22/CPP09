# include "PmergeMe.hpp"

bool	CheckError( char **argv )
{
	unsigned int 	i;
	unsigned int 	j;
	long			k;
	
	i = 1;
	while (argv[i])
	{
		j = 0;
		if (strlen(argv[i]) == 0)
            return (FAILURE);
		k = atol(argv[i]);
		if (k < 0 || k > std::numeric_limits<unsigned int>::max())
			return (FAILURE);
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}



int main(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc < 3 || argc > 6001)
    {
        std::cerr << RED << "Error" << NORMAL << std::endl;
        return (FAILURE);
    }
    else
    {
        if (CheckError(argv) == FAILURE)
        {
            std::cerr << RED << "Error" << NORMAL << std::endl;
            return (FAILURE);
        }
        else
        {
            PmergeMe instance;
            while (i < argc)
            {
                instance.my_vector.push_back(atoi(argv[i]));
                instance.my_deque.push_back(atoi(argv[i]));
                i++;
            }
			instance.ProcessVector(argv); // on envoie argv pour imprimer les args
			instance.ProcessDeque();
		}
    }
    return (SUCCESS);
}
