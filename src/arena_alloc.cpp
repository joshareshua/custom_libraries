#include "../bits/stdc++.h"

using namespace std;

class ArenaAlloc{
public:

    explicit ArenaAlloc(size_t chunk_size) : default_chunk_size(chunk_size){}

    ArenaAlloc(const ArenaAlloc&) = delete;
    ArenaAlloc& operator=(const ArenaAlloc&) = delete;
    
    ArenaAlloc(ArenaAlloc&&) noexcept = default;
    ArenaAlloc& operator=(ArenaAlloc&&) noexcept = default;

    void* allocate(){}

    void reset(){}


private:
    struct Chunk{
        //to be implemented...
    };
    vector<Chunk> chunks;
    size_t default_chunk_size;
    Chunk& add_chunk(std::size_t minimum_size);

};