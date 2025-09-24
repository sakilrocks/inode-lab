
#include "filesystem.h"
#include <iostream>

FileSystem::FileSystem() {
    root = new Directory{"root", nullptr};
    current = root;
}

FileSystem::~FileSystem() {
    deleteDirRecursive(root);
}


void FileSystem::deleteDirRecursive(Directory* dir) {
    for (auto &subdir : dir->subdirs) {
        deleteDirRecursive(subdir.second);
    }
    delete dir;
}


void FileSystem::mkdir(const std::string &name) {
    if (current->subdirs.count(name)) {
        std::cout << "directory already exists\n";
        return;
    }
    Directory* newDir = new Directory{name, current};
    current->subdirs[name] = newDir;
    std::cout << "directory created: " << name << "\n";
}


void FileSystem::ls() const {
    for (const auto &[name, _] : current->subdirs) {
        std::cout << "[DIR]  " << name << "\n";
    }
    for (const auto &[name, file] : current->files) {
        std::cout << "[FILE] " << name << "\n";
    }
}


void FileSystem::cd(const std::string &name) {
    if (name == ".." && current->parent) {
        current = current->parent;
    } else if (current->subdirs.count(name)) {
        current = current->subdirs[name];
    } else {
        std::cout << "directory not found\n";
    }
}


void FileSystem::create(const std::string &name) {
    if (current->files.count(name)) {
        std::cout << "file already exists\n";
        return;
    }
    current->files[name] = File{name, ""};
    std::cout << "file created: " << name << "\n";
}


void FileSystem::write(const std::string &name, const std::string &content) {
    if (!current->files.count(name)) {
        std::cout << "file not found\n";
        return;
    }
    current->files[name].data = content;
    std::cout << "wrote to file: " << name << "\n";
}


void FileSystem::read(const std::string &name) const {
    if (!current->files.count(name)) {
        std::cout << "file not found.\n";
        return;
    }
    std::cout << "contents of " << name << ": " << current->files.at(name).data << "\n";
}


void FileSystem::rm(const std::string &name) {
    if (current->files.erase(name)) {
        std::cout << "deleted file: " << name << "\n";
    } else if (current->subdirs.erase(name)) {
        std::cout << "deleted directory: " << name << "\n";
    } else {
        std::cout << "no such file or directory.\n";
    }
}

