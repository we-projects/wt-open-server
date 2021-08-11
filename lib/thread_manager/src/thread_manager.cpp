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
} 

template <class T, class C>
we_thread_mgr::thread_item<T, C>::~thread_item() {

    /* todo 需要加入判断线程是否还在执行 */

    pthread_join(this->thread, nullptr);
}

/* 线程执行的方法 */
template <class T, class C>
void* we_thread_mgr::thread_item<T, C>::
    thread_working_only(void *arg) {

    thread_item* t_this;

    std::string log_func_name = 
        "[void* we_thread_mgr:: \
            local_call_thread_working(int efd)]";

    t_this = thread_item(arg);
    if (t_this == nullptr)
        std::cerr << log_func_name + "t_this is nullptr\n";

    while (true) {
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

    int ans = 0;

    /* todo 若线程存在跳过，或通过参数加入重启等其他操作 */

    if (pthread_create(&this->thread , NULL, thread_working_only, this)) {
        std::cerr << log_func_name + "pthread_create error\n";
        ans = 1;
    }

    return ans;
}

template <class T, class C>
int we_thread_mgr::thread_item<T, C>::push_task(T t_func, C t_proj, int sec_timeout) {
    std::string log_func_name = 
        "[int we_thread_mgr::thread_item<T, C>::push_task()]";

    int ans = -1;

    /* todo  */

    return ans;
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




