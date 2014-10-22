class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL)
        {
            return NULL;
        }

        int haylen = strlen(haystack);
        int ndllen = strlen(needle);
        if (ndllen > haylen) return NULL;

        for (int i = 0; i < haylen - ndllen + 1; i++)
        {
            int j = 0 ;
            char *p = &haystack[i];
            for (; j < ndllen; j++)
            {
                if (*p != needle[j])
                    break;
                p++;
            }

            if (j == ndllen)
                return &haystack[i];

        }
        return NULL;
    }
};