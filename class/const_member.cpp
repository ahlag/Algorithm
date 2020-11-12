#include <iostream>

using namespace std;

class Date {
public:
    enum Month {
      jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    
    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {}
    
    //const member: can't modify
    /*
    int day()     const {return d;};
    Month month() const {return m;};
    int year()    const {return y;};
     */
    
    int day()     {return d;};
    Month month() {return m;};
    int year()    {return y;};
    
    //non-const member: can modify
    void add_day(int n);
    /*
    void add_month(int n);
    void add_year(int n);
     */
private:
    int   y;
    Month m;
    int   d;
};

void Date::add_day(int n) { d = d + n;}

void some_function(Date& d, const Date& start_of_term) {
    int a = d.day();
    //int b = start_of_term.day();
    d.add_day(3);
}

int main() {
    
   // Date d(2000, Date::jan, 20);
   Date cd(2001, Date::feb, 21);
    
    cout << cd.day() <<  /*cd.day() <<*/ endl;
    
    
    
    
    return 0;
}
