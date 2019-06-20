#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <thread>

//Useless
#include <iostream>


class core
{
public:
    //Retourne le nombre de coeur sur la machine
    const uint Core_count_computer = std::thread::hardware_concurrency();
    uint CoreProcessingCount = std::thread::hardware_concurrency()*2;

    void call_from_thread(int tid, int ThreadsCount, QString _LauncedP);
    void exec(QString LauncedP);

    uint64_t CharCount = 0;
    bool CharSpe_Password;//Si le MDP contient des charactères spéciaux

    bool AttacByDico;//Une attaque par le dictionaire
    bool UTF8_Password;//si le MDP utilise de l'UTF-8
    core();
    ~core();

private:

};

#endif // CORE_H
