/*
	* File     : log_manager.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Sun 18 Jul 2021 08:25:40 PM CST
*/

#ifndef _LOG_MANAGER_H
#define _LOG_MANAGER_H

#include <iostream>
#include <string>
#include <map>

namespace gay_lib_log {

    class log_manager;
    typedef int(log_manager::*log_handle)(std::string);

    enum log_type {
        ltDebug, 
        ltHint, 
        ltWarning, 
        ltError
    };

    class log_manager {
    private: 
        std::map<gay_lib_log::log_type, gay_lib_log::log_handle> log_handle_list;

        int Debug_log_handle(std::string);
        int Hint_log_handle(std::string);
        int Warning_log_handle(std::string);
        int Error_log_handle(std::string);
    public: 
        log_manager();
        ~log_manager();
    public:
        int gay_log(std::string log_str, gay_lib_log::log_type type);
    };
    
}

#endif
