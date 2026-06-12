#include "../bits/stdc++.h"
#include "../include/arena_alloc.h"

using namespace std;

//Special Member functions

explicit ArenaAlloc::ArenaAlloc(size_t chunk_size): default_chunk_size(chunk_size){}


ArenaAlloc::ArenaAlloc(const ArenaAlloc&) = delete;
ArenaAlloc& ArenaAlloc::operator=(const ArenaAlloc&) = delete;


ArenaAlloc::ArenaAlloc(ArenaAlloc&&) noexcept = default;
ArenaAlloc& ArenaAlloc::operator=(ArenaAlloc&&) noexcept = default;



//Helper Functions

void* ArenaAlloc::allocate(std::size_t bytes, 
        std::size_t alignment = alignof(std::max_align_t)){
            //tbd...
}

void ArenaAlloc::reset(){
    chunks.clear();
}

size_t ArenaAlloc::used() const{
    size_t usedChunks{};

    for (const auto& chunk : chunks){
        if (!chunk.data) ++usedChunks;
    }

    size_t chunkSize = sizeof(Chunk);

    return usedChunks * chunkSize;
}

size_t ArenaAlloc::capacity() const{
    return chunks.size() * default_chunk_size;
}

size_t ArenaAlloc::chunk_count() const {
    return chunks.size();
}







