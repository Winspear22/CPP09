# include "PmergeMe.hpp"

//PmergeMe::PmergeMe(/*ARGS*/)
/*{
	this->_duration = 0;
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

PmergeMe::~PmergeMe( void )
{
	return ;
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
}*/