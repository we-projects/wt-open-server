/*
	* File     : parser.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Thu 19 Aug 2021 08:58:16 PM CST
*/

#include "parser.h"

bool exp_parser::parser::json_parse() {
    
}

exp_parser::parser::parser(std::string expr_init) : 
    expr(expr_init) {}

exp_parser::parser::~parser() {}

bool exp_parser::parser::parsing(std::string expre_str) {
    if (!expre_str.empty())
        this->expr = expre_str;

    if (this->expr.empty())
        std::cerr << std::string("[exp_parser::parser::parsing] expr is empty.") << std::endl;

    this->exp_json["temp"] = this->expr;
    this->json_parse();

    // 序列化为字符串
    std::string json_str = this->exp_json.dump();
    // 美化输出，使用 4 个空格对输出进行格式化
    std::string pretty_str = this->exp_json.dump(4, ' ');
    std::cout << pretty_str << std::endl;

    return true;
}
