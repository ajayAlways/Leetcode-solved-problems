class Solution {

private:
    unordered_map<string,string>url2code,code2url;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string alphabets = "abcdefghijklmnopqrstuvwxyz1234567890";
        while(url2code.find(longUrl)==url2code.end()){
            random_shuffle(alphabets.begin(),alphabets.end());
            string code = alphabets.substr(0,6);
            if(code2url.find(code)==code2url.end()){
                code2url[code] = longUrl;
                url2code[longUrl] = code;
            }
        }
        return "http.tinyurl.com/"+url2code[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(shortUrl.length()-6,6);
        return code2url[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));