#include <windows.h>
#include <iostream>
#include <process.h>
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    ~node() {delete left; delete right;}
};

int main()
{
    // v3 = (rand() % 30 + 1985);
    node* list = new node[(rand() % 30 + 40)];
    list[0].data = (rand() % 100);
    list[0].left = NULL;
    list[0].right = NULL;
    cout << list[0].data;
    delete list;
}


// using namespace std;

// //Потік А формує спільний ресурс(1).Потік В звертається до цього спільного ресурсу для
// //зчитування даних і виконує над ними перетворення(2).Потік С виводить результат перетворення у вікно
// //програми.Усі потоки належать одному процесу.Захист спільного ресурсу виконати за допомогою
// //м’ютекса.
// //(1) - бінарне дерево дійсних чисел
// //(2) - пошук входження елемента


// typedef struct _THREADARG { // Аргумент потоку

//     DWORD iTh; // Номер потоку: 0, 1, 3, ...

// } THREADARG, * PTHREADARG;



// static DWORD WINAPI ThFunc(PTHREADARG pThArg);


// static BOOL WINAPI Write(PTHREADARG pThArg);



// static HANDLE* ThreadHandle;



// HANDLE hMutex;



// volatile DWORD M = 0; // Спільний ресурс
// volatile struct node
// {
//     int data;
//     struct node* left;
//     struct node* right;
// };


// int main(int argc, TCHAR* argv[])

// {



//     DWORD NPr, ThId, iTh;

//     PTHREADARG ThArg;

//     NPr = 3; // Кількість потоків



//     // Масив аргументів потоків

//     ThArg = new THREADARG[NPr];

//     // Масив дескрипторів потоків

//     ThreadHandle = new HANDLE[NPr];

//     // Створюємо м’ютекс у вільному стані

//     hMutex = CreateMutex(NULL, FALSE, NULL);



//     // Створити потоки (у призупиненому стані)

//     for (iTh = 0; iTh < NPr; iTh++)

//     {

//         ThArg[iTh].iTh = iTh;

//         ThreadHandle[iTh] = (HANDLE)_beginthreadex

//         (NULL,

//             0,

//             (unsigned int(__stdcall*)(void*))ThFunc,

//             &ThArg[iTh],

//             CREATE_SUSPENDED,

//             (unsigned int*)&ThId);

//     }



//     // Запустити усі призупинені потоки

//     for (iTh = 0; iTh < NPr; iTh++)

//         ResumeThread(ThreadHandle[iTh]);



//     // дочекатися завершення усіх потоків
//     WaitForMultipleObjects(NPr, ThreadHandle, TRUE, INFINITE);        // Без таймаута



//     CloseHandle(hMutex); // Закрити дескриптор

//     // м’ютекса

//     // Закрити дескриптори потоків

//     for (iTh = 0; iTh < NPr; iTh++)

//         CloseHandle(ThreadHandle[iTh]);

//     delete[]ThArg;

//     delete[]ThreadHandle;



//     return 0;



// } // End of _tmain.



// // функція потоків

// DWORD WINAPI ThFunc(PTHREADARG pThArg)

// {

//     if (Write(pThArg)) // Якщо мютекс звільнився

//         // і поточний потік відпрацював,

//         _endthreadex(0); // то завершити потік з

//     // кодом завершення 0

//     return 0;

// }



// // функція роботи зі спільним ресурсом,

// // захищеним м’ютексом

// BOOL WINAPI Write(PTHREADARG pThArg)

// {

//     DWORD dwWaitResult;



//     // Чекаємо звільнення м’ютекса перед тим як

//     // звернутися до спільного ресурсу

//     dwWaitResult = WaitForSingleObject(hMutex,

//         5000L); // 5 секунд на таймаут або INFINITE

//     if (dwWaitResult == WAIT_TIMEOUT) // Таймаут.

//         // М’ютекс за цей час не звільнився

//     {

//         return FALSE;

//     }

//     else // М’ютекс звільнився, і наш потік його зайняв.

//           //Можна працювати.

//     {



//         M += pThArg->iTh;



//         cout << "Write: "

//             << pThArg->iTh

//             << "\t"

//             << "M="

//             << M

//             << endl;



//         ReleaseMutex(hMutex); // Звільняємо м’ютекс

//     }



//     return TRUE;

// }

