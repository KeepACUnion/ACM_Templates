struct Complex{
    double a,b;
    Complex(double aa = 0, double bb = 0){a = aa, b = bb;}
    Complex operator + (const Complex& rbs) const{
        return Complex(a+rbs.a, b+rbs.b);
    }
    Complex operator - (const Complex& rbs) const{
        return Complex(a-rbs.a, b-rbs.b);
    }
    Complex operator * (const Complex& rbs) const{
        return Complex(a*rbs.a-b*rbs.b, a*rbs.b+b*rbs.a);
    }
};
void change(Complex y[], int len){
    for(int i = 1, j = len/2; i < len-1; i++){
        if(i < j) swap(y[i], y[j]);
        int k = len>>1;
        while(1){
            j ^= k;
            if(j&k) break;
            k >>= 1;
        }
    }
}
void fft(Complex y[], int len, int o){
    change(y, len);
    for(int h = 2; h <= len; h <<= 1){
        Complex wn(cos(-o*2*PI/h), sin(-o*2*PI/h));
        for(int i = 0; i < len; i += h){
            Complex w(1,0);
            for(int j = i; j < i+h/2; j++){
                Complex l = y[j], r = w*y[j+h/2];
                y[j] = l+r; y[j+h/2] = l-r;
                w = w*wn;
            }
        }
    }
    if(o == -1) for(int i = 0; i < len; i++) y[i].a /= len;
}
