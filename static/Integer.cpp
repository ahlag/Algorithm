#include <iostream>
#include "Integer.h"

using namespace std;

static int m_value;

Integer::Integer(int num) {
    m_value = num;
}

void Integer::Show() {
    cout << m_value << endl;
}
