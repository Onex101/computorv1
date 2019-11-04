#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool isOperation(std::string term, char &operation){
    char tmp = term.at(0);
    if (tmp == '+'){
        operation = '+';
        return true;
    }
    else if (tmp == '-'){
        operation = '-';
        return true;
    }
    else if (tmp == '*'){
        operation = '*';
        return true;
    }
    else if (tmp == '='){
        operation = '=';
        return true;
    }
    operation = '+';
    return false;
}

bool isOperationBool(std::string term){
    if (term == "+"){
        return true;
    }
    else if (term == "-"){
        return true;
    }
    else if (term == "*"){
        return true;
    }
    else if (term == "="){
        return true;
    }
    return false;
}

bool hasDegree(std::string term){
    if (term.find('^') != std::string::npos)
        return true;
    else
        return false;
}

int checkDegree(std::string term){
    if (hasDegree(term)){
        char degree = term.back();
        if (degree == '0')
            return 0;
        else if (degree == '1')
            return 1;
        else if (degree == '2')
            return 2;
    }
    return 3;
}

float ft_strtof(std::string s)
{
    float number;
    std::stringstream ss;
    ss << s;
    ss >> number;
    return number;
}

std::string ft_ftostr(float myFloat){
    std::ostringstream ss;
    ss << myFloat;
    std::string s(ss.str());
    return s;
}

float sub(float i, float j){
    return i - j;
}

float add(float i, float j){
    return i + j;
}

float mul(float i, float j){
    return i * j;
}

int main (int argc, char **argv) {
    ++argv;
    std::vector<std::string> terms;
    std::string operations;
    std::stringstream line;
    float reduced[4] = {0 , 0 , 0 , 0};
    int degree;
    char coefficent;
    bool swap;
    int swapNow;
    char * pch;
    char operation;
    
    if (*argv){
        std::vector<std::string> terms;
        std::string term;
        std::string str = argv[0];
        std::string::size_type pos = std::string::npos;
        std::string prevOperation = "";
        int swapStage = 0;
        std::cout << str + "\n";
        while ((pos = str.find_first_of("+-=")) != std::string::npos) {
            if (prevOperation == ""){
                prevOperation = str.at(0);
                if (!isOperationBool(prevOperation))
                    prevOperation = "";
            }
            std::string str2 = str.substr(0, pos);
            std::string chars = "* ";
            for (char c: chars) {
                str2.erase(std::remove(str2.begin(), str2.end(), c), str2.end());
            }
            if (str2.length() > 0){
                terms.push_back(prevOperation + str2);
            }
            prevOperation = str.at(pos);
            if (prevOperation == "="){
                prevOperation = "";
                swapNow = swapStage;
            }
            swapStage++;
            operations += (str.at(pos));
            str.erase(0, pos + 1);
        }
        std::string chars = "* ";
        for (char c: chars) {
            str.erase(std::remove(str.begin(), str.end(), c), str.end());
        }
        terms.push_back(prevOperation + str);
        for(int i=0; i < terms.size(); i++){
            // std::cout << terms.at(i);
            isOperation(terms.at(i), operation);
            if (terms.at(i) == "="){
                swap = false;
            }
            else{
                degree = checkDegree(terms.at(i));
                int pos = terms.at(i).find_first_of("X");
                float value = ft_strtof(terms.at(i).substr(0, pos));
                if (i < swapNow)
                        reduced[degree] += value;
                    else
                        reduced[degree] -= value;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            std::string neg = ft_ftostr(reduced[i] * -1) + " * X^" + ft_ftostr(i);
            std::string pos = ft_ftostr(reduced[i]) + " * X^" + ft_ftostr(i);
            if (i == 0){
                if (reduced[i] < 0)
                    std::cout << "- " + neg;
                else
                    std::cout << pos;
            }
            else{
                if (reduced[i] < 0)
                    std::cout << " - " + neg;
                else
                    std::cout << " + " + pos;
            }
        }

        std::cout << " = 0\n";
    }
    return 0; 
}