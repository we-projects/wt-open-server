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
        /* 被执行方法的所属对象*/
        C task_class;

        /* 被执行方法的地址*/
        T task_func;
    public: 
        task_item(C task_c, T task_f);
        ~task_item();
    public: 
        /* 执行方法 */
        void task_run();
    };

    /*
     * 线程信息
     * 保存线程的任务队列
     * */

    template <class T, class C>
    class thread_item {
    private:
        /* 线程 */
        pthread_t thread;

        std::queue<we_thread_mgr::task_item<T, C>> 
            *task_info_queue;
    private: 
        static void* thread_working_only(void *);
    public: 
        thread_item();
        ~thread_item();
    public: 
        /*
         * 线程启动方法
         * 0: success
         * */
        int run();

        /*
         * 增加任务到队列中
         * 参数：
         * 方法，对象
         * 返回值: 
         * 0: success
         * */
        int push_task(T, C, int);
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
        std::map<int, 
            we_thread_mgr::thread_item<T, C>> *thread_pool;
    public: 
        thread_manager();
        ~thread_manager();
    public: 
    };

}

#endif



