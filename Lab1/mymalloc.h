#define LIST_SIZE 1024

/*
Header Region is what is associated to a chunk of malloced memory
This is so the free can know exactly how much to release
Example:

 hr->  ______________________
       | addr:0x590293      |
       | size:20            |
 ptr-> ----------------------
       |                    |
       |                    |
       |                    |
       |                    |
       |____________________|

*/
typedef struct header_region {
    unsigned int addr;
    unsigned int size;
} header_region;

typedef struct node {
    int          size;  // Size of memory space
    struct node* next; // Address of next
} node;

// Utility functions
node* getFreeListHead();
void setFreeListHead(node* n);
int initializeList();
void printList(node* n);

void* myMalloc(size_t memsize);
void myFree(void* ptr);
node* firstFitSearch(node* n, size_t memsize);