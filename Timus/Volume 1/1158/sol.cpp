#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct Bigint {
    string a;
    int sign;

    using ll = long long;

    Bigint(){}
    void operator = (string b) {
        a= (b[0]=='-' ? b.substr(1) : b);
        reverse(a.begin(), a.end());
        (*this).Remove0(b[0]=='-' ? -1 : 1);
    }
    Bigint(string x) {(*this)=x;}
    Bigint(ll x) {(*this)=to_string(x);}
    void operator = (ll x){*this=to_string(x);}

    char operator[](int i){return a[i];}
    int size() {return a.size();}
    Bigint inverseSign() {sign*=-1; return (*this);}

    Bigint Remove0(int newSign) {
        sign = newSign;
        for(int i=a.size()-1; i>0 && a[i]=='0'; i--) a.pop_back();
        if(a.size()==1 && a[0]=='0') sign=1;
        return (*this);
    }

    bool operator == (Bigint x) {return sign==x.sign && a==x.a;}
    bool operator == (string x) {return *this==Bigint(x);}
    bool operator == (ll x)     {return *this==Bigint(x);}
    bool operator != (Bigint x) {return !(*this==x);}
    bool operator != (string x) {return !(*this==x);}
    bool operator != (ll x)     {return !(*this==x);}

    bool operator < (Bigint b) {
        if (sign!=b.sign) return sign<b.sign;
        if(a.size()!=b.size()) return a.size()*sign<b.size()*sign;
        for(int i=a.size()-1; i>=0; i--)
            if(a[i] != b[i]) return a[i]<b[i];
        return false;
    }
    bool operator <  (string x) {return *this<Bigint(x);}
    bool operator <  (ll x)     {return *this<Bigint(x);}
    bool operator <= (Bigint b) {return *this==b || *this<b;}
    bool operator <= (string b) {return *this==b || *this<b;}
    bool operator <= (ll b)     {return *this==b || *this<b;}
    bool operator >  (Bigint b) {return !(*this==b || *this<b);}
    bool operator >  (string x) {return !(*this==x || *this<x);}
    bool operator >  (ll b)     {return !(*this==b || *this<b);}
    bool operator >= (Bigint b) {return *this==b || *this>b;}
    bool operator >= (string b) {return *this==b || *this>b;}
    bool operator >= (ll b)     {return *this==b || *this>b;}

    Bigint operator + (Bigint b) {
        if(sign != b.sign) return (*this)-b.inverseSign();
        Bigint sum;
        for(int i=0, carry=0; i<a.size() || i<b.size() || carry; i++){
            if (i<a.size()) carry+=a[i]-'0';
            if (i<b.size()) carry+=b[i]-'0';
            sum.a += (carry % 10 + 48);
            carry /= 10;
        }
        return sum.Remove0(sign);
    }
    Bigint operator +  (string x) {return *this+Bigint(x);}
    Bigint operator +  (ll x)     {return *this+Bigint(x);}
    Bigint operator ++ (int) {*this+=1; return *this-1;}
    Bigint operator ++ ()    {*this+=1; return *this;}
      void operator += (Bigint x) {*this = *this+x;}
      void operator += (string x) {*this = *this+x;}
      void operator += (ll x)     {*this = *this+x;}


    Bigint operator - ( Bigint b ) {
        if(sign != b.sign) return (*this)+b.inverseSign();
        if(*this < b) return (b - *this).inverseSign();
        Bigint sub;
        for(int i=0,borrow=0; i<a.size(); i++) {
            borrow = a[i]-borrow-(i<b.size() ? b.a[i] : '0');
            sub.a += borrow>=0 ? borrow+'0' : borrow + 58;
            borrow = borrow>=0 ? 0:1;
        }
        return sub.Remove0(sign);
    }
    Bigint operator - (string x) {return *this-Bigint(x);}
    Bigint operator - (ll x)     {return *this-Bigint(x);}
    Bigint operator -- (int) {*this-=1; return *this+1;}
    Bigint operator -- ()    {*this-=1; return *this;}
      void operator -= (Bigint x) {*this = *this-x;}
      void operator -= (string x) {*this = *this-x;}
      void operator -= (ll x)     {*this = *this-x;}

    Bigint operator * (Bigint b) {
        Bigint mult("0");
        for(int i=0, k=a[i]; i<a.size(); i++, k=a[i]) {
            while(k-- -'0') mult=mult+b;
            b.a.insert(b.a.begin(),'0');
        }
        return mult.Remove0(sign * b.sign);
    }
    Bigint operator * (string x) {return *this*Bigint(x);}
    Bigint operator * (ll x)     {return *this*Bigint(x);}
      void operator *= (Bigint x) {*this = *this*x;}
      void operator *= (string x) {*this = *this*x;}
      void operator *= (ll x)     {*this = *this*x;}

    Bigint operator / (Bigint b) {
        if(b.size()==1 && b[0]=='0') b.a[0]/=(b[0]-'0');
        Bigint c("0"), d;
        for(int j=0; j<a.size(); j++) d.a += "0";
        int dSign = sign*b.sign; b.sign=1;
        for(int i=a.size()-1; i>=0; i--) {
            c.a.insert(c.a.begin(),'0');
            c=c+a.substr(i,1);
            while(!(c<b)) c=c-b, d.a[i]++;
        }
        return d.Remove0(dSign);
    }
    Bigint operator / (string x) {return *this/Bigint(x);}
    Bigint operator / (ll x)     {return *this/Bigint(x);}
      void operator /= (Bigint x) {*this = *this/x;}
      void operator /= (string x) {*this = *this/x;}
      void operator /= (ll x)     {*this = *this/x;}

    Bigint operator % (Bigint b) {
        if( b.size()==1 && b[0]=='0') b.a[0]/=(b[0]-'0') ;
        Bigint c("0");
        int cSign = sign*b.sign; b.sign=1;
        for( int i=a.size()-1; i>=0; i-- ) {
            c.a.insert( c.a.begin(),'0');
            c = c+a.substr(i,1);
            while(!(c<b)) c=c-b;
        }
        return c.Remove0(cSign);
    }
    Bigint operator % (string x) {return *this%Bigint(x);}
    Bigint operator % (ll x)     {return *this%Bigint(x);}
      void operator %= (Bigint x) {*this = *this%x;}
      void operator %= (string x) {*this = *this%x;}
      void operator %= (ll x)     {*this = *this%x;}

    void print() {
        if(sign==-1) putchar('-');
        for(int i=a.size()-1; i>=0; i--) putchar(a[i]);
    }
    friend istream& operator >>(istream &in,Bigint &x){
        string s; in>>s; x=s; return in;
    }
    friend ostream& operator <<(ostream &out,Bigint &x){
        if(x.sign==-1) putchar('-');
        for(int i=x.size()-1; i>=0; i--)
            putchar(x[i]);
        return out;
    }

    friend Bigint pow(Bigint base, Bigint pw){
        Bigint ans=1;
        while(pw!=0){
            if(pw%2 !=0) ans*=base;
            base*=base, pw/=2;
        }
        return ans;
    }
    friend Bigint pow(Bigint a, Bigint b,Bigint mod) {
        if (b==0) return Bigint(1);
        Bigint tmp=pow(a,b/2,mod);
        if ((b%2)==0) return (tmp*tmp)%mod;
        else return (((tmp*tmp)%mod)*a)%mod;
    }
    friend Bigint sqrt(Bigint x) {
        Bigint ans=x,tmp=(x+1)/2;
        while (tmp<ans) ans=tmp, tmp=(tmp+x/tmp)/2;
        return ans;
    }
    friend Bigint gcd(Bigint a,Bigint b){
        return a%b==0 ? b : gcd(b, a%b);
    }
    friend Bigint lcm(Bigint a,Bigint b){
        return a/gcd(a,b);
    }
};

int alpha;

struct AhoCorasick {
  enum { first = 0 };
  struct Node {
    int back, start = -1, end = -1, nmatches = 0;
    vector<int> next;
    Node(int v) : next(alpha, v) {}
  };
  vector<Node> N;
  vector<int> backp;
  void insert(string& s, int j) {
    assert(!s.empty());
    int n = 0;
    for (char c : s) {
      int& m = N[n].next[c - first];
      if (m == -1) {
        n = m = (int)N.size();
        N.emplace_back(-1);
      } else
        n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].nmatches++;
  }
  AhoCorasick(vector<string>& pat) : N(1, -1) {
    for (int i = 0; i < (int)pat.size(); ++i)
      insert(pat[i], i);
    N[0].back = (int)N.size();
    N.emplace_back(0);

    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      for (int i = 0; i < alpha; ++i) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1)
          ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
          N[ed].nmatches += N[y].nmatches;
          q.push(ed);
        }
      }
    }
  }
  Bigint paths(int m) {
    int n = (int)N.size();
    vector<Bigint> dp(n, Bigint(0)), prev(n, Bigint(0));
    prev[0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int u = 0; u < n; ++u) {
        if (N[u].nmatches) {
          continue;
        }
        for (int c = 0; c < alpha; ++c) {
          int v = N[u].next[c];
          if (!N[v].nmatches) {
            dp[v] += prev[u];
          }
        }
      }
      prev.swap(dp);
      fill(dp.begin(), dp.end(), Bigint(0));
    }
    return accumulate(prev.begin(), prev.end(), Bigint(0));
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int m, p;
  cin >> alpha >> m >> p;

  map<char, int> mp;
  {
    string allowed;
    getline(cin, allowed);
    getline(cin, allowed);
    for (int i = 0; i < alpha; ++i) {
      mp[allowed[i]] = i;
    }
  }

  vector<string> pat(p);
  for (string& p : pat) {
    cin >> p;
    for (char& c : p) {
      c = char(mp[c]);
    }
  }

  AhoCorasick aho(pat);

  Bigint ans = aho.paths(m);
  cout << ans << '\n';

  return 0;
}