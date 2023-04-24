# include <iomanip>
# include <iostream>
# include <stack>

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw "Error";

		std::string			token;
		std::stack<int> 	st;
		std::istringstream s(av[1]);

		while (s >> token)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				if (st.size() < 2)
					throw "Error";
				int n2 = st.top();
				st.pop();
				int n1 = st.top();
				st.pop();
				int ret;

				switch (token[0])
				{
    				case '+':
		   	   	 		ret = n1 + n2;
       					break;
		    		case '-':
       					ret = n1 - n2;
		        		break;
    				case '*':
     		   			ret = n1 * n2;
    		   			break;
    				case '/':
        				if (n2 == 0)
            				throw  "Error: Division by zero.";
        				ret = n1 / n2;
        				break;
    				default:
        				throw "Error: Invalid operator.";
				}
				st.push(ret);
			}
			else
			{
				for (int i = 0; token[i] != '\0'; i++)
				{
					 if(token[i] < 48 || token[i] > 57)
        				throw "Error: Invalid input.";
				}
				int num = atoi(token.c_str());
            	st.push(num);
			}
		}
		if (st.size() != 1)
        	throw "Error: Invalid input expression.";
		std::cout << st.top() << std::endl;
    }
 	catch(const char *s)
 	{
 		std::cerr << s << std::endl;
 	}
}