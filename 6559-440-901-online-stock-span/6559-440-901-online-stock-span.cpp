//tc == o(2N) ,sc == o(N)
class StockSpanner {
public:
    int index; 
    stack<pair<int, int>> st; // Stores {price, index}
    StockSpanner() {
        index = -1; // Start before the first price
        //st.clear();
    }

    int next(int price) {
        index++; // Move to the next index

        // Remove all smaller or equal prices from the stack
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        // Calculate the span
        int previousIndex = st.empty() ? -1 : st.top().second;
        int span = index - previousIndex;

        // Push the current price and index onto the stack
        st.push({price, index});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */