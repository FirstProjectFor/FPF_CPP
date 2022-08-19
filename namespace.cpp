#include <iostream>
#include "namespace_copy.cpp"

using namespace std;

namespace namespace_A
{
    void showInfo()
    {
        cout << "namespace A" << endl;
    }
}

namespace namespace_B
{
    void showInfo()
    {
        cout << "namespace B" << endl;
    }
}

using namespace namespace_A;
// using namespace namespace_B;

int main()
{
    showInfo();
    showInfoCopy();
    return 0;
}
