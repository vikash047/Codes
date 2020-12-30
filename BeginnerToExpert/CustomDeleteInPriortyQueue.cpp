#include<bits/stc++.h>


using namespace std;

template <class T, class Container = vector<T>, class Compare = less<typename Container::value_type> >
class PQDelete : public priority_queue<T, Container, Compare>
{
    public:
    bool remove(T val) {
        auto it = find(this->c.begin(), this->c.end(), val);
        if(it != this->c.end()) {
            this->c.erase(it);
            make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        return false;
    }
};

int int main(int argc, char const *argv[])
{
    
    cout << "Hello world" << endl;
    return 0;
}
