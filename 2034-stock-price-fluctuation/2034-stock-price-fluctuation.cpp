class StockPrice {
public:
    map<int, int> mp;
    multiset<int> prices;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)) {
            prices.erase(prices.find(mp[timestamp]));
        }
        mp[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};