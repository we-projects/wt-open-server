/*
	* File     : parser.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Thu 19 Aug 2021 08:58:25 PM CST
*/

#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include <string>

#include "configor/json.hpp"

namespace exp_parser {

    class parser {
    private: 
        std::string *expression;
        configor::json exp_json;
    public:
        parser(std::string);
        ~parser();

        bool parsing();
    };
    
};

#endif
