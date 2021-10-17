/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** main
*/

#include <iostream>
#include <string>
#include <fstream>

class file
{
    public:
        std::fstream file;
        char line[100];
        int nread = 0;
};

static void process_read(file *file)
{
    while ((file->nread = file->file.readsome(file->line, 100)) != 0)
        std::cout.write(file->line, file->nread);
    file->file.close();
}

int my_cat(const int ac, const char * const *av)
{
    file file;

    if (1 == ac) {
        std::cerr << "my_cat: Usage: " << *av << " file [...]" << std::endl;
        return (0);
    }
    for (int i = 1; ac > i; i++) {
        file.file.open(av[i], std::ios::in);
        if (file.file)
            process_read(&file);
        else
            std::cerr << "my_cat: " << *(av + 1) << ": No such file or directory" << std::endl;
    }
    return (0);
}

int main(int ac, const char * const *av)
{
    return (my_cat(ac, av));
}