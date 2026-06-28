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

// Seearch allocator if requested bytes available and allocate
void* ArenaAlloc::allocate(std::size_t bytes, 
        std::size_t alignment = alignof(std::max_align_t)){

            size_t currBytes = bytes;
            size_t begin = -1;
            
            while(currBytes > 0){
                chunks.push_back(add_chunk(default_chunk_size));
                currBytes -= default_chunk_size;
            }

            if (currBytes > 0) return nullptr;

            return &(chunks[begin]);
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

size_t ArenaAlloc::get_available() const {
    size_t availableBytes{};

    for (size_t i{}; i < chunks.size(); ++i){
        if (!chunks[i].data) availableBytes += default_chunk_size;
    }

    return availableBytes;
}







