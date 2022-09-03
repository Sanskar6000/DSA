//Let's say the answer for n soldiers and k will be W(n, k);
//then after removing one soldier it will be (W(n - 1, k) + k) % n
//therefore W(n, k) = (W(n - 1, k) + k) % n
//Base case will be W(1, k) = 0