#include "boardpresenter.h"

const std::string BoardPresenter::LINE_SEPARATOR = "\n------------\n ";
const std::string BoardPresenter::TOKEN_SEPARATOR = "|";

std::string BoardPresenter::Present(Board board){
    BoardSpaces spaces = *new BoardSpaces(board.state());
    std::vector<std::vector<std::string>> rows = spaces.Rows();
    
    std::string first_row = FormatRow(rows[0]);
    std::string second_row = FormatRow(rows[1]);
    std::string third_row = FormatRow(rows[2]);
    
    return first_row + LINE_SEPARATOR + second_row + LINE_SEPARATOR + third_row + "\n";
}

std::string BoardPresenter::FormatRow(std::vector<std::string> row){
    std::string first_token = FormatToken(*(row.begin()));
    std::string last_token = FormatToken(*(row.end() - 1));
    std::vector<std::string> middle = std::vector<std::string>(row.begin() + 1, row.end() - 1);
    std::string formatted_row = first_token + JoinMiddle(middle) + last_token;
    return formatted_row;
}

std::string BoardPresenter::JoinMiddle(std::vector<std::string> middle){
    std::vector<std::string>::const_iterator iterator;
    std::string formatted_middle = "";
    for (iterator = middle.begin(); iterator != middle.end(); iterator++){
        std::string token = *iterator;
        formatted_middle += TOKEN_SEPARATOR;
        formatted_middle += FormatToken(token);
        formatted_middle += TOKEN_SEPARATOR;
    }
    return formatted_middle;
}

std::string BoardPresenter::FormatToken(std::string token){
    char formatted_token [20];
    sprintf(formatted_token, "%3s", token.c_str());
    return formatted_token;
}