# include "RPN.hpp"

float add(float a, float b, float &result)
{
	result = a + b;
	return (SUCCESS);
}
float sub(float a, float b, float &result)
{
	result = a - b;
	return (SUCCESS);
}
float mul(float a, float b, float &result)
{
	result = a * b;
	return (SUCCESS);
}
float div(float a, float b, float &result)
{
	if (b == 0)
        return (FAILURE);
    result = a / b;
    return (SUCCESS);
}


RPN::RPN( const std::string & input ): argv_splitted(input)
{
	this->operatorFunctions[0].op = '+';
    this->operatorFunctions[0].func = add;
    this->operatorFunctions[1].op = '-';
    this->operatorFunctions[1].func = sub;
    this->operatorFunctions[2].op = '*';
    this->operatorFunctions[2].func = mul;
    this->operatorFunctions[3].op = '/';
    this->operatorFunctions[3].func = div;
	this->opFunc = NULL;
	return ;
}

RPN::RPN( const RPN & copy )
{
	*this = copy;
	return ;
}

const RPN & 		RPN::operator=( const RPN & rhs )
{
	int i;
	this->_input_data = rhs._input_data;
	//on ne traite pas std::istrinstream car les constructeurs ne sont pas publics, il n'est donc pas possible de les assigner
	//this->argv_splitted = std::istringstream(_input_data);
    this->_stack = rhs._stack;

	i = 0;
	while (i < 4)
	{
		this->operatorFunctions[i].op = rhs.operatorFunctions[i].op;
        this->operatorFunctions[i].func = rhs.operatorFunctions[i].func;
		i++;
	}
	return (*this);
}

RPN::~RPN( void )
{
	return ;
}

std::stack<float>		RPN::GetStack( void ) const
{
	return (this->_stack);
}

void				RPN::SetStack( std::stack<float> src )
{
	this->_stack = src;
}

bool				RPN::IsOperand( const std::string & str ) const
{
	if (str == "+" || str == "-" || str == "/" || str == "*")
		return (SUCCESS);
	return (FAILURE);
}