#ifndef MAXHEAP_PRINTJOB_H
#define MAXHEAP_PRINTJOB_H

using namespace std;

class PrintJob {
private:
    int priority;
    int jobNumber;
    int numPages;

public:
    PrintJob ( int, int, int);
    int getPriority ( );
    int getJobNumber ( );
    int getPages ( );
    //You can add additional functions here
};

#endif //MAXHEAP_PRINTJOB_H
