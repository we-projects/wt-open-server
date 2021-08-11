/*
	* File     : thread_manager.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Wed 21 Jul 2021 09:15:19 PM CST
*/

#include "thread_manager.h"

/* task_item */

template <class T, class C>
we_thread_mgr::task_item<T, C>::task_item(C task_c, T task_f) : 
    task_class(task_c), task_func(task_f){}

template <class T, class C>
we_thread_mgr::task_item<T, C>::~task_item() {
    
}

template <class T, class C>
void we_thread_mgr::task_item<T, C>::task_run() {
    this->task_class->*this->task_func();
}

/* thread_item */

template <class T, class C>
we_thread_mgr::thread_item<T, C>::thread_item() {
    std::string log_func_name = 
        "[we_thread_mgr::thread_item<T, C>::thread_item()]";

    /* 创建`eventfd` */
    this->efd = eventfd(0, 0);
    if (efd == -1)
        std::cerr << log_func_name + "create efd failed\n";

} 

template <class T, class C>
we_thread_mgr::thread_item<T, C>::~thread_item() {
    pthread_join(this->thread, nullptr);
}

/* 线程执行的方法 */
template <class T, class C>
void* we_thread_mgr::thread_item<T, C>::
    local_call_thread_working(void *arg) {

    ssize_t read_size;
    uint64_t read_sig;
    thread_item* t_this;

    std::string log_func_name = 
        "[void* we_thread_mgr:: \
            local_call_thread_working(int efd)]";

    t_this = thread_item(arg);
    if (t_this == nullptr)
        std::cerr << log_func_name + "t_this is nullptr\n";

    while (true) {
        read_size = read(t_this->efd, 
            &read_sig, sizeof(uint64_t));

        if (read_size != sizeof(uint64_t))
            std::cerr << log_func_name + "read error\n";

        /* 放弃任务队列中所有任务，直接退出线程 */
        if (read_sig == 2) {
            pthread_exit(nullptr);
        }

        /* 没有收到执行的通知
         * 休眠1s, 再继续
         * */
        if (read_sig != 1) {
            sleep(1);
            continue;
        }

        /* 从任务队列中取出一个任务 */
        we_thread_mgr::task_item<T, C> task;
        t_this->task_info_queue->front();
        t_this->task_info_queue->pop();

        /* 执行该任务 */
        task.task_run();
    }
    
    return nullptr;
}

template <class T, class C>
int we_thread_mgr::thread_item<T, C>::run() {
    std::string log_func_name = 
        "[int we_thread_mgr::thread_item<T, C>::run()]";

    if (pthread_create(&this->thread , NULL, local_call_thread_working, this)) {
        std::cerr << log_func_name + "pthread_create error\n";
        return -1;
    }

    return this->efd;
}

/* thread_manager */

template <class T, class C>
we_thread_mgr::thread_manager<T, C>::thread_manager() {
    this->thread_pool = new std::map<int, 
                                    we_thread_mgr::thread_item<T, C>>;
}

template <class T, class C>
we_thread_mgr::thread_manager<T, C>::~thread_manager() {
    
}




