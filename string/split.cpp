/**
 * @defgroup   SPLIT split
 *
 * @brief      This file implements split.
 *
 * @author     Tu-160
 * @date       2022
 */

#include <vector>
#include <map>
#include <iostream>


void split(const char* str, std::map<std::string,std::string>& ret)
{
    ret.erase(ret.begin(), ret.end());

    std::string str_temp = std::string(str);
    std::string tmp;
    std::string key;
    std::string val;
    bool flag = false;

    for (unsigned int i=0; i<str_temp.size(); i++) {
        if (str_temp[i] == ':') {
            key = tmp;
            tmp = "";

        } else if (str_temp[i] == ',') {
            val = tmp;
            tmp = "";

        } else {
            tmp += str_temp[i];
        }

        if (i == str_temp.size() - 1) {
            if (key.size() > 0) {
                val = tmp;
                flag = true;
            }

        } else {
            if (key.size() > 0 && val.size() > 0) {
                flag = true;
            }
        }

        if (flag == true) {
            ret[key] = val;
            key = "";
            val = "";
            flag = false;
        }
    }
}



int main(int argc, char *argv[])
{

    std::map<std::string, std::string> ret;
    const char* ch = "11:12,13:file44,fa12:76";
    split(ch, ret);

    for (std::map<std::string, std::string>::iterator it = ret.begin(); it != ret.end(); it++) {
        std::cout << "k/v: " << it->first << "," << it->second << std::endl;
    }

//  k/v: 11,12
//  k/v: 13,file44
//  k/v: fa12,76


    return 0;
}
