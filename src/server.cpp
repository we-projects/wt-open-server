/*
	* File     : server.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Sat 17 Jul 2021 07:43:24 PM CST
*/

#include "server.h"

int main() {

    /* everything todo.*/

    std::cout << "hello world " << std::endl;

    gay_lib_log::log_manager *g_log = new gay_lib_log::log_manager();

    g_log->gay_log("this is a Debug type log.", gay_lib_log::log_type::ltDebug);

    std::string test;
    std::cin >> test;

    exp_parser::parser parser;
    parser.parsing(test);

    return 0;
}
