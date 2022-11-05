/*
    Grupo 25%
        Membros:
            Victor T. S. Marciano : 180131
            Vinicius Ibanez Alves: 180023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 10
#define LOOP 0 // 1 if kernel should loop | 0 if should stop at 100 iteration

typedef char *(*pf)();

typedef struct node
{
    pf Function;
    int pid;
    int frequency; // n=0 not repeating | n<0 repeating
    int priority;  // the grater the more important
    struct node *next;
} node;

int getBufferSize(node **head)
{
    node *current = *head;
    int counter = 0;
    while (current->next != NULL)
    {
        counter += 1;
        current = current->next;
    }

    return counter + 1;
}

char *addInitialProcess(node **head, node **tail, pf function, int pid, int frequency, int priority)
{
    printf("Adding Initial Process | PID:%d\n", pid);
    node *new_node;
    new_node = (node *)malloc(sizeof(node));

    new_node->Function = function;
    new_node->pid = pid;
    new_node->next = NULL;
    new_node->frequency = frequency;
    new_node->priority = priority;
    *head = new_node;
    *tail = new_node;

    return "SUCCESS";
}

char *addProcess(node **head, node **tail, pf function, int pid, int frequency, int priority)
{

    printf("Adding Process | PID:%d\n", pid);
    if (getBufferSize(head) >= BUFFER_SIZE)
    {
        printf("Error: Buffer is full\n");
        return "FAILURE";
    }
    else
    {
        node *current = *tail;
        int counter = 0;

        current->next = (node *)malloc(sizeof(node));
        *tail = current->next;
        current->next->pid = pid;
        current->next->Function = function;
        current->next->frequency = frequency;
        current->next->priority = priority;
        current->next->next = NULL;
        return "SUCCESS";
    }
}

pf removeProcess(node **head, int* frequency, int* priority)
{
    printf("Removing process | PID:%d\n", (*head)->pid);
    pf function = NULL;
    node *next_node = NULL;

    if (*head == NULL)
    {
        return NULL;
    }

    next_node = (*head)->next;
    function = (*head)->Function;
    *frequency = (*head)->frequency;
    *priority = (*head)->priority;
    free(*head);
    *head = next_node;

    return function;
}

char *function1()
{
    printf("Running Function 1\n");
    return "REPEAT";
}

char *function2()
{
    printf("Running Function 2\n");
    return "END";
}

char *function3(void)
{
    printf("Running Function 3\n");
    return "END";
}

char *function4(void)
{
    printf("Running Function 4\n");
    return "REPEAT";
}

char *function5(void)
{
    printf("Running Function 5\n");
    return "REPEAT";
}

void executeProcess(node **head, node **tail)
{
    char *reschedule;
    int frequency, priority;
    pf function = removeProcess(head, &frequency, &priority);
    if (function != NULL)
    {
        reschedule = function();
        if (strcmp(reschedule, "REPEAT") == 0)
        {
            printf("FREQUENCY %i\tPRIORITY %i\n", frequency, priority);
            printf("Rescheduling Process\n");
            addProcess(head, tail, function, rand() % 100, frequency, priority);
        }
    }
}

int main()
{

    srand(time(NULL));
    int loop = LOOP;

    printf("##### Starting the Kernel #####\n\n");
    int counter = 0;
    node *head = NULL;
    node *tail = NULL;

    // head = (node *) malloc(sizeof(node));
    printf("Add Process: %s\n\n", addInitialProcess(&head, &tail, function1, 1, 0, 1));
    printf("Add Process: %s\n\n", addProcess(&head, &tail, function2, 2, 2, 2));
    printf("Add Process: %s\n\n", addProcess(&head, &tail, function3, 2, 3, 4));
    printf("Add Process: %s\n\n", addProcess(&head, &tail, function4, 4, 5, 1));
    printf("Add Process: %s\n\n", addProcess(&head, &tail, function5, 5, 5, 1));

    int pid = getBufferSize(&head);
    while (counter >= 0)
    {
        if (head->next != NULL)
        {
            executeProcess(&head, &tail);
            printf("\n\n");
        }
        else
        {
            pid = -1;
        }
        counter += 1;
        if (loop == 0 && counter >= 100)
        {
            counter = -1;
        }
    }

    printf("##### Kernel session closing ##### \n");
}
