char* minWindow(char* s, char* t) {
    int n = 0, cnt[128] = { 0 };
    int head, tail, start, len = -1;
    char c, *p;

    if (!s || !*s || !t || !*t) return NULL;

    while (c = *(t ++)) {
        cnt[c] ++;
        n ++;   // total number of characters in T
    }

    head = tail = 0;
    while (c = s[tail ++]) {
        if (cnt[c] > 0) n --;  // decrease total number if a valid character is found
        cnt[c] --;  // decrease count of current character

        while (n == 0) { // all characters are found
            if (len == -1 || len > tail - head) {
                start = head;
                len = tail - head;
            }
            c = s[head ++];  // advance head
            cnt[c] ++;  // increase count
            if (cnt[c] > 0) {
                n = 1;  // a valid character was pushed out of head, will find it back from tail
            }
        }
    }

    if (len != -1) {
        p = &s[start];
        p[len] = 0;
    } else {
        p = "";
    }

    return p;
}
