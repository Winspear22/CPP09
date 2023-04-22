# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/*ARGS*/)
{
	this->_switch = FIRST_TIME;
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
        this->_it = rhs._it;
		this->_rit = rhs._rit;
        this->_database_content = rhs._database_content;
		this->_switch = rhs._switch;
    }
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void )
{
	return ;
}

std::map<std::string, float>	BitcoinExchange::GetDatabaseContent( void )
{
	return (this->_database_content);
}

std::map<std::string, float>::iterator	BitcoinExchange::GetIterator( void )
{
	return (this->_it);
}
std::map<std::string, float>::reverse_iterator	BitcoinExchange::GetReverseIterator( void )
{
	return (this->_rit);
}

bool		BitcoinExchange::GetSwitch( void )
{
	return (this->_switch);
}

void		BitcoinExchange::SetDatabaseContent( std::string first_element, float second_element )
{
	this->_database_content.insert(std::make_pair(first_element, second_element));
}
void		BitcoinExchange::SetIterator( void )
{
	this->_it = this->_database_content.begin();
}

void		BitcoinExchange::SetReverseIterator( void )
{
	this->_rit = this->_database_content.rbegin();
}

void		BitcoinExchange::SetSwitch( bool i )
{
	this->_switch = i;
}

void BitcoinExchange::SplitByCharacter( std::string input )
{
	size_t comma_pos;
	float second_element;
	std::string first_element;
	std::string second_element_str;
	size_t i;
	
	i = 0;
	while (i < input.size())
    {
        char c = input[i];
        if (c != ',' && c != '-' && !isdigit(c) && c != '\n' && c != '\r' && c != '.')
            return ;
		i++;
    }
	comma_pos = input.find(',');
    if (comma_pos != std::string::npos)
	{
        first_element = input.substr(0, comma_pos);
        second_element_str = input.substr(comma_pos + 1);
		second_element = static_cast<float>(std::strtod(second_element_str.c_str(), NULL));
		this->SetDatabaseContent(first_element, second_element);
    }
	return ;
}

std::string BitcoinExchange::SplitByCharacterForChecking( std::string input, int choice, const char c )
{
	size_t comma_pos;
	std::string element;

	comma_pos = input.find(c);
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

	value_str = this->SplitByCharacterForChecking(str, VALUE, '|');
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

int BitcoinExchange::ErrorCharacterChecker( const std::string &str )
{
	size_t	i;
	int		pipe_count;
	int		middle_score_count;
	
	i = 0;
	pipe_count = 0;
	middle_score_count = 0;
	if (str == "date | value\r" && this->_switch == FIRST_TIME)
	{
		this->SetSwitch(SECOND_TIME);
		return (FIRST_LINE_ERROR);
	}
	/*VERIFIE LA PRESENCE DE LETTRES OU CARACTERES INTERDITS*/
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
		if (c == '-')
			middle_score_count++;
		i++;
    }
	/*VERIFIE QU'IL YA BIEN AU MOINS UN PIPE ET QUE CE PIPE EST ' | '*/
	if (str.find(" | ") == std::string::npos || pipe_count > 1) 
        return (FAILURE);
	/*VERIFIE QU'ON NE PUISSE PAS ENCHAINER LES - COMME CA -----15*/
	if (middle_score_count > 3)
		return (FAILURE);

	/*VERIFIE QU'IL Y'A BIEN UN CHIFFRE APRES LE PIPE*/
	size_t 		last_pipe_pos = str.find_last_of('|');
	std::string after_pipe = str.substr(last_pipe_pos + 1);
    if (last_pipe_pos == std::string::npos || last_pipe_pos + 1 >= str.size())
        return (FAILURE);
    if (after_pipe.find_first_not_of(" ") == std::string::npos || !isdigit(after_pipe[after_pipe.find_first_not_of(" -")]))
		return (FAILURE);
	
	/*VERIFIE LE CAS OU ON FAIT 15 14*/
	std::string value_str = this->SplitByCharacterForChecking(str, VALUE, '|');
	size_t 		j = value_str.find_first_of("0123456789");
	while (value_str[j])
	{
		if (!isdigit(value_str[j]) && value_str[j] != '.')
			break ;
		j++;
	}
	size_t k = j;
	while (value_str[k])
    {
        if (!isspace(value_str[k]))
            return (FAILURE);
        k++;
    }
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
	full_date = this->SplitByCharacterForChecking(str, DATE, '|');
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

bool BitcoinExchange::CheckForErrorsInInput( std::string input )
{
	if (this->ErrorCharacterChecker(input) == FIRST_LINE_ERROR)
		return (FAILURE);
	if (this->ErrorCharacterChecker(input) == FAILURE)
	{
		ErrorMsg(input, CHARACTER_ERROR);
		return (FAILURE);
	}
	if (this->ErrorDateFormatChecker(input) == FAILURE)
	{
		ErrorMsg(input, DATE_ERROR);
		return (FAILURE);
	}
	if (this->ErrorAmountFormatChecker(input) == FAILURE)
	{
		ErrorMsg(input, AMOUNT_ERROR);
		return (FAILURE);
	}
	return (SUCCESS);
}

void BitcoinExchange::WriteCorrectOutpout( const std::string &str )
{
	std::string		value_str;
	std::string		date_str;
	std::string		closest_date;
	float			value;

	this->SetIterator();
	value_str = this->SplitByCharacterForChecking(str, VALUE, '|');
	date_str = this->SplitByCharacterForChecking(str, DATE, '|');
	value = std::atof(value_str.c_str());
	while (this->_it != this->_database_content.end())
	{
		if (date_str == this->_it->first)
		{
			std::cout << BLUE << this->_it->first << " => " << WHITE << value << " = " << YELLOW << this->_it->second * value << std::endl;
			return ;
		}
		this->_it++;
	}
	this->SetReverseIterator();
	while (this->_rit != this->_database_content.rend())
	{
		if (this->_rit->first < str)
		{
			std::cout << CYAN << date_str << " => " << WHITE << value << " = " << YELLOW << this->_rit->second * value << std::endl;
			return ;
		}
		this->_rit++;
	}
	return ;
}


