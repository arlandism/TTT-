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
