class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int deck_len = deck.size(), i;
        if (deck_len <= 2) return deck;
        // sort the deck
        sort(deck.begin(), deck.end());
        deque<int> res;
        for (i = 0; i < deck_len; i++) {
            res.push_front(deck.back());
            deck.pop_back();
            if (i != deck_len - 1) {
                res.push_front(res.back());
                res.pop_back();
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};