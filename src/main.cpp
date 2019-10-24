#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool isOperation(std::string term, char &operation){
    if (term == "+"){
        operation = '+';
        return true;
    }
    else if (term == "-"){
        operation = '-';
        return true;
    }
    else if (term == "*"){
        operation = '*';
        return true;
    }
    else if (term == "="){
        operation = '=';
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

float ft_strtof(std::string s, int degree)
{
    float number;
    std::stringstream ss;
    ss << s;
    ss >> number;
    return number;
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
    float reduced[4] = {1 , 1 , 1 , 0};
    int degree;
    char coefficent;
    bool swap;
    char * pch;
    char operation;
    
    if (*argv){
        std::vector<std::string> terms;
        std::string term;
        // std::istringstream termStream(argv[0]);
        // while (std::getline(termStream, term, ' '))
        // {
        //     terms.push_back(term);
        // }
        std::string str = argv[0];
        std::string::size_type pos = std::string::npos;
        std::string prevOperation = "";
        while ((pos = str.find_first_of("=+-")) != std::string::npos) {
            std::string str2 = str.substr(0, pos);
            std::string chars = "* ";
            for (char c: chars) {
                str2.erase(std::remove(str2.begin(), str2.end(), c), str2.end());
            }
            prevOperation = str.at(pos);
            if (str2.length() > 0){
                terms.push_back(str2);
            }
            operations += (str.at(pos));
            std::cout << prevOperation << "\n";
            str.erase(0, pos + 1);
        }
        std::string chars = "* ";
        for (char c: chars) {
            str.erase(std::remove(str.begin(), str.end(), c), str.end());
        }
        terms.push_back(str);
        for(int i=0; i < terms.size(); i++){
            std::cout << terms.at(i);
            if (isOperation(terms.at(i), operation)){
                // std::cout << operation;
                continue;
            }
            else if (terms.at(i) == "="){
                swap = false;
            }
            else{
                degree = checkDegree(terms.at(i));
                std::cout << "| Term " << ft_strtof(terms.at(i), degree);
                std::cout << "| Operation: " << operation;
                std::cout << "| Degree: " << degree <<"\n";
                float value = ft_strtof(terms.at(i), degree);
                if (operation == '=') {
                    if (swap)
                        reduced[degree] += value;
                    else
                        reduced[degree] -= value;
                }
                else if (operation == '-'){
                    if (swap)
                        reduced[degree] -= - value;
                    else
                        reduced[degree] += value;
                }    
                else if (operation == '+'){
                    if (swap)
                        reduced[degree] += value;
                    else
                        reduced[degree] -= value;
                }
            }
            // std::cout << degree;
        }
        std::cout << "\nNew Values: ";
        for (int i = 0; i < 4; i++)
        {
            std::cout << " " << reduced[i];
        }
    }
    return 0; 
}