# include "PmergeMe.hpp"


PmergeMe::PmergeMe(/*ARGS*/)
{
	this->_duration = 0;
	return ;
}

PmergeMe::~PmergeMe( void )
{
	return ;
}

PmergeMe::PmergeMe( const PmergeMe & copy )
{
	*this = copy;
	return ;
}

const PmergeMe & PmergeMe::operator=( const PmergeMe & rhs )
{
	if (this != &rhs)
	{
		this->_duration = rhs._duration;
		this->my_deque = rhs.my_deque;
		this->my_vector = rhs.my_vector;
		this->_start_timing_vector = rhs._start_timing_vector;
		this->_start_timing_deque = rhs._start_timing_deque;
		this->_end_time_vector = rhs._end_time_vector;
		this->_end_time_deque = rhs._end_time_deque;
		this->_duration = rhs._duration;
	}
	return (*this);
}

void	PmergeMe::ProcessVector( char **argv )
{
	gettimeofday(&this->_start_timing_vector, NULL);
	this->_SortContainers(this->my_vector, 0, this->my_vector.size() - 1);
	gettimeofday(&this->_end_time_vector, NULL);
	this->_duration = (this->_end_time_vector.tv_sec - this->_start_timing_vector.tv_sec) + (this->_end_time_vector.tv_usec - this->_start_timing_vector.tv_usec) / 1000000.0;;
	this->_PrintContainers(this->my_vector, argv);
	std::cout << WHITE << "Time to process a range of " << YELLOW << this->my_vector.size() << " elements " << WHITE << "with std::" << YELLOW << "vector" << NORMAL << " : " << YELLOW << this->_duration << " sec(s)" << NORMAL << std::endl;

	return ;
}

void	PmergeMe::ProcessDeque( void )
{
	gettimeofday(&this->_start_timing_deque, NULL);
	this->_SortContainers(this->my_deque, 0, this->my_deque.size() - 1);
	gettimeofday(&this->_end_time_deque, NULL);
	this->_duration = (this->_end_time_deque.tv_sec - this->_start_timing_deque.tv_sec) + (this->_end_time_deque.tv_usec - this->_start_timing_deque.tv_usec) / 1000000.0;;
	std::cout << WHITE << "Time to process a range of " << PURPLE << this->my_deque.size() << " elements " << WHITE << "with std::" << PURPLE << "deque" << NORMAL << " : " << PURPLE << this->_duration << " sec(s)" << NORMAL << std::endl;
	
	return ;
}


template <typename Container>
void PmergeMe::_MergeContainers(Container & container, int begin, int middle, int end)
{
	int			i;
	size_t		index_l;
	size_t		index_r;
	Container	firsthalf(container.begin() + begin, container.begin() + middle + 1);
	Container	secondhalf(container.begin() + middle + 1, container.begin() + end + 1);
	
	i = begin;
	index_l = 0;
	index_r = 0;
	while (i < end + 1)
	{
		if (index_r == secondhalf.size()) // Si la seconde moitiée est remplie, alors on ne peut que remplir la première
		{
			container[i] = firsthalf[index_l];
			index_l++;
		}
		else if (index_l == firsthalf.size()) // Si la première moitié est remplie, alors on ne peut que remplir la première
		{
			container[i] = secondhalf[index_r];
			index_r++;
		}
		else if (firsthalf[index_l] > secondhalf[index_r]) // Si le chiffre compris dans la première moitié est plus grand que celui de la seconde
		{
			container[i] = secondhalf[index_r]; // Alors c'est celui de la seconde moitié qui doit être merge
			index_r++;
		}
		else
		{
			container[i] = firsthalf[index_l]; // Si c'est l'inverse, alors ça doit être celui de la première moitié
			index_l++;
		}
		i++;
	}
	return;
}

template <typename Container>
void PmergeMe::_SortContainers(Container & container, int begin, int end)
{
	int middle;

	if (begin < end) // peut s'xpliquer par tant qu'il y'a plus d'un élément dans le tableau. Ce if sert à arrêter la récursivité
	{
		middle = begin + (end - begin) / 2;

		this->_SortContainers(container, begin, middle);
		this->_SortContainers(container, middle + 1, end);
		this->_MergeContainers(container, begin, middle, end);
	}
}

template <typename Container>
void PmergeMe::_PrintContainers( Container & container, char **argv )
{
	int	i;
	int	argv_nb;
	typename Container::iterator	it;

	i = 1;
	argv_nb = 1;
	it = container.begin();
	while (argv[argv_nb])
		argv_nb++;
	if (argv_nb < 8)
	{
		std::cout << CYAN << "Before: " << NORMAL;
		while (argv[i] && i < 8)
		{
			std::cout << argv[i] << " ";
			i++;
		}
	}
	else
	{
		std::cout << CYAN << "Before: " << NORMAL;
		while (argv[i] && i < 8)
		{
			std::cout << argv[i] << " ";
			i++;
		}
		std::cout << " [...]";
	}
	std::cout << std::endl;
	if (argv_nb < 8)
	{
		std::cout << GREEN << "After: " << NORMAL;
		while (it != container.end())
		{
			std::cout << *it << " ";
			it++;
		}
	}
	else
	{
		i = 0;
		std::cout << GREEN << "After: " << NORMAL;
		while (i < 8)
		{
			std::cout << *it << " ";
			i++;
			it++;
		}
		std::cout << " [...]";
	}
	std::cout << std::endl;
}