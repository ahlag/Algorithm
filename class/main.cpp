#include <iostream>

using namespace std;

class Date {
public:
    Date(int yy, int mm, int dd);
    class Invalid {};
    void add_day(int n);
    int month() { return m; }
    int day() { return d; }
    int year() { return y; }
private:
    int y, m, d;
    bool is_valid();
};

Date::Date(int yy, int mm, int dd)
     : y(yy), m(mm), d(dd)
{
    if(!is_valid()) throw Invalid{};
    
}

bool Date::is_valid()
{
    if(m<1 || 12<m) {
        return false;
    } else {
        return true;
    }
}

void Date::add_day(int n) {
    d = d + n;
}

int main() {
 
    try {
        Date dxy {2004,1,1};
        cout << dxy.month() << endl;
        dxy.add_day(2);
        cout << dxy.day() << endl;
    }
    catch(Date::Invalid) {
        cerr << "Invalid Day!" << endl;
    } catch(...) {
        cerr << "Error" << endl;
    }
    
    return 0;
}
