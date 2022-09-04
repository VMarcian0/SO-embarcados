#include <stdio.h>

typedef void (*pf)(void);

typedef struct{
    char *ProcessName;
    int MemoryAloc;
    float ExecutionTime;
    pf Function;
} Process;

#define BUFFER_SIZE 5

Process bufferCircular[BUFFER_SIZE];
int start = 0, end = 0;

void AddProc(char *nProcessName, int nMemoryAloc, float nExecutionTime, pf nFunction){
    // is there space left on the buffer?
    if(((end + 1) % BUFFER_SIZE) != start){
        bufferCircular[end].ProcessName = nProcessName;
        bufferCircular[end].MemoryAloc = nMemoryAloc;
        bufferCircular[end].ExecutionTime = nExecutionTime;
        bufferCircular[end].Function = nFunction;
        // Update the end
        end = (end + 1) % BUFFER_SIZE;
        printf("Process Added!\tstart: %d\t|\tend: %d\n", start, end);
    }
    else printf("Buffer is full!\tstart: %d\t|\tend: %d\n", start, end);
}

void RemProc(void){
    if(start != end){
        start = (start + 1) % BUFFER_SIZE;
        printf("Process Removed!\tstart: %d\t|\tend: %d\n",start, end);
    }
    else printf("Buffer is empty!\tstart: %d|\tend: %d\n", start, end);
}

void ExecProc(void){
    if(start != end){
        bufferCircular[start].Function();
        printf("Finished Process!\n");
    }
    else printf("Buffer is empty!\n");
}

void f1(void){printf("f1\n");}
void f2(void){printf("f2\n");}
void f3(void){printf("f3\n");}

int main(){
    AddProc("Process1", 1024, 0.05, f1);
    AddProc("Process2", 256, 0.01, f2);
    AddProc("Process3", 512, 0.25, f3);
    ExecProc();
    RemProc();
    ExecProc();
    RemProc();
    ExecProc();
    RemProc();
    return 0;
}