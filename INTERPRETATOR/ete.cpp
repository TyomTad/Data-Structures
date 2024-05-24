#include "ete.h"
#include "includes.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

extern std::vector<std::vector<std::string>> memory;

bool ete::doub(const std::string& str) {
    return str.find('.') != std::string::npos;
}

bool ete::Pay(std::vector<std::string> payman) {
    if (payman.size() <= 3) {
        val1 = payman[0];
        nshan = payman[1];
        val2 = payman[2];
    } else {
        val1 = payman[0];
        nshan = payman[1] + payman[2];
        val2 = payman[3];
    }
    //std::cout << val1 + " " + nshan + " " + val2 << std::endl;

    for (const auto& mem : memory) {
        if (val1 == mem[0]) {
            val1 = mem[1];
        }
        if (val2 == mem[0]) {
            val2 = mem[1];
        }
    }

    if (doub(val1) && doub(val2)) {
        if (nshan == "<") {
            return std::stod(val1) < std::stod(val2);
        } else if (nshan == "<=") {
            return std::stod(val1) <= std::stod(val2);
        } else if (nshan == ">") {
            return std::stod(val1) > std::stod(val2);
        } else if (nshan == ">=") {
            return std::stod(val1) >= std::stod(val2);
        } else if (nshan == "==") {
            return std::stod(val1) == std::stod(val2);
        } else if (nshan == "!=") {
            return std::stod(val1) != std::stod(val2);
        } else {
            throw std::out_of_range("Undefined boolean symbol: " + nshan);
        }
        std::cout << "double\n";
    } else if (std::isdigit(val1[0]) && std::isdigit(val2[0])) {
        if (nshan == "<") {
            return std::stoi(val1) < std::stoi(val2);
        } else if (nshan == "<=") {
            return std::stoi(val1) <= std::stoi(val2);
        } else if (nshan == ">") {
            return std::stoi(val1) > std::stoi(val2);
        } else if (nshan == ">=") {
            return std::stoi(val1) >= std::stoi(val2);
        } else if (nshan == "==") {
            return std::stoi(val1) == std::stoi(val2);
        } else if (nshan == "!=") {
            return std::stoi(val1) != std::stoi(val2);
        } else {
            throw std::out_of_range("Undefined boolean symbol: " + nshan);
        }
    } else if (val1.front() == '\"' && val1.back() == '\"' && val2.front() == '\"' && val2.back() == '\"') {
        if (nshan == "==") {
            return val1 == val2;
        } else if (nshan == "!=") {
            return val1 != val2;
        } else {
            throw std::out_of_range("Undefined boolean symbol for strings: " + nshan);
        }
    } else if (val1.front() == '{' && val1.back() == '}' && val2.front() == '{' && val2.back() == '}') {
        throw std::out_of_range("Array comparison not supported");
    } else {
        throw std::out_of_range("Syntax error");
    }
}
