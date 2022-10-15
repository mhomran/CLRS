
class Set {
    public:
    /**
     * @brief given an iterable X, build set from items in X
     * 
     * @param X 
     * @param size 
     */
    virtual void Build(int X[], int size) = 0;

    /**
     * @brief return the stored item with key k
     * 
     * @param k 
     */
    virtual void Find(int k) = 0;

    /**
     * @brief add x to set (replace item with key x.key if one already exists) 
     * 
     * @param k 
     */
    virtual void Insert(int k) = 0;

    /**
     * @brief remove and return the stored item with key k
     * 
     * @param k 
     */
    virtual void Delete(int k) = 0;

    /**
     * @brief return the stored item with smallest key
     * 
     */
    virtual void FindMin(void) = 0;

    /**
     * @brief return the stored item with largest key
     * 
     */
    virtual void FindMax(void) = 0;

    /**
     * @brief return the stored item with smallest key larger than k
     * 
     * @param k 
     */
    virtual void FindNext(int k) = 0;

    /**
     * @brief return the stored item with largest key smaller than k
     * 
     * @param k 
     */
    virtual void FindPrev(int k) = 0;

    /**
     * @brief Print the Set
     * 
     */
    virtual void Print(void) = 0;

    /**
     * @brief Destroy the Set object
     * 
     */
    virtual ~Set() {};
};