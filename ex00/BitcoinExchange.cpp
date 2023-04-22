# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/*ARGS*/)
{
	this->_switch = false;
	return ;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & copy )
{
	*this = copy;
}

const BitcoinExchange & BitcoinExchange::operator=( const BitcoinExchange & rhs )
{
    if (this != &rhs)
    {
        this->_switch = rhs._switch;
        this->_it = rhs._it;
        this->_database_content = rhs._database_content;
    }
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

/*std::string BitcoinExchange::SplitByCharacterForChecking( std::string input )
{
	size_t comma_pos;
	std::string first_element;

	comma_pos = input.find('|');
    if (comma_pos != std::string::npos)
		first_element = input.substr(0, comma_pos - 1);
	return (first_element);
}*/

std::string BitcoinExchange::SplitByCharacterForChecking( std::string input, int choice )
{
	size_t comma_pos;
	std::string element;

	comma_pos = input.find('|');
	if (choice == DATE)
	{
		if (comma_pos != std::string::npos)
			element = input.substr(0, comma_pos - 1);
	}
	else if (choice == VALUE)
	{
		if (comma_pos != std::string::npos)
			element = input.substr(comma_pos + 1);
	}
	return (element);
}


void BitcoinExchange::ErrorMsg( const std::string &str, int error_nb )
{
	if (error_nb == CHARACTER_ERROR)
		std::cout << RED << "Error: bad input => " << WHITE << str << NORMAL << std::endl;
	if (error_nb == DATE_ERROR)
		std::cout << RED << "Error: bad input => " << WHITE << str << NORMAL << std::endl;
	if (error_nb)
	return ;
}

bool BitcoinExchange::ErrorAmountFormatChecker( const std::string &str )
{
	std::string value_str;
	long long	value;
	if (str == "date | value\r" && this->_switch == false)
	{
		this->_switch = true;
		return (SUCCESS);
	}
	value_str = this->SplitByCharacterForChecking(str, VALUE);
	value = std::atol(value_str.c_str());
	if (value > std::numeric_limits<int>::max())
	{
		std::cout << RED << "Error: " << WHITE << "too large a number." << NORMAL << std::endl; 
		return (FAILURE);
	}
	if (value < 0)
	{
		std::cout << RED << "Error: " << WHITE << "not a positive number." << NORMAL << std::endl;
		return (FAILURE);
	}
	return (SUCCESS);
}

bool BitcoinExchange::ErrorCharacterChecker( const std::string &str )
{
	size_t	i;
	int		pipe_count;
	
	i = 0;
	pipe_count = 0;
	if (str == "date | value\r" && this->_switch == false)
		return (SUCCESS);
	i = 0;
    while (i < str.size())
    {
        char c = str[i];
        if (isalpha(c))
            return (FAILURE);
        if (isspace(c) && c != ' ' && c != '\n' && c != 13)
            return (FAILURE);
        if (!isdigit(c) && !isspace(c) && c != '-' && c != '.' && c != '|')
            return (FAILURE);
		if (c == '|')
            pipe_count++;
		i++;
    }
	if (str.find(" | ") == std::string::npos || pipe_count > 1) 
        return FAILURE;
    return (SUCCESS);
}

bool BitcoinExchange::ErrorDateFormatChecker( const std::string &str )
{
	std::string full_date;
	std::string year_str;
    std::string month_str;
    std::string day_str;
	
	int year;
    int month;
    int day;
	if (str == "date | value\r" && this->_switch == false)
		return (SUCCESS);
	full_date = this->SplitByCharacterForChecking(str, DATE);
	if (full_date.size() != 10 || full_date[4] != '-' || full_date[7] != '-')
        return (FAILURE);
	year_str = full_date.substr(0, 4);
	month_str = full_date.substr(5, 2);
	day_str = full_date.substr(8, 2);
	
	year = std::atoi(year_str.c_str());
	month = std::atoi(month_str.c_str());
	day = std::atoi(day_str.c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return (FAILURE);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (FAILURE);
    /*if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) 
	{
        if (day > 29)
            return (FAILURE);
    } 
	else if (month == 2 && day > 28) 
        return (FAILURE);*/
    return (SUCCESS);
}

void BitcoinExchange::CompareFileWithDatabase( std::string input )
{
	if (this->ErrorCharacterChecker(input) == FAILURE)
		return (ErrorMsg(input, CHARACTER_ERROR));
	if (this->ErrorDateFormatChecker(input) == FAILURE)
		return (ErrorMsg(input, DATE_ERROR));
	if (this->ErrorAmountFormatChecker(input) == FAILURE)
		return (ErrorMsg(input, AMOUNT_ERROR));
	return ;
}