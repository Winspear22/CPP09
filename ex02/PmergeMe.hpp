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
		PmergeMe( /*ARGS*/ );
		~PmergeMe( void );

		void	ProcessVector( char **argv );
		void	ProcessDeque( void );

		std::vector<int> my_vector;
		std::deque<int> my_deque;

	private:
		PmergeMe( const PmergeMe & copy );
		const PmergeMe & operator=( const PmergeMe & rhs );
		
		template <typename Container>
		void _MergeContainers(Container & container, int begin, int middle, int end);

		template <typename Container>
		void _SortContainers(Container & container, int begin, int end);

		template <typename Container>
		void _PrintContainers( Container & container, char **argv );


		timeval _start_timing_vector;
		timeval _start_timing_deque;
		timeval _end_time_vector;
		timeval _end_time_deque;
		double	_duration;
};
#endif