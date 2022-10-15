#include "set.hpp"
#include "../sequence/array_seq.hpp"

class SortedArraySet : public Set {
    ArraySeq A;

    public:
    SortedArraySet();
    ~SortedArraySet();
    
    /**
     * @brief given an iterable X, build set from items in X
     * 
     * @param X 
     * @param size 
     */
    virtual void Build(int X[], int size);

    /**
     * @brief return the stored item with key k
     * 
     * @param k 
     */
    virtual void Find(int k);

    /**
     * @brief add x to set (replace item with key x.key if one already exists) 
     * 
     * @param k 
     */
    virtual void Insert(int k);

    /**
     * @brief remove and return the stored item with key k
     * 
     * @param k 
     */
    virtual void Delete(int k);

    /**
     * @brief return the stored item with smallest key
     * 
     */
    virtual void FindMin(void);

    /**
     * @brief return the stored item with largest key
     * 
     */
    virtual void FindMax(void);

    /**
     * @brief return the stored item with smallest key larger than k
     * 
     * @param k 
     */
    virtual void FindNext(int k);

    /**
     * @brief Print the Set
     * 
     */
    virtual void Print(void);

    /**
     * @brief return the stored item with largest key smaller than k
     * 
     * @param k 
     */
    virtual void FindPrev(int k);
};