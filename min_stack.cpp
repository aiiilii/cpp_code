#include <stack>
#include <limits>

using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int x) {
        if (x <= min) {
            st.push(min); // push previous min into the stack, then update the min;
            min = x;
        }
        st.push(x); // then push x into stack, x get pushed into stack no matter if it is the min or not;
    }

    void pop() {
        if (st.top() == min) {
            st.pop();
            min = st.top(); // stored the previous min below the current min, so when the current min is popped out, update the min;
            st.pop();
        } else {
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min;
    }

private:
    int min = numeric_limits<int>::max();

    stack<int> st;
};
