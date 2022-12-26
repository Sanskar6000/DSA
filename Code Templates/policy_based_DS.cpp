//For printing the elements to be removed can only be solved using indexed_set
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//less -> ascending order greater -> descending order
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; //*find_by_order, order_of_key

int main(){
    indexed_set s;
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9);

    cout << *s.find_by_order(2) << "\n"; 

    cout << s.order_of_key(7) << "\n";

    cout << s.order_of_key(6) << "\n";
    cout << s.order_of_key(8) << "\n";
}