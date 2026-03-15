struct buf {
  int valid;             // has data been read from disk?
  int disk;              // does disk "own" buf?
  uint dev;              // device
  uint blockno;          // block number
  struct sleeplock lock; // lock
  uint refcnt;           // block reference count
  struct buf *prev;      // LRU cache list
  struct buf *next;
  uchar data[BSIZE];
};
