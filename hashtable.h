/**
 * @author Charles Jackson
 */
#ifndef HASHTABLE_H
#  define HASHTABLE_H

#  define MAX_LOADFACTOR 0.75

#  define defhashtable(name, key_type, value_type)                      \
    typedef struct {                                                    \
        int size;                                                       \
        int length;                                                     \
        struct {                                                        \
            key_type* key;                                              \
            value_type* value;                                          \
        }** table;                                                      \
        int(*keyhash)(key_type);                                        \
        int(*keyequal)(key_type, key_type);                             \
    } name##hashtype;                                                   \
    name##hashtype* name

#  define inithashtable(name, initial_size, key_hash, key_equal)        \
    do {                                                                \
        name = malloc(sizeof(name##hashtype));                          \
        /* length is the length of the internal array */                \
        name->length = initial_size;                                    \
        /* size is how many elements are present */                     \
        name->size = 0;                                                 \
        name->keyhash = key_hash;                                       \
        name->keyequal = key_equal;                                     \
        name->table = calloc(                                           \
            initial_size, sizeof(typeof(name->table[0])));              \
    } while (0)

#  define newhashtable(name, key_type, value_type,                      \
                       initial_size, key_hash, key_equal)               \
    defhashtable(name, key_type, value_type);                           \
    inithashtable(name, initial_size, key_hash, key_equal)

#  define puthash(hash, keyin, valuein)                                 \
    do {                                                                \
        if (hash->size / (double) hash->length >= MAX_LOADFACTOR) {     \
            rehash(hash);                                               \
        }                                                               \
        puthashnorehash(hash, keyin, valuein);                          \
    } while (0)

#  define gethash(hash, keyin, valueout)                                \
    do {                                                                \
        int index = abs(hash->keyhash(keyin)) % hash->length;           \
        int factor = 0;                                                 \
        while (factor <= hash->length) {                                \
            if (hash->table[index] != NULL &&                           \
                hash->keyequal(keyin,                                   \
                               *hash->table[index]->key) == 0) {        \
                valueout = *hash->table[index]->value;                  \
                break;                                                  \
            }                                                           \
            index = (int)((index + pow(2.0, factor))) % hash->length;   \
            ++factor;                                                   \
        }                                                               \
    } while(0)

#  define rehash(hash)                                                  \
    do {                                                                \
        int newsize = hash->length * 2;                                 \
        int oldlength = hash->length;                                   \
        typeof(hash->table) oldtable = hash->table;                     \
        hash->table = calloc(newsize, sizeof(typeof(hash->table[0])));  \
        hash->length = newsize;                                         \
        hash->size = 0;                                                 \
        for (int i = 0; i < oldlength; ++i) {                           \
            if (oldtable[i] != NULL) {                                  \
                puthashnorehash(hash, *oldtable[i]->key,                \
                                *oldtable[i]->value);                   \
            }                                                           \
        }                                                               \
        free(oldtable);                                                 \
    } while(0)

#  define puthashnorehash(hash, keyin, valuein)                         \
    do {                                                                \
        int index = abs(hash->keyhash(keyin)) % hash->length;           \
        int factor = 0;                                                 \
        while (factor < hash->length) {                                 \
            if (hash->table[index] == NULL ||                           \
                (hash->table[index]->key != NULL &&                     \
                 hash->keyequal(keyin,                                  \
                                *hash->table[index]->key) == 0)) {      \
                if (hash->table[index] == NULL) {                       \
                    hash->size += 1;                                    \
                }                                                       \
                hash->table[index] = malloc(                            \
                    sizeof(typeof(hash->table[index])));                \
                hash->table[index]->key = malloc(sizeof(keyin));        \
                *hash->table[index]->key = keyin;                       \
                hash->table[index]->value = malloc(sizeof(valuein));    \
                *hash->table[index]->value = valuein;                   \
                break;                                                  \
            }                                                           \
            index = (int)((index + pow(2, factor))) % hash->length;     \
            ++factor;                                                   \
        }                                                               \
    } while(0)

int isprime(int num);
int hashstr(char*);
int strequal(char*, char*);
int hashint(int);
int intequal(int, int);

#endif  /* HASHTABLE_H */
