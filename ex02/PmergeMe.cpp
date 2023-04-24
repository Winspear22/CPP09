# include "PmergeMe.hpp"

PmergeMe::PmergeMe(/*ARGS*/)
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
	(void)rhs;
	return (*this);
}

PmergeMe::~PmergeMe( void )
{
	return ;
}