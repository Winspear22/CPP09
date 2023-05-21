#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/*====================================================*/
/*----------------------INCLUDES----------------------*/
/*====================================================*/
# include <iomanip>
# include <iostream>
# include <deque>
# include <vector>
# include <stdlib.h>
# include <cstring>
# include <limits>
# include <sys/time.h>
/*====================================================*/

/*====================================================*/
/*--------------------CODES COULEUR-------------------*/
/*====================================================*/
# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define NORMAL "\033[0m"
/*====================================================*/

/*====================================================*/
/*-------------------CODE DE RETURNS------------------*/
/*====================================================*/
# define SUCCESS 0
# define FAILURE 1
/*====================================================*/

/*====================================================*/
/*-------------------CLASS PMERGEME-------------------*/
/*====================================================*/
class PmergeMe
{
	public:
		PmergeMe(/*ARGS*/);
		~PmergeMe( void );

		std::vector<unsigned int> my_vector;
		std::deque<unsigned int> my_deque;

		void	ProcessVector( char **argv );
		void	ProcessDeque( void );

	private:
		PmergeMe( const PmergeMe & copy );
		const PmergeMe & operator=( const PmergeMe & rhs );
		
		template <typename Container>
		void _MergeContainers(Container &vec, int begin, int middle, int end)
		{
			int			i;
			size_t		index_r;
			size_t		index_l;
			Container	firsthalf(vec.begin() + begin, vec.begin() + middle + 1);
			Container	secondhalf(vec.begin() + middle + 1, vec.begin() + end + 1);
			
			i = begin;
			index_r = 0;
			index_l = 0;
			while (i < end + 1)
			{
				if (index_l == secondhalf.size())
				{
					vec[i] = firsthalf[index_r];
					index_r++;
				}
				else if (index_r == firsthalf.size())
				{
					vec[i] = secondhalf[index_l];
					index_l++;
				}
				else if (firsthalf[index_r] > secondhalf[index_l])
				{
					vec[i] = secondhalf[index_l];
					index_l++;
				}
				else
				{
					vec[i] = firsthalf[index_r];
					index_r++;
				}
				i++;

			}
			return;
		}

		template <typename Container>
		void _InsertContainers(Container &vec, int begin, int end)
		{
			typename Container::value_type temp;
			if (vec[begin] > vec[end])
			{
				temp = vec[begin];
				vec[begin] = vec[end];
				vec[end] = temp;
			}
		}

		/*template <typename Container>
		void _SortContainers(Container &vec, int begin, int end)
		{
			int middle;

			middle = (begin + end) / 2;
			if (end - begin <= 2)
				this->_InsertContainers(vec, begin, end);
			else
			{
				
				this->_SortContainers(vec, begin, middle);
				this->_SortContainers(vec, middle + 1, end);
				this->_MergeContainers(vec, begin, middle, end);
			}
		}*/

		template <typename Container>
void _SortContainers(Container &vec, int begin, int end)
{
	int middle;

	if (begin < end) 
	{
		middle = begin + (end - begin) / 2;
		
		this->_SortContainers(vec, begin, middle);
		this->_SortContainers(vec, middle + 1, end);
		this->_MergeContainers(vec, begin, middle, end);
	}
}

		template <typename Container>
		void _PrintContainers( Container &vec, char **argv )
		{
			int								i;
			int								argv_nb;
			typename Container::iterator	it;

			i = 1;
			argv_nb = 1;
			it = vec.begin();
			while (argv[argv_nb])
				argv_nb++;
			if (argv_nb < 6000)
			{
				std::cout << "Before: ";
				while (argv[i] && i < 6000)
				{
					std::cout << argv[i] << " ";
					i++;
				}
			}
			else
			{
				std::cout << "Before: ";
				while (argv[i] && i < 6000)
				{
					std::cout << argv[i] << " ";
					i++;
				}
				std::cout << " [...]";
			}
			std::cout << std::endl;
			if (argv_nb < 6000)
			{
				std::cout << "After: ";
				while (it != vec.end())
				{
					std::cout << *it << " ";
					it++;
				}
			}
			else
			{
				i = 0;
				std::cout << "After: ";
				while (i < 6000)
				{
					std::cout << *it << " ";
					i++;
					it++;
				}
				std::cout << " [...]";
			}
			std::cout << std::endl;
		}


		timeval _start_timing_vector;
		timeval _start_timing_deque;
		timeval _end_time_vector;
		timeval _end_time_deque;
		double	_duration;
};
#endif