class Solution {
public:
    int compareVersion(string version1, string version2) {
        // assumes versions are valid
        long i = 0, j = 0, curi = 0, curj = 0;
        // keep interating
        while (i < version1.length() || j < version2.length()) {
            // skip all the zeros first
            while (i < version1.length() && version1[i] == '0') i++;
            while(j < version2.length() && version2[j] == '0') j++;
            curi = 0;
            curj = 0;
            // when there is a value add to curi until next stop
            while (i < version1.length() && version1[i] != '.') {
                curi = curi * 10 + (int) version1[i++] - (int) '0';
            }
            while (j < version2.length() && version2[j] != '.') {
                curj = curj * 10 + (int) version2[j++] - (int) '0';
            }
            // compare the values
            if (curi > curj) return 1;
            if (curi < curj) return -1;

            // increment to change to the next one
            i++;
            j++;
        }
        return 0;
    }
};