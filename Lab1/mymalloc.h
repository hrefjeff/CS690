#define LIST_SIZE 4096

typedef struct freelist_node {
    int                     size;  // Size of memory space
    struct freelist_node    *next; // Address of next
} freelist_node;

/*
Header Region is what is associated to a chunk of malloced memory
This is so the free can know exactly how much to release
Example:

 hr->  ______________________
       |                    |
       | size:20            |
 ptr-> ----------------------
       |                    |
       |                    |
       |                    |
       |                    |
       |____________________|

*/
typedef struct header_region {
    int size;
} header_region;

int* mymalloc(freelist_node *n, size_t memsize);
void myfree(void *ptr);
void searchList(freelist_node *n);