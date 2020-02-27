# zstructs

Some useful data structures implemented by Zhmylev <KorG> Sergey.

Currently this repo consists of:

* pst    -- pseudo tree to index void ptrs by character keys.
May use per-character hash to reduce memory usage.

* kdh    -- k-D hash, where k = 2. Stores up to X ptrs in statically allocated
chunks, the others are stored in queue.h
