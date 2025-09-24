
#include "fileSystem.h"
#include <iostream>
#include <sstream>

int main() {
    FileSystem fs;
    std::string line, cmd, arg, data;

    std::cout << "welcome to inode-lab, type 'exit' to quit.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> cmd;

        if (cmd == "exit") break;
            else if (cmd == "mkdir") { iss >> arg; fs.mkdir(arg); }
            else if (cmd == "ls") fs.ls();
            else if (cmd == "cd") { iss >> arg; fs.cd(arg); }
            else if (cmd == "create") { iss >> arg; fs.create(arg); }
            else if (cmd == "write") {
                iss >> arg;
                std::getline(iss, data);
                    if (!data.empty() && data[0] == ' ') data.erase(0, 1);
                        fs.write(arg, data);
            }
            else if (cmd == "read") { iss >> arg; fs.read(arg); }
            else if (cmd == "rm") { iss >> arg; fs.rm(arg); }

        else std::cout << "unknown command\n";
    }

    std::cout << "exiting inode-lab.\n";
    return 0;
}