#define LIST_SIZE 4096

typedef struct freelist_node {
    int                     size;  // Size of memory space
    struct freelist_node    *next; // Address of next
}

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


void* mymalloc(size_t memsize){
    // find chunk of mem
    // split it
    // first chunk: put header info on 
    // second chunk: remain on the list
}

void myfree(void *ptr){
    header_region *hptr = (void *)ptr - sizeof(header_region); // this points to size
    int size_of_chunk = hptr->size;
    // update list with this info
}

// Splitting - When allocation occurs, the allocator needs to find a free
//             chunk of memory that can satisfy the request and split it into two
//             The first chunk it will return to the caller
//             The second chunk will remain on the list
//             Request for 1byte: return addr of byte, and then update list

// Coallescing - When memory is freed, look at the addr you are returning as well as
//               nearby chunks of free space; if the newly freed space sits right next to one (or two)
//               existing free chunks, merge them into a single larger free chunk.
//               Update the list accordingly