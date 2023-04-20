# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/*ARGS*/)
{
	return ;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & copy )
{
	*this = copy;
}

const BitcoinExchange & BitcoinExchange::operator=( const BitcoinExchange & rhs )
{
	(void)rhs;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void )
{
	return ;
}