#include <iostream>
#include "vector"

std::string first_player_type, second_player_type,
            first_player_token, second_player_token;

std::vector<std::string> valid_player_choices = {"Human", "AI"};

void PrintWelcomeBanner(){
    std::cout << "***************************\n";
    std::cout << "* Welcome to Tic Tac Toe! *\n";
    std::cout << "***************************\n";
}

int main(int argc, const char * argv[])
{
    return 0;
}