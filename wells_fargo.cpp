/* 
1. You are given two strings containing only English Letters. Write an algorithm to count the number of occurences
of the second string in the first string.

Input:
TimisplayinginthehouseofTimwiththeTim
Tim

Output:
3
*/

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#include "debug.h"
#else
	#define dbg(x...)
#endif

#define int long long int

void solve() {
	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
}

/*
2. In a science research lab, combining two nuclear chemicals produce a maximum energy that is the product of the 
energy of the two chemicals. The energy value of the chemicals can be positive or negative. Scientist wishes to 
calculate the sum of the energies of two chemicals which produces the maximum energy on reaction.

Write an algorithm to find sum of the energies of two chemicals which produces the maximum energy on reaction.

Input:
7
9 -3 8 -6 -7 8 10

Output:
19
*/
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#include "debug.h"
#else
	#define dbg(x...)
#endif

#define int long long int

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &i : a) cin >> i;

	sort(a.begin(), a.end());
	long long x = a[0] * a[1], y = a[n - 1] * a[n - 2];

	if(x > y) cout << a[0] + a[1] << '\n';
	else cout << a[n - 1] + a[n - 2] << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
}

/*
3. You are given a queue of integers and a target number. Your task is to transform the queue into a new
queue such that the target number becomes the first element of the queue. However, you can only perform
the following operations:
i. Dequeue the current front element of the queue and enqueue it back at the end.
ii. Dequeue the current front element of the queue.

Write a function named 'transformQueue' that takes in three parameters: 'queue', 'target' and queue size.
Function should return a new queue with the desired transformation. If not possible to obtain the desired
transformation, return an empty queue. 

For example, we have queue containing the numbers [5, 2, 9, 1, 7]. We want to transform the queue such that
the number 9 becomes the first element. Write a 'transformQueue' function that iterates through each element
in the original queue. It enqueues each element into a new queue and checks if the element matches the 
target number. If the match is found it returns the tranformed queue. Otherwise, it returns an empty queue.
In this case since the target number 9 is found in the queue, the function returns a new queue
[9, 1, 7, 5, 2]. Write a queue data structure to operate on. Have a function to enqueue and dequeue.
*/

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#include "debug.h"
#else
	#define dbg(x...)
#endif

#define int long long int

class MyQueue{
private:
	queue<int> q;
public:
	void enqueue(int val) {
		q.push(val);
	}

	void dequeueEnqueue() {
		int t = q.front();
		q.pop();
		q.push(t);
	}

	void dequeue() {
		q.pop();
	}

	int front() {
		return q.front();
	}

	int size() {
		return q.size();
	}

	queue<int> getQueue() {
		return q;
	}

	bool isEmpty() {
		return q.empty();
	}
};

queue<int> transformQueue(queue<int> q, int target, int n) {
	MyQueue ans;
	while(!q.empty()) {
		ans.enqueue(q.front());
		q.pop();
	}

	for(int i = 0; i < n; i++) {
		if(ans.front() == target) {
			return ans.getQueue();
		}
		ans.dequeueEnqueue();
	}

	while(!ans.isEmpty()) {
		ans.dequeue();
	}

	return ans.getQueue();
}


void solve() {
	queue<int> q;
	int n, target;
	cin >> n >> target;

	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}	

	queue<int> ans = transformQueue(q, target, n);
	while(!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop();
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
}

/*
4. A stock trader trades in N selected stocks. The trader has calculated the relative stock price changes
in the N stocks from the previous day stock prices. The lucky number of the trader is K, so the trader
wishes to invest in the particular stock that has the kth smallest relative stock value.

Write an algorith to find kth smallest stock price.
*/

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#include "debug.h"
#else
	#define dbg(x...)
#endif

#define int long long int

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	priority_queue<int> q;
	for(auto &i : a) {
		cin >> i;
	} 

	int k;
	cin >> k;

	for(auto i : a) {
		q.push(i);
		if(q.size() > k) q.pop();
	}

	cout << q.top() << '\n';
	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
}

/*
5. The first line of input consists of an integer centreX1, representing x coordinates of the center of the
first circle. 
The second line of input consists of an integer centreY1, representing y coordinates of the center of the
first circle. 
The third line consists of an integer radius1, representing radius of first circle.
The fourth line of input consists of an integer centreX2, representing x coordinates of the center of the
second circle. 
The second line of input consists of an integer centreY2, representing y coordinates of the center of the
second circle. 
The third line consists of an integer radius2, representing radius of second circle.

print real number representing area of intersection of two circles rounded upto 6 decimal places
*/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include <bits/stdc++.h>
#define ld long double
using namespace std;
int main(){
    ld x, y, r, X, Y, R, d, a, b, pi = acos(-1), ans;
	cin >> x >> y >> r >> X >> Y >> R;

    d=sqrt((X-x)*(X-x)+(Y-y)*(Y-y));

	if(R+r<=d) ans=0;
	else if(R+d<=r||r+d<=R) ans=pi*min(r, R)*min(r, R);
	else {
		a=acos((r*r+d*d-R*R)/(2.0*d*r));
		b=acos((R*R+d*d-r*r)/(2.0*d*R));
		ans=(ld)(r*r*(a-sin(a)*cos(a))+R*R*(b-sin(b)*cos(b)));
	}
	
	cout << fixed << setprecision(6) << ans << endl;
    return 0;
}

/*
6. 1st Jan 1900 -> Monday
Count number of sundays between given two years
*/
int count_sundays(int start_year, int end_year) {
    // 1st Jan 1900 -> Monday
    int code = 1;

    vector<int> months = {31,28,31,30,31,30,31,31,30,31,30,31};

    int ans = 0;

    for(int i = start_year; i <= end_year; i++) {
        if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            months[1] = 29;
        }
        else months[1] = 28;

        for(int j : months) {
            code = (code + j) % 7;

            if(code == 0) ans++;
        }
    }

    return ans;
}

int main() {
    int start_year;
    cin >> start_year;

    int end_year;
    cin >> end_year;

    int res = count_sundays(1900, end_year) - count_sundays(1900, start_year - 1) << '\n';
}