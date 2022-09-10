# vector
memory safe generic vector running in C.
Uses typeof so isn't compliant with the C standard, but could be made to take the type as an argument with light modification.

Usage example in the main file, custom structures can be used as long as they have a pointer to an array named arr and an integer for length called len.
Basic vectors can be made automatically of any type, including structs, with the vector(T) command, they will be named {T}Vector.
Elements can be added to or removed from vectors with the push_back and remove_at commands.=
Use the inbuilt commands on their own in a line, rather than making anythihngh equal to it:
```
make_vec(myVector, someType);
push_back(myVector, 12);
```
NOT
```
someTypeVector myVector = make_vec(someType);
myVector = push_back(myVector, 12);
```
This holds true for all functions relating to vectors as they are macros rather than true functions, so values cannot be equal to them.

They are memory safe to the extent of my testing, although they may encounter issues in large use cases, and they will automatically close the program with an exit code of 2 if memory reallocation fails.
I would advise only using specialised vector structs rather than adding extra values within the vector struct, although the code will work, because the default constructor and destructor will not deal with variables other than arr and len. So:
```
typedef struct {
  intVector values;
  charVector keys;
  } intCharDict;
```
rather than
```
typedef struct {
  int* arr;
  int len;
  char* keys;
  } intCharDict;
```
as in this example char* keys would be left unallocated with the default constructor, and if memory was allocated, would cause memory to leak with the default constructor. As such, if you use vectors made with anything but the default vector(T) or you use a struct with allocated memory within it as T I would advise creating custom constructors and destructors.
Beyond constructors and destructors, this will work with any type, including custom types, including vectors of vectors, although the names become unweildy quickly.
