/*
	* File     : parser.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Thu 19 Aug 2021 08:58:16 PM CST
*/

#include "parser.h"

exp_parser::parser::parser(std::string expre_str) {
    this->expression = new std::string(expre_str);
}

exp_parser::parser::~parser() {
    delete this->expression;
}

bool exp_parser::parser::parsing() {
    this->exp_json = {
        { "nul", nullptr },
        { "number", 1 },
        { "float", 1.3 },
        { "boolean", false },
        { "string", "中文测试" },
        { "array", { 1, 2, true, 1.4 } },
        { "object", {
                { "key", "value" },
                { "key2", "value2" },
            },
        }
    };

    // 序列化为字符串
    std::string json_str = this->exp_json.dump();
    // 美化输出，使用 4 个空格对输出进行格式化
    std::string pretty_str = this->exp_json.dump(4, ' ');

    std::cout << pretty_str << std::endl;

    return true;
}
