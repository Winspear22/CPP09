#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

/*====================================================*/
/*----------------------INCLUDES----------------------*/
/*====================================================*/
# include <iomanip>
# include <iostream>
# include <map>
# include <stdio.h>
# include <fstream>
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
/*-----------------CLASS BITCOINEXCHANGE--------------*/
/*====================================================*/
class BitcoinExchange
{
	public:
		BitcoinExchange(/*ARGS*/);
		BitcoinExchange( const BitcoinExchange & copy );
		const BitcoinExchange & operator=( const BitcoinExchange & rhs );
		~BitcoinExchange( void );


	private:

};
/*====================================================*/

#endif