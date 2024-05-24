#include "typecontroler.h"
//#include "type.h"
#include "int.h"
#include "bool.h"
#include "string.h"
#include "array.h"
#include "double.h"
//#include "includes.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype> // For isdigit

extern std::vector<std::vector<std::string>> memory; // Global memory

std::string TypeControler::Mathval(std::string val1, std::string val2, std::string nshan) {
    for (const auto& mem : memory) {
        if (val1 == mem[0]) {
            val1 = mem[1];
        }
        if (val2 == mem[0]) {
            val2 = mem[1];
        }
    }

    if ((val1 == "true" || val1 == "false") && (val2 == "true" || val2 == "false")) {
        if (nshan == "+") {
            val1 = (val1 == "true" || val2 == "true") ? "true" : "false";
        } else if (nshan == "-") {
            val1 = (val1 == "true" && val2 == "false") ? "true" : "false";
        } else {
            throw std::out_of_range("Undefined operation for bool: " + nshan);
        }
    } else if (val1.front() == '\"' && val1.back() == '\"' && val2.front() == '\"' && val2.back() == '\"') {
        if (nshan == "+") {
            val1 = "\"" + val1.substr(1, val1.size() - 2) + val2.substr(1, val2.size() - 2) + "\"";
        } else {
            throw std::out_of_range("Undefined operation for strings: " + nshan);
        }
    } else if (val1.front() == '<' && val1.back() == '>' && val2.front() == '<' && val2.back() == '>') {
        throw std::out_of_range("Undefined operation for arrays: " + nshan);
    } else if (doub(val1) && doub(val2)) {
        if (nshan == "+") {
            val1 = std::to_string(std::stod(val1) + std::stod(val2));
        } else if (nshan == "-") {
            val1 = std::to_string(std::stod(val1) - std::stod(val2));
        } else if (nshan == "*") {
            val1 = std::to_string(std::stod(val1) * std::stod(val2));
        } else if (nshan == "/") {
            if (val2 != "0") {
                val1 = std::to_string(std::stod(val1) / std::stod(val2));
            } else {
                throw std::out_of_range("Division by zero");
            }
        } else {
            throw std::out_of_range("Undefined operation for doubles: " + nshan);
        }
    } else if (isdigit(val1[0]) && isdigit(val2[0])) {
        if (nshan == "+") {
            val1 = std::to_string(std::stoi(val1) + std::stoi(val2));
        } else if (nshan == "-") {
            val1 = std::to_string(std::stoi(val1) - std::stoi(val2));
        } else if (nshan == "*") {
            val1 = std::to_string(std::stoi(val1) * std::stoi(val2));
        } else if (nshan == "/") {
            if (val2 != "0") {
                val1 = std::to_string(std::stoi(val1) / std::stoi(val2));
            } else {
                throw std::out_of_range("Division by zero");
            }
        } else {
            throw std::out_of_range("Undefined operation for integers: " + nshan);
        }
    } else {
        throw std::out_of_range("Syntax error");
    }
    return val1;
}

bool TypeControler::doub(std::string rhv) {
    return rhv.find('.') != std::string::npos;
}

TypeControler::TypeControler(std::vector<std::string> tokens) {
    std::string valuestr;
    std::string namestr = tokens[0];
    
    if (tokens.size() < 4) {
        for (size_t i = 2; i < tokens.size(); ++i) {
            valuestr += tokens[i] + " ";
        }
        //std::cout << valuestr << std::endl;
    } else {
        valuestr = Mathval(tokens[2], tokens[4], tokens[3]);
       // std::cout << valuestr << std::endl;
    }

    std::istringstream r1(valuestr);
    std::string tmp;
    r1 >> tmp;
    std::istringstream n1(namestr);
    std::string rhv;
    n1 >> rhv;

    chooseType(tmp, rhv);
}

void TypeControler::chooseType(std::string value, std::string name) {
    for (auto& entry : memory) {
        if (!entry.empty() && entry[0] == name) {
            for (const auto& val : memory) {  
                if (value == val[0]) {
                    value = val[1];
                }
            }
            entry[1] = value;
            entry[2] = searchType(value);
            return;
        }
    }

    if (value == "true" || value == "false") {
        Bool(name, value);
    } else if (value.front() == '\"' && value.back() == '\"') {
        String(name, value);
    } else if (value.front() == '<' && value.back() == '>') {
        Array(name, value);
    } else if (doub(value)) {
        Double(name, value);
    } else if (isdigit(value[0])) {
        Int(name, value);
    } else {
        throw std::out_of_range("Syntax error");
    }
}

std::string TypeControler::searchType(std::string value) {
    if (value == "true" || value == "false") {
        return "bool";
    } else if (value.front() == '\"' && value.back() == '\"') {
        return "string";
    } else if (value.front() == '<' && value.back() == '>') {
        return "array";
    } else if (doub(value)) {
        return "double";
    } else if (isdigit(value[0])) {
        return "int";
    } else {
        throw std::out_of_range("Syntax error");
    }
}

