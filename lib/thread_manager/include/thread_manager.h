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
#include <map>

namespace we_thread_mgr {

    /* 
     * 任务信息
     * 任务队列中的任务节点
     * 保存着任务的信息
     * */
    template <class T, class C>
    class task_item {
    private:
        C task_class;
        T task_func;
    public: 
        task_item();
        ~task_item();
    };

    /*
     * 任务队列
     * 保存一个任务队列以及 eventfd 文件描述符
     * */
    template <class T, class C>
    class task_queue {
    private: 
        int efd;
        std::queue<we_thread_mgr::task_item<T, C>> task_info_queue;
    public: 
        task_queue();
        ~task_queue();
    };


    /*
     * 线程状态
     * */
    enum thread_status {
        /* 可用 */
        ts_available, 

        /* 已分配*/
        ts_assigned, 
    };

    /*
     * 线程信息
     * 保存线程的任务队列
     * */

    template <class T, class C>
    class thread_item {
    private:
        pthread_t thread;
        we_thread_mgr::task_queue<T, C> t_queue;
        we_thread_mgr::thread_status status;
    public: 
        thread_item();
        ~thread_item();
    };


    /*
     * 线程管理者
     * 生成、分配以及销毁线程
     * 实现目标：
     * * 使用者只需要将任务丢给mgr, 
     * * 线程的创建，执行，销毁，任务的分配等等全部由mgr完成
     * */
    template <class T, class C>
    class thread_manager {
    private:
        std::map<we_thread_mgr::thread_status, 
                 we_thread_mgr::thread_item<T, C>> thread_pool;
    public: 
        thread_manager();
        ~thread_manager();
    };

}

#endif



