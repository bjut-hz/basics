//
// Created by hz on 2020/7/5.
//

#include <vector>
#include <string>
bool IsUniqueChar(std::string str) {
    // ascii map
    std::vector<int> dict(128, 0);
    for(auto& ch : str) {
        if(dict[ch - 'a']) {
            return false;
        }
        dict[ch - 'a']++;
    }

    return true;
}
