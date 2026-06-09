#include<iostream>
using namespace std;
class Calculator
{
    private:
         double num1,num2;
    public:
        Calculator(){
            num1=0;
            num2=0;
        }
        void intput(){
            cout<<"Enter first number:"<<endl;
            cin>>num1;
            cout<<"Enter second number:"<<endl;
            cin>>num2;
        }
        double add(){
            return num1+num2;
        }
        double sub(){
            return num1-num2;
        }
        double multiply(){
            return num1*num2;
        }
        double divide(){
            if(num2!=0)
            return num1/num2;
            else{
                cout<<"Division by zero is error"<<endl;
                return 0;
            }
        }
        void checkOddEven(int n){
            if(n%2==0){
                cout<<n<<" is even"<<endl;
            }
            else{
                cout<<n<<" is odd"<<endl;
            }
            }
            void printtable(int n){
                cout<<"Table "<<n<<":"<<endl;
                for(int i=1;i<=10;i++){
                    cout<<n <<"X "<<i<<"="<<n*i<<endl;
                }
            }
            void display(){
                cout<<"Addition ="<<add()<<endl;
                cout<<"Subtraction ="<<sub()<<endl;
                cout<<"Multiplication ="<<multiply()<<endl;
                cout<<"Division ="<<divide()<<endl;
                cout<<"Check Odd/Even:"<<endl;
                checkOddEven(num1);
                checkOddEven(num2);
                cout<<"Multiplication:"<<endl;
                printtable(num1);
                printtable(num2);
            }
        };
        int main(){
            Calculator c;
            c.intput();
            c.display();
            return 0;
        }