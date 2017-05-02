// words2.cpp - implements class Words
// (dynamic array version)
//Evan Pieper, 4/30/17

#include <cassert>
#include <string>
#include "words2.h"

using std::string;

namespace lab03_2
{
        Words::Words(unsigned int initial_capacity) {
                used = 0;
                capacity = initial_capacity;
                data = new string[initial_capacity];
        }

        Words::Words(const Words &source)
        {
                used = source.size();
                capacity = source.get_capacity();
                data = new string[capacity];
                for(int i = 0;i<used;i++)
                {
                        data[i] = source.data[i];
                }
        }

        Words::~Words()
        {
                delete [] data;
        }

        Words& Words::operator=(const Words &source)
        {
                if(this == &source){return *this;}
                if(capacity >= source.get_capacity())
                {
                        used = source.size();
                        //for(int i = used +1;i<capacity;i++)
                        //{
                                delete [] data;
                                data = new string[source.size()];
                        //}
                        for(int i = 0;i<used;i++)
                        {
                                data[i] = source.data[i];
                        }
                        return *this;
                }
                data = new string[source.get_capacity()];
                used = source.size();
                //for(int i = used +1;i<capacity;i++)
                //{
                        delete [] data;
                        data = new string[source.size()];
                //}
                for(int i = 0;i<used;i++)
                {
                        data[i] = source.data[i];
                }
                return *this;
        }

    void Words::append(string word) {
        if(used >= capacity)
        {
                string *temp = new string[capacity + 1];
                for(int i = 0;i<used;i++)
                {
                        temp[i] = data[i];
                }
                temp[capacity-1] = word;
                delete [] data;
                data = new string[capacity +1];
                used++;
                for(int i = 0;i<capacity +1;i++)
                {
                        data[i] = temp[i];
                }
                delete [] temp;

        }
        else
        {
                data[used] = word;
                ++used;
        }


    }

    string& Words::operator[] (unsigned int index) {
        assert(index < used);
       return data[index];
    }

    unsigned int Words::size() const {
        return used;
    }

    unsigned int Words::get_capacity() const {
        return capacity;
    }

    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
    }

}
                                                                             1,1           Top
