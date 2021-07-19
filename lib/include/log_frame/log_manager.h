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

namespace gay_lib_log {

    class log_manager {
    private: 
    public: 
        log_manager();
        ~log_manager();
    public:
        int gay_log(std::string log_str, int type);
    };
    
}

#endif
