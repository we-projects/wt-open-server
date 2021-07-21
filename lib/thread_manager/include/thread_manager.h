/*
	* File     : thread_manager.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Wed 21 Jul 2021 09:17:20 PM CST
*/

#ifndef _THREAD_MANAGER_H
#define _THREAD_MANAGER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>             /* Definition of uint64_t */
#include <pthread.h>
#include <sys/eventfd.h>

#include <iostream>
#include <queue>

namespace we_thread_mgr {

    /* 
     * 任务信息
     * 任务队列中的任务节点
     * 保存着任务的信息
     * */
    class task_item {
    private:
    public: 
        task_item();
        ~task_item();
    };

    /*
     * 任务队列
     * 保存一个任务队列以及 eventfd 文件描述符
     * */
    class task_queue {
    private: 
        int efd;
        std::queue<we_thread_mgr::task_item> task_info_queue;
    public: 
        task_queue();
        ~task_queue();
    };

    /*
     * 线程信息
     * 保存线程的任务队列
     * */
    class thread_item {
    private:
        pthread_t thread;
        we_thread_mgr::task_queue t_queue;
    public: 
        thread_item();
        ~thread_item();
    };

    /*
     * 线程管理者
     * 生成、分配以及销毁线程
     * */
    class thread_manager {
    private:
    public: 
        thread_manager();
        ~thread_manager();
    };

}

#endif
