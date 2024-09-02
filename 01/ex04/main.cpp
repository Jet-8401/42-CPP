#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

#define ERR_USAGE "Usage: ./sedBis <filename> <s1> <s2>"
#define ERR_OPEN "Cannot open "
#define ERR_S1_EMPTY "Cannot set s1 to an empty string!"

void	search_and_put(std::string &line, std::ofstream &output,
	char *s1, char *s2)
{
	size_t				pos, last_pos, s1_len;

	last_pos = 0;
	s1_len = std::strlen(s1);
	while ((pos = line.find(s1, last_pos)) != std::string::npos)
	{
		// writing the non-modified line to the file without s1
		output << line.substr(last_pos, pos - last_pos);
		// writing s2 to transform s1 to s2 into the string
		output << s2;
		// moving the last position to s1 + s1_len, skipping s1
		last_pos = pos + s1_len;
	}
	// printing the rest of the line if there is no other occurence of s1
	output << line.substr(last_pos) << '\n';
}

void	ft_err(std::string message)
{
	std::cerr << "\x1B[31mError: " << message << "\x1B[0m" << std::endl;
}

int	main(int argc, char *argv[])
{
	std::ifstream	input;
	std::ofstream	output;
	std::string		filename_out;
	std::string		line;

	if (argc != 4)
		return (ft_err(ERR_USAGE), 0);
	if (!*argv[2])
		return (ft_err(ERR_S1_EMPTY), 0);
	input.open(argv[1]);
	if (input.fail())
		return (ft_err(std::string(ERR_OPEN) + argv[1]), 0);
	(filename_out = argv[1]).append(".replace");
	output.open(filename_out.data(), std::ostream::out | std::ostream::trunc);
	if (output.fail())
		return (ft_err(std::string(ERR_OPEN) + filename_out), 0);

	while (std::getline(input, line))
		search_and_put(line, output, argv[2], argv[3]);

	input.close();
	output.close();
	return (0);
}
