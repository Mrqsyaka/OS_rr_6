#include <windows.h>

#include <iostream>

#include <process.h>



using namespace std;



typedef struct _THREADARG { // Аргумент потоку

    DWORD iTh; // Номер потоку: 0, 1, 3, ...

} THREADARG, * PTHREADARG;



static DWORD WINAPI ThFunc(PTHREADARG pThArg);

static BOOL WINAPI Write(PTHREADARG pThArg);



static HANDLE* ThreadHandle;



HANDLE hMutex;



volatile DWORD M = 0; // Спільний ресурс



int _tmain(int argc, TCHAR* argv[])

{



    DWORD NPr, ThId, iTh;

    PTHREADARG ThArg;

    NPr = 16; // Кількість потоків



    // Масив аргументів потоків 

    ThArg = new THREADARG[NPr];

    // Масив дескрипторів потоків 

    ThreadHandle = new HANDLE[NPr];

    // Створюємо м’ютекс у вільному стані

    hMutex = CreateMutex(NULL, FALSE, NULL);



    // Створити потоки (у призупиненому стані)

    for (iTh = 0; iTh < NPr; iTh++)

    {

        ThArg[iTh].iTh = iTh;

        ThreadHandle[iTh] = (HANDLE)_beginthreadex

        (NULL,

            0,

            (unsigned int(__stdcall*)(void*))ThFunc,

            &ThArg[iTh],

            CREATE_SUSPENDED,

            (unsigned int*)&ThId);

    }



    // Запустити усі призупинені потоки

    for (iTh = 0; iTh < NPr; iTh++)

        ResumeThread(ThreadHandle[iTh]);



    // дочекатися завершення усіх потоків  WaitForMultipleObjects(NPr, ThreadHandle, TRUE,

    INFINITE);        // Без таймаута



    CloseHandle(hMutex); // Закрити дескриптор

    // м’ютекса

    // Закрити дескриптори потоків

    for (iTh = 0; iTh < NPr; iTh++)

        CloseHandle(ThreadHandle[iTh]);

    delete[]ThArg;

    delete[]ThreadHandle;



    return 0;



} // End of _tmain.



// функція потоків

DWORD WINAPI ThFunc(PTHREADARG pThArg)

{

    if (Write(pThArg)) // Якщо мютекс звільнився

        // і поточний потік відпрацював,

        _endthreadex(0); // то завершити потік з

    // кодом завершення 0

    return 0;

}



// функція роботи зі спільним ресурсом,

// захищеним м’ютексом

BOOL WINAPI Write(PTHREADARG pThArg)

{

    DWORD dwWaitResult;



    // Чекаємо звільнення м’ютекса перед тим як

    // звернутися до спільного ресурсу

    dwWaitResult = WaitForSingleObject(hMutex,

        5000L); // 5 секунд на таймаут або INFINITE

    if (dwWaitResult == WAIT_TIMEOUT) // Таймаут.

        // М’ютекс за цей час не звільнився

    {

        return FALSE;

    }

    else // М’ютекс звільнився, і наш потік його зайняв.  

          //Можна працювати.

    {



        M += pThArg->iTh;



        cout << "Write: "

            << pThArg->iTh

            << "\t"

            << "M="

            << M

            << endl;



        ReleaseMutex(hMutex); // Звільняємо м’ютекс

    }



    return TRUE;

}