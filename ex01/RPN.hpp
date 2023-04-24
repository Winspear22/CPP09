#ifndef RPN_HPP
# define RPN_HPP

/*====================================================*/
/*----------------------INCLUDES----------------------*/
/*====================================================*/
# include <iomanip>
# include <iostream>
# include <stack>
# include <stdio.h>
# include <fstream>
# include <sstream>
# include <stdlib.h>
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

struct OperatorFunction 
{
    char op;
    float (*func)(float, float, float&);
	
};

float add(float a, float b, float &result);
float sub(float a, float b, float &result);
float mul(float a, float b, float &result);
float divi(float a, float b, float &result);

/*====================================================*/
/*----------------------CLASS RPN---------------------*/
/*====================================================*/
class RPN
{
    public:
		/*===================================================================================================================*/
		/*--------------------------------------------CONSTRUCTORS AND DESTRUCTOR--------------------------------------------*/
		/*===================================================================================================================*/
							RPN( const std::string & input );
							const RPN & operator=( const RPN & rhs );
							~RPN( void );
		/*===================================================================================================================*/
		/*------------------------------------------------GETTERS AND SETTERS------------------------------------------------*/
		/*===================================================================================================================*/
		std::stack<float>				GetStack( void ) const;
		void							SetStack( std::stack<float> src );
		bool							IsOperand( const std::string & str ) const;
		
		std::stack<float>		_stack;
		std::istringstream	argv_splitted;
		OperatorFunction operatorFunctions[4];
		OperatorFunction opFunc;

    private:
		RPN( const RPN & copy );
		std::string			_input_data;
};
/*====================================================*/
#endif