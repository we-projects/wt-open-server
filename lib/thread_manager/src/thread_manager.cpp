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
                                task_class(task_c), 
                                task_func(task_f){}

template <class T, class C>
we_thread_mgr::task_item<T, C>::~task_item() {
    
}

template <class T, class C>
void we_thread_mgr::task_item<T, C>::task_run() {
    this->task_class->*this->task_func();
}

/* task_queue */

template <class T, class C>
we_thread_mgr::task_queue<T, C>::task_queue() {
    
}

template <class T, class C>
we_thread_mgr::task_queue<T, C>::~task_queue() {
    
}

/* thread_item */

template <class T, class C>
we_thread_mgr::thread_item<T, C>::thread_item() {
    
}

template <class T, class C>
we_thread_mgr::thread_item<T, C>::~thread_item() {
    
}

/* thread_manager */

template <class T, class C>
we_thread_mgr::thread_manager<T, C>::thread_manager() {
    
}

template <class T, class C>
we_thread_mgr::thread_manager<T, C>::~thread_manager() {
    
}




