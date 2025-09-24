# inode-lab

a simple **virtual file system** simulation in C++.  

---

## **features**
- create directories (`mkdir`)  
- list contents (`ls`)  
- change directory (`cd`)  
- create files (`create`)  
- write to files (`write`)  
- read file contents (`read`)  
- remove files or directories (`rm`)  

### note:
- all files and directories are **stored in memory** while the program runs.  
- no actual .txt files are created on your computer yet.  
- the data/ folder is reserved for future persistent storage.  
- .gitignore keeps compiled files and runtime files like filesystem.bin out of the repo.  

---

## **file structure**

```
inode-lab/
├─ src/
│   ├─ main.cpp         # CLI interface
│   └─ filesystem.cpp   # file system implementation
├─ include/
│   └─ filesystem.h     # file and directory structs + declarations
├─ data/                # reserved for future persistent storage
├─ Makefile             # build script
├─ .gitignore           # ignore compiled and runtime files
└─ README.md
```
