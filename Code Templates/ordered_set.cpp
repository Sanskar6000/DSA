//For printing the elements to be removed can only be solved using ordered_set
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

//template for ordered set
template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

//Find by order -> returns iterator to the kth element in O(log n) time
ordered_set<int> s;
int main(){

}