#include <iostream>

int main(int argc, char** argv)
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else
    for (size_t i = 1; argv[i]; i++)
    {
      for (size_t x = 0; x < strlen(argv[i]); x++)
        putchar(toupper(argv[i][x]));
    }
  std::cout << "\n";
  return 0;
}
