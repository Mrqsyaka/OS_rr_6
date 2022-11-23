#include <windows.h>
#include <iostream>
#include <process.h>
#include <iostream>

using namespace std;
#include <iostream>

using namespace std;


// struct node{
// 	int value;
// 	node *left;
// 	node *right;
// };

// class btree{
// public:
// 	btree();
// 	~btree();

// 	void insert(int key);
// 	node *search(int key);
// 	void destroy_tree();
// 	void inorder_print();
// 	void postorder_print();
// 	void preorder_print();

// private:
// 	void destroy_tree(node *leaf);
// 	void insert(int key, node *leaf);
// 	node *search(int key, node *leaf);
// 	void inorder_print(node *leaf);
// 	void postorder_print(node *leaf);
// 	void preorder_print(node *leaf);

// 	node *root;
// };


// btree::btree(){
// 	root = NULL;
// }

// btree::~btree(){
// 	destroy_tree();
// }

// void btree::destroy_tree(node *leaf){
// 	if(leaf != NULL){
// 		destroy_tree(leaf->left);
// 		destroy_tree(leaf->right);
// 		delete leaf;
// 	}
// }

// void btree::insert(int key, node *leaf){

// 	if(key < leaf->value){
// 		if(leaf->left != NULL){
// 			insert(key, leaf->left);
// 		}else{
// 			leaf->left = new node;
// 			leaf->left->value = key;
// 			leaf->left->left = NULL;
// 			leaf->left->right = NULL;
// 		}
// 	}else if(key >= leaf->value){
// 		if(leaf->right != NULL){
// 			insert(key, leaf->right);
// 		}else{
// 			leaf->right = new node;
// 			leaf->right->value = key;
// 			leaf->right->right = NULL;
// 			leaf->right->left = NULL;
// 		}
// 	}

// }

// void btree::insert(int key){
// 	if(root != NULL){
// 		insert(key, root);
// 	}else{
// 		root = new node;
// 		root->value = key;
// 		root->left = NULL;
// 		root->right = NULL;
// 	}
// }

// node *btree::search(int key, node *leaf){
// 	if(leaf != NULL){
// 		if(key == leaf->value){
// 			return leaf;
// 		}
// 		if(key < leaf->value){
// 			return search(key, leaf->left);
// 		}else{
// 			return search(key, leaf->right);
// 		}
// 	}else{
// 		return NULL;
// 	}
// }

// node *btree::search(int key){
// 	return search(key, root);
// }

// void btree::destroy_tree(){
// 	destroy_tree(root);
// }

// void btree::inorder_print(){
// 	inorder_print(root);
// 	cout << "\n";
// }

// void btree::inorder_print(node *leaf){
// 	if(leaf != NULL){
// 		inorder_print(leaf->left);
// 		cout << leaf->value << ",";
// 		inorder_print(leaf->right);
// 	}
// }

// void btree::postorder_print(){
// 	postorder_print(root);
// 	cout << "\n";
// }

// void btree::postorder_print(node *leaf){
// 	if(leaf != NULL){
// 		inorder_print(leaf->left);
// 		inorder_print(leaf->right);
// 		cout << leaf->value << ",";
// 	}
// }

// void btree::preorder_print(){
// 	preorder_print(root);
// 	cout << "\n";
// }

// void btree::preorder_print(node *leaf){
// 	if(leaf != NULL){
// 		cout << leaf->value << ",";
// 		inorder_print(leaf->left);
// 		inorder_print(leaf->right);
// 	}
// }

// int main(){

// 	//btree tree;
// 	btree *tree = new btree();

// 	tree->insert(10);
// 	tree->insert(6);
// 	tree->insert(14);
// 	tree->insert(5);
// 	tree->insert(8);
// 	tree->insert(11);
// 	tree->insert(18);

// значення 5 - значення, що ти шукаєш if воно є значить елемент входить

//     cout <<tree->search(5)->value;

// 	delete tree;

// }






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

