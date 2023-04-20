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

std::map<std::string, float>	BitcoinExchange::GetFileContent( void )
{
	return (this->_database_content);
}

void	BitcoinExchange::SetFileContent( std::map<std::string, float> map )
{
	this->_database_content = map;
}

void BitcoinExchange::SplitByCharacter( std::string input )
{
	size_t comma_pos;
	float second_element;
	std::string first_element;
	std::string second_element_str;
	
	comma_pos = input.find(',');
    if (comma_pos != std::string::npos)
	{
        first_element = input.substr(0, comma_pos);
        second_element_str = input.substr(comma_pos + 1);
		second_element = static_cast<float>(std::strtod(second_element_str.c_str(), NULL));
		this->_database_content.insert(std::make_pair(first_element, second_element));
    }
	return ;
}