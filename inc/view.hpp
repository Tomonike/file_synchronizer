#pragma once

#include <atomic>
#include <filesystem>
#include <iostream>
#include <regex>
#include <set>

namespace fs = std::filesystem;

class View
{
public:
    enum class Message
    {
        Incorrect = 0,
        GiveFolder,
        DirExists,
        Interval
    };

    void printMenu();
    void printOptions();
    void printDirectory(const fs::path &path);
    void printFiles(const std::set<fs::path> &fileDirList);

    void printMessage(Message m);

private:
    bool validateForPrinting(std::string name);
};