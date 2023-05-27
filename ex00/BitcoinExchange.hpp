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
# include <stdlib.h>
# include <unistd.h>
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
# define FIRST_LINE_ERROR 2
# define TOO_EARLY_ERROR 4
# define TOO_LATE_ERROR 5

# define CHARACTER_ERROR 1
# define DATE_ERROR 2
# define AMOUNT_ERROR 3
# define EMPTY_LINE 7
# define DATE_VALUE_ERROR 8

# define VALUE 1
# define DATE 2

# define FIRST_TIME 1
# define SECOND_TIME 0
/*====================================================*/


/*====================================================*/
/*-----------------CLASS BITCOINEXCHANGE--------------*/
/*====================================================*/
class BitcoinExchange
{
	public:
		/*===================================================================================================================*/
		/*--------------------------------------------CONSTRUCTORS AND DESTRUCTOR--------------------------------------------*/
		/*===================================================================================================================*/
														BitcoinExchange(/*ARGS*/);
														~BitcoinExchange( void );
		/*===================================================================================================================*/
		/*------------------------------------------------GETTERS AND SETTERS------------------------------------------------*/
		/*===================================================================================================================*/
		std::map<std::string, float>					GetDatabaseContent( void );
		std::map<std::string, float>::iterator			GetIterator( void );
		std::map<std::string, float>::reverse_iterator	GetReverseIterator( void );
		bool											GetSwitch( void );
		void											SetDatabaseContent( std::string first_element, float second_element );
		void											SetIterator( void );
		void											SetReverseIterator( void );
		void											SetSwitch( bool i );
		/*===================================================================================================================*/
		/*-----------------------------------------------------SPLITTERS-----------------------------------------------------*/
		/*===================================================================================================================*/
		void											SplitByCharacter( std::string input );
		//std::string 									SplitByCharacterForChecking( std::string input, int choice );
		std::string										SplitByCharacterForChecking( std::string input, int choice, const char c );

		/*===================================================================================================================*/
		/*------------------------------------------------CHECKERS AND WRITING-----------------------------------------------*/
		/*===================================================================================================================*/
		int												CheckForErrorsInInput( std::string input );
		void											WriteCorrectOutpout( const std::string &str );
		/*===================================================================================================================*/
		/*---------------------------------------------------ERROR HANDLERS--------------------------------------------------*/
		/*===================================================================================================================*/
		int												ErrorCharacterChecker( const std::string &str );
		void											ErrorMsg( const std::string &str, int error_nb );
		int												ErrorDateFormatChecker( const std::string &str );
		bool											ErrorAmountFormatChecker( const std::string &str );
		bool											isFirstLine;

	private:
		BitcoinExchange( const BitcoinExchange & copy );
		const BitcoinExchange & operator=( const BitcoinExchange & rhs );
		std::map<std::string, float>					_database_content;
		std::map<std::string, float>::iterator			_it;
		std::map<std::string, float>::reverse_iterator	_rit;
		bool											_switch;


};
/*====================================================*/

#endif