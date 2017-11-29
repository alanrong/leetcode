static std::map<string, string> smap;
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        std::hash<std::string> hash_fn;
        size_t h = hash_fn(longUrl);
        char c[16] = {0};
        sprintf(c, "%d",h);
        smap[c] = longUrl;
        return "http://tinyurl.com/" + string(c);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t pos = shortUrl.find_last_of("/");
        if (pos != -1) {
            string c = shortUrl.substr(pos+1);
            return smap[c];
        }
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));