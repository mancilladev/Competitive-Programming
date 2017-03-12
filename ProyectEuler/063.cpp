#include <iostream>
using namespace std;

ostream&
operator<<( ostream& dest, __int128_t value )
{
    ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( ios_base::badbit );
        }
    }
    return dest;
}

int len(__int128 n) {
        int cnt = 1;
        while(n /= 10)
                cnt++;
        return cnt;
}

__int128 pow(__int128 n, int k) {
        if (k == 0)
                return 1;
        return n * pow(n, k-1);
}

int main () {
        int ans = 0;
        for (int k = 1; k < 25; k++) {
                __int128 i = 0;
                int l = 0;
                while (l <= k) {
                        i++;
                        l = len(pow(i, k));
                        if (l == k)
                                ans++;
                }
        }
        cout<<ans<<endl;
}
