//for integers
while(r - l >= 3) {
    int m1 = l + (r - l)/3;
    int m2 = r - (r - l)/3;

    val1 = f(m1);
    val2 = f(m2);

    if(val1 > val2) {
        r = m2;
    }
    else {
        l = m1;
    }
}

ans = max(f(l), f(l + 1), f(l + 2));

//for real numbers
while(r - l >= error) {
    int m1 = l + (r - l)/3;
    int m2 = r - (r - l)/3;

    val1 = f(m1);
    val2 = f(m2);

    if(val1 > val2) {
        r = m2;
    }
    else {
        l = m1;
    }
}