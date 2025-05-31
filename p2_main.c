#include <stdio.h>
#include <stdlib.h>

struct Q {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    int *Array;
};
typedef struct Q *Queue;                                         //Welcome to my Program//
/////////////////////////////////////////////////            //////Mohammad omar : 1212429//////
struct node;
typedef struct node* Node;
struct node{
    Queue data;
    Node next;
};
typedef Node Stack;
/////////////////////////////////////////////////
struct inode;
typedef struct inode* ptr;
struct inode{
    int data;
    ptr next;
};
typedef ptr sstack;
/////////////////////////////////////////////////
struct iinode;
typedef struct iinode* pptr;
struct iinode {
    int loser;
    int winner;
    pptr next;
};
typedef pptr stack3 ;
///////////////////////////////////////////////////////////////////
Stack createStack();                                          // createStack 1
void push(Stack Top, Queue q);                                // push 1
void pop(Stack Top);                                          // pop 1
int isEmpty(Stack Top);                                       // isEmpty 1
Queue top(Stack Top);                                         // top 1
sstack createIntStack();                                      // createIntStack 2
void ppush(sstack Top, int value);                            // push 2
void ppop(sstack Top);                                        // pop 2
int iisEmpty(sstack Top);                                     // isEmpty 2
int ttop(sstack Top);                                         // top 2
pptr createPairStack();                                       // createPairStack 3
void pppush(stack3 Top, int loser_idx, int winner_idx);       // push 3
void pppop(stack3 Top);                                       // pop 3
int iiisEmpty(stack3 Top);                                    // isEmpty 3
void makePairStackEmpty(stack3 Top);                          // makeEmpty 3
Queue CreateQueue(int MaxElements);                           // CreateQueue
void DisposeQueue(Queue Q);                                   // Dispose
void MakeEmpty(Queue Q);                                      // makeEmpty
int IsEmpty(Queue Q);                                         // isEmpty
void Enqueue(int X, Queue Q);                                 // Enqueue
int FrontAndDequeue(Queue Q);                                 // FrontAndDequeue
int DequeueRear(Queue Q);                                     // DequeueRear
int Succ(int Value, Queue Q);                                 // Successor
int Prev(int Value, Queue Q);                                 // Previous
void tournament(Queue Q, int* champion_id, int* runner_up_id);//tournament
//////////////////////////////////////////////////////////////////////////////////////
stack3 result = NULL;

int main() {

    Stack cases = createStack();
    printf("(----------Welcome to our tournament----------)\n");
    int n;
    scanf("%d", &n);
    while (n != -9999) {

        Queue q = CreateQueue(n);
        if (IsEmpty(q)) {
        for (int i = 0; i < n; i++) {             // we have 3 deferent stacks the first one , when the user enter a line of teams id then
        int id;                                   // we move them to an queue then we push this queue to an the main and the first stack
        scanf("%d", &id);                         // then we start our program by make the user entering a number , when we found the number -9999 the program will exit and give us the output
        Enqueue(id, q);                           // we define the next type of stack , its a global one , and will hold the champion and the runner up for each game
        }                                         // for stack 2 will content only one data , that will be the winner and the real runner
        push(cases, q);
        scanf("%d", &n);
        }
        else{ printf("out of space");
        }

    }
        ptr champions = createIntStack();
        ptr runnerUp = createIntStack();

    while (!isEmpty(cases)) {
        Queue q = top(cases);
        pop(cases);                                // know we will start by see if the main stack 1 content the queues or not , then we will start
        result = createPairStack();                // pop one q each time , or each game , then we define an id for the champion and for the real runner ,a and give it
        int IDchampion;                            // to the only one function in the program , we will give her the id for runner up and for the champion
        int IDrunner_Up;                           // and also will give her a the first queue in the first stack , this function called tournament
        tournament(q, &IDchampion, &IDrunner_Up);  // we will explain the tournament function later on
        ppush(champions, IDchampion);              // after the function is done we push the id of the champion to the stack 2 , that content node of data
        ppush(runnerUp, IDrunner_Up);              // free the this queue to make a space on the memory , and free the global stack ,,,,, global stack , is an stack from type
        DisposeQueue(q);                           // from type 3 that we will recored and hold the id of the winner , and the ids of the teams who lose from them
        free(result);                              // when we go to the tournament function we will take about who we record them in the stack
                                                   // go back to the main stack that hold the queue and push one queue and repeat till the stack cases that hold them is empty
    }
        printf("Champions and RunnerUps:\n");      // when all the tournament are done , and stack 2 that hold the winners and the runner we need to print them
    while (!iisEmpty(champions) && !iisEmpty(runnerUp)) {

        int championID = ttop(champions);          // first check the if both stack are empty or not , with there special function
        ppop(champions);                           // if not just we need to pop the element from them , by make tow integers that look for the top of both stack and pop them then print them
        int runnerID = ttop(runnerUp);
        ppop(runnerUp);
        printf("Champion: %d, Runner-Up: %d\n", championID, runnerID);
    }

    return 0;
}

//////////////////////////////////////Stacks functions///////////////////////////////////////
Stack createStack(){                               //function to make an stack of type struct node , the node are a queues
    Stack S;
    S = (Stack)malloc(sizeof(struct node));
        if (S == NULL) {
        printf("stack is not created check the malloc function\n");
    }   else {
        S->next = NULL;
    }
    return S;
}////////////////////////////////////////////////////////////////////////////////////////////
void push(Stack Top, Queue q){                  // function that take a queue and push it to the main stack of type node
    Node newNode = (Node)malloc(sizeof(struct node));
        if (Top == NULL) {
        printf("there is no stack\n");
    }   else if (newNode == NULL) {
        printf("no space *_*\n");
    }

        newNode->data = q;
        newNode->next = Top->next;
        Top->next = newNode;
}
////////////////////////////////////////////////////////////////////////////////////////////
void pop(Stack Top){                             // function that pop a queue from the main stack of type node
    Node temp;

        if (Top == NULL) {
        printf("Stack Not Found..\n");
    }   else if (isEmpty(Top)) {
        printf("Stack Underflow, Nothing to delete..\n");
    }
        temp = Top->next;
        Top->next = temp->next;
        free(temp);
}
////////////////////////////////////////////////////////////////////////////////////////////
int isEmpty(Stack Top){                           // function to check if the main stack of type node , that conten a queue is empty or not
    return (Top->next == NULL);
}
////////////////////////////////////////////////////////////////////////////////////////////
Queue top(Stack Top){                             // this function will return the top queue in the main stack of type node
        if (Top == NULL) {
        printf("stack are not found\n");
    }   else if (isEmpty(Top)) {
        printf("stack is empty\n");
    }
    return Top->next->data;
}
////////////////////////////////////////////////////////////////////////////////////////////
sstack createIntStack(){                          // know we start the next creation for the stack 2 that hold the winner and the runner up IDs , from type inode
    ptr S;
    S = (ptr)malloc(sizeof(struct inode));
         if (S == NULL) {
         printf("stack is not created check the malloc function\n");
    }    else {
         S->next = NULL;
    }
    return S;
}
////////////////////////////////////////////////////////////////////////////////////////////
void ppush(ptr Top, int value){                  // this function will push an integer to the stack 2 of type inode
    sstack newNode = (sstack)malloc(sizeof(struct inode));
        if (Top == NULL) {
        printf("stack are not found\n");
    }   else if (newNode == NULL) {
        printf("Out of space\n");
    }
        newNode->data = value;
        newNode->next = Top->next;
        Top->next = newNode;
}
////////////////////////////////////////////////////////////////////////////////////////////
void ppop(sstack Top){                             // a function to pop an integer from the stack 2 of type inode , we will use it when we finish our program and print the result on screen
       ptr temp;
    if (Top == NULL) {
        printf("Integer Stack Not Found..\n");
    }   else if (iisEmpty(Top)) {
        printf("Integer Stack Underflow, Nothing to delete..\n");
    }
        temp = Top->next;
        Top->next = temp->next;
        free(temp);
}
////////////////////////////////////////////////////////////////////////////////////////////
int iisEmpty(sstack Top){                          //function to check if the stack of type inode is empty or not
    return (Top->next == NULL);
}
////////////////////////////////////////////////////////////////////////////////////////////
int ttop(sstack Top){                              // this function will return the top integer in the second stack of type inode
    if (Top == NULL) {
        printf("Integer Stack Not Found..\n");
    } else if (iisEmpty(Top)) {
        printf("Integer Stack is empty, Nothing to return..\n");
    }
    return Top->next->data;
}
////////////////////////////////////////////////////////////////////////////////////////////
pptr createPairStack(){                              // now we will start the third stack from type iinode , that hold an the id of the winner and how lose from him , to play the next game of the runner tournament
    stack3 S;
    S = (pptr)malloc(sizeof(struct iinode));
    if (S == NULL) {
        printf("Could not create pair stack. Stack is not found..\n");
    } else {
        S->next = NULL;
    }
    return S;
}
////////////////////////////////////////////////////////////////////////////////////////////
void pppush(stack3 Top, int loser, int winner){      // a function that will push the winner and the loser integer id to the third stack , of type iinode
    pptr newNode = (stack3)malloc(sizeof(struct iinode));
    if (Top == NULL) {
        printf("Pair Stack Not Found..\n");
    } else if (newNode == NULL) {
        printf("Out of space..\n");
    }
        newNode->loser = loser;
        newNode->winner = winner;
        newNode->next = Top->next;
        Top->next = newNode;
}
////////////////////////////////////////////////////////////////////////////////////////////
void pppop(stack3 Top){                             // a function to pop a pair of the third stack of type iinode
    pptr temp;
    if (Top == NULL) {
        printf("Pair Stack Not Found..\n");
    } else if (iiisEmpty(Top)) {
        printf("Pair Stack Underflow, Nothing to delete..\n");
    }
       temp = Top->next;
       Top->next = temp->next;
       free(temp);
}
////////////////////////////////////////////////////////////////////////////////////////////
int iiisEmpty(stack3 Top){                        // a function to check if the third stack , that contain a pair is empty or not
    return (Top->next == NULL);
}
////////////////////////////////////////////////////////////////////////////////////////////
void makeItEmpty(stack3 Top){                     // this is the new function that it does not contain in other stacks function , since after we determine the winner and the runner up of the first game
        if (Top == NULL) {                        // the third stack will be contain a winner and who lose from it , so we do not want to overwrite of the stack , of free it and create it another time
        printf("Pair Stack Not Found..\n");       // we only make him empty to use , for another game
    return;
    }   else if (iiisEmpty(Top)) {
    return;
    }
    while (!iiisEmpty(Top)) {
        pppop(Top);
    }
}
////////////////////////////////////////////Queue Functions ////////////////////////////////
Queue CreateQueue(int MaxElements) {
    Queue Q;
    Q = (Queue)malloc(sizeof(struct Q));
        if (Q == NULL) {
        printf("Out of space!\n");                 // function to create a queue (one important think that ,(( the queue implementation an circular arrays))
    return NULL;}
    Q->Array = (int*)malloc(sizeof(int) * MaxElements);
        if (Q->Array == NULL) {
        printf("Out of space!\n");
        free(Q);
    return NULL;
    }   Q->Capacity = MaxElements;
        MakeEmpty(Q);
    return Q;
}
////////////////////////////////////////////////////////////////////////////////////////////
int IsEmpty(Queue Q) {                      // function to check if the queue is empty or not
    return Q->Size == 0;
}
////////////////////////////////////////////////////////////////////////////////////////////
void DisposeQueue(Queue Q) {               // function to free the queue
    if (Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
void MakeEmpty(Queue Q) {                   // function to make the queue empty ((not) free it and delete it)
       Q->Size = 0;
       Q->Front = 0;
       Q->Rear = -1;
}
////////////////////////////////////////////////////////////////////////////////////////////
int Succ(int Value, Queue Q) {              // successor
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}
////////////////////////////////////////////////////////////////////////////////////////////
int Prev(int Value, Queue Q) {              // previous
    if (Value == 0)
        Value = Q->Capacity - 1;
    else
        Value--;
    return Value;
}
////////////////////////////////////////////////////////////////////////////////////////////
void Enqueue(int X, Queue Q) {              // function for push or enqueue to the queue
    if (Q->Size == Q->Capacity) {
        printf("Full Queue\n");
    } else {
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
        Q->Size++;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
int FrontAndDequeue(Queue Q) {              // FrontAndDequeue function to take the front value
    int X = 0;
    if (IsEmpty(Q)) {
        printf("Empty Queue!\n");
    } else {
        X = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);
        Q->Size--;
    }
    return X;
}
////////////////////////////////////////////////////////////////////////////////////////////
int DequeueRear(Queue Q) {              // function to dequeue from Rear
        int value = Q->Array[Q->Rear];
        Q->Rear = Prev(Q->Rear, Q);
        Q->Size--;
        return value;
    }
//////////////////////////////////////// Tournament function/////////////////////////////////
void tournament(Queue Q, int* champion_id, int* runner_up_id) {
    // Initialize teams
        int n = Q->Size;                                  // Finally the main function of this project is the tournament
        int teams_id[n];                                  // this function will take an tow integer and a queue to determine the runnerUp champion
        int index = 0;                                    // starting by make tow integer n that will be the size of the queue and an array that have the also the size of the queue , so the array will contain the ID teams
    Queue temp = CreateQueue(Q->Capacity);                // create an temp queue , take the front number and dequeue it to the team id integer
    if (temp== NULL) {                                    // we need to copy the queue to an temp ,because we need to put an array to store each team in his index
        printf("error");                                  // and after we copy it and move the team id to an array , then we need to get back our queue the original one
    }
    while (!IsEmpty(Q)) {
        int team_id = FrontAndDequeue(Q);
        teams_id[index] = team_id;
        Enqueue(team_id, temp);
        index++;
    }

    while (!IsEmpty(temp)) {
        Enqueue(FrontAndDequeue(temp), Q);                 // and after we copy it and move the team id to an array , then we need to get back our queue the original one
    }
        DisposeQueue(temp);                                // then just free the temp queue , but we know have the array contain the same element of the queue and there index , so the real queue not affect
                                                           // starting up by create tow queues , for the first round , and the other queue will be for the other rounds
        Queue current_round = CreateQueue(n);              // sure that the size of them is the same as the real one
        Queue next_round = CreateQueue(n);
    for (int i = 0; i < n; i++) {                          // adding an index number to the currant queue so that we can use the team array
        Enqueue(i, current_round);
    }
        int round = 1;
        int champion_index ;

    while (1) {
        int teams_in_current_round = current_round->Size;  // going to an infinite loop to reach the final round and detect the champion
                                                           // assign an integer value of the size of the real queue but we assign it as it in the currant round , since we need to dequeue from it
        if (teams_in_current_round == 1) {                 //check if there is only 1 team in the currant round , if is just , get off the infinite loop
            champion_index = FrontAndDequeue(current_round);
            break;
        }

                                                           //test case to see if the teams in the currant round are odd or even , if its odd , then we need to call a function to take the rear integer and put it in the front queue of the next round
        if (teams_in_current_round % 2 == 1) {
            int last = DequeueRear(current_round);         // Remove last team
            Enqueue(last, next_round);                     // Place at rear of next round
        }
    while (!IsEmpty(current_round)) {                      // match start by taking tow team from the front of the queue
           int idx1 = FrontAndDequeue(current_round);      // assign an winner index and a loser index to detect , who play whith the winner
           int idx2 = FrontAndDequeue(current_round);      // if the round is even , then the team with bigger number , go tot he next queue
           int winnerdx, lossedx;                          // if the round is odd , then the team with a less number , will go to the next round , so the round is the counter index
        if (round% 2 == 1) {
        if (teams_id[idx1] < teams_id[idx2]) {             // know we need to use our array for comparison , the array that taken a place in the bigging of the code
           winnerdx = idx1;                                // if the first number is bigger than the another number , then we will assign the winner and the loser else if it smaller , or if the round is even number then we will take the number that he is bugger
           lossedx = idx2;
        } else {
           winnerdx = idx2;
           lossedx = idx1;
                }
        } else {
        if (teams_id[idx1] > teams_id[idx2]) {
           winnerdx = idx1;
           lossedx = idx2;
        } else {
           winnerdx = idx2;
           lossedx = idx1;
                }
            }
            pppush(result, lossedx, winnerdx);              // Record match result on the global stack (stack 3 iinode)
            Enqueue(winnerdx, next_round);                  // the winner will go forward to the next round by enqueue the winner to the next round queue
        }                                                   // after finish the first round , the while loop will stop , since the currant round element is empty
                                                            // so we finish the first round , we need to swap the queues , assign temp queue for the currant round
            Queue temp = current_round;                     // and make the currant round equal the next round , to make the next round queue empty
            current_round = next_round;                     // so that the the currant round will be the queue of the next round value , and the next round will be empty and go forward to tot next round in infinite loop
            next_round = temp;
            MakeEmpty(next_round);
        round++;
    }
            *champion_id = teams_id[champion_index];         // get the  champion id as a pointer ..... when the final round finish , champion index , will have the value of the champion , thus we can get it as a pointer from the teams ID array and take off the function

            int candidate[n];                                // we need to collect the runner up candidates
            int count = 0;
            stack3 current = createPairStack();
            current = result->next;                          // take the first node of the global stack
                                                             // know we need to find the loser from the winner , by create an stack type iinode and an array to store the index and store the teams on it
    while (current != NULL) {                                // if the node in global stack that point to the winner , equal the the champion , then put in the array the loser of the champion
        if (current->winner == champion_index) {
            candidate[count++] = current->loser;
        }
            current = current->next;                          // go to the another node in the global stack
    }
            int runner_up;
            if (count == 1) {                                 // if there is only one lose from the winner , then we is the runner up
            runner_up = candidate[0];
           *runner_up_id = teams_id[runner_up];
    } else {                                                  // start our runner up tournament
            MakeEmpty(current_round);                         // before we start we need to make both the currant and the next round , empty
            MakeEmpty(next_round);
        for (int i = 0; i < count; i++) {                     // pop from the array each index to the queue currant round
            Enqueue(candidate[i], current_round);
        }

            round = 1;                                         // start the round with 1 ,,,,,, the roles is the same think , but the different that its easy to pick the winner since we do not need to track the winner and the losser

        while (1) {
            int teams_in_current_round = current_round->Size;  // make our infinte loop till we find the real winner , and all the code be the same as before

            if (teams_in_current_round == 1) {
               runner_up = FrontAndDequeue(current_round);
                break;
            }
            if (teams_in_current_round % 2 == 1) {
                int last_team = DequeueRear(current_round);
                Enqueue(last_team, next_round);
            }
            while (!IsEmpty(current_round)) {
                int idx1 = FrontAndDequeue(current_round);
                int idx2 = FrontAndDequeue(current_round);
                int winner_idx;
                if (round % 2 == 1) {
                    if (teams_id[idx1] < teams_id[idx2]) {
                winner_idx = idx1;
                    } else {
                winner_idx = idx2;
                    }
                } else {
                    if (teams_id[idx1] > teams_id[idx2]) {
                        winner_idx = idx1;
                    } else {
                        winner_idx = idx2;
                    }
                }
                Enqueue(winner_idx, next_round);
            }
                Queue temp = current_round;
                current_round = next_round;
                next_round = temp;
                MakeEmpty(next_round);

            round++;
        }
              *runner_up_id = teams_id[runner_up];
    }

}
