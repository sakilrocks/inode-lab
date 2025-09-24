
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <map>
#include <vector>

// represents a file in our virtual file system

struct File {
    std::string name;
    std::string data;
};

// represents a directory in our virtual file system

struct Directory {
    std::string name;
    Directory* parent;
    std::map<std::string, Directory*> subdirs;
    std::map<std::string, File> files;
};



class FileSystem {

public:
    FileSystem();
    ~FileSystem();

    void mkdir(const std::string& name);
    void ls() const;
    void cd(const std::string& name);
    void create(const std::string& name);
    void write(const std::string& name, const std::string& content);
    void read(const std::string& name) const;
    void rm(const std::string& name);

private:
    Directory* root;
    Directory* current;

    void deleteDirRecursive(Directory* dir);   // helper for destructor
};

#endif
