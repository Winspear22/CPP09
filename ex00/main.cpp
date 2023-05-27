# include "BitcoinExchange.hpp"

bool IsTextFile(const std::string& filename) 
{
    std::ifstream file(filename.c_str(), std::ios::binary);
    
    if (!file)
        return false;
    
    char c;
    size_t count = 0;

    while (file.get(c) && count++ < 512) 
    {
        if (!std::isprint(c) && !std::isspace(c))
            return false;
    }

    if (access(filename.c_str(), X_OK) == 0) 
        return (SUCCESS);
	else 
        return (FAILURE);
    return true;
}


int main(int argc, char **argv) 
{
    if (argc != 2) 
	{
        std::cerr << RED << "Error. Not enough or too much arguments. You have " 
        << WHITE << argc - 1 << RED << " arguments, you must have " 
        << WHITE << "1" << RED << " argument." << NORMAL << std::endl;
        return (FAILURE);
    }

    std::string tmp;
    std::string line;
    std::ifstream database("data.csv");
    BitcoinExchange btc;
    if (!IsTextFile(argv[1])) 
    {
        std::cerr << RED << "Error: " << WHITE << argv[1] << RED <<" is not a text file." << NORMAL << std::endl;
        return (FAILURE);
    }
    if (database.is_open()) 
	{
        if (database.peek() == EOF)
        {
            std::cout << RED << "Error:" << WHITE " data.csv " << RED << "is empty." << NORMAL << std::endl;
            return (FAILURE); 
        }
        while(getline(database, line)) 
            btc.SplitByCharacter(line);
        database.close();
    } 
	else
	{
        std::cerr << RED << "Error: could not open database " << WHITE << "data.csv." << NORMAL << std::endl;
        return (FAILURE);
    }

    std::ifstream file(argv[1]);
    if (file.is_open()) 
	{
        if (file.peek() == EOF)
        {
            std::cout << RED << "Error " << WHITE << argv[1] << RED << " is empty." << NORMAL << std::endl;
            return (FAILURE); 
        }
        while(getline(file, line)) 
		{
            if(btc.CheckForErrorsInInput(line) == SUCCESS)
                btc.WriteCorrectOutpout(line);
        }
        file.close();
    } 
	else 
	{
        std::cerr << RED << "Error: could not open file." << NORMAL << std::endl;
        return (FAILURE);
    }
    return (SUCCESS);
}
