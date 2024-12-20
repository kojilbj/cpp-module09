#include <string>
#include <iostream>
#include <fstream>

void	replace(std::string& str, const std::string s1, const std::string s2)
{
	size_t	pos;

	pos = str.find(s1);
	while (pos != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos = str.find(s1);
	}
}

int	main(int ac, char *av[])
{
	std::string		buff;
	std::string		infile_name;
	std::string		outfile_name;
	std::fstream	infile;
	std::fstream	outfile;

	if (ac != 4)
	{
		std::cout << "arguements: ./replace filename s1 s2" << std::endl;
		return (1);
	}
	infile_name = av[1];
	infile.open(infile_name, std::fstream::in);
	if (!infile.is_open())
	{
		std::cerr << "Error Infile open" << std::endl;
		infile.close();
		return (1);
	}
	outfile_name = infile_name + ".replace";
	outfile.open(outfile_name, std::fstream::out);
	if (!outfile.is_open())
	{
		std::cerr << "Error Outfile open" << std::endl;
		infile.close();
		outfile.close();
		return (1);
	}
	while (std::getline(infile, buff))
	{
		replace(buff, av[2], av[3]);
		outfile << buff << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}