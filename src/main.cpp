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
    return -1;
}

float performOperation(float term, std::string newTerm, char operation){
    if (operation == '-')

    else if (operation == '+')
    
    else if (operation == '*')

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
    std::string reduced[4];
    int degree;
    char coefficent;
    char operation;
    
    if (*argv){
        std::vector<std::string> terms;
        std::string term;
        std::istringstream termStream(argv[0]);
        while (std::getline(termStream, term, ' '))
        {
            terms.push_back(term);
        }
        for(int i=0; i < terms.size(); i++){
            operation = '\0';
            if (isOperation(terms.at(i), operation)){
                std::cout << operation;
                continue;
            }
            degree = checkDegree(terms.at(i));
            reduced[degree] = reduced[degree]
            std::cout << degree;
        }
    }
    return 0; 
}