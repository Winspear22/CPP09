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
# include <string.h>

# include <cstdlib>
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
# define IS_NOT_A_NUMBER 0
# define IS_A_NUMBER 1
# define IS_NOT_PRINTABLE 0

# define CHARACTER_ERROR 1
# define DATE_ERROR 2
# define AMOUNT_ERROR 3
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

		std::map<std::string, float>		GetFileContent( void );
		void								SetFileContent( std::map<std::string, float> map );
		bool								GetSwitch( void );

		void								SplitByCharacter( std::string input );
		std::string 						SplitByCharacterForChecking( std::string input );

		void								CompareFileWithDatabase( std::string input );
		
		bool								ErrorCharacterChecker( const std::string &str );
		void								ErrorMsg( const std::string &str, int error_nb );
		bool								ErrorDateFormatChecker( const std::string &str );
		bool								ErrorAmountFormatChecker( const std::string &str );


		std::map<std::string, float>			_database_content;
		std::map<std::string, float>::iterator	_it;

	private:
		bool									_switch;


};
/*====================================================*/

#endif