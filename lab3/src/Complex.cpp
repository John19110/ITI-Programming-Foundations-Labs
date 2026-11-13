#include <iostream>

using namespace std;

class Complex {
    int real ;
    int img;
  
    public:
      
          Complex(double real=0 ,double img=0 ){
            this->real=real;
            this->img=img;
        }
        void setComplex(int real,int img){
            this->real=real;
            this->img=img;
        }


        int getReal()const 
        {
            return real;
        }
                int getImg()const 
        {
            return img;
        }
        void getComplex(){
            if(real !=0){
                cout<<real;
            }
            if(img !=0 ){
                  
               (img >0)?cout<<"+"<<img<<"j"<<endl:cout<<img<<"j"<<endl;
            }

        }
     Complex operator -( const Complex & C )const 
     {
        return Complex(this->real - C.real,this->img-C.img);
     } 
     Complex operator *( const Complex & C )const 
     {
        return Complex(this->real * C.real,this->img*C.img);
     }  Complex operator /( const Complex & C )const 
     {
        return Complex(this->real / C.real,this->img / C.img);
     } 



          Complex operator -( const int x  )const 
     {
        return Complex(this->real - x,this->img-x);
     } 
         Complex operator *( const int x  )const 
     {
        return Complex(this->real * x,this->img *x);
     } 
           Complex operator /( const int x  )const 
     {
        return Complex(this->real / x,this->img /x);
     } 


};

       Complex operator /(const int x ,Complex C) 
     {
        return Complex(C.getReal() / x,C.getImg() /x);
     } 
       Complex operator *(const int x ,Complex C) 
     {
        return Complex(C.getReal() * x,C.getImg() *x);
     } 

       Complex operator -(const int x ,Complex C) 
     {
        return Complex(C.getReal() - x,C.getImg() -x);
     } 




int main()
{
        Complex C;
        C.setComplex(5,5);
        Complex C1;
        C1.setComplex(10,10);
        Complex C2;
        C2=C-C1;
        C2.getComplex();
        C2=C1*C;
        C2.getComplex();
        C2=C1/C;
        C2.getComplex();
        
    return 0;
}

