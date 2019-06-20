/*
*
* git.py - for git clone and pull in local
*
* Created by Benoît(Bensuperpc@gmail.com) 04th June 2019
* Updated by X for C++11
*
* Released into the Public domain with MIT licence
* https://opensource.org/licenses/MIT
*
* Written with QtCreator and C++11
* Script compatibility : Windows, Linux
* Script requirement : C++11 and above, GCC 7.X and above
*
* ==============================================================================
*/

#include "core.h"
#include <iostream>
#include <thread>
#include<qprocess.h>
#include<QtDebug>

#include <iostream>
#include <mutex>
#include <chrono>
static std::mutex g_display_mutex;
static std::atomic_uint tt;

core::core()
{
    core::exec("t");
}


void core::exec(QString LauncedP){
    std::thread *tt = new std::thread[CoreProcessingCount];//On créer les Threads
    for (unsigned int i = 0; i < CoreProcessingCount; ++i) {
        tt[i] = std::thread(&core::call_from_thread,this,i,CoreProcessingCount, LauncedP);
    }
    for (unsigned int i = 0; i < CoreProcessingCount; ++i){
        if(tt[i].joinable()){
            tt[i].join();
            qDebug() << "Join thread :" << i;
        }
    }

    delete [] tt;//On nettoie la Memoire
    qDebug() << "ffff ";
}

void core::call_from_thread(int tid, int ThreadsCount, QString _LauncedP) {
    tt = tt + 1;

    std::thread::id this_id = std::this_thread::get_id();
    g_display_mutex.lock();
    std::cout << "thread " << this_id << " sleeping...\n";
    qDebug() << "Launched by thread " << tid;

    qDebug() << "tt " << tt;
    g_display_mutex.unlock();
    qDebug() << "===========";

    std::vector<int>  arr;
    for(unsigned long long i = 64 ; i<=75; i++){
           arr.emplace_back(i);

            //std::cout << arr[i].ggg;
            qDebug() << "I =" << i <<char(arr[i]);
        }
    qDebug() << "===========";


    std::this_thread::sleep_for(std::chrono::seconds(5));

}




core::~core()
{

}
