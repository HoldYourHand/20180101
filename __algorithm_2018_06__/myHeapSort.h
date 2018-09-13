#ifndef __MYHEAPSORT_H__
#define __MYHEAPSORT_H__

namespace fjd
{

template<typename T>
class myHeapSort
{
    public:
            myHeapSort()
            : default_size_(20)
            , Heap_((T*)calloc(sizeof(T), default_size_))
            {}
            
            

            ~myHeapSort()
            {
                free(Heap_);
            }

    private:
            int default_size_;
            T *Heap_;
};

}      // fjd

#endif