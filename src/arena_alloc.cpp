#include "../bits/stdc++.h"

using namespace std;

class ArenaAlloc{
public:

    explicit ArenaAlloc(size_t chunk_size) : default_chunk_size(chunk_size){}


    void* allocate(){}

    void reset(){}

    size_t used() const {};
    size_t capacity() const{};
    size_t chunk_count() const{};


private:
    struct Chunk{
        unique_ptr<byte[]> data;
        size_t size;
        size_t offset;
    };
    vector<Chunk> chunks;
    size_t default_chunk_size;
    Chunk& add_chunk(std::size_t minimum_size);

};