# include "BitcoinExchange.hpp"

bool IsExecutable(const std::string& filename) 
{
    if (access(filename.c_str(), X_OK) == 0) 
        return (SUCCESS);
	else 
        return (FAILURE);
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
    if(database.is_open()) 
	{
        while(getline(database, line)) 
            btc.SplitByCharacter(line);
        database.close();
    } 
	else
	{
        std::cerr << RED << "Error: could not open database " << WHITE << "data.csv." << NORMAL << std::endl;
        return (FAILURE);
    }

    if (!IsExecutable(argv[1])) 
	{
        std::cerr << RED << "Error: file is not a text file." << NORMAL << std::endl;
        return (FAILURE);
    }

    std::ifstream file(argv[1]);
    if (file.is_open()) 
	{
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
