#include "boardspaces.h"

std::vector<std::vector<std::string>> BoardSpaces::Rows(){
    std::vector<std::vector<std::string>> rows;
    for(int i = 0, offset = 0; i < base_; i++, offset += base_){
        std::vector<std::string>::const_iterator start = state_.begin() + offset;
        std::vector<std::string>::const_iterator end = start + base_;
        std::vector<std::string> row = std::vector<std::string>(start, end);
        rows.push_back(row);
    }
    return rows;
}

std::vector<std::vector<std::string>> BoardSpaces::Columns(){
    std::vector<std::vector<std::string>> columns;
    for (int i = 0; i < base_; i++){
        int index = i;
        std::vector<std::string> column;
        for (int j = 0; j < base_; j++){
            column.push_back(state_[index]);
            index += base_;
        }
        columns.push_back(column);
    }
    return columns;
}