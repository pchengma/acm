// LeetCode: 1832. Check if the Sentence Is Pangram (Easy)
class CheckIfPangram {
public:
    bool checkIfPangram(string sentence) {
        set<char> st;
        for (int i = 0; i < sentence.size(); i++) {
            st.insert(sentence[i]);
        }
        if (st.size() != 26) {
            return false;
        }
        return true;
    }
};