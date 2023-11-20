/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:42:52 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:42:53 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


int	replace(char **argv, std::string infile)
{
	std::ofstream	ofs;
    std::string outfile;
	int				pos;

    outfile = std::string(argv[1]).append(".replace");
	ofs.open(outfile.c_str());
	if (ofs.fail())
		return (1);
	for (int i = 0; i < (int)infile.size(); i++)
	{
		pos = infile.find(argv[2], i);
		if (pos != -1 && pos == i)
		{
			ofs << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			ofs << infile[i];
	}
	ofs.close();
	return (0);
}

int main (int argc, char **argv)
{
  std::ifstream ifs;
  char c;
  std::string infile;

  if (argc != 4)
  {
    std::cout << "usage: replace <file> to_replace replacement" << std::endl;
    return (1);
  }
  ifs.open(argv[1]);
  if (ifs.fail())
  {
		std::cout << "Error: " << argv[1] << ": no such file or directory" << std::endl;
		return (1);
	}
  while(!ifs.eof() && ifs >> std::noskipws >> c)
		infile += c;
	replace(argv, infile);
    ifs.close();
	return (0);

}
