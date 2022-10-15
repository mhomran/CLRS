template <class T> 
class Sequence {
    public:

    /**
     * @brief given an iterable X, build sequence from items in X
     * 
     * @param X 
     */
    virtual void Build(T X[], int size) = 0;

    /**
     * @brief Get the item at i
     * 
     * @param i 
     * @return T 
     */
    virtual T GetAt(int i) = 0;

    /**
     * @brief Set the item x at i
     * 
     * @param i 
     * @return int 
     */
    virtual void SetAt(int i, T x) = 0;

    /**
     * @brief Insert Item at the beginning of the sequence
     * 
     * @param x 
     */
    virtual void InsertFirst(T x) = 0;

    /**
     * @brief Delete item at the beginning of the sequence
     * 
     */
    virtual void DeleteFirst(void) = 0;

    /**
     * @brief Insert Item at the end of the sequence
     * 
     * @param x 
     */
    virtual void InsertLast(T x) = 0;

    /**
     * @brief Delete item at the end of the sequence
     * 
     */
    virtual void DeleteLast(void) = 0;

    /**
     * @brief Insert Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void InsertAt(int i, T x) = 0;

    /**
     * @brief Delete Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void DeleteAt(int i) = 0;

    /**
     * @brief print the sequence
     * 
     */
    virtual void Print(void) = 0;

    /**
     * @brief Destroy the Sequence object
     * 
     */
    virtual ~Sequence() {};
};