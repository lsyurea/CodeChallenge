class Solution {
public:
    string sortVowels(string s) {
        // stable sorting -> merge sort
        string vowels = "aeiouAEIOU";
        string vowel_sorted = merge_sort(s);
        string res;
        int idx = 0, gidx = 0;
        for (auto &ch : s) {
            if (str_contains(vowels, ch)) res += vowel_sorted[idx++];
            else res += s[idx + gidx++];
        }
        return res;
    }

    string merge_sort(string s) {
        int str_len = s.size();
        if (str_len <2) return s;
        return merge(merge_sort(s.substr(0, str_len / 2)),
            merge_sort(s.substr(str_len / 2, str_len)));
    }

    string merge(string left, string right) {
        // only sort the vowels and ignore the consonant
        string new_string;
        string vowels = "aeiouAEIOU";
        int left_idx = 0, right_idx = 0;
        while (left_idx < left.size() && right_idx < right.size()) {
            if (str_contains(vowels, right[right_idx])
                && str_contains(vowels, left[left_idx])) {
                if ((int) left[left_idx] <= (int) right[right_idx]) {
                    new_string += left[left_idx++];
                } else {
                    new_string += right[right_idx++];
                }
            } else if (str_contains(vowels, left[left_idx])) {
                right_idx++;
            } else {
                left_idx++;
            }
        }

        while (left_idx < left.size()) {
            if (!str_contains(vowels, left[left_idx])) left_idx++;
            else new_string += left[left_idx++];
        }

        while (right_idx < right.size()) {
            if (!str_contains(vowels, right[right_idx])) right_idx++;
            else new_string += right[right_idx++];
        }

        return new_string;
    }
    
    bool str_contains(string s, char c) {
        for (auto &ch : s) {
            if (ch == c) return true;
        }
        return false;
    }
};