using ll = long long;
struct Entry {
    ll value;
    int index;
    // bool operator<(const Entry& other) const {
    //     if (value != other.value){
    //         return value < other.value;
    //     }
    //     return index < other.index;
    // }
    inline bool operator>(const Entry& other) const {
        if (value != other.value) {
            return value > other.value;
        }
        return index > other.index;
    }
};
inline ll modPower(ll a, ll n, ll mod) {
    ll ans = 1 % mod;
    a = a % mod;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            // important or we won't use the optimisation
            return nums;
        }
        ll MOD = 1e9 + 7;
        int maxm = 0;
        priority_queue<Entry, vector<Entry>, greater<Entry>> pq;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxm) {
                maxm = nums[i];
            }
            pq.emplace(nums[i], i);
        }
        // if we exahust the k simulation trials if the minimum element is not smaller 
        // than the max number in the array
        while (k && pq.top().value < maxm) {
            Entry x = pq.top();
            pq.pop();
            x.value *= multiplier;
            // x.value %= MOD;
            pq.push(x);k--;
        }
        int n = nums.size();
        int i = 0;
        // after the smallest element becomes larger than the max original element,
        // we end up in a repetition, so we just do power modulo
        // 
        while (!pq.empty()) {
            Entry x = pq.top();
            pq.pop();
            nums[x.index] = static_cast<int>(
                x.value%MOD *
                modPower(multiplier, k / n + (i < (k % n) ? 1 : 0), MOD) % MOD);
            i++;
        }
        return nums;
    }
};
