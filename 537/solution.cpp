typedef struct Cmp {
    int real;
    int imag;
};

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        struct Cmp c1 = parse(a);
        struct Cmp c2 = parse(b);
        struct Cmp c3{0,0};
        c3.real = c1.real * c2.real - c1.imag * c2.imag;
        c3.imag = c1.real * c2.imag + c1.imag * c2.real;
        stringstream ss;
        ss << c3.real << "+" << c3.imag << "i";
        return ss.str();
    }
private:
   struct Cmp parse(string a) {
        struct Cmp c{0,0};
        size_t pos = a.find("+");
        if (pos == std::string::npos) {
            return c;
        }
        string f(a.begin(),a.begin()+pos);
        string s(a.begin()+pos+1,a.end());
        c.real = static_cast<int>(strtol(f.c_str(),NULL,10));
        c.imag = static_cast<int>(strtol(s.c_str(),NULL,10));
        return c;
    }
};