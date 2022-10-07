// LeetCode: 732. My Calendar III (Hard)
class MyCalendarThree {
public:
    map<int, int> mp;

    MyCalendarThree() {

    }

    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int ans = 0, cnt = 0;
        for (auto x: mp) {
            cnt += x.second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */