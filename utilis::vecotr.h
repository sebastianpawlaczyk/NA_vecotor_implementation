#include <iostream>
#include <initializer_list>

namespace utils{

    template <typename T, std::size_t Capacity>
    class vector{
    public:
        //types:
        using value_type = T; //*second version -> typedef T value_type
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = T*;
        using const_iterator = const T*;

        vector(std::size_t n,const T& val):size_(n) {

            if (n > Capacity) throw std::length_error("Wrong size");

            //for(int i = 0; i <n; i++) values_[i] = val;
            std::fill_n(std::begin(values_), n, val);
        }

        vector(std::initializer_list<T> l):size_(l.size()){
            /*auto itr = std::begin(l);
            for(int i = 0; i < l.size(); i++){
                if(itr == std::end(l)) break;
                values_[i] = *itr;
                itr++;
            }*/
            if(l.size() > Capacity)throw std::out_of_range("Wrong size");
            std::copy(std::begin(l),std::end(l),values_);
        }

        iterator begin(){
            return &values_[0];
        }

        const_iterator begin()const{
            return &values_[0];
        }

        iterator end(){
            return &values_[size_];
        }

        const_iterator end()const{
            return &values_[size_];
        }

        std::size_t size()const{
            return size_;
        }

        std::size_t capacity()const{
            return Capacity;
        }

        reference operator[](std::size_t n){


            if(n > size_ - 1)throw std::out_of_range("Wrong index");

            return values_[n];
        };

        const_reference operator[](std::size_t n)const{


            if(n > size_ - 1)throw std::out_of_range("Wrong index");

            return values_[n];
        };

        reference at(std::size_t index){

            if( index > size_ -1 )throw std::out_of_range("Wrong index");
            return values_[index];
        }

        const_reference at(std::size_t index)const{

            if( index > size_ -1 )throw std::out_of_range("Wrong index");
            return values_[index];
        }

        void resize(std::size_t new_size){

            int i = size_;
            if(new_size > Capacity)throw std::out_of_range("Wrong new_size");
            else if(size_ > new_size)size_ = new_size;
            else{
                size_ = new_size;
                for(i; i < size_; i++){
                    values_[i] = 0;
                }
            }
        }

        void resize(std::size_t new_size, T value){

            if(new_size > Capacity)throw std::out_of_range("Wrong new_size");
            else if (size_ < new_size){
                int i = size_;
                size_ = new_size;
                for(i; i<new_size; i++){
                    values_[i] = value;
                }
            }
            else{
                size_  = new_size;
            }
        }

        void push_back(const T& value){

            if(size_ == Capacity)throw std::out_of_range("Out_of_range");
            size_++;
            values_[size_-1] = value;
        }

        void pop_back() {
            resize(size_-1);
        }


    private:
        std::size_t size_;
        T values_[Capacity];
    };
}
