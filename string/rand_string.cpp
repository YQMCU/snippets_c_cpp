#include <stdlib.h>
#include <string>
#include <iostream>

/**
 * @brief      生成随机字符串，可用于临时文件名
 *
 * @param      s       { parameter_description }
 * @param[in]  number  The number
 */
static void get_rand_string(std::string &s, const int number)
{
    s = "";
    char str[64] = "00123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char ch;
    // srand 重置随机种子 能让生成的字符串都是同一个
    // srand((unsigned int) time((time_t*) NULL)); // #include <time.h>
    for (int i=0; i<number; i++) {
        ch = str[(rand() % 61) + 1];
        s += ch;
    }
}

int main() {

    std::string temp_name;

    for (int i=0; i<6; i++) {
        get_rand_string(temp_name, 6);
        std::cout << "temp name: " << temp_name << std::endl;
    }

    // temp name: fjpQFl
    // temp name: AH03WO
    // temp name: eqI36l
    // temp name: 870PxV
    // temp name: myaoF9
    // temp name: IA99dQ

}
