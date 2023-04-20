# include "BitcoinExchange.hpp"


//error: request for member ‘SplitByCharacter’ in ‘btc’, which is of non-class type ‘BitcoinExchange()’
//    btc.SplitByCharacter(line);

int main( int argc, char **argv )
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << RED << "Error. Not enough or too much arguments. You have " \
		<< WHITE << argc - 1 << RED << " arguments, you must have " \
		<< WHITE << "1" << RED << " argument." << NORMAL << std::endl;
		return (FAILURE);
	}

	std::string								tmp;
	std::string 							line;
	std::ifstream 							database("data.csv");
	BitcoinExchange							btc;
	if (database.is_open()) 
	{
        while (getline(database, line)) 
			btc.SplitByCharacter(line);
        database.close();
    } 
	else 
	{
        std::cerr << RED << "Error. Unable to open database " << WHITE << "data.csv" << NORMAL << std::endl;
        return (FAILURE);
    }

	std::ifstream	file(argv[1]);
	if (file.is_open())
	{
		while (getline(file, line))

		file.close();
	}
	else
	{
		std::cerr << RED << "Error. Unable to open file " << WHITE << argv[1] << NORMAL << std::endl;
        return (FAILURE);
	}
	btc._it = btc._database_content.begin();
	while (btc._it != btc._database_content.end())
	{
		std::cout << BLUE << "First == " << WHITE << btc._it->first << NORMAL << std::endl;
		std::cout << GREEN << "Second == " << WHITE << btc._it->second << NORMAL << std::endl;
		btc._it++;
	}
    return (SUCCESS);
}