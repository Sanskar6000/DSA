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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k; 

    for(int i = 1; i <= n; i++) s.insert(i);

    int ind = 0;
    while(s.size() != 0) {
        ind = (ind + k) % s.size();
        cout << *(s.find_by_order(ind)) << " ";
        s.erase(s.find_by_order(ind)); 
    }

}