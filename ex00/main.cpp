# include "BitcoinExchange.hpp"

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
	std::map<std::string, float>			file_content;
	std::map<std::string, float>::iterator	it;
	std::string								tmp;
	std::string 							line;
	std::ifstream 							file(argv[1]);
	
	if (file.is_open()) 
	{
        while (getline(file, line)) 
            tmp += line + "\n";
        file.close();
    } 
	else 
	{
        std::cerr << RED << "Error. Unable to open file " << WHITE << argv[1] << NORMAL << std::endl;
        return (FAILURE);
    }
    return (SUCCESS);
}