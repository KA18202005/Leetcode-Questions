class RLEIterator {
    int cur;
    vector<int> seq;
public:
    RLEIterator(vector<int>& encoding) {
        seq = encoding;
        cur = 0;
    }
    
    int next(int n) {
        while(cur < seq.size()) {
            if(seq[cur] >= n) {
                seq[cur] -= n;
                return seq[cur + 1];
            }
            else {
                n -= seq[cur];
                cur += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */