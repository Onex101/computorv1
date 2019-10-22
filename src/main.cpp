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
    std::stringstream line;
    float reduced[4] = {};
    int degree;
    char coefficent;
    char operation;
    bool swap;
    
    if (*argv){
        std::vector<std::string> terms;
        std::string term;
        std::istringstream termStream(argv[0]);
        while (std::getline(termStream, term, ' '))
        {
            terms.push_back(term);
        }
        for(int i=0; i < terms.size(); i++){
            // std::cout << terms.at(i);
            if (isOperation(terms.at(i), operation)){
                // std::cout << operation;
                continue;
            }
            else if (terms.at(i) == "="){
                swap = false;
            }
            else{
                degree = checkDegree(terms.at(i));
                std::cout  << ft_strtof(terms.at(i)) << "| Operation: " << operation << "| Degree: " << degree;
                if (operation == '-'){
                    if (swap)
                        reduced[degree] = reduced[degree] - ft_strtof(terms.at(i));
                    else
                        reduced[degree] = reduced[degree] + ft_strtof(terms.at(i));
                }    
                else if (operation == '+' && swap){
                    if (swap)
                        reduced[degree] = reduced[degree] + ft_strtof(terms.at(i));
                    else
                        reduced[degree] = reduced[degree] - ft_strtof(terms.at(i));
                }
                else if (operation == '*' && swap){
                    if (swap)
                        reduced[degree] = reduced[degree] * ft_strtof(terms.at(i));
                    else
                        reduced[degree] = reduced[degree] / ft_strtof(terms.at(i));
                }
            }
            // std::cout << degree;
        }
        for (int i = 0; i < 4; i++)
        {
            std::cout << reduced[i];
        }
    }
    return 0; 
}