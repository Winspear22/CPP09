# include "RPN.hpp"

RPN::RPN( const std::string & input ): argv_splitted(input), _input_data(input)
{
	return ;
}

RPN::RPN( const RPN & copy )
{
	*this = copy;
	return ;
}

const RPN & 		RPN::operator=( const RPN & rhs )
{
	this->_input_data = rhs._input_data;
//	this->argv_splitted = std::istringstream(_input_data);
	return (*this);
}

RPN::~RPN( void )
{
	return ;
}

std::stack<int>		RPN::GetStack( void ) const
{
	return (this->_stack);
}

void				RPN::SetStack( std::stack<int> src )
{
	this->_stack = src;
}

bool				RPN::IsOperand( const std::string & str ) const
{
	if (str == "+" || str == "-" || str == "/" || str == "*")
		return (SUCCESS);
	return (FAILURE);
}