/*
	* File     : log_manager.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Sun 18 Jul 2021 08:26:34 PM CST
*/

#include "log_manager.h"

/* private function */

int gay_lib_log::log_manager::Debug_log_handle(std::string log_str) {
    std::cout << std::string("[Debug] ") << log_str << std::endl;
    return 0;
}

int gay_lib_log::log_manager::Hint_log_handle(std::string log_str) {
    std::cout << std::string("[Hint] ") << log_str << std::endl;
    return 0;
}

int gay_lib_log::log_manager::Warning_log_handle(std::string log_str) {
    std::cout << std::string("[Warning] ") << log_str << std::endl;
    return 0;
}

int gay_lib_log::log_manager::Error_log_handle(std::string log_str) {
    std::cout << std::string("[Error] ") << log_str << std::endl;
    return 0;
}


/* public function */

gay_lib_log::log_manager::log_manager() {
    this->log_handle_list[ltDebug]   = &gay_lib_log::log_manager::Debug_log_handle;
    this->log_handle_list[ltHint]    = &gay_lib_log::log_manager::Hint_log_handle;
    this->log_handle_list[ltWarning] = &gay_lib_log::log_manager::Warning_log_handle;
    this->log_handle_list[ltError]   = &gay_lib_log::log_manager::Error_log_handle;
}

gay_lib_log::log_manager::~log_manager() {
    
}

int gay_lib_log::log_manager::gay_log(std::string log_str, gay_lib_log::log_type type) {
    return ((this->*this->log_handle_list[type])(log_str));
}
