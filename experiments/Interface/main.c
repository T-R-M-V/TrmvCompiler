//==================================================================================================================
//------------------------------------------------------------------------------------------------------------------
// TESTING FOR INTERFACES
//------------------------------------------------------------------------------------------------------------------
//
//
//------------------------------------------------------------------------------------------------------------------
// This simple file is a test to understand what we need to write in Target language to support multiple
// interfaces. 
//------------------------------------------------------------------------------------------------------------------
//
//
//------------------------------------------------------------------------------------------------------------------
// Points to reason about:
//  - watch this resource to learn more about that: https://www.cs.rit.edu/~ats/books/ooc.pdf
//  - probably all the virtual function must go under this data structure.
//------------------------------------------------------------------------------------------------------------------
//==================================================================================================================

// Necessary for HashMap implementation (START)
#include <malloc.h>
#include <string.h>
// Necessary for HashMap implementation (END)





//==================================================================================================================
//------------------------------------------------------------------------------------------------------------------
// HashMap usable like virtual pointer table
//------------------------------------------------------------------------------------------------------------------
// We can use this hashmap to retrieve the pointer to virtual function.
// NOTE: If we want to use a data structures to handle the pointer to virtual function, we must
// hide that from the rest of source code. We can use a very rare name or something like a private
// name and hide in some manner the files.  
// NOTE: Probably there is a better option to save this data and retrieve that, it's only a try to
// show that probably is possible to write Target C code to save a virtual function pointer table.
// NOTE: Probably we can give a numeric identifier to the virtual functions and order the elements
// on the base of the identifier. In this manner we can perform a retrieve of pos not in O(n) but
// in O(log(n)).
struct Element {
    const char* identifier;
    const void* virtualFunctionPointer;
};

struct HashMap {
    struct Element* elements;
    unsigned int size;

    // NOTE: That can be useful in future to minimize the number of reallocations
    //unsigned int capacity;
};



// void allocateMemory(const struct HashMap*, unsigned int);
// int retrieveIndexFromIdentifier(struct HashMap*, const char*);
// int insertInHashMap(const char* const, void*);



// This function is necessary to handle the storage of this data structure
void allocateMemory(struct HashMap* this, unsigned int virtualFunctionsToStore) {

    if(this->elements == NULL)
        free(this->elements);

    this->elements = (struct Element*)malloc(sizeof(void*) * virtualFunctionsToStore);
    this->size = virtualFunctionsToStore;
}

// This function is useful to retrieve the position of an identifier from the index.
// Return the position in the elements buffer if the identifier is saved in this HashMap.
// Return -1 if the identifier isn't found
int retrieveIndexFromIdentifier(struct HashMap* this, const char* identifier) {
    int pos;

    for(pos = 0;pos < this->size; pos++) {
        struct Element* element = &(this->elements[pos]);
        
        if(strcmp(identifier, element->identifier) == 0) 
            return pos;
    }

    return -1;
}

// This function must handle the collision and send an error in some manner...
// We want to handle the collision cause we know that collision between names of virtual pointer function must
// not be redundant.
// NOTE: the handling of error is useful only during the production of the language, so we can offer a debug version
// of this HashMap and a release version.
int insertInHashMap(struct HashMap* this, const char* const identifier, void* virtualFunctionPointer) {

    if (retrieveIndexFromIdentifier(this, identifier) >= 0)
        return -1;

    unsigned int previousSize = this->size;
    allocateMemory(this, previousSize+1);
    struct Element* new_element = &(this->elements[previousSize]);
    new_element->identifier = identifier;
    new_element->virtualFunctionPointer = virtualFunctionPointer;

    return 0;
}


// This function get the virtual function pointer from the identifier.
// This function use retrieveIndexFromIdentifier function to retrieve the position in the buffer of elements.
// NOTE: This function probably must stop if the pos is < 0,
const void* getVirtualFunctionPointerFromIdentifier(struct HashMap* this, const char* const identifier) {
    int pos = retrieveIndexFromIdentifier(this, identifier);

    // TODO: Add check for the value of pos

    return this->elements[pos].virtualFunctionPointer;
}
//==================================================================================================================

// Base class for virtual object
// NOTE: reason about the fact that we can insert this in all the object with an optional
// virtual function pointer table field. We can use this to store an integer that identifies
// uniquely a type in the codebase.
// NOTE: i choiced to store a pointer to a shared vtable. I thinked that this is better to
// mantain the size of object limited. We know the size of this table at runtime, so we can
// directly store the right quantity of pointers.
// For now i choiced the more simple strategy... 
struct Object {
    struct HashMap* vtable;
};





int main() {




    return 0;
}